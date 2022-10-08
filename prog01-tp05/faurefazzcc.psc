Algoritmo Registro_Faurefazz
	menos15Paq = 0
	trabajoSolo15 = 0
	Escribir "NRO CAMION: "
	Leer nroCamion
	Mientras nroCamion <> 0 Hacer
		nroCamionAnt = nroCamion
		soloPrimerQuin = verdadero
		Mientras nroCamion == nroCamionAnt Hacer
			Escribir "DIA: "
			Leer dia
			Escribir "CANTIDAD PAQUETES ENVIADOS: "
			Leer cantPaquetes
			Si cantPaquetes < 15 Entonces
				menos15Paq = menos15Paq + 1
			FinSi
			Si dia > 15 Entonces
				soloPrimerQuin = falso
			FinSi
			Escribir "NRO CAMION: "
			Leer nroCamion
		FinMientras
		Si soloPrimerQuin Entonces
			trabajoSolo15 = trabajoSolo15 + 1
		FinSi
	FinMientras
	Escribir "LA CANTIDAD DE ENVIOS CON MENOS DE 15 PAQUETES FUERON: ", menos15Paq
	Escribir "LA CANTIDAD DE CAMIONES QUE TRABAJARON SOLO LA PRIMER QUINCENA FUERON: ", trabajoSolo15
FinAlgoritmo
