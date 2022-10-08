Algoritmo sin_titulo
	N = 0
	primerNum = FALSO
	Anterior = 1
	numNeg = 0
	numPos = 0
	Mientras N <> Anterior Hacer
		Si N == 0 & !primerNum Entonces
			primerNum = VERDADERO
			Anterior = 1
		SiNo
			Anterior = N
		FinSi
		Leer N
		Si N <> Anterior Entonces
			Si N > 0 Entonces
				numPos = numPos + 1
			FinSi
			Si N < 0 Entonces
				numNeg = numNeg + 1
			FinSi
		FinSi
	FinMientras
	total = numNeg + numPos
	Si total <> 0 Entonces
		numNeg = numNeg * 100 / total
		numPos = numPos * 100 / total
		Escribir "Positivos: ",numPos,"% / Negativos: ", numNeg,"%"
	SiNo
		Escribir "no se ingresaron numeros positivos o negativos"
	FinSi
FinAlgoritmo
