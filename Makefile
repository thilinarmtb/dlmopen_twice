CFLAGS ?= -Wall -Wpedantic -Wextra

LIB = libfoo.so
BIN = bar

all: run

lib:
	gcc $(CFLAGS) -c -fPIC -o foo.o foo.c
	gcc  -shared -o $(LIB) foo.o -ldl

bin: lib
	gcc $(CFLAGS) bar.c -o bar -Wl,-rpath,. -L. -lfoo -ldl

run: bin
	./$(BIN)

clean:
	-@rm $(LIB) $(BIN) *.o core.* 2>/dev/null
