Algoritmo sin_titulo
	bisiestos = 0
	Para i<-1 Hasta 10 Hacer
		Leer anio
		Si esBisiesto(anio) Entonces
			bisiestos = bisiestos+1
		FinSi
	FinPara
	Escribir "bisiestos: ",bisiestos
FinAlgoritmo

Funcion R = esBisiesto(year)
	R = falso
	Si year%4==0 & year%100<>0 Entonces
		R = verdadero
	FinSi
	Si year%400==0 Entonces
		R = verdadero
	FinSi
FinFuncion
