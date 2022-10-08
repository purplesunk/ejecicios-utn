Algoritmo sin_titulo
	totalPos = 0
	Para grupo<-1 Hasta 10 Hacer
		Escribir "Inicio grupo ",grupo
		maxPar = 1
		maxImpar = 0
		cantNum = 0
		cantPos = 0
		cantNeg = 0
		Escribir "Ingrese número: "
		Leer num
		Mientras num <> 0 Hacer
			Si num % 2 == 0 Entonces
				Si (maxPar == 1) | (num > maxPar) Entonces
					maxPar = num
				FinSi
			SiNo
				Si (maxImpar == 0) | (num > maxImpar)  Entonces
					maxImpar = num
				FinSi
			FinSi
			cantNum = cantNum + 1
			Si num > 0 Entonces
				cantPos = cantPos + 1
				totalPos = totalPos + 1
			SiNo
				cantNeg = cantNeg + 1
			FinSi
			Escribir "Ingrese número: "
			Leer num
		FinMientras
		Escribir "Fin de grupo ",grupo
		Si cantNum <> 0 Entonces
			Escribir "Negativos: ",cantNeg*100/cantNum,"% / Positivos: ",cantPos*100/cantNum,"%"
		SiNo
			Escribir "No se ingresaron números para este grupo"
		FinSi
		Si maxPar <> 1 Entonces
			Escribir "Máximo par: ",maxPar
		FinSi
		Si maxImpar <> 0 Entonces
			Escribir "Máximo impar: ",maxImpar
		FinSi
	FinPara
	Escribir "Total de números positivos: ",totalPos
FinAlgoritmo
