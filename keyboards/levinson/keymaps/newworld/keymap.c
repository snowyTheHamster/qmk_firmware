#include "levinson.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _NAVI 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  LOWER,
  RAISE,
  NAVI,
  ADJUST,
};

// Fillers to make layering more clear
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

[_QWERTY] = LAYOUT( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Dvorak
  * ,-----------------------------------------------------------------------------------.
  * |Tab   |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |Bksp  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |Lower |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |Shift |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |Ctrl  |Win.v |Alt   |GUI   |Navi  |Space |Space |Raise |Lang  |Ins   |Del   |Ctrl  |
  * `-----------------------------------------------------------------------------------'
*/
 [_DVORAK] = LAYOUT( \
  KC_TAB,  KC_QUOT, KC_COMM,  KC_DOT,   KC_P,     KC_Y,       KC_F,       KC_G,     KC_C,    KC_R,    KC_L,     KC_BSPC, \
  LOWER,   KC_A,    KC_O,     KC_E,     KC_U,     KC_I,       KC_D,       KC_H,     KC_T,    KC_N,    KC_S,     KC_ENTER, \
  KC_LSFT, KC_SCLN, KC_Q,     KC_J,     KC_K,     KC_X,       KC_B,       KC_M,     KC_W,    KC_V,    KC_Z,     KC_RSFT, \
  KC_LCTL, TT_VIEW, KC_LALT,  KC_LGUI,  NAVI,     KC_SPC,     KC_SPC,     RAISE,    TT_LANG, KC_INS,  KC_DEL,   KC_RCTL \
 ),

/* Lower
  * ,-----------------------------------------------------------------------------------.
  * |Esc   |      |Up    |      |      |      |      |      |      |Pg.U  |Pg.D  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |Lower |Left  |Down  |Right |      |      |      |      |      |Home  |End   |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |Shift |      |      |      |      |      |      |      |      |      |      |Shift |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |Ctrl  |      |Alt   |GUI   |Lower |Space |Space |Raise |      |Ins   |Del   |Ctrl  |
  * `-----------------------------------------------------------------------------------'
*/
 [_LOWER] = LAYOUT( \
  KC_ESC,  XXXXXXX, KC_UP,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, \
  LOWER,   KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_END,  XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, \
  _______, XXXXXXX, _______, _______,  XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, KC_INS,  KC_DEL,  KC_RCTL \
 ),

/* Raise
  * ,-----------------------------------------------------------------------------------.
  * |Esc   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |   [  |   ]  |   `  |   -  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |Shift |      |      |      |      |      |      |   /  |   =  |   \  |      |Shift |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |Ctrl  |      |Alt   |GUI   |Navi  |Space |Space |Raise |      |Ins   |Del   |Ctrl  |
  * `-----------------------------------------------------------------------------------'
*/
 [_RAISE] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_GRV,  KC_MINUS, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, KC_EQL,  KC_BSLS, XXXXXXX,  KC_RSFT, \
  _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, RAISE,   XXXXXXX, KC_INS,  KC_DEL,   KC_RCTL \
 ),

/* NAVI
  * ,------+------+------+------+------+------+------+------+------+------+------+------.
  * |Esc   |#<-   |#->   |c.bk  |c.fr  |Vol.U |      |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |DEL   |#,tab |al,tab|c.left|c.rght|Vol.D |      |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |Shift |al-sp |   C  |Copy  |Paste |Mute  |      |      |      |      |      |Shift |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |Ctrl  |Ctl-w |Alt   |GUI   |Navi  |Space |Space |Raise |      |Ins   |Del   |Ctrl  |
  * `-----------------------------------------------------------------------------------'
*/
  [_NAVI] = LAYOUT( \
  KC_ESC,  TT_VIRL,      TT_VIRR,      TT_BACK,  TT_FORW,  KC_VOLU, XXXXXXX, TT_BACK,  TT_FORW,  XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_DEL,  LGUI(KC_TAB), LALT(KC_TAB), TT_CHROL, TT_CHROR, KC_VOLD, XXXXXXX, TT_CHROL, TT_CHROR, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, TT_ALTSPA,    KC_C,         TT_COPY,  TT_PASTE, KC_MUTE, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_RSFT, \
  _______, TT_TABW,      _______,      _______,  NAVI,     _______, _______, XXXXXXX,  XXXXXXX,  KC_INS,  KC_DEL,  KC_RCTL \
 ),

/* Adjust (Navi + Raise)
  * ,-----------------------------------------------------------------------------------.
  * |      |Reset |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |Audoff|Audoff|AGnorm|AGswap|Dvorak|Dvorak|Dvorak|      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
*/
[_ADJUST] =  LAYOUT( \
  RESET,   RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, \
  _______, _______, _______, AU_OFF,  AU_OFF,  AG_NORM, AG_SWAP, DVORAK,  DVORAK,  DVORAK,  DVORAK,  DVORAK, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
