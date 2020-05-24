#include "mclang.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

def(nil, bubble_sort, i32 arr[], i32 len)
def(nil, selection_sort, i32 arr[], i32 len)
void selection_sort2(int arr[], int len);
func(i32, main, i32 argc, i8 ** argv)
    call(printf, "welcome to mclang v%s\n", __MARCO_C_LANG_VERSION__);

    i8 a as 1 coda

    i8 *str as "hello" coda

	test a == 1 and not get(strcmp, str, "world") then
	    call(printf, "hello")
	again a == 2 then
	    call(printf, "this a %s to %d\n", "hah", 123)
	last
        call(printf, "do final.\n")
	end

    i8 b as 1 coda
    i8 c as 1, d as 2 coda
    
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
