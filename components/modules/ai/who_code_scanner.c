#include "who_code_scanner.h"

#include "esp_log.h"
#include "esp_camera.h"
#include "esp_code_scanner.h"
#include "who_c_wrapper.h"

static const char *TAG = "code_scanner";

static QueueHandle_t xQueueFrameI = NULL;
static QueueHandle_t xQueueEvent = NULL;
static QueueHandle_t xQueueFrameO = NULL;
static QueueHandle_t xQueueResult = NULL;

static bool gEvent = true;
static bool gReturnFB = true;

static void decode_task(void *arg)
{
    camera_fb_t *frame = NULL;
    ai_msg_t msg;

    while (true)
    {
        if (gEvent)
        {
            bool is_detected = false;
            if (xQueueReceive(xQueueFrameI, &frame, portMAX_DELAY)){
                esp_image_scanner_t *esp_scn = esp_code_scanner_create();
                esp_code_scanner_config_t config = {ESP_CODE_SCANNER_MODE_FAST, ESP_CODE_SCANNER_IMAGE_RGB565, frame->width, frame->height};
                esp_code_scanner_set_config(esp_scn, config);
                int decoded_num = esp_code_scanner_scan_image(esp_scn, frame->buf);
                if(decoded_num){
                    esp_code_scanner_symbol_t result = esp_code_scanner_result(esp_scn);
                    ESP_LOGI(TAG, "Decoded %s symbol \"%s\"\n", result.type_name, result.data);

                    msg.type = AI_TYPE_CODE_SCANNER;
                    msg.data = result.data;
                    msg.type_name = result.type_name;
                    xQueueSend(xQueueResult, &msg, portMAX_DELAY);
                }
                esp_code_scanner_destroy(esp_scn);
            }

            if (xQueueFrameO){
                xQueueSend(xQueueFrameO, &frame, portMAX_DELAY);
            }else if (gReturnFB){
                esp_camera_fb_return(frame);
            }else{
                free(frame);
            }
        }
    }
}

static void task_event_handler(void *arg)
{
    while (true)
    {
        xQueueReceive(xQueueEvent, &(gEvent), portMAX_DELAY);
    }
}

void register_code_scanner(const QueueHandle_t frame_i,
                                 const QueueHandle_t event,
                                 const QueueHandle_t result,
                                 const QueueHandle_t frame_o,
                                 const bool camera_fb_return)
{
    xQueueFrameI = frame_i;
    xQueueFrameO = frame_o;
    xQueueEvent = event;
    xQueueResult = result;
    gReturnFB = camera_fb_return;

    xTaskCreatePinnedToCore(decode_task, "code_scanner", 4 * 1024, NULL, 5, NULL, 1);
    if (xQueueEvent)
        xTaskCreatePinnedToCore(task_event_handler, "cat_face_event", 1 * 1024, NULL, 5, NULL, 1);
}
