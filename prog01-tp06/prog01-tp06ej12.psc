Algoritmo ej12
	dimension vNumeros[10]
	Para i<-0 Hasta 9 Hacer
		Leer vNumeros[i]
	FinPara
	Escribir "Ingrese un número: "
	Leer num
	repetido = 0
	Para i<-0 Hasta 9 Hacer
		Si num == vNumeros[i] Entonces
			repetido = repetido + 1
		FinSi
	FinPara
	Escribir "El numero se repitió ",repetido," veces."
FinAlgoritmo
