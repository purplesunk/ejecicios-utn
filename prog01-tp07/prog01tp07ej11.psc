Algoritmo sin_titulo
	dimension vac[10]
	Para i<-0 Hasta 9 Hacer
		Leer vac[i]
	FinPara
	Escribir sumaVector(vac,10)
FinAlgoritmo

Funcion R = sumaVector(vec, T)
	suma = 0
	Para i<-0 Hasta T-1 Hacer
		suma = suma + vec[i]
	FinPara
	R = suma
FinFuncion
