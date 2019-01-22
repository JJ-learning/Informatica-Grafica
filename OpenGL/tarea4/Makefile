LIBS= -lGL -lglut -lGLU
#Fichero makefile

union: nuevo.x clean

nuevo.x: nuevo.o 
	gcc -o ejecutable nuevo.o  $(LIBS)

#Construccion de los ficheros objeto
nuevo.o: nuevo.cpp
	gcc -c nuevo.cpp

#Construcción del destino que permite eliminar los ficheros objeto
clean:
	@echo "Borrando los ficheros objetos generados"
	rm *.o