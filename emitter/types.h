#pragma once

#include "../common/portable.h"


//Do not complain when i use enum::member
#pragma warning( disable : 4482)

//unnamed struncts/unions
#pragma warning( disable : 4201)

//unused parameters
#pragma warning( disable : 4100)

//basic includes from runtime lib
#include <stdlib.h>
#include <stdio.h>

#include <vector>
using namespace std;

#ifndef dbgbreak
#define dbgbreak __asm {int 3}
#endif

#ifndef verify
#define verify(x) if((x)==false){ printf("Verify Failed  : " #x "\n in %s -> %s : %d \n",__FUNCTION__,__FILE__,__LINE__); dbgbreak;}
#endif

#ifndef die
#define die(reason) { printf("Fatal error : %s\n in %s -> %s : %d \n",reason,__FUNCTION__,__FILE__,__LINE__); dbgbreak;}
#endif