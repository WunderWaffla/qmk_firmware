#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layers {
  _QW,
  _LW,
  _FN,
  _RS,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    M1,
    M2,
    M3,
    M4,
    M5,
    M6,
    DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define M1_S DYN_REC_START1
#define M2_S DYN_REC_START2
#define M1_R DYN_MACRO_PLAY1
#define M2_R DYN_MACRO_PLAY2
#define M_STOP DYN_REC_STOP

#define FN_SPC LT(_FN, KC_SPC)
#define FN_BSP LT(_FN, KC_BSPC)
#define CTL_ESC CTL_T(KC_ESC)
#define SFT_MEH SFT_T(KC_GRV)
#define SFT_MIN MT(MOD_RSFT, KC_MINS)
#define CTL_QT MT(MOD_RCTL, KC_QUOT)
#define LW_SPC LT(_LW, KC_SPC)
#define LW_BSP LT(_LW, KC_BSPC)
#define FGUI GUI_T(KC_F2)
#define GUIGO GUI_T(KC_ENT)
#define GUITAB LGUI_T(KC_TAB)
#define SFT_BSP SFT_T(KC_BSPC)
#define ALT_MNS ALT_T(KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( \
    KC_GRV,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                       KC_Y,  KC_U,  KC_I,   KC_O,   KC_P,    KC_LBRC,\
    CTL_ESC, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                       KC_H,  KC_J,  KC_K,   KC_L,   KC_SCLN, CTL_QT,\
    KC_BSLS, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                       KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH, ALT_MNS,\
                                  GUITAB,  LW_BSP, KC_LEAD, SFT_BSP, FN_SPC,GUIGO \
  ),

  [_FN] = LAYOUT( \
    KC_CAPS, KC_BTN4, _______, _______, _______, M1_R,                       KC_HOME, KC_END,  KC_LBRC, KC_RBRC, _______, KC_DEL,\
    _______, _______, _______, _______, _______, M2_R,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,\
    _______, M1,      M2,      M3,      M4,      M5,                         M1,      M2,      KC_PGUP, KC_PGDN, M5,      _______,\
                                        _______, _______,_______,   _______, _______,_______ \
  ),

  [_LW] = LAYOUT( \
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,\
    KC_GRV,  KC_1,    KC_2,  KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,\
    KC_F1,   KC_F2,   KC_F3, KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
                                      _______, _______, _______,   _______, _______, _______ \
  ),

  [_RS] = LAYOUT( \
    _______, _______, _______, M_STOP,  M1_S,    M2_S,                        KC_INS,  KC_7, KC_8, KC_9, KC_SLCK, _______,\
    _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY,                     _______, KC_4, KC_5, KC_6, _______, _______,\
    RESET,   _______, _______, _______, _______, KC_PSCR,                     KC_0,    KC_1, KC_2, KC_3, _______, _______,\
                                        _______, _______, _______,   _______, _______, _______ \
  )
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_LBRC) {
      SEND_STRING(SS_TAP(X_RBRC));
    }
    SEQ_TWO_KEYS(KC_LBRC, KC_LBRC) {
      register_code(KC_LSFT);
      register_code(KC_RBRC);
      unregister_code(KC_RBRC);
      unregister_code(KC_LSFT);
    }
    SEQ_ONE_KEY(KC_J) {
      // Anything you can do in a macro.
      SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_RSHIFT) SS_UP(X_LSHIFT) SS_UP(X_RSHIFT));
    }
    SEQ_TWO_KEYS(KC_D, KC_E) {
      SEND_STRING("docker exe"SS_TAP(X_TAB)"-it eva"SS_TAP(X_TAB)"backe"SS_TAP(X_TAB)"sh"SS_TAP(X_ENTER)"tail -f -n 1000 $LOG_PORTAL"SS_TAP(X_ENTER));
    }
    SEQ_TWO_KEYS(KC_D, KC_P) {
      SEND_STRING("docker exe"SS_TAP(X_TAB)"-it eva"SS_TAP(X_TAB)"post"SS_TAP(X_TAB)"bash"SS_TAP(X_ENTER)"psql -U postgres -d evalink -p 5132"SS_TAP(X_ENTER)"\\x auto"SS_TAP(X_ENTER));
      /* SEND_STRING(SS_LCTRL("a")SS_LCTRL("c")); */
    }
    SEQ_TWO_KEYS(KC_T, KC_P) {
      SEND_STRING("ssh -L 2050:localhost:5132 ");
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com"SS_TAP(X_ENTER));
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LW, _FN, _RS);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  if (record->event.pressed) {
    switch(keycode) {
      case M1:
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_E))));
        return false; break;
      case M2:
        SEND_STRING("@evalink.test");
        return false; break;
      case M3:
        SEND_STRING(""SS_TAP(X_ENTER));
        return false; break;
      case M4:
        SEND_STRING(SS_LSFT("ZQ"));
        return false; break;
      case M5:
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_P)))SS_TAP(X_F));
        return false; break;
      case M6:
        SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_RSHIFT) SS_UP(X_LSHIFT) SS_UP(X_RSHIFT));
        return false; break;
    }
  }
  return true;
};
