#include QMK_KEYBOARD_H

#define _BASE 0
#define _HELPER 1
#define _GAMING 2
#define _MISC 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all(
    KC_F1,   KC_F2,   KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_BSPC, KC_HOME,
    KC_F3,   KC_F4,   KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    KC_F5,   KC_F6,   LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_PGUP,
    KC_F7,   KC_F8,   KC_LSFT,        KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    KC_F9,   KC_F10,  KC_F11,         KC_F12,  KC_LGUI, KC_LALT,   KC_SPC,  KC_SPC,  KC_SPC,   KC_SPC,  KC_GESC, KC_RCTL, TG(_GAMING), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_HELPER] = LAYOUT_all(
    _______, _______, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,  KC_BSPC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_GAMING] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_MISC] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL+5);
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _HELPER));
  rgblight_set_layer_state(1, layer_state_cmp(state, _GAMING));
  return state;
}

// This will turn the entire row (8 with a length of 8) of LEDs on TEAL while the
// layer is active. 
const rgblight_segment_t PROGMEM helpers_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 8, HSV_TEAL}
);

// This will turn all 8 of the front LEDs solid to a specific color while this
// layer is active.
const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 1, HSV_RED},
    {9, 1, HSV_TEAL},
    {10, 1, HSV_GREEN},
    {11, 1, HSV_BLUE},
    {12, 1, HSV_PURPLE},
    {13, 1, HSV_GOLD},
    {14, 1, HSV_RED},
    {15, 1, HSV_TEAL}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    helpers_layer,    // Overrides caps lock layer
    gaming_layer    // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Set Default Settings
    rgblight_sethsv(255, 255, 255);
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL+5); 

    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

// Encoder Configurations
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
