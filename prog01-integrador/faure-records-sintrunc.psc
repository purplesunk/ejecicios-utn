Algoritmo sin_titulo
	maxDuracionDisco <- 0
	totalVinilos <- 0
	suma2020 <- 0
	cant2020 <- 0
	Escribir 'NRO DISCO: '
	Leer nroDisco
	Mientras nroDisco>=0 Hacer
		nroDiscoAnt <- nroDisco
		duracionDisco <- 0
		cantSegundos = 0
		lado = 0
		vinilo = 1
		Mientras nroDisco==nroDiscoAnt Hacer
			Escribir 'NRO CANCION: '
			Leer nroCancion
			Escribir 'DURACION: '
			Leer duracion
			Escribir 'AÑO CANCION: '
			Leer lanzamiento
			duracionDisco <- duracionDisco+duracion
			cantSegundos <- cantSegundos+duracion
			Si cantSegundos > 1800 Entonces
				cantSegundos <- duracion
				lado = lado + 1
			FinSi
			Si lado == 2 Entonces
				lado = 0
				vinilo = vinilo + 1
			FinSi
			Si lanzamiento==2020 Entonces
				suma2020 <- suma2020+duracion
				cant2020 <- cant2020+1
			FinSi
			Escribir 'NRO DISCO: '
			Leer nroDisco
		FinMientras
		totalVinilos = totalVinilos + vinilo
		Si duracionDisco>maxDuracionDisco Entonces
			maxDuracionDisco <- duracionDisco
			discoMasLargo <- nroDiscoAnt
		SiNo
			Si (duracionDisco==maxDuracionDisco) & (nroDiscoAnt<discoMasLargo) Entonces
				discoMasLargo <- nroDiscoAnt
			FinSi
		FinSi
	FinMientras
	Escribir 'EL DISCO MAS LARGO ES: ',discoMasLargo
	Escribir 'LA CANTIDAD DE VINILOS SON: ',totalVinilos
	Si cant2020<>0 Entonces
		promedio2020 <- suma2020/cant2020
		Escribir 'EL PROMEDIO DE LAS CANCIONES DEL 2020 ES: ',promedio2020
	FinSi
FinAlgoritmo
