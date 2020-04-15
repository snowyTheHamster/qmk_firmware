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
    MT(MOD_LCTL, KC_QUOT),   KC_COMM,    KC_DOT,              KC_P,          KC_Y,            KC_F,            KC_G,          KC_C,    KC_R,    MT(MOD_RCTL, KC_L),
    LT(4, KC_A),             KC_O,       KC_E,                KC_U,          KC_I,            KC_D,            KC_H,          KC_T,    KC_N,    KC_S,
    LSFT_T(KC_SCLN),         MT(MOD_LALT, KC_Q),       MT(MOD_LGUI, KC_J),  LT(3, KC_K),   KC_SPC,          LT(2, KC_B),     LT(1, KC_M),   KC_W,    KC_V,    RSFT_T(KC_Z)
  ),

  [1] = LAYOUT_ortho_3x10( //Numbers
    MT(MOD_LCTL, KC_1),    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    MT(MOD_RCTL, KC_0),
    KC_TAB,                KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_BSPC, KC_ENT,
    KC_LSFT,               KC_LALT, KC_F1,   KC_F9,   XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_RSFT
  ),

  [2] = LAYOUT_ortho_3x10( //Symbols
    KC_LCTL,  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_GRV,  MT(MOD_LCTL, KC_MINUS),
    KC_TAB,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, KC_EQL,  KC_BSLS, XXXXXXX,
    KC_LSFT,  KC_LALT, XXXXXXX, XXXXXXX, KC_X,    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT
  ),

  [3] = LAYOUT_ortho_3x10( //Navigation thumb
    TT_VIRL,      TT_VIRR,       TT_CHROL, TT_CHROR,  KC_VOLU,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, KC_RCTL,
    LGUI(KC_TAB), LALT(KC_TAB),  TT_COPY,  TT_PASTE,  KC_VOLD,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
    TT_TABW,      KC_LALT,       XXXXXXX,  _______,   KC_MUTE,  XXXXXXX, XXXXXXX,  XXXXXXX,  KC_INS,  KC_DEL
  ),

  [4] = LAYOUT_ortho_3x10( //Arrow pinky
    BL_TOGG, XXXXXXX, KC_UP,    XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  KC_PGUP, KC_PGDN,
    _______, KC_LEFT, KC_DOWN,  KC_RIGHT,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  KC_HOME, KC_END,
    KC_LSFT, KC_LALT, XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, KC_RSFT
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
