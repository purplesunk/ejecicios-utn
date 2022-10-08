Algoritmo sin_titulo
	totalRecaudado <- 0
	vehiculosNoTrabajados <- 0
	kmTrabajadosEl20 <- 0
	masCantidadKm <- 0
	Escribir 'CODIGO VEHICULO: '
	Leer codVehiculo
	Mientras codVehiculo<>0 Hacer
		vehiculoAnt = codVehiculo
		trabajoTodoMes <- verdadero
		kmPorVehiculo <- 0
		Mientras codVehiculo == vehiculoAnt Hacer
			Escribir 'DIA: '
			Leer dia
			Escribir 'TIPO VEHICULO: '
			Leer tipoV
			Escribir 'MEDICIÓN EN KM (COMIENZO): '
			Leer kmInicio
			Escribir 'MEDICIÓN EN KM (FINAL): '
			Leer kmFinal
			kmTrabajados <- kmFinal-kmInicio
			kmPorVehiculo <- kmPorVehiculo+kmTrabajados
			Si kmTrabajados==0 Entonces
				trabajoTodoMes <- falso
			FinSi
			Si dia==20 Entonces
				kmTrabajadosEl20 <- kmTrabajadosEl20+kmTrabajados
			FinSi
			Si tipoV==1 Entonces
				recaudo <- kmTrabajados*60
			SiNo
				recaudo <- kmTrabajados*90
			FinSi
			totalRecaudado <- totalRecaudado+recaudo
			Escribir 'CODIGO VEHICULO: '
			Leer codVehiculo
		FinMientras
		Si !trabajoTodoMes Entonces
			vehiculosNoTrabajados <- vehiculosNoTrabajados+1
		FinSi
		Si kmPorVehiculo>masCantidadKm Entonces
			masCantidadKm = kmPorVehiculo
			vehiculoMasAndado = vehiculoAnt
		FinSi
	FinMientras
	Escribir 'LA CANTIDAD DE VEHICULOS QUE NO TRABAJARON FUERON: ',vehiculosNoTrabajados
	Escribir 'LA CANTIDAD DE KILOMETROS DEL DIA 20 FUERON: ',kmTrabajadosEl20
	Escribir 'LA RECAUDACION TOTAL FUE: $',totalRecaudado
	Escribir "EL VEHICULO QUE MAS KILOMETROS HIZO FUE: ", vehiculoMasAndado
FinAlgoritmo
