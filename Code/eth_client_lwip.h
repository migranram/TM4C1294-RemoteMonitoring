//*****************************************************************************
//
// eth_client.h - Prototypes for the driver for the eth_client.
//
// Copyright (c) 2013-2020 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.2.0.295 of the EK-TM4C1294XL Firmware Package.
//
//*****************************************************************************
#ifndef ETH_CLIENT_H_
#define ETH_CLIENT_H_

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Maximum size for the circular receive buffer.
//
//*****************************************************************************
#define SEND_BUFFER_SIZE                 4096


//*****************************************************************************
//
// The type definition for event functions.
//
//*****************************************************************************
typedef void (* tEventFunction)(uint32_t ui32Event, void* pvData,
                                uint32_t ui32Param);

//*****************************************************************************
//
// Exported Ethernet function prototypes.
//
//*****************************************************************************
extern void EthClientInit(uint32_t ui32SysClock, tEventFunction pfnEvent);
extern void EthClientTick(uint32_t ui32TickMS);
extern uint32_t EthClientAddrGet(void);
extern void EthClientMACAddrGet(uint8_t *pui8Addr);

extern int32_t EthClientTCPConnect(void);
extern void EthClientTCPDisconnect(void);
extern void EthClientProxySet(const char *pcProxyName, uint16_t ui16Port);
extern void EthClientHostSet(const char *pcHostName, uint16_t ui16Port);
extern int32_t EthClientDNSResolve(void);
extern uint32_t EthClientServerAddrGet(void);
extern int32_t EthClientSend(uint8_t *pi8Request, uint32_t ui32Size);


int debug;

#ifdef __cplusplus
}
#endif

#endif
