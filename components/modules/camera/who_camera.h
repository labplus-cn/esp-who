#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#include "esp_camera.h"

#if CONFIG_CAMERA_MODULE_LABPLUS_XUNFEI_JS_PRIMARY_BOARD
#define CAMERA_MODULE_NAME "labplus_xunfie_jiangsu_primary_school_board"
#define CAMERA_PIN_PWDN -1
#define CAMERA_PIN_RESET -1

#define CAMERA_PIN_VSYNC 18
#define CAMERA_PIN_HREF 17
#define CAMERA_PIN_PCLK 48
#define CAMERA_PIN_XCLK 47

#define CAMERA_PIN_SIOD 44
#define CAMERA_PIN_SIOC 43

// #define CAMERA_PIN_D0 9
// #define CAMERA_PIN_D1 10
// #define CAMERA_PIN_D2 11
// #define CAMERA_PIN_D3 12
// #define CAMERA_PIN_D4 13
// #define CAMERA_PIN_D5 14
// #define CAMERA_PIN_D6 15
// #define CAMERA_PIN_D7 16

#define CAMERA_PIN_D0 12
#define CAMERA_PIN_D1 10
#define CAMERA_PIN_D2 9
#define CAMERA_PIN_D3 11
#define CAMERA_PIN_D4 13
#define CAMERA_PIN_D5 14
#define CAMERA_PIN_D6 15
#define CAMERA_PIN_D7 16
#elif CONFIG_CAMERA_MODULE_LABPLUS_LEDONG_V2_BOARD
#define CAMERA_MODULE_NAME "LABPLUS_LEDONG_V2_BOARD"
#define CAMERA_PIN_PWDN -1
#define CAMERA_PIN_RESET -1

#define CAMERA_PIN_VSYNC 34
#define CAMERA_PIN_HREF 33
#define CAMERA_PIN_PCLK 48
#define CAMERA_PIN_XCLK 47

#define CAMERA_PIN_SIOD 44
#define CAMERA_PIN_SIOC 43

#define CAMERA_PIN_D0 10
#define CAMERA_PIN_D1 11
#define CAMERA_PIN_D2 12
#define CAMERA_PIN_D3 13
#define CAMERA_PIN_D4 14
#define CAMERA_PIN_D5 15
#define CAMERA_PIN_D6 17
#define CAMERA_PIN_D7 18
#endif

#define XCLK_FREQ_HZ 10000000

#ifdef __cplusplus
extern "C"
{
#endif
    /**
     * @brief Initialize camera
     * 
     * @param pixformat    One of
     *                     - PIXFORMAT_RGB565
     *                     - PIXFORMAT_YUV422
     *                     - PIXFORMAT_GRAYSC
     *                     - PIXFORMAT_JPEG
     *                     - PIXFORMAT_RGB888
     *                     - PIXFORMAT_RAW
     *                     - PIXFORMAT_RGB444
     *                     - PIXFORMAT_RGB555
     * @param frame_size   One of
     *                     - FRAMESIZE_96X96,    // 96x96
     *                     - FRAMESIZE_QQVGA,    // 160x120
     *                     - FRAMESIZE_QCIF,     // 176x144
     *                     - FRAMESIZE_HQVGA,    // 240x176
     *                     - FRAMESIZE_240X240,  // 240x240
     *                     - FRAMESIZE_QVGA,     // 320x240
     *                     - FRAMESIZE_CIF,      // 400x296
     *                     - FRAMESIZE_HVGA,     // 480x320
     *                     - FRAMESIZE_VGA,      // 640x480
     *                     - FRAMESIZE_SVGA,     // 800x600
     *                     - FRAMESIZE_XGA,      // 1024x768
     *                     - FRAMESIZE_HD,       // 1280x720
     *                     - FRAMESIZE_SXGA,     // 1280x1024
     *                     - FRAMESIZE_UXGA,     // 1600x1200
     *                     - FRAMESIZE_FHD,      // 1920x1080
     *                     - FRAMESIZE_P_HD,     //  720x1280
     *                     - FRAMESIZE_P_3MP,    //  864x1536
     *                     - FRAMESIZE_QXGA,     // 2048x1536
     *                     - FRAMESIZE_QHD,      // 2560x1440
     *                     - FRAMESIZE_WQXGA,    // 2560x1600
     *                     - FRAMESIZE_P_FHD,    // 1080x1920
     *                     - FRAMESIZE_QSXGA,    // 2560x1920
     * @param fb_count     Number of frame buffers to be allocated. If more than one, then each frame will be acquired (double speed)
     */
    void register_camera(const pixformat_t pixel_fromat,
                         const framesize_t frame_size,
                         const uint8_t fb_count,
                         const QueueHandle_t frame_o);

    void camera_init(const pixformat_t pixel_fromat,
                        const framesize_t frame_size,
                        const uint8_t fb_count);
                        
    bool is_camera_initialized(void);

#ifdef __cplusplus
}
#endif
