Algoritmo sin_titulo
	cantPrimos = 0
	Para n<-1 Hasta 10 Hacer
		Escribir "Ingrese número: "
		Leer num
		cantDivisore = 0
		Para i<-1 Hasta num Hacer
			Si ( num>0 ) & ( num%i==0 ) Entonces
				cantDivisore = cantDivisore + 1
			FinSi
		FinPara
		Si cantDivisore == 2 Entonces
			cantPrimos = cantPrimos + 1
		FinSi
	FinPara
	Escribir CantPrimos
FinAlgoritmo
