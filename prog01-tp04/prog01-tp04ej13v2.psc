Algoritmo sin_titulo
	N <- 1
	ultImpar <- 0
	Mientras N<>0 Hacer
		Leer N
		Si N%2<>0 Entonces
			Si ultImpar == 0 Entonces
				ultImpar <- N
			SiNo
				anteUltImpar <- ultImpar
				ultImpar <- N
			FinSi
		FinSi
	FinMientras
	Escribir 'Anteultimo Impar: ',anteUltImpar
	Escribir 'Ultimo Impar: ',ultImpar
FinAlgoritmo
