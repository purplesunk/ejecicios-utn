Algoritmo sin_titulo
	Pos = 0
	Neg = 0
	Repetir
		Leer N
		Si N > 0 Entonces
			Pos = Pos + 1
		SiNo
			Si N < 0 Entonces
				Neg = Neg + 1
			FinSi
		FinSi
	Mientras Que N<>0
	Escribir "Positivos: ", Pos
	Escribir "Negativos: ", Neg
FinAlgoritmo
