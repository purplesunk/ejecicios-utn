Algoritmo sin_titulo
	rupturas = 0
	Dimension vNumeros[20]
	Para i<-0 Hasta 19 Hacer
		Leer vNumeros[i]
	FinPara
	Para i<-1 Hasta 19 Hacer
		Si vNumeros[i]<=vNumeros[i-1] Entonces
			rupturas = rupturas + 1
		FinSi
	FinPara
	Escribir rupturas
FinAlgoritmo
