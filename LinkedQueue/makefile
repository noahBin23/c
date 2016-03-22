main: linkqueue.o main.o
	gcc linkqueue.o main.o -o main
linkqueue.o: linkqueue.h linkqueue.c
	gcc -c -o linkqueue.o linkqueue.c
main.o: linkqueue.h linkqueue.o main.c
	gcc -c -o main.o main.c
.PHONY:clean
clean:
	rm -f *.o
