Algoritmo sin_titulo
	N <- 0
	Anterior <- 1
	pasoNumero <- FALSO
	Mientras N<>Anterior Hacer
		Anterior <- N
		Leer N
		Si !pasoNumero Entonces
			Si N == 0 Entonces
				Anterior = 1
			FinSi
			pasoNumero <- VERDADERO
			max <- N
		FinSi
		Si N<>Anterior Entonces
			Si N>max Entonces
				max <- N
			FinSi
		FinSi
	FinMientras
	Escribir 'maximo: ',max
FinAlgoritmo
