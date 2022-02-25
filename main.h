#ifndef _MAIN_H_
#define _MAIN_H_

// register address
#define RCC_BASE 0x40023800
#define GPIOA_BASE 0x40020000
#define SCB_BASE 0xE000ED00
#define STK_BASE 0xE000E010

#define RCC_AHB1ENR *(volatile uint32_t *)(RCC_BASE + 0x30)
#define RCC_AHB1RSTR *(volatile uint32_t *)(RCC_BASE + 0x10)
#define GPIOA_MODER *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x14)

#define SCB_SHCSR *(volatile uint32_t *)(SCB_BASE + 0x24)
#define SCB_SHPR3 *(volatile uint32_t *)(SCB_BASE + 0x20)
#define SCB_ICSR *(volatile uint32_t *)(SCB_BASE + 0x04)

#define STK_LOAD *(volatile uint32_t *)(STK_BASE + 0x04)
#define STK_SCSR *(volatile uint32_t *)(STK_BASE + 0x00)

// bit fields
#define GPIOA5 (1UL << 10)
#define LD2_ON (1 << 5)
#define LD2_OFF ~(1 << 5)

#endif