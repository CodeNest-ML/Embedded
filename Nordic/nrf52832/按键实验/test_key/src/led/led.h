/**
 * @file led.h
 * @brief LED驱动头文件
 * 
 * 该文件定义了nRF52832芯片的GPIO LED接口相关声明和宏定义。
 * 使用P0端口的17-20引脚作为LED输出控制。
 * 
 * 硬件连接：
 *   - LED1 连接至 P0.17 引脚
 *   - LED2 连接至 P0.18 引脚
 *   - LED3 连接至 P0.19 引脚
 *   - LED4 连接至 P0.20 引脚
 * 
 * LED电路说明：
 *   - LED采用低电平点亮设计（输出低电平时LED点亮）
 *   - 这意味着：
 *     - nrf_gpio_pin_clear() → LED点亮
 *     - nrf_gpio_pin_set() → LED熄灭
 *     - nrf_gpio_pin_toggle() → LED状态翻转
 * 
 * @note LED_START和LED_STOP用于定义LED引脚范围
 */

#include <stdint.h>

#ifndef __LED_H
#define __LED_H

/*==============================================*
 * LED引脚范围定义                              *
 *==============================================*/
/** @brief LED引脚起始编号 */
#define LED_START      17
/** @brief LED0引脚 P0.17 */
#define LED_0          17
/** @brief LED1引脚 P0.18 */
#define LED_1          18
/** @brief LED2引脚 P0.19 */
#define LED_2          19
/** @brief LED3引脚 P0.20 */
#define LED_3          20
/** @brief LED引脚结束编号 */
#define LED_STOP       20

/**
 * @brief 初始化所有LED
 * 
 * 配置P0.17~P0.20引脚为GPIO输出模式。
 * 初始化后所有LED处于熄灭状态（输出高电平）。
 * 
 * @note 该函数应该在系统初始化阶段调用，通常在main函数开始时调用
 */
void LED_Init(void);

/**
 * @brief 点亮LED1
 * 
 * 将P0.17引脚输出低电平，LED1点亮。
 */
void LED1_Open(void);

/**
 * @brief 熄灭LED1
 * 
 * 将P0.17引脚输出高电平，LED1熄灭。
 */
void LED1_Close(void);

/**
 * @brief 翻转LED1状态
 * 
 * 将P0.17引脚电平翻转：
 *   - 如果当前点亮，则变为熄灭
 *   - 如果当前熄灭，则变为点亮
 */
void LED1_Toggle(void);

/**
 * @brief 点亮LED2
 * 
 * 将P0.18引脚输出低电平，LED2点亮。
 */
void LED2_Open(void);

/**
 * @brief 熄灭LED2
 * 
 * 将P0.18引脚输出高电平，LED2熄灭。
 */
void LED2_Close(void);

/**
 * @brief 翻转LED2状态
 * 
 * 将P0.18引脚电平翻转。
 */
void LED2_Toggle(void);

/**
 * @brief 点亮LED3
 * 
 * 将P0.19引脚输出低电平，LED3点亮。
 */
void LED3_Open(void);

/**
 * @brief 熄灭LED3
 * 
 * 将P0.19引脚输出高电平，LED3熄灭。
 */
void LED3_Close(void);

/**
 * @brief 翻转LED3状态
 * 
 * 将P0.19引脚电平翻转。
 */
void LED3_Toggle(void);

/**
 * @brief 点亮LED4
 * 
 * 将P0.20引脚输出低电平，LED4点亮。
 */
void LED4_Open(void);

/**
 * @brief 熄灭LED4
 * 
 * 将P0.20引脚输出高电平，LED4熄灭。
 */
void LED4_Close(void);

/**
 * @brief 翻转LED4状态
 * 
 * 将P0.20引脚电平翻转。
 */
void LED4_Toggle(void);


#endif /* __LED_H */
