#include "customcode_0TWQQ1wfypZRJ8lXW0NTh.h"
#ifdef __cplusplus
extern "C" {
#endif


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC extern void get_fac_us_addr_0TWQQ1wfypZRJ8lXW0NTh(uint8_T **varAddr);
DLL_EXPORT_CC extern void get_fac_ms_addr_0TWQQ1wfypZRJ8lXW0NTh(uint16_T **varAddr);
DLL_EXPORT_CC extern const char_T *get_dll_checksum_0TWQQ1wfypZRJ8lXW0NTh(void);
DLL_EXPORT_CC extern void delay_init_0TWQQ1wfypZRJ8lXW0NTh(void);
DLL_EXPORT_CC extern void delay_us_0TWQQ1wfypZRJ8lXW0NTh(uint32_T nus);
DLL_EXPORT_CC extern void delay_ms_0TWQQ1wfypZRJ8lXW0NTh(uint16_T nms);
DLL_EXPORT_CC extern void IIC_Init_0TWQQ1wfypZRJ8lXW0NTh(void);
DLL_EXPORT_CC extern void MPU6050_initialize_0TWQQ1wfypZRJ8lXW0NTh(void);
DLL_EXPORT_CC extern void DMP_Init_0TWQQ1wfypZRJ8lXW0NTh(void);
DLL_EXPORT_CC extern void Read_DMP_0TWQQ1wfypZRJ8lXW0NTh(void);
DLL_EXPORT_CC extern void MPU6050ReadDATA_0TWQQ1wfypZRJ8lXW0NTh(real32_T accel[], real32_T Tempera, real32_T gyro[]);
DLL_EXPORT_CC extern void Kalman_Filter_0TWQQ1wfypZRJ8lXW0NTh(real32_T Accel, real32_T Gyro, real32_T angle);

/* Function Definitions */
DLL_EXPORT_CC const uint8_T *get_checksum_source_info(int32_T *size);
#ifdef __cplusplus
}
#endif

