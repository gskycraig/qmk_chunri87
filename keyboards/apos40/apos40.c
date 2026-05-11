/* Copyright (C) 2023 Westberry Technology Corp., Ltd
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

#ifdef RGB_MATRIX_ENABLE

// clang-format off
#undef ___
#define ___ NO_LED

led_config_t g_led_config = {
    LAYOUT(
       29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  ___,  ___, 
       28,  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,
       4,   5,   6,   7,   8,   9,   17,  16,  15,  14,
       3,   2,   1,   0,   10,  11,  12,  13
    ), {
    {  45 , 52 },  // 0
    {  30 , 52 },  // 1
    {  15 , 52 },  // 2
    {   3 , 52 },  // 3
    
    {   8 , 41 },  // 4
    {  27 , 41 },  // 5
    {  39 , 41 },  // 6
    {  51 , 41 },  // 7
    {  67 , 41 },  // 8
    {  79 , 41 },  // 9
   
    {  70 , 52 },  // 10
    {  85 , 52 },  // 11
    { 100 , 52 },  // 12
    { 115 , 52 },  // 13
 
    {  91 , 41 },  // 14
    { 103 , 41 },  // 15
    { 118 , 41 },  // 16
    { 130 , 41 },  // 17 
   
    { 133 , 17 },  // 18
    { 121 , 17 },  // 19
    { 106 , 17 },  // 20
    {  94 , 17 },  // 21
    {  82 , 17 },  // 22
    {  70 , 17 },  // 23
    {  54 , 17 },  // 24
    {  42 , 17 },  // 25
    {  30 , 17 },  // 26
    {  18 , 17 },  // 27
    {   3 , 17 },  // 28

    {   0 ,  3 },  // 29
    {  15 ,  3 },  // 30
    {  27 ,  3 },  // 31
    {  39 ,  3 },  // 32
    {  51 ,  3 },  // 33
    {  67 ,  3 },  // 34
    {  79 ,  3 },  // 35
    {  91 ,  3 },  // 36
    { 103 ,  3 },  // 37
    { 118 ,  3 }   // 38
}, {     
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4
}};

// clang-format on
#endif
