Algoritmo ej2
	dimension num[10]
	suma = 0
	Para i<-0 Hasta 9 Hacer
		Leer num[i]
		suma = suma + num[i]
	FinPara
	promedio = suma / 10
	Para i<-0 Hasta 9 Hacer
		Si num[i] > promedio Entonces
			Escribir num[i]
		FinSi
	FinPara
FinAlgoritmo
