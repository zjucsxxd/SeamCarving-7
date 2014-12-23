allocation_test.exe : allocation.o allocation_test.o
	gcc objets/allocation.o objets/allocation_test.o -o allocation_test.exe

allocation.o : sources/allocation.c
	gcc sources/allocation.c -c -o objets/allocation.o

allocation_test.o : sources/allocation_test.c
	gcc sources/allocation_test.c -c -o objets/allocation_test.o
