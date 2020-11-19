#include "mclang.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "shape.h"

def (int32, test);

def (int32, main) begin
    printf("hello, world!\n");

    object (shape) *obj = NULL, *obj1 = NULL;
    create (shape, obj,NULL);
    
    when obj == NULL then
        printf("create obj failed!\n");
        return -1;    
    end

    set(obj, width, 100);
    set(obj, height, 200);
    func (obj, show_area);
    funcn (obj, set_width, 200);
    func (obj, show_area);
    
    create (shape, obj1,NULL);
    
    when obj1 == NULL then
        printf("create obj failed!\n");
        return -1;    
    end

    obj1->width = 200;
    obj1->height = 400;
    func (obj1, show_area);
    funcn (obj1, set_width, 50);
    func (obj1, show_area);
    
    destroy(obj1);
    
    destroy(obj);

    object (shape) obj2;

    build(shape, &obj2, NULL);
    debuild(&obj2);

    printf("end container!\n");

    int A = 1;
    loop true then
        A++;
        printf("A: %d\n", A);
        when A >= 5 then
            break;
        end
    end

    when A == 2 then
        printf("A == 2\n");
    elif A == 3 then
        printf("A == 3\n");
    other
        printf("A == %d\n", A);
    end

    cycle 
        A++;
        continue;
    until A < 10 endcycle

    match  A then
    case 7:
        printf("A IS 7\n");
        break;
    case 8:
        printf("A IS 8\n");
        break;
    default:
        printf("A == %d\n", A);
        break;
    end

    bool B = false;

    when B == false then
        goto label_1;
    other
        goto label_2;
    end

label_1:
    printf("AT LABEL 1\n");
        

label_2:
    printf("AT LABEL 2\n");
     
label_3:
    printf("AT LABEL 3\n");

    return test();
end

def (int32, test) begin
    
    int32 i;
    forcond i = 0; i < 10; i++ then
        printf("i=%d\n", i);
    end

    enum C begin
        C_ABC = 1,
        C_DEF,
    enddata

    struct D begin
        int32 A;
        int32 B;
    enddata
    struct D student;

    char data[3] = begin
        1, 2, 3
    enddata

    char ITEM;
    int32 idx = 0;
    foreach (ITEM, idx, data) then
        printf("item:%d\n", ITEM);
    end

    forindex (ITEM, LEN_ARRAY(data), 1) then
        printf("index:%d\n", ITEM);
    end
    
    return 0;
end
