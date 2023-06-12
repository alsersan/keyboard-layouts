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

enum layers {
    _QWERTY = 0,
    _DVORAK,
    _COLEMAK_DH,
    _SYM,
    _NUMFUNC,
    _NAV,
    _ADJUST,
};


// Aliases for readability
#define SYM_QT  LT(_SYM, KC_QUOT)
#define ADJ_TAB LT(_ADJUST, KC_TAB)
#define NUM_SPC LT(_NUMFUNC, KC_SPC)
#define CTL_P   LCTL(KC_P)
#define CT_SFP  LCTL(LSFT(KC_P))
#define CTL_S   LCTL(KC_S)
#define CTL_GRV LCTL(KC_GRV)

#define CTL_ESC MT(MOD_LCTL, KC_ESC)

#define CTL_Z   LCTL(KC_Z)
#define CTL_Y   LCTL(KC_Y)
#define CTL_F   LCTL(KC_F)
#define CTL_X   LCTL(KC_X)
#define CTL_C   LCTL(KC_C)
#define CTL_V   LCTL(KC_V)
#define CT_SFC  LCTL(LSFT(KC_C))
#define CT_SFV  LCTL(LSFT(KC_V))

#define PRT_SC LGUI(LSFT(KC_S))

#define ADJUST   MO(_ADJUST)
#define NAV      MO(_NAV)

