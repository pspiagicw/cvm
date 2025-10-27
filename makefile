CFLAGS=-Werror -Wall -pedantic
build:
	gcc $(CFLAGS) -o cvm main.c log.c magic.c constants.c bytecode.c vm.c

.PHONY: build
