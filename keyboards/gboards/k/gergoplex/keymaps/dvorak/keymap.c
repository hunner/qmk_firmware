/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0 // dvroak layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

/* Combomap
 *
 * ,-----------------------------.      ,--------------------------------.
 * |     |    ESC    |     |     |      |     |    ENT    |    BSPC      |
 * |-----+-----+-----+-----+-----|      |--------------------------------|
 * |     |     |     |     |     |      |     |     |     |     |        |
 * |-----+-----+-----+-RMB-+-LMB-+      |--------------------------------|
 * |     |    TAB    |     |     |      |    QUO   UNDR   |    SPC       |
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
 *     | ESC | DEL | BSPC(SYM) |           |SPC(NUM)| ENT|TAB|
 *     '-----------------------'           '-----------------'
 */
[BASE] = LAYOUT_gergoplex(
    KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, /**/ KC_F, KC_G, KC_C, KC_R, KC_L,
    LSFT_T(KC_A), LCTL_T(KC_O), LALT_T(KC_E), LGUI_T(KC_U), KC_I, /**/ KC_D, LGUI_T(KC_H), LALT_T(KC_T), LCTL_T(KC_N), LSFT_T(KC_S),
    KC_SCLN, KC_Q, KC_J, KC_K, KC_X, /**/ KC_B, KC_M, KC_W, KC_V, KC_Z,

    KC_ESC, KC_DELETE, LT(SYMB, KC_BSPC), /**/ LT(NUMB, KC_SPC), KC_ENT, KC_TAB
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
 *          | MMB |  ;   |  = |           |  =  |  ;  |  DEL |
 *          '-----------------'           '------------------'
 */
[SYMB] = LAYOUT_gergoplex(
    KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_PIPE,
    KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PGUP,   KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_MINS,
    KC_GRV , KC_TILD, KC_LBRC, KC_RBRC, KC_PGDN,   KC_EQL , KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOT,
                      CMB_TOG, KC_SCLN, KC_EQL ,   KC_EQL , KC_SCLN, KC_DEL
    ),
/* Keymap 2: Pad/Function layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  6    |  7  |  8  |  9  |  0  |
 * |------+-----+-----+-----+-----|      |-------------------------------|
 * |  F1  | F2  | F3  | F4  |  F5 |      | VOLUP | LFT | DWN | UP  | RGT |
 * |------+-----+-----+-----+-----|      |-------------------------------|
 * |  F6  | F7  | F8  | F9  | F10 |      | VOLDN | MLFT| MDWN| MUP | MRGT|
 * `------+-----+-----+------+----'      `-------------------------------'
 *          .-----------------.           .-----------------.
 *          | F11 | F12|      |           |     | PLY | SKP |
 *          '-----------------'           '-----------------'
 */
[NUMB] = LAYOUT_gergoplex(
    KC_1,  KC_2,  KC_3,  KC_4,  KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,        KC_VOLU, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,       KC_VOLD, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
                  KC_F11,KC_F12,KC_TRNS,      KC_TRNS,KC_MPLY,KC_MNXT
    )
};
