Algoritmo sin_titulo
	Dimension vendedor[15]
	totalRecaudo = 0
	Para i<-0 Hasta 14 Hacer
		vendedor[i] <- 0
	FinPara
	Escribir 'Ingrese número de vendedor: '
	Leer nroVendedor
	Mientras nroVendedor<>0 Hacer
		Escribir 'Ingrese importe de la venta: '
		Leer importe
		totalRecaudo = totalRecaudo + importe
		indice <- nroVendedor-1
		vendedor[indice] <- vendedor[indice]+importe
		Escribir 'Ingrese número de vendedor: '
		Leer nroVendedor
	FinMientras
	maxRecaudo <- 0
	Para i<-0 Hasta 14 Hacer
		Si vendedor[i] > maxRecaudo Entonces
			maxRecaudo <- vendedor[i]
			masVendio = i+1
		FinSi
	FinPara
	Escribir "El vendedor que vendió más en total es: Vendedor ",masVendio
	Escribir "No realizaron ventas: "
	Para i<-0 Hasta 14 Hacer
		Si vendedor[i] == 0 Entonces
			Escribir "Vendedor ",i+1
		FinSi
	FinPara
	Escribir "Total recaudado por la empresa: ",totalRecaudo
FinAlgoritmo
