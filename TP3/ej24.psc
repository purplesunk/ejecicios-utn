Algoritmo sin_titulo
	Leer num
	divisoresSuma <- 0
	Para i<-num-1 Hasta 1 Con Paso -1 Hacer
		Si num%i==0 Entonces
			divisoresSuma = divisoresSuma + i
		FinSi
	FinPara
	Si divisoresSuma == num Entonces
		Escribir num,' es n�mero perfecto'
	SiNo
		Escribir num,' no es n�mero perfecto'
	FinSi
FinAlgoritmo
