#include "mclang.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "shape.h"

/* 容器配置 */
#define object_name                 shape_object_name
#define object_funclist_name        shape_object_funclist_name

// 容器共有成员
static int32 count = 0;

// 构建函数
object_constructor begin
    count++;
    printf("call constructor %d!\n", count);
end
// 析构函数
object_destructor begin
    --count;
    printf("call destructor %d!\n", count);
end

// 
object_func(int, get_width) begin

end
// 
object_funcn(int, set_width, int width) begin


end
// 
object_func(int, get_area) begin
    //printf("area: %d\n", cont->height * cont->width);
end
// 
object_func(int, show_area) begin
    printf("area: %d\n", cont->height * cont->width);
end
/* 构建函数列表 */
object_funclist(object_funclist_name) = begin
    .constructor = constructor,
    .destructor = destructor,
    .get_width = get_width,
    .set_width = set_width,
    .get_area = get_area,
    .show_area = show_area, 
end;
