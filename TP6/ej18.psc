Algoritmo sin_titulo
	Dimension vDos[10]
	Dimension vUno[10]
	Dimension vTres[10]
	Escribir 'Primer Vector: '
	Para i<-0 Hasta 9 Hacer
		Leer vUno[i]
	FinPara
	Escribir 'Segundo Vector: '
	Para i<-0 Hasta 9 Hacer
		Leer vDos[i]
	FinPara
	repetidos <- 0
	Para i<-0 Hasta 9 Hacer
		Para j<-0 Hasta 9 Hacer
			Si vUno[i]==vDos[j] Entonces
				vTres[repetidos] <- vDos[j]
				repetidos <- repetidos+1
			FinSi
		FinPara
	FinPara
	repetidos = repetidos - 1
	Para i<-0 Hasta repetidos Hacer
		Escribir 'V03-',i+1,': ',vTres[i]
	FinPara
FinAlgoritmo
