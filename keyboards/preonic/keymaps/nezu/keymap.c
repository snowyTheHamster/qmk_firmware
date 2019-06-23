#include QMK_KEYBOARD_H

enum preonic_layers {
  _DVORAK,
  _LOWER,
  _NAVI,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  DVORAK,
  LOWER,
  NAVI,
  RAISE,
  BACKLIT
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define TT_TABW LCTL(KC_W)
#define TT_BACK LALT(KC_LEFT)
#define TT_FORW LALT(KC_RIGHT)
#define TT_COPY LCTL(KC_INS)
#define TT_PASTE LSFT(KC_INS)
#define TT_UNDO LCTL(KC_Z)
#define TT_LANG LALT(KC_LSFT)
#define TT_VIEW LGUI(KC_TAB)
#define TT_CHROR LCTL(KC_TAB)
#define TT_CHROL LCTL(LSFT(KC_TAB))
#define TT_VIRWIN LGUI(LCTL(KC_D))
#define TT_VIRL LGUI(LCTL(KC_LEFT))
#define TT_VIRR LGUI(LCTL(KC_RIGHT))
#define TT_ALTSPA LALT(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DVORAK] = LAYOUT_preonic_grid( \
  TT_VIEW, KC_LEFT, KC_RIGHT, TT_CHROL, TT_CHROR, TT_ALTSPA,  TT_VIRWIN,  TT_VIRL,  TT_VIRR, XXXXXXX, XXXXXXX,  XXXXXXX, \
  KC_TAB,  KC_QUOT, KC_COMM,  KC_DOT,   KC_P,     KC_Y,       KC_F,       KC_G,     KC_C,    KC_R,    KC_L,     KC_BSPC, \
  LOWER,   KC_A,    KC_O,     KC_E,     KC_U,     KC_I,       KC_D,       KC_H,     KC_T,    KC_N,    KC_S,     KC_ENTER, \
  KC_LSFT, KC_SCLN, KC_Q,     KC_J,     KC_K,     KC_X,       KC_B,       KC_M,     KC_W,    KC_V,    KC_Z,     KC_RSFT, \
  KC_LCTL, TT_VIEW, KC_LALT,  KC_LGUI,  NAVI,    KC_SPC,     KC_SPC,     RAISE,    TT_LANG, KC_INS,  KC_DEL,   KC_RCTL \
),

[_LOWER] = LAYOUT_preonic_grid( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_ESC,  XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, \
  LOWER,   KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_END,  XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, \
  _______, XXXXXXX, _______, _______,  XXXXXXX,   _______, _______, XXXXXXX, XXXXXXX, KC_INS,  KC_DEL,  KC_RCTL \
),

[_NAVI] = LAYOUT_preonic_grid( \
  XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  \
  KC_ESC,  TT_VIRL,      TT_VIRR,      TT_BACK, TT_FORW,  KC_VOLU, XXXXXXX, TT_BACK,  TT_FORW,  XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_DEL,  LGUI(KC_TAB), LALT(KC_TAB), KC_HOME, KC_END,   KC_VOLD, XXXXXXX, TT_CHROL, TT_CHROR, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, TT_ALTSPA,    KC_C,         TT_COPY, TT_PASTE, KC_MUTE, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_RSFT, \
  _______, TT_TABW,      _______,      _______, NAVI,     _______, _______, XXXXXXX,  XXXXXXX,  KC_INS,  KC_DEL,  KC_RCTL \
),

[_RAISE] = LAYOUT_preonic_grid( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_GRV,  KC_MINUS, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, KC_EQL,  KC_BSLS, XXXXXXX,  KC_RSFT, \
  _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, RAISE,   XXXXXXX, KC_INS,  KC_DEL,   KC_RCTL \
),

[_ADJUST] = LAYOUT_preonic_grid( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, \
  _______, _______, _______, AU_OFF,   AU_OFF,  AG_NORM, AG_SWAP, DVORAK,  DVORAK, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case NAVI:
          if (record->event.pressed) {
            layer_on(_NAVI);
            update_tri_layer(_NAVI, _RAISE, _ADJUST);
          } else {
            layer_off(_NAVI);
            update_tri_layer(_NAVI, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_NAVI, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_NAVI, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            PORTE &= ~(1<<6);
          } else {
            unregister_code(KC_RSFT);
            PORTE |= (1<<6);
          }
          return false;
          break;
      }
    return true;
};
