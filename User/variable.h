#ifndef _VARIABLE_H_
#define _VARIABLE_H_


#include "stm32f10x_it.h"
#include "command.h"


#define SERIAL_NUMBER_ADDR          0X0807F5D0          /*���кŴ�ŵ�ַ*/  //16
#define HARDWARE_VERSION_ADDR  0X0807F5E0  /*���кŴ�ŵ�ַ*/ //16
#define AUTO_LEVELEFLAG_ADDR       0X0807F5F0      /**/  // 2
#define AUTO_FILAMENT_DEV_ADDR  0X0807F5F4  /**/ // 2 

#define RECOVERY_SAVE_FLAG_ADDR             0X0807F600//�ϵ������������λ��
#define RECOVERY_SAVE_ADDR                      0X0807F602

//#define FACTORY_SETTINGS_STORE_FLAG_ADDR   0X0807F600  	/*�������ô洢��־��ŵ�ַ*/
//#define FACTORY_SETTINGS_PARAMETERS_ADDR  0X0807F602	/*�������ò�����ŵ�ַ*/

#define USER_SETTINGS_STORE_FLAG_ADDR   0X0807F800	/*�û����ô洢��־��ŵ�ַ*/
#define USER_SETTINGS_PARAMETERS_ADDR  0X0807F802	/*�û����ò�����ŵ�ַ*/
  


  #define WIFI_AUTO_CONNECT_FLAG_ADDR    0X0807FC00	/*����WiFi�Զ����ӱ�־*/
  #define WIFI_SERVER_PARAMETERS_ADDR    0X0807FC02	/*WiFi server������ŵ�ַ*/
  #define WIFI_USER_STORE_FLAG_ADDR         0X0807FCA0	/*wifi�û����ò�����ŵ�ַ*/
  #define WIFI_USER_PARAMETERS_ADDR        0X0807FCA2	/*wifi�û����ò�����ŵ�ַ*/
  #define MOTOR_UNLOCK_TIME_FLAG_ADDR   0X0807FF00	 

  #define FILAMENT_DEFAULT_ADDR    0X0807FF02	/*save filament default vavue*/

  #define BED_LEVELING_HOMINGXYZ_ADDR  0X0807FF10	//�Զ���ƽʱ�������λ���걣��(x0,y0,z0)





typedef struct{
       u8      Motor_Lock;  // 1:���������  0:������Խ���
	float   print_percent;  //��ӡ����
	float   print_file_size;  //�ļ���С
	u8      Filament_Dev_Flag;//�Ĳļ���־
	u8     Auto_Levele_Flag; //�Զ���ƽ��־
	u32   Motor_Disable_Times; //�������ʱ��
	u16   Beep_period ; //period in milliseconds
       int    Beep_duration ; //duration in milliseconds 
       u8    files_refresh_flag; //ˢ��SD���ļ�
       u8    feed_tare;//��ӡ����
       u8   system_status;//ϵͳ״̬
	u8   sd_print_flag;//SD ����ӡʹ��
	u8   sd_print_status;//SD����ӡ״̬
	u8   serial_ack_flag;//����Ӧ���־
	u8   serial_printf_flag;//���ڴ�ӡ��־
	u8   sd_file_cmp;//ִ�й�M23ѡ���gcode�ļ�
	u8   serial_axis_move_cmd;//=DISABLE;��������־
	u8   selected_file_pos;//��λ��ѡ����ļ���������sd_file_name��sd_file_namebuf�е�λ��
	int   serial_print_time;//���ڷ��͵Ĵ�ӡʱ������ӡ����
	u8   serial_print_flag;//���ڴ�ӡ��־
       u32 pause_time;  //G4 ��ͣʱ��
       u8   pause_flag;  //G4��ͣ��־
       u8   stop_flag;    //��ֹ��ӡ
       u16 fan_hotend_speed;//�ķ���ٶ�
       u16 fan_controler_speed;//��������ٶ�
       u8 Unexpected_events;//ͻ���¼�
       u8  sd_status;//sd��״̬
       u8 auto_leveling_calculate_enable;//�Զ���ƽ����ʹ��
       u8 sd_file_num;//gcode�ļ�����
       
}SystemInfor;

typedef struct{
	char  printer_file_path[512]; 
}Systembuf_Info;

extern SystemInfor system_infor;
extern Systembuf_Info  Systembuf_Infos;
extern float Current_Position[4];
extern float Destination[4];
extern char cmdbuffer[BUFSIZE][MAX_CMD_SIZE];
extern bool axis_known_position[3];//�Ƿ��Ѿ���λ��־


void system_data_init(void);
void SD_Printdata_init(void);


#endif

