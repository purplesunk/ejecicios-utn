Algoritmo ejercicio15
	dimension vector[5]
	llenarVectorRandom(vector,5,10)
	dimension vector2[9]
	intercalarPromedio(vector,vector2,5)
	mostrarVector(vector2,9)
FinAlgoritmo

Funcion llenarVectorRandom(vec,tam,num)
	Para i<-0 Hasta tam-1 Hacer
		vec[i] <- azar(num)+1
	FinPara
FinFuncion

Funcion mostrarVector(vec,tam)
	Para i<-0 Hasta tam-1 Hacer
		Escribir vec[i]
	FinPara
FinFuncion

Funcion linea()
	Escribir '-----------------------------'
FinFuncion

Funcion intercalarVectores(vec,vec2,vectorR,tam)
	Para i<-0 Hasta tam-1 Hacer
		vectorR[i*2]<-vec[i]
		vectorR[(i*2)+1]<-vec2[i]
	FinPara
FinFuncion

Funcion intercalarPromedio(vec,vecR,tam)
	Para i<-0 Hasta tam-1 Hacer
		vecR[i*2]=vec[i]
		Si i<>4 Entonces
			vecR[(i*2)+1]=(vec[i]+vec[i+1])/2
		FinSi
	FinPara
FinFuncion
