Algoritmo sin_titulo
	Leer N
	max = N
	min = N
	Mientras N <> 0 Hacer
		Leer N
		Si N <> 0 Entonces
			Si N > max Entonces
				max = N
			SiNo
				Si N < min Entonces
					min = N
				FinSi
			FinSi
		FinSi
	FinMientras
	Escribir "máximo: ", max
	Escribir "mínimo: ", min
FinAlgoritmo
