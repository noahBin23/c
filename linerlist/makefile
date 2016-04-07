main_testLinerlist:linerlist.o main_testLinerlist.o
	gcc main_testLinerlist.o linerlist.o -o main_testLinerlist
main_testLinerlist.o:linerlist.h main_testLinerlist.c
	gcc -c -o main_testLinerlist.o main_testLinerlist.c
linerlist.o:linerlist.h linerlist.c
	gcc -c -o linerlist.o linerlist.c
clean:
	rm *.o
	rm main_testLinerlist
