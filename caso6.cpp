/* Paso 6: colocar los últimos vértices (sin orientar) */
void validacion_caso6(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
/* Validar que la cara blanca este formada */	
	bandi1=0;
	for (i=0; i<3; i++)
	{
		for (i=0; j<3; i++)
		{
			if (cubo[i][j][0]==0)
			{
				bandi1=1;
			}
		}
	}
/* Validar que las demas caras tengan dos filas armadas*/
	bandi2=0;
	for (i=1; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			if ((cubo[i][j][2]==1) && (cubo[i][j][4]==5) && (cubo[i][j][3]==2) && (cubo[i][j][1]==3))
				bandi2=1;
		}
	}	

/* Validar que en la cara inferior este dos filas amarillas armadas*/
	bandi3=0;
	for (i=1; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			if (cubo[i][j][5]==5)
				bandi3=1;
		}
	}
	/* Validar que la posicion 0,1 sea del mismo color*/
	bandi4=0;
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			if ((cubo[0][1][2]==2) && (cubo[0][1][4]==4) && (cubo[0][1][3]==3) && (cubo[0][1][1]==1))
				bandi4=1;
		}
	}

/* valida la cruz completa*/
	bandi5=0;
	for (i=0; i<3; i++)
	{
		if ((cubo[1][i][5]==5) && (cubo[i][1][5]==5))
			bandi5=1;
	}
	
	
	/*1 */  if ((bandi1==1)&& (bandi2==1)&& (bandi4==1) && (bandi5==1) && (cubo[0][0][3]==5) && (cubo[0][2][3]==5) && (cubo[0][0][4]==3) && (cubo[0][2][4]==5) && (cubo[0][0][5]==4) && (cubo[0][2][5]==3) && (cubo[2][0][5]==1) && (cubo[2][2][5]==4))
	
	/*1 */  if ((bandi1==1)&& (bandi2==1)&& (bandi4==1) && (bandi5==1) && (cubo[0][0][3]==5) && (cubo[0][2][3]==5) && (cubo[0][0][4]==4) && (cubo[0][2][4]==5) && (cubo[0][0][5]==3) && (cubo[0][2][5]==2) && (cubo[2][0][5]==2) && (cubo[2][2][5]==1))
	
	
	/*1 */  if ((bandi1==1)&& (bandi2==1) && (bandi3==1) && (bandi4==1) && (cubo[0][0][5]==1) && (cubo[0][2][5]==1) && (cubo[0][0][3]==4) && (cubo[0][2][3]==2) && (cubo[0][2][4]==2) && (cubo[0][0][4]==3)) 
	
	/*1 */  if ((bandi1==1)&& (bandi2==1) && (bandi3==1) && (bandi4==1) && (cubo[0][0][5]==4) && (cubo[0][2][5]==2) && (cubo[0][0][3]==1) && (cubo[0][2][3]==1) && (cubo[0][2][4]==3) && (cubo[0][0][4]==2)) 
}

/* paso 6.1: Un vértice está en su sitio y los otros 3 se deben intercambiar en sentido horario. */
void caso6_1(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	
	printf("Tienes el primer caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara izquierda 90° hacia arriba/izquierda.\n");
	printf("3. Gira la cara superior 90° a la izquierda.\n 4. Gira la cara derecha 90° hacia la derecha.\n");
	printf("5. Gira la cara superior 90° a la derecha.\n 6. Gira la cara izquierda 90° hacia abajo/derecha.\n");
	printf("7. Gira la cara superior 90° a la izquierda.\n 8. Gira la cara derecha 90° hacia abajo.\n");
	printf("9. Gira la cara superior 90° a la derecha.\n 10. \n");
	return 0;
}

/* paso 6.2: Un vértice está en su sitio y los otros 3 se deben intercambiar en sentido anti-horario. */
void caso6_2(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	printf("Tienes el segundo caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara derecha 90° hacia la derecha.\n");
	printf("3. Gira la cara superior 90° a la derecha.\n 4. Gira la cara izquierda 90° hacia arriba/izquierda.\n");
	printf("5. Gira la cara superior 90° a la izquierda.\n 6. Gira la cara derecha 90° hacia abajo.\n");
	printf("7. Gira la cara superior 90° a la derecha.\n 8. Gira la cara izquierda 90° hacia abajo/derecha.\n");
	printf("9. Gira la cara superior 90° a la izquierda.\n 10. \n");
	return 0;
}

/* Paso 6.3: Los dos vértices se deben intercambiar entre si y los dos frontales también.*/
void caso6_3(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
	{
		printf("Tienes el tercer caso\n");
		printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
		printf("1. Pon la cara blanca abajo\n 2. Gira la cara frontal 90° a la derecha.\n");
		printf("3. Gira la cara superior 90° a la izquierda.\n 4. Gira la cara derecha 90° hacia la derecha.\n");
		printf("5. Gira la cara superior 90° a la derecha.\n 6. Gira la cara derecha 90° hacia abajo.\n");
		printf("7. Repetir 3 veces desde el #2 al 6#\n 8. Gira la cara frontal 90° a la izquierda.\n");
		printf("9. \n 10. \n");
	return 0;
	}	
	
/* Paso 6.4: Los vértices se deben intercambiar en cruz.*/
void caso6_4(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
	{
		printf("Tienes el cuarto caso\n");
		printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
		printf("1. Pon la cara blanca abajo\n 2. Gira la cara frontal 90° a la derecha.\n");
		printf("3. Gira la cara trasera 90° a la izquierda.\n 4. Gira la cara superior 180° a la izquierda.\n");
		printf("5. Gira la cara frontal 90° a la izquierda.\n 6. Gira la cara trasera 90° a la derecha.\n");
		printf("7. Gira la cara derecha 90° hacia abajo.\n 8. Gira la cara izquierda 90° hacia arriba-izquierda.\n");
		printf("9. Gira la cara superior 180° a la izquierda.\n 10. Gira la cara derecha 90° hacia la derecha.\n");
		printf("11. Gira la cara izquierda 90° hacia abajo-derecha.\n 12. Gira la cara superior 180° a la izquierda.\n");
	return 0;
	}


