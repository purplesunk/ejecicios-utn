Algoritmo sin_titulo
	Dimension vUno[5]
	Dimension vDos[5]
	Dimension vTres[10]
	Escribir 'Primer Vector: '
	Para i<-0 Hasta 4 Hacer
		Leer vUno[i]
	FinPara
	Escribir 'Segundo Vector: '
	Para i<-0 Hasta 4 Hacer
		Leer vDos[i]
	FinPara
	Para i<-0 Hasta 4 Hacer
		vTres[i*2] = vUno[i]
		j = (i*2) + 1
		vTres[j] = vDos[i]
	FinPara
	Escribir "Tercer Vector: "
	Para i<-0 Hasta 9 Hacer
		Escribir vTres[i]
	FinPara
FinAlgoritmo
