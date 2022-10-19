Algoritmo sin_titulo
	Dimension vac[10]
	Para i<-0 Hasta 9 Hacer
		Leer vac[i]
	FinPara
	intercambiar(vac,3,10)
	Para i<-0 Hasta 9 Hacer
		Escribir vac[i]
	FinPara
FinAlgoritmo

Funcion intercambiar(vec,pos1,pos2)
	uno = vec[pos1-1]
	dos = vec[pos2-1]
	vec[pos1-1] = dos
	vec[pos2-1] = uno
FinFuncion
