Algoritmo sin_titulo
	dimension decada[10]
	Para i<-0 Hasta 9 Hacer
		decada[i] = 0
	FinPara
	Para i<-1 Hasta 200 Hacer
		Escribir "Ingrese edad: "
		Leer edad
		resto = edad%10
		edad = (edad-resto)/10
		decada[edad] = decada[edad] + 1
	FinPara
	Escribir "Cantidad de personas según década: "
	Para i<-0 Hasta 9 Hacer
		Escribir "Década ",i,": ", decada[i]
	FinPara
FinAlgoritmo
