Algoritmo sin_titulo
	estaOrdenado = verdadero
	Dimension vNumeros[20]
	Para i<-0 Hasta 19 Hacer
		Leer vNumeros[i]
	FinPara
	Para i<-1 Hasta 19 Hacer
		Si vNumeros[i] <= vNumeros[i-1] Entonces
			estaOrdenado = falso
		FinSi
	FinPara
	Si estaOrdenado Entonces
		Escribir "Conjunto ordenado"
	SiNo
		Escribir "Conjunto desordenado"
	FinSi
FinAlgoritmo
