/**
 * @file key.c
 * @brief 按键驱动实现文件
 * 
 * 该文件实现了nRF52832芯片的GPIO按键检测功能。
 * 包含按键初始化、软件消抖检测、按键释放等待等功能。
 * 
 * 功能特性：
 *   - 支持4个独立按键检测
 *   - 软件消抖处理，避免机械按键抖动导致的误触发
 *   - 阻塞式等待按键释放，确保每次按下只触发一次
 * 
 * 消抖原理：
 *   机械按键在按下瞬间会产生短暂的接触不稳定现象（抖动），
 *   持续时间通常为5~10ms。本驱动通过延时后再检测的方式，
 *   判断按键状态是否稳定，从而过滤掉抖动干扰。
 * 
 * @see key.h 按键驱动头文件
 */

#include "key.h"
#include <hal/nrf_gpio.h>

/**
 * @brief 延时函数（软件延时）
 * 
 * 使用空循环实现的简单延时函数，用于按键消抖和按键释放等待。
 * 延时时间由传入的参数temp控制，temp值越大延时越长。
 * 
 * @param temp 延时计数器初值，值越大延时越长
 * 
 * @warning 这是一个阻塞式延时，会占用CPU时间
 * @note 实际延时时间与CPU主频有关，需根据实际情况调整temp值
 */
void Delay(uint32_t temp)
{
    /* 空循环延时
     * 每次循环temp递减，直到为0时退出
     * 延时时间 ≈ temp × 单次循环执行时间 */
    for (; temp != 0; temp--)
        ;
};

/**
 * @brief 初始化所有按键
 * 
 * 配置P0.13~P0.16引脚为GPIO输入模式，并启用内部上拉电阻。
 * 
 * 配置详情：
 *   - 输入模式：读取引脚电平状态
 *   - 上拉电阻：按键未按下时引脚保持高电平
 *   - 低电平触发：按键按下时引脚被拉低读取到0
 * 
 * @note 本函数只初始化4个标准按键引脚，如需添加更多按键需修改源码
 * @see key.h 中的引脚定义
 */
void KEY_Init(void)
{
    /* 配置P0.13为输入模式，启用内部上拉电阻 */
    nrf_gpio_cfg_input(13, NRF_GPIO_PIN_PULLUP);
    
    /* 配置P0.14为输入模式，启用内部上拉电阻 */
    nrf_gpio_cfg_input(14, NRF_GPIO_PIN_PULLUP);
    
    /* 配置P0.15为输入模式，启用内部上拉电阻 */
    nrf_gpio_cfg_input(15, NRF_GPIO_PIN_PULLUP);
    
    /* 配置P0.16为输入模式，启用内部上拉电阻 */
    nrf_gpio_cfg_input(16, NRF_GPIO_PIN_PULLUP);
}

/**
 * @brief 检测按键1(KEY1)是否按下
 * 
 * 采用软件消抖方式检测按键1的按下状态：
 * 1. 首次检测引脚电平，如果为低电平（按下）进入下一步
 * 2. 延时一段时间（消抖）
 * 3. 再次检测引脚电平，确认是否仍为低电平
 *    - 如果仍是低电平，说明是真正的按键按下
 *    - 如果变为高电平，说明是抖动，忽略此次按下
 * 4. 等待按键释放（循环检测直到引脚变为高电平）
 * 5. 返回0表示一次有效的按键按下事件
 * 
 * @return uint8_t 
 *         - 0: 成功检测到一次按键按下并已释放
 *         - 1: 按键未按下或处于消抖/等待释放状态
 * 
 * @note 调用此函数会阻塞，直到按键释放
 */
uint8_t KEY1_Down(void)
{
    /* 第一步：检测是否有按键按下
     * 读取P0.13引脚电平，按键按下时为低电平(0) */
    if (nrf_gpio_pin_read(KEY_1) == 0)
    {
        /* 检测到低电平，可能是按下或抖动
         * 进入第二步：延时消抖 */
        Delay(10000);  // 延时约10ms（具体时间取决于CPU频率）
        
        /* 第三步：再次检测确认
         * 如果仍然是低电平，确认是真正的按键按下 */
        if (nrf_gpio_pin_read(KEY_1) == 0)
        {
            /* 第四步：等待按键释放
             * 循环检测直到引脚恢复高电平
             * 确保每次按下只返回一次有效值 */
            while (nrf_gpio_pin_read(KEY_1) == 0)
                ;  // 等待释放
            
            /* 第五步：返回0表示检测成功
             * 外部代码通过判断返回值是否为0来确定按键事件 */
            return 0;
        }
        else
        {
            /* 消抖后变为高电平，说明是抖动干扰
             * 返回1表示此次按下无效 */
            return 1;
        }
    }
    else
    {
        /* 未检测到低电平，按键处于未按下状态
         * 返回1表示没有按键按下 */
        return 1;
    }
}

/**
 * @brief 检测按键2(KEY2)是否按下
 * 
 * 功能与KEY1_Down()完全相同，检测P0.14引脚对应的按键2。
 * 
 * @return uint8_t 
 *         - 0: 按键已按下并释放
 *         - 1: 按键未按下或处于消抖/等待释放状态
 * 
 * @see KEY1_Down() 详细的检测流程说明
 */
uint8_t KEY2_Down(void)
{
    /* 检测P0.14引脚电平 */
    if (nrf_gpio_pin_read(KEY_2) == 0)
    {
        /* 延时消抖 */
        Delay(10000);
        
        /* 再次检测确认 */
        if (nrf_gpio_pin_read(KEY_2) == 0)
        {
            /* 等待按键释放 */
            while (nrf_gpio_pin_read(KEY_2) == 0)
                ;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

/**
 * @brief 检测按键3(KEY3)是否按下
 * 
 * 功能与KEY1_Down()完全相同，检测P0.15引脚对应的按键3。
 * 
 * @return uint8_t 
 *         - 0: 按键已按下并释放
 *         - 1: 按键未按下或处于消抖/等待释放状态
 * 
 * @see KEY1_Down() 详细的检测流程说明
 */
uint8_t KEY3_Down(void)
{
    /* 检测P0.15引脚电平 */
    if (nrf_gpio_pin_read(KEY_3) == 0)
    {
        /* 延时消抖 */
        Delay(10000);
        
        /* 再次检测确认 */
        if (nrf_gpio_pin_read(KEY_3) == 0)
        {
            /* 等待按键释放 */
            while (nrf_gpio_pin_read(KEY_3) == 0)
                ;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

/**
 * @brief 检测按键4(KEY4)是否按下
 * 
 * 功能与KEY1_Down()完全相同，检测P0.16引脚对应的按键4。
 * 
 * @return uint8_t 
 *         - 0: 按键已按下并释放
 *         - 1: 按键未按下或处于消抖/等待释放状态
 * 
 * @see KEY1_Down() 详细的检测流程说明
 */
uint8_t KEY4_Down(void)
{
    /* 检测P0.16引脚电平 */
    if (nrf_gpio_pin_read(KEY_4) == 0)
    {
        /* 延时消抖 */
        Delay(10000);
        
        /* 再次检测确认 */
        if (nrf_gpio_pin_read(KEY_4) == 0)
        {
            /* 等待按键释放 */
            while (nrf_gpio_pin_read(KEY_4) == 0)
                ;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}
