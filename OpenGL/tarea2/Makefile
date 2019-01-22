LIBS= -lGL -lglut -lGLU
#Fichero makefile

union: ejemplo.x clean

ejemplo.x: ejemplo.o 
	gcc -o ejecutable ejemplo.o  $(LIBS)

#Construccion de los ficheros objeto
ejemplo.o: ejemplo.cpp
	gcc -c ejemplo.cpp

#Construcción del destino que permite eliminar los ficheros objeto
clean:
	@echo "Borrando los ficheros objetos generados"
	rm *.o