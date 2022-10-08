Algoritmo sin_titulo
	primoCheck = 0
	ordenCheck = 1
	anterior = 0
	actual = 0
	Para i<-1 Hasta 7 Hacer
		Leer num
		divisor = 0
		Para p<-num Hasta 1 Con Paso -1 Hacer
			Si num % p == 0 Entonces
				divisor = divisor + 1
			FinSi
		FinPara
		Si divisor == 2 Entonces
			Si primoCheck == 0 Entonces
				anterior = num
				primoCheck = 1
			SiNo
				anterior = actual
				actual = num
				Si anterior > actual Entonces
					ordenCheck = 0
				FinSi
			FinSi
		FinSi
	FinPara
	Si ordenCheck == 1 Entonces
		Escribir "Ordenados"
	SiNo
		Escribir "No ordenados"
	FinSi
FinAlgoritmo
