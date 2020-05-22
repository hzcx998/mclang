
# includes dir
INCS     = 
# libarys dir
LIBS     = 

# System environment variable.
ifeq ($(OS),Windows_NT)
	HOSTOS		:= windows
	RM		= D:/Softwares/Cygwin/bin/rm 	# in cygwin
	CC       	= D:/Softwares/Mingw/bin/gcc	# need mingw gcc for windows
	# need mingw include and libs in windows
	LIBS     += -L"D:/Softwares/Dev-Cpp/MinGW64/lib" -L"D:/Softwares/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib" -static-libgcc -g3
	INCS     += -I"D:/Softwares/Dev-Cpp/MinGW64/include" -I"D:/Softwares/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"D:/Softwares/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.8.1/include"
else
	ifeq ($(shell uname),Darwin)
		HOSTOS		:= macos
		RM		= rm
		CC       	= gcc
	else
		ifeq ($(shell uname),Linux)
			HOSTOS		:= linux
			RM		= rm
			CC       	= gcc
		else
			HOSTOS		:= unix-like
			RM		= rm
			CC       	= gcc
		endif
	endif
endif

# flags	
CFLAGS   = $(INCS) -g3

# objects		
OBJS = 	main.o \
		
# out file
BIN = mc
	
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
	
