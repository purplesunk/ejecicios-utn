Algoritmo sin_titulo
	Leer num
	divisores = 0
	Para i<-num Hasta 1 Con Paso -1 Hacer
		Si num%i==0 Entonces
			divisores = divisores + 1
		FinSi
	FinPara
	Escribir divisores
FinAlgoritmo
