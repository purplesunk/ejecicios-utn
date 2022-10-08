Algoritmo sin_titulo
	primerParCheck <- 0
	Para m<-1 Hasta 7 Hacer
		Leer num
		Si num%2==0 & primerParCheck==0 Entonces
			primerParCheck <- 1
			primerPar <- num
			parUbi = m
		FinSi
		divisores <- 0
		Para i<-num Hasta 1 Con Paso -1 Hacer
			Si num%i==0 Entonces
				divisores <- divisores+1
			FinSi
		FinPara
		Si divisores==2 Entonces
			ultimoPrimo <- num
			primoUbi = m
		FinSi
	FinPara
	Escribir 'primer par: ',primerPar, " ubicación: ", parUbi
	Escribir 'último primo: ',ultimoPrimo , " ubicación: ", primoUbi
FinAlgoritmo
