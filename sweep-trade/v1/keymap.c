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
    _MAIN = 0,
    _SECONDARY,
};

// Sends Ctrl+Alt+Shift+kc
#define CAS(kc) LCTL(LALT(LSFT(kc)))

// Tap: Ctrl+Alt+Shift+5, Hold: secondary layer
#define CAS5_SEC LT(_SECONDARY, KC_5)

/*
 * Shortcut numbering: every key sends CAS(kc). Each key position has a fixed
 * code, reserved even when the key is unused (XXXXXXX). Codes go in the order
 * F1-F12, 1-9, 0, then A-Z, by position: columns left to right, top to bottom
 * within each column, thumb keys last. _SECONDARY continues after _MAIN.
 *
 * _MAIN left half:
 *   F1  F4  F7  F10  1
 *   F2  F5  F8  F11  2
 *   F3  F6  F9  F12  3
 *               4    5   (5 is also the layer key on hold)
 *
 * _SECONDARY left half:
 *   6  9  B  E  H
 *   7  0  C  F  I
 *   8  A  D  G  J
 *            K  L   (L reserved: that position is the layer key)
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /*
  * Main layer: C-Cancel, S-Sell, F-Flat, B-Buy
  * Size 20*: tap for Size 20, hold for secondary layer
  *
  * ┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
  * | C Last |S B-5 25%| F B-2 | B B+2  | Size 1 |        |   -    |   -    |   -    |   -    |   -    |
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * | C Symb |S B-5 33%| F B-5 | B B+5  | Size 5 |        |   -    |   -    |   -    |   -    |   -    |
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * | C All  |S B-5 50%| F B-10| B B+10 | Size 10|        |   -    |   -    |   -    |   -    |   -    |
  * └────────┴────────┴────────┼────────┼────────┤        ├────────┼────────┼────────┴────────┴────────┘
  *                            | Size 15|Size 20*|        |   -    |   -    |
  *                            └────────┴────────┘        └────────┴────────┘
  */
  [_MAIN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
     CAS(KC_F1),CAS(KC_F4),CAS(KC_F7),CAS(KC_F10),CAS(KC_1), XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
     CAS(KC_F2),CAS(KC_F5),CAS(KC_F8),CAS(KC_F11),CAS(KC_2), XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
     CAS(KC_F3),CAS(KC_F6),CAS(KC_F9),CAS(KC_F12),CAS(KC_3), XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┼────────┼────────┤        ├────────┼────────┼────────┴────────┴────────┘
                                CAS(KC_4),CAS5_SEC,         XXXXXXX, XXXXXXX
  //                           └────────┴────────┘        └────────┴────────┘
  ),

 /*
  * Secondary layer: F-Flat, B-Buy, P-Price input, MKT-Market, T-Test
  *
  * ┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
  * |   -    |   -    | F MKT  | B MKT  |P + 0.01|        |   -    |   -    |   -    |   -    |   -    |
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * | Test B |   -    | F Fixed| B Fixed|P = Ask |        |   -    |   -    |   -    |   -    |   -    |
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * |T -0.01 |T +0.01 |   -    |   -    |P - 0.01|        |   -    |   -    |   -    |   -    |   -    |
  * └────────┴────────┴────────┼────────┼────────┤        ├────────┼────────┼────────┴────────┴────────┘
  *                            |   -    |   ▼    |        |   -    |   -    |
  *                            └────────┴────────┘        └────────┴────────┘
  */
  [_SECONDARY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, CAS(KC_B),CAS(KC_E),CAS(KC_H),      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
     CAS(KC_7),XXXXXXX,CAS(KC_C),CAS(KC_F),CAS(KC_I),      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
     CAS(KC_8),CAS(KC_A),XXXXXXX, XXXXXXX, CAS(KC_J),      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┼────────┼────────┤        ├────────┼────────┼────────┴────────┴────────┘
                                XXXXXXX, _______,          XXXXXXX, XXXXXXX
  //                           └────────┴────────┘        └────────┴────────┘
  ),
};

/*
 * CAS5_SEC is a layer-tap key, but LT() can only send unmodified keys, so a
 * tap would send a plain 5. Intercept the tap and send Ctrl+Alt+Shift+5
 * instead; a hold falls through to QMK and activates the secondary layer.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CAS5_SEC:
            // LT only supports basic keycodes, so send the modded tap manually
            if (record->tap.count && record->event.pressed) {
                tap_code16(CAS(KC_5));
                return false;
            }
            break;
    }
    return true;
}
