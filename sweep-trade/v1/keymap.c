/* Copyright 2026 Álvaro Serrano
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

enum layers {
    _HYPER = 0,
};

// Sends Ctrl+Alt+Shift+kc
#define CAS(kc) LCTL(LALT(LSFT(kc)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /*
  * Hyper layer: C-Cancel, S-Sell, F-Flat, B-Buy
  *
  * ┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
  * | C Last |S B-5 25%| F B-2 | B B+2  | Size 1 |        |   -    |   -    |   -    |   -    |   -    |
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * | C Symb |S B-5 33%| F B-5 | B B+5  | Size 5 |        |   -    |   -    |   -    |   -    |   -    |
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * | C All  |S B-5 50%| F B-10| B B+10 | Size 10|        |   -    |   -    |   -    |   -    |   -    |
  * └────────┴────────┴────────┼────────┼────────┤        ├────────┼────────┼────────┴────────┴────────┘
  *                            | Size 15| Size 20|        |   -    |   -    |
  *                            └────────┴────────┘        └────────┴────────┘
  */
  [_HYPER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
     CAS(KC_F1),CAS(KC_F4),CAS(KC_F7),CAS(KC_F10),CAS(KC_1), XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
     CAS(KC_F2),CAS(KC_F5),CAS(KC_F8),CAS(KC_F11),CAS(KC_2), XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
     CAS(KC_F3),CAS(KC_F6),CAS(KC_F9),CAS(KC_F12),CAS(KC_3), XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┼────────┼────────┤        ├────────┼────────┼────────┴────────┴────────┘
                                CAS(KC_4),CAS(KC_5),        XXXXXXX, XXXXXXX
  //                           └────────┴────────┘        └────────┴────────┘
  ),
};
