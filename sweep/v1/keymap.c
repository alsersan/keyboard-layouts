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
    _SYM,
    _NUMFUNC,
    _ADJUST,
};

#define SYM_QT  LT(_SYM, KC_QUOT)
#define NUM_SPC LT(_NUMFUNC, KC_SPC)
#define ADJUST   MO(_ADJUST)

// Home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L RALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

#define GUI_GRV LGUI_T(KC_GRV)
#define ALT_DLR LALT_T(KC_DLR)
#define CTL_LCBR LCTL_T(KC_LCBR)
#define SFT_RCBR LSFT_T(KC_RCBR)

// Combos
uint16_t COMBO_LEN = 2;

enum combo_events {
    COMBO_ESC,
    COMBO_TAB
};

const uint16_t PROGMEM esc_combo[] = {SYM_QT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {NUM_SPC, KC_RSFT, COMBO_END};

combo_t key_combos[] = {
    [COMBO_ESC] = COMBO(esc_combo, KC_ESC),
    [COMBO_TAB] = COMBO(tab_combo, KC_TAB)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /*
  * Base layer: QWERTY
  *                                                                                     
  * ┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
  * |   Q    |   W    |   E    |   R    |   T    |        |   Y    |   U    |   I    |   O    |   P    |         
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * |   A    |   S    |   D    |   F    |   G    |        |   H    |   J    |   K    |   L    |  ; :   |                
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * |   Z    |   X    |   C    |   V    |   B    |        |   N    |   M    |   , <  |  . >   |  / ?   |    
  * └────────┴────────┴────────┼────────┼────────┤        ├────────┼────────┼────────┴────────┴────────┘
  *                            |  SYM/  |  Bksp  |        |NUMFUNC/| RShift |                                 
  *                            |  ' "   |        |        | Space  |        |       
  *                            └────────┴────────┘        └────────┴────────┘
  */  
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
     KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,         KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
     GUI_A   ,ALT_S   ,CTL_D   ,SFT_F   ,KC_G    ,         KC_H    ,SFT_J   ,CTL_K   ,ALT_L   ,GUI_SCLN, 
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────├────────┼────────┼────────┤
     KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,         KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,
  //└────────┴────────┴────────┼────────┼────────┤        ├────────┼────────├────────┴────────┴────────┘
                                SYM_QT  ,KC_BSPC ,         NUM_SPC ,KC_RSFT                             
  //                           |        |        |        |        |        |  
  //                           └────────┴────────┘        └────────┴────────┘
  ),

 /*
  * Sym layer: symbols
  *                                                                                     
  * ┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
  * |   !    |   ?    |   (    |   )    |   _    |        |   #    |   =    |   <    |   >    |   +    |         
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * |   ` ~  |   $    |   {    |   }    |   |    |        |   ←    |   ↓    |   ↑    |   →    |  - _   |                
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * |   ~    |   %    |   [    |   ]    |   &    |        |   *    |   :    |   ^    |   \    |   @    |    
  * └────────┴────────┴────────┼────────┼────────┤        ├────────┼────────┼────────┴────────┴────────┘
  *                            |   --   |   --   |        |  Enter |   --   |                                 
  *                            |        |        |        |        |        |       
  *                            └────────┴────────┘        └────────┴────────┘
  */  
  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
     KC_EXLM ,KC_QUES ,KC_LPRN ,KC_RPRN ,KC_UNDS ,         KC_HASH ,KC_EQL  ,KC_LT   ,KC_GT   ,KC_PLUS ,
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
     GUI_GRV ,ALT_DLR ,CTL_LCBR,SFT_RCBR,KC_PIPE ,         KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,KC_MINS , 
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────├────────┼────────┼────────┤
     KC_TILD ,KC_PERC ,KC_LBRC ,KC_RBRC ,KC_AMPR ,         KC_ASTR ,KC_COLN ,KC_CIRC ,KC_BSLS ,KC_AT   ,
  //└────────┴────────┴────────┼────────┼────────┤        ├────────┼────────├────────┴────────┴────────┘
                                _______ ,_______ ,         KC_ENT  ,_______                             
  //                           |        |        |        |        |        |  
  //                           └────────┴────────┘        └────────┴────────┘
  ),

 /*
  * Numfunc layer: numbers, function keys and random
  *                                                                                     
  * ┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
  * |   F1   |   F2   |   F3   |   F4   |   F5   |        |   F6   |   F7   |   F8   |   F9   |   F10  |        
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * |   1    |    2   |   3    |   4    |   5    |        |   6    |   7    |   8    |   9    |   0    |                
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * | CapsLk |        |        |        |        |        |   F11  |   F12  |        |        |        |    
  * └────────┴────────┴────────┼────────┼────────┤        ├────────┼────────┼────────┴────────┴────────┘
  *                            | ADJUST | Delete |        |   --   |   --   |                                 
  *                            |        |        |        |        |        |       
  *                            └────────┴────────┘        └────────┴────────┘
  */  
  [_NUMFUNC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,         KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
     KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,         KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    , 
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────├────────┼────────┼────────┤
     KC_CAPS ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,         KC_F11  ,KC_F12  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┼────────┼────────┤        ├────────┼────────├────────┴────────┴────────┘
                                ADJUST  ,KC_DEL  ,         _______ ,_______                             
  //                           |        |        |        |        |        |  
  //                           └────────┴────────┘        └────────┴────────┘
  ),

 /*
  * Adjust layer: reset buttons
  *                                                                                     
  * ┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
  * |        |        |        |        |        |        |        |        |        |        |        |         
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * |        |        |        |        |        |        |        |        |        |        |        |                
  * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
  * | Reset  |        |        |        |        |        |        |        |        |        | Reset  |    
  * └────────┴────────┴────────┼────────┼────────┤        ├────────┼────────┼────────┴────────┴────────┘
  *                            |   --   |        |        |   --   |        |                                 
  *                            |        |        |        |        |        |       
  *                            └────────┴────────┘        └────────┴────────┘
  */  
  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,         XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,         XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX , 
  //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────├────────┼────────┼────────┤
     QK_BOOT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,         XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QK_BOOT ,
  //└────────┴────────┴────────┼────────┼────────┤        ├────────┼────────├────────┴────────┴────────┘
                                _______ ,XXXXXXX ,         _______ ,XXXXXXX                             
  //                           |        |        |        |        |        |  
  //                           └────────┴────────┘        └────────┴────────┘
  ),

//  /*
//   * Layer template
//   *                                                                                     
//   * ┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
//   * |        |        |        |        |        |        |        |        |        |        |        |         
//   * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
//   * |        |        |        |        |        |        |        |        |        |        |        |                
//   * ├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
//   * |        |        |        |        |        |        |        |        |        |        |        |    
//   * └────────┴────────┴────────┼────────┼────────┤        ├────────┼────────┼────────┴────────┴────────┘
//   *                            |        |        |        |        |        |                                 
//   *                            |        |        |        |        |        |       
//   *                            └────────┴────────┘        └────────┴────────┘
//   */  
//   [_LAYERINDEX] = LAYOUT(
//   //┌────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┐
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,         XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//   //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,         XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX , 
//   //├────────┼────────┼────────┼────────┼────────┤        ├────────┼────────├────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,         XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//   //└────────┴────────┴────────┼────────┼────────┤        ├────────┼────────├────────┴────────┴────────┘
//                                 XXXXXXX ,XXXXXXX ,         XXXXXXX ,XXXXXXX ,                            
//   //                           |        |        |        |        |        |  
//   //                           └────────┴────────┘        └────────┴────────┘
//   ),
};

