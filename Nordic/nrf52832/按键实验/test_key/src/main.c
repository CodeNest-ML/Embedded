/**
 * @file main.c
 * @brief nRF52832 按键控制LED示例程序主文件
 * 
 * 本程序演示了使用Zephyr RTOS读取GPIO按键输入，
 * 并根据按键状态控制LED灯的亮灭与翻转。
 * 
 * 硬件连接说明：
 *   - 按键：P0.13(KEY1)、P0.14(KEY2)、P0.15(KEY3)、P0.16(KEY4)
 *   - LED灯：P0.17(LED1)、P0.18(LED2)、P0.19(LED3)、P0.20(LED4)
 * 
 * @note 所有GPIO引脚均使用P0端口
 */

#include <zephyr/kernel.h>
#include <led/led.h>
#include <key/key.h>

/**
 * @brief 主函数 - 程序入口点
 * 
 * 该函数完成以下功能：
 * 1. 初始化LED驱动，将LED引脚配置为输出模式
 * 2. 初始化按键驱动，将按键引脚配置为输入模式并启用上拉电阻
 * 3. 进入主循环，轮询检测按键状态
 * 4. 当检测到按键按下时，切换对应LED的状态
 * 
 * @return int 程序正常退出时返回0（实际为无限循环，不会执行到此）
 */
int main(void)
{
        /* 初始化LED驱动
         * 配置P0.17~P0.20引脚为GPIO输出模式
         * 初始状态下所有LED关闭（输出高电平）*/
        LED_Init();
        
        /* 初始化按键驱动
         * 配置P0.13~P0.16引脚为GPIO输入模式
         * 启用内部上拉电阻，按键未按下时读取到高电平 */
        KEY_Init();
        
        /* 主循环 - 轮询方式检测按键
         * 由于Zephyr下GPIO中断可能配置较复杂，
         * 本示例采用简单的轮询方式检测按键状态 */
        while (1)
        {
                /* 检测按键1(KEY1)是否按下
                 * 按键按下时引脚被拉低，KEY1_Down()返回0
                 * 当检测到按键按下时，翻转LED1的状态 */
                if (KEY1_Down() == 0)
                {
                        LED1_Toggle();  // 翻转LED1：亮->灭 或 灭->亮
                }
                
                /* 检测按键2(KEY2)是否按下
                 * 按下时翻转LED2的状态 */
                if (KEY2_Down() == 0)
                {
                        LED2_Toggle();  // 翻转LED2
                }
                
                /* 检测按键3(KEY3)是否按下
                 * 按下时翻转LED3的状态 */
                if (KEY3_Down() == 0)
                {
                        LED3_Toggle();  // 翻转LED3
                }
                
                /* 检测按键4(KEY4)是否按下
                 * 按下时翻转LED4的状态 */
                if (KEY4_Down() == 0)
                {
                        LED4_Toggle();  // 翻转LED4
                }
                
                /* 预留代码：可用于测试其他按键功能
                 * 取消注释即可使用TKY按键（需在key.h中定义TKY引脚）
                 * if (TKY_Down() == 1)  // 判断按键是否按下
                 * {
                 *     LED1_Toggle();    // 按下时翻转LED1
                 * }
                 */
        }
}
