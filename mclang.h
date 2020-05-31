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

#define __MARCO_C_LANG_VERSION__    0x03    /* v0.3 */

#if __MARCO_C_LANG_VERSION__ == 0x03    /* v0.3 */
/* keywords */
#define when                if(                 
#define elif                }else if(           
#define other               }else{              
#define then                ){                  
#define loop               while(              
#define and                 &&                  
#define or                  ||                  
#define not                 !                   
#define cycle                do{                 
#define until               }while(             
#define begin               {                   
#define end                 }                   
#define meet                );                  

#define match              switch(

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

#define forcond                 for(

#define uint8 unsigned char
#define uint16 unsigned short
#define uint32 unsigned int
#define uint64 unsigned long int
#define int8 char
#define int16 short
#define int32 int
#define int64 long int
#define f32 float
#define f64 double
#define f128 long double

/* define a function */
#define func(_ret, _func, ...) \
        _ret _func (__VA_ARGS__) 

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

/* loop in condition */

/* ternary operation */
#define ternary(_cond, _x, _y) \
        _cond ? _x : _y

/*
object_name
object_funclist_name
*/
#define object(name) struct name

#define object_constructor \
        static void constructor(struct object_name *cont, void *args)
#define object_constructor_ptr(name) \
        void (*constructor)(struct name *cont, void *args)
#define object_destructor \
        static void destructor(struct object_name *cont)
#define object_destructor_ptr(name) \
        void (*destructor)(struct name *cont)

#define object_func(ret, func) \
        static ret func(struct object_name *cont)

#define object_funcn(ret, func,...) \
        static ret func(struct object_name *cont,__VA_ARGS__)

#define object_func_ptr(ret, name, func) \
        ret (*func)(struct name *cont)

#define object_funcn_ptr(ret, name, func, ...) \
        ret (*func)(struct name *cont, __VA_ARGS__)

#define object_funclist_BOX(name) \
        struct name
        
#define object_funclist_ptr(name) \
        struct name *_funclist

#define object_funclist(name) \
        struct name name
        
#define object_inherit(name) \
        struct name _inherit

#define build(name, obj, args) \
        (obj)->_funclist = &(name##_funclist); \
        (obj)->_funclist->constructor((obj), (args))

#define debuild(obj) \
        (obj)->_funclist->destructor(obj)

#define create(name, obj, args) \
        do { \
            obj = malloc(sizeof(struct name)); \
            if (obj == NULL) { \
                break; \
            } \
            build(name, obj, args); \
        } while (0)

#define call(obj, func) \
        (obj)->_funclist->func(obj)
#define calln(obj, func, ...) \
        (obj)->_funclist->func(obj, __VA_ARGS__)

#define destroy(obj) \
        do { \
            if (!(obj)) \
                break; \
            debuild(obj); \
            free(obj); \
        } while (0)

#elif __MARCO_C_LANG_VERSION__ == 0x02    /* v0.2 */
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
#define func(_ret, _func, ...) \
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

/*
object_name
object_funclist_name
*/
#define object(name) struct name

#define object_constructor \
        static void constructor(struct object_name *cont, void *args)
#define object_constructor_ptr(name) \
        void (*constructor)(struct name *cont, void *args)
#define object_destructor \
        static void destructor(struct object_name *cont)
#define object_destructor_ptr(name) \
        void (*destructor)(struct name *cont)

#define object_func(ret, func) \
        static ret func(struct object_name *cont)

#define object_func_ARGS(ret, func,...) \
        static ret func(struct object_name *cont,__VA_ARGS__)

#define object_func_ptr(ret, name, func) \
        ret (*func)(struct name *cont)

#define object_func_ARGS_ptr(ret, name, func, ...) \
        ret (*func)(struct name *cont, __VA_ARGS__)

#define object_func_LIST_BOX(name) \
        struct name
        
#define object_func_LIST_ptr(name) \
        struct name *_funclist

#define object_func_LIST(name) \
        struct name name
        
#define object_INHERIT(name) \
        struct name _inherit

#define BUILD(name, obj, args) \
        (obj)->_funclist = &(name##_funclist); \
        (obj)->_funclist->constructor((obj), (args))

#define DEBUILD(obj) \
        (obj)->_funclist->destructor(obj)

#define CREATE(name, obj, args) \
        do { \
            obj = malloc(sizeof(struct name)); \
            if (obj == NULL) { \
                break; \
            } \
            BUILD(name, obj, args); \
        } while (0)

#define CALL(obj, func) \
        (obj)->_funclist->func(obj)
#define CALL_ARGS(obj, func, ...) \
        (obj)->_funclist->func(obj, __VA_ARGS__)

#define DESTROY(obj) \
        do { \
            if (!(obj)) \
                break; \
            DEBUILD(obj); \
            free(obj); \
        } while (0)

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