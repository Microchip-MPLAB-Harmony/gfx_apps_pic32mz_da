/*******************************************************************************
 File System Handler Source File

 Mohit M
 18-APR-2021
 *******************************************************************************/

#include "app_fs.h"

#define SDCARD_DEV_NAME      SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0
#define SDCARD_MOUNT_NAME    SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0

/* Application data */
APP_FS_DATA app_fs;

static void APP_FS_SysFSEventHandler(SYS_FS_EVENT event,
        void* eventData,
        uintptr_t context) {
    switch (event) {
            /* If the event is mount then check if media is mounted */
        case SYS_FS_EVENT_MOUNT:
            if (strcmp((const char *) eventData, SDCARD_MOUNT_NAME) == 0) {
                printf("File System Mounted\r\n");
                app_fs.mounted = true;
            }
            break;

            /* If the event is unmount then check if media is unmounted */
        case SYS_FS_EVENT_UNMOUNT:
            if (strcmp((const char *) eventData, SDCARD_MOUNT_NAME) == 0) {
                printf("File System Unmounted\r\n");
                app_fs.mounted = false;
                app_fs.state = APP_FS_STATE_MOUNT_WAIT;
            }
            break;

        case SYS_FS_EVENT_ERROR:
            printf("File System Error\r\n");
            break;

        default:
            printf("File System Unhandled Event\r\n");
            break;
    }
}

void APP_FS_Initialize(void) {
    /* Place the state machine in its initial state */
    app_fs.state = APP_FS_STATE_MOUNT_WAIT;

    /* Register the File System Event handler */
    SYS_FS_EventHandlerSet((void const*) APP_FS_SysFSEventHandler,
            (uintptr_t) NULL);
}

void APP_FS_Tasks(void) {

    /* Check the application's current state */
    switch (app_fs.state) {
            /* State machine waits for the sdcard to be mounted */
        case APP_FS_STATE_MOUNT_WAIT:
            /* Wait for card to be mounted */
            if (app_fs.mounted == true) {
                app_fs.state = APP_FS_STATE_IDLE;
            }
            break;

            /* State machine idle state */
        case APP_FS_STATE_IDLE:
            break;

            /* The default state should never be executed */
        default:
            break;
    }
}

/* Common Interface */
bool COMMON_APP_FS_CheckMount(void) {
    return app_fs.mounted;
}
