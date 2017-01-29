/*
 BME280.h - Header file for the BME280 Barometric Pressure Sensor Arduino Library.
 Copyright (C) 2012 Love Electronics Ltd (loveelectronics.com)

 This program is free software: you can redistribute it and/or modify
 it under the terms of the version 3 GNU General Public License as
 published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 Datasheet for BME280:
 http://www.bosch-sensortec.com/content/language1/downloads/BST-BMP180-DS000-07.pdf

 */

#ifndef _GRIDEYE_H_
#define _GRIDEYE_H_

#include <inttypes.h>

#include "../../SmingCore/Wire.h"
#include "Arduino.h"

//*****************************************************************************
//
//! \addtogroup GRID_EYE_API_Sample Sample API
//! \brief The Sample API Reference for grid eye sensor
//! @{
//
//*****************************************************************************

class grideye
{
public:
	grideye();
	uint8_t address;
	uint8_t init(uint8_t grideye_address);

	/*Secondary Functions*/
	bool bAMG_PUB_I2C_Read(uint8_t ucRegAddr, uint8_t ucSize,
			uint8_t* ucDstAddr);
};

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

#ifdef __cplusplus
extern "C"
{
#endif

#include "grid_eye_config.h"
#include "Hw_grid_eye.h"

#define  DataPin                       5     // the number of the Tx pin

//*****************************************************************************
//
//! \addtogroup GRID_EYE_API_Layered Layered API
//! \brief The Layered API Reference for grid eye sensor
//! @{
//
//*****************************************************************************
//*****************************************************************************
//
//! \addtogroup GRID_EYE_API_LV1 Sensor API
//! \brief The LV1 API Reference for grid eye sensor
//! @{
//
//*****************************************************************************
BOOL bAMG_PUB_I2C_Read(UCHAR, UCHAR, UCHAR, UCHAR*);
short shAMG_PUB_TMP_ConvThermistor(UCHAR[2]);
short shAMG_PUB_TMP_ConvTemperature(UCHAR[2]);
void vAMG_PUB_TMP_ConvTemperature64(UCHAR*, short*);
short shAMG_PUB_CMN_ConvFtoS(float);
float fAMG_PUB_CMN_ConvStoF(short);

//*****************************************************************************
//
//! @}
//
//*****************************************************************************
//*****************************************************************************
//
//! \addtogroup GRID_EYE_API_LV2 Image Processing API
//! \brief The LV2 API Reference for grid eye sensor
//! @{
//
//*****************************************************************************
short shAMG_PUB_CMN_CalcAve(short*, USHORT, UCHAR, UCHAR, BOOL*);
short shAMG_PUB_CMN_CalcIIR(short, short, short);
short shAMG_PUB_CMN_CalcIIR_f(short, short, float);

void vAMG_PUB_IMG_ConvertFlipX(UCHAR, UCHAR, short*, short*);
void vAMG_PUB_IMG_ConvertFlipY(UCHAR, UCHAR, short*, short*);
BOOL bAMG_PUB_IMG_ConvertFlipXY(UCHAR, UCHAR, short*, short*);
BOOL bAMG_PUB_IMG_ConvertRotate90(UCHAR, UCHAR, short*, short*);
void vAMG_PUB_IMG_ConvertRotate180(UCHAR, UCHAR, short*, short*);
BOOL bAMG_PUB_IMG_ConvertRotate270(UCHAR, UCHAR, short*, short*);

BOOL bAMG_PUB_IMG_LinearInterpolationSQ15(short*, short*);
BOOL bAMG_PUB_IMG_LinearInterpolation(UCHAR, UCHAR, short*, short*);

BOOL bAMG_PUB_IMG_ImageDilation1(UCHAR, UCHAR, UCHAR*, UCHAR*);
BOOL bAMG_PUB_IMG_ImageDilation2(UCHAR, UCHAR, UCHAR, UCHAR*, UCHAR*);

void vAMG_PUB_ODT_CalcDiffImage(USHORT, short*, short*, short*);
void vAMG_PUB_ODT_CalcDetectImage1(USHORT, short*, short, UCHAR, UCHAR*);
void vAMG_PUB_ODT_CalcDetectImage2(USHORT, short*, short*, UCHAR, UCHAR*);

UCHAR ucAMG_PUB_ODT_CalcDataLabeling8(UCHAR, UCHAR, UCHAR, USHORT, UCHAR*,
		USHORT*);

BOOL bAMG_PUB_FEA_CalcArea(USHORT, UCHAR, UCHAR*, USHORT*);
BOOL bAMG_PUB_FEA_CalcRectangle(UCHAR, UCHAR, UCHAR, UCHAR*, UCHAR*);
BOOL bAMG_PUB_FEA_CalcMinTemp(USHORT, UCHAR, UCHAR*, short*, short*);
BOOL bAMG_PUB_FEA_CalcMaxTemp(USHORT, UCHAR, UCHAR*, short*, short*);
BOOL bAMG_PUB_FEA_CalcAveTemp(USHORT, UCHAR, UCHAR*, short*, short*);
BOOL bAMG_PUB_FEA_CalcStdDevTemp(USHORT, UCHAR, UCHAR*, short*, USHORT*);
BOOL bAMG_PUB_FEA_CalcStdDevTemp_f(USHORT, UCHAR, UCHAR*, short*, float*);
BOOL bAMG_PUB_FEA_CalcCenterTemp(UCHAR, UCHAR, UCHAR, UCHAR*, short*, short*);
BOOL bAMG_PUB_FEA_CalcCenterTemp_f(UCHAR, UCHAR, UCHAR, UCHAR*, short*, float*);

BOOL bAMG_PUB_BGT_UpdateBackTemp(USHORT, UCHAR*, short*, short, short*);

BOOL bAMG_PUB_HDT_JudgeHuman(USHORT, USHORT);

BOOL bAMG_PUB_OUT_CalcOutImage(UCHAR, UCHAR, UCHAR, UCHAR, short*, UCHAR*);
BOOL bAMG_PUB_OUT_CalcOutImage_f(UCHAR, UCHAR, UCHAR, UCHAR, float*, UCHAR*);

//*****************************************************************************
//
//! @}
//
//*****************************************************************************
//*****************************************************************************
//
//! \addtogroup GRID_EYE_API_LV3 Human detection API
//! \brief The LV3 API Reference for grid eye sensor
//! @{
//
//*****************************************************************************
BOOL bAMG_PUB_ODT_Initialize(UCHAR, UCHAR, ULONG, USHORT);
BOOL bAMG_PUB_ODT_SetPrm(UCHAR, UCHAR);
BOOL bAMG_PUB_ODT_Execute(short*, short*, short*, UCHAR*, UCHAR*, USHORT*);

BOOL bAMG_PUB_OTR_Initialize(UCHAR, UCHAR, UCHAR, UCHAR, UCHAR, ULONG, USHORT);
BOOL bAMG_PUB_OTR_SetPrm(UCHAR, short);
BOOL bAMG_PUB_OTR_Execute(short*, short*, short*, UCHAR, UCHAR*, USHORT*);
BOOL bAMG_PUB_OTR_GetResultByLabel(UCHAR, UCHAR, short*);
BOOL bAMG_PUB_OTR_GetOutput(UCHAR*, UCHAR*);
BOOL bAMG_PUB_BGT_SetPrm(UCHAR, short);
void vAMG_PUB_BGT_UpdateBackTemp(USHORT, UCHAR*, short*, short*);

//*****************************************************************************
//
//! @}
//
//*****************************************************************************
//*****************************************************************************
//
//! @}
//
//*****************************************************************************
//*****************************************************************************
//
//! @}
//
//*****************************************************************************
//*****************************************************************************
//
//! @}
//
//*****************************************************************************

#ifdef __cplusplus
}
#endif

#endif /* GRIDEYE_H_ */
