#include "variable.h"
#include "LCD2004.h"
#include "sd_print.h"




SystemInfor system_infor;
Systembuf_Info  Systembuf_Infos;
float Current_Position[4] = {0.0};
float Destination[4];
char cmdbuffer[BUFSIZE][MAX_CMD_SIZE];
bool axis_known_position[3] = {false, false, false};//�Ƿ��Ѿ���λ��־

/*
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
       u8    percentage;//��ӡ����
       u8   system_status;//ϵͳ״̬
	u8   sd_print_flag;//SD ����ӡʹ��
	u8   sd_print_status;//SD����ӡ״̬
	u8   serial_ack_flag;//����Ӧ���־
	u8   serial_printf_flag;//���ڴ�ӡ��־
	u8   sd_file_cmp;//ִ�й�M23ѡ���gcode�ļ�
	u8   serial_axis_move_cmd;//=DISABLE;��������־
       
}SystemInfor;
*/
/**********************************************************************
*****��λ�ϵ��ʼ������
*****
*****
***********************************************************************/
void system_data_init(void)
{
	system_infor.serial_axis_move_cmd = DISABLE;
	system_infor.print_file_size=0;
	system_infor.system_status=IDLE;
	system_infor.sd_file_cmp=0;
	system_infor.fan_controler_speed =128;
	system_infor.Unexpected_events=DISABLE;//ͻ���¼�
	system_infor.auto_leveling_calculate_enable =ENABLE;
	system_infor.serial_printf_flag = DISABLE;
}

void SD_Printdata_init(void)
{
	system_infor.sd_print_status = SD_PRINTING;
	system_infor.print_percent=0.0;
      system_infor.system_status = PRINT; 
      system_infor.pause_flag = 0;
      system_infor.stop_flag = 0;

}



































