#include "mclang.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "shape.h"

/* 容器配置 */
#define CONTAINER_NAME              SHAPE_CONTAINER_NAME
#define CONTAINER_FUNC_LIST_NAME    SHAPE_CONTAINER_FUNC_LIST_NAME

// 容器共有成员
STATIC INT32 count = 0;

// 构建函数
CONTAINER_CONSTRUCTOR START
    count++;
    printf("call constructor %d!\n", count);
END
// 析构函数
CONTAINER_DESTRUCTOR START
    --count;
    printf("call destructor %d!\n", count);
END

// 
CONTAINER_FUNC(int, get_width) START

END
// 
CONTAINER_FUNC_ARGS(int, set_width, int width) START


END
// 
CONTAINER_FUNC(int, get_area) START
    //printf("area: %d\n", cont->height * cont->width);
END
// 
CONTAINER_FUNC(int, show_area) START
    printf("area: %d\n", cont->height * cont->width);
END
/* 构建函数列表 */
CONTAINER_FUNC_LIST(CONTAINER_FUNC_LIST_NAME) = START
    .constructor = constructor,
    .destructor = destructor,
    .get_width = get_width,
    .set_width = set_width,
    .get_area = get_area,
    .show_area = show_area, 
END;
