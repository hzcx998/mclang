#include "mclang.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "shape.h"

#if __MARCO_C_LANG_VERSION__ == 0x01    /* v0.1 */
def(nil, bubble_sort, i32 arr[], i32 len)
def(nil, selection_sort, i32 arr[], i32 len)
void selection_sort2(int arr[], int len);
func(i32, main, i32 argc, i8 ** argv)
    call(printf, "welcome to mclang v%s\n", __MARCO_C_LANG_VERSION__)

    i8 a = 1;

    i8 *str = "hello";

	test a == 1 and not get(strcmp, str, "world") then
	    call(printf, "hello")
	again a == 2 then
	    call(printf, "this a %s to %d\n", "hah", 123)
	last
        call(printf, "do final.\n")
	end

    i8 b = 1;
    i8 c as 1, d = 2;
    
	loop b < 10 then 
	    b += 1;
	    call(printf, "loop %d\n", b);
	end

    i8 data as 0 coda

    i8 buf[10] as start
        0, 1, 2, 4, 
    end coda

    foreach(data, buf) then
        test data == 0 then advance end
        
        call(printf, "data:%d\n", data)
    end

    foreachi(data, sizeof(buf), 1)then
        call(printf, "data:%d\n", data)
        test data > 5 then
            term
        end
    end

    const nil *nil_buf as NULL coda

    i8 i as 0 coda

    i as (1 + 3) / 2 * 10 % 2 coda

    i += 5 coda
    i++ coda

    i as ternary(i > 5, i, 0) coda

    go
        i++ coda
    end loop i < 10 unitl

    auto i32 var0 as 0x123 coda
    call(printf, "hello, %x\n", var0)

    branch var0 then
    node(0)
        call(printf, "exam 0\n")
        term
    final
        call(printf, "final\n")
        term
    end

    f32 pi as 3.1415926f coda
    call(printf, "pi: %f\n", pi)
    
    enum types start
        TOKEN_A as 0,
        TOKEN_B
    end coda

    struct student start
        i8 *name coda
        i32 age bitf 4 coda
        i32 year bitf 4 coda
    end coda

    struct student stu coda
    stu.name as "jason" coda
    call(printf, "studnet: name: %s\n", stu.name)

    call(printf, "studnet: size: %d\n", sizeof(stu))

    i32 new as 0 coda

    new = (i32) i coda

    i32 arr[] = start 
        22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70
    end coda
    i32 len = (i32) sizeof(arr) / sizeof(*arr) coda
    //call(bubble_sort, arr, len)
    call(selection_sort, arr, len)
    
    i32 j coda
    foreachi(j, len, 1) then
        call(printf, "%d ", arr[j])
    end
    ret(0);
end

func(nil, bubble_sort, i32 arr[], i32 len)
    i32 i, j, temp coda
    foreachi(i, len-1, 1) then
        foreachi(j, len - 1 - i, 1) then
            test arr[j] > arr[j + 1] then
                temp as arr[j] coda
                arr[j] as arr[j + 1] coda
                arr[j + 1] as temp coda
            end
        end
    end
end

func(nil, swap, out i32 *a, out i32 *b)
    i32 temp as *a;
    *a as *b;
    *b as temp;
end

func(nil, selection_sort, out i32 arr[], i32 len)
    i32 i,j;
    foreachi(i, len-1, 1) then
        i32 min as i;
        forcond (j = i + 1, j < len, j++) then     //走訪未排序的元素
            test arr[j] < arr[min] then   //找到目前最小值
                min as j;    //紀錄最小值
            end
        end
        call(swap, &arr[min], &arr[i])    //做交換
    end
end

#elif __MARCO_C_LANG_VERSION__ == 0x02    /* v0.2 */
FUNC (INT32, test);

FUNC (INT32, main) START
    printf("hello, world!\n");

    CONTAINER(shape) *obj = NULL, *obj1 = NULL;
    CREATE (shape, obj,NULL);
    
    IF obj == NULL THEN
        printf("create obj failed!\n");
        RETURN -1;    
    END

    obj->width = 100;
    obj->height = 200;
    CALL (obj, show_area);
    CALL_ARGS (obj, set_width, 200);
    CALL (obj, show_area);
    
    CREATE (shape, obj1,NULL);
    
    IF obj1 == NULL THEN
        printf("create obj failed!\n");
        RETURN -1;    
    END

    obj1->width = 200;
    obj1->height = 400;
    CALL (obj1, show_area);
    CALL_ARGS (obj1, set_width, 50);
    CALL (obj1, show_area);
    
    DESTROY(obj1);
    
    DESTROY(obj);

    CONTAINER(shape) obj2;

    BUILD(shape, &obj2, NULL);
    DEBUILD(&obj2);

    printf("end container!\n");

    INT32 A = 1;
    WHILE TRUE THEN
        A++;
        printf("A: %d\n", A);
        IF A >= 5 THEN
            BREAK;
        END
    END

    IF A == 2 THEN
        printf("A == 2\n");
    ELIF A == 3 THEN
        printf("A == 3\n");
    ELSE
        printf("A == %d\n", A);
    END

    DO 
        A++;
        CONTINUE;
    UNTIL A < 10 MEET

    SWITCH  A THEN
    CASE 7:
        printf("A IS 7\n");
        BREAK;
    CASE 8:
        printf("A IS 8\n");
        BREAK;
    DEFAULT:
        printf("A == %d\n", A);
        BREAK;
    END

    BOOL B = FALSE;

    IF B == FALSE THEN
        GOTO LABEL_1;
    ELSE
        GOTO LABEL_2;
    END

LABEL_1:
    printf("AT LABEL 1\n");
        

LABEL_2:
    printf("AT LABEL 2\n");
     
LABEL_3:
    printf("AT LABEL 3\n");

    RETURN test();
END

FUNC (INT32, test) START
    
    INT32 i;
    FOR i = 0; i < 10; i++ THEN
        printf("i=%d\n", i);
    END

    ENUM C START
        C_ABC = 1,
        C_DEF,
    END;

    STRUCT D START
        INT32 A;
        INT32 B;
    END;
    STRUCT D student;

    CHAR DATA[3] = START
        1, 2, 3
    END;

    CHAR ITEM;
    INT32 idx = 0;
    FOREACH (ITEM, idx, DATA) THEN
        printf("item:%d\n", ITEM);
    END

    #define LEN_ARRAY(_array) (sizeof(_array) / sizeof(_array[0]))

    FORINDEX (ITEM, LEN_ARRAY(DATA), 1) THEN
        printf("index:%d\n", ITEM);
    END
    
    RETURN 0;
END

#endif 