#include "mclang.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

extern void cbasic();

decl(test, s32, arg(a, s32), arg(b, s32))

def (ascending, s32)
    local var(i, s32)
    begincoro
    forcond i = 0; i < 10; inc(i) then
        yeild(i)
    end
    endcoro(-1)
end

def (main, s32)
    cbasic();
    call(printf, "hello, world!\n")
    var(a, s32)
    var(A, s32, 1)
    as(A, A + 1)
    loop true then
        as(A, A+1)
        call(printf, "A: %d\n", A)
        cmp A >= 5 then
            skip
        end
    end

    cmp A == 2 then
        call(printf,"A == 2\n")
    recmp A == 3 then
        call(printf,"A == 3\n")
    nocmp
        call(printf,"A == %d\n", A)
    end

    match A then
    branch(7)
        call(printf,"A cmp 7\n")
        skip
    branch(8)
        call(printf,"A cmp 8\n")
        skip
    branch(9)
        call(printf,"A == %d\n", A)
        skip
    nomatch
        skip
    end
    
    var(B, bool, false)
    cmp B == false then
        jmp(label_1)
    nocmp
        jmp(label_1)
    end

    var(C, s32) as(C, 1)

lable(label_1)
    call(printf,"AT LABEL 1\n")
    
lable(label_2)
    call(printf,"AT LABEL 2\n")

lable(label_3)
    call(printf,"AT LABEL 3\n")
    back(test(1, 2))
end

def (xbook, nil, arg(ptr, nil))
    // do nothing
    back(ptr)
end

def (test, s32, arg(x, s32), arg(y, s32))

    var(i, s32) forcond i = 0; i < 10; inc(i) then
        call(printf, "i=%d\n", i)
    end

    mutli (list(C),
        C_ABC = 1,
        C_DEF
    )

    mutli (group(D),
        var(a, s32)
        var(b, s32)
    )

    var(student, group(D))

    mutli (let(stu0[10], char),
        1, 2
    )

    var(db0[10], char)
    mutli (let(data[10], char),
        1, 2, 3
    )

    var(item, char)
    var(idx, s32, 0)
    foreach (item, idx, data) then
        call(printf,"item:%d\n", item)
    end

    forindex (item, arraysize(data), 1) then
        call(printf,"index:%d\n", item)
    end

    var(a, int, 3)
    try
        cmp a == 1 then
            throw(1)
        recmp a == 2 then
            throw(2)
        nocmp 
            try
                cmp a > 2 then
                    call(printf,"throw 1\n")
                    throw(1)
                end
            catch(1)
                call(printf,"throw 3\n")
                throw(3)
            endtry
        end
    catch(1)
        call(printf,"catch 1\n")
    catch(2)
        call(printf,"catch 2\n")
    finally
        call(printf,"catch finally\n")
    endtry

    call(free, xbook(malloc(32)))

    call(printf, "call: %d\n", ascending())
    call(printf, "call: %d\n", ascending())
    call(printf, "call: %d\n", ascending())

    back(0)
end