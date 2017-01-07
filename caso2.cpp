/* paso 2: completar la cara superior */

void validacion_casos2(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	if ((matriza[0][1]==0) && (matriza[1][1]==0) && (matriza[1][0]==0)  && (matriza[1][2]==0) && (matriza[2][1]==0)&& (matrizf[0][1]==1) && (matrizf[1][1]==1) && (matrizf[2][2]==0) && (matrizd[0][1]==3) && (matrizd[1][1]==3) && (matrizd[2][0]==0))
	{
		caso2_1(matriza, matrizb, matrizf, matrizt, matrizi, matrizd);
	}
	if ((matriza[0][1]==0) && (matriza[1][1]==0) && (matriza[1][0]==0)  && (matriza[1][2]==0) && (matriza[2][1]==0)&& (matrizf[0][1]==1) && (matrizf[1][1]==1) && (matrizf[2][2]==1) && (matrizd[0][1]==3) && (matrizd[1][1]==3) && (matrizd[2][0]==0))
	{
		caso2_2(matriza, matrizb, matrizf, matrizt, matrizi, matrizd);
	}
	if ((matriza[0][1]==0) && (matriza[1][1]==0) && (matriza[1][0]==0)  && (matriza[1][2]==0) && (matriza[2][1]==0)&& (matrizf[0][1]==1) && (matrizf[1][1]==1) && (matrizf[2][2]==3) && (matrizd[0][1]==3) && (matrizd[1][1]==3) && (matrizd[2][0]==1))		
	{
		caso2_3(matriza, matrizb, matrizf, matrizt, matrizi, matrizd);
	}
	return 0;
}


/* paso 2_1: el vértice tiene el color blanco en la cara frontal. */
void caso2_1(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	printf("Tienes el primer caso\n");
	printf("Debes completar la capa superior \n Realiza los siguientes pasos: \n ");
	printf("1. Toma de frente la cara que tiene rojo y blanco \n 2. Gira la base 90° a la izquierda \n");
	printf("3. Baja 90° la cara derecha \n 4. Gira 90° la base a la derecha\n 5. Sube 90° la cara derecha \n");
	printf(" \n");
	return 0;
}

/* paso 2.2: el vértice tiene el color blanco en la cara derecha. */
void caso2_2(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	printf("Tienes el segundo caso\n");
	printf("Debes completar la capa superior\n Realiza los siguientes pasos:\n ");
	printf("1. Toma de frente la cara que tiene solo rojo \n 2. Gira la base 90° a la derecha \n");
	printf("3. Gira 90° la cara frontal hacia la derecha\n 4. Gira la base 90° a la izquierda \n");
	printf("5. Gira 90° la cara frontal hacia la izquierda\n");
	return 0;
}


/* paso 2.1: el vértice tiene el color blanco abajo.*/

void caso2_3(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	printf("Tienes el tercer caso\n");
	printf("Debes completar la capa superior \n Realiza los siguientes pasos: \n ");
	printf("1. Toma de frente la cara que tiene 2 rojos y un azul\n 2. Baja la cara derecha 90° hacia el frente \n");
	printf("3. Gira la base 180° a la izquierda \n 4. Gira la cara derecha 90° hacia arriba-ensentido de las manecillas\n");
	printf("5. Gira la base 180° hacia la derecha \n 6.Gira la base frontal 90° hacia la derecha\n");
	printf("7. Gira la base 90° a la izquierda\n 8. Gira la cara frontal 90° a la izquierda\n");
	return 0;
}



