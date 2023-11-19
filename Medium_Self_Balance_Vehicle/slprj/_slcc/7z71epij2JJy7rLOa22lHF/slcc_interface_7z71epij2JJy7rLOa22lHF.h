#include "customcode_7z71epij2JJy7rLOa22lHF.h"
#ifdef __cplusplus
extern "C" {
#endif


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC extern void get_fac_us_addr_7z71epij2JJy7rLOa22lHF(uint8_T **varAddr);
DLL_EXPORT_CC extern void get_fac_ms_addr_7z71epij2JJy7rLOa22lHF(uint16_T **varAddr);
DLL_EXPORT_CC extern const char_T *get_dll_checksum_7z71epij2JJy7rLOa22lHF(void);
DLL_EXPORT_CC extern void delay_init_7z71epij2JJy7rLOa22lHF(void);
DLL_EXPORT_CC extern void delay_us_7z71epij2JJy7rLOa22lHF(uint32_T nus);
DLL_EXPORT_CC extern void delay_ms_7z71epij2JJy7rLOa22lHF(uint16_T nms);
DLL_EXPORT_CC extern void IIC_Init_7z71epij2JJy7rLOa22lHF(void);
DLL_EXPORT_CC extern void MPU6050_initialize_7z71epij2JJy7rLOa22lHF(void);
DLL_EXPORT_CC extern void DMP_Init_7z71epij2JJy7rLOa22lHF(void);
DLL_EXPORT_CC extern void Read_DMP_7z71epij2JJy7rLOa22lHF(void);
DLL_EXPORT_CC extern void MPU6050ReadDATA_7z71epij2JJy7rLOa22lHF(real32_T *accel, real32_T Tempera, real32_T *gyro);
DLL_EXPORT_CC extern void Kalman_Filter_7z71epij2JJy7rLOa22lHF(real32_T Accel, real32_T Gyro, real32_T angle);

/* Function Definitions */
DLL_EXPORT_CC const uint8_T *get_checksum_source_info(int32_T *size);
#ifdef __cplusplus
}
#endif

