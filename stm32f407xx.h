#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

#define __vo volatile
#define __weak _attribute__((weak))

/*
 * Processor specific details
 */

#define NVIC_ISER0             ((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1             ((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2             ((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3             ((__vo uint32_t*)0xE000E10c)

/*
 * Arm cortex processor priority registers
 */

#define NVIC_ICER0             ((__vo uint32_t*)0XE000E180)
#define NVIC_ICER1             ((__vo uint32_t*)0XE000E184)
#define NVIC_ICER2             ((__vo uint32_t*)0XE000E188)
#define NVIC_ICER3             ((__vo uint32_t*)0XE000E18C)


/*
 * ARM Cortex Mx processor priority register address calculation
 */
#define NVIC_PR_BASE_ADDR      ((__vo uint32_t*)0XE000E400)


/*
 * ARM Cortex Mx Processor number of priority bits implemented by priority register
 */

#define NO_PR_BITS_IMPLEMENTED   4

/*
 * Base addresses of flash and SRAM
 */

#define FLASH_BASEADDR          0x08000000U
#define SRAM1_BASEADDR          0x20000000U
#define SRAM2_BASEADDR          0x2001C000U
#define ROM_BASEADDR            0x1FFF0000U
#define SRAM_BASEADDR           SRAM1_BASEADDR

#define PERIPH_BASEADDR           0x40000000U
#define APB1PERIPH_BASEADDR       PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR       0x40010000U
#define AHB1PERIPH_BASEADDR       0x40020000U
#define AHB2PERIPH_BASEADDR       0x50000000U

/*
 * AHB1
 */

#define GPIOA_BASEADDR            (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR            (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR            (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR            (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR            (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR            (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR            (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR            (AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR            (AHB1PERIPH_BASEADDR + 0x2000)
#define RCC_BASEADDR              (AHB1PERIPH_BASEADDR + 0x3800)

/*
 * APB1
 */


#define I2C1_BASEADDR             (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR             (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR             (APB1PERIPH_BASEADDR + 0x3800)
#define SPI2_BASEADDR             (APB1PERIPH_BASEADDR + 0x3C00)
#define SPI3_BASEADDR             (APB1PERIPH_BASEADDR + 0x4400)
#define USART2_BASEADDR           (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR           (APB1PERIPH_BASEADDR + 0x4800)
#define USART4_BASEADDR           (APB1PERIPH_BASEADDR + 0x4C00)
#define USART5_BASEADDR           (APB1PERIPH_BASEADDR + 0x5000)

/*
 * APB2
 */

#define EXTI_BASEADDR              (APB2PERIPH_BASEADDR + 0x3C00)
#define SPI1_BASEADDR              (APB2PERIPH_BASEADDR + 0x3000)
#define USART1_BASEADDR            (APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR            (APB2PERIPH_BASEADDR + 0x1400)
#define SYSCFG_BASEADDR            (APB2PERIPH_BASEADDR + 0x3800)


/*
 * Peripheral structure definations
 *
 */

typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
}GPIO_RegDef_t;

typedef struct
{
	uint32_t CR;
	uint32_t PLLCFGR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t AHB1RSTR;
	uint32_t AHB2RSTR;
	uint32_t AHB3RSTR;
	uint32_t RESERVED0;
	uint32_t APB1RSTR;
	uint32_t APB2RSTR;
	uint32_t RESERVED1[2];
	uint32_t AHB1ENR;
	uint32_t AHB2ENR;
	uint32_t AHB3ENR;
	uint32_t RESERVED2;
	uint32_t APB1ENR;
	uint32_t APB2ENR;
	uint32_t RESERVED3[2];
	uint32_t AHB1LPENR;
	uint32_t AHB2LPENR;
	uint32_t AHB3LPENR;
	uint32_t RESERVED4;
	uint32_t APB1LPENR;
	uint32_t APB2LPENR;
	uint32_t RESERVED5[2];
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t RESERVED6[2];
	uint32_t SSCGR;
	uint32_t PLLI2SCFGR;
}RCC_RegDef_t;

/*
 * peripheral register definition structure for EXTI
 */

typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
}EXTI_RegDef_t;


/*
 * peripheral register definition structure for SYSCFG
 */

typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	     uint32_t RESERVED1[2];
	__vo uint32_t CMPCR;
	     uint32_t RESERVED2[2];
	__vo uint32_t CFGR;
}SYSCFG_RegDef_t;


/*
 *
 */



