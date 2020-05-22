# tools
RM			= D:/Softwares/Cygwin/bin/rm
CC       	= D:/Softwares/Mingw/bin/gcc	# need mingw gcc for windows

# need mingw include and libs
LIBS     = -L"D:/Softwares/Dev-Cpp/MinGW64/lib" -L"D:/Softwares/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib" -static-libgcc -g3
INCS     = -I"D:/Softwares/Dev-Cpp/MinGW64/include" -I"D:/Softwares/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"D:/Softwares/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.8.1/include"

# flags	
CFLAGS   = $(INCS) -g3

# objects		
OBJS = 	main.o \
		
# out file
BIN = mc.exe
	
.PHONY: all clean

# all need to do
all: $(BIN) 

$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $(BIN) $(LIBS)

%.o : %.c
	@echo [CC] $@ $<
	@$(CC) -c $(CFLAGS) -o $@ $<

# clean .o .a files
clean: 
	-$(RM) $(BIN)
	-$(RM) $(OBJS)
	