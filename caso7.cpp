/* Caso 7: girar los vértices para ¡terminar el cubo! */

void validacion_caso7();
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
			if ((cubo[i][j][1]==1) && (cubo[i][j][2]==2) && (cubo[i][j][3]==3) && (cubo[i][j][4]==4))
				bandi2=1 ;
		}
	}	
	
	/* Validar que haya dos filas amarillas armadas*/
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
	
	/* Validar dos columnas azules armadas*/
	bandi6=0;
	for (i=0; i<2; i++)
	{
		for (j=0; j<3; j++)
		{
			if (cubo[i][j][2]==2)
				bandi6=1 ;
		}
	}	

	/* Validar que haya dos filas amarillas armadas*/
	bandi7=0;
	for (i=0; i<2; i++)
	{
		for (j=0; j<3; j++)
		{
			if (cubo[i][j][5]==5)
				bandi7=1;
		}
	}
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][2][4]==5) && (cubo[0][0][3]==4) && (cubo[2][2][5]==3))
		caso7_1()
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][2][4]==3) && (cubo[0][0][3]==5) && (cubo[2][2][5]==4))
		caso7_2 ()
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi6==1) && (bandi7==1) && (cubo[0][0][3]==2)&& (cubo[0][2][3]==4) && (cubo[0][2][2]==5) && (cubo[0][2][5]==3) && (cubo[2][2][5]==3) && (cubo[0][0][4]==5))	
		caso7_3 ()
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (bandi6==1) && (cubo[0][2][3]==4) && (cubo[0][0][3]==5) && (cubo[0][0][5]==4) && (cubo[2][2][5]==2) && (cubo[0][2][2]==3) && (cubo[0][2][5]==3) )
		caso7_4 ()
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][2]==1) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==5) && (cubo[0][0][5]==4) && (cubo[0][2][5]==4) && (cubo[2][0][5]==2) && (cubo[2][2][5]==2)) )
		caso7_5 ()
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (bandi7==1) && (cubo[0][0][5]==5) && (cubo[0][2][5]==5) && (cubo[2][0][5]==1) && (cubo[2][2][5]==3) && (cubo[0][0][2]==5) && (cubo[0][2][2]==5) && (cubo[0][0][3]==2) && (cubo[0][2][3]==3))
		caso7_6 ()
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (bandi7==1) && (cubo[0][0][5]==5) && (cubo[0][2][5]==5) && (cubo[2][0][5]==2) && (cubo[2][2][5]==2) && (cubo[0][0][2]==1) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==3))
		caso7_7 ()
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (bandi6==1) && (cubo[0][0][5]==1) && (cubo[0][2][5]==5) && (cubo[2][0][5]==5) && (cubo[2][2][5]==2) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==3))
		caso7_8 ()
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][5]==5) && (cubo[0][2][5]==4) && (cubo[2][0][5]==2) && (cubo[2][2][5]==3) && (cubo[0][0][2]==1) && (cubo[0][2][2]==5) && (cubo[0][0][3]==2) && (cubo[0][2][3]==5))
		caso7_9 ()
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][5]==5) && (cubo[0][2][5]==3) && (cubo[2][0][5]==1) && (cubo[2][2][5]==2) && (cubo[0][0][2]==5) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==4))  
		caso7_10 ()
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][5]==1) && (cubo[0][2][5]==3) && (cubo[2][0][5]==) && (cubo[2][2][5]==3) && (cubo[0][0][2]==5) && (cubo[0][2][2]==5) && (cubo[0][0][3]==2) && (cubo[0][2][3]==4)) 
		caso7_11 ()
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][5]==1) && (cubo[0][2][5]==3) && (cubo[2][0][5]==2) && (cubo[2][2][5]==2) && (cubo[0][0][2]==1) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==4)) 
		caso7_12 ()
		
/* Caso7.1 forma 1: El vértice necesita un giro en el sentido horario. */	
void caso7_1();
{
	printf("Tienes el primer caso\n");
	printf("Debes completar el cubo \n Realiza los siguientes pasos:\n ");
	printf("1. La cara blanca abajo\n 2. Gira la cara derecha 90° hacia abajo.\n");
	printf("3. Gira la base 90° a la derecha.\n 4. Gira la cara derecha 90° hacia la derecha.\n");
	printf("5. Gira la base 90° a la izquierda.\n 6. Gira la cara derecha 90° hacia abajo.\n");
	printf("7. Gira la base 90° a la derecha.\n 8. Gira la cara derecha 90° hacia la derecha. \n");
	printf("9. Gira la base 90° a la izquierda.\n 10. \n");
	return 0;
}

