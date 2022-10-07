Algoritmo sin_titulo
	Para i<-1 Hasta 3 Hacer
		Leer num;
		Si i == 1 Entonces
			mayor = num;
			medio = num;
		FinSi
		Si num > mayor Entonces
			medio = mayor;
			mayor = num;
		SiNo
			Si medio == mayor | num > medio Entonces
				medio = num;
			FinSi
		FinSi
	FinPara
	Escribir medio;
FinAlgoritmo
