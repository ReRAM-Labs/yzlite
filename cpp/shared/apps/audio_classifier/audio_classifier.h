/***************************************************************************/ /**
                                                                               * @file
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
#ifndef AUDIO_CLASSIFIER_H
#define AUDIO_CLASSIFIER_H

#ifdef __cplusplus
extern "C" {
#endif

extern int category_count;

/***************************************************************************/ /**
                                                                               * Initialize application.
                                                                               ******************************************************************************/
void audio_classifier_init(void);

const char *get_category_label(int index);

#ifdef __cplusplus
}
#endif

#endif // AUDIO_CLASSIFIER_H
