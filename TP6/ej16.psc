Algoritmo sin_titulo
	dimension num[10]
	hayRepetidos = falso
	Para i<-0 Hasta 9 Hacer
		Leer num[i]
	FinPara
	Para i<-0 Hasta 9 Hacer
		Para j<-0 Hasta 9 Hacer
			Si num[i]==num[j] & i<>j Entonces
				hayRepetidos = verdadero
			FinSi
		FinPara
	FinPara
	Si hayRepetidos Entonces
		Escribir "Hay repetidos"
	FinSi
FinAlgoritmo