/* Caso7.2 forma 1: El vértice necesita un giro en el sentido anti-horario. */
void caso7_2(int matriza[3][3], int matrizb[3][3], int matrizf[3][3], int matrizt[3][3], int matrizi[3][3], int matrizd[3][3]);
{
	printf("Tienes el segundo caso\n");
	printf("Debes completar el cubo\n Realiza los siguientes pasos:\n ");
	printf("1. La cara blanca abajo\n 2. Gira la base 90° a la derecha.\n");
	printf("3. Gira la cara derecha 90° hacia abajo.\n 4. Gira la base 90° a la izquierda.\n");
	printf("5. Gira la cara derecha 90° hacia la derecha.\n 6. Gira la base 90° a la derecha.\n");
	printf("7. Gira la cara derecha 90° hacia abajo.\n 8. Gira la base 90° a la izquierda.\n");
	printf("9. Gira la cara derecha 90° hacia la derecha. \n 10. \n");
	return 0;
}

void caso7_3
	{
		printf("Debes completar el cubo \n Realiza los siguientes pasos:\n ");
		printf("1. Pon la cara amarilla arriba\n 2.Gira la cara derecha 90° hacia abajo. \n");
		printf("3.Gira la base 90° a la derecha \n 4.Gira la cara derecha 90° hacia la derecha.  \n");
		printf("5.Gira la base 90° a la izquierda. \n 6.Gira la cara derecha 90° hacia abajo. \n");
		printf("7.Gira la base 90° a la derecha. \n 8.Gira la cara derecha 90° hacia la derecha.  \n");
		printf("9. Gira la base 90° a la izquierda. \n 10.Gira la cara superior 90° a la izquierda. \n");
		printf("11.Gira la base 90° a la derecha. \n 12.Gira la cara derecha 90° hacia abajo. \n");
		printf("13. Gira la base 90° a la izquierda. \n 14.Gira la cara derecha 90° hacia la derecha. \n");	
		printf("15. Gira la base 90° a la derecha. \n 16. Gira la cara derecha 90° hacia abajo. \n");
		printf("17. Gira la base 90° a la izquierda. \n 18. Gira la cara derecha 90° hacia la derecha. \n);
		printf ("19. Gira la cara superior 90° a la derecha. \n");
		return 0;
	}

void caso7_4()
{
	printf("Debes completar el cubo\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara amarilla arriba\n 2. Gira la base 90° a la derecha.\n");
	printf("3. Gira la cara derecha 90° hacia abajo.\n 4. Gira la base 90° a la izquierda.\n");
	printf("5. Gira la cara derecha 90° hacia la derecha.\n 6. Gira la base 90° a la derecha.\n");
	printf("7. Gira la cara derecha 90° hacia abajo.\n 8. Gira la base 90° a la izquierda.\n");
	printf("9. Gira la cara derecha 90° hacia la derecha.\n 10. Gira la cara superior 90° a la izquierda.\n");
	printf("11. Gira la base 90° a la derecha.\n");
	printf("12. Gira la cara derecha 90° hacia abajo.\n 13. Gira la base 90° a la izquierda.\n");
	printf("14. Gira la cara derecha 90° hacia la derecha.\n 15. Gira la base 90° a la derecha.\n");
	printf("16. Gira la cara derecha 90° hacia abajo.\n 17. Gira la base 90° a la izquierda.\n");
	printf("18. Gira la cara derecha 90° hacia la derecha.\n 19. Gira la cara superior 90° a la izquierda.\n");
	printf("20. Gira la base 90° a la derecha.\n");
	printf("21. Gira la cara derecha 90° hacia abajo.\n 22. Gira la base 90° a la izquierda.\n");
	printf("23. Gira la cara derecha 90° hacia la derecha.\n 24. Gira la base 90° a la derecha.\n");
	printf("25. Gira la cara derecha 90° hacia abajo.\n 26. Gira la base 90° a la izquierda.\n");
	printf("27. Gira la cara derecha 90° hacia la derecha.\n 28. Gira la cara superior 180° a la izquierda.\n");
	return 0;
}

void caso7_5 ();
	{
		printf("Debes completar el cubo \n Realiza los siguientes pasos:\n ");
		printf("1.Pon la cara amarilla hacia arriba\n 2.Gira la base 90° a la derecha.\n");
		printf("3. Gira la cara derecha 90° hacia abajo.\n 4.Gira la base 90° a la izquierda.\n");
		printf("5.Gira la cara derecha 90° hacia la derecha. \n 6. Gira la base 90° a la derecha.n");
		printf("7.Gira la cara derecha 90° hacia abajo.\n 8.Gira la base 90° a la izquierda.\n");
		printf("9. Gira la cara derecha 90° hacia la derecha. \n 10. Gira la cara superior 90° a la izquierda.\n");
		printf("11.Gira la cara derecha 90° hacia abajo.\n 12.Gira la base 90° a la derecha.\n");
		printf("13.Gira la cara derecha 90° hacia la derecha.\n 14.Gira la base 90° a la izquierda.\n");
		printf("15.Gira la cara derecha 90° hacia abajo. \n 16. Gira la base 90° a la derecha.\n");
		printf("17.Gira la cara derecha 90° hacia la derecha.\n 18.Gira la base 90° a la izquierda. \n");
		printf("19.Gira la cara superior 90° a la izquierda.\n 20.Gira la base 90° a la derecha.\n");
		printf("21. Gira la cara derecha 90° hacia abajo.\n 22.Gira la base 90° a la izquierda.\n");
		printf("23.Gira la cara derecha 90° hacia la derecha. \n 24. Gira la base 90° a la derecha.n");
		printf("25.Gira la cara derecha 90° hacia abajo.\n 26.Gira la base 90° a la izquierda.\n");
		printf("27. Gira la cara derecha 90° hacia la derecha. \n 28. Gira la cara superior 90° a la izquierda.\n");
		printf("29.Gira la cara derecha 90° hacia abajo.\n 30.Gira la base 90° a la derecha.\n");
		printf("31.Gira la cara derecha 90° hacia la derecha.\n 32.Gira la base 90° a la izquierda.\n");
		printf("33. Gira la cara derecha 90° hacia abajo. \n 34. Gira la base 90° a la derecha.\n");
		printf("35.Gira la cara derecha 90° hacia la derecha.\n 36.Gira la base 90° a la izquierda. \n");
		printf("37. Gira la cara superior 90° a la izquierda.\n");
		return 0;
	}

void caso7_6();
{
	printf("Debes completar el cubo\n Realiza los siguientes pasos:\n ");
	printf("1. Con la cara amarilla arriba\n 2. Gira la cara derecha 180° hacia la derecha.\n");
	printf("3. Gira la cara superior 90° a la izquierda.\n 4. Gira la cara trasera 180° a la izquierda.\n");
	printf("5. Gira la cara superior 90° a la derecha.\n 6. Gira la cara derecha 90° hacia la derecha.\n");
	printf("7. Gira la cara frontal 180° a la derecha.\n 8. Gira la cara derecha 90° hacia abajo.\n");
	printf("9. Gira la cara superior 90° a la izquierda.\n 10. Gira la cara trasera 180° a la izquierda.\n");
	printf("11. Gira la cara superior 90° a la derecha.\n");
	printf("12. Gira la cara derecha 90° hacia la derecha.\n 13. Gira la cara frontal 180° a la derecha.\n");
	printf("14. Gira la cara derecha 90° hacia la derecha.\n");
	return 0;
}

void caso7_7();
{
	printf("Tienes el segundo caso\n");
	printf("Debes completar el cubo\n Realiza los siguientes pasos:\n ");
	printf("1.Pon la cara amarilla arriba \n 2.Gira la cara frontal 180° a la derecha.\n");
	printf("3.Gira la base 90° a la izquierda.\n 4.Gira la cara frontal 180° a la derecha.\n");
	printf("5.Gira la cara superior 90° a la izquierda. \n 6.Gira la cara frontal 90° a la izquierda. \n");
	printf("7.Gira la cara izquierda 180° hacia abajo/derecha.\n 8.Gira la cara superior 90° a la izquierda.\n");
	printf("9.Gira la cara izquierda 180° hacia abajo/derecha.\n 10.Gira la cara superior 90° a la derecha.\n");
	printf("11.Gira la cara frontal 180° a la derecha.\n 12.Gira la base 90° a la derecha.\n");
	printf("13.Gira la cara frontal 90° a la izquierda. \n 14.Gira la cara superior 90° a la derecha. \n");
	return 0;
}

void caso7_8();
{
	printf("Tienes el tercer caso\n");
	printf("Debes completar el cubo\n Realiza los siguientes pasos:\n ");
	printf("1.Pon la cara amarilla arriba \n 2.Gira la cara frontal 90° a la derecha.\n");
	printf("3.Gira la cara izquierda 90° hacia arriba/izquierda. \n 4.Gira la base 180° a la derecha.\n");
	printf("5.Gira la cara izquierda 90° hacia abajo/derecha.\n 6.Gira la cara frontal 90° a la izquierda.\n");
	printf("7.Gira la cara superior 180° a la izquierda.\n 8.Gira la cara frontal 90° a la derecha.\n");
	printf("9.Gira la cara izquierda 90° hacia arriba/izquierda.\n 10.Gira la base 180° a la derecha.\n");
	printf("11.Gira la cara izquierda 90° hacia abajo/derecha.\n 12.Gira la cara frontal 90° a la izquierda.\n");
	printf("13.Gira la cara superior 180° a la izquierda.\n");
	return 0;
}

void caso7_9 ();
{
	printf("Debes completar el cubo\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara amarilla arriba\n 2.Gira la cara frontal 90° a la derecha. \n");
	printf("3.Gira la cara superior 90° a la derecha. \n 4.Gira la cara trasera 90° a la izquierda. \n");
	printf("5.Gira la cara superior 180° a la izquierda. \n 6.Gira la cara frontal 180° a la derecha. \n");
	printf("7.Gira la base 90° a la izquierda. \n 8.Gira la cara izquierda 180° hacia abajo/derecha. \n");
	printf("9.Gira la base 90° a la derecha. \n 10.Gira la cara superior 90° a la izquierda. \n");
	printf("11. Gira la cara trasera 90° a la derecha.\n 12.Gira la cara superior 90° a la derecha. \n");
	printf("13. Gira la cara frontal 90° a la derecha. \n 14.Gira la cara superior 90° a la derecha. \n");
	return 0;
	
}

void caso7_10 ();
{
	printf("Debes completar el cubo\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara amarilla arriba\n 2.Gira la cara derecha 90° hacia abajo.\n");
	printf("3.Gira la cara superior 90° a la izquierda.\n 4.Gira la cara izquierda 90° hacia abajo/derecha.\n");
	printf("5.Gira la base 90° a la izquierda.\n 6.Gira la cara superior 90° a la derecha.\n");
	printf("7.Gira la cara frontal 180° a la derecha.\n 8.Gira la base 90° a la derecha.\n");
	printf("9.Gira la cara derecha 180° hacia la derecha.  \n 10.Gira la cara superior 180° a la izquierda. \n");
	printf("11.Gira la cara izquierda 90° hacia arriba/izquierda.  \n 12.Gira la cara superior 90° a la izquierda.\n");
	printf("13.Gira la cara derecha 90° hacia abajo. \n 14.Gira la cara superior 90° a la izquierda.\n");
	return 0;
}

void caso7_11 ();
{
	printf("\nUna vez con la cruz hecha y los aristas en su lugar procedemos \n con los siguientes movimientos\n");
	printf("1. Gira la cara derecha 90° hacia Abajo.\n");
	printf("2. Gira la cara superior 180° a la Izquierda.\n");
	printf("3. Gira la cara superior 90° a la Derecha.\n");   
	printf("4. Gira la cara superior 180° a la izquierda.\n");
	printf("5. Gira la cara derecha 180° hacia la derecha.\n");
	printf("6. Gira la cara trasera 90° a la izquierda.\n");
	printf("7. Gira la base 90° a la izquierda.\n");
	printf("8. Gira la cara derecha 90° hacia abajo.\n");
	printf("9. Gira la cara frontal 90° a la derecha.\n");
	printf("10. Gira la cara derecha 90° hacia la derecha.\n");
	printf("11. Gira la cara frontal 90° a la izquierda.\n");	
	return 0;
}

void caso7_12 ();
{
	printf("\nUna vez con la cruz hecha y los aristas en su lugar procedemos \n con los siguientes movimientos\n");
	printf("1. Gira la cara izquierda 90° hacia arriba/izquierda.\n");
	printf("2.Gira la cara derecha 90° hacia la derecha. \n");
	printf("3. Gira la base 90° a la derecha.\n");   
	printf("4. Gira la cara izquierda 180° hacia abajo/derecha.\n");
	printf("5. Gira la cara superior 180° hacia la izquierda.\n");
	printf("6. Gira la cara izquierda 90° hacia abajo/derecha.\n");
	printf("7. Gira la base 90° a la izquierda.\n");
	printf("8. Gira la cara izquierda 180° hacia abajo/derecha.\n");
	printf("9. Gira la cara superior 180° a la izquierda.\n");
	printf("10. Gira la cara derecha 90° hacia abajo.\n");
	printf("11. Gira la cara superior 90° a la izquierda.\n");
	printf("12. Gira la cara derecha 180° hacia la derecha.\n");
	printf("13. Gira la cara trasera 180° a la izquierda.\n");
	printf("14. Gira la cara derecha 180° hacia la derecha.\n");
	printf("15. Gira la cara superior 90° a la izquierda.\n");
	return 0;
}
