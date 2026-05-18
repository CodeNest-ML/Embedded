/**
 * @file led.h
 * @brief LED驱动头文件
 *
 * 提供LED初始化和控制接口
 */

#ifndef LED_H
#define LED_H

#include <zephyr/kernel.h>

/* LED引脚定义 - nRF52832 DK LED1 */
#define LED_1 17
/* LED引脚定义 - nRF52832 DK LED2 */
#define LED_2 18
/* LED引脚定义 - nRF52832 DK LED3 */
#define LED_3 19
/* LED引脚定义 - nRF52832 DK LED4 */
#define LED_4 20

/**
 * @brief 初始化LED
 *
 * 配置LED引脚为输出模式，初始状态为熄灭
 */
void led_init(void);

/**
 * @brief 点亮LED
 */
void led_on(void);

/**
 * @brief 熄灭LED
 */
void led_off(void);

/**
 * @brief 切换LED状态
 *
 * @return 当前LED状态 (true=亮, false=灭)
 */
bool led_toggle(void);

#endif /* LED_H */
