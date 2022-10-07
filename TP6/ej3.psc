Algoritmo sin_titulo
	Dimension num[10]
	Para i<-0 Hasta 9 Hacer
		Leer num[i]
	FinPara
	max = num[0]
	pos = 1
	Para i<-1 Hasta 9 Hacer
		Si num[i] > max Entonces
			max = num[i]
			pos = i + 1
		FinSi
	FinPara
	Escribir "El máximo número ingresado es: ", max , " y su posición: ", pos
FinAlgoritmo
