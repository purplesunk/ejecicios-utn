Algoritmo ejercicio19
	Dimension vector[5]
	Dimension vector2[5]
	llenarVectorRandom(vector,5)
	llenarVectorRandom(vector2,5)
	linea()
	mostrarVector(vector,5)
	linea()
	mostrarVector(vector2,5)
	linea()
	Dimension vector3[10]
	intercalarVectores(vector,vector2,vector3,5)
	mostrarVector(vector3,10)
FinAlgoritmo

Funcion llenarVectorRandom(vec,tam)
	Para i<-0 Hasta tam-1 Hacer
		vec[i] <- azar(100)
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
		vectorR[i*2]=vec[i]
		vectorR[(i*2)+1]=vec2[i]
	FinPara
FinFuncion
