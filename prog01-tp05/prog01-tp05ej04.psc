Algoritmo sin_titulo
	ordenados = verdadero
	primoAnt = 1
	Escribir "Ingrese un n�mero: "
	Leer N
	Mientras N<>0 Hacer
		divisores = 0
		Si N>1 Entonces
			Para i<-1 Hasta N Hacer
				Si N%i==0 Entonces
					divisores = divisores + 1
				FinSi
			FinPara
			Si divisores == 2 Entonces
				Si (primoAnt==1)|(N>primoAnt) Entonces
					primoAnt = N
				SiNo
					ordenados = falso
				FinSi
			FinSi
		FinSi
		Escribir "Ingrese un n�mero: "
		Leer N
	FinMientras
	Si ordenados Entonces
		Escribir "Los n�meros primos est�n ordenados de menor a mayor"
	SiNo
		Escribir "Los n�meros primos NO est�n ordenados de menor a mayor"
	FinSi
FinAlgoritmo
