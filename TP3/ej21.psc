Algoritmo sin_titulo
	Leer num
	Escribir 'los divisores pares de ',num,' son: '
	Para i<-num Hasta 2 Con Paso -1 Hacer
		Si num%i==0 & i%2==0 Entonces
			Escribir i
		FinSi
	FinPara
FinAlgoritmo
