Algoritmo sin_titulo
	peso = 0
	pesofinal = 0
	cantBultos = 0
	Mientras peso < 2000 Hacer
		Escribir "Ingrese el peso de la caja: "
		Leer kgs
		peso = peso + kgs
		Si peso < 2000 Entonces
			pesofinal = peso
			cantBultos = cantBultos + 1
		SiNo
			Escribir "ultima caja no ingresada, se pasa el peso total"
		FinSi
	FinMientras
	Escribir "se cargaran ",cantBultos," cajas y el peso total es de ",pesofinal
FinAlgoritmo