#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define DVORAK   DF(_DVORAK)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /*
  * Base layer: QWERTY
  *                                                                                     
  * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  * |ADJ/Tab |   Q    |   W    |   E    |   R    |   T    |                                           |   Y    |   U    |   I    |   O    |   P    | CapsLk |
  * ├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
  * |Ctrl/Esc|   A    |   S    |   D    |   F    |   G    |                                           |   H    |   J    |   K    |   L    |  ; :   |  LAlt  | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |  LAlt  |   Z    |   X    |   C    |   V    |   B    | Ctl+P  |Ct+Sf+P |       | Ctrl+` | Ctrl+S |   N    |   M    |   , <  |  . >   |  / ?   | RShift |
  * └────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
  *                            |  LGUI  |  RAlt  |SYM/' " |  Bksp  | Delete |       | Enter  |NUMFUNC/| RShift |  F12   | ADJUST |                           
  *                            |        |        |        |        |        |       |        | Space  |        |        |        |
  *                            └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  */  
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     ADJ_TAB ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                                            KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_CAPS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTL_ESC ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                                            KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_LALT , 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,CTL_P   ,CT_SFP  ,        CTL_GRV ,CTL_S   ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //└────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                KC_LGUI ,KC_RALT ,SYM_QT  ,KC_BSPC ,KC_DEL  ,        KC_ENT  ,NUM_SPC ,KC_RSFT ,KC_F12  ,ADJUST                            
  //                           |        |        |        |        |        |       |        |        |        |        |        |
  //                           └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  ),

  /*
  * Base layer: DVORAK
  *                                                                                     
  * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  * |ADJ/Tab |   ' "  |   , <  |   . >  |   P    |   Y    |                                           |   F    |   G    |   C    |   R    |   L    | CapsLk |
  * ├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
  * |Ctrl/Esc|   A    |   O    |   E    |   U    |   I    |                                           |   D    |   H    |   T    |   N    |   S    |  LAlt  | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |  LAlt  |   ; :  |   Q    |   J    |   K    |   X    | Ctl+P  |Ct+Sf+P |       | Ctrl+` | Ctrl+S |   B    |   M    |   W    |   V    |   Z   | RShift |
  * └────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
  *                            |  LGUI  |  RAlt  |SYM/' " |  Bksp  | Delete |       | Enter  |NUMFUNC/| RShift |  F12   | ADJUST |                           
  *                            |        |        |        |        |        |       |        | Space  |        |        |        |
  *                            └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  */  
  [_DVORAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     ADJ_TAB ,KC_QUOT ,KC_COMM ,KC_DOT  ,KC_P    ,KC_Y    ,                                            KC_F    ,KC_G    ,KC_C    ,KC_R    ,KC_L    ,KC_CAPS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTL_ESC ,KC_A    ,KC_O    ,KC_E    ,KC_U    ,KC_I    ,                                            KC_D    ,KC_H    ,KC_T    ,KC_N    ,KC_S    ,KC_LALT , 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT ,KC_SCLN ,KC_Q    ,KC_J    ,KC_K    ,KC_X    ,CTL_P   ,CT_SFP  ,        CTL_GRV ,CTL_S   ,KC_B    ,KC_M    ,KC_W    ,KC_V    ,KC_Z    ,KC_RSFT ,
  //└────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                KC_LGUI ,KC_RALT ,SYM_QT  ,KC_BSPC ,KC_DEL  ,        KC_ENT  ,NUM_SPC ,KC_RSFT ,KC_F12  ,ADJUST                            
  //                           |        |        |        |        |        |       |        |        |        |        |        |
  //                           └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  ),

 /*
  * Base layer: Colemak DH
  *                                                                                     
  * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  * |ADJ/Tab |   Q    |   W    |   F    |   P    |   B    |                                           |   J    |   L    |   U    |   Y    |  ; :   | CapsLk |
  * ├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
  * |Ctrl/Esc|   A    |   R    |   S    |   T    |   G    |                                           |   M    |   N    |   E    |   I    |   O    |  LAlt  | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * | LAlt   |   Z    |   X    |   C    |   D    |   V    | Ctl+P  |Ct+Sf+P |       | Ctrl+` | Ctrl+S |   K    |   H    |   , <  |  . >   |  / ?   | RShift |
  * └────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
  *                            |  LGUI  |  RAlt  |SYM/' " |  Bksp  | Delete |       | Enter  |NUMFUNC/| RShift |  F12   | ADJUST |                           
  *                            |        |        |        |        |        |       |        | Space  |        |        |        |
  *                            └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  */  
  [_COLEMAK_DH] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     ADJ_TAB ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,                                            KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_CAPS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTL_ESC ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,                                            KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_LALT , 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,CTL_P   ,CT_SFP  ,        CTL_GRV ,CTL_S   ,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //└────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                KC_LGUI ,KC_RALT ,SYM_QT  ,KC_BSPC ,KC_DEL  ,        KC_ENT  ,NUM_SPC ,KC_RSFT ,KC_F12  ,ADJUST                            
  //                           |        |        |        |        |        |       |        |        |        |        |        |
  //                           └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  ),

 /*
  * Sym layer: symbols
  *                                                                                     
  * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  * |        |   !    |   ?    |   (    |   )    |   _    |                                           |   #    |   =    |   <    |   >    |   +    | Ctrl+X |
  * ├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
  * |   ` ~  |   @    |   $    |   {    |   }    |   |    |                                           |   ←    |   ↓    |   ↑    |   →    |  - _   | Ctrl+C | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |   --   |   ~    |   %    |   [    |   ]    |   &    | Ctrl+Z | Ctrl+Y |       |Ct+Sf+C |Ct+Sf+V |   *    |   :    |   ^    |   \    |   /    | Ctrl+V |
  * └────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
  *                            |   --   |        |  --    |   --   |   --   |       |   --   |   --   |   --   | Ctrl+F |Prt Scr |                           
  *                            |        |        |        |        |        |       |        |        |        |        |        |
  *                            └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  */  
  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_EXLM ,KC_QUES ,KC_LPRN ,KC_RPRN ,KC_UNDS ,                                            KC_HASH ,KC_EQL  ,KC_LT   ,KC_GT   ,KC_PLUS ,CTL_X   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV  ,KC_AT   ,KC_DLR  ,KC_LCBR ,KC_RCBR ,KC_PIPE ,                                            KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,KC_MINS ,CTL_C   , 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_TILD ,KC_PERC ,KC_LBRC ,KC_RBRC ,KC_AMPR ,CTL_Z   ,CTL_Y   ,        CT_SFC  ,CT_SFV  ,KC_ASTR ,KC_COLN ,KC_CIRC ,KC_BSLS ,KC_PSLS ,CTL_V   ,
  //└────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                _______ ,XXXXXXX ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,CTL_F   ,PRT_SC                              
  //                           |        |        |        |        |        |       |        |        |        |        |        |
  //                           └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  ),

 /*
  * Nav layer: mouse navigation and other controls
  *                                                                                     
  * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  * |   --   |        |Mouse ↑ |        |MouseW ↑|        |                                           |  Home  |Bright -|Bright +| PrtSc  |        |        |
  * ├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
  * |        |Mouse ← |Mouse ↓ |Mouse → |MouseW ↓|        |                                           | Page ↑ | Vol -  | Vol +  | Mute   |        |        | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |        |        | Power  | Sleep  |  Wake  |        |        |        |       |        |        | Page ↓ |        | ScLck  |        |        |        |
  * └────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
  *                            |        |        |        |        |        |       |        |        |        |        |        |                           
  *                            |        |        |        |        |        |       |        |        |        |        |        |
  *                            └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  */  
  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,                                            KC_HOME ,KC_BRID ,KC_BRIU ,KC_PSCR ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,                                            KC_PGUP ,KC_VOLD ,KC_VOLU ,KC_MUTE ,XXXXXXX ,XXXXXXX , 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_PWR  ,KC_SLEP ,KC_WAKE ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_PGDN ,XXXXXXX ,KC_SCRL ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                            
  //                           |        |        |        |        |        |       |        |        |        |        |        |
  //                           └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  ),

 /*
  * Numfunc layer: Numbers and function keys
  *                                                                                     
  * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  * |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |                                           |   F7   |   F8   |   F9   |   F10  |   F11  |   F12  |
  * ├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
  * |        |   1    |    2   |   3    |   4    |   5    |                                           |   6    |   7    |   8    |   9    |   0    |        | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |   --   |        |        |        |        |        |        |        |       |        |        |        |        |        |        |        |        |
  * └────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
  *                            |        |        |        |   --   |   --   |       |   --   |   --   |   --   |        |        |                           
  *                            |        |        |        |        |        |       |        |        |        |        |        |
  *                            └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  */  
  [_NUMFUNC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,                                            KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,XXXXXXX , 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,_______ ,_______ ,XXXXXXX ,XXXXXXX                            
  //                           |        |        |        |        |        |       |        |        |        |        |        |
  //                           └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  ),

 /*
  * Adjust Layer: Default layer settings, RGB
  *                                                                                     
  * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  * |  --    | QWERTY |  Hue + |  Sat + |Bright +| Mode + |                                           | Static | Breath |Rainbow |  Swirl | Snake  |        |
  * ├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
  * |        | DVORAK |  Hue - |  Sat - |Bright -| Mode - |                                           |Kni Rid |Christm |St grad |RGB test|Twinkle |        | 
  * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  * |        | COLEMAK|        |        |        | Toggle |        | Reset  |       | Reset  |        |        |        |        |        |        |        |
  * └────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
  *                            |        |        |        |        |        |       |        |        |        |        |  --    |                           
  *                            |        |        |        |        |        |       |        |        |        |        |        |
  *                            └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  */  
  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,QWERTY  ,RGB_HUI ,RGB_SAI ,RGB_VAI ,RGB_MOD ,                                            RGB_M_P ,RGB_M_B ,RGB_M_R ,RGB_M_SW,RGB_M_SN,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,DVORAK  ,RGB_HUD ,RGB_SAD ,RGB_VAD ,RGB_RMOD,                                            RGB_M_K ,RGB_M_X ,RGB_M_G ,RGB_M_T ,RGB_M_TW,XXXXXXX , 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,COLEMAK ,XXXXXXX ,XXXXXXX ,XXXXXXX ,RGB_TOG ,XXXXXXX ,QK_BOOT ,        QK_BOOT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______                            
  //                           |        |        |        |        |        |       |        |        |        |        |        |
  //                           └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
  ),

//  /*
//   * Layer template
//   *                                                                                     
//   * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
//   * |        |        |        |        |        |        |                                           |        |        |        |        |        |        |
//   * ├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
//   * |        |        |        |        |        |        |                                           |        |        |        |        |        |        | 
//   * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//   * |        |        |        |        |        |        |        |        |       |        |        |        |        |        |        |        |        |
//   * └────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
//   *                            |        |        |        |        |        |       |        |        |        |        |        |                           
//   *                            |        |        |        |        |        |       |        |        |        |        |        |
//   *                            └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
//   */  
//   [_LAYERINDEX] = LAYOUT(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX , 
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐       ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//   //└────────┴────────┴────────┼────────┼────────┼────────┼────────┼────────┤       ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────┘
//                                 XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                            
//   //                           |        |        |        |        |        |       |        |        |        |        |        |
//   //                           └────────┴────────┴────────┴────────┴────────┘       └────────┴────────┴────────┴────────┴────────┘
//   ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _DVORAK:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */
