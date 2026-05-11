// Copyright 2023 JoyLee (@itarze)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "usb_main.h"
#include "immobile.h"
#include "config.h"
#include "stars21.h"

extern uint16_t qbat_send;
extern uint8_t qbat_save;

uint8_t get_bat_flag = 0; 

enum layers {
    _LB = 0,
    _LF,
    _LM,
    _LMF
};

#define RGB_HSV_MAX 7
static uint8_t rgb_hsvs[7][3] = {
    {HSV_RED},
    {HSV_YELLOW},
    {HSV_GREEN},
    {HSV_CYAN},
    {HSV_BLUE},
    {HSV_PINK},
    {HSV_WHITE},
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LB] = LAYOUT(
        KC_ESC,  KC_TAB,   KC_BSPC, MO(_LF),
        KC_NUM,  KC_PSLS,  KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,    KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,    KC_P6,
        KC_P1,   KC_P2,    KC_P3,   KC_PENT,
        KC_P0,   KC_PDOT
    ),

    [_LF] = LAYOUT( /* Base */
        EE_CLR, RGB_MOD,  RGB_HUI, KC_NO,
        IM_USB,  KC_PSLS,  KC_PAST, KC_PMNS,
        IM_BT1,  IM_BT2,   IM_2G4,  KC_PPLS,
        RGB_SPI, RGB_SPD,  KC_P6,
        RGB_VAI, RGB_VAD,  RL_MOD,   RGB_TOG,
        IM_BATQ,  KC_PDOT
    )
};

// clang-format on
#ifdef RGB_MATRIX_BLINK_ENABLE
void bat_indicators_hook(uint8_t index);

blink_rgb_t blink_rgbs[RGB_MATRIX_BLINK_COUNT] = {
    {.index = IM_MM_RGB_BLINK_INDEX_BT1, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = IM_MM_RGB_BLINK_INDEX_BT2, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = IM_MM_RGB_BLINK_INDEX_2G4, .interval = 250, .times = 1, .color = {.r = 0x00, .g = 0xFF, .b = 0x00}, .blink_cb = im_mm_rgb_blink_cb},
    {.index = RGB_MATRIX_BLINK_INDEX_BAT, .interval = 250, .times = 3, .color = {.r = 0x00, .g = 0x00, .b = 0x00}, .blink_cb = bat_indicators_hook},
    {.index = RGB_MATRIX_BLINK_INDEX_ALL, .interval = 250, .times = 3, .color = {.r = 100, .g = 100, .b = 100}, .blink_cb = NULL},
};
#endif

typedef enum {
    BAT_NORMAL,
    BAT_LOW,
    BAT_CHRGING,
    BAT_FULL,
} bat_statue_t;
bat_statue_t bat_statue = BAT_NORMAL;

static bool bat_blink = false;
static uint8_t battery_full_flag = 1;
static uint8_t battery_chrg_flag = 1;
static bool full_flag = false;
static uint16_t laste_time_off = 0;
static uint16_t battime_out = 0;
static uint32_t battime_char = 0;


#ifdef RGB_MATRIX_BLINK_INDEX_BAT

void bat_indicators_hook(uint8_t index) {

    if (mm_eeconfig.devs != DEVS_USB) {

        if ((!mm_eeconfig.charging) && (qbat_save <= BATTERY_CAPACITY_LOW)) {
            /* 低电提醒 */
            rgb_matrix_blink_set_color(RGB_MATRIX_BLINK_INDEX_BAT, RGB_RED);
            rgb_matrix_blink_set_interval_times(index, 500, 0x3);
            bat_blink = true;
            bat_statue = BAT_LOW;
        } else {
            bat_blink = false;
        }
        // if ((qbat_save < 1U) && (!mm_eeconfig.charging)) {
        //     if (laste_time_off == 0) laste_time_off = timer_read();
        //     if (timer_elapsed(laste_time_off)>08) {
        //         laste_time_off=0;
        //         im_set_power_off();
        //     }
        // } else {
        //     laste_time_off = 0;
        // }
    } else {
        bat_blink = false;
    }
   
    // rgb_matrix_blink_set(index);
}

bool rgb_matrix_blink_user(blink_rgb_t *blink_rgb) {
    if (blink_rgb->index == RGB_MATRIX_BLINK_INDEX_BAT) {
        if (bat_blink != true) {
            return false;
        }
    }
    return true;
}

#endif

typedef union {
    uint32_t raw;
    struct {
        uint8_t flag: 1;
        uint8_t rgb_enable: 1;
        uint8_t rgb_hsv_index: 3;
    };
} confinfo_t;
confinfo_t confinfo;

#ifdef RGB_MATRIX_ENABLE

// 此函数不需要改动
bool mm_get_rgb_enable(void) {
#    ifdef RGBLIGHT_ENABLE
    return confinfo.rgb_enable;
#    else
    return rgb_matrix_config.enable;
#    endif
}

// 此函数不需要改动
void mm_set_rgb_enable(bool state) {
#    ifdef RGBLIGHT_ENABLE
    confinfo.rgb_enable = state;
    eeconfig_update_user(confinfo.raw);
#    else
    rgb_matrix_config.enable = state;
#    endif
}

#endif

void eeconfig_confinfo_default(void) {
    confinfo.flag = false;
    confinfo.rgb_enable = true;
    confinfo.rgb_hsv_index = 0;
    eeconfig_update_user(confinfo.raw);
}

bool im_led_deinit_user(void) {

    writePin(RGB_DRIVER_EN_PIN, 0);

    writePin(POWER_DCDC_EN_PIN, 0);

    return true;
}

bool im_led_init_user() {

    writePin(POWER_DCDC_EN_PIN, 1);

    writePin(RGB_DRIVER_EN_PIN, 1);
    return true;
}

// 初始化一些GPIO PIN 相关的操作
bool im_pre_init_user(void) {
    setPinInput(CHRG_PIN);
    setPinOutput(RGB_DRIVER_EN_PIN);
    setPinOutput(POWER_DCDC_EN_PIN);
    writePin(POWER_DCDC_EN_PIN, 1);
    return true;
}

static uint32_t readbat = 0x00;
// 初始化和参数相关的操作，在恢复出厂设置时此函数会被调用
bool im_init_user(void) {
    setPinOutput(RGB_DRIVER_EN_PIN);
    writePin(RGB_DRIVER_EN_PIN, 1);
    setPinInputHigh(CHRG_PIN);
    setPinInputHigh(FULL_PIN);

    confinfo.raw = eeconfig_read_user();
    if (!confinfo.raw) {
        eeconfig_confinfo_default();
    }
    readbat = timer_read32();
#ifdef RGB_MATRIX_BLINK_INDEX_BAT
    rgb_matrix_blink_set(RGB_MATRIX_BLINK_INDEX_BAT);
#endif

    return true;
}

// 恢复出厂设置回调函数
bool im_reset_settings_user(void) {

#ifdef MULTIMODE_ENABLE
    // eeconfig_update_multimode_default();
#endif
#ifdef RGB_MATRIX_BLINK_ENABLE
    rgb_matrix_blink_set(RGB_MATRIX_BLINK_INDEX_ALL);
#endif

    return true;
}
bool chrg_flag = false;
// 无限循环
bool im_loop_user(void) {

    if (timer_elapsed32(readbat) >= 3000) {
        readbat = timer_read32();
        battery_chrg_flag = readPin(CHRG_PIN);
        battery_full_flag = readPin(FULL_PIN);
    }

    if ((!mm_eeconfig.charging) && full_flag ) {
        full_flag = false;
    }

    if ((chrg_flag) && (!battery_full_flag)) {
        if (bat_statue != BAT_FULL) bts_send_vendor(v_bat_full);
        full_flag = true;
        bat_statue = BAT_FULL;
    }

    if ((!mm_eeconfig.charging) && (bat_statue != BAT_LOW)) {
        if (bat_statue != BAT_NORMAL) bts_send_vendor(v_bat_stop_charging);
        bat_statue = BAT_NORMAL;
    }

    return true;
}

bool im_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case US_TS1: { // 低频
            if (record->event.pressed) {
                bts_send_vendor(0x60);
                bts_rf_send_carrier(0, 5, 0x01);
            } break;
            return false;
        } break;
        case US_TS2: { // 中频
            if (record->event.pressed) {
                bts_send_vendor(0x60);
                bts_rf_send_carrier(19, 5, 0x01);
            } break;
            return false;
        } break;
        case US_TS3: { // 高频
            if (record->event.pressed) {
                bts_send_vendor(0x60);
                bts_rf_send_carrier(38, 5, 0x01);
            } break;
            return false;
        } break;
        case US_STOP: { // 停止
            if (record->event.pressed) {
                bts_rf_send_stop();
            } break;
            return false;
        } break;
        case RGB_HUI:
            if (record->event.pressed) {
                uint8_t now_mode_one = rgb_matrix_get_mode();
                if((now_mode_one == 6) ||(now_mode_one == 13) ||(now_mode_one == 15) ||(now_mode_one == 16) ||(now_mode_one == 25) ||(now_mode_one == 26) ||(now_mode_one == 34)){
                    confinfo.rgb_hsv_index = (confinfo.rgb_hsv_index + 1) % 6;
                    rgb_matrix_sethsv(rgb_hsvs[confinfo.rgb_hsv_index][0],
                                        rgb_hsvs[confinfo.rgb_hsv_index][1],
                                        rgb_matrix_get_val());
                }else{
                    confinfo.rgb_hsv_index = (confinfo.rgb_hsv_index + 1) % 7;
                    rgb_matrix_sethsv(rgb_hsvs[confinfo.rgb_hsv_index][0],
                                        rgb_hsvs[confinfo.rgb_hsv_index][1],
                                        rgb_matrix_get_val());
                }
                eeconfig_update_user(confinfo.raw);
            }
            return false;
            break;

        case IM_USB: {
            if (record->event.pressed) {
                if (mm_eeconfig.devs != DEVS_USB) {
                    confinfo.flag = false;
                    eeconfig_update_user(confinfo.raw);
                    return true;
                } else {
                    mm_switch_mode(DEVS_USB, mm_eeconfig.last_devs, false);
                    confinfo.flag = true;
                    eeconfig_update_user(confinfo.raw);
                    return false;
                }
            }
        }break;
        case IM_BT1:
        case IM_BT2:
        case IM_BT3:
        case IM_2G4: {
            if (record->event.pressed) {
                if(confinfo.flag) {
                    return true;
                } else {
                    return false;
                }
            }
        }break;
        case RL_MOD: {
            if (record->event.pressed) {
                // confinfo.rgb_index ++;    
                // if(confinfo.rgb_index >=9){
                //     confinfo.rgb_index = 0;
                // }
                // eeconfig_update_user(confinfo.raw);     

                if(rgblight_get_mode() >= 42){ 

                    rgblight_mode(1);                
                    rgblight_setrgb(0,0,0);           
                    return false;
                }
                //rgblight_get_mode();

                // if(confinfo.rgb_index != 0)
                // {                                                 
                //     rgblight_mode(1); 
                //     // confinfo.rgb_index = (confinfo.rgb_index) % RGB_MAX;
                //     rgblight_setrgb(rgb_light[confinfo.rgb_index][0],rgb_light[confinfo.rgb_index][1], rgb_light[confinfo.rgb_index][2]);       

                //     confinfo.rgb_index ++;    
                //     if(confinfo.rgb_index >=9){
                //         confinfo.rgb_index = 0;
                //     }
                //     eeconfig_update_user(confinfo.raw);                              
                // }    
                // else
                // {
                //     rgblight_mode(14);
                //     confinfo.rgb_index = 1;
                //     eeconfig_update_user(confinfo.raw);
                // }
            }
            return true;
        } break;
        case IM_BATQ: {
            if (record->event.pressed) {
                get_bat_flag = 1;               
            }else{
                get_bat_flag = 0;   
            }
            return false;
        }break;

        


            default:
            break;
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE

#ifndef RGB_MATRIX_BAT_VAL
#    define RGB_MATRIX_BAT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(16, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
    }

    if ((!battery_chrg_flag) && (!full_flag)) {
        if (bat_statue != BAT_CHRGING) bts_send_vendor(v_bat_charging);
        rgb_matrix_set_color(RGB_MATRIX_BLINK_INDEX_BAT, RGB_BLUE);
        chrg_flag = true;
        bat_statue = BAT_CHRGING;
    }

    if(mm_eeconfig.charging){
       if(qbat_save >= 100){
            if(battime_char < 3300){
                rgb_matrix_set_color(RGB_MATRIX_BLINK_INDEX_BAT, RGB_GREEN);
                battime_char ++;
            }
            else{
                battime_char = 3300;
            }
       }
       else{
            rgb_matrix_set_color(RGB_MATRIX_BLINK_INDEX_BAT, RGB_RED);
            battime_char = 0;
       }    
    }
    else{
        battime_char = 0;
    }

    if(get_bat_flag){
        if((qbat_save >=76) &&(qbat_save <= 100)){
            rgb_matrix_set_color(17, RGB_GREEN);
        }
        else if((qbat_save >=51) &&(qbat_save <= 75)){
            rgb_matrix_set_color(17, 255,120,0);
        }
        else if((qbat_save >=26) &&(qbat_save <= 50)){
            rgb_matrix_set_color(17, 255,255,0);
        }
        else{
            rgb_matrix_set_color(17, RGB_RED);
        }
    }


    if ((!mm_eeconfig.charging) && (qbat_save <= BATTERY_CAPACITY_LOW)){

        if(battime_out <= 300){          
            rgb_matrix_set_color(RGB_MATRIX_BLINK_INDEX_BAT, RGB_RED);
        }
        else if(battime_out <= 600){            
            rgb_matrix_set_color(RGB_MATRIX_BLINK_INDEX_BAT, RGB_BLACK);            
        }
        
        if(battime_out > 600){
            battime_out = 0;
        }
        else{
            battime_out ++;
        }

      
    }

    if ((qbat_save < 1U) && (!mm_eeconfig.charging)) {
        if (laste_time_off == 0) laste_time_off = timer_read();
        if (timer_elapsed(laste_time_off)>10000) {
            laste_time_off=0;
            im_set_power_off();
        }
    } else {
        laste_time_off = 0;
    }



    return true;
}
#endif

