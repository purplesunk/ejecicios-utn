Algoritmo sin_titulo
	dimension vNum[10]
	Para i<-0 Hasta 9 Hacer
		Leer vNum[i]
	FinPara
	Escribir "Ingrese un numero de 1 a 10: "
	Leer a
	Escribir "Ingrese un numero de 1 a 10: "
	Leer b
	Si a>=b Entonces
		inicio = b-1
		final = a-1
	SiNo
		inicio = a-1
		final = b-1
	FinSi
	max = vNum[inicio]
	Para i<-inicio Hasta final Hacer
		Si vNum[i]>max Entonces
			max = vNum[i]
		FinSi
	FinPara
	Escribir "El maximo entre las posiciones ",inicio+1," y ",final+1," es ",max
FinAlgoritmo
