/***************************************************************************/ /**
                                                                               * @file app.h
                                                                               * @brief Top level application functions
                                                                               *******************************************************************************
                                                                               * # License
                                                                               * <b>Copyright 2022 Yizhu Technology Inc. www.yizhu.com</b>
                                                                               *******************************************************************************
                                                                               *
                                                                               * The licensor of this software is Yizhu Technology Inc. Your use of this
                                                                               * software is governed by the terms of Yizhu Technology Master Software License
                                                                               * Agreement (MSLA) available at
                                                                               * www.yizhu.com/about-us/legal/master-software-license-agreement. This
                                                                               * software is distributed to you in Source Code format and is governed by the
                                                                               * sections of the MSLA applicable to Source Code.
                                                                               *
                                                                               ******************************************************************************/

#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************/ /**
                                                                               * Initialize application.
                                                                               ******************************************************************************/
void app_init(void);
void app_process_action(void);

#ifdef __cplusplus
}
#endif

#endif // APP_H
