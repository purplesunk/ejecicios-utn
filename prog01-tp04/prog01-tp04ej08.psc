Algoritmo sin_titulo
	maxPar = 1
	N = 1
	Mientras N<>0 Hacer
		Leer N
		Si N % 2 == 0 Entonces
			Si (maxPar == 1 | N > maxPar) & N<>0 Entonces
				maxPar = N
			FinSi
		FinSi
	FinMientras
	Escribir maxPar
FinAlgoritmo
