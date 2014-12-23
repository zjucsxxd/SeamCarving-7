allocation_test.exe : allocation.o allocation_test.o
	gcc objets/allocation.o objets/allocation_test.o -o allocation_test.exe

%.o : sources/%.c
	gcc $< -c -o objets/$@

clean :
	rm objets/*.o
	
cleanexe :
	rm *.exe
