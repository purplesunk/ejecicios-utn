Algoritmo Playeros
	importeDia5 = 0
	Para i<-1 Hasta 5 Hacer
		combus3 = 0
		Escribir "NRO PLAYERO: "
		Leer nroPlayero
		Escribir "DIA: "
		Leer dia
		Mientras dia <> 0 Hacer
			Escribir "NRO COMBUSTIBLE: "
			Leer nroCombus
			Escribir "LITROS VENDIDOS: "
			Leer litrosVend
			Escribir "IMPORTE: "
			Leer importe
			Si nroCombus == 3 Entonces
				combus3 = combus3 + litrosVend
			FinSi
			Si dia == 5 Entonces
				importeDia5 = importeDia5 + importe
			FinSi
			Escribir "DIA: "
			Leer dia
		FinMientras
		Si combus3 < 2000 Entonces
			Escribir "EL PLAYERO NUMERO ",nroPlayero," NO VENDIO MAS DE 2000 LITROS"
		FinSi
	FinPara
	Escribir "IMPORTE TOTAL DEL DIA 5 FUE: $",importeDia5
FinAlgoritmo
