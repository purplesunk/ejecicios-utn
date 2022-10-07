Algoritmo WHILE
	mostrados = 0
	multiplo = 5
	Leer num
	Mientras mostrados < num Hacer
		multiplo = multiplo + 1
		Si multiplo%2==0 & multiplo%3==0 & multiplo%5<>0 Entonces
			mostrados = mostrados + 1
			Escribir multiplo
		FinSi
	FinMientras
FinAlgoritmo
