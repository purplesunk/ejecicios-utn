Algoritmo sin_titulo
	medioCheck = 0
	Para i<-1 Hasta 5 Hacer
		Leer num
		Si i==1 Entonces
			mayor <- num
			medio <- num
		SiNo
			Si num>mayor Entonces
				medio <- mayor
				mayor <- num
			SiNo
				Si (medio==mayor & medioCheck == 0) | (num > medio) Entonces
					medioCheck = medioCheck + 1
					medio <- num
				FinSi
			FinSi
		FinSi
	FinPara
	Escribir 'Máximo: ',mayor
	Escribir 'Medio: ',medio
FinAlgoritmo
