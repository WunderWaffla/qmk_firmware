/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layers {
  _QW,
  _LW,
  _FN,
  _RS,
  _GAME,
  _REAPER,
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

#define M1_S DYN_REC_START1
#define M2_S DYN_REC_START2
#define M1_R DYN_MACRO_PLAY1
#define M2_R DYN_MACRO_PLAY2
#define M_STOP DYN_REC_STOP

#define FN_SPC LT(_FN, KC_SPC)
#define FN_BSP LT(_FN, KC_BSPC)
#define CTL_ESC CTL_T(KC_ESC)
#define SFT_MEH SFT_T(KC_PAUSE)
#define SFT_MIN GUI_T(KC_MINS)
#define CTL_QT MT(MOD_RCTL, KC_QUOT)
#define LW_SPC LT(_LW, KC_SPC)
#define LW_BSP LT(_LW, KC_BSPC)
#define FGUI GUI_T(KC_F2)
#define SFTGO SFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QW] = LAYOUT_5x6(
     KC_GRV,  KC_1, KC_2,    KC_3,    KC_4, KC_5,                      KC_6, KC_7, KC_8,    KC_9,  KC_0,     KC_EQL,
     KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R, KC_T,                      KC_Y, KC_U, KC_I,    KC_O,  KC_P,     KC_BSLS,
     CTL_ESC, KC_A, KC_S,    KC_D,    KC_F, KC_G,                      KC_H, KC_J, KC_K,    KC_L  ,KC_SCLN,  CTL_QT,
     SFT_MEH, KC_Z, KC_X,    KC_C,    KC_V, KC_B,                      KC_N, KC_M, KC_COMM, KC_DOT ,KC_SLSH, SFT_MIN,
                    KC_PGUP, KC_PGDN,                                              KC_LBRC, KC_RBRC,
                             FGUI,    LW_BSP,                        FN_SPC,  SFTGO,
                             KC_LEAD, FN_SPC,                        LW_BSP,  M6,
                             DF(_REAPER), KC_RALT,                   KC_LALT, DF(_GAME)
  ),

  [_REAPER] = LAYOUT_5x6(
     CTL_ESC,  KC_1, KC_2,    KC_3,    KC_4, KC_5,                      KC_6, KC_7, KC_8,    KC_9,  KC_0,     KC_EQL,
     KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R, KC_T,                      KC_Y, KC_U, KC_I,    KC_O,  KC_P,     KC_BSLS,
     KC_GRV,  KC_A,  KC_S,    KC_D,    KC_F, KC_G,                      KC_H, KC_J, KC_K,    KC_L  ,KC_SCLN,  CTL_QT,
     SFT_MEH, KC_Z,  KC_X,    KC_C,    KC_V, KC_B,                      KC_N, KC_M, KC_COMM, KC_DOT ,KC_SLSH, SFT_MIN,
                     KC_PGUP, KC_PGDN,                                              KC_LBRC, KC_RBRC,
                              KC_F2,   KC_BSPC,                       FN_SPC,  SFTGO,
                              KC_F3,   KC_SPC,                        LW_BSP,  M6,
                              KC_F4,   KC_RALT,                       KC_LALT, DF(_QW)
  ),

  [_GAME] = LAYOUT_5x6(
     CTL_ESC,  KC_1, KC_2,    KC_3,    KC_4, KC_5,                      KC_6, KC_7, KC_8,    KC_9,  KC_0,     KC_EQL,
     KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R, KC_T,                      KC_Y, KC_U, KC_I,    KC_O,  KC_P,     KC_BSLS,
     KC_GRV, KC_A, KC_S,    KC_D,    KC_F, KC_G,                      KC_H, KC_J, KC_K,    KC_L  ,KC_SCLN,  CTL_QT,
     SFT_MEH, KC_Z, KC_X,    KC_C,    KC_V, KC_B,                      KC_N, KC_M, KC_COMM, KC_DOT ,KC_SLSH, SFT_MIN,
                    KC_PGUP, KC_PGDN,                                              KC_LBRC, KC_RBRC,
                             KC_F2,  KC_BSPC,                       FN_SPC,  SFTGO,
                             KC_F3, KC_SPC,                        LW_BSP,  M6,
                             KC_F4, KC_RALT,                       KC_LALT, DF(_QW)
  ),

  [_FN] = LAYOUT_5x6(
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
     KC_CAPS, KC_BTN4, KC_BTN3, _______, M1_R,    M2_R,                 KC_HOME, KC_END,  KC_LBRC, KC_RBRC,  _______, KC_DEL,
     _______, M1_S,    M2_S,    M1_R,    M2_R,    M_STOP,               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  _______, _______,
     _______, M1,      M2,      M3,      M4,      M5,                   _______, _______, _______,  _______, _______, _______,
                       _______, _______,                                                  _______, _______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),

  [_LW] = LAYOUT_5x6(
     _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                       _______, _______,                                                _______, _______,
                                           _______,_______,          _______,_______,
                                           _______,_______,          _______,_______,
                                           _______,_______,          _______,_______
  ),

  [_RS] = LAYOUT_5x6(
     _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
     _______, _______, _______, M_STOP,  M1_S,    M2_S,              KC_INS,  KC_7,    KC_8,    KC_9,    KC_SLCK, KC_PAUS,
     _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY,           _______, KC_4,    KC_5,    KC_6,    _______, _______,
     RESET,   _______, _______, _______, _______, KC_PSCR,           KC_0,    KC_1,    KC_2,    KC_3,    _______, _______,
                       _______, _______,                                                _______, _______,
                                           _______,_______,          _______,_______,
                                           _______,_______,          _______,_______,
                                           _______,_______,          _______,_______
  ),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_J) {
      // Anything you can do in a macro.
      SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_RSHIFT) SS_UP(X_LSHIFT) SS_UP(X_RSHIFT));
    }
    SEQ_TWO_KEYS(KC_D, KC_E) {
    }
    SEQ_TWO_KEYS(KC_D, KC_P) {
      /* SEND_STRING(SS_LCTRL("a")SS_LCTRL("c")); */
    }
    SEQ_TWO_KEYS(KC_T, KC_P) {
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
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
        return false; break;
      case M3:
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
