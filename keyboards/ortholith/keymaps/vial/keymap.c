// Copyright 2026 mina-root
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <math.h>

// レイヤー定義
enum custom_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _LAYER3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        // Row 0 左 6キー
        KC_ESC,         KC_Q,           KC_L,           KC_U,           KC_COMM,        KC_DOT,
        // Row 0 右 6キー
        KC_F,           KC_W,           KC_R,           KC_Y,           KC_P,           KC_BSPC,

        // Row 1 左 6キー (Home Row Mods)
        KC_TAB,         KC_E,           LCTL_T(KC_I),   LSFT_T(KC_A),   LSFT_T(KC_O),   KC_MINS,
        // Row 1 右 6キー (Home Row Mods)
        KC_K,           RSFT_T(KC_T),   RSFT_T(KC_N),   RCTL_T(KC_S),   KC_H,           KC_QUOT,

        // Row 2 左 7キー (x=0〜6, 追加キー[2,6]含む)
        S(KC_INT1),     KC_Z,           KC_X,           KC_C,           KC_V,           KC_SCLN,        KC_SLSH,
        // Row 2 右 7キー (x=8〜14, 追加キー[6,0]含む)
        KC_RBRC,        KC_G,           KC_D,           KC_M,           KC_J,           KC_B,           KC_SLSH,

        // Row 3 左親指 7キー (x=0〜6)
        KC_LGUI,        KC_LNG1,        KC_LALT,        KC_ESC,         LT(1, KC_LNG2), LT(3, KC_SPC),  LCTL_T(KC_DEL),
        // Row 7 右親指 4キー (x=8, 9, 13, 14)
        KC_BSPC,        LT(2, KC_ENT),  KC_RALT,        KC_RGUI
    ),
    [_LOWER] = LAYOUT(
        // Row 0 左 6キー
        S(KC_6),    S(KC_COMM), KC_RBRC,    S(KC_DOT),  KC_BSLS,    KC_EQL,
        // Row 0 右 6キー
        S(KC_5),    KC_P7,      KC_P8,      KC_P9,      S(KC_EQL),  S(KC_LBRC),

        // Row 1 左 6キー
        S(KC_3),    KC_LBRC,    S(KC_8),    S(KC_2),    S(KC_9),    S(KC_1),
        // Row 1 右 6キー
        S(KC_MINS), KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    S(KC_INT3),

        // Row 2 左 7キー (x=0〜6, 追加キー[2,6]含む)
        S(KC_4),    UG_NEXT,    S(KC_RBRC), S(KC_7),    S(KC_BSLS), S(KC_SLSH), UG_TOGG,
        // Row 2 右 7キー (x=8〜14, 追加キー[6,0]含む)
        KC_TRNS,    KC_PPLS,    KC_P1,      KC_P2,      KC_P3,      KC_PAST,    KC_INT3,

        // Row 3 左親指 7キー (x=0〜6)
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        // Row 7 右親指 4キー (x=8, 9, 13, 14)
        KC_TRNS,    KC_P0,      KC_TRNS,    KC_TRNS
    ),
    [_RAISE] = LAYOUT(
        // Row 0 左 6キー
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,
        // Row 0 右 6キー
        KC_TRNS,    KC_HOME,    KC_UP,      KC_PGUP,    KC_RBRC,    KC_BSLS,

        // Row 1 左 6キー
        KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
        // Row 1 右 6キー
        KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_RGHT,    S(KC_RBRC), S(KC_BSLS),

        // Row 2 左 7キー (x=0〜6, 追加キー[2,6]含む)
        KC_TRNS,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_TRNS,    KC_TRNS,
        // Row 2 右 7キー (x=8〜14, 追加キー[6,0]含む)
        SGUI(KC_S), KC_END,     KC_TRNS,    KC_PGDN,    KC_TRNS,    KC_TRNS,    KC_TRNS,

        // Row 3 左親指 7キー (x=0〜6)
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        // Row 7 右親指 4キー (x=8, 9, 13, 14)
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
    ),
    [_LAYER3] = LAYOUT(
        // Row 0 左 6キー
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Row 0 右 6キー
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        // Row 1 左 6キー
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Row 1 右 6キー
        KC_TRNS, MS_BTN1, MS_BTN2, MS_BTN3, MS_BTN4, KC_TRNS,

        // Row 2 左 7キー (x=0〜6, 追加キー[2,6]含む)
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Row 2 右 7キー (x=8〜14, 追加キー[6,0]含む)
        MS_WHLL, MS_WHLD, MS_WHLR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        // Row 3 左親指 7キー (x=0〜6)
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Row 7 右親指 4キー (x=8, 9, 13, 14)
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)
    },
    [_LOWER] = {
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    [_RAISE] = {
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    [_LAYER3] = {
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    }
};
#endif

#if defined(POINTING_DEVICE_ENABLE)
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (mouse_report.x == 0 && mouse_report.y == 0) {
        return mouse_report;
    }

    double dx = mouse_report.x;
    double dy = mouse_report.y;
    double speed = sqrt(dx * dx + dy * dy);

    double factor = 1.0;
    
    if (speed < 2.0) {
        factor = 0.4; // Low-speed deceleration
    } else {
        factor = 0.4 + (speed - 2.0) * 0.15; // Accelerate proportionally
        if (factor > 2.0) {
            factor = 2.0; // Acceleration ceiling
        }
    }
    double new_x = dx * factor;
    double new_y = dy * factor;

    mouse_report.x = (new_x > 0) ? (int8_t)(new_x + 0.5) : (int8_t)(new_x - 0.5);
    mouse_report.y = (new_y > 0) ? (int8_t)(new_y + 0.5) : (int8_t)(new_y - 0.5);

    return mouse_report;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_ln_P(PSTR("BASE"), false);
                break;
            case _LOWER:
                oled_write_ln_P(PSTR("LOWER"), false);
                break;
            case _RAISE:
                oled_write_ln_P(PSTR("RAISE"), false);
                break;
            case _LAYER3:
                oled_write_ln_P(PSTR("LAYER3"), false);
                break;
            default:
                oled_write_ln_P(PSTR("UNKNOWN"), false);
        }
        
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.caps_lock ? PSTR("CAPS ") : PSTR("caps "), false);
        oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("num "), false);
    } else {
        oled_write_ln_P(PSTR("Ortholith"), false);
        oled_write_ln_P(PSTR("Split Keyboard"), false);
    }
    return false;
}
#endif
