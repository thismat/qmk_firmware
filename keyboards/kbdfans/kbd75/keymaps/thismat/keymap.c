#include QMK_KEYBOARD_H

/* Keyboard Layout
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
 * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┼───┤
 * │   │   │   │   │   │   │   │   │   │   │   │   │   │  2U   │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │1.5U │   │   │   │   │   │   │   │   │   │   │   │   │1.5U │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │1.75U │   │   │   │   │   │   │   │   │   │   │   │2.25U   │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │2.25U   │   │   │   │   │   │   │   │   │   │   │1.75U │   │   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │1.25│1.25│1.25│6.25U                   │1U │1U │1U │1U │1U │1U │
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 */

 enum layers {
   QWERTY,
   HELPERS,
   GAMING,
 };


/* Macros */
#define KC_HMSL LSFT(KC_HOME) // Select everything to home
#define KC_ENSL  LSFT(KC_END) // Select everything to end

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT(
    KC_ESC,          KC_F1,    KC_F2,    KC_F3,    KC_F4,       KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_VOLD,  KC_VOLU,  KC_MPLY,
    KC_GRV,          KC_1,     KC_2,     KC_3,     KC_4,        KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   _______,  KC_BSPC,  KC_HOME,
    KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,        KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
    LCTL_T(KC_ESC),  KC_A,     KC_S,     KC_D,     LT(1, KC_F), KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_PGDN,
    KC_LSFT,         _______,  KC_Z,     KC_X,     KC_C,        KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
    MO(1),           KC_LGUI,  KC_LALT,                         KC_SPC,   KC_SPC,   KC_SPC,                       KC_RALT,  KC_RCTL,  TG(2),    KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [HELPERS] = LAYOUT(
    RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_DEL,   _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_HMSL,  KC_ENSL,  KC_END,   _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,  _______,  VLK_TOG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),

  [GAMING] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_VOLD,  KC_VOLU,  KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   _______,  KC_BSPC,  KC_HOME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_PGDN,
    KC_LSFT,  _______,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
    MO(1),  KC_LGUI,  KC_LALT,                      KC_SPC,   KC_SPC,   KC_SPC,                         KC_RALT,  KC_RCTL,  TG(2),    KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

};

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL+5);
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, HELPERS));
  rgblight_set_layer_state(1, layer_state_cmp(state, GAMING));
  return state;
}

// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM helpers_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 8, HSV_TEAL}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
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