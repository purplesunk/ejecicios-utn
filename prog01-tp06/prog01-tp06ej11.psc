Algoritmo sin_titulo
	dimension vNumeros[10]
	Para i<-0 Hasta 9 Hacer
		Leer vNumeros[i]
	FinPara
	Escribir "Ingrese un n�mero: "
	Leer num
	indice = -1
	Para i<-0 Hasta 9 Hacer
		Si num == vNumeros[i] Entonces
			indice = i
		FinSi
	FinPara
	Escribir "Indice del n�mero ingresado: ",indice
FinAlgoritmo
