Algoritmo sin_titulo
	dimension vNumeros[5]
	Para i<-0 Hasta 4 Hacer
		Leer vNumeros[i]
	FinPara
	dimension vResultado[9]
	Para i<-0 Hasta 4 Hacer
		ri = i*2
		vResultado[ri] = vNumeros[i]
		Si i>0 Entonces
			vResultado[ri-1] = (vResultado[ri]+vResultado[ri-2])/2
		FinSi
	FinPara
	Para i<-0 Hasta 8 Hacer
		Escribir "R",i+1,") ",vResultado[i]
	FinPara
FinAlgoritmo
