/*
 * front.h
 *
 *  Created on: Feb 13, 2025
 *      Author: krmji
 */

#ifndef APPS_FRONT_H_
#define APPS_FRONT_H_

#if 1

//#define STROBE_DELAY					0xC1
//#define STROBE_PULSE					0xC2
//#define STROBE_RISEFALL				0xC3
#define CV_PWM							0xC4

#define DEVICE_STATUS					0xD1
#define MCP48_STATUS					0xD2

//#define REQUEST_FRONT					0xD3
#define REQUEST_FRONT					0xD3 //=210
//#define MAINFIRM_INFO					0xD3 //=210
#define IP_PORT_INFO      				0xD4 //메인에서 전달받은 정보를 구분할때만 사용하며 보낼때는 REQUEST_FRONT를 사용함.
#define TEMP_DCFAN                      0xD6
/*브리지모드*/
#define BRIDGE_CHECK                    0xD7

#define MODE_4CH_INDIVIDUAL     		15 //4개 채널 개별 사용  -->
#define MODE_2CH_INDIVIDUAL     		14 //2개 채널 개별 사용  -->
#define MODE_2CH_BRIDGE         		13 //2개 채널 브리지    -->
#define MODE_3CH_BRIDGE         		11 //3개 채널 브리지    -->
#define MODE_4CH_BRIDGE         		 7 //4개 채널 브리지    -->
/*end 브리지모드*/

//저항값 정보
#define RESISTOR_INFO                   0xD8 //216
//랜 연결 정보
#define LAN_Status_INFO                 0xD9 //217

#define DEVICE_ECHO						0xE0
#define SENSING_LED						0xE1
#define DEVICE_RESET					0xE2
#define DEVICE_UPDATE					0xF0



#define DEVICE_FIRMWARE_VERSION			114
#define DEVICE_RESET_REQUEST			115

#define LCD_STATUS_INITIALIZING			30
#define LCD_STATUS_MODE_LOCAL			31
#define LCD_STATUS_MODE_REMOTE			32
#define LCD_STATUS_MODE_EXT				33
#define LCD_STATUS_MODE_LAN				34

#define CHANGE_IP_PORT 51
#define ASK_BOOTING_INFO 52 // 프론트 쪽에서 펌웨어와 아이피 포트 정보 요청..

#define STX 0x02
#define ETX 0x03

#define CLCD4LINE 1

#endif

#if 1 //타이머 락 설정, 테스트 정의


#define FlashSave_Active 1
#define FlashLoad_Active 1
//#define TEST_ACTIVE 1

#endif
#if 0
/* 버튼 인터페이스 */
#define Btn_Mode_Pressed() 	(HAL_GPIO_ReadPin(ENTER_SW_GPIO_Port, ENTER_SW_Pin) == 0)
#define Btn_Enter_Pressed() (HAL_GPIO_ReadPin(ENTER_SW_GPIO_Port, ENTER_SW_Pin) == 0)
#define Btn_Up_Pressed() 	(HAL_GPIO_ReadPin(EN_A_GPIO_Port, EN_A_Pin) == 0)
#define Btn_Down_Pressed() 	(HAL_GPIO_ReadPin(EN_B_GPIO_Port, EN_B_Pin) == 0)


////공장 초기화 모드 + 엔터
//#define FactoryMode() 		( Btn_Mode_Pressed() && Btn_Enter_Pressed() && !Btn_Down_Pressed() && !Btn_Up_Pressed() )
////유저인터페이스  엔터 + 업
//#define UserinterfaceMode() ( !Btn_Mode_Pressed() && Btn_Enter_Pressed() && !Btn_Down_Pressed() && Btn_Up_Pressed())
////시스템버전체크  엔터 + 다운
//#define FirmVersionMode() 	( !Btn_Mode_Pressed() && Btn_Enter_Pressed() && Btn_Down_Pressed() && !Btn_Up_Pressed())
////채널개수선택 업 + 다운
//#define ChannelSelectMode() ( !Btn_Mode_Pressed() && !Btn_Enter_Pressed() && Btn_Down_Pressed() && Btn_Up_Pressed())

//순서  < 다운 | 업 | 엔터 | 모드 >

#define btn_mode 0b0001
#define btn_enter 0b0010
#define btn_up 0b0100
#define btn_down 0b1000
#define btn_nothing 0b0000

#define btn_mode_up   0b0101
#define btn_mode_down 0b1001

#define FactoryMode 0b0011   // 엔터 + 모드
#define UserinterfaceMode 0b0110 // 업 + 엔터
#define FirmVersionMode 0b1010 // 다운 + 엔터
#define ChannelSelectMode 0b1100 //다운 + 업
#define returnMode 0b0101 //업 + 모드


#define wait_time 100
#endif


void front_proc(void);



#endif /* APPS_FRONT_H_ */

