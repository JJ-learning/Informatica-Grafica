LIBS= -lGL -lglut -lGLU
#Fichero makefile

union: rectangulo.x clean

rectangulo.x: rectangulo.o 
	gcc -o ejecutable rectangulo.o  $(LIBS)

#Construccion de los ficheros objeto
rectangulo.o: rectangulo.cpp
	gcc -c rectangulo.cpp

#Construcción del destino que permite eliminar los ficheros objeto
clean:
	@echo "Borrando los ficheros objetos generados"
	rm *.o
