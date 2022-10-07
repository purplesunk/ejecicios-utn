Algoritmo sin_titulo
	N = 1
	Ordenados = VERDADERO
	Primer = FALSO
	Mientras N<>0 Hacer
		Leer N
		Si !Primer Entonces
			Primer = VERDADERO
			Anterior = N
		SiNo
			Si N < Anterior & N <> 0 Entonces
				Ordenados = FALSO
			FinSi
		FinSi
	FinMientras
	Si Ordenados Entonces
		Escribir "Conjunto Ordenado"
	SiNo
		Escribir "Conjunto Desordenado"
	FinSi
FinAlgoritmo
