/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// Helpers

// Combos
const uint16_t PROGMEM enter_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(enter_combo, KC_ENT),
    COMBO(esc_combo, KC_ESC), 
};


// Layer shorthand
enum layer_names {
    _BASE,
    _FN,
    _SYM,
    _GAMING,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | ]      | Y      | U      | I      | O      | P      | \      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | L_CTRL | A      | S      | D      | F      | G      | HOME   | PG UP  | H      | J      | K      | L      | ;      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | Play   | Vol+   | Vol-   | LGUI   | LALT   |      SYMBOLS    |      SPACE      | FN     | LEFT   | DOWN   | UP     | RIGHT  |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_ortho_2x2u(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_MPLY, KC_VOLU, KC_VOLD, KC_LGUI, KC_LALT,     MO(_SYM),         KC_SPC,       MO(_FN), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /* Symbols Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        | [      | ]      |        |
     * |--------+--------+--------+--------+--------+-----------------+-----------------+--------+-----------------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        | {      | }      |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |        |        |        | LEFT   | DOWN   | UP     | RIGHT  |        |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |        |        |        | +      | =      |        |        | \      |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |                 |                 |        |        |        |        | GAMING |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_SYM] = LAYOUT_ortho_2x2u(
        KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PLUS, KC_EQL,  _______, _______, KC_BSLS, _______,
        _______, _______, _______, _______, _______,     _______,          _______,      _______, _______, _______, _______, TG(_GAMING)
    ),


    /* Function Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | `      | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | DEL    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * |        |        | MENU   |        |        |        |        |        |        |        |        |        | PRT SC |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        | RESET  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * |        |        |        |        |        |        |        |        |        | MUTE   | VOL DN | VOL UP | \      |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * |        |        |        |        |        |                 |                 |        |        |        |        |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_ortho_2x2u(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     _______,          _______,      _______, _______, _______, _______, _______
    ),

    /* Gaming SymbolsLayer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * |        |        |        |        |        |                 |                 |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * |        |        |        |        |        |                 |                 |        |        |        |        |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |                 |                 |        |        |        |        |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |                 |                 |        |        |        |        |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     * |        |        |        |        |        |                 |                 |        |        |        |        |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_GAMING] = LAYOUT_ortho_2x2u(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     KC_SPC,           _______,      _______, _______, _______, _______, TG(_GAMING)
    ),

};


/*
 * =========================================================================
 * RGB Toggles!
 * Change the underglow RBG toggles to display when switching between layers
 * =========================================================================
  */

/*
 * SYMBOL LAYER HIGHLIGHTING
 * This will turn the entire fton row (0-7) of LEDs to TEAL while the
 * layer is active.
 */
const rgblight_segment_t PROGMEM symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_TEAL}
);

/*
 * GAMING LAYER HIGHLIGHTING
 * This will turn all 7 of the front LEDs solid to a specific color while this
 * layer is active.
  */
const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED},
    {1, 1, HSV_TEAL},
    {2, 1, HSV_GREEN},
    {3, 1, HSV_BLUE},
    {4, 1, HSV_PURPLE},
    {5, 1, HSV_GOLD},
    {6, 1, HSV_RED}
);

// Define the array of layer color modifications. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    symbol_layer,    
    gaming_layer    
);


// Default layer RGB state
layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL+5);
  return state;
}

/*
 * Set the RGB lighting state to trigger based on the active state
 * of the layers
 */
layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _SYM));
  rgblight_set_layer_state(1, layer_state_cmp(state, _GAMING));
  return state;
}

// Keyboard init
void keyboard_post_init_user(void) {
    // Set Default Settings
    rgblight_sethsv(255, 255, 255);
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL+5); 

    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}
