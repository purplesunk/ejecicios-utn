Algoritmo sin_titulo
	diasCargados <- 0
	mayorRecaudo <- 0
	diaMayorR <- 0
	totalRecaudo <- 0
	Escribir 'Ingrese dia: '
	Leer dia
	Mientras dia<>0 & diasCargados<31 Hacer
		Si dia>0 & dia<=31 Entonces
			Escribir 'recaudacion: '
			Leer recaudo
			totalRecaudo <- totalRecaudo+recaudo
			Si diasCargados==0 | recaudo>mayorRecaudo Entonces
				mayorRecaudo <- recaudo
				diaMayorR <- dia
			FinSi
			diasCargados <- diasCargados+1
		FinSi
		Escribir 'Ingrese dia: '
		Leer dia
	FinMientras
	Escribir 'EL DIA QUE MAS SE RECAUDO FUE EL ',diaMayorR
	Escribir 'LA RECAUDACION TOTAL FUE $',totalRecaudo
	Escribir 'EL PORCENTAJE DE DIAS TRABAJADOS ES ',diasCargados*100/31,'%'
FinAlgoritmo
