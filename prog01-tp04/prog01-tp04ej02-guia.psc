Algoritmo sin_titulo
	N = 1
	Pos = 0
	Neg = 0
	Mientras N<>0 Hacer
		Leer N
		Si N>0 Entonces
			Pos = Pos + 1
		FinSi
		Si N<0 Entonces
			Neg = Neg + 1
		FinSi
	FinMientras
	Escribir "Positivos: ",Pos, " / Negativos: ", Neg
FinAlgoritmo
