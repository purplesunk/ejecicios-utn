Algoritmo sin_titulo
	totalPos = 0
	Para grupo<-1 Hasta 10 Hacer
		Escribir "Inicio grupo ",grupo
		maxPar = 1
		maxImpar = 0
		cantNum = 0
		cantPos = 0
		cantNeg = 0
		Escribir "Ingrese n�mero: "
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
			Escribir "Ingrese n�mero: "
			Leer num
		FinMientras
		Escribir "Fin de grupo ",grupo
		Si cantNum <> 0 Entonces
			Escribir "Negativos: ",cantNeg*100/cantNum,"% / Positivos: ",cantPos*100/cantNum,"%"
		SiNo
			Escribir "No se ingresaron n�meros para este grupo"
		FinSi
		Si maxPar <> 1 Entonces
			Escribir "M�ximo par: ",maxPar
		FinSi
		Si maxImpar <> 0 Entonces
			Escribir "M�ximo impar: ",maxImpar
		FinSi
	FinPara
	Escribir "Total de n�meros positivos: ",totalPos
FinAlgoritmo
