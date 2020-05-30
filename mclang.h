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
 */
#ifndef __MARCO_C_LANG_H__
#define __MARCO_C_LANG_H__

#define __MARCO_C_LANG_VERSION__    0x02    /* v0.2 Masonry */

#if __MARCO_C_LANG_VERSION__ == 0x02    /* v0.2 */
/* keywords */
#define IF                  if(                 
#define ELIF                }else if(           
#define ELSE                }else{              
#define THEN                ){                  
#define WHILE               while(              
#define AND                 &&                  
#define OR                  ||                  
#define NOT                 !                   
#define DO                  do{                 
#define UNTIL               }while(             
#define START               {                   
#define END                 }                   
#define MEET                );                  

#define SWITCH              switch(

#ifdef _Bool
#define BOOL                _Bool
#define TRUE                true
#define FALSE               false
#else
#define BOOL                char
#define TRUE                1
#define FALSE               0
#endif
#define OUT

#define RETURN              return
#define BREAK               break
#define CONTINUE            continue
#define GOTO                goto
#define DEFAULT             default
#define CASE                case
#define FOR                 for(

#define ENUM                enum
#define STRUCT              struct
#define EXTERN              extern
#define STATIC              static
#define REGISTER            register
#define SIZEOF              sizeof
#define TYPEDEF             typedef
#define UNION               union
#define VOLATILE            volatile
#define RESTRICT            restrict
#define INLINE              inline

#define UINT8 unsigned char
#define UINT16 unsigned short
#define UINT32 unsigned int
#define UINT64 unsigned long int
#define INT8 char
#define INT16 short
#define INT32 int
#define INT64 long int
#define VOID void
#define FLOAT32 float
#define FLOAT64 double
#define FLOAT128 long double
#define CHAR char

/* define a function */
#define FUNC(_ret, _func, ...) \
        _ret _func (__VA_ARGS__) 

/* get each item in array */
#define FOREACH(_item, _idx, _array) \
        for(_item = _array[0];\
        _idx < (sizeof(_array) / sizeof(_array[0]));\
        ++_idx, _item = _array[_idx]

/* get each index in a number */
#define FORINDEX(_item, _num, _step) \
        for(_item = 0;\
        _item < _num;\
        _item += _step

/* loop in condition */

/* ternary operation */
#define TERNARY(_cond, _x, _y) \
        _cond ? _x : _y

#elif __MARCO_C_LANG_VERSION__ == 0x01  /* v0.1 */

#define test                if(                 /* test condition */
#define again               }else if(           /* test again */
#define last                }else{              /* last to do */
#define then                ){                  /* then to do */
#define start               {                   /* start block */
#define end                 }                   /* end block */
#define loop                while(              /* loop while true */
#define ret(_value)         return (_value);    /* return a value */
#define retnil              return;             /* return nil */
#define and                 &&                  /* logical and */
#define or                  ||                  /* logical or */
#define not                 !                   /* logical not */
#define as                  =                   /* assinment */
#define coda                ;                   /* end of grammar */
#define term                break;              /* break out loop */
#define advance             continue;           /* advance processing */
#define go                  do{                 /* go to do */
#define unitl               );                  /* until with loop */
#define const               const               
#define auto                auto
#define branch              switch(             /* conditional branch */
#define jump(_label)        goto _label;        /* jump to label */
#define final               default:            /* final branch */
#define node(_case)         case (_case):       /* branch node */
#define enum                enum
#define struct              struct
#define import              extern
#define static              static
#define register            register
#define sizeof              sizeof
#define typedef             typedef
#define union               union
#define volatile            volatile
#define restrict            restrict
#define inline              inline
#ifdef _Bool
#define bool                _Bool
#define true                true
#define false               false
#else
#define bool                char
#define true                1
#define false               0
#endif
#define bitf                :                   /* bit field */
#define out                                     /* outgoing parameter */

/* integer [unsigned] integer [8, 16, 32, 64] */
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long int   u64;
typedef char                i8;
typedef short               i16;
typedef int                 i32;
typedef long int            i64;
typedef void                nil;
typedef float               f32;
typedef double              f64;
typedef long double         f128;

/* call a function */
#define call(_func, ...) \
        (_func)(__VA_ARGS__);

/* declare a function */
#define def(_ret, _func, ...) \
        _ret _func (__VA_ARGS__);
/* define a function */
#define func(_ret, _func, ...) \
        _ret _func (__VA_ARGS__){

/* get a function return value */
#define get(_func, ...) \
        (_func)(__VA_ARGS__)

/* get each item in array */
#define foreach(_item, _array) \
        int _item##_idx = 0;\
        for(_item = _array[0];\
        _item##_idx < (sizeof(_array) / sizeof(_array[0]));\
        ++_item##_idx, _item = _array[_item##_idx]

/* get each index in a number */
#define foreachi(_item, _num, _step) \
        for(_item = 0;\
        _item < _num;\
        _item += _step

/* loop in condition */
#define forcond(_init, _cond, _next) \
        for(_init; _cond; _next

/* ternary operation */
#define ternary(_cond, _x, _y) \
        _cond ? _x : _y

#endif  /* __MARCO_C_LANG_VERSION__ */

#endif  /* __MARCO_C_LANG_H__ */