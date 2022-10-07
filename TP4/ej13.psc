Algoritmo sin_titulo
	N = 1
	pasoImpar = FALSO
	Mientras N<>0 Hacer
		Leer N
		Si N%2<>0 Entonces
			Si !pasoImpar Entonces
				ultImpar = N
				pasoImpar = VERDADERO
			SiNo
				anteUltImpar = ultImpar
				ultImpar = N
			FinSi
		FinSi
	FinMientras
	Escribir "Anteultimo Impar: ", anteUltImpar
	Escribir "Ultimo Impar: ", ultImpar
FinAlgoritmo
