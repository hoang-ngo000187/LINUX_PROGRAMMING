


static:
	ar rcs lib/static/libhello.a obj/helloHoang.o obj/helloWorld.o
link:
	gcc obj/main.o -Llib/static -lhello -o bin/statically-linked
all:
	gcc -c main.c -o obj/main.o -I./inc
	gcc -c src/helloHoang.c -o obj/helloHoang.o -I./inc
	gcc -c src/helloWorld.c -o obj/helloWorld.o -I./inc
clean:
	rm -rf obj/* bin/*