//GPIO_regDef_t pGPIOA   = (GPIO_regDef_t) AHB1PERIPH_BASEADDR;
#define GPIOA        (GPIO_RegDef_t*) GPIOA_BASEADDR
#define GPIOB        (GPIO_RegDef_t*) GPIOB_BASEADDR
#define GPIOC        (GPIO_RegDef_t*) GPIOC_BASEADDR
#define GPIOD        (GPIO_RegDef_t*) GPIOD_BASEADDR
#define GPIOE        (GPIO_RegDef_t*) GPIOE_BASEADDR
#define GPIOF        (GPIO_RegDef_t*) GPIOF_BASEADDR
#define GPIOG        (GPIO_RegDef_t*) GPIOG_BASEADDR
#define GPIOH        (GPIO_RegDef_t*) GPIOH_BASEADDR
#define GPIOI        (GPIO_RegDef_t*) GPIOI_BASEADDR
#define RCC          ((RCC_RegDef_t*) RCC_BASEADDR)

#define GPIOA_PCLK_EN()     (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()     (RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()     (RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()     (RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()     (RCC->AHB1ENR |= (1<<4))
#define GPIOF_PCLK_EN()     (RCC->AHB1ENR |= (1<<5))
#define GPIOG_PCLK_EN()     (RCC->AHB1ENR |= (1<<6))
#define GPIOH_PCLK_EN()     (RCC->AHB1ENR |= (1<<7))
#define GPIOI_PCLK_EN()     (RCC->AHB1ENR |= (1<<8))
#define SYSCFG_PCLK_EN()    (RCC-> APB2ENR |= (1<<0))

#define GPIOA_PCLK_DI()     (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()     (RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()     (RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()     (RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()     (RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DI()     (RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DI()     (RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DI()     (RCC->AHB1ENR &= ~(1<<7))
#define GPIOI_PCLK_DI()     (RCC->AHB1ENR &= ~(1<<8))



#define RCC                 ((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI                ((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG              ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)


/*
 *
 */
/******GPIOs Reseting********/



#define  GPIOA_REG_RESET()        do{  (RCC-> AHB1RSTR |= (1<<0));   ( RCC-> AHB1RSTR &= ~(1<<0));} while(0)
#define  GPIOB_REG_RESET()        do{  (RCC-> AHB1RSTR |= (1<<1));   ( RCC-> AHB1RSTR &= ~(1<<1));} while(0)
#define  GPIOC_REG_RESET()        do{  (RCC-> AHB1RSTR |= (1<<2));   ( RCC-> AHB1RSTR &= ~(1<<2));} while(0)
#define  GPIOD_REG_RESET()        do{  (RCC-> AHB1RSTR |= (1<<3));   ( RCC-> AHB1RSTR &= ~(1<<3));} while(0)
#define  GPIOE_REG_RESET()        do{  (RCC-> AHB1RSTR |= (1<<4));   ( RCC-> AHB1RSTR &= ~(1<<4));} while(0)
#define  GPIOF_REG_RESET()        do{  (RCC-> AHB1RSTR |= (1<<5));   ( RCC-> AHB1RSTR &= ~(1<<5));} while(0)
#define  GPIOG_REG_RESET()        do{  (RCC-> AHB1RSTR |= (1<<6));   ( RCC-> AHB1RSTR &= ~(1<<6));} while(0)
#define  GPIOH_REG_RESET()        do{  (RCC-> AHB1RSTR |= (1<<7));   ( RCC-> AHB1RSTR &= ~(1<<7));} while(0)
#define  GPIOI_REG_RESET()        do{  (RCC-> AHB1RSTR |= (1<<8));   ( RCC-> AHB1RSTR &= ~(1<<8));} while(0)

/******Some Generic Macros*******/

#define ENABLE          1
#define DISABLE         0
#define SET             ENABLE
#define RESET           DISABLE
#define GPIO_PIN_SET    SET
#define GPIO_PIN_RESET    RESET



/*
 * IRQ(Interrupt Request) Numbers of STM32F407x MCU
 */

#define IRQ_NO_EXTI0       6
#define IRQ_NO_EXTI1       7
#define IRQ_NO_EXTI2       8
#define IRQ_NO_EXTI3       9
#define IRQ_NO_EXTI4      10
#define IRQ_NO_EXTI9_5    23
#define IRQ_NO_EXTI15_10  40

/*
 * returns port code for given GPIOx base address
 */

/*
 * This macro returns a code (between 0 to 7) for a given GPIO base address(x)
 */

#define GPIO_BASEADDR_TO_CODE(x)     ( ( x == GPIOA)?0:\
		                               ( x == GPIOB)?1:\
		                               ( x == GPIOC)?2:\
		                               ( x == GPIOD)?3:\
		                               ( x == GPIOE)?4:\
		                               ( x == GPIOF)?5:\
		                               ( x == GPIOG)?6:\
		                               ( x == GPIOH)?7:\
		                               ( x == GPIOI)?8:0)

#include "stm32f407xx_gpio_driver.h"


#endif /* INC_STM32F407XX_H_ */
