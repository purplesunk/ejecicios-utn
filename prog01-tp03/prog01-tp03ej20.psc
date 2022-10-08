Algoritmo sin_titulo
	Leer num
	Escribir 'los divisores de ',num,' son: '
	Para i<-num Hasta 1 Con Paso -1 Hacer
		Si num%i==0 Entonces
			Escribir i
		FinSi
	FinPara
FinAlgoritmo
