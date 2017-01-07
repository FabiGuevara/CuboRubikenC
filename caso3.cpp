/* paso 3: completar la segunda capa */

void validacion_caso3(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	ban1=0;
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			if (matriza[i][j]==0)
			{
				ban1=1;
			}
		}
	}
	
	ban2=0;
	for (i=3; i==3; i++)
	{
		for (j=0; j<3; j++)
		{
			if ((matrizt[i][j]==3) && (matrizi[i][j]==1) && (matrizd[i][j]==5) && (matrizf[i][j]==2))
			{
				ban2=1;
			}
		}
	}
	
	if ((ban1==1)&& (ban2==1) && (matrizi[1][1]==1) && (matrizd[0][1]==5) && (matrizd[1][1]==5) && (matriza[1][1]==4) && (matriza[1][2]==4) && (matrizf[1][1]==2))
	{
		caso3_1(matriza, matrizb, matrizf, matrizt, matrizi, matrizd);
	}
	if ((ban1==1)&& (ban2==1) && (matrizi[1][1]==1) && (matrizd[1][1]==5) && (matrizf[1][1]==2) && (matrizf[0][1]==2) && (matriza[1][1]==4) && (matriza[2][1]==5))
	{
		caso3_2(matriza, matrizb, matrizf, matrizt, matrizi, matrizd);
	}
return 0;
}

/* paso 3.1: la arista queda a la derecha del hueco donde va. */
void caso3_1(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	printf("Tienes el primer caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos: \n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara de arriba 90° a la derecha\n");
	printf("3. Gira la cara frontal 90° a la derecha\n 4. Gira 90° la cara superior a la derecha\n 5. Gira la cara frontal 90° a la derecha\n");
	printf("6. Gira la cara frontal 90° a la izquierda\n 7. Gira 90° la cara derecha hacia arriba\n");
	printf("8. Gira la cara frontal 90° a la derecha\n 9. Baja 90° la cara derecha\n ");
	return 0;
}

/* paso 3.2: el vértice tiene el color blanco en la cara derecha. */
void caso3_2(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	
	printf("Tienes el segundo caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara de arriba 90° a la derecha\n");
	printf("3. Gira la cara superior 90° a la izquierda\n 4. Gira la cara derecha 90° hacia la derecha\n 5. Gira la cara superior 90° a la derecha\n");
	printf("6. Gira la cara derecha 90° hacia abajo\n 7. Gira la cara superior 90° a la derecha\n");
	printf("8. Gira la cara frontal 90° a la izquierda\n 9. Gira la cara superior 90° a la izquierda\n 10. Gira la cara derecha 90° hacia abajo.\n");
	return 0;
}


