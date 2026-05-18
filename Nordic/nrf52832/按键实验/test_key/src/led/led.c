/**
 * @file led.c
 * @brief LED驱动实现文件
 * 
 * 该文件实现了nRF52832芯片的GPIO LED控制功能。
 * 包含LED初始化、点亮、熄灭、翻转等功能。
 * 
 * 功能特性：
 *   - 支持4个独立LED控制
 *   - 每个LED支持点亮、熄灭、翻转三种操作
 *   - 采用低电平点亮设计（输出低电平LED亮）
 * 
 * GPIO操作函数说明：
 *   - nrf_gpio_cfg_output() : 配置引脚为输出模式
 *   - nrf_gpio_pin_clear()   : 输出低电平（LED点亮）
 *   - nrf_gpio_pin_set()    : 输出高电平（LED熄灭）
 *   - nrf_gpio_pin_toggle() : 翻转当前电平状态
 * 
 * @see led.h LED驱动头文件
 */

#include <hal/nrf_gpio.h>
#include "led.h"

/**
 * @brief 初始化所有LED
 * 
 * 配置P0.17~P0.20引脚为GPIO输出模式。
 * 初始化后所有LED处于熄灭状态（默认输出高电平）。
 * 
 * 配置详情：
 *   - 输出模式：可控制引脚输出高低电平
 *   - 默认电平：高电平（LED熄灭）
 *   - 驱动能力：标准GPIO驱动能力
 * 
 * @note 该函数应该在系统初始化阶段调用，通常在main函数开始时调用
 * @warning 调用此函数后，LED引脚将被配置为输出模式，请勿在其他地方修改这些引脚
 */
void LED_Init(void)
{
    /* 配置P0.17为GPIO输出模式 → LED1 */
    nrf_gpio_cfg_output(LED_0);
    
    /* 配置P0.18为GPIO输出模式 → LED2 */
    nrf_gpio_cfg_output(LED_1);
    
    /* 配置P0.19为GPIO输出模式 → LED3 */
    nrf_gpio_cfg_output(LED_2);
    
    /* 配置P0.20为GPIO输出模式 → LED4 */
    nrf_gpio_cfg_output(LED_3);
}

/*==============================================*
 * LED1控制函数 (P0.17)                         *
 *==============================================*/

/**
 * @brief 点亮LED1
 * 
 * 将P0.17引脚输出低电平，LED1点亮。
 * 
 * @note 由于采用低电平点亮设计，输出低电平即可点亮LED
 */
void LED1_Open(void)
{
    /* 输出低电平 → LED点亮 */
    nrf_gpio_pin_clear(LED_0);
}

/**
 * @brief 熄灭LED1
 * 
 * 将P0.17引脚输出高电平，LED1熄灭。
 */
void LED1_Close(void)
{
    /* 输出高电平 → LED熄灭 */
    nrf_gpio_pin_set(LED_0);
}

/**
 * @brief 翻转LED1状态
 * 
 * 将P0.17引脚电平翻转：
 *   - 如果当前点亮（低电平），则变为熄灭（高电平）
 *   - 如果当前熄灭（高电平），则变为点亮（低电平）
 */
void LED1_Toggle(void)
{
    /* 翻转当前电平状态 */
    nrf_gpio_pin_toggle(LED_0);
}

/*==============================================*
 * LED2控制函数 (P0.18)                         *
 *==============================================*/

/**
 * @brief 点亮LED2
 * 
 * 将P0.18引脚输出低电平，LED2点亮。
 */
void LED2_Open(void)
{
    /* 输出低电平 → LED点亮 */
    nrf_gpio_pin_clear(LED_1);
}

/**
 * @brief 熄灭LED2
 * 
 * 将P0.18引脚输出高电平，LED2熄灭。
 */
void LED2_Close(void)
{
    /* 输出高电平 → LED熄灭 */
    nrf_gpio_pin_set(LED_1);
}

/**
 * @brief 翻转LED2状态
 * 
 * 将P0.18引脚电平翻转。
 */
void LED2_Toggle(void)
{
    /* 翻转当前电平状态 */
    nrf_gpio_pin_toggle(LED_1);
}

/*==============================================*
 * LED3控制函数 (P0.19)                         *
 *==============================================*/

/**
 * @brief 点亮LED3
 * 
 * 将P0.19引脚输出低电平，LED3点亮。
 */
void LED3_Open(void)
{
    /* 输出低电平 → LED点亮 */
    nrf_gpio_pin_clear(LED_2);
}

/**
 * @brief 熄灭LED3
 * 
 * 将P0.19引脚输出高电平，LED3熄灭。
 */
void LED3_Close(void)
{
    /* 输出高电平 → LED熄灭 */
    nrf_gpio_pin_set(LED_2);
}

/**
 * @brief 翻转LED3状态
 * 
 * 将P0.19引脚电平翻转。
 */
void LED3_Toggle(void)
{
    /* 翻转当前电平状态 */
    nrf_gpio_pin_toggle(LED_2);
}

/*==============================================*
 * LED4控制函数 (P0.20)                         *
 *==============================================*/

/**
 * @brief 点亮LED4
 * 
 * 将P0.20引脚输出低电平，LED4点亮。
 */
void LED4_Open(void)
{
    /* 输出低电平 → LED点亮 */
    nrf_gpio_pin_clear(LED_3);
}

/**
 * @brief 熄灭LED4
 * 
 * 将P0.20引脚输出高电平，LED4熄灭。
 */
void LED4_Close(void)
{
    /* 输出高电平 → LED熄灭 */
    nrf_gpio_pin_set(LED_3);
}

/**
 * @brief 翻转LED4状态
 * 
 * 将P0.20引脚电平翻转。
 */
void LED4_Toggle(void)
{
    /* 翻转当前电平状态 */
    nrf_gpio_pin_toggle(LED_3);
}
