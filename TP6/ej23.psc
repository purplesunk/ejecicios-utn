Algoritmo sin_titulo
	Dimension articulos[20]
	Dimension diaSinVentas[31]
	Para i<-0 Hasta 19 Hacer
		articulos[i] <- 0
	FinPara
	Para i<-0 Hasta 30 Hacer
		diaSinVentas[i] <- verdadero
	FinPara
	totalCant <- 0
	ventas <- 0
	Escribir 'Ingrese numero de articulo: '
	Leer nroArticulo
	Mientras nroArticulo<>0 Hacer
		Escribir 'Ingrese dia: '
		Leer dia
		Escribir 'Ingrese cantidad vendida: '
		Leer cantVendida
		ventas <- ventas+1
		totalCant <- totalCant+cantVendida
		indice <- nroArticulo-1
		articulos[indice] = articulos[indice] + cantVendida
		diaSinVentas[dia-1]<-falso
		Escribir 'Ingrese numero de articulo: '
		Leer nroArticulo
	FinMientras
	Escribir 'Cantidad total vendida por articulo: '
	hayNoVendido <- falso
	Para i<-0 Hasta 19 Hacer
		Si articulos[i]<>0 Entonces
			Escribir 'Articulo ',i+1,': ',articulos[i]
		SiNo
			hayNoVendido <- verdadero
		FinSi
	FinPara
	Si hayNoVendido Entonces
		Escribir 'Los demás no se vendieron'
	FinSi
	Escribir 'Dias que no hubo ventas: '
	Para i<-0 Hasta 30 Hacer
		Si diaSinVentas[i] Entonces
			Escribir 'Dia ',i+1
		FinSi
	FinPara
	promedio <- totalCant/ventas
	Escribir 'Articulos cuyas ventas son mayores al promedio: '
	Para i<-0 Hasta 19 Hacer
		Si articulos[i]>promedio Entonces
			Escribir 'Articulo ',i+1
		FinSi
	FinPara
FinAlgoritmo
