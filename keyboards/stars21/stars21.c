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
        17,  18,  19,  20,
        16,  15,  14,  13,
        9,   10,  11,  12,
        8,   7,   6,
        2,   3,   4,   5,
        1,  0
    ), {
    { 112 , 64 },  // 0
    {  28 , 64 },  // 1

    {   0 , 51 },  // 2
    {  56 , 51 },  // 3
    { 112 , 51 },  // 4
    { 168 , 51 },  // 5

    { 112 , 38 },  // 6
    {  56 , 38 },  // 7
    {   0 , 38 },  // 8

    {   0 , 26 },  // 9
    {  56 , 26 },  // 10
    { 112 , 26 },  // 11
    { 168 , 26 },  // 12

    { 168 , 13 },  // 13
    { 112 , 13 },  // 14
    {  56 , 13 },  // 15
    {   0 , 13 },  // 16

    {   0 ,  0 },  // 17
    {  56 ,  0 },  // 18
    { 112 ,  0 },  // 19
    { 168 ,  0 },  // 20

    {   0 ,  0 },  // 17
    {   0 ,  0 },  // 17
    {   0 ,  0 },  // 17
    {   0 ,  0 },  // 17
    {   0 ,  0 },  // 17
    {   0 ,  0 },  // 17
    {   0 ,  0 },  // 17
    {   0 ,  0 },  // 17
    {   0 ,  0 },  // 17
    {   0 ,  0 },  // 17
    {   0 ,  0 },  // 17
    {   0 ,  0 },  // 17
    {   0 ,  0 },  // 17

}, {
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4,
    4, 4, 4, 4,
    4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
}};

// clang-format on
#endif
