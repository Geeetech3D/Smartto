#ifndef _SETTING_H_
#define _SETTING_H_

#include "stm32f10x.h"
#include "XZK_Configuration.h"
#include "XZK_Rule.h"
#include "math.h"
#include "stdbool.h"
#include "vector_3.h"



typedef enum
{
	FACTORY_SETTINGS = 0,
	USER_SETTINGS	
}SettingMode;

typedef struct 
{
    float min_position[3];	       //������Сλ�� 12
    float max_position[3]; 	//�������λ��12
   u8   motor_direction[6];       //���ת������6
   float steps_per_mm[4];	//���ÿ��һ���׵Ĳ���16
   u16 max_feedrate[4];	//�����������ٶ�8
   float zz_offset;//Z��ƫ��4
   float zprobe_zoffset;//�Զ���ƽZ��ƫ��4
  u8    auto_leveling_flag;// 1

   char SN[16];
   char HV[6];
  u16 extrude_multiply;                                //���ϱ���
  u32 min_segment_steps;                           //�ƶ�����С����
  u32 min_segment_time;                           //��ӡ����СƵ��
  u8   endstop_level[6];	     //��λ�㹤����ƽ
  u8   endstop_status[6];    //��λ�㹤��ʹ��״̬
  float retract_acceleration;                      //�س���ٶ�
  float acceleration;					//���ٶ�
  u32 axis_steps_per_sqr_second[4];      //XYZE���ƶ�����
  u8 min_travel_feedrate;                            //�մ���С��ӡ�ٶ�
  u8 min_feedrate;	                          //��С��ӡ�ٶ�
  u8   home_position[3];	      //�����λʱ��λ��
  u16 home_speed[3];	      //�����λ���ٶ�
  float max_jerk;             //�趨Ĭ�ϵ������ٶ�Ϊ���ͻ���ٶ�
  float max_x_jerk;         //�趨Ĭ�ϵ������ٶ�Ϊ���ͻ���ٶ�x
  float max_y_jerk;         //�趨Ĭ�ϵ������ٶ�Ϊ���ͻ���ٶ�y
  float max_z_jerk;         //�趨Ĭ�ϵ������ٶ�Ϊ���ͻ���ٶ�z
  float max_e_jerk;         //�趨Ĭ�ϵ������ٶ�Ϊ���ͻ���ٶ�  e
   u16 max_acceleration[4];    //XYZE����ٶ�
  u8 pid_adjust_range;   //����PID���ڵķ�Χ
  matrix_3x3 plan_bed_level_matrix;
  u8 locate_mode;	//����ģʽ
  float Kp[HOTHEAD_NUMBER];					//PID���ڲ���P  20
  float Ki[HOTHEAD_NUMBER];					//PID���ڲ���i  20
  float Kd[HOTHEAD_NUMBER];					//PID���ڲ���d  20
  float targe_temperature[HOTHEAD_NUMBER];	//���ȶ�Ŀ���¶�20
  float min_temperature[HOTHEAD_NUMBER];	      //���ȶ���С�¶�20
  float max_temperature[HOTHEAD_NUMBER];	      //���ȶ�����¶�20
  u8 hotend_num;//����ͷ��Ŀ   1
  FunctionalState hotend_enable[HOTHEAD_NUMBER];	//���ȶ�ʹ�ܱ�־  5
  u8  temperature_sampling_period; //�¶Ȳɼ�����  1
  u8 unit;             //��λ
  u8 wifi_exist_flag;
}setting_t;//

typedef struct 
{
	u8 a;
}setting_s;

extern setting_t Setting;

void Get_Printer_User_Settings(void);
void Store_Memory(SettingMode mode);
void Restore_Defaults(SettingMode mode);
void Store_SerialNumber(void);
void Get_SerialNumber(void);
void Store_Hardware_Version(void);
void Get_Hardware_Version(void);
void Store_AutoLevele_Flag(u8 flag);
u8 Get_AutoLevele_Flag(void);
void Store_Filament_Dev_Flag(u8 flag);
u8 Get_Filament_Dev_Flag(void);
#endif
