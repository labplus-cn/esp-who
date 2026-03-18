#include "who_human_face_detection.hpp"
#include "who_human_face_recognition.hpp"
#include "who_motion_detection.hpp"
#include "who_cat_face_detection.hpp"
#include "who_color_detection.hpp"

#ifdef __cplusplus
extern "C" {
#endif 

#include "who_c_wrapper.h"

void register_human_face_detection_wrapper(QueueHandle_t frame_i,
    QueueHandle_t event,
    QueueHandle_t result,
    QueueHandle_t frame_o,
    const bool camera_fb_return)
{
    register_human_face_detection(frame_i, event, result, frame_o, camera_fb_return);
}

void register_human_face_recognition_wrapper(QueueHandle_t frame_i,
    QueueHandle_t event,
    QueueHandle_t result,
    QueueHandle_t frame_o,
    const bool camera_fb_return)
{
    register_human_face_recognition(frame_i, event, result, frame_o, camera_fb_return);
}

void register_motion_detection_wrapper(QueueHandle_t frame_i, QueueHandle_t event,
    QueueHandle_t result, QueueHandle_t frame_o)
{
    register_motion_detection(frame_i, event, result, frame_o);
}

void register_cat_face_detection_wrapper(QueueHandle_t frame_i,
    QueueHandle_t event,
    QueueHandle_t result,
    QueueHandle_t frame_o,
    const bool camera_fb_return)
{
    register_cat_face_detection(frame_i, event, result, frame_o, camera_fb_return);
}

void register_color_detection_wrapper(QueueHandle_t frame_i,
    QueueHandle_t event,
    QueueHandle_t result,
    QueueHandle_t frame_o,
    const bool camera_fb_return)
{
    register_color_detection(frame_i, event, result, frame_o, camera_fb_return);
}

#ifdef __cplusplus
}
#endif