/*
 * Copyright (c) 2014 The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file was originally distributed by Qualcomm Atheros, Inc.
 * under proprietary terms before Copyright ownership was assigned
 * to the Linux Foundation.
 */

/******************************************************************************
*
* Name:  nan_Api.h
*
* Description: NAN FSM defines.
*
******************************************************************************/

#ifndef __NAN_API_H__
#define __NAN_API_H__

#include "vos_types.h"
#include "halTypes.h"

typedef struct sNanRequestReq {
	tANI_U16 request_data_len;
	tANI_U8* request_data;
} tNanRequestReq, *tpNanRequestReq;

/******************************************************************************
 * Function: Pointer NanCallback
 *
 * Description:
 * this function pointer is used hold nan response callback. When ever we
 * receive nan response, we will use this callback.
 *
 * Args:
 * first argument to pass hHal pointer and second argument
 * to pass the nan response data.
 *
 * Returns:
 * void
******************************************************************************/
typedef void (*NanCallback)(void*, tSirNanEvent*);

/******************************************************************************
 * Function: sme_NanRegisterCallback
 *
 * Description:
 * This function gets called when HDD wants register nan rsp callback with
 * sme layer.
 *
 * Args:
 * hHal and callback which needs to be registered.
 *
 * Returns:
 * void
******************************************************************************/
void sme_NanRegisterCallback(tHalHandle hHal, NanCallback callback);

/******************************************************************************
 * Function: sme_NanRequest
 *
 * Description:
 * This function gets called when HDD receives NAN vendor command
 * from userspace
 *
 * Args:
 * Nan Request structure ptr
 *
 * Returns:
 * VOS_STATUS
******************************************************************************/
VOS_STATUS sme_NanRequest(tpNanRequestReq input);


#endif /* __NAN_API_H__ */
