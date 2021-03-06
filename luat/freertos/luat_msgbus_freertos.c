
#include "luat_msgbus.h"

#include "cmsis_os2.h"

#define LUAT_MSGBUS_MAXCOUNT 0xFF
//#define LUAT_MSGBUS_MAXSIZE 8
static osMessageQueueId_t queue; 

void luat_msgbus_init(void) {
    if (!queue) {
        queue = osMessageQueueNew(LUAT_MSGBUS_MAXCOUNT, sizeof(rtos_msg_t), NULL);
    }
}
uint32_t luat_msgbus_put(rtos_msg_t* msg, size_t timeout) {
    return osMessageQueuePut(queue, msg, NULL, timeout);
}
uint32_t luat_msgbus_get(rtos_msg_t* msg, size_t timeout) {
    return osMessageQueueGet(queue, msg, NULL, timeout);
}
uint32_t luat_msgbus_freesize(void) {
    return osMessageQueueGetSpace(queue);
}
