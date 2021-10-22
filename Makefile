LIBRARY = libmx.a

CL_FL = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: crt_obj libmx crt_lib

crt_obj:
	mkdir obj

libmx:
	clang $(CL_FL) -c src/*.c
	mv *.o obj/

crt_lib:
	ar -rc $(NAME_LIB) obj/*.o
	ranlib $(NAME_LIB)

clean:
	rm -rf obj

uninstall:
	rm -rf obj
	rm -rf $(NAME_LIB)

reinstall:
	make uninstall
	make