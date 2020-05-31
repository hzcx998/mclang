#ifndef __SHAPE_object_H__
#define __SHAPE_object_H__

#include "mclang.h"

#define shape_object_name              shape
#define shape_object_funclist_name    shape_funclist

/* 容器 */
object(shape_object_name) begin
    // 函数成员
    object_funclist_ptr(shape_object_funclist_name);
    // 变量成员
    int32 width, height;
end;

/* 函数列表盒子 */
object_funclist_BOX(shape_object_funclist_name) begin
    object_constructor_ptr(shape_object_name);
    object_destructor_ptr(shape_object_name);
    
    object_func_ptr(int32, shape_object_name, get_width);
    object_funcn_ptr(int32, shape_object_name, set_width, int32 widht);
    object_func_ptr(int32, shape_object_name, get_area);
    object_func_ptr(int32, shape_object_name, show_area);
end;

/* 导出函数列表 */
extern object_funclist(shape_object_funclist_name);

#endif  /* __SHAPE_object_H__ */