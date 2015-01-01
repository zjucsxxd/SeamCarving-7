main : allocation.o calcul_cout.o energie.o zoomx.o seam_carving.o prog.o supprime_colonne.o trouve_chemin.o
	gcc objets/allocation.o objets/calcul_cout.o objets/energie.o objets/prog.o objets/seam_carving.o objets/supprime_colonne.o objets/trouve_chemin.o objets/zoomx.o -o prog.exe 
%.o : sources/%.c
	gcc $< -c -o objets/$@
clean :
	rm objets/*.o
cleanexe :
	rm *.exe
