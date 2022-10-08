Algoritmo sin_titulo
	num = 1
	cantPos = 0
	cantNeg = 0
	promPos = 0
	promNeg = 0
	Mientras num%2<>0 Hacer
		Leer num
		Si num%2<>0 Entonces
			Si num<0 Entonces
				cantNeg = cantNeg + 1
				promNeg = promNeg + num
			SiNo
				cantPos = cantPos + 1
				promPos = promPos + num
			FinSi
		FinSi
	FinMientras
	Si cantPos > 0 Entonces
		Escribir "Promedio Positivos: ", promPos / cantPos
	FinSi
	Si cantNeg > 0 Entonces
		Escribir "Promedio Negativos: ", promNeg / cantNeg
	FinSi
FinAlgoritmo
