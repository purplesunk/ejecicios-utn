Algoritmo sin_titulo
	N = 1
	primerNum = FALSO
	Mientras N<>0 Hacer
		Leer N
		Si !primerNum Entonces
			max = N
			segMax = N
			primerNum = VERDADERO
		SiNo
			Si N>max & N<>0 Entonces
				segMax = max
				max = N
			SiNo
				Si N>segMax & N<>0 Entonces
					segMax = N
				FinSi
			FinSi
		FinSi
	FinMientras
	Escribir "Maximo: ",max
	Escribir "Segundo Maximo: ",segMax
FinAlgoritmo
