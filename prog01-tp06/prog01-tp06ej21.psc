Algoritmo sin_titulo
	Dimension articulos[20]
	Para i<-0 Hasta 19 Hacer
		articulos[i] <- 0
	FinPara
	Escribir 'Ingrese número de articulo: '
	Leer nroArticulo
	Mientras nroArticulo<>0 Hacer
		Escribir 'Ingrese cantidad vendida: '
		Leer cantVendida
		indice <- nroArticulo-1
		articulos[indice] <- articulos[indice]+cantVendida
		Escribir 'Ingrese número de articulo: '
		Leer nroArticulo
	FinMientras
	cantMaxVendida <- 0
	Dimension noVendidos[20]
	cantSinVender <- -1
	Para i<-0 Hasta 19 Hacer
		Si articulos[i]>cantMaxVendida Entonces
			cantMaxVendida <- articulos[i]
			masVendido <- i+1
		FinSi
		Si articulos[i]==0 Entonces
			cantSinVender <- cantSinVender+1
			noVendidos[cantSinVender] <- i+1
		FinSi
	FinPara
	Escribir 'El articulo que más se vendió en total fue ',masVendido
	Escribir 'Artículos que no registraron ventas: '
	Para i<-0 Hasta cantSinVender Hacer
		Escribir noVendidos[i]
	FinPara
	Escribir "Unidades vendidas del articulos 10: ",articulos[9]
FinAlgoritmo
