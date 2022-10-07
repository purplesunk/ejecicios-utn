Algoritmo sin_titulo
	Dimension num[10]
	Para i<-0 Hasta 9 Hacer
		Leer num[i]
	FinPara
	max = abs(num[0])
	maxAbs = num[0]
	Para i<-1 Hasta 9 Hacer
		Si abs(num[i])>max Entonces
			max = abs(num[i])
			maxAbs = num[i]
		FinSi
	FinPara
	Escribir "El valor máximo absoluto es: ",maxAbs
FinAlgoritmo
