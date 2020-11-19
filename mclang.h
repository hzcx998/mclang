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
 * 
 */
#ifndef __MARCO_C_LANG_H__
#define __MARCO_C_LANG_H__

#define __MARCO_C_LANG_VERSION__    0x03    /* v0.3 */

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
#define enddata             };                
#define endcycle            );                  

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
#define def(_ret, _func, ...) \
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

#define LEN_ARRAY(_array) (sizeof(_array) / sizeof(_array[0]))

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

#define object_funclist_box(name) \
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

#define func(obj, func) \
        (obj)->_funclist->func(obj)
#define funcn(obj, func, ...) \
        (obj)->_funclist->func(obj, __VA_ARGS__)
#define set(obj, m, val) \
        (obj)->m = val
#define get(obj, m, val) \
        (val) = (obj)->m

#define destroy(obj) \
        do { \
            if (!(obj)) \
                break; \
            debuild(obj); \
            free(obj); \
        } while (0)

#endif  /* __MARCO_C_LANG_H__ */