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
       30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,   
       56,  55,  54,  53,  52,  51,  50,  49,  48,  47,  46,  45,  44,
       57,  58,  59,  60,  61,  62,  63,  64,  65,  66
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
    {  19 , 29 },  // 31
    {  31 , 29 },  // 32
    {  43 , 29 },  // 33
    {  55 , 29 },  // 34
    {  71 , 29 },  // 35
    {  83 , 29 },  // 36
    {  95 , 29 },  // 37
    { 107 , 29 },  // 38
    { 122 , 29 },  // 39
    { 134 , 29 },  // 40
    { 146 , 29 },  // 41
    { 170 , 29 },  // 42
    { 188 , 29 },  // 43
    
    { 177 , 41 },  // 44
    { 158 , 41 },  // 45
    { 142 , 41 },  // 46
    { 130 , 41 },  // 47
    { 118 , 41 },  // 48
    { 103 , 41 },  // 49
    {  91 , 41 },  // 50
    {  79 , 41 },  // 51
    {  67 , 41 },  // 52
    {  51 , 41 },  // 53
    {  39 , 41 },  // 54
    {  27 , 41 },  // 55
    {   8 , 41 },  // 56
                                   
    {   3 , 52 },  // 57
    {  15 , 52 },  // 58
    {  30 , 52 },  // 59
    {  70 , 52 },  // 60
    { 133 , 52 },  // 61
    { 144 , 52 },  // 62
    { 155 , 52 },  // 63
    { 166 , 52 },  // 64
    { 177 , 52 },  // 65
    { 188 , 52 },  // 66

    { 188 , 41 },  // 67
    { 188 , 41 },  // 68
    { 188 , 41 }   // 69


}, {
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
      4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
      4, 4, 4
}};

// clang-format on
#endif
