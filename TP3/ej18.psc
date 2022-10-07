Algoritmo sin_titulo
	comprobarOrdenado = 1
	Para i<-1 Hasta 8 Hacer
		Leer num
		Si i == 1 Entonces
			mayor = num
		FinSi
		Si num >= mayor Entonces
			mayor = num
		SiNo
			comprobarOrdenado = 0
		FinSi
	FinPara
	Si comprobarOrdenado == 1 Entonces
		Escribir "Conjunto ordenado"
	SiNo
		Escribir "Conjunto desordenado"
	FinSi
FinAlgoritmo
