/* Copyright 2015-2017 Jack Humbert
 *
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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FORWARD,
  _BACKWARD,
  _LEAVE,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FWD   MO(_FORWARD)
#define BWD   MO(_BACKWARD)
#define LV    MO(_LEAVE)

// tap dance declarations
enum {
    TD_SCLN, // colon / semicolon
    TD_SLSH, // fwd slash / back slash
    /* TD_FN0,                   */
    TD_QUOT,
    TD_LBRACKET,
    TD_RBRACKET
};

// tap dance definitions
qk_tap_dance_action_t 
tap_dance_actions[] = {
  [TD_SCLN]     = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
  [TD_SLSH]     = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLASH),
  /* [TD_FN0]      = ACTION_TAP_DANCE_DOUBLE(KC_FN0 , RESET), */
  [TD_QUOT]     = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
  [TD_LBRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *       0      1      2      3      4      5      6      7      8      9     10     11
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MTCE |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LV   |  BWD | Alt  | Lower|  Gui |    Space    | Entr | Raiz | GUI  | Alt  | FWD  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
//              0        1        2      3        4       5       6       7        8        9           10       11
           KC_TAB,    KC_Q,    KC_W,  KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,        KC_P, KC_BSPC,
    CTL_T(KC_ESC),    KC_A,    KC_S,  KC_D,    KC_F,   KC_G,   KC_H,   KC_J,    KC_K,    KC_L, TD(TD_SCLN), KC_QUOT,
          KC_LSPO,    KC_Z,    KC_X,  KC_C,    KC_V,   KC_B,   KC_N,   KC_M, KC_COMM,  KC_DOT, TD(TD_SLSH), KC_RSPC,
               LV,     BWD, KC_LALT, LOWER, KC_LGUI, KC_SPC, KC_SPC, KC_ENT,   RAISE,  KC_RGUI,    KC_RALT,     FWD 
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      | CAPS | DOT  |      |      |      | KP7  | KP8  | KP9  |  KP- | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MTCE |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | KP8  | KP5  | KP6  |  KP+ |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | KP1  | KP2  | KP3  |  KP* |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FN0  | Ctrl |  Alt | XXX  |  GUI |    SPACE    | KP0  | LEFT | DOWN |  UP  | RIGHT|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
//        0        1        2        3        4        5        6     7        8        9       10       11
     KC_TAB, _______, KC_CAPS,  KC_DOT, _______, _______, _______, KC_7,    KC_8,    KC_9, KC_PMNS, KC_BSPC,
     KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_4,    KC_5,    KC_6, KC_PPLS, KC_SLSH,
    _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_1,    KC_2,    KC_3, KC_PAST,  KC_ENT,
    _______, KC_LCTL, KC_LALT, XXXXXXX, KC_LGUI,  KC_SPC,  KC_SPC, KC_0, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT
),

/* Raise
 *       0      1      2      3      4      5      6      7      8      9     10     11 
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | MTCE | BWORD| FWORD| HOME |  END |      |      |   -  |   =  |      |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| PREV | PLAY | NEXT | MUTE | Vol- | Vol+ |   [  |   ]  |      |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    SPACE    | Enter| XXX  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
//              0              1               2              3        4        5        6                7                8        9       10       11
          KC_TILD,       KC_EXLM,          KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC,         KC_AMPR,         KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    CTL_T(KC_ESC), LALT(KC_LEFT), LALT(KC_RIGHT), KC_HOME,  KC_END, _______, _______,         KC_MINS,          KC_EQL, _______, _______, KC_BSLS,
          KC_LSFT,       KC_MPRV,        KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, TD(TD_LBRACKET), TD(TD_RBRACKET), _______, _______, KC_RSFT,
          _______,       _______,        _______, _______, _______,  KC_SPC,  KC_SPC,          KC_ENT,         XXXXXXX, _______, _______, _______
),

/* Backward
 *       0      1      2      3      4      5      6      7      8      9     10     11 
 * ,-----------------------------------------------------------------------------------.
 * |SWAP  |USWAP |      |      |      |      |      |      |LCLICK|RCLICK|      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |SWAP  |USWAP |      |      |      |      | LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | WHLLT| WHLDN| WHLUP| WHLRT|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | XXX  |      |      |      |    SPACE    |      |      |      |      |RESET |
 * `-----------------------------------------------------------------------------------'
 */
[_BACKWARD] = LAYOUT_planck_grid(
//        0        1        2        3        4        5        6        7        8        9       10       11
    LAG_SWP, LAG_NRM, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______,
    RAG_SWP, RAG_NRM, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
    XXXXXXX, _______, _______, _______, _______,  KC_SPC,  KC_SPC, _______, _______, _______, _______,   RESET
),

/* Forward
 *       0      1      2      3      4      5      6      7      8      9     10     11 
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |  DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    SPACE    |      |      |      |      | XXX  |
 * `-----------------------------------------------------------------------------------'
 */
[_FORWARD] = LAYOUT_planck_grid(
//        0        1        2        3        4        5        6        7        8         9       10       11
     KC_GRV, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN,   KC_END, _______,  KC_DEL,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______,  KC_SPC,  KC_SPC,  KC_ENT, _______,  _______, _______, XXXXXXX
),

/* Leave
 *       0      1      2      3      4      5      6      7      8      9     10     11 
 * ,-----------------------------------------------------------------------------------.
 * |  `   |      |      |      |      |      |      |      |      |      |      | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |WHLLFT|WHLDWN|WHLUP |WHLRGT|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    SPACE    |      |      |      |      | XXX  |
 * `-----------------------------------------------------------------------------------'
 */
[_LEAVE] = LAYOUT_planck_grid(
//         0        1        2        3        4        5        6        7        8         9       10       11
     _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN,   KC_END, _______,  KC_DEL,
     _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
     _______, _______, _______, _______, _______,  KC_SPC,  KC_SPC,  KC_ENT, _______,  _______, _______, XXXXXXX
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _FORWARD);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                layer_on(_FORWARD);
            } else {
                layer_off(_FORWARD);
            }
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

// old MACRO
/* const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
 * {
 *   switch(id) {
 *     case 4: // Back delete
 *       if(record->event.pressed) {
 *         return MACRO(D(LALT), D(RSHIFT), T(LEFT), T(BSPC), END);
 *       } else {
 *         clear_keyboard();
 *       }
 *     break;
 *     case 5: // Forward delete
 *       if(record->event.pressed) {
 *         return MACRO(D(LALT), D(RSHIFT), T(RIGHT), T(BSPC), END);
 *       } else {
 *         clear_keyboard();
 *       }
 *     break;
 *   }
 *   return MACRO_NONE;
 * }; */
// for leader
void matrix_scan_user(void) {
}
