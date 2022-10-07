Algoritmo sin_titulo
	num = 1
	PrimerPar = 0
	SegundoPar = 0
	Mientras num<>0 Hacer
		Leer num
		Si num%2==0 & num>0 Entonces
			Si PrimerPar == 0 Entonces
				PrimerPar = num
			SiNo
				Si SegundoPar == 0 Entonces
					SegundoPar = num
				FinSi
			FinSi
		FinSi
	FinMientras
	Si PrimerPar > 0 Entonces
		Escribir "Primer par positivo : ", PrimerPar
		Si SegundoPar > 0 Entonces
			Escribir "Segundo par positivo : ", SegundoPar
		SiNo
			Escribir "No se ingresó un segundo par."
		FinSi
	SiNo
		Escribir "No se ingresaron número pares."
	FinSi
FinAlgoritmo
