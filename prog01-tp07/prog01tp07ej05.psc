Algoritmo sin_titulo
	Leer A,B,C
	Escribir max(A,B,C)
FinAlgoritmo

Funcion R = max(num,num2,num3)
	Si num > num2 Entonces
		R = num
	SiNo
		R = num2
	FinSi
	Si num3 > R Entonces
		R = num3
	FinSi
FinFuncion
