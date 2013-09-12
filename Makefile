# Makefile template for shared library
#  
#  CC = gcc # C compiler
CFLAGS = -fPIC -Wall -Werror -Wextra -O2 -g -I./src/include
LDFLAGS = -shared  # linking flags
RM = rm -f  # rm command
TARGET_LIB = lib/libpenetra.so # target lib
 
SRCS = src/penetra.c src/dos.c # source files
OBJS = $(SRCS:.c=.o)
 
.PHONY: all
all: ${TARGET_LIB}
 
$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^
 
$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@
 
include $(SRCS:.c=.d)
 
.PHONY: clean
clean:
	rm lib/*.so src/*.d src/*.o
