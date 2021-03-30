#ifndef _MARCO_C_H
#define _MARCO_C_H

/* For the full documentation and explanation of the code below, please refer to
 * https://github.com/GorgonMeducer/PLOOC/blob/master/plooc.h
 */
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__cplusplus)
/*! \brief You can use __PLOOC_EVAL() to dynamically select the right API which
 *!        has the right number of parameters (no more than 8).
 */
//! @{
#define __PLOOC_VA_NUM_ARGS_IMPL(   _0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,  \
                                    _13,_14,_15,_16,__N,...)      __N
#define __PLOOC_VA_NUM_ARGS(...)                                                \
            __PLOOC_VA_NUM_ARGS_IMPL( 0,##__VA_ARGS__,16,15,14,13,12,11,10,9,   \
                                      8,7,6,5,4,3,2,1,0)

#define __16_PLOOC_EVAL(__FUNC, __NO_ARGS)  __FUNC##__NO_ARGS
#define __15_PLOOC_EVAL(__FUNC, __NO_ARGS)  __16_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __14_PLOOC_EVAL(__FUNC, __NO_ARGS)  __16_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __13_PLOOC_EVAL(__FUNC, __NO_ARGS)  __14_PLOOC_EVAL(__FUNC, __NO_ARGS)

#define __12_PLOOC_EVAL(__FUNC, __NO_ARGS)  __13_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __11_PLOOC_EVAL(__FUNC, __NO_ARGS)  __12_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __10_PLOOC_EVAL(__FUNC, __NO_ARGS)  __11_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __9_PLOOC_EVAL(__FUNC, __NO_ARGS)   __10_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __8_PLOOC_EVAL(__FUNC, __NO_ARGS)   __9_PLOOC_EVAL(__FUNC, __NO_ARGS)

#define __7_PLOOC_EVAL(__FUNC, __NO_ARGS)   __8_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __6_PLOOC_EVAL(__FUNC, __NO_ARGS)   __7_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __5_PLOOC_EVAL(__FUNC, __NO_ARGS)   __6_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __4_PLOOC_EVAL(__FUNC, __NO_ARGS)   __5_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __3_PLOOC_EVAL(__FUNC, __NO_ARGS)   __4_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __2_PLOOC_EVAL(__FUNC, __NO_ARGS)   __3_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __1_PLOOC_EVAL(__FUNC, __NO_ARGS)   __2_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __0_PLOOC_EVAL(__FUNC, __NO_ARGS)   __1_PLOOC_EVAL(__FUNC, __NO_ARGS)

#define __PLOOC_EVAL(__FUNC, ...)           __0_PLOOC_EVAL(                     \
                                                __FUNC,                         \
                                                __PLOOC_VA_NUM_ARGS(__VA_ARGS__))
//! @}   
#endif

#define _USE_EXCEPTION
#ifdef _USE_EXCEPTION
/* try catch */
#include <setjmp.h>
/* For the full documentation and explanation of the code below, please refer to
 * http://www.di.unipi.it/~nids/docs/longjump_try_trow_catch.html
 */
#define try         do { jmp_buf ex_buf__; switch( setjmp(ex_buf__) ) { case 0: while(1) { {
#define catch(_x)   } break; case _x: {
#define finally     } break; } default: { {
#define endtry      } break; } } }while(0);
#define throw(_x)   longjmp(ex_buf__, _x);
#endif /* _USE_EXCEPTION */

#define _USE_COROUTINE
#ifdef _USE_COROUTINE

/* For the full documentation and explanation of the code below, please refer to
 * https://www.chiark.greenend.org.uk/~sgtatham/coroutine.h
 */

#define begincoro      static int _coro_line = 0; switch(_coro_line) { case 0:;;
#define endcoro(z)     } return (z);
#define endcorono      } return;

#define yeild(z)     \
        do {\
            _coro_line=__LINE__;\
            return (z); case __LINE__:;\
        } while (0);
#define yeildno       \
        do {\
            _coro_line=__LINE__;\
            return; case __LINE__:;\
        } while (0);

#endif /* _USE_COROUTINE */

#endif  /* _MARCO_C_H */