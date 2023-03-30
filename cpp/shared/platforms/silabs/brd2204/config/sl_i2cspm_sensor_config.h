/***************************************************************************/ /**
                                                                               * @file
                                                                               * @brief I2CSPM Config
                                                                               *******************************************************************************
                                                                               * # License
                                                                               * <b>Copyright 2019 Yizhu Technology Inc. www.yizhu.com</b>
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

#ifndef SL_I2CSPM_SENSOR_CONFIG_H
#define SL_I2CSPM_SENSOR_CONFIG_H

// <<< Use Configuration Wizard in Context Menu

// <h>I2CSPM settings

// <o SL_I2CSPM_SENSOR_REFERENCE_CLOCK> Reference clock frequency
// <i> Frequency in Hz of the reference clock.
// <i> Select 0 to use the frequency of the currently selected clock.
// <i> Default: 0
#define SL_I2CSPM_SENSOR_REFERENCE_CLOCK 0

// <o SL_I2CSPM_SENSOR_SPEED_MODE> Speed mode
// <0=> Standard mode (100kbit/s)
// <1=> Fast mode (400kbit/s)
// <2=> Fast mode plus (1Mbit/s)
// <i> Default: 0
#define SL_I2CSPM_SENSOR_SPEED_MODE 0
// </h> end I2CSPM config

// <<< end of configuration section >>>

// <<< sl:start pin_tool >>>
// <i2c signal=SCL,SDA> SL_I2CSPM_SENSOR
// $[I2C_SL_I2CSPM_SENSOR]
#define SL_I2CSPM_SENSOR_PERIPHERAL I2C2
#define SL_I2CSPM_SENSOR_PERIPHERAL_NO 2

// I2C2 SCL on PI5
#define SL_I2CSPM_SENSOR_SCL_PORT gpioPortI
#define SL_I2CSPM_SENSOR_SCL_PIN 5
#define SL_I2CSPM_SENSOR_SCL_LOC 7

// I2C2 SDA on PI4
#define SL_I2CSPM_SENSOR_SDA_PORT gpioPortI
#define SL_I2CSPM_SENSOR_SDA_PIN 4
#define SL_I2CSPM_SENSOR_SDA_LOC 7

// [I2C_SL_I2CSPM_SENSOR]$
// <<< sl:end pin_tool >>>

#endif // SL_I2CSPM_SENSOR_CONFIG_H
