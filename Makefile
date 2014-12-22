#$@  	Le nom de la cible
#$< 	Le nom de la première dépendance
#$^ 	La liste des dépendances
#$* 	Le nom du fichier sans suffixe

DIRSDL=/users/prog1a/C/librairie/2011
CFLAGS=-g -I$(DIRSDL)/include 
LDFLAGS=-L$(DIRSDL)/lib -lSDLmain -lSDL -lSDL_ttf -lSDL_image  -lSDL_sound -lSDL_phelma -lSDL_draw

#DEFINE=-DDEBUG

#DIRSDL=/opt/local/include/
#CFLAGS=-g -I$(DIRSDL) -I$(DIRSDL)/SDL -Wall $(DEFINE)
#LDFLAGS=-g -L/opt/local/lib -Wl,-framework,Cocoa  -lSDLmain -lSDL -lSDL_ttf -lSDL_image -lSDL_sound -lSDL_draw -lSDL_phelma

#SRC = $(wildcard *.c) 
SRC=allocation.c calcul_cout.c energie.c seam_carving.c supprime_colonne.c trace_chemin.c trouve_chemin.c zoomx.c autre_energie.c
OBJS = $(SRC:.c=.o)

TESTS_SRC=allocation_test.c energie_test.c
TESTS_EXEC=$(TESTS_SRC:.c=.o)
TESTS_EXEC=$(TESTS_SRC:.c=.exe)

prog : prog.o $(OBJS) 
	gcc -o $@ $^ $(LDFLAGS)

demo_seam : demo_seam.o seam_carving_graphique.o $(OBJS) 
	gcc -o $@ $^ $(LDFLAGS)

allocation_test.exe : allocation_test.o allocation.o
	gcc -o $@ objets/$^ $(LDFLAGS)

%.o: %.c
	gcc -c sources/$< -o objets/$@ $(CFLAGS)
	
clean :
	rm -f *.o prog  *~

%.exe	:  %.o $(OBJS) 
	gcc -o $@ $< $(LDFLAGS) $(OBJS)
	

