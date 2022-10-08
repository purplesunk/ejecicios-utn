Algoritmo sin_titulo
	grupoMin = 0
	posMin = 0
	valorMin = 0
	mayorProm = 0
	grupoProm = 0
	Para g<-1 Hasta 10 Hacer
		promedio = 0
		cantNum = 0
		Escribir "Ingrese número: "
		Leer N
		Mientras N<>0 Hacer
			cantNum = cantNum + 1
			promedio = promedio + N
			Si (grupoMin == 0) | (N < valorMin) Entonces
				grupoMin = g
				posMin = cantNum
				valorMin = N
			FinSi
			Escribir "Ingrese número: "
			Leer N
		FinMientras
		Si cantNum <> 0 Entonces
			promedio = promedio / cantNum
			Escribir "Promedio de grupo ",g,": ", promedio
			Si (grupoProm == 0) | (promedio>mayorProm) Entonces
				grupoProm = g
				mayorProm = promedio
			FinSi
		FinSi
	FinPara
	Escribir "Valor mínimo de todos los grupos: ",valorMin
	Escribir "Grupo: ",grupoMin
	Escribir "Posición: ", posMin
	Escribir "Mayor promedio: ",mayorProm
	Escribir "Grupo: ",grupoProm
FinAlgoritmo
