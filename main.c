#include "mclang.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

decl(test, s32, arg(a, s32), arg(b, s32))

def (main, s32) begin
    func(printf, "hello, world!\n")
    var(a, s32)
    varset(A, s32, 1)
    eva(A, A+1)
    loop true then
        evainc(A)
        func(printf, "A: %d\n", A)
        when A >= 5 then
            skip
        end
    end

    when A == 2 then
        func(printf,"A == 2\n")
    elif A == 3 then
        func(printf,"A == 3\n")
    other
        func(printf,"A == %d\n", A)
    end

    match A then
    branch(7)
        func(printf,"A IS 7\n")
        skip
    branch(8)
        func(printf,"A IS 8\n")
        skip
    branch(9)
        func(printf,"A == %d\n", A)
        skip
    nomatch
        skip
    end

    varset(B, bool, false)
    when B == false then
        jmp(label_1)
    other
        jmp(label_1)
    end

lable(label_1)
    func(printf,"AT LABEL 1\n")
    
lable(label_2)
    func(printf,"AT LABEL 2\n")

lable(label_3)
    func(printf,"AT LABEL 3\n")
    return func(test,1, 2)
end

def (test, s32, arg(x, s32), arg(y, s32)) begin

    var(i, s32)
    forcond i = 0; i < 10; inc(i) then
        func(printf, "i=%d\n", i)
    end

    list (C) begin
        C_ABC = 1,
        C_DEF,
    enddata

    group (D) begin
        var(a, s32)
        var(b, s32)
    enddata

    var(student, group(D))
    varmult(stu0, group(D)) begin
        1, 2
    enddata

    var(db0[10], char)
    varmult(data[10], char) begin
        1, 2, 3
    enddata

    var(ITEM, char)
    varset(idx, s32, 0)
    foreach (ITEM, idx, data) then
        func(printf,"item:%d\n", ITEM)
    end

    forindex (ITEM, LEN_ARRAY(data), 1) then
        func(printf,"index:%d\n", ITEM)
    end

    varset(a, int, 3)
    try
        when a == 1 then
            throw(1)
        elif a == 2 then
            throw(2)
        other 
            try
                when a > 2 then
                    func(printf,"throw 1\n")
                    throw(1)
                end
            catch(1)
                func(printf,"throw 3\n")
                throw(3)
            endtry
        end
    catch(1)
        func(printf,"catch 1\n")
    catch(2)
        func(printf,"catch 2\n")
    finally
        func(printf,"catch finally\n")
    endtry

    return 0;
end