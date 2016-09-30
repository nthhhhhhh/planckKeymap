#include "planck.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

/*timeout*/
#define LEADER_TIMEOUT 800

/* tap dances */
//Tap Dance Declarations
enum {
  TD_SCLN,
  TD_SLSH,
  TD_FN0,
  TD_QUOT,
  TD_LBRACKET,
  TD_RBRACKET
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
  [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLASH),
  [TD_FN0] = ACTION_TAP_DANCE_DOUBLE(KC_FN0, RESET),
  [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
  [TD_LBRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | MTCE |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FN0  | Ctrl | Alt  | Lower|  GUI |    Space    | Entr | Raiz | GUI  | Lead | Alt  |
 * `-----------------------------------------------------------------------------------'
 */
[0] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {CTL_T(KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD(TD_SCLN), KC_QUOT},
  {KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD(TD_SLSH), KC_RSPC},
  {KC_FN0,  KC_LCTL, KC_LALT, M(1), KC_LGUI,    KC_SPC,  KC_SPC,  KC_ENT,  M(2),    KC_RGUI, KC_LEAD, KC_RALT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |      | Caps |      |      |      |  KP7 |  KP8 |  KP9 |  KP- | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | MTCE |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  KP4 |  KP5 |  KP6 |  KP+ |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  KP1 |  KP2 |  KP3 |  KP* |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FN0  | Ctrl |  Alt |  GUI |      |             |  KP0 | LEFT | DOWN |  UP  | RIGHT|
 * `-----------------------------------------------------------------------------------'
 */
[1] = {
  {KC_TAB,  _______, _______,  KC_CAPS, _______,  _______, _______, KC_7, KC_8, KC_9, KC_PMNS, KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,    KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_4, KC_5, KC_6, KC_PPLS, KC_SLSH},
  {_______, KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_1, KC_2, KC_3, KC_PAST, KC_ENT },
  {KC_FN0,  KC_LCTL, KC_LALT,  KC_LGUI, _______, _______, KC_DOT,  KC_0, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | MTCE |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |      |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   [  |   ]  |      |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RESET|      |      |      |      |             | Enter|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[2] = {
  {KC_TILD,  KC_EXLM,  KC_AT,  KC_HASH,    KC_DLR,    KC_PERC,   KC_CIRC,  KC_AMPR,   KC_ASTR,  KC_LPRN,   KC_RPRN,    KC_BSPC},
  {CTL_T(KC_ESC),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  _______, _______, KC_BSLS},
  {KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  TD(TD_LBRACKET), TD(TD_RBRACKET), _______, _______, KC_RSFT},
  {RESET,   _______, _______, _______, _______, _______, _______, KC_ENT, _______, _______, _______, _______}
},

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 1:
      if (record->event.pressed) {
        layer_on(1);
      } else {
        layer_off(1);
      }
      break;
    case 2:
      if (record->event.pressed) {
        layer_on(2);
      } else {
        layer_off(2);
      }
      break;
  }
  return MACRO_NONE;
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    
    // maximize window
    // cmd + ctrl + alt + m
    SEQ_ONE_KEY(KC_H) {
      register_code(KC_LGUI);
      register_code(KC_LALT);
      register_code(KC_LCTL);
      register_code(KC_M);

      unregister_code(KC_LGUI);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
      unregister_code(KC_M);
    }

    // tile window top right
    // cmd + alt + up
    SEQ_ONE_KEY(KC_K) {
      register_code(KC_LGUI);
      register_code(KC_LALT);
      register_code(KC_UP);

      unregister_code(KC_LGUI);
      unregister_code(KC_LALT);
      unregister_code(KC_UP);
    }

    // tile window top left
    // ctrl + alt + up
    SEQ_ONE_KEY(KC_J) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_UP);

      unregister_code(KC_LCTL);
      unregister_code(KC_LALT);
      unregister_code(KC_UP);
    }

    // tile window bottom left
    // ctrl + alt + down
    SEQ_ONE_KEY(KC_M) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_DOWN);

      unregister_code(KC_LCTL);
      unregister_code(KC_LALT);
      unregister_code(KC_DOWN);
    }

    // tile window bottom right
    // cmd + alt + down
    SEQ_ONE_KEY(KC_COMM) {
      register_code(KC_LALT);
      register_code(KC_LGUI);
      register_code(KC_DOWN);

      unregister_code(KC_LALT);
      unregister_code(KC_LGUI);
      unregister_code(KC_DOWN);
    }

    // tile window left
    SEQ_TWO_KEYS(KC_J, KC_M) {
      register_code(KC_LCTL);
      register_code(KC_LGUI);
      register_code(KC_LEFT);

      unregister_code(KC_LCTL);
      unregister_code(KC_LGUI);
      unregister_code(KC_LEFT);
    }

    // tile window right
    SEQ_TWO_KEYS(KC_K, KC_COMM) {
      register_code(KC_LCTL);
      register_code(KC_LGUI);
      register_code(KC_RIGHT);

      unregister_code(KC_LCTL);
      unregister_code(KC_LGUI);
      unregister_code(KC_RIGHT);
    }

    // top half window
    SEQ_TWO_KEYS(KC_J, KC_K){
      register_code(KC_LALT);
      register_code(KC_LSHIFT);
      register_code(KC_UP);

      unregister_code(KC_LALT);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_UP);
    }

    // bottom half window
    SEQ_TWO_KEYS(KC_M, KC_COMM) {
      register_code(KC_LALT);
      register_code(KC_LSHIFT);
      register_code(KC_DOWN);

      unregister_code(KC_LALT);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_DOWN);
    }
  }
}
