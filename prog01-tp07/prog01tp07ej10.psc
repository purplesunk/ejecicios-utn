Algoritmo sin_titulo
	primos = 0
	Leer a
	Mientras a<>0 Hacer
		Si esPrimo(a)==1 Entonces
			primos = primos+1
		FinSi
		Leer a
	FinMientras
	Escribir primos
FinAlgoritmo

Funcion R = esPrimo(num)
	divisores = 0
	Si num > 1 Entonces
		Para i<-1 Hasta num Hacer
			Si num%i==0 Entonces
				divisores = divisores + 1
			FinSi
		FinPara
	FinSi
	Si divisores == 2 Entonces
		R = 1
	SiNo
		R = 0
	FinSi
FinFuncion
