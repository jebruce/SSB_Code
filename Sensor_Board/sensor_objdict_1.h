
/* File generated by gen_cfile.py. Should not be modified. */

#ifndef SENSOR_OBJDICT_1_H
#define SENSOR_OBJDICT_1_H

#include "../libs/dspic_CanFestival/CanFestival-3/include/data.h"

/* Prototypes of function provided by object dictionnary */
UNS32 Sensor_Board_valueRangeTest (UNS8 typeValue, void * value);
const indextable * Sensor_Board_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks);

/* Master node data struct */
extern CO_Data Sensor_Board_Data;
extern INTEGER32 sensor1_strain_gauge_processed_Strain_Gauge_1P;		/* Mapped at index 0x2010, subindex 0x01 */
extern INTEGER32 sensor1_strain_gauge_processed_Strain_Gauge_2P;		/* Mapped at index 0x2010, subindex 0x02 */
extern INTEGER32 sensor1_strain_gauge_processed_Strain_Gauge_3P;		/* Mapped at index 0x2010, subindex 0x03 */
extern INTEGER32 sensor1_strain_gauge_processed_Strain_Gauge_4P;		/* Mapped at index 0x2010, subindex 0x04 */
extern INTEGER32 sensor1_strain_gauge_processed_Strain_Gauge_5P;		/* Mapped at index 0x2010, subindex 0x05 */
extern INTEGER32 sensor1_strain_gauge_processed_Strain_Gauge_6P;		/* Mapped at index 0x2010, subindex 0x06 */
extern INTEGER32 sensor1_strain_gauge_processed_Strain_Gauge_7P;		/* Mapped at index 0x2010, subindex 0x07 */
extern INTEGER32 sensor1_strain_gauge_processed_Strain_Gauge_8P;		/* Mapped at index 0x2010, subindex 0x08 */
extern INTEGER32 sensor1_strain_gauge_raw_Strain_Gauge_1R;		/* Mapped at index 0x2011, subindex 0x01 */
extern INTEGER32 sensor1_strain_gauge_raw_Strain_Gauge_2R;		/* Mapped at index 0x2011, subindex 0x02 */
extern INTEGER32 sensor1_strain_gauge_raw_Strain_Gauge_3R;		/* Mapped at index 0x2011, subindex 0x03 */
extern INTEGER32 sensor1_strain_gauge_raw_Strain_Gauge_4R;		/* Mapped at index 0x2011, subindex 0x04 */
extern INTEGER32 sensor1_strain_gauge_raw_Strain_Gauge_5R;		/* Mapped at index 0x2011, subindex 0x05 */
extern INTEGER32 sensor1_strain_gauge_raw_Strain_Gauge_6R;		/* Mapped at index 0x2011, subindex 0x06 */
extern INTEGER32 sensor1_strain_gauge_raw_Strain_Gauge_7R;		/* Mapped at index 0x2011, subindex 0x07 */
extern INTEGER32 sensor1_strain_gauge_raw_Strain_Gauge_8R;		/* Mapped at index 0x2011, subindex 0x08 */
extern REAL32 sensor1_ahrs_quaternion_Quaternion_ahrs_1;		/* Mapped at index 0x2012, subindex 0x01 */
extern REAL32 sensor1_ahrs_quaternion_Quaternion_ahrs_2;		/* Mapped at index 0x2012, subindex 0x02 */
extern REAL32 sensor1_ahrs_quaternion_Quaternion_ahrs_3;		/* Mapped at index 0x2012, subindex 0x03 */
extern REAL32 sensor1_ahrs_quaternion_Quaternion_ahrs_4;		/* Mapped at index 0x2012, subindex 0x04 */
extern REAL32 sensor1_imu_quaternion_Quaternion_imu_1;		/* Mapped at index 0x2013, subindex 0x01 */
extern REAL32 sensor1_imu_quaternion_Quaternion_imu_2;		/* Mapped at index 0x2013, subindex 0x02 */
extern REAL32 sensor1_imu_quaternion_Quaternion_imu_3;		/* Mapped at index 0x2013, subindex 0x03 */
extern REAL32 sensor1_imu_quaternion_Quaternion_imu_4;		/* Mapped at index 0x2013, subindex 0x04 */
extern REAL32 sensor1_accel_accel_x_norm;		/* Mapped at index 0x2014, subindex 0x01 */
extern REAL32 sensor1_accel_accel_y_norm;		/* Mapped at index 0x2014, subindex 0x02 */
extern REAL32 sensor1_accel_accel_z_norm;		/* Mapped at index 0x2014, subindex 0x03 */
extern INTEGER16 sensor1_accel_accel_x_raw;		/* Mapped at index 0x2014, subindex 0x04 */
extern INTEGER16 sensor1_accel_accel_y_raw;		/* Mapped at index 0x2014, subindex 0x05 */
extern INTEGER16 sensor1_accel_accel_z_raw;		/* Mapped at index 0x2014, subindex 0x06 */
extern REAL32 sensor1_gyro_gyro_x_norm;		/* Mapped at index 0x2015, subindex 0x01 */
extern REAL32 sensor1_gyro_gyro_y_norm;		/* Mapped at index 0x2015, subindex 0x02 */
extern REAL32 sensor1_gyro_gyro_z_norm;		/* Mapped at index 0x2015, subindex 0x03 */
extern INTEGER16 sensor1_gyro_gyro_x_raw;		/* Mapped at index 0x2015, subindex 0x04 */
extern INTEGER16 sensor1_gyro_gyro_y_raw;		/* Mapped at index 0x2015, subindex 0x05 */
extern INTEGER16 sensor1_gyro_gyro_z_raw;		/* Mapped at index 0x2015, subindex 0x06 */
extern REAL32 sensor1_mag_mag_x_norm;		/* Mapped at index 0x2016, subindex 0x01 */
extern REAL32 sensor1_mag_mag_y_norm;		/* Mapped at index 0x2016, subindex 0x02 */
extern REAL32 sensor1_mag_mag_z_norm;		/* Mapped at index 0x2016, subindex 0x03 */
extern INTEGER16 sensor1_mag_mag_x_raw;		/* Mapped at index 0x2016, subindex 0x04 */
extern INTEGER16 sensor1_mag_mag_y_raw;		/* Mapped at index 0x2016, subindex 0x05 */
extern INTEGER16 sensor1_mag_mag_z_raw;		/* Mapped at index 0x2016, subindex 0x06 */
extern UNS16 sensor1_ranging_distances_node_1;		/* Mapped at index 0x2017, subindex 0x01 */
extern UNS16 sensor1_ranging_distances_node_2;		/* Mapped at index 0x2017, subindex 0x02 */
extern UNS16 sensor1_ranging_distances_node_3;		/* Mapped at index 0x2017, subindex 0x03 */
extern UNS16 sensor1_ranging_distances_node_4;		/* Mapped at index 0x2017, subindex 0x04 */
extern UNS16 sensor1_ranging_distances_node_5;		/* Mapped at index 0x2017, subindex 0x05 */
extern UNS16 sensor1_ranging_distances_node_6;		/* Mapped at index 0x2017, subindex 0x06 */
extern UNS16 sensor1_ranging_distances_node_7;		/* Mapped at index 0x2017, subindex 0x07 */
extern UNS16 sensor1_ranging_distances_node_8;		/* Mapped at index 0x2017, subindex 0x08 */
extern UNS16 sensor1_ranging_distances_node_9;		/* Mapped at index 0x2017, subindex 0x09 */
extern UNS16 sensor1_ranging_distances_node_10;		/* Mapped at index 0x2017, subindex 0x0A */
extern UNS16 sensor1_ranging_distances_node_11;		/* Mapped at index 0x2017, subindex 0x0B */
extern UNS16 sensor1_ranging_distances_node_12;		/* Mapped at index 0x2017, subindex 0x0C */
extern UNS16 sensor1_ranging_distances_node_13;		/* Mapped at index 0x2017, subindex 0x0D */
extern UNS16 sensor1_ranging_distances_node_14;		/* Mapped at index 0x2017, subindex 0x0E */
extern UNS16 sensor1_ranging_distances_node_15;		/* Mapped at index 0x2017, subindex 0x0F */
extern UNS16 sensor1_ranging_distances_node_16;		/* Mapped at index 0x2017, subindex 0x10 */
extern UNS16 sensor1_ranging_distances_node_18;		/* Mapped at index 0x2017, subindex 0x11 */
extern UNS16 sensor1_ranging_distances_node_19;		/* Mapped at index 0x2017, subindex 0x12 */
extern UNS16 sensor1_ranging_distances_node_20;		/* Mapped at index 0x2017, subindex 0x13 */
extern UNS16 sensor1_ranging_distances_node_21;		/* Mapped at index 0x2017, subindex 0x14 */
extern REAL32 sensor1_ahrs_ypr_yaw;		/* Mapped at index 0x2018, subindex 0x01 */
extern REAL32 sensor1_ahrs_ypr_pitch;		/* Mapped at index 0x2018, subindex 0x02 */
extern REAL32 sensor1_ahrs_ypr_roll;		/* Mapped at index 0x2018, subindex 0x03 */
extern INTEGER32 motor2_position_control_Commanded_Position;		/* Mapped at index 0x2022, subindex 0x01 */
extern UNS16 motor2_position_control_P_Gain;		/* Mapped at index 0x2022, subindex 0x02 */
extern UNS16 motor2_position_control_I_Gain;		/* Mapped at index 0x2022, subindex 0x03 */
extern UNS16 motor2_position_control_D_Gain;		/* Mapped at index 0x2022, subindex 0x04 */
extern REAL32 motor2_position_control_SS_Gain_1st_Order;		/* Mapped at index 0x2022, subindex 0x05 */
extern REAL32 motor2_position_control_SS_Gain_2st_Order;		/* Mapped at index 0x2022, subindex 0x06 */
extern REAL32 motor2_position_control_SS_Gain_3st_Order;		/* Mapped at index 0x2022, subindex 0x07 */
extern REAL32 motor2_position_control_O_Gain_1st_Order;		/* Mapped at index 0x2022, subindex 0x08 */
extern REAL32 motor2_position_control_O_Gain_2st_Order;		/* Mapped at index 0x2022, subindex 0x09 */
extern REAL32 motor2_position_control_O_Gain_3st_Order;		/* Mapped at index 0x2022, subindex 0x0A */
extern INTEGER32 desired_motor_position_motor_2;		/* Mapped at index 0x2040, subindex 0x01 */
extern INTEGER32 desired_motor_position_motor_72;		/* Mapped at index 0x2040, subindex 0x02 */
extern UNS8 ranging_id;		/* Mapped at index 0x2041, subindex 0x00*/

#endif // SENSOR_OBJDICT_1_H
