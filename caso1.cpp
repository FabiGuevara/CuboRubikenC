/* paso1 cruz superior */

void validacion_casos(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	if ((matriza[1][1]==0) && (matrizf[1][1]== 1) && (matrizd[1][1]==3) && (matrizd[2][1]==1) && (matrizb[1][2]==0))
	{
		caso1_1((matriza, matrizb, matrizf, matrizt, matrizi, matrizd);
	}
    if ((matriza[1][1]==0) && (matriza[1][2]==0) && (matrizf[1][1]== 1) && (matrizf[2][1]==0)&& (matrizd[1][1]==3) && (matrizd[0][1]==3));
	{
		caso1_2(matriza, matrizb, matrizf, matrizt, matrizi, matrizd);
	}
	if ((matriza[1][1]==0) && (matriza[0][1]==0) && (matriza[1][0]==0) (matriza[1][2]==0) &&(matrizf[1][1]== 1) && (matrizf[1][2]== 0) && (matrizd[1][1]==3) && (matrizd[0][1]==3) && (matrizb[1][1]==3)&& (matrizb[1][0]==3))
	{
		caso1_3 (matriza, matrizb, matrizf, matrizt, matrizi, matrizd);
	}
return 0;
}

/*  Caso 3: arista en la capa intermedia, se reduce a un caso anterior. */
void caso1_3(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3];)
{
	printf("Tienes el tercer caso\n");
	printf("Debes hacer una cruz arriba de color blanco \n realiza los siguientes pasos \n ");
	Printf("1.- Toma la cara que tiene rojo  en el centro y a la dercha blanco como frente \n 2.- gira la cara derecha hacia abajo 90° \n 3.-Gira la base hacia la izquierda 90°\n 4.-Gira la cara derecha 90° hacia arriba \n");
	
	return 0;
}

/* Caso 1: arista en la capa inferior con el blanco hacia abajo. */
void caso1_1(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3];)
{
	printf("Tienes el primer caso\n");
	printf("Debes hacer una cruz arriba de color blanco \n realiza los siguientes pasos \n ");
	Printf("1.- Toma la cara que tiene al rojo en el centro \n 2.- Gira la base 90° a la izquierda \n 3.-Gira 180° la cara frontal hacia la derecha \n");
	
	return 0;
}
