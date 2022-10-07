Algoritmo sin_titulo
	Dimension vNumeros[10]
	Para i<-0 Hasta 9 Hacer
		Leer vNumeros[i]
	FinPara
	primos <- 0
	Para i<-0 Hasta 9 Hacer
		divisores <- 0
		divisor <- 2
		Si vNumeros[i]<2 Entonces
			divisores <- 1
		FinSi
		Mientras divisores==0 & divisor<vNumeros[i] Hacer
			Si vNumeros[i]%divisor==0 Entonces
				divisores <- divisores+1
			FinSi
			divisor <- divisor+1
		FinMientras
		Si divisores==0 Entonces
			primos <- primos+1
		FinSi
	FinPara
	Escribir 'Hay ',primos,' números primos.'
	primos <- 0
	Para i<-0 Hasta 9 Hacer
		divisores <- 0
		divisor <- 2
		Si vNumeros[i]<2 Entonces
			divisores <- 1
		FinSi
		Mientras divisores==0 & divisor<vNumeros[i] Hacer
			Si vNumeros[i]%divisor==0 Entonces
				divisores <- divisores+1
			FinSi
			divisor <- divisor+1
		FinMientras
		Si divisores==0 Entonces
			primos <- primos+1
			Escribir primos,") ",vNumeros[i]
		FinSi
	FinPara
FinAlgoritmo
