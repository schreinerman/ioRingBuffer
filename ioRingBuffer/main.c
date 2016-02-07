//
//  main.c
//  ioRingBuffer
//
//  Created by Manuel Schreiner on 07.02.16.
//  Copyright © 2016 io-expert.com. All rights reserved.
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this condition and the following disclaimer.
//
// This software is provided by the copyright holder and contributors "AS IS"
// and any warranties related to this software are DISCLAIMED.
// The copyright owner or contributors be NOT LIABLE for any damages caused
// by use of this software.

#include <stdio.h>
#include "ioringbuffer.h"
uint8_t au8Buffer[512];
stc_ioringbuffer_t stcRingBuffer = {&au8Buffer[0],sizeof(au8Buffer)};

uint8_t au8Tmp[15];
uint32_t u32DataRead;

int main(int argc, const char * argv[]) {
    int i;
    memset(&au8Tmp[0],0,sizeof(au8Tmp));
    IoRingBuffer_Init(&stcRingBuffer);
    IoRingBuffer_Add(&stcRingBuffer, (uint8_t*)"Hello, World!\n", 14,NULL );
    IoRingBuffer_Add(&stcRingBuffer, (uint8_t*)"Hello, World2\n", 14,NULL );
    IoRingBuffer_Add(&stcRingBuffer, (uint8_t*)"Hello, World3\n", 14,NULL );
    
    for(i = 0;i < 10;i++)
    {
        memset(&au8Tmp[0],0,sizeof(au8Tmp));
        IoRingBuffer_Read(&stcRingBuffer, &au8Tmp[0], 14, &u32DataRead, NULL);
        printf((char_t*)&au8Tmp[0]);
    }

    return 0;
}
