Algoritmo sin_titulo
	factura = -1
	litrosArt1 = 0
	totalfac = 0
	mas3000 = 0
	Mientras factura <> 0 Hacer
		Escribir "ingrese num factura: "
		Leer factura
		Si factura > 0 Entonces
			Escribir "ingrese num articulo: "
			Leer articulo
			Escribir "cant de litos: "
			Leer litros
			Escribir "precio: "
			Leer precio
			totalfac = totalfac + precio
			Si articulo == 1 Entonces
				litrosArt1 = litrosArt1 + litros
			FinSi
			Si precio > 3000 Entonces
				mas3000 = mas3000 + 1
			FinSi
		FinSi
	FinMientras
	Escribir "total facturado ", totalfac
	Escribir "litros vendidos de art1: ",litrosArt1
	Escribir "facturaciones de mas de 3000: ",mas3000
FinAlgoritmo
