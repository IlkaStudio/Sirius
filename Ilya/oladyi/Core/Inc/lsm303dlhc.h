#ifndef LSM303DLHC_H_
#define LSM303DLHC_H_
 
#include "stm32f4xx_hal.h"
#include <string.h>
//------------------------------------------------
#define ABS(x)         (x < 0) ? (-x) : x
//------------------------------------------------
#define LD_PORT GPIOE
#define LD3 GPIO_PIN_9 //RED1
#define LD4 GPIO_PIN_8 //BLUE1
#define LD5 GPIO_PIN_10 //ORANGE1
#define LD6 GPIO_PIN_15 //GREEN1
#define LD7 GPIO_PIN_11 //GREEN2
#define LD8 GPIO_PIN_14 //ORANGE2
#define LD9 GPIO_PIN_12 //BLUE2
#define LD10 GPIO_PIN_13 //RED2
//-------------------------------------------------
#define ACC_I2C_ADDRESS                      0x32
#define MAG_I2C_ADDRESS                      0x3C
//------------------------------------------------
//-------------------------------------------------
#define LSM303DLHC_CTRL_REG1_A               0x20  /* Control register 1 acceleration */
#define LSM303DLHC_CTRL_REG2_A               0x21  /* Control register 2 acceleration */
#define LSM303DLHC_CTRL_REG3_A               0x22  /* Control register 3 acceleration */
#define LSM303DLHC_CTRL_REG4_A               0x23  /* Control register 4 acceleration */
#define LSM303DLHC_CTRL_REG5_A               0x24  /* Control register 5 acceleration */
#define LSM303DLHC_CRA_REG_M                 0x00  /* Control register A magnetic field */
#define LSM303DLHC_CRB_REG_M                 0x01  /* Control register B magnetic field */
#define LSM303DLHC_MR_REG_M                  0x02  /* Control register MR magnetic field */
//------------------------------------------------
#define LD3_ON HAL_GPIO_WritePin(LD_PORT, LD3, GPIO_PIN_SET) //RED1
#define LD4_ON HAL_GPIO_WritePin(LD_PORT, LD4, GPIO_PIN_SET) //BLUE1
#define LD5_ON HAL_GPIO_WritePin(LD_PORT, LD5, GPIO_PIN_SET) //ORANGE1
#define LD6_ON HAL_GPIO_WritePin(LD_PORT, LD6, GPIO_PIN_SET) //GREEN1
#define LD7_ON HAL_GPIO_WritePin(LD_PORT, LD7, GPIO_PIN_SET) //GREEN2
#define LD8_ON HAL_GPIO_WritePin(LD_PORT, LD8, GPIO_PIN_SET) //ORANGE2
#define LD9_ON HAL_GPIO_WritePin(LD_PORT, LD9, GPIO_PIN_SET) //BLUE2
#define LD10_ON HAL_GPIO_WritePin(LD_PORT, LD10, GPIO_PIN_SET) //RED2
#define LD3_OFF HAL_GPIO_WritePin(LD_PORT, LD3, GPIO_PIN_RESET) //RED1
#define LD4_OFF HAL_GPIO_WritePin(LD_PORT, LD4, GPIO_PIN_RESET) //BLUE1
#define LD5_OFF HAL_GPIO_WritePin(LD_PORT, LD5, GPIO_PIN_RESET) //ORANGE1
#define LD6_OFF HAL_GPIO_WritePin(LD_PORT, LD6, GPIO_PIN_RESET) //GREEN1
#define LD7_OFF HAL_GPIO_WritePin(LD_PORT, LD7, GPIO_PIN_RESET) //GREEN2
#define LD8_OFF HAL_GPIO_WritePin(LD_PORT, LD8, GPIO_PIN_RESET) //ORANGE2
#define LD9_OFF HAL_GPIO_WritePin(LD_PORT, LD9, GPIO_PIN_RESET) //BLUE2
#define LD10_OFF HAL_GPIO_WritePin(LD_PORT, LD10, GPIO_PIN_RESET) //RED2
//------------------------------------------------
#define LSM303DLHC_NORMAL_MODE            ((uint8_t)0x00)
#define LSM303DLHC_LOWPOWER_MODE          ((uint8_t)0x08)
//-------------------------------------------------
#define LSM303DLHC_ODR_1_HZ                ((uint8_t)0x10)  /*!< Output Data Rate = 1 Hz */
#define LSM303DLHC_ODR_10_HZ               ((uint8_t)0x20)  /*!< Output Data Rate = 10 Hz */
#define LSM303DLHC_ODR_25_HZ               ((uint8_t)0x30)  /*!< Output Data Rate = 25 Hz */
#define LSM303DLHC_ODR_50_HZ               ((uint8_t)0x40)  /*!< Output Data Rate = 50 Hz */
#define LSM303DLHC_ODR_100_HZ              ((uint8_t)0x50)  /*!< Output Data Rate = 100 Hz */
#define LSM303DLHC_ODR_200_HZ              ((uint8_t)0x60)  /*!< Output Data Rate = 200 Hz */
#define LSM303DLHC_ODR_400_HZ              ((uint8_t)0x70)  /*!< Output Data Rate = 400 Hz */
#define LSM303DLHC_ODR_1620_HZ_LP          ((uint8_t)0x80)  /*!< Output Data Rate = 1620 Hz only in Low Power Mode */
#define LSM303DLHC_ODR_1344_HZ             ((uint8_t)0x90)  /*!< Output Data Rate = 1344 Hz in Normal mode and 5376 Hz*/
//-------------------------------------------------
#define LSM303DLHC_X_ENABLE                ((uint8_t)0x01)
#define LSM303DLHC_Y_ENABLE                ((uint8_t)0x02)
#define LSM303DLHC_Z_ENABLE                ((uint8_t)0x04)
#define LSM303DLHC_AXES_ENABLE             ((uint8_t)0x07)
#define LSM303DLHC_AXES_DISABLE            ((uint8_t)0x00)
//-------------------------------------------------
#define LSM303DLHC_HR_ENABLE               ((uint8_t)0x08)
#define LSM303DLHC_HR_DISABLE              ((uint8_t)0x00)
//-------------------------------------------------
#define LSM303DLHC_FULLSCALE_2G            ((uint8_t)0x00)  /*!< �2 g */
#define LSM303DLHC_FULLSCALE_4G            ((uint8_t)0x10)  /*!< �4 g */
#define LSM303DLHC_FULLSCALE_8G            ((uint8_t)0x20)  /*!< �8 g */
#define LSM303DLHC_FULLSCALE_16G           ((uint8_t)0x30)  /*!< �16 g */
//-------------------------------------------------
#define LSM303DLHC_BlockUpdate_Continous   ((uint8_t)0x00) /*!< Continuos Update */
#define LSM303DLHC_BlockUpdate_Single      ((uint8_t)0x80) /*!< Single Update: output registers not updated until MSB and LSB reading */
//-------------------------------------------------
#define LSM303DLHC_BLE_LSB                 ((uint8_t)0x00) /*!< Little Endian: data LSB @ lower address */
#define LSM303DLHC_BLE_MSB                 ((uint8_t)0x40) /*!< Big Endian: data MSB @ lower address */
//-------------------------------------------------
#define LSM303DLHC_HPM_NORMAL_MODE_RES     ((uint8_t)0x00)
#define LSM303DLHC_HPM_REF_SIGNAL          ((uint8_t)0x40)
#define LSM303DLHC_HPM_NORMAL_MODE         ((uint8_t)0x80)
#define LSM303DLHC_HPM_AUTORESET_INT       ((uint8_t)0xC0)
//-------------------------------------------------
#define LSM303DLHC_HPFCF_8                 ((uint8_t)0x00)
#define LSM303DLHC_HPFCF_16                ((uint8_t)0x10)
#define LSM303DLHC_HPFCF_32                ((uint8_t)0x20)
#define LSM303DLHC_HPFCF_64                ((uint8_t)0x30)
//-------------------------------------------------
#define LSM303DLHC_HPF_AOI1_DISABLE        ((uint8_t)0x00)
#define LSM303DLHC_HPF_AOI1_ENABLE              ((uint8_t)0x01)
//-------------------------------------------------
#define LSM303DLHC_HPF_AOI2_DISABLE        ((uint8_t)0x00)
#define LSM303DLHC_HPF_AOI2_ENABLE         ((uint8_t)0x02)
//-------------------------------------------------
#define LSM303DLHC_ACC_SENSITIVITY_2G     ((uint8_t)1)  /*!< accelerometer sensitivity with 2 g full scale [mg/LSB] */
#define LSM303DLHC_ACC_SENSITIVITY_4G     ((uint8_t)2)  /*!< accelerometer sensitivity with 4 g full scale [mg/LSB] */
#define LSM303DLHC_ACC_SENSITIVITY_8G     ((uint8_t)4)  /*!< accelerometer sensitivity with 8 g full scale [mg/LSB] */
#define LSM303DLHC_ACC_SENSITIVITY_16G    ((uint8_t)12) /*!< accelerometer sensitivity with 12 g full scale [mg/LSB] */
//------------------------------------------------
#define LSM303DLHC_OUT_X_L_A                 0x28  /* Output Register X acceleration */
#define LSM303DLHC_OUT_X_H_A                 0x29  /* Output Register X acceleration */
#define LSM303DLHC_OUT_Y_L_A                 0x2A  /* Output Register Y acceleration */
#define LSM303DLHC_OUT_Y_H_A                 0x2B  /* Output Register Y acceleration */
#define LSM303DLHC_OUT_Z_L_A                 0x2C  /* Output Register Z acceleration */
#define LSM303DLHC_OUT_Z_H_A                 0x2D  /* Output Register Z acceleration */
//------------------------------------------------
#define LSM303DLHC_OUT_X_H_M                 0x03  /* Output Register X magnetic field */
#define LSM303DLHC_OUT_X_L_M                 0x04  /* Output Register X magnetic field */
#define LSM303DLHC_OUT_Z_H_M                 0x05  /* Output Register Z magnetic field */
#define LSM303DLHC_OUT_Z_L_M                 0x06  /* Output Register Z magnetic field */ 
#define LSM303DLHC_OUT_Y_H_M                 0x07  /* Output Register Y magnetic field */
#define LSM303DLHC_OUT_Y_L_M                 0x08  /* Output Register Y magnetic field */
//------------------------------------------------
#define LSM303DLHC_TEMPSENSOR_ENABLE         ((uint8_t) 0x80)   /*!< Temp sensor Enable */
#define LSM303DLHC_TEMPSENSOR_DISABLE        ((uint8_t) 0x00)   /*!< Temp sensor Disable */
//------------------------------------------------
#define LSM303DLHC_ODR_0_75_HZ              ((uint8_t) 0x00)  /*!< Output Data Rate = 0.75 Hz */
#define LSM303DLHC_ODR_1_5_HZ               ((uint8_t) 0x04)  /*!< Output Data Rate = 1.5 Hz */
#define LSM303DLHC_ODR_3_0_HZ               ((uint8_t) 0x08)  /*!< Output Data Rate = 3 Hz */
#define LSM303DLHC_ODR_7_5_HZ               ((uint8_t) 0x0C)  /*!< Output Data Rate = 7.5 Hz */
#define LSM303DLHC_ODR_15_HZ                ((uint8_t) 0x10)  /*!< Output Data Rate = 15 Hz */
#define LSM303DLHC_ODR_30_HZ                ((uint8_t) 0x14)  /*!< Output Data Rate = 30 Hz */
#define LSM303DLHC_ODR_75_HZ                ((uint8_t) 0x18)  /*!< Output Data Rate = 75 Hz */
#define LSM303DLHC_ODR_220_HZ               ((uint8_t) 0x1C)  /*!< Output Data Rate = 220 Hz */
//------------------------------------------------
#define  LSM303DLHC_FS_1_3_GA               ((uint8_t) 0x20)  /*!< Full scale = �1.3 Gauss */
#define  LSM303DLHC_FS_1_9_GA               ((uint8_t) 0x40)  /*!< Full scale = �1.9 Gauss */
#define  LSM303DLHC_FS_2_5_GA               ((uint8_t) 0x60)  /*!< Full scale = �2.5 Gauss */
#define  LSM303DLHC_FS_4_0_GA               ((uint8_t) 0x80)  /*!< Full scale = �4.0 Gauss */
#define  LSM303DLHC_FS_4_7_GA               ((uint8_t) 0xA0)  /*!< Full scale = �4.7 Gauss */
#define  LSM303DLHC_FS_5_6_GA               ((uint8_t) 0xC0)  /*!< Full scale = �5.6 Gauss */
#define  LSM303DLHC_FS_8_1_GA               ((uint8_t) 0xE0)  /*!< Full scale = �8.1 Gauss */
//------------------------------------------------
#define LSM303DLHC_CONTINUOS_CONVERSION      ((uint8_t) 0x00)   /*!< Continuous-Conversion Mode */
#define LSM303DLHC_SINGLE_CONVERSION         ((uint8_t) 0x01)   /*!< Single-Conversion Mode */
#define LSM303DLHC_SLEEP                     ((uint8_t) 0x02)   /*!< Sleep Mode */                       
//------------------------------------------------
void AccelMag_Ini(void);
void AccelMag_Read(void);
//------------------------------------------------
#endif /* LSM303DLHC_H_ */
