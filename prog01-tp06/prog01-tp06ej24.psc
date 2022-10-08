Algoritmo sin_titulo
	Dimension precioPlan[3,2]
	Para i<-0 Hasta 2 Hacer
		Escribir 'Ingrese numero de plan: '
		Leer nroPlan
		Escribir 'Ingrese precio al contado'
		Leer contado
		Escribir 'Ingrese precio con tarjeta'
		Leer tarjeta
		precioPlan[nroPlan-1,0]<-contado
		precioPlan[nroPlan-1,1]<-tarjeta
	FinPara
	Escribir 'SEGUNDA PARTE'
	Dimension totalRecaudo[2]
	Para i<-0 Hasta 1 Hacer
		totalRecaudo[i] <- 0
	FinPara
	Dimension planElegido[3]
	Para i<-0 Hasta 2 Hacer
		planElegido[i] <- 0
	FinPara
	dimension planNoVendidoXLocal[8,3]
	Para i<-0 Hasta 7 Hacer
		Para j<-0 Hasta 2 Hacer
			planNoVendidoXLocal[i,j] = verdadero
		FinPara
	FinPara
	Escribir 'Ingrese nro de local: '
	Leer nroLocal
	Mientras nroLocal<>9 Hacer
		Escribir 'Ingrese nro de plan contratado: '
		Leer nroPlan
		Escribir 'Ingrese cantidad de personas: '
		Leer cantPersonas
		Escribir 'Ingrese método de pago: '
		Leer codPago
		nroLocal = nroLocal -1
		nroPlan <- nroPlan-1
		codPago <- codPago-1
		importe <- precioPlan[nroPlan,codPago]*cantPersonas
		totalRecaudo[codPago] <- totalRecaudo[codPago]+importe
		planElegido[nroPlan] <- planElegido[nroPlan]+cantPersonas
		planNoVendidoXLocal[nroLocal,nroPlan] = falso
		Escribir 'Ingrese nro de local: '
		Leer nroLocal
	FinMientras
	Escribir 'Total recaudado al contado: ',totalRecaudo[0]
	Escribir 'Total recaudado con tarjeta: ',totalRecaudo[1]
	maxPersonasEligieron = 0
	Para i<-0 Hasta 2 Hacer
		Si planElegido[i] >= maxPersonasEligieron Entonces
			maxPersonasEligieron = planElegido[i]
			masElegido = i+1
		FinSi
	FinPara
	Escribir "Plan mas elegido: Plan ",masElegido
	Para i<-0 Hasta 7 Hacer
		hayPlanSinVender = falso
		Para j<-0 Hasta 2 Hacer
			Si planNoVendidoXLocal[i,j] Entonces
				hayPlanSinVender = verdadero
			FinSi
		FinPara
		Si hayPlanSinVender Entonces
			Escribir "Planes sin vender en el Local ",i+1,": "
		FinSi
		Para j<-0 Hasta 2 Hacer
			Si planNoVendidoXLocal[i,j] Entonces
				Escribir "Plan ",j+1
			FinSi
		FinPara
	FinPara
FinAlgoritmo
