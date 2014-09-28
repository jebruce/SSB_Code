
/* File generated by gen_cfile.py. Should not be modified. */

#ifndef SENSOR_OBJDICT_H
#define SENSOR_OBJDICT_H

#include "../libs/dspic_CanFestival/CanFestival-3/include/data.h"

/* Prototypes of function provided by object dictionnary */
UNS32 Sensor_Board_valueRangeTest (UNS8 typeValue, void * value);
const indextable * Sensor_Board_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks);

/* Master node data struct */
extern CO_Data Sensor_Board_Data;
extern UNS32 Strain_Gauge1;		/* Mapped at index 0x2001, subindex 0x00*/
extern UNS32 Strain_Gauge2;		/* Mapped at index 0x2002, subindex 0x00*/
extern UNS32 Strain_Gauge3;		/* Mapped at index 0x2003, subindex 0x00*/
extern UNS32 Strain_Gauge4;		/* Mapped at index 0x2004, subindex 0x00*/
extern UNS32 Target_Tension;		/* Mapped at index 0x3000, subindex 0x00*/
extern REAL32 Actual_Position;		/* Mapped at index 0x3001, subindex 0x00*/
extern REAL32 Actual_Velocity;		/* Mapped at index 0x3002, subindex 0x00*/
extern UNS8 Voltage_24V;		/* Mapped at index 0x4000, subindex 0x00*/
extern INTEGER32 Position_actual_value;		/* Mapped at index 0x6064, subindex 0x00*/
extern INTEGER32 Velocity_actual_value;		/* Mapped at index 0x606C, subindex 0x00*/
extern INTEGER16 Current_actual_value;		/* Mapped at index 0x6078, subindex 0x00*/
extern INTEGER32 Target_position;		/* Mapped at index 0x607A, subindex 0x00*/
extern INTEGER32 Target_velocity;		/* Mapped at index 0x60FF, subindex 0x00*/
extern UNS16 Motor_data_Continous_current_limit;		/* Mapped at index 0x6410, subindex 0x01 */
extern UNS16 Motor_data_Output_current_limit;		/* Mapped at index 0x6410, subindex 0x02 */
extern UNS8 Motor_data_Pole_pair_number;		/* Mapped at index 0x6410, subindex 0x03 */
extern UNS16 Motor_data_Maximal_speed_in_current_mode;		/* Mapped at index 0x6410, subindex 0x04 */
extern UNS16 Motor_data_Thermal_time_constant_winding;		/* Mapped at index 0x6410, subindex 0x05 */
extern UNS32 Supported_drive_modes;		/* Mapped at index 0x6502, subindex 0x00*/

#endif // SENSOR_OBJDICT_H
