#include QMK_KEYBOARD_H

// Layers
enum layers {
    _FN    ,
    _GAMING,
    _MOUSE ,
    _QWERTY,
    _NAV   ,
    _SYM   ,
};

// Custom Keys
#define NXT_TAB  LCTL(KC_TAB)
#define PRV_TAB  RCS(KC_TAB)

#define MO_FN    MO(_FN)
#define MO_SYM   MO(_SYM)

#define TG_GAME  TG(_GAMING)
#define TG_MOUS  TG(_MOUSE)
#define TG_NAV   TG(_NAV)

#define SELW_L   RCS(KC_LEFT)
#define SELW_R   RCS(KC_RIGHT)

// Combos!
const uint16_t PROGMEM enter_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM home_combo[]  = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM end_combo[]   = {KC_K, KC_L, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(enter_combo, KC_ENT),
    COMBO(home_combo,  KC_HOME),
    COMBO(end_combo,   KC_END)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TG_NAV,           TG_GAME, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT, MO_SYM,                    KC_SPC,  KC_ENT,  MO_FN
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  _______, _______, _______, _______, KC_MUTE,                            _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, PRV_TAB, NXT_TAB, _______, _______, KC_MPLY,                            _______, _______, _______, KC_LCBR, KC_RCBR, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_GRV,  KC_TILD, _______, _______, KC_VOLU,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, KC_VOLD, KC_HOME,          KC_END,  KC_PLUS, KC_EQL,  _______, _______, KC_BSLS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, TG_MOUS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, TG_NAV,           _______, _______, SELW_L,  _______,  SELW_R, _______, KC_DEL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_DEL,  _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, QK_BOOT, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, MO_SYM,           _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_SPC,                    KC_SPC,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, KC_WH_U, KC_WH_D,                            _______, _______, KC_MS_U, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, KC_BTN1, KC_BTN2,                             _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,  _______,         _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,  _______, TG_MOUS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

/*
 * RGB Underglow Indexes
 * Left Half:  28, 29, 30, 31, 32, 33
 * Right Half: 62, 63, 64, 65, 66, 67
 */
bool rgb_matrix_indicators_kb(void) {
  if (is_keyboard_master()) {

    switch (get_highest_layer(layer_state)) {
      case (_GAMING):
        rgb_matrix_set_color(28, 0, 128, 155);
        rgb_matrix_set_color(29, 0, 128, 155);
        rgb_matrix_set_color(30, 0, 128, 155);
        rgb_matrix_set_color(31, 0, 128, 155);
        rgb_matrix_set_color(32, 0, 128, 155);
        rgb_matrix_set_color(33, 0, 128, 155);
        break;
      case (_SYM):
        rgb_matrix_set_color(28, 255, 208, 0);
        rgb_matrix_set_color(29, 255, 208, 0);
        rgb_matrix_set_color(30, 255, 208, 0);
        rgb_matrix_set_color(31, 255, 208, 0);
        rgb_matrix_set_color(32, 255, 208, 0);
        rgb_matrix_set_color(33, 255, 208, 0);
        break;
      case (_MOUSE):
        rgb_matrix_set_color(28, 255, 0, 166);
        rgb_matrix_set_color(29, 255, 0, 166);
        rgb_matrix_set_color(30, 255, 0, 166);
        rgb_matrix_set_color(31, 255, 0, 166);
        rgb_matrix_set_color(32, 255, 0, 166);
        rgb_matrix_set_color(33, 255, 0, 166);
        break;

    }
  } else {
    switch (get_highest_layer(layer_state)) {
      case (_GAMING):
        //rgb_matrix_set_color_all(0, 128, 155);
        rgb_matrix_set_color(62, 0, 128, 155);
        rgb_matrix_set_color(63, 0, 128, 155);
        rgb_matrix_set_color(64, 0, 128, 155);
        rgb_matrix_set_color(65, 0, 128, 155);
        rgb_matrix_set_color(66, 0, 128, 155);
        rgb_matrix_set_color(67, 0, 128, 155);
        break;
      case (_SYM):
        rgb_matrix_set_color(62, 255, 208, 0);
        rgb_matrix_set_color(63, 255, 208, 0);
        rgb_matrix_set_color(64, 255, 208, 0);
        rgb_matrix_set_color(65, 255, 208, 0);
        rgb_matrix_set_color(66, 255, 208, 0);
        rgb_matrix_set_color(67, 255, 208, 0);
        break;
      case (_MOUSE):
        rgb_matrix_set_color(62, 255, 0, 166);
        rgb_matrix_set_color(63, 255, 0, 166);
        rgb_matrix_set_color(64, 255, 0, 166);
        rgb_matrix_set_color(65, 255, 0, 166);
        rgb_matrix_set_color(66, 255, 0, 166);
        rgb_matrix_set_color(67, 255, 0, 166);
        break;
    }
  }

  return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_CYCLE_OUT_IN);
    rgb_matrix_set_speed(30);
}
