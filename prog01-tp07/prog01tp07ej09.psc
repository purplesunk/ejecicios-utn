Algoritmo sin_titulo
	pares = 0
	impares = 0
	Leer A
	Mientras A<>0 Hacer
		Si esPar(A)==1 Entonces
			pares = pares+1
		SiNo
			impares = impares +1
		FinSi
		Leer A
	FinMientras
	Escribir "pares: ",pares," impares: ",impares
FinAlgoritmo

Funcion R = esPar(num)
	Si num%2==0 Entonces
		R = 1
	SiNo
		R = 0
	FinSi
FinFuncion
