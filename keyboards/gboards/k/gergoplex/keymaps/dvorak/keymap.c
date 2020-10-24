/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "keymap_steno.h"

#define _BASE 0 // dvroak layer
#define _SYMB 1 // symbols
#define _NUMB 2 // numbers/motion
#define _ADJUST 3 // stenography
#define _STENO 4 // stenography

/* Combo map -- see combos.def
 *
 * ,-----------------------------.      ,--------------------------------.
 * |     |    ESC   TAB    |     |      |     |    ENT   BSPC   |        |
 * |-----+-----+-----+-----+-----|      |--------------------------------|
 * |     |     |     |     |     |      |     |     |     |     |        |
 * |-----+-----+-----+-RMB-+-LMB-+      |--------------------------------|
 * |     |     |     |     |     |      |    DASH  UNDR  SPC    |        |
 * `-----+-----+-----+------+----'      `--------------------------------'
 *  .-------------------------.           .-----------------.   
 *  |        |       |        |           |     |     |     |
 *  '-------------------------'           '-----------------' 
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,------------------------------.      ,--------------------------------.
 * |   '  |  ,  |  .  |  P  |  Y  |      |  F  |  G  |  C  |  R  |    L   |
 * |------+-----+-----+-----+-----|      |--------------------------------|
 * |LSFT/A|CTL/O|ALT/E|CMD/U|  I  |      |  D  |CMD/H|ALT/T|CTL/N| SHFT/S |
 * |------+-----+-----+-----+-----|      |--------------------------------|
 * |   ;  |  Q  |  J  |  K  |  X  |      |  B  |  M  |  W  |  V  |    Z   |
 * `------+-----+-----+------+----'      `--------------------------------'
 *     .-----------------------.           .-----------------.
 *     |    | BSPC(SYM) |      |           |   |SPC(NUM)|    |
 *     '-----------------------'           '-----------------'
 */
[_BASE] = LAYOUT_gergoplex(
    KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, /**/ KC_F, KC_G, KC_C, KC_R, KC_L,
    LSFT_T(KC_A), LCTL_T(KC_O), LALT_T(KC_E), LGUI_T(KC_U), KC_I, /**/ KC_D, LGUI_T(KC_H), LALT_T(KC_T), LCTL_T(KC_N), LSFT_T(KC_S),
    KC_SCLN, KC_Q, KC_J, KC_K, KC_X, /**/ KC_B, KC_M, KC_W, KC_V, KC_Z,

    KC_NO, LT(_SYMB, KC_BSPC), KC_NO, /**/ KC_NO, LT(_NUMB, KC_SPC), KC_NO
    ),
/* Keymap 1: Symbols layer
 * ,------------------------------.      ,--------------------------------.
 * |   !  |  @  |  #  |  $  |  %  |      |  ^  |  &  |  *  |  \  |    |   |
 * |------+-----+-----+-----+-----|      |--------------------------------|
 * |   {  |  }  |  (  |  )  | PUP |      |  +  |  -  |  /  |  *  |    -   |
 * |------+-----+-----+-----+-----|      |--------------------------------|
 * |   `  |  ~  |  [  |  ]  | PDN |      |  =  |     |     |     |    '   |
 * `------+-----+-----+-----+-----'      `--------------------------------'
 *          .-----------------.           .------------------.
 *          | MMB |      |    |           |     |     |  DEL |
 *          '-----------------'           '------------------'
 */
[_SYMB] = LAYOUT_gergoplex(
    KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE,
    KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PGUP,   KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_MINS,
    KC_GRV , KC_TILD, KC_LBRC, KC_RBRC, KC_PGDN,   KC_EQL , KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOT,
                      CMB_TOG, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_DEL
    ),
/* Keymap 2: Pad/Function layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  6    |  7  |  8  |  9  |  0  |
 * |------+-----+-----+-----+-----|      |-------------------------------|
 * |  F1  | F2  | F3  | F4  |  F5 |      |  F11  | LFT | DWN | UP  | RGT |
 * |------+-----+-----+-----+-----|      |-------------------------------|
 * |  F6  | F7  | F8  | F9  | F10 |      |  F12  | MLFT| MDWN| MUP | MRGT|
 * `------+-----+-----+------+----'      `-------------------------------'
 *          .-----------------.           .-----------------.
 *          |     |    |      |           |     |     |     |
 *          '-----------------'           '-----------------'
 */
[_NUMB] = LAYOUT_gergoplex(
    KC_1,  KC_2,  KC_3,  KC_4,  KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,        KC_F11 , KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,       KC_F12 , KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
                KC_TRNS,KC_TRNS,KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS
    ),

/* ## Adjust (Lower and Raise)
 * ## ,------+------+------+------+------.          ,------+------+------+------+------.
 * ## |      |      |      |Steno |      |          |      |      |      |      |      |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          +------+------+------+------+------|
 * ## |      |      |Scrn  |Talon |      |          |      | Prev | Vol  | Vol  | Next |
 * ## |      |      |Saver |      |      |          |      |      | Down | Up   |      |
 * ## |------+------+------+------+------|          +------+------+------+------+------|
 * ## |      |      |      |      |      |          |      |      | Mute | Play |      |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## `------+------+------+------+------'          `------+------+------+------+------'
 * ##
 * ##               ,------+------+------.          ,------+------+------.
 * ##               |      |      |      |          |      |      |Reset |
 * ##               |      |      |      |          |      |      |      |
 * ##               `------+------+------'          `------+------+------'
 */
  [_ADJUST] = LAYOUT_gergoplex(
      KC_NO, KC_NO, KC_NO, TO(_STENO), KC_NO,             /**/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, HYPR(KC_BSPACE), HYPR(KC_TAB), KC_NO, /**/ KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  /**/ KC_NO, KC_NO, KC_MUTE, KC_MPLY, KC_NO,
                                     KC_NO, KC_NO, KC_NO, /**/ KC_NO, KC_NO, RESET
      ),


/* ## Steno (Plover)
 * ## ,------+------+------+------+------.          ,------+------+------+------+------.
 * ## |  #   |  #   |  #   |  #   |  #   |          |  #   |  #   |  #   |  #   | Exit |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          +------+------+------+------+------|
 * ## |  S   |  T   |  P   |  H   |  *   |          |  F   |  P   |  L   |  T   |  D   |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          +------+------+------+------+------|
 * ## |  S   |  K   |  W   |  R   |  *   |          |  R   |  B   |  G   |  S   |  Z   |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## `------+------+------+------+------'          `------+------+------+------+------'
 * ##
 * ##               ,------+------+------.          ,------+------+------.
 * ##               |  *   |  A   |  O   |          |  E   |  U   |  *   |
 * ##               |      |      |      |          |      |      |      |
 * ##               `------+------+------'          `------+------+------'
 */
  [_STENO] = LAYOUT_gergoplex(
      STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  /**/ STN_N6,  STN_N7,  STN_N8,  STN_N9,  TO(_BASE),
      STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, /**/ STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
      STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, /**/ STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
          STN_ST3, STN_A,   STN_O, /**/ STN_E, STN_U, STN_ST4
      ),

};


void keyboard_post_init_user(void) {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}


uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _SYMB, _NUMB, _ADJUST);
}
