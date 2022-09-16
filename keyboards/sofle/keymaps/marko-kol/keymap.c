 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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
#include "oled.c"
#include "encoder.c"

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

//Modified keymap by marko-kol. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Bksp |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    |  Caps |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  \   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /TO(3)  /       \TO(2) \  |Enter |   [  |   ]  |  -   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
  TD(TD_ESC_CAPS),  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,           KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
  KC_BSPC,          KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,          KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    KC_CAPS,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                 KC_LGUI,KC_LALT,KC_LCTRL, KC_SPC, TO(3),                     TO(2),  KC_ENT, KC_LBRC, KC_RBRC, KC_MINS
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Bksp |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  Mute |    |  Caps |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |  \   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /TO(3)  /       \TO(2) \  |Enter |   [  |   ]  |  -   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[1] = LAYOUT(
  TD(TD_ESC_CAPS), KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_TAB,          KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL,
  KC_BSPC,         KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT,         KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_CAPS,KC_K,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                 KC_LGUI,KC_LALT,KC_LCTRL, KC_ENT, KC_TRNS,            KC_TRNS,  KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS | Home |      |  Up  |      |N.LCK |                    |  Del |   7  |   8  |   9  |   -  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS | End  | Left | Down | Right|Scroll|-------.    ,-------|   *  |   4  |   5  |   6  |   +  |   |  |
 * |------+------+------+------+------+------|  Mute |    |  Caps |------+------+------+------+------+------|
 * | TRNS |  =   |  -   |  +   |   {  |   }  |-------|    |-------|   /  |   1  |   2  |   3  |   =  | TRNS |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS | TRNS | TRNS |Enter | / TRNS  /       \TO(1) \  |Space |   0  |   .  |   ,  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
  KC_GRV,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_TRNS, KC_HOME,  KC_NO,   KC_UP,   KC_NO,   KC_NLCK,                        KC_DEL,  KC_P7,   KC_P8,   KC_P9,  KC_PMNS, KC_F12,
  KC_TRNS, KC_END,   KC_LEFT, KC_DOWN, KC_RGHT, KC_SLCK,                        KC_PAST, KC_P4,   KC_P5,   KC_P6,  KC_PPLS, KC_BSLS,
  KC_TRNS, KC_EQL,   KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_MUTE,       KC_CAPS,KC_PSLS, KC_P1,   KC_P2,   KC_P3,  KC_EQL,  KC_TRNS,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS,       TO(1), KC_SPC, KC_P0, KC_PDOT, KC_COMM
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * | TRNS | TRNS | TRNS | TRNS | TRNS | TRNS |                    | TRNS | TRNS | TRNS | TRNS | TRNS | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS | Ins  |      |      |      |      |                    | PgUp | TRNS |  Up  | TRNS | TRNS | TRNS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS | LAlt |      |      |      | Enter|-------.    ,-------| PgDn | Left | Down | Right| TRNS | Ins  |
 * |------+------+------+------+------+------|  Mute  |   |  Caps |------+------+------+------+------+------|
 * | TRNS | Undo |      |      |      |      |--------|   |-------|      | TRNS |      | TRNS |      | TRNS |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS | TRNS | TRNS |Enter | /TO(1)  /       \TO(2) \  |Space | TRNS | TO(1)| TO(0)|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[3] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
  KC_TRNS, KC_INS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_PGUP, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_ENT,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_INS,
  KC_TRNS, KC_UNDO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_TRNS,    KC_CAPS,  KC_NO,   KC_TRNS, KC_NO,   KC_TRNS, KC_NO,   KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, TO(1),       TO(2), KC_SPC, KC_TRNS, TO(1), TO(0)
)
};