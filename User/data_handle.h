#ifndef __DATA_HANDLE_H__
#define __DATA_HANDLE_H__
#include "stm32f10x_it.h"


#define  TEMPERATURE_INFO                                      1   //�¶�
#define  RATE_FAN_LAYER                                   2  //���������ȡ��ٶ�
#define  PRINTING_STATUS                                3 //GCODE
#define  PRINTER_SD_STATUS                            4//��ӡ�� SD״̬
#define  COORDINATE_XYZ                                 5
#define  PRINTER_MESSAGE                                6 //��ӡ����Ϣ
#define  PRINTER_START_MESSAGE                    8// //�Զ���ƽ���Ĳļ�⡢WiFi�ϵ��Զ�������wifi״̬

#define  WIFI_IP_MESSAGE                                9   //wifi  ip
#define  WIFI_STATUS_MESSAGE                       10   //wifi  status
#define  WIFI_SERVER_MESSAGE                       11   //wifi  SSID��  server ip
#define  WIFI_SET_SUCCEE                                12  //wifi  set  ok
#define  WIFI_EXIST_TEST                                13  //wifi  exist test
#define  WIFI_DETAIL_MESSAGE                        14
#define  WIFI_DEBUG_MESSAGE                        15



#define  PRINTER_RESET                                   16 //��ӡ����λ
#define  SD_EXCEPTION                                      17 //SD���쳣
#define  RECOVER_STANDBY                                 18
#define  INPUT_STANDBY                                      19
#define  LCD_VERSION_INFO                               20 //LCD  ���汾��Ϣ
#define  TEMP_EXCEPTION                                  21  //�¶��쳣
#define  FILAMENT_DETECTOR                            22 //�Ĳļ��
#define  FILAMENT_DETECTOR_OFF_ON                            23 //�Ĳļ�⿪��





#define CMD_FILAMAND_NO                  1   //�Ĳ���


void Frash_Update_ToLCD(void);
void  Updata_To_LCD(u8 item) ;  //Add_Message(TEMP_EXCEPTION);
void ADD_Item_to_LCD(void);
void Main_Command_Handle(void);
void Add_MessageM(u8 item);

#endif
