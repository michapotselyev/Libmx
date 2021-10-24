all: LIBMX clean

LIBMX:
	mkdir obj
	cd obj && clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c ../src/*.c
	ar rcs libmx.a obj/*.o
	ranlib libmx.a

clean:
	rm -rf obj
	rm -rf libmx.a

uninstall:
	rm -rf obj
	rm -rf libmx.a

reinstall: all

