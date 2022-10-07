Algoritmo sin_titulo
	recaudoTotal <- 0
	recaudoPrimerQuincena <- 0
	cantChile <- 0
	cantBrasil <- 0
	cantPeru <- 0
	maxPasajesVendidos = 0
	Escribir 'NRO VENTA: '
	Leer nroVenta
	Mientras nroVenta<>0 Hacer
		Escribir 'NRO VUELO: '
		Leer nroVuelo
		Escribir 'DIA: '
		Leer dia
		Escribir 'CANTIDAD PASAJES: '
		Leer cantPasajes
		Segun nroVuelo  Hacer
			652:
				recaudacion <- 2500*cantPasajes
				cantChile <- cantChile+cantPasajes
			120:
				recaudacion <- 2800*cantPasajes
				cantBrasil <- cantBrasil+cantPasajes
			115:
				recaudacion <- 3200*cantPasajes
				cantPeru <- cantPeru+cantPasajes
		FinSegun
		recaudoTotal <- recaudoTotal+recaudacion
		Si dia<=15 Entonces
			recaudoPrimerQuincena <- recaudoPrimerQuincena+recaudacion
		FinSi
		Si cantPasajes > maxPasajesVendidos Entonces
			maxPasajesVendidos = cantPasajes
			maxDia = dia
		FinSi
		Escribir 'NRO VENTA: '
		Leer nroVenta
	FinMientras
	porcentajePrimerQuincena <- recaudoPrimerQuincena*100/recaudoTotal
	Escribir 'PORCENTAJE DE LA PRIMER QUINCENA ES: ',porcentajePrimerQuincena,'%'
	Si cantChile>cantBrasil Entonces
		destino <- 652
		maxCant <- cantChile
	SiNo
		destino <- 120
		maxCant <- cantBrasil
	FinSi
	Si cantPeru>maxCant Entonces
		destino <- 115
	FinSi
	Segun destino  Hacer
		652:
			Escribir 'EL DESTINO QUE MAS VIAJARON FUE: Santiago de Chile, Chile'
		120:
			Escribir 'EL DESTINO QUE MAS VIAJARON FUE: Rio de Janeiro, Brasil'
		115:
			Escribir 'EL DESTINO QUE MAS VIAJARON FUE: Lima, Perú'
	FinSegun
	Escribir "EL DIA CON LA MAYOR COMPRA FUE: ", maxDia
FinAlgoritmo
