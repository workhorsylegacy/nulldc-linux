#pragma once
#include "types.h"
#include "dc/sh4/intc.h"


void FASTCALL asic_RaiseInterrupt(HollyInterruptID inter);
void FASTCALL asic_CancelInterrupt(HollyInterruptID inter);

//Init/Res/Term for regs
void asic_reg_Init();
void asic_reg_Term();
void asic_reg_Reset(bool Manual);