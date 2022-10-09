Algoritmo sin_titulo
	Dimension precioArticulo[25]
	Para i<-0 Hasta 24 Hacer
		Escribir 'Ingrese número de articulo: '
		Leer nroArticulo
		indice <- nroArticulo-1
		Escribir 'Precio unitario: '
		Leer precioArticulo[indice]
	FinPara
	Escribir 'Ingreso de ventas: '
	Dimension articulosVendidos[25]
	Para i<-0 Hasta 24 Hacer
		articulosVendidos[i] <- 0
	FinPara
	totalRecaudado <- 0
	Dimension cantVendidaXSucursal[5]
	Para i<-0 Hasta 4 Hacer
		cantVendidaXSucursal[i] <- 0
	FinPara
	Escribir 'Ingrese número de articulo: '
	Leer nroArticulo
	Mientras nroArticulo<>0 Hacer
		Escribir 'Ingrese número de sucursal: '
		Leer nroSucursal
		Escribir 'Ingrese cantidad vendida: '
		Leer cantVendida
		indice <- nroArticulo-1
		articulosVendidos[indice] <- articulosVendidos[indice]+cantVendida
		importe <- precioArticulo[indice]*cantVendida
		totalRecaudado <- totalRecaudado+importe
		s <- nroSucursal-1
		cantVendidaXSucursal[s] <- cantVendidaXSucursal[s]+cantVendida
		Escribir 'Ingrese número de articulo: '
		Leer nroArticulo
	FinMientras
	Escribir 'Cantidad vendida de cada artículo:'
	Para i<-0 Hasta 24 Hacer
			Escribir 'Articulo ',i+1,': ',articulosVendidos[i]
	FinPara
	Escribir 'Monto total recaudado: ',totalRecaudado
	maxCantVendXSuc <- 0
	Para i<-0 Hasta 4 Hacer
		Si cantVendidaXSucursal[i]>maxCantVendXSuc Entonces
			maxCantVendXSuc <- cantVendidaXSucursal[i]
			sucursalMasVendio <- i+1
		FinSi
	FinPara
	Escribir 'La sucursal que más artículos vendió: Sucursal ',sucursalMasVendio
FinAlgoritmo
