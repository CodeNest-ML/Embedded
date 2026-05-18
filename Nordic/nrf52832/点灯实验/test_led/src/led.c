/**
 * @file led.c
 * @brief LED驱动实现
 */

#include "led.h"
#include <hal/nrf_gpio.h>

void led_init(void)
{
    /* 配置 LED 引脚为输出 */
    nrf_gpio_pin_dir_set(LED_1, NRF_GPIO_PIN_DIR_OUTPUT);
    nrf_gpio_pin_dir_set(LED_2, NRF_GPIO_PIN_DIR_OUTPUT);
    nrf_gpio_pin_dir_set(LED_3, NRF_GPIO_PIN_DIR_OUTPUT);
    nrf_gpio_pin_dir_set(LED_4, NRF_GPIO_PIN_DIR_OUTPUT);

    /* 初始熄灭 LED */
    nrf_gpio_pin_set(LED_1);
    nrf_gpio_pin_set(LED_2);
    nrf_gpio_pin_set(LED_3);
    nrf_gpio_pin_set(LED_4);
}

void led1_on(void)
{
    nrf_gpio_pin_clear(LED_1);
}

void led1_off(void)
{
    nrf_gpio_pin_set(LED_1);
}

bool led1_toggle(void)
{
    nrf_gpio_pin_toggle(LED_1);

    /* 返回当前LED状态 */
    return nrf_gpio_pin_read(LED_1) == 0;
}
