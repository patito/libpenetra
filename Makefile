CFLAGS = -fPIC -Wall -Werror -Wextra -O2 -g -I./src/include
LDFLAGS = -shared
RM = rm -f
TARGET_LIB = lib/libpenetra.so
 
SRCS = src/penetra.c src/dos.c src/coff.c
OBJS = $(SRCS:.c=.o)
 
all: ${TARGET_LIB}
 
$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^
 
clean:
	rm lib/*.so src/*.o
