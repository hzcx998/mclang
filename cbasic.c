#include "mclang.h"
#include "cbasic.h"
#include <stdlib.h>
#include <stdio.h>

Sub(test2)

EndSub

Function(Min, Integer, ByVal(x, Integer), ByVal(y, Integer))
    If x > y Then
        Return(x)
    Else
        Return(y)
    EndIf
EndFunction

Sub(cbasic)
    ConsoleWriteLine("cbasic")
    DimAs(a, Integer, 1)
    $(a = 10)
    DimAs(b, Boolean, False)

    ConstAs(c, Integer)

    If a > 10 Then
        ConsoleWrite("A > 10")
    ElseIf a > 5 Then
        ConsoleWrite("A > 5")
    Else 
        ConsoleWrite("A <= 0")
    EndIf

    Select(a)
        Case(1)
            ConsoleWrite("case 1")
            ExitCase
        Case(10)
            ConsoleWrite("case 10")
            ExitCase
        CaseElse
            ConsoleWrite("no case")
    EndSelect

    DimAs(i, Integer, 0)
    DoWhile(i < 10)
        ConsoleWrite("%d", i);
        $(i += 1)
    Loop

    $(i = 0)

    DoUntil(i > 10)
        ConsoleWrite("%d", i)
        $(i += 1)
        ContinueDo
    Loop

    $(i = 0)
    Do
        ConsoleWrite("%d", i)
        i += 1;
        If i > 5 Then
            ExitDo
        EndIf
    LoopWhile(i < 10) 
        
    $(i = 0)
    While(i < 10)
        ConsoleWrite("%d", i)
        $(i += 1)
    EndWhile

    Goto(label)
    ConsoleWriteLine("first")
label:
    ConsoleWriteLine("second")

    DimAs(j, Integer, 10);

    $(j = i + 10 * 30 + Min(20, 10))

    exit(0);
EndSub