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
        0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14, 
       29,  28,  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16,  15,
       30,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,    
       58,  57,  56,  55,  54,  53,  52,  51,  50,  49,  48,  47,  46,  45,  
       59,  60,  61,  62,  63,  64,  66,  67,  68
    ), {
    {   0 ,  3 },  // 0
    {  15 ,  3 },  // 1
    {  27 ,  3 },  // 2
    {  39 ,  3 },  // 3
    {  51 ,  3 },  // 4
    {  67 ,  3 },  // 5
    {  79 ,  3 },  // 6
    {  91 ,  3 },  // 7
    { 103 ,  3 },  // 8
    { 118 ,  3 },  // 9
    { 130 ,  3 },  // 10
    { 142 ,  3 },  // 11
    { 154 ,  3 },  // 12
    { 170 ,  3 },  // 13
    { 188 ,  3 },  // 14   

    { 188 , 17 },  // 15
    { 173 , 17 },  // 16
    { 158 , 17 },  // 17
    { 145 , 17 },  // 18
    { 133 , 17 },  // 19
    { 121 , 17 },  // 20
    { 106 , 17 },  // 21
    {  94 , 17 },  // 22
    {  82 , 17 },  // 23
    {  70 , 17 },  // 24
    {  54 , 17 },  // 25
    {  42 , 17 },  // 26
    {  30 , 17 },  // 27
    {  18 , 17 },  // 28
    {   3 , 17 },  // 29

    {   3 , 29 },  // 30
   
    {  19 , 29 },  // 32
    {  31 , 29 },  // 33
    {  43 , 29 },  // 34
    {  55 , 29 },  // 35
    {  71 , 29 },  // 36
    {  83 , 29 },  // 37
    {  95 , 29 },  // 38
    { 107 , 29 },  // 39
    { 122 , 29 },  // 40
    { 134 , 29 },  // 41
    { 146 , 29 },  // 42
    { 170 , 29 },  // 43
    { 188 , 29 },  // 44
    
    { 188 , 41 },  // 45
    { 177 , 41 },  // 46
    { 158 , 41 },  // 47
    { 142 , 41 },  // 48
    { 130 , 41 },  // 49
    { 118 , 41 },  // 50
    { 103 , 41 },  // 51
    {  91 , 41 },  // 52
    {  79 , 41 },  // 53
    {  67 , 41 },  // 54
    {  51 , 41 },  // 55
    {  39 , 41 },  // 56
    {  27 , 41 },  // 57
    {   8 , 41 },  // 58
    
    {   3 , 52 },  // 59
    {  15 , 52 },  // 60
    {  30 , 52 },  // 61
    {  70 , 52 },  // 62
    { 133 , 52 },  // 63
    { 144 , 52 },  // 64
   
    { 166 , 52 },  // 66
    { 177 , 52 },  // 67
    { 188 , 52 }   // 68
}, {
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 4, 4, 4, 4
}};

// clang-format on
#endif
