Algoritmo sin_titulo
	pasoPositivo = 0
	cantTernasPos = 0
	negAnterior = 0
	pasoNegativo = 0
	cantTernasNeg = 0
	Para i<-1 Hasta 20 Hacer
		Leer num
		Si num > 0 Entonces
			pasoPositivo = pasoPositivo + 1
			Si pasoPositivo == 3 Entonces
				pasoPositivo = 0
				cantTernasPos = cantTernasPos + 1
			FinSi
		SiNo
			pasoPositivo = 0
		FinSi
		Si (num < 0) & (negAnterior == 0 | negAnterior < num) Entonces
			pasoNegativo = pasoNegativo + 1
			negAnterior = num
			Si pasoNegativo == 3 Entonces
				pasoNegativo = 0
				cantTernasNeg = cantTernasNeg + 1
			FinSi
		SiNo
			pasoNegativo = 0
		FinSi
	FinPara
	Escribir "Cantidad de ternas de valores positivos consecutivos: ", cantTernasPos
	Escribir "Cantidad de ternas de valores negativos consecutivos y ordenados de forma creciente: ", cantTernasNeg
FinAlgoritmo
