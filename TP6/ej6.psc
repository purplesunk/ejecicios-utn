Algoritmo sin_titulo
	Dimension num[10]
	Para i<-0 Hasta 9 Hacer
		Leer num[i]
	FinPara
	ult = 1
	posUlt = 0
	Para i<-0 Hasta 9 Hacer
		Si num[i]%2==0 Entonces
			antUlt = ult
			posAntUlt = posUlt
			ult = num[i]
			posUlt = i + 1
		FinSi
	FinPara
	Si ult <> 1 Entonces
		Si antUlt <> 1 Entonces
			Escribir "El ante�ltimo n�mero par fue: ", antUlt, " Posici�n: ", posAntUlt
		FinSi
		Escribir "El �ltimo n�mero par fue: ", ult, " Posici�n: ", posUlt
	FinSi
FinAlgoritmo
