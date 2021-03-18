CC_VERBOSE = $(CC)
CC_NO_VERBOSE = @echo "Building $@..."; $(CC)
DESTDIR?=/usr/lib

ifeq ($(VERBOSE),YES)
  V_CC = $(CC_VERBOSE)
  AT := 
else
  V_CC = $(CC_NO_VERBOSE)
  AT := @
endif

C_FILES = $(wildcard *.c bin/*.c)
O_FILES = $(C_FILES:src/%.c=build/objects/%.o)

.PHONY: all clean
.DEFAULT: all

all: main

main: $(O_FILES)
	$(V_CC) -I../include/ -o $@ $^

build:
	$(AT)mkdir -p ../build/objects
	$(AT)mkdir -p ../build/lib

build/%.o: src/%.c | build
	$(V_CC) -c $< -o $@
bin:
	gcc bin/main.c -o main
install: 
	mv ../build/lib ${DESTDIR}
clean:
	@echo Removing build directory
	$(AT)-rm -rf build