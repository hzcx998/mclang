/**
 * Copyright (C), 2020, Jason Hu, www.book-os.org
 */
#ifndef _CBASIC_H
#define _CBASIC_H

#include "macro.h"

typedef char *      String;
typedef char        Byte;
typedef short       Integer;
typedef int         Long;
typedef long long   Longlong;
typedef float       Float;
typedef double      Double;
typedef char        Boolean;

#define True 1
#define False 0
#define Const const

#define If          if(
#define Then        ){
#define Else        }else{
#define ElseIf      }else if(
#define EndIf       }
#define Select(n)   switch(n){
#define Case(n)     case n:
#define CaseElse    default:
#define EndSelect   }
#define ExitCase    break;
#define DoWhile(cond)     while ((cond)) {
#define Loop        }
#define DoUntil(cond)     while (!(cond)) {
#define ExitDo      break;
#define ContinueDo  continue;
#define Do          do {
#define LoopWhile(cond)   } while(cond);
#define While(cond) while(cond) {
#define EndWhile    }

#define Goto(label) goto label;

#define Return(x)   return x;
#define Static      static
#define Private     static
#define Public

/*----Dim As ----*/
#define ByVal(__name, __type) \
        __type __name
#define ByRef(__name, __type) \
        __type* __name

#define __DimWithInit(__name, __type, __value) \
        __type __name = __value;
#define __DimOnly(__name, __type) \
        __type __name;
#define __DimPointer(__name, __type) \
        __type* __name;

#define __DimAs2  __DimOnly
#define __DimAs3  __DimWithInit

#define DimAs(__name, __type, ...)                       \
        __PLOOC_EVAL(__DimAs, __name, __type, ##__VA_ARGS__)(__name, __type, ##__VA_ARGS__)

/*----Const As ----*/
#define __ConstDimWithInit(__name, __type, __value) \
        const __type __name = __value;
#define __ConstDimOnly(__name, __type) \
        const __type __name;

#define __ConstDimAs2  __ConstDimOnly
#define __ConstDimAs3  __ConstDimWithInit

#define ConstAs(__name, __type, ...)                       \
        __PLOOC_EVAL(__ConstDimAs, __name, __type, ##__VA_ARGS__)(__name, __type, ##__VA_ARGS__)

/*----Mod ----*/
#define Mod(a, b) (a % b)


#define Sub(__func, ...) \
        void __func (__VA_ARGS__) {
#define EndSub  }

#define Function(__func, __ret, ...) \
        __ret __func (__VA_ARGS__) {
#define EndFunction  }

#define ConsoleWrite(fmt, ...) printf(fmt, ##__VA_ARGS__);
#define ConsoleWriteLine(fmt, ...) printf(fmt"\n", ##__VA_ARGS__);

#define Exp(exp)  exp;     

#endif /* _CBASIC_H */