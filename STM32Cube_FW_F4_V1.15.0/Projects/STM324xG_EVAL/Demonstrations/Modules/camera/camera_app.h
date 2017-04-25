/**
  ******************************************************************************
  * @file    camera_app.h
  * @author  MCD Application Team
  * @version V1.4.0
  * @date    17-February-2017   
  * @brief   Camera application header file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CAMERA_APP_H
#define __CAMERA_APP_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Exported constants --------------------------------------------------------*/
#define CAMERA_FRAME_BUFFER 0x64100000
#define CAMERA_CVRT_BUFFER  0x64109600

#define RGB_HEADER_SIZE      54
#define IMAGE_BUFFER_SIZE   (160*120*2)     /* Size of RGB16 image */
#define MAX_IMAGE_SIZE      (160*120*3)      /* Size of RGB24 image  */
#define IMAGE_COLUMN_SIZE   160
#define IMAGE_LINE_SIZE     120
   
/* Exported types ------------------------------------------------------------*/
typedef union
{
  uint32_t d32;
  struct
  {
    uint32_t brightness     : 3;
    uint32_t contrast       : 3;    
  }b;
} CameraSettingsTypeDef;

/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void    CAMERA_Init(void);
void    CAMERA_Suspend(void);
void    CAMERA_Resume(void);
void    CAMERA_Stop(void);
void    CAMERA_Set_ContrastBrightness(uint32_t contrast_Level, uint32_t brightness_level);
void    CAMERA_SelectEffect(uint32_t effect);
uint8_t CAMERA_SaveToFile(uint8_t *path);
uint8_t CAMERA_GetState(void);
#ifdef __cplusplus
}
#endif

#endif /*__CAMERA_APP_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
