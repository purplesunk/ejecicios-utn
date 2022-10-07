Algoritmo sin_titulo
	min = 0
	max = 0
	N = 1
	Mientras N <> 0 Hacer
		Leer N
		Si N > 0 Entonces
			Si N < min | min == 0 Entonces
				min = N
			FinSi
		FinSi
		Si N < 0 Entonces
			Si N > max | max == 0 Entonces
				max = N
			FinSi
		FinSi
	FinMientras
	Si min <> 0 Entonces
		Escribir "Mínimo de los positivos: ", min
	SiNo
		Escribir "No se ingresaron positivos"
	FinSi
	Si max <> 0 Entonces
		Escribir "Máximo de los negativos: ", max
	SiNo
		Escribir "No se ingresaron negativos"
	FinSi
FinAlgoritmo
