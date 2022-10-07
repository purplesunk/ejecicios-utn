Algoritmo sin_titulo
	caroClase1 <- 0
	precioC1 <- 0
	caroClase2 <- 0
	precioC2 <- 0
	caroClase3 <- 0
	precioC3 <- 0
	promClase1 <- 0
	promClase2 <- 0
	promClase3 <- 0
	cantC1 <- 0
	cantC2 <- 0
	cantC3 <- 0
	Para i<-1 Hasta 10 Hacer
		Escribir 'Ingrese número de artículo: '
		Leer numArt
		Escribir 'Ingrese precio unitario: '
		Leer precio
		Escribir 'Ingrese clase de articulo: (1, 2 o 3) '
		Leer clase
		Segun clase  Hacer
			1:
				cantC1 <- cantC1+1
				promClase1 <- promClase1+precio
				Si precio>precioC1 Entonces
					caroClase1 <- numArt
					precioC1 <- precio
				FinSi
			2:
				cantC2 <- cantC2+1
				promClase2 <- promClase2+precio
				Si precio>precioC2 Entonces
					caroClase2 <- numArt
					precioC2 <- precio
				FinSi
			3:
				cantC3 <- cantC3+1
				promClase3 <- promClase3+precio
				Si precio>precioC3 Entonces
					caroClase3 <- numArt
					precioC3 <- precio
				FinSi
		FinSegun
	FinPara
	Escribir "Artículo más caro de clase 1: ", caroClase1
	Escribir "Artículo más caro de clase 2: ", caroClase2
	Escribir "Artículo más caro de clase 3: ", caroClase3
	promClase1 = promClase1 / cantC1
	promClase2 = promClase2 / cantC2
	promClase3 = promClase3 / cantC3
	Si promClase1 > promClase2 Entonces
		Si promClase3 > promClase1 Entonces
			Escribir "Clase 3 mayor precio promedio."
		SiNo
			Escribir "Clase 1 mayor precio promedio."
		FinSi
	SiNo
		Si promClase3 > promClase2 Entonces
			Escribir "Clase 3 mayor precio promedio."
		SiNo
			Escribir "Clase 2 mayor precio promedio."
		FinSi
	FinSi
FinAlgoritmo
