Algoritmo sin_titulo
	posG1 <- 0; posG2 <- 0
	negG1 <- 0; negG2 <- 0
	cerosG1 <- 0; cerosG2 <- 0
	ultPrimoG1 <- 0; ultPrimoG2 <- 0
	ubiPrimoG1 <- 0; ubiPrimoG2 <- 0
	imparesCant <- 0
	Para g<-1 Hasta 2 Hacer
		pos <- 0; neg <- 0; ceros <- 0
		ultPrimo <- 0
		ubiPrimo <- 0
		Para i<-1 Hasta 5 Hacer
			Leer num
			Si num>0 Entonces
				pos <- pos+1
			SiNo
				Si num==0 Entonces
					ceros <- ceros+1
				SiNo
					neg <- neg+1
				FinSi
			FinSi
			Si num%2<>0 Entonces
				imparesCant <- imparesCant+1
			FinSi
			divisores <- 0
			Para p<-num Hasta 1 Con Paso -1 Hacer
				Si num%p==0 Entonces
					divisores <- divisores+1
				FinSi
			FinPara
			Si divisores==2 Entonces
				ultPrimo <- num
				ubiPrimo <- i
			FinSi
		FinPara
		Segun g  Hacer
			1:
				posG1 <- pos
				negG1 <- neg
				cerosG1 <- ceros
				ultPrimoG1 <- ultPrimo
				ubiPrimoG1 <- ubiPrimo
			2:
				posG2 <- pos
				negG2 <- neg
				cerosG2 <- ceros
				ultPrimoG2 <- ultPrimo
				ubiPrimoG2 <- ubiPrimo
		FinSegun
	FinPara
	Escribir 'Grupo 1: '
	Escribir 'positivos: ',posG1
	Escribir 'negativos: ',negG1
	Escribir 'ceros: ',cerosG1
	Si ultPrimoG1 <> 0 Entonces
		Escribir "último primo: ", ultPrimoG1
		Escribir "ubicación: ", ubiPrimoG1
	SiNo
		Escribir "no tenía primo"
	FinSi
	Escribir 'Grupo 2: '
	Escribir 'positivos: ',posG2
	Escribir 'negativos: ',negG2
	Escribir 'ceros: ',cerosG2
	Si ultPrimoG2 <> 0 Entonces
		Escribir "último primo: ", ultPrimoG2
		Escribir "ubicación: ", ubiPrimoG2
	SiNo
		Escribir "no tenía primo"
	FinSi
	Escribir "cantidad total de impares: ", imparesCant
FinAlgoritmo
