/* paso 5: Extender la cruz a la última capa */

void busqueda_validacion5()
{
	int bande1=0, bande2=0, i, j;
	do{
		for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			if (cubo[i][j][0]==0)
			{
				bande1=1;
			}
		}
	}
	
	for (i=1; i<3; i++)
	{
		for (j=1; j<3; j++)
		{
			if ((cubo[i][j][1]==1) && (cubo[i][j][3]==3) && (cubo[i][j][4]==4) && (cubo[i][j][2]==2))
			{
				bande2=1;
			}
		}
	}	
	
	
	if ((bande1==1)&&(bande2==1)&&(cubo[0][1][4]==4)&&(cubo[0][1][3]==3)&&(cubo[0][1][5]==5)&&(cubo[1][0][5]==5)&&(cubo[1][1][5]==5)&&(cubo[1][2][5]==5)&&(cubo[2][1][5]==5))
	{
		caso5_1();
	}
	if ((bande1==1)&&(bande2==1)&&(cubo[0][1][3]==1)&&(cubo[0][1][4]==4)&&(cubo[0][1][5]==5)&&(cubo[1][0][5]==5)&&(cubo[1][1][5]==5)&&(cubo[1][2][5]==5)&&(cubo[2][1][5]==5))
	{
		caso5_2();
	}	
	}while(((bande1==1)&&(bande2==1)&&(cubo[0][1][4]==4)&&(cubo[0][1][3]==3)&&(cubo[0][1][5]==5)&&(cubo[1][0][5]==5)&&(cubo[1][1][5]==5)&&(cubo[1][2][5]==5)&&(cubo[2][1][5]==5))||
	((bande1==1)&&(bande2==1)&&(cubo[0][1][3]==1)&&(cubo[0][1][4]==4)&&(cubo[0][1][5]==5)&&(cubo[1][0][5]==5)&&(cubo[1][1][5]==5)&&(cubo[1][2][5]==5)&&(cubo[2][1][5]==5)));
	
	

}

/* paso 5.1: Conseguimos 2 aristas adyacentes colocadas en su sitio */
void caso5_1()
{
	printf("Tienes el primer caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos: \n ");
	printf("1. Pon la cara blanca abajo y tomar como frente la cara con centro verde\n 2. Gira la cara derecha 90° hacia abajo.\n");
	printf("3. Gira la cara superior 90° a la derecha.\n 4. Gira la cara derecha 90° hacia la derecha.\n");
	printf("5. Gira la cara superior 90° a la derecha.\n 6. Gira la cara derecha 90° hacia abajo.\n");
	printf("7. Gira la cara superior 90° a la izquierda.\n 8. Gira la cara derecha 180° hacia la derecha.\n");
	printf("9. Gira la cara superior 90° a la derecha.\n");
	return 0;
}

/* paso 5.2: Conseguimos 2 aristas opuestas colocadas en su sitio.  */
void caso5_2()
{
	
	printf("Tienes el segundo caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara derecha 90° hacia abajo.\n");
	printf("3. Gira la cara superior 90° a la derecha.\n 4. Gira la cara derecha 90° hacia la derecha.\n");
	printf("5. Gira la cara superior 90° a la derecha.\n 6. Gira la cara derecha 90° hacia abajo.\n");
	printf("7. Gira la cara superior 90° a la izquierda.\n 8. Gira la cara derecha 180° hacia la derecha.\n");
	printf("9. Girar todo el cubo 90° a la izquierda.\n 10. Gira la cara derecha 90° hacia abajo.\n");
	printf("11. Gira la cara superior 90° a la derecha.\n 12. Gira la cara derecha 90° hacia la derecha.\n");
	printf("13. Gira la cara superior 90° a la derecha.\n 14. Gira la cara derecha 90° hacia abajo.\n");
	printf("15. Gira la cara superior 90° a la izquierda.\n 16. Gira la cara derecha 180° hacia la derecha.\n");
	printf("17. Gira la cara superior 90° a la derecha.\n")
	return 0;
}




