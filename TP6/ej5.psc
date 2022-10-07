Algoritmo sin_titulo
	Dimension num[10]
	Para i<-0 Hasta 9 Hacer
		Leer num[i]
	FinPara
	men = 2
	max = 1
	Para i<-0 Hasta 9 Hacer
		Si num[i]%2==0 Entonces
			Si (max==1) | (num[i]>max) Entonces
				max = num[i]
			FinSi
		SiNo
			Si (men==2) | (num[i]<men) Entonces
				men = num[i]
			FinSi
		FinSi
	FinPara
	Si men <> 2 Entonces
		Escribir "Menor de los impares: ", men
	FinSi
	Si max <> 1 Entonces
		Escribir "Mayor de los pares: ", max
	FinSi
FinAlgoritmo
