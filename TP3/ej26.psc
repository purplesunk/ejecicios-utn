Algoritmo sin_titulo
	prevImpar = 0
	duplasConsec = 0
	Para n<-1 Hasta 10 Hacer
		Leer num
		Si num % 2 <> 0 Entonces
			Si prevImpar == 0 Entonces
				prevImpar = 1
			SiNo
				duplasConsec = duplasConsec + 1
			FinSi
		SiNo
			prevImpar = 0
		FinSi
	FinPara
	Escribir "hay ",duplasConsec, " duplas de numeros impares consecutivas"
FinAlgoritmo
