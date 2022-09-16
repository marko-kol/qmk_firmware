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

//Setting up what encoder rotation does. If your encoder can be pressed as a button, that function can be set in Via.

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (layer_state_is(1)) {
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
        } else if (layer_state_is(3)) {
            if (clockwise) {
                tap_code16(C(KC_LEFT));
            } else {
                tap_code16(C(KC_RGHT));
            }
        }
    }
    else if (index == 1) {
        if (layer_state_is(1)) {
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDOWN);
            }
        } else if (layer_state_is(3)) {
            if (clockwise) {
                tap_code16(C(KC_Z));
            } else {
                tap_code16(C(KC_Y));
            }
        }
    }
    return false;
}

#endif
