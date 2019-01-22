#Programa de .obj a .wrl
import sys

if len(sys.argv)>=3:
	print ("Numero de argumentos correcto")
	print (len(sys.argv))
else:
	print ("Falta el argumento del fichero")
	sys.exit(1)

#Abrimos el fichero OBJ
try:
	ficheroOBJ=open(sys.argv[1], "r")
except Exception:
	print ("Error al abrir el fichero")
	sys.exit(1)

#Escribimos lo basico en un fichero para crear el wrl
try:
	ficheroWRL=open(sys.argv[2], "w")
except Exception:
	print ("Error al abrir el fichero")
	sys.exit(1)

ficheroWRL.write("#VRML V2.0 utf8\n")
ficheroWRL.write("Shape{\n")
ficheroWRL.write("\tgeometry IndexedFaceSet{\n")
ficheroWRL.write("\t\tcoord Coordinate{\n")
ficheroWRL.write("\t\t\tpoint[\n")

#Ahora tenemos que ir leyendo el fichero OBJ linea a linea y sacar lo que necesitamos
#Escribiremos primero los vertices
for linea in ficheroOBJ:
	if linea[0]=="v" and linea[1]==" ":
		separacion=linea.split(" ")#Ya tenemos separada la linea en una tupla
		#Borramos la separacion para poder coger el resto de la linea
		del separacion[0]
		#Finalmente escribimos en el fichero WRL
		ficheroWRL.write("\t\t\t\t")
		#Hacemos lo siguiente para borrar el ultimo salto de linea y así poder poner la ,
		separacion = [elem.strip() for elem in separacion]
		for elemento in separacion:
			ficheroWRL.write(elemento+" ")

		ficheroWRL.write(",\n")

#Cerramos el point
ficheroWRL.write("\t\t\t]\n")
#Cerramos el coord Cordinate
ficheroWRL.write("\t\t}\n")
#Cerramos el fichero OBJ
ficheroOBJ.close()

#Seguidamente escribiremos las caras
#Hay que volver a abrir el fichero OBJ
try:
	ficheroOBJ=open(sys.argv[1], "r")
except Exception:
	print ("Error al abrir el fichero")
	sys.exit(1)

ficheroWRL.write("\t\tcoordIndex[\n")

for linea in ficheroOBJ:
	if linea[0]=="f" and linea[1]==" ":
		#Realizamos el mismo paso que con los vertices
		separacion = linea.split(" ")
		del separacion[0]

		if len(separacion)==3:
			#Tenemos ['x1/x2/x3', 'x1/x2/x3', 'x1/x2/x3']
			ficheroWRL.write("\t\t\t\t")
			for elemento in separacion:
				#Separamos los elemento con /
				item = elemento.split("/")
				#Conseguimos todos los elementos de x [x1,x2,x3]
				#Escribimos el primero
				ficheroWRL.write(item[0]+", ")
			ficheroWRL.write("\n")
		elif len(separacion)>3:
			#Este else es para cuando tiene más de tres elementos, es decir, que tienen un espacio al final
			#Lo primero es borrar ese espacio para que no nos coloque dobles comas
			del separacion[len(separacion)-1]
			ficheroWRL.write("\t\t\t\t")
			for elemento in separacion:
				#Realizamos la misma operacion que antes
				item=elemento.split("/")
				ficheroWRL.write(item[0]+", ")
			ficheroWRL.write("\n")
#Cerramos la parte de coorIndex
ficheroWRL.write("\t\t\t]\n")

ficheroWRL.write("\t}\n")
ficheroWRL.write("}\n")

#Cerramos los dos ficheros
ficheroOBJ.close()
ficheroWRL.close()