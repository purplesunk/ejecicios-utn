Algoritmo sin_titulo
	Dimension max[10]
	Para i<-0 Hasta 9 Hacer
		Escribir "Grupo ",i+1
		Leer num
		mayor = num
		Mientras num <> 0 Hacer
			Si num > mayor Entonces
				mayor = num
			FinSi
			Leer num
		FinMientras
		max[i] = mayor
	FinPara
	Escribir "Valores máximos de cada grupo: "
	Para i<-0 Hasta 9 Hacer
		Escribir "Grupo ",i+1,": ",max[i]
	FinPara
FinAlgoritmo
