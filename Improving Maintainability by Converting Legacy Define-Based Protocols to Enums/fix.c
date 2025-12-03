#ifndef FRONT_PROTOCOL_H_
#define FRONT_PROTOCOL_H_

#include <stdint.h>

/* ----------------------------------------------------------------------
 * 1. 장비 제어 명령 (Front → Main 또는 Main → Front 공통)
 * --------------------------------------------------------------------*/
typedef enum {
    CMD_CV_PWM              = 0xC4,   // CV/PWM 출력
    CMD_DEVICE_STATUS       = 0xD1,   // 메인 장비 상태 요청/응답
    CMD_MCP48_STATUS        = 0xD2,   // DAC 상태
    CMD_REQUEST_FRONT       = 0xD3,   // Front 정보 요청 (메인으로부터)
    CMD_IP_PORT_INFO        = 0xD4,   // IP/Port 전달 (메인에서 보낼 때)
    CMD_TEMP_DCFAN          = 0xD6,   // 온도 + 팬속 정보
    CMD_BRIDGE_CHECK        = 0xD7,   // 브리지 모드 체크
    CMD_RESISTOR_INFO       = 0xD8,   // 저항값 정보
    CMD_LAN_STATUS_INFO     = 0xD9,   // LAN 상태 정보
    CMD_DEVICE_ECHO         = 0xE0,   // 장비 echo
    CMD_SENSING_LED         = 0xE1,   // 센싱 LED
    CMD_DEVICE_RESET        = 0xE2,   // 장비 리셋
    CMD_DEVICE_UPDATE       = 0xF0    // 펌웨어 업데이트 명령
} ProtocolCommand_t;

/* ----------------------------------------------------------------------
 * 2. LCD / UI 관련 상태
 * --------------------------------------------------------------------*/
typedef enum {
    LCD_STATUS_INITIALIZING = 30,
    LCD_STATUS_MODE_LOCAL   = 31,
    LCD_STATUS_MODE_REMOTE  = 32,
    LCD_STATUS_MODE_EXT     = 33,
    LCD_STATUS_MODE_LAN     = 34
} LcdStatus_t;

/* ----------------------------------------------------------------------
 * 3. 장비 모드 (Bridge / Individual 4채널)
 * --------------------------------------------------------------------*/
typedef enum {
    MODE_4CH_INDIVIDUAL = 15,
    MODE_2CH_INDIVIDUAL = 14,
    MODE_2CH_BRIDGE     = 13,
    MODE_3CH_BRIDGE     = 11,
    MODE_4CH_BRIDGE     = 7
} BridgeMode_t;

/* ----------------------------------------------------------------------
 * 4. 부트 요청/버전 정보
 * --------------------------------------------------------------------*/
#define DEVICE_FIRMWARE_VERSION   114
#define DEVICE_RESET_REQUEST      115

#define CHANGE_IP_PORT            51
#define ASK_BOOTING_INFO          52

/* ----------------------------------------------------------------------
 * 5. 프레임 제어 코드 (STX/ETX)
 * --------------------------------------------------------------------*/
#define STX 0x02
#define ETX 0x03

#endif /* FRONT_PROTOCOL_H_ */
