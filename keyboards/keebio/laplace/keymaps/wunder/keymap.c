#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;
// Combined Layers
/* #define LOWER ((1UL << _FN) | (1UL << _RS)) */
/* #define NUMPAD ((1UL << _FN2) | (1UL << _FN3)) */

/* enum custom_layers { */
enum planck_layers {
  _QW,
  _LW,
  _FN,
  _RS,
};

/* enum custom_keycodes { */
enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    M1,
    M2,
    M3,
    M4,
    M5,
    DYNAMIC_MACRO_RANGE
};


/* enum planck_keycodes { */
/* }; */
#include "dynamic_macro.h"

#define M1_S DYN_REC_START1
#define M2_S DYN_REC_START2
#define M1_R DYN_MACRO_PLAY1
#define M2_R DYN_MACRO_PLAY2
#define M_STOP DYN_REC_STOP

#define FN_SPC LT(_FN, KC_SPC)
#define RS_BSP LT(_RS, KC_BSPC)
#define CTL_ESC CTL_T(KC_ESC)
#define SFT_MEH SFT_T(KC_PAUSE)
#define SFT_MIN MT(MOD_RSFT, KC_MINS)
#define CTL_QT MT(MOD_RCTL, KC_QUOT)
#define LW_SPC LT(_LW, KC_SPC)
#define LW_EQL LT(_LW, KC_EQL)
#define FGUI GUI_T(KC_F2)
#define GUIGO GUI_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT(
    KC_TAB,   KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,   KC_BSPC,
    CTL_ESC,  KC_A,    KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  CTL_QT,
    SFT_MEH,  KC_Z,    KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SFT_MIN,
    _______,  LW_SPC,  FGUI,     _______,  RS_BSP,   FN_SPC,   GUIGO,  KC_LEAD,  KC_RALT,    _______
  ),

  [_FN] = LAYOUT(
    KC_CAPS,  KC_BTN4,  _______,  _______,  _______,  _______,  KC_HOME,  KC_END,   KC_LBRC,  KC_RBRC,  _______,  KC_DEL,  _______,
    _______,  M1_S,     M2_S,     M1_R,     M1_S,     M_STOP,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,
    _______,  M1,       M2,       M3,       M4,       M5,       KC_PGUP,  KC_PGDN,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______

  ),

  [_LW] = LAYOUT(
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_MOD, _______,  KC_PSCR, _______, KC_7,   KC_8,   KC_9,  _______,  _______,  _______,
    _______,  RGB_HUD,  RGB_SAD,  KC_MPRV, KC_MNXT,  KC_MPLY, _______, KC_4,   KC_5,   KC_6,  _______,  _______,
    _______,  _______,  _______,  _______, _______,  _______, KC_0,   KC_1,   KC_2,   KC_3,  _______,  _______,
    _______,  _______,  _______,  _______, _______,  _______, _______, _______, _______, _______
  ),

  [_RS] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3, KC_F4,   KC_F5,   KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    KC_GRV,  KC_1,    KC_2,  KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
    _______, _______, _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______
  ),
};

/* uint32_t layer_state_set_user(uint32_t state) { */
/*   return update_tri_layer_state(state, _FN, _RS, _LW); */
/* } */

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_J) {
      // Anything you can do in a macro.
      // SEND_STRING("QMK is awesome.");
      SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_RSHIFT) SS_UP(X_LSHIFT) SS_UP(X_RSHIFT));
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTRL("a")SS_LCTRL("c"));
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

// Process Combined Layers
/* uint32_t layer_state_set_user(uint32_t state) { */
/*     if ((state & LOWER) == LOWER) { */
/*         state |= 1UL << _LW; */
/*     } else { */
/*         state &= ~(1UL << _LW); */
/*     /1* } if ((state & SYSTEM) == SYSTEM) { *1/ */
/*     /1*     state |= 1UL << _SYSTEM; *1/ */
/*     /1* } else { *1/ */
/*     /1*     state &= ~(1UL << _SYSTEM); *1/ */
/*     } */
/*     return state; */
/* } */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  if (record->event.pressed) {
    switch(keycode) {
      case M1:
        SEND_STRING("gotogit"SS_TAP(X_ENTER));
        return false; break;
      case M2:
        SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_RSHIFT) SS_UP(X_LSHIFT) SS_UP(X_RSHIFT));
        return false; break;
      case M3:
        SEND_STRING("");
        return false; break;
      case M4:
        SEND_STRING(SS_LSFT("ZQ"));
        return false; break;
      case M5:
        SEND_STRING(SS_LSFT("ZZ"));
        return false; break;
    }
  }
  return true;
};

/* void dip_update(uint8_t index, bool active) { */
/*   switch (index) { */
/*     case 0: */
/*       if (active) { */
/*         layer_on(_LW); */
/*       } else { */
/*         layer_off(_LW); */
/*       } */
/*       break; */
/*    } */
/* } */

  /* //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐ */
  /*    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CTL_QT, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    SFT_MEH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT,          KC_RALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_MIN, */
  /* //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘ */
  /*                                   FGUI,    FN_BSP,  LW_SPC,                    KC_LEAD,  FN_SPC,  GUIGO */
  /*                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘ */
  /* //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐ */
  /*    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    KC_CAPS, KC_BTN4, KC_BTN5, KC_BTN3, _______, _______,                            KC_HOME, KC_END,  KC_LBRC, KC_RBRC, _______, KC_DEL, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    _______, M1_S,    M2_S,    M1_R,    M2_R,    M_STOP,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS, _______, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    _______, M1,      M2,      M3,      M4,      M5,      _______,          _______, KC_PGUP, KC_PGDN, KC_EQL,  _______, _______, QWERTY, */
  /* //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘ */
  /*                                   _______, _______, _______,                   _______, _______, _______ */
  /*                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘ */
  /* //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐ */
  /*    _______, _______, _______, KC_INS,  KC_SLCK, KC_PAUS,                            _______, _______, _______, _______, _______, _______, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    _______, _______, _______, _______, _______, KC_PSCR,                            _______, _______, _______, _______, _______, _______, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    _______, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY,                            _______, _______, _______, _______, _______, _______, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    RESET,   _______, _______, _______, _______, _______, GAME,             _______, _______, _______, _______, _______, _______, _______, */
  /* //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘ */
  /*                                   _______,   _______, _______,                   _______, _______, _______ */
  /*                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘ */

  /* [_GAME] = LAYOUT( */
  /* //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐ */
  /*    CTL_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    LW_EQL, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CTL_QT, */
  /* //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤ */
  /*    SFT_MEH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F1,            KC_RALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_MIN, */
  /* //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘ */
  /*                                   KC_F5,   KC_BSPC, KC_F4,                     KC_F3,   FN_SPC,   GUIGO */
  /*                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘ */
  /* ), */
