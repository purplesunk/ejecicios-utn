Algoritmo sin_titulo
	Dimension libro[200,2]
	Para i<-0 Hasta 199 Hacer
		Escribir 'Ingrese código de libro: '
		Leer codLibro
		Escribir 'Ingrese tema: '
		Leer tema
		Escribir 'Ingrese precio: '
		Leer precio
		libro[codLibro-1,0]<-tema-1
		libro[codLibro-1,1]<-precio
	FinPara
	Escribir 'Segundo lote: '
	Dimension dias[31]
	Para i<-0 Hasta 30 Hacer
		dias[i] <- 0
	FinPara
	dimension recaudoVendedor[10]
	Para i<-0 Hasta 9 Hacer
		recaudoVendedor[i] = 0
	FinPara
	dimension cantTema[20]
	Para i<-0 Hasta 19 Hacer
		cantTema[i] = 0
	FinPara
	Escribir 'Ingrese código de libro: '
	Leer codLibro
	Mientras codLibro<>0 Hacer
		Escribir 'Número de vendedor: '
		Leer vendedor
		Escribir 'Día de venta: '
		Leer dia
		indice <- codLibro-1
		importe <- libro[indice,1]
		dias[dia-1]<-dias[dia-1]+importe
		recaudoVendedor[vendedor-1]=recaudoVendedor[vendedor-1]+importe
		cantTema[libro[indice,0]]=cantTema[libro[indice,0]] + 1
		Escribir 'Ingrese código de libro: '
		Leer codLibro
	FinMientras
	Escribir 'Recaudación total por días: '
	Para i<-0 Hasta 30 Hacer
		Escribir 'Día ',i+1,': ',dias[i]
	FinPara
	maxRecaudo = 0
	Para i<-0 Hasta 9 Hacer
		Si recaudoVendedor[i] > maxRecaudo Entonces
			maxRecaudo = recaudoVendedor[i]
			mayorVendedor = i+1
		FinSi
	FinPara
	Escribir "Vendedor con mayor recaudo total por ventas: Vendedor ", mayorVendedor
	maxTema = 0
	Para i<-0 Hasta 19 Hacer
		Si cantTema[i] > maxTema Entonces
			maxTema = cantTema[i]
			mayorTema = i+1
		FinSi
	FinPara
	Escribir "Tema más vendido: Tema ",mayorTema
FinAlgoritmo
