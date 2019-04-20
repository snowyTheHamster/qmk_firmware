#include QMK_KEYBOARD_H


#define TT_BACK LALT(KC_LEFT)
#define TT_FORW LALT(KC_RIGHT)
#define TT_COPY LCTL(KC_INS)
#define TT_PASTE LSFT(KC_INS)
#define TT_VIRL LGUI(LCTL(KC_LEFT))
#define TT_VIRR LGUI(LCTL(KC_RIGHT))
#define TT_CHROR LCTL(KC_TAB)
#define TT_CHROL LCTL(LSFT(KC_TAB))
#define TT_TABW LCTL(KC_W)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
    RSFT_T(KC_Z), KC_V, KC_W, LT(1, KC_M), LT(2, KC_B), KC_SPC, LT(3, KC_K), MT(MOD_LGUI, KC_J), KC_Q, LSFT_T(KC_SCLN),
    KC_S, KC_N, KC_T, KC_H, KC_D, KC_I, KC_U, KC_E, KC_O,LT(4, KC_A),
    MT(MOD_RCTL, KC_L), KC_R, KC_C, KC_G, KC_F, KC_Y, KC_P, KC_DOT, KC_COMM, MT(MOD_LCTL, KC_QUOT)
  ),

  [1] = LAYOUT_ortho_3x10( //Numbers
    KC_RSFT, XXXXXXX, KC_LALT, _______, XXXXXXX, KC_SPC, KC_F9, KC_F8, KC_F7, KC_LSFT,
    KC_ENT, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F3, KC_F2, KC_F1, KC_TAB,
    MT(MOD_RCTL, KC_0), KC_9, KC_8, KC_7, KC_6, KC_5, KC_4, KC_3, KC_2, MT(MOD_LCTL, KC_1)
  ),

  [2] = LAYOUT_ortho_3x10( //Symbols
    KC_RSFT, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_X, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,
    XXXXXXX, KC_BSLS, KC_EQL, KC_SLSH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,
    MT(MOD_LCTL, KC_MINUS), KC_GRV, KC_RBRC, KC_LBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC, KC_LCTL
  ),

  [3] = LAYOUT_ortho_3x10( //Navigation thumb
    KC_DEL, KC_INS, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, _______, XXXXXXX, XXXXXXX, TT_TABW,
    KC_END, KC_HOME, TT_CHROR, TT_CHROL, XXXXXXX, KC_VOLD, TT_PASTE, TT_COPY, LALT(KC_TAB), LGUI(KC_TAB),
    KC_PGDN, KC_PGUP, TT_FORW, TT_BACK, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, TT_VIRR, TT_VIRL
  ),

  [4] = LAYOUT_ortho_3x10( //Arrow pinky
    KC_RSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,
    KC_END, KC_HOME, TT_CHROR, TT_CHROL, XXXXXXX, XXXXXXX, KC_RIGHT, KC_DOWN, KC_LEFT, _______,
    KC_PGDN, KC_PGUP, TT_FORW, TT_BACK, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP ,XXXXXXX, XXXXXXX
  ),


};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {
    DDRD |= (1 << 5); PORTD &= ~(1 << 5);
  } else {
    DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    DDRB |= (1 << 0); PORTB &= ~(1 << 0);
  } else {
    DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_COMPOSE)) {

  } else {

  }

  if (usb_led & (1 << USB_LED_KANA)) {

  } else {

  }

}
