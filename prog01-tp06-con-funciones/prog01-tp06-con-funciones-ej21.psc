Algoritmo sin_titulo
	Dimension cantVendidaArticulo[20]
	vectorEnCero(cantVendidaArticulo,20)
	nroArticulo <- ingresarNroArticulo()
	Mientras nroArticulo<>0 Hacer
		cantVendida <- ingresarCantVendida()
		acumularDatoVector(cantVendidaArticulo,nroArticulo,cantVendida)
		nroArticulo <- ingresarNroArticulo()
	FinMientras
	Escribir 'El articulo que más se vendio en total fue: Articulo ',posMax(cantVendidaArticulo,20)
	articulosSinVentas(cantVendidaArticulo,20)
	Escribir "Unidades vendidas por el articulo 10: ",cantVendidaArticulo[9]
FinAlgoritmo

Funcion R = ingresarNroArticulo()
	Escribir 'Ingrese número de Articulo: '
	Leer R
FinFuncion

Funcion R = ingresarCantVendida()
	Escribir 'Ingrese cantidad vendida: '
	Leer R
FinFuncion

Funcion acumularDatoVector(vec,pos,dato)
	i <- pos-1
	vec[i] <- vec[i]+dato
FinFuncion

Funcion mostrarVector(vec,tam)
	Para i<-0 Hasta tam-1 Hacer
		Escribir vec[i]
	FinPara
FinFuncion

Funcion vectorEnCero(vec,tam)
	Para i<-0 Hasta tam-1 Hacer
		vec[i] <- 0
	FinPara
FinFuncion

Funcion pos = posMax(vec,tam)
	max <- vec[0]
	pos <- 1
	Para i<-1 Hasta tam-1 Hacer
		Si vec[i]>max Entonces
			max <- vec[i]
			pos <- i+1
		FinSi
	FinPara
FinFuncion

Funcion articulosSinVentas(vec,tam)
	Escribir 'Los articulos que no se vendieron son: '
	Para i<-0 Hasta tam-1 Hacer
		Si vec[i]==0 Entonces
			Escribir 'Articulo ',i+1
		FinSi
	FinPara
FinFuncion
