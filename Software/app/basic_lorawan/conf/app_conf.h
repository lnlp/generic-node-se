/** Copyright © 2021 The Things Industries B.V.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/**
 * @file app_conf.h
 * @brief Common configuration file for GNSE applications
 *
 * @copyright Copyright (c) 2021 The Things Industries B.V.
 *
 */

#ifndef APP_CONF_H
#define APP_CONF_H

#define APP_LOG_ENABLED 1

/* if ON (=1) it enables the debugger plus 4 dgb pins */
/* if OFF (=0) the debugger is OFF (lower consumption) */
#define DEBUGGER_ON       0


/* LOW_POWER_DISABLE = 0 : LowPowerMode enabled : MCU enters stop2 mode*/
/* LOW_POWER_DISABLE = 1 : LowPowerMode disabled : MCU enters sleep mode only */
#define LOW_POWER_DISABLE 0

/* LoRaWAN v1.0.2 software based OTAA activation information */
#define APPEUI                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#define DEVEUI                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#define APPKEY                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

/**
  * Supported requester to the MCU Low Power Manager - can be increased up  to 32
  * It lists a bit mapping of all user of the Low Power Manager
  */
typedef enum
{
  CFG_LPM_APPLI_Id,
  CFG_LPM_UART_TX_Id,
  CFG_LPM_TCXO_WA_Id,
} CFG_LPM_Id_t;

/**
  * IWDG timer definitions
  */

/* if ON (=1) the independent watchdog timer is used (reset MCU after inactivity) */
/* if OFF (=0) the independent watchdog timer is not used */
#define IWDG_TIMER_ON       0

/* Watchdog counter trigger in seconds */
/* This changes based on the config (prescalers for LSI and IWDG) */
/* One tick is 1.024 seconds with default config: 1 / (LSI_VALUE / LSIPrescaler) = 1 / (250 / 256) */
/* Important is to keep LSI_VALUE at 250 when using the LSI prescaler of 128 */
/* Maximum is 4095 */
#define GNSE_IWDG_TIMEOUT_S 10U

/**
  * sequencer definitions
  */

/**
  * This is the list of priority required by the application
  * Each Id shall be in the range 0..31
  */
typedef enum
{
  CFG_SEQ_Prio_0,
  CFG_SEQ_Prio_NBR,
} CFG_SEQ_Prio_Id_t;

/**
  * This is the list of task id required by the application
  * Each Id shall be in the range 0..31
  */
typedef enum
{
  CFG_SEQ_Task_LmHandlerProcess,
  CFG_SEQ_Task_LoRaSendOnTxTimerOrButtonEvent,
  CFG_SEQ_Task_NBR
} CFG_SEQ_Task_Id_t;

#endif /* APP_CONF_H */
