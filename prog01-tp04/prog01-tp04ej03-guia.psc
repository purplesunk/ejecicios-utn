Algoritmo sin_titulo
	N = -1
	mayor = 0
	Mientras N < 0 Hacer
		Leer N
		Si N < 0 Entonces
			Si mayor == 0 | N > mayor Entonces
				mayor = N
			FinSi
		FinSi
	FinMientras
	Escribir mayor
FinAlgoritmo
