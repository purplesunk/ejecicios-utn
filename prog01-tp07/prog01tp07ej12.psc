Algoritmo sin_titulo
	Dimension vac[10]
	Para i<-0 Hasta 9 Hacer
		Leer vac[i]
	FinPara
	maxVec(vac,10)
FinAlgoritmo

Funcion maxVec(vec,T)
	max <- vec[0]
	pos = 1
	Para i<-1 Hasta T-1 Hacer
		Si vec[i]>max Entonces
			max <- vec[i]
			pos = i+1
		FinSi
	FinPara
	Escribir "valor max: ",max," pos: ", pos
FinFuncion
