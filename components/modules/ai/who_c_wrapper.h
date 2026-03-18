#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

typedef enum _ai_type_t{
    AI_TYPE_NONE = 0,
    AI_TYPE_COLOR_DETECTION,
    AI_TYPE_FACE_DETECTION,
    AI_TYPE_FACE_RECOGNITION,
    AI_TYPE_CAT_FACE_DETECTION,
    AI_TYPE_MOTION_DEECTION,
    AI_TYPE_CODE_SCANNER,
}ai_type_t;

typedef struct _ai_msg_t
{
    uint16_t type;
    int id;
    float similarity;
    uint8_t element_num;
    const char *data;
    const char *type_name;
    int box[5][4];
    int keypoint[5][10];
}ai_msg_t;

void register_human_face_detection_wrapper(QueueHandle_t frame_i,
                                   QueueHandle_t event,
                                   QueueHandle_t result,
                                   QueueHandle_t frame_o,
                                   const bool camera_fb_return);

void register_human_face_recognition_wrapper(QueueHandle_t frame_i,
                                    QueueHandle_t event,
                                    QueueHandle_t result,
                                    QueueHandle_t frame_o,
                                    const bool camera_fb_return);  
                                    
void register_motion_detection_wrapper(QueueHandle_t frame_i, QueueHandle_t event,
                                QueueHandle_t result, QueueHandle_t frame_o);

void register_cat_face_detection_wrapper(QueueHandle_t frame_i,
                                QueueHandle_t event,
                                QueueHandle_t result,
                                QueueHandle_t frame_o,
                                const bool camera_fb_return);

void register_color_detection_wrapper(QueueHandle_t frame_i,
                                    QueueHandle_t event,
                                    QueueHandle_t result,
                                    QueueHandle_t frame_o,
                                    const bool camera_fb_return);
