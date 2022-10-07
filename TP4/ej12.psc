Algoritmo sin_titulo
	primerImpar = 0
	ultImpar = 0
	N = 1
	Mientras N <> 0 Hacer
		Leer N
		Si N%2<>0 Entonces
			Si primerImpar = 0 Entonces
				primerImpar = N
				ultImpar = N
			SiNo
				ultImpar = N
			FinSi
		FinSi
	FinMientras
	Escribir "Primer Impar: ", primerImpar
	Escribir "Último Impar: ", ultImpar
FinAlgoritmo
