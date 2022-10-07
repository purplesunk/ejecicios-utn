Algoritmo sin_titulo
	haySegMayor <- FALSO
	Para i<-1 Hasta 10 Hacer
		Leer num
		Si i==1 Entonces
			mayor <- num
		SiNo
			Si num>mayor Entonces
				segMayor <- mayor
				mayor <- num
			SiNo
				Si ((!haySegMayor) | (num>segMayor)) & (num<>mayor) Entonces
					segMayor <- num
					haySegMayor <- VERDADERO
				FinSi
			FinSi
		FinSi
	FinPara
	Escribir 'Mayor: ',mayor
	Escribir 'Segundo mayor: ',segMayor
FinAlgoritmo
