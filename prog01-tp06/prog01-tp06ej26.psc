Algoritmo sin_titulo
	Dimension importeXTarifa[20]
	Para i<-0 Hasta 19 Hacer
		Escribir 'Ingrese n�mero de tarifa: '
		Leer nroTarifa
		Escribir 'Ingrese importe por KM: '
		Leer importeKm
		indice <- nroTarifa-1
		importeXTarifa[indice] <- importeKm
	FinPara
	Escribir 'Ingreso de env�os realizados: '
	Dimension recaudoXTarifa[20]
	Para i<-0 Hasta 19 Hacer
		recaudoXTarifa[i] <- 0
	FinPara
	Dimension recaudoCamion[100]
	Dimension kmCamion[100]
	Para i<-0 Hasta 99 Hacer
		recaudoCamion[i] <- 0
		kmCamion[i] <- 0
	FinPara
	Escribir 'Ingrese n�mero de cami�n: '
	Leer nroCamion
	Mientras nroCamion>0 Hacer
		Escribir 'Ingrese n�mero de tarifa: '
		Leer nroTarifa
		Escribir 'Ingrese kil�metros recorridos: '
		Leer kmRecorridos
		iT <- nroTarifa-1
		iC <- nroCamion-1
		importe <- importeXTarifa[iT]*kmRecorridos
		recaudoXTarifa[iT] <- recaudoXTarifa[iT]+importe
		recaudoCamion[iC] <- recaudoCamion[iC]+importe
		kmCamion[iC] <- kmCamion[iC]+kmRecorridos
		Escribir 'Ingrese n�mero de cami�n: '
		Leer nroCamion
	FinMientras
	Escribir 'Total recaudado por tarifa: '
	Para i<-0 Hasta 19 Hacer
		Si i<9 Entonces
			Escribir 'Tarifa 0',i+1,': $',recaudoXTarifa[i]
		SiNo
			Escribir 'Tarifa ',i+1,': $',recaudoXTarifa[i]
		FinSi
	FinPara
	Escribir '--------------------------------------------'
	Escribir 'N�mero de cami�n	Total recaudado (en $)'
	Para i<-0 Hasta 99 Hacer
		Si recaudoCamion[i]<>0 Entonces
			Si i<9 Entonces
				Escribir ' 00',i+1,'			 ',recaudoCamion[i]
			SiNo
				Si i<99 Entonces
					Escribir ' 0',i+1,'			 ',recaudoCamion[i]
				SiNo
					Escribir ' ',i+1,'			 ',recaudoCamion[i]
				FinSi
			FinSi
		FinSi
	FinPara
	menorKmRecorridos = -1
	Para i<-0 Hasta 99 Hacer
		Si kmCamion[i] <> 0 Entonces
			Si (menorKmRecorridos == -1) | (kmCamion[i] < menorKmRecorridos) Entonces
				menorKmRecorridos = kmCamion[i]
				menorCamion = i+1
			FinSi
		FinSi
	FinPara
	Escribir "Camion que recorri� menos: ",menorCamion
FinAlgoritmo
