Algoritmo sin_titulo
	N = 1
	primerImpar = 0
	segImpar = 0
	Mientras N<>0 Hacer
		Leer N
		Si N%2<>0 Entonces
			Si primerImpar == 0 Entonces
				primerImpar = N
			SiNo
				Si segImpar == 0 Entonces
					segImpar = N
				FinSi
			FinSi
		FinSi
	FinMientras
	Si primerImpar<>0 Entonces
		Escribir "Primer Impar: ",primerImpar
		Si segImpar <> 0 Entonces
			Escribir "Segundo Impar: ",segImpar
		SiNo
			Escribir "No se ingresó un segundo número Impar."
		FinSi
	SiNo
		Escribir "No se ingresó un número Impar."
	FinSi
FinAlgoritmo
