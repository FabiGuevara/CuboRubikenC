
/* paso 4: cruz en la última cara */

void validacion_caso4(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	band1=0;
	for (i=0; i<3; i++)
	{
		for (i=0; j<3; i++)
		{
			if (matriza[i][j]==0)
			{
			band1=1;
			}
		}
	}

	band2=0;
	for (i=1; i<3; i++)
	{
		for (j=1; j<3; j++)
		{
			if ((matrizi[i][j]==1) && (matrizd[i][j]==5) && (matrizf[i][j]==2) && (matrizt[i][j]==3))
			{
			band2=1;
			}
		}
	}

	if ((band1==1)&& (band2==1) && (matrizd[0][1]==4) && (matriza[0][1]==4) && (matriza[1][1]==4) && (matriza[2][1]==4))
	{
		caso4_1(matriza, matrizb, matrizf, matrizt, matrizi, matrizd);
	}
	if ((band1==1)&& (band2==1) && (matrizf[0][1]==4) && (matrizd[0][1]==4) && (matriza[0][1]==4) && (matriza[0][1]==4) && (matriza[1][0]==4))
	{
		caso4_2(matriza, matrizb, matrizf, matrizt, matrizi, matrizd);
	}
	if ((band1==1)&& (band2==1) && (matrizf[0][1]==4) && (matrizd[0][1]==4) && (matriza[0][0]==4)))
	{
		caso4_3(matriza, matrizb, matrizf, matrizt, matrizi, matrizd);
	}
return 0;
}


/* paso 4.1: la arista queda a la derecha del hueco donde va. */
void caso4_1(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	printf("Tienes el primer caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos: \n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara derecha 90° hacia abajo.\n");
	printf("3. Gira la cara frontal 90° a la izquierda.\n 4. Gira la cara superior 90° a la derecha.\n 5. Gira la cara frontal 90° a la derecha. \n");
	printf("6. Gira la cara superior 90° a la izquierda.\n 7. Gira la cara derecha 90° hacia la derecha.\n");
	return 0;
}

/* paso 4.2: el vértice tiene el color blanco en la cara derecha. */
void caso4_2(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	
	printf("Tienes el segundo caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara derecha 90° hacia abajo.\n");
	printf("3. Gira la cara superior 90° a la derecha.\n 4. Gira la cara frontal 90° a la izquierda.\n 5. Gira la cara superior 90° a la izquierda. \n");
	printf("6. Gira la cara frontal 90° a la derecha.\n 7. Gira la cara derecha 90° hacia la derecha.\n");
	return 0;
}

/* paso 4.3: el vértice tiene el color blanco en la cara derecha. */
void caso4_3(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	
	printf("Tienes el tercer caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara derecha 90° hacia abajo.\n");
	printf("3. Gira la cara frontal 90° a la izquierda.\n 4. Gira la cara superior 90° a la derecha.\n");
	printf("5. gira la cara frontal 90° a la derecha.\n 6. Gira la cara superior 90° a la izquierda.\n");
	printf("7. Gira la cara derecha 90° hacia la derecha.\n 8. Gira la cara superior 180° a la izquierda.\n");
	printf("9. Gira la cara derecha 90° hacia abajo.\n  10. Gira la cara superior 90° a la derecha.\n");
	printf("11. Gira la cara frontal 90° a la izquierda.\n 12. Gira la cara superior 90° a la izquierda.\n");
	printf("13.Gira la cara frontal 90° a la derecha.\n 14. Gira la cara derecha 90° hacia la derecha.\n")
	return 0;
}

