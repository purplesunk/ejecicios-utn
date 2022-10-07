Algoritmo sin_titulo
	dimension vNumeros[10]
	Para i<-0 Hasta 9 Hacer
		Leer vNumeros[i]
	FinPara
	pares = 0
	Para i<-0 Hasta 9 Hacer
		Si vNumeros[i]%2==0 Entonces
			pares = pares + 1
		FinSi
	FinPara
	Escribir "Hay ",pares," pares."
	pares = 0
	Para i<-0 Hasta 9 Hacer
		Si vNumeros[i]%2==0 Entonces
			pares = pares + 1
			Escribir pares,") ",vNumeros[i]
		FinSi
	FinPara
FinAlgoritmo
