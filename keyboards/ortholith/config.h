// Copyright 2026 mina-root
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifndef __ASSEMBLER__
#include <stdbool.h>
bool is_keyboard_left(void);
#define SERIAL_USART_TX_PIN (is_keyboard_left() ? GP11 : GP20)
#define WS2812_DI_PIN (is_keyboard_left() ? GP9 : GP11)

// Pointing Device (Trackball) configuration
#define POINTING_DEVICE_RIGHT
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_CS_PIN GP17
#define POINTING_DEVICE_ROTATION_270 
#define POINTING_DEVICE_INVERT_Y
#define ROTATIONAL_TRANSFORM_ANGLE 3
// SPI Configuration for RP2040 (SPID0)
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MISO_PIN GP16
#define SPI_MOSI_PIN GP19

// RGB Matrix configuration
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

// I2C Configuration for OLED
#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP12
#define I2C1_SCL_PIN GP13

#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X32
#    define SPLIT_OLED_ENABLE
#    define SPLIT_LAYER_STATE_ENABLE
#    define SPLIT_LED_STATE_ENABLE
#endif
#else
#define SERIAL_USART_TX_PIN GP11
#define WS2812_DI_PIN GP9
#endif
