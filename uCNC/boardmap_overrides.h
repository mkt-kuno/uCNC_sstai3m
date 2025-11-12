#ifndef BOADMAP_OVERRIDES_H
#define BOADMAP_OVERRIDES_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "boardmap_reset.h"
#define MCU MCU_AVR
#define BOARD "src/hal/boards/avr/boardmap_ramps14.h"
#define KINEMATIC KINEMATIC_CARTESIAN
#define AXIS_COUNT 1
#define BAUDRATE 115200
#define BOARD_NAME "TRIGORILLA"
#define PCINT0_PORT B
#define PCINT1_PORT J
#define PCINT2_PORT K
#define UART_PORT 0
#define UART2_PORT 0
#define ITP_TIMER 1
#define RTC_TIMER 0
#define ONESHOT_TIMER 4
#define IC74HC595_COUNT 0
#define IC74HC165_COUNT 0
#define STEP0_BIT 6
#define STEP0_PORT F
#define DIR0_BIT 7
#define DIR0_PORT F
#define STEP0_EN_BIT 2
#define STEP0_EN_PORT F
#define DOUT4_PORT A
#define LIMIT_X_BIT 5
#define LIMIT_X_PORT E
#define LIMIT_X_ISR -6
#define TX_BIT 1
#define TX_PORT E
#define RX_BIT 0
#define RX_PORT E
#define RX_PULLUP
#define TOOL_COUNT 0
//Custom configurations
#define BOARDMAP_RAMPS14_H true
#define AVR6 true
#define SPI_FREQ 100000UL
#define F_CPU 16000000UL


#ifdef __cplusplus
}
#endif
#endif
