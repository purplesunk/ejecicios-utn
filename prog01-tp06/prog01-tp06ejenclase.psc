Algoritmo sin_titulo
	Dimension vMes[12]
	Para i<-0 Hasta 11 Hacer
		vMes[i] <- 0
	FinPara
	Escribir 'Mes: '
	Leer mes
	Mientras mes <> 0 Hacer
		Escribir 'dia: '
		Leer dia
		Escribir 'importe: '
		Leer importe
		vMes[mes-1]<-vMes[mes-1]+importe
		Escribir 'Mes: '
		Leer mes
	FinMientras
	Para i<-0 Hasta 11 Hacer
		Escribir "Mes ",i+1,": ",vMes[i]
	FinPara
FinAlgoritmo
