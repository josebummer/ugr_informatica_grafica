# fichero Makefile Practica 3 -- Jose Antonio Ruiz Millan
#
# nombre del fichero ejecutable
#
TARGETS= practica5

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -std=c++11 -g -DXWINDOWS -DSHM -I/usr/include -I.
CXXFLAGS=  -std=c++11 -g -DXWINDOWS -DSHM -I/usr/include -I.

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut

# definicion del compilador
#
CC = g++

# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) : practica5.o objetos.o objetos.h file_ply_stl.o
	$(CC) -o $@ $(CXXFLAGS) practica5.o objetos.o file_ply_stl.o $(LDFLAGS)

#
#
clean:
	rm -f *.o
	rm -f *.gch
	rm -fr .vscode
	rm -f $(TARGETS)

#
#
redo:
	touch *.cc
	make

#
#
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *
