Algoritmo Gentes_Flay
	pasajesVendidos <- 0
	registros <- 0
	mayorPasajeros <- 0
	avionMayorPasajeros <- 0
	Escribir "NRO AVION: "
	Leer nroAvion
	Mientras nroAvion<>0 Hacer
		Escribir "DIA Y CANTIDAD DE PASAJES VENDIDOS: "
		Leer diaVuelo,cantPasajes
		Si cantPasajes>mayorPasajeros Entonces
			mayorPasajeros <- cantPasajes
			avionMayorPasajeros <- nroAvion
		FinSi
		registros <- registros+1
		pasajesVendidos <- pasajesVendidos+cantPasajes
		Escribir "NRO AVION: "
		Leer nroAvion
	FinMientras
	Escribir 'EL AVION CON MAYOR CANTIDAD DE PASAJEROS ES EL ',avionMayorPasajeros
	Si registros<>0 Entonces
		Escribir 'EL PROMEDIO DE PASAJES ES: ',pasajesVendidos/registros
	FinSi
FinAlgoritmo
