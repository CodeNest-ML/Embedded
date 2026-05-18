/**
 * @file main.c
 * @brief LED闪烁测试主程序
 *
 * 测试LED驱动：1秒交替亮灭
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "led.h"

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

int main(void)
{
    printk("=== LED 1秒交替亮灭测试 ===\r\n");
    
    /* 初始化LED */
    led_init();
    
    /* 主循环：1秒交替亮灭 */
    while (1) {
        /* LED 亮 */
        led1_on();
        printk("LED ON\r\n");
        k_busy_wait(1000000);  /* 1秒 = 1000000微秒 */

        /* LED 灭 */
        led1_off();
        printk("LED OFF\r\n");
        k_busy_wait(1000000);  /* 1秒 = 1000000微秒 */
    }

    return 0;
}
