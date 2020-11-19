/**
 * Copyright (C), 2020, Jason Hu, www.book-os.org
 * File name: mclang.h
 * Description:
 *      This is a programming language based on the C language macro.
 *  Based on the C language, the macro function is used to redefine
 *  some keywords and syntax. This is not like the interpreter, 
 *  it will be expanded into C language code during the C macro 
 *  expansion stage, and then compiled into assembly and machine code,
 *  so its execution efficiency is the same as C language. In other words,
 *  just changed the C language, it still looks very cool!
 * 
 * Change Logs:
 *  | Date          | Author        | Notes             | Version
 *  | 2020-05-23    | Jason Hu      | First Release     | 0.1
 *  | 2020-05-30    | Jason Hu      | Masonry           | 0.2
 *  | 2020-06-1     | Jason Hu      | Masonry           | 0.3
 *  | 2020-10-20    | Jason Hu      | Cola              | 0.4
 */
#ifndef __MARCO_C_LANG_H__
#define __MARCO_C_LANG_H__

#define __MARCO_C_LANG_VERSION__    0x04    /* v0.4 */

/* keywords */
#define when                if(                 
#define elif                }else if(           
#define other               }else{              
#define then                ){                  
#define loop                while(              
#define and                 &&                  
#define or                  ||                  
#define not                 !                   
#define cycle               do{                 
#define until               }while(             
#define begin               {                   
#define end                 }                      
#define enddata             };                
#define endcycle            );                  

#define match               switch(

#ifdef _Bool
#define boll                _Bool
#define true                true
#define false               false
#else
#define bool                char
#define true                1
#define false               0
#endif
#define out

#define forcond             for(
#define branch(x)           case x:
#define nomatch             default:
#define skip                break;
#define rep                 continue;

#define u8      unsigned char
#define u16     unsigned short
#define u32     unsigned int
#define u64     unsigned long int
#define s8      char
#define s16     short
#define s32     int
#define s64     long int
#define f32     float
#define f64     double
#define f128    long double

/* declare a function */
#define decl(_func, _ret, ...) \
        _ret _func (__VA_ARGS__);

/* define a function */
#define def(_func, _ret, ...) \
        _ret _func (__VA_ARGS__) 

/* call a function */
#define func(_func, ...) \
        _func(__VA_ARGS__);

/* get each item in array */
#define foreach(_item, _idx, _array) \
        for(_item = _array[0];\
        _idx < (sizeof(_array) / sizeof(_array[0]));\
        ++_idx, _item = _array[_idx]

/* get each index in a number */
#define forindex(_item, _num, _step) \
        for(_item = 0;\
        _item < _num;\
        _item += _step

/* ternary operation */
#define ternary(_cond, _x, _y) \
        _cond ? _x : _y

#define list(_name)                 enum _name
#define group(_name)                struct _name

#define lable(_name)                _name:
#define jmp(_name)                  goto _name;

#define var(_name, _type)           _type _name;
#define varset(_name, _type, _val)  _type _name = _val;
#define varmult(_name, _type) _type _name = 

#define eva(_val, _state)           _val = _state;
#define reva(_state, _val)          _val = _state;
#define arg(_name, _type)           _type _name

#define evainc(_val)                _val++;
#define evadec(_val)                _val--;

#define revainc(_val)               ++_val;
#define revadec(_val)               --_val;

#define inc(_val)                   _val++
#define dec(_val)                   _val--
#define rinc(_val)                  ++_val
#define rdec(_val)                  ++_val

#define LEN_ARRAY(_array)           (sizeof(_array) / sizeof(_array[0]))

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

#endif  /* __MARCO_C_LANG_H__ */