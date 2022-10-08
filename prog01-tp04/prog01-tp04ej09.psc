Algoritmo sin_titulo
	Leer N
	max = N
	posicion = 1
	Mientras N <> 0 Hacer
		Leer N
		posicion = posicion + 1
		Si N > max & N<>0 Entonces
			max = N
			posMax = posicion
		FinSi
	FinMientras
	Escribir "El máximo ingresado fue: ",max, " y su posición fue: ",posMax
FinAlgoritmo
