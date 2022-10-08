Algoritmo sin_titulo
	Leer num
	divisores <- 0
	Para i<-num Hasta 1 Con Paso -1 Hacer
		Si num%i==0 Entonces
			divisores <- divisores+1
		FinSi
	FinPara
	Si divisores == 2 Entonces
		Escribir num, " es primo"
	SiNo
		Escribir num, " no es primo"
	FinSi
FinAlgoritmo
