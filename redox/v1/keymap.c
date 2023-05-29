/* Copyright 2023 Álvaro Serrano
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

#define _QWERTY 0
#define _SYM 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYM,
  NAV,
  ADJUST,
};

// Aliases for readability
#define CTL_P   LCTL(KC_P)
#define CT_SFP  LCTL(LSFT(KC_P))
#define SYM_QT  LT(_SYM, KC_QUOT)
#define ALT_F2  LALT(KC_F2)
#define CT_SLSH LCTL(KC_SLSH)

#define CTL_S   LCTL(KC_S)
#define CTL_GRV LCTL(KC_GRV)
#define ALT_TAB LALT(KC_TAB)
#define CT_SFA  LCTL(LSFT(KC_A))
#define NAV_L   MO(_NAV)
#define ADJ_L   MO(_ADJUST)

#define CTL_Z   LCTL(KC_Z)
#define CTL_Y   LCTL(KC_Y)
#define CTL_F   LCTL(KC_F)
#define CTL_X   LCTL(KC_X)
#define CTL_C   LCTL(KC_C)
#define CTL_V   LCTL(KC_V)
#define CT_SFC  LCTL(LSFT(KC_C))
#define CT_SFV  LCTL(LSFT(KC_V))

#define PRT_SC LGUI(LSFT(KC_S))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
  * Base QWERTY layer
  *
  * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  * |  ` ~   |   1    |    2   |   3    |   4    |   5    |                                           |   6    |   7    |   8    |   9    |   0    | CapsLk | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |  Tab   |   Q    |    W   |   E    |   R    |   T    | Ctrl+/ |                         |Ct+Sf+A |   Y    |   U    |   I    |   O    |   P    |  - _   |
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |  Esc   |   A    |    S   |   D    |   F    |   G    |LAlt+F2 |                         |Alt+Tab |   H    |   J    |   K    |   L    |  ; :   |  = +   | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * | LShift |   Z    |    X   |   C    |   V    |   B    | Ctl+P  |Ct+Sf+P |       | Ctrl+` | Ctrl+S |   N    |   M    |   , <  |  . >   |  / ?   | RShift |
  * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
  * |  Ctrl  |  LAlt  |  LGUI  |  RAlt  |    |SYM/' " |   |  Bksp  | Delete |       | Enter  | Space  |   | LShift |    |  F12   |  NAV_L |  ADJ_L |        |
  * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  */ 
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_CAPS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,CT_SLSH ,                          CT_SFA  ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,ALT_F2  ,                          ALT_TAB ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,CTL_P   ,CT_SFP  ,        CTL_GRV ,CTL_S   ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LALT ,KC_LGUI ,KC_RALT ,     SYM_QT  ,    KC_BSPC ,KC_DEL  ,        KC_ENT  ,KC_SPC  ,    KC_LSFT ,     KC_F12  ,NAV_L   ,ADJ_L   ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

 /*
  * Sym layer: symbols
  *
  * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  * |        |   F1   |   F2   |   F3   |   F4   |   F5   |                                           |   F8   |   F9   |   F10  |   F11  |   F12  |        | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |        |   !    |   ?    |   (    |   )    |   _    |   F6   |                         |   F7   |   #    |   =    |   <    |   >    |   +    | Ctrl+X |
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |   ` ~  |   @    |   ^    |   {    |   }    |   |    |   \    |                         |   $    |   ←    |   ↓    |   ↑    |   →    |   -    | Ctrl+C | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |   --   |   ~    |   %    |   [    |   ]    |   &    | Ctrl+Z | Ctrl+Y |       |Ct+Sf+C |Ct+Sf+V |   *    |   :    |        |        |   /    | Ctrl+V |
  * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
  * |   --   |   --   |   --   |        |    |   --   |   |   --   |   --   |       |  --    |   --   |   |   --   |    | Ctrl+F |Prt Scr |        |        |
  * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  */  
  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_EXLM ,KC_QUES ,KC_LPRN ,KC_RPRN ,KC_UNDS ,KC_F6   ,                          KC_F7   ,KC_HASH ,KC_EQL  ,KC_LT   ,KC_GT   ,KC_PLUS ,CTL_X   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV  ,KC_AT   ,KC_CIRC ,KC_LCBR ,KC_RCBR ,KC_PIPE ,KC_BSLS ,                          KC_DLR  ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,KC_PMNS ,CTL_C   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_TILD ,KC_PERC ,KC_LBRC ,KC_RBRC ,KC_AMPR ,CTL_Z   ,CTL_Y   ,        CT_SFC  ,CT_SFV  ,KC_ASTR ,KC_COLN ,XXXXXXX ,XXXXXXX ,KC_PSLS ,CTL_V   ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,XXXXXXX ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     CTL_F   ,PRT_SC  ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

 /*
  * Nav layout: mouse navigation and other controls
  *
  * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  * |        |        |        |        |        |        |                                           |        |        |        |        |        |        | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |        |        |Mouse ↑ |        |MouseW ↑|        |        |                         |        |  Home  |Bright -|Bright +| PrtSc  |        |        |
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |        |Mouse ← |Mouse ↓ |Mouse → |MouseW ↓|        |        |                         |        | Page ↑ | Vol -  | Vol +  | Mute   |        |        | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |        |        | Power  | Sleep  |  Wake  |        |        |        |       |        |        | Page ↓ |        | ScLck  |        |        |        |
  * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
  * |        |        |        |        |    |        |   |        |        |       |        |        |   |        |    |        |   --   |        |        |
  * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  */  
  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_HOME ,KC_BRID ,KC_BRIU ,KC_PSCR ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_PGUP ,KC_VOLD ,KC_VOLU ,KC_MUTE ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_PWR  ,KC_SLEP ,KC_WAKE ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_PGDN ,XXXXXXX ,KC_SCRL ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

 /*
  * Adjust layout: RGB
  *
  * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  * |        |        |        |        |        |        |                                           |        |        |        |        |        |        | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |        |  Hue + |  Sat + |Bright +| Mode + |        |        |                         |        | Static | Breath |Rainbow |  Swirl | Snake  |        |
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |        |  Hue - |  Sat - |Bright -| Mode - |        |        |                         |        |Kni Rid |Christm |St grad |RGB test|Twinkle |        | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |        |        |        |        |        |        |        |        |       |        |        |        |        |        |        |        |        |
  * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
  * |        |        |        |        |    |        |   |        |        |       |        |        |   |        |    |        |        |   --   |        |
  * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  */  
  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RGB_HUI ,RGB_SAI ,RGB_VAI ,RGB_MOD ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,RGB_M_P ,RGB_M_B ,RGB_M_R ,RGB_M_SW,RGB_M_SN,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RGB_HUD ,RGB_SAD ,RGB_VAD ,RGB_RMOD,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,RGB_M_K ,RGB_M_X ,RGB_M_G ,RGB_M_T ,RGB_M_TW ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

//  /*
//   * Layer template
//   *
//   * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
//   * |        |        |        |        |        |        |                                           |        |        |        |        |        |        | 
//   * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//   * |        |        |        |        |        |        |        |                         |        |        |        |        |        |        |        |
//   * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//   * |        |        |        |        |        |        |        |                         |        |        |        |        |        |        |        | 
//   * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//   * |        |        |        |        |        |        |        |        |       |        |        |        |        |        |        |        |        |
//   * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
//   * |        |        |        |        |    |        |   |        |        |       |        |        |   |        |    |        |        |        |        |
//   * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
//   */  
//   [_LAYERINDEX] = LAYOUT(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//   //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
//   //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
//   ),
};