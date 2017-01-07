#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define white "\033[0;47m"
#define yellow "\033[1;43m"
#define red "\033[0;41m"
#define green "\033[0;42m"
#define blue "\033[1;44m"
#define orange "\033[0;45m"
#define termina "\033[0m"
#define espacio "  "

char cad [1];
int validar(void)
{

	int i, numero;
    	
	if (!isdigit(cad [0]))
	{
		printf("NO ES UN NUMERO \n");
		numero=9;
		return(numero);
	}
	else
	{
		numero=cad[0]-48;
		return(numero);
	}
}

	int cubo[3][3][6]; /*Matriz de tres dimensiones para llenar*/
	char opc_color[20]; /*Nombre de los centros*/
	void color(int z); /*Funcion para llamar cada matriz con centro de color, opc_color*/
	int comprobar(int aux); /*Funcion para comprobar que solo se ingresen numeros, que esos numeros sean del 0 al 5 y que cada numero no se repita mas de 9 veces */
	void llenar(); /*Funcion que sirve para llenar la matriz antes para que la busqueda de las nueve veces funcione.*/
	void combinacion(); /*Funcion que sirve para llenar las matrices.*/
	int validacion_combinacion(); /*validad que las combinaciones iniciales sean las correspondientes para el algoritmo*/
	void movimiento_cara(int cara); /*Funcion que sirve para girar la cara.*/
	void girototal(int cara,int caso); /*Funcion que sirve para hacer todos los giros, y que se cambien los colores de las matrices.*/
	void busqueda_validacion1(); /* paso1 cruz superior */
	void caso1_1(); /* Caso 1: arista en la capa inferior con el blanco hacia abajo. */
	void caso1_2(); /*Caso 2 arista en la capa inferior con el blanco hacia abajo. */
	void caso1_3(); /*  Caso 3: arista en la capa intermedia, se reduce a un caso anterior. */
	void busqueda_validacion2(); /* paso 2: completar la cara superior */
	void caso2_1(); /* paso 2_1: el vértice tiene el color blanco en la cara frontal. */
	void caso2_2(); /* paso 2.2: el vértice tiene el color blanco en la cara derecha. */
	void caso2_3(); /* paso 2.1: el vértice tiene el color blanco abajo.*/
	void busqueda_validacion3(); /* paso 3: completar la segunda capa */
	void caso3_1(); /* paso 3.1: la arista queda a la derecha del hueco donde va. */
	void caso3_2(); /* paso 3.2: el vértice tiene el color blanco en la cara derecha. */
	void busqueda_validacion4(); /* paso 4: cruz en la última cara */
	void caso4_1(); /* paso 4.1: la arista queda a la derecha del hueco donde va. */
	void caso4_2(); /* paso 4.2: el vértice tiene el color blanco en la cara derecha. */
	void caso4_3(); /* paso 4.3: el vértice tiene el color blanco en la cara derecha. */
	void busqueda_validacion5(); /* paso 5: Extender la cruz a la última capa */
	void caso5_1(); /* paso 5.1: Conseguimos 2 aristas adyacentes colocadas en su sitio */
	void caso5_2(); /* paso 5.2: Conseguimos 2 aristas opuestas colocadas en su sitio.  */
	void busqueda_validacion6(); /* Paso 6: colocar los últimos vértices (sin orientar) */
	void caso6_1(); /* paso 6.1: Un vértice está en su sitio y los otros 3 se deben intercambiar en sentido horario. */
	void caso6_2(); /* paso 6.2: Un vértice está en su sitio y los otros 3 se deben intercambiar en sentido anti-horario. */
	void caso6_3(); /* Paso 6.3: Los dos vértices se deben intercambiar entre si y los dos frontales también.*/
	void caso6_4(); /* Paso 6.4: Los vértices se deben intercambiar en cruz.*/
	void busqueda_validacion7();/* Caso 7: girar los vértices para ¡terminar el cubo! */
	void caso7_1(); /* Caso7.1 forma 1: El vértice necesita un giro en el sentido horario. */
	void caso7_2();/* Caso7.2 forma 1: El vértice necesita un giro en el sentido anti-horario. */
	void caso7_3();
	void caso7_4();
	void caso7_5();
	void caso7_6();
	void caso7_7();
	void caso7_8();
	void caso7_9();
	void caso7_10();
	void caso7_11();
	void caso7_12();
	void mostrar_cubo(); /*Funcion que imprime cubo, 0=blanco, 1=rojo,  2=azul, 3=naranja, 4=verde, 5=amarillo */
	int menu();
	FILE *guarda_pasos; /*Archivo donde se guardan los pasos*/
	void guarda_datos(); /*Funcion que guarda los pasos realizados*/
	void lee_datos(); /*Archivo que muestra los pasos realizados*/
	
	int main(void){
		int opc,opc1, valid,op1;
			printf("Ingresa la combinacion guiandose de la siguiente simbologia\n0) Blanco\n1) Rojo \n2) Azul \n3) Naranja \n4) Verde \n5) Amarillo\n");
			llenar();
			combinacion();
		do{
				
				valid=validacion_combinacion(); 				
				do
				{
					printf("Esta combinancion no es valida, para este algoritmo.\n1) Salir del programa  \n2)Volver a hacer la combinacion\n");
					scanf("%s", cad);
					op1=validar();
				}while (op1==9);
				
				if(op1==1){
					printf("Gracias por utilizar este programa\n");
					exit(1);
				}
				else
				combinacion();
						
			}while((op1==2)||(valid==0));
			
			do{
				opc= menu();
		
				switch(opc){
					case 1:
						mostrar_cubo();
						break;
				
					case 2:
						do
						{
							printf("1) Paso 1\n 2) Paso 2\n 3) Paso 3\n 4) Paso 4\n 5) Paso 5\n 6) Paso 6\n 7) Paso 7\n Opcion:\t");
							scanf("%s", cad);
							opc1=validar();
						}while (opc1==9);
						switch(opc1){
							case 1: busqueda_validacion1();
									menu();
									break;
							case 2: busqueda_validacion2();
									menu();
									break;
							case 3: busqueda_validacion3();
									menu();
									break;
							case 4: busqueda_validacion4();
									menu();
									break;
							case 5: busqueda_validacion5();
									menu();
									break;
							case 6: busqueda_validacion6();
									menu();
									break;
							case 7: busqueda_validacion7();
									menu();
									break;
						   default: printf("Esta opcion no existe, favor de volver a ingresar una\n");
									break;
						}
						break;
				   
				    case 3: lee_datos();
				    		break;
			        		
			        case 4: printf("Gracias por utilizar este programa\n");
			        		break;
			        	
				   default: printf("Esta opcion no existe, favor de volver a ingresar una\n");	
							break;
				}
		
			}while(opc!=3);
	}
	
	void color(int z) /*Funcion para llamar cada matriz con centro de color, opc_color*/
{
	switch(z)
	{	
	case 0:		
		strcpy(opc_color,"Blanco");
		break;
	case 1:
		strcpy(opc_color,"Rojo");
		break;
	case 2:
		strcpy(opc_color,"Azul");
		break;
	case 3:
		strcpy(opc_color,"Naranja");
		break;
	case 4:
		strcpy(opc_color,"Verde");
		break;
	case 5:
		strcpy(opc_color,"Amarillo");
		break;		
	}
}
int comprobar(int aux){ /*Funcion para comprobar que solo se ingresen numeros, que esos numeros sean del 0 al 5 y que cada numero no se repita mas de 9 veces */
	int z,y,x,i=0,temp=0;
	//int aux = atoi(a);	
	for(z=0; z<6; z++)
	{
		for(y=0; y<3; y++)
		{
			for(x=0; x<3; x++){
				if(cubo[x][y][z]==aux)
					i++;
			}
		}			
	}
	if(aux>5 || aux<0)
	{
		printf("Error: ese no es un color\n");
		temp=1;
	}
	if(i>8)
	{
		color(aux);
		printf("El color %s esta agotado\n", opc_color);
		temp=1;
	}
	return temp;
}
void llenar() /*Funcion que sirve para llenar la matriz antes para que la busqueda de las nueve veces funcione.*/
{
	int z,x,y;
	for (z=0; z<6; z++)
		for(y=0; y<3; y++)
			for(x=0; x<3; x++)
				cubo[x][y][z]=6;
	
}
void combinacion(){ /*Funcion que sirve para llenar las matrices.*/
	
	int z=0,y=0,x=0,aux;
	/*for que maneja las caras*/
	do
		{
		for (z=0; z<6; z++){
		color(z);
			printf("Ingresa la cara con centro %s\n",opc_color);
			for(y=0; y<3; y++)
			{
				for(x=0; x<3; x++)
				{
					scanf("%s",cad);
					aux=validar();
					if(comprobar(aux)==0)
						cubo[x][y][z]=aux;
				}			
			}
		cubo[1][1][z]=z;
    	}
	}while (aux==9);	
}

void movimiento_cara(int cara) /*Funcion que sirve para girar la cara.*/
{
	int res[3][3],x;
		
		for(x=0;x<3;x++){
			res[x][0]=cubo[x][0][cara];
			res[x][1]=cubo[x][1][cara];
			res[x][2]=cubo[x][2][cara];
		}
		for(x=0;x<3;x++)
		{
			cubo[0][x][cara]=res[x][2];
			cubo[1][x][cara]=res[x][1];
			cubo[2][x][cara]=res[x][0];
	   }
}

void girototal(int cara,int caso) /*Funcion que sirve para hacer todos los giros, y que se cambien los colores de las matrices.*/
{
int res[4][3],num_caras[4],x;	
	if(cara==0)
	{
		if(caso == 1)
		{
			num_caras[0]=0;num_caras[1]=3;num_caras[2]=5;num_caras[3]=1;
		}
		if(caso==2)
		{
			num_caras[0]=0;num_caras[1]=4;num_caras[2]=5;num_caras[3]=2;
		}
		if(caso==3)
		{
			num_caras[0]=0;num_caras[1]=3;num_caras[2]=5;num_caras[3]=1;
		}
		if(caso==4)
		{
			num_caras[0]=0;num_caras[1]=4;num_caras[2]=5;num_caras[3]=2;
		}
	}
	if(cara==1)
	{
		if(caso==1)
		{		
			num_caras[0]=1;num_caras[1]=2;num_caras[2]=3;num_caras[3]=4;
		}
		if(caso==2)
		{
			num_caras[0]=1;num_caras[1]=0;num_caras[2]=3;num_caras[3]=5;
		}
		if(caso==3)
		{
			num_caras[0]=1;num_caras[1]=2;num_caras[2]=3;num_caras[3]=2;
		}
		if(caso==4)
		{
			num_caras[0]=1;num_caras[1]=0;num_caras[2]=3;num_caras[3]=5;
		}
	}
	if(cara==2)
	{
		if(caso==1)
		{
			num_caras[0]=2;num_caras[1]=3;num_caras[2]=4;num_caras[3]=1;
		}
		if(caso==2)
		{
			num_caras[0]=2;num_caras[1]=0;num_caras[2]=4;num_caras[3]=5;
		}
		if(caso==3)
		{
			num_caras[0]=2;num_caras[1]=3;num_caras[2]=4;num_caras[3]=1;
		}
		if(caso==4)
		{
			num_caras[0]=2;num_caras[1]=0;num_caras[2]=4;num_caras[3]=5;
		}
	}
	if(cara==3)
	{
		if(caso==1)
		{
			num_caras[0]=3;num_caras[1]=4;num_caras[2]=1;num_caras[3]=2;
		}
		if(caso==2)
		{
			num_caras[0]=3;num_caras[1]=0;num_caras[2]=1;num_caras[3]=5;
		}
		if(caso==3)
		{
			num_caras[0]=3;num_caras[1]=4;num_caras[2]=1;num_caras[3]=2;
		}
		if(caso==4)
		{
			num_caras[0]=3;num_caras[1]=0;num_caras[2]=1;num_caras[3]=5;
		}
	}
	if(cara==4)
	{
		if(caso==1)
		{
			num_caras[0]=4;num_caras[1]=1;num_caras[2]=2;num_caras[3]=3;
		}
		if(caso==2)
		{
			num_caras[0]=4;num_caras[1]=0;num_caras[2]=2;num_caras[3]=5;
		}
		if(caso==3)
		{
			num_caras[0]=4;num_caras[1]=1;num_caras[2]=2;num_caras[3]=3;
		}
		if(caso==4)
		{
			num_caras[0]=4;num_caras[1]=0;num_caras[2]=2;num_caras[3]=5;
		}
	}
	if(cara==5)
	{
		if(caso==1)
		{
			num_caras[0]=5;num_caras[1]=3;num_caras[2]=0;num_caras[3]=1;
		}
		if(caso==2)
		{
			num_caras[0]=5;num_caras[1]=2;num_caras[2]=0;num_caras[3]=4;
		}
		if(caso==3)
		{
			num_caras[0]=5;num_caras[1]=3;num_caras[2]=0;num_caras[3]=1;
		}
		if(caso==4)
		{
			num_caras[0]=5;num_caras[1]=2;num_caras[2]=0;num_caras[3]=4;
		}
	}
		if(caso==1)
		{
			for(x=0;x<3;x++)
			{				
				res[0][x]=cubo[0][x][num_caras[0]];				
				res[1][x]=cubo[0][x][num_caras[1]];			
				res[2][x]=cubo[0][x][num_caras[2]];				
				res[3][x]=cubo[0][x][num_caras[3]];	
			}
			for(x=0;x<3;x++)
			{			
				cubo[0][x][num_caras[0]]= res[3][x];			
				cubo[0][x][num_caras[1]]= res[0][x];				
				cubo[0][x][num_caras[2]]= res[1][x];				
				cubo[0][x][num_caras[3]]= res[2][x]; 
			}
			movimiento_cara(cara);
		}
		if(caso==2)
		{
			
			for(x=0;x<3;x++)
			{
				res[x][0]=cubo[x][2][num_caras[0]];
				res[x][1]=cubo[x][2][num_caras[1]];
				res[x][2]=cubo[x][2][num_caras[2]];
				res[x][3]=cubo[x][2][num_caras[3]];
				
			}
			for(x=0;x<3;x++)
			{
				cubo[x][2][num_caras[0]]=res[x][3];
				cubo[x][2][num_caras[1]]=res[x][0];
				cubo[x][2][num_caras[2]]=res[x][1];
				cubo[x][2][num_caras[3]]=res[x][2];
			}			
			movimiento_cara(cara);
			movimiento_cara(cara);
			movimiento_cara(cara);
		}
		if(caso==3)
		{
			for(x=0;x<3;x++)
			{
				res[0][x]=cubo[2][x][num_caras[0]];
				res[1][x]=cubo[2][x][num_caras[1]];
				res[2][x]=cubo[2][x][num_caras[2]];
				res[3][x]=cubo[2][x][num_caras[3]];
			}
			for(x=0;x<3;x++)
			{
				cubo[2][x][num_caras[0]] = res[3][x];
				cubo[2][x][num_caras[1]] = res[0][x];
				cubo[2][x][num_caras[2]] = res[1][x];
				cubo[2][x][num_caras[3]] = res[2][x];
			}	
			movimiento_cara(cara);
					
		}
		if(caso==4)
		{
			
			for(x=0;x<3;x++)
			{
				res[x][0]=cubo[x][0][num_caras[0]];
				res[x][1]=cubo[x][0][num_caras[1]];
				res[x][2]=cubo[x][0][num_caras[2]];
				res[x][3]=cubo[x][0][num_caras[3]];
				
			}
			for(x=0;x<3;x++)
			{
				cubo[x][0][num_caras[0]] = res[x][3];
				cubo[x][0][num_caras[1]] = res[x][0];
				cubo[x][0][num_caras[2]] = res[x][1];
				cubo[x][0][num_caras[3]] = res[x][2];
			}
			movimiento_cara(cara);	
			movimiento_cara(cara);
			movimiento_cara(cara);		
		}					
}


void mostrar_cubo(){ /*Funcion que imprime cubo*/
	int z, x, y;
	for(z=0; z<6; z++){
		color(z);
		printf("Impresion de la cara %s\n", opc_color);
		for(y=0; y<3; y++){
			for(x=0; x<3; x++){	
			if (cubo[x][y][z]==0)
                   printf("%s%s%s", white, espacio, termina);
                if (cubo[x][y][z]==1)
                   printf("%s%s%s", red, espacio, termina);
                if(cubo[x][y][z]==2)
                   printf("%s%s%s", green, espacio, termina);
                if(cubo[x][y][z]==3)
                   printf("%s%s%s", blue, espacio, termina);
                if(cubo[x][y][z]==4)
                   printf("%s%s%s", yellow, espacio, termina);
                if(cubo[x][y][z]==5)
                   printf("%s%s%s", orange, espacio, termina);
			}
			printf("\n");
		}
	}
}


int menu()
{
	int opcion;
	do
	{
		printf("\n1) Mostrar el cubo\n");
		printf("2) Mostrar algoritmo\n");
		printf("3) Mostrar pasos realizados\n");
		printf("4) Salir del programa\n");
		scanf("%s", cad);
		opcion=validar();
	}while(opcion==9);
	return(opcion);
}

	int validacion_combinacion() /*valida que las combinaciones iniciales sean las correspondientes para el algoritmo*/
	{
		int op=0;
			if(((cubo[1][1][0]==0)&&(cubo[1][1][1]== 1)&&(cubo[1][1][2]==2)&&(cubo[2][1][2]==1)&&(cubo[1][2][4]==0))||
			((cubo[1][1][0]==0)&&(cubo[1][2][0]==0)&&(cubo[1][1][1]== 1)&&(cubo[2][1][1]==0)&&(cubo[0][1][2]==2)&&(cubo[1][1][2]==2))||
			((cubo[0][1][0]==0)&&(cubo[1][0][0]==0)&&(cubo[1][1][0]==0)&&(cubo[1][2][0]==0)&&(cubo[1][1][1]== 1)&&(cubo[1][2][1]== 0)&&(cubo[0][1][2]==2)&&(cubo[1][0][2]==1)&&(cubo[1][1][2]==2)))
			{
			 
			 op=1;
			}
			 	 
	 return(op);		
	}

	void busqueda_validacion1() /* paso1 cruz superior */
{
	do{
		if ((cubo[1][1][0]==0)&&(cubo[1][1][2]== 2)&&(cubo[1][1][1]==1)&&(cubo[2][1][2]==1)&&(cubo[1][2][5]==0))
	{
		caso1_1();
		guarda_datos();
		
	}
    if ((cubo[1][1][0]==0)&&(cubo[1][2][0]==0)&&(cubo[1][1][1]== 1)&&(cubo[2][1][1]==0)&&(cubo[0][1][2]==2)&&(cubo[1][1][2]==2));
	{
		caso1_2();
		guarda_datos();
	}
	if ((cubo[0][1][0]==0)&&(cubo[1][0][0]==0)&&(cubo[1][1][0]==0)&&(cubo[1][2][0]==0)&&(cubo[1][1][1]== 1)&&(cubo[1][2][1]== 0)&&(cubo[0][1][2]==2)&&(cubo[1][0][2]==1)&&(cubo[1][1][2]==2))
	{
		caso1_3 ();
		guarda_datos();
    }
	}while(((cubo[1][1][0]==0)&&(cubo[1][1][1]== 1)&&(cubo[1][1][2]==2)&&(cubo[2][1][2]==1)&&(cubo[1][2][4]==0))||
	((cubo[1][1][0]==0)&&(cubo[1][2][0]==0)&&(cubo[1][1][1]== 1)&&(cubo[2][1][1]==0)&&(cubo[0][1][2]==2)&&(cubo[1][1][2]==2))||
	((cubo[0][1][0]==0)&&(cubo[1][0][0]==0)&&(cubo[1][1][0]==0)&&(cubo[1][2][0]==0)&&(cubo[1][1][1]== 1)&&(cubo[1][2][1]== 0)&&(cubo[0][1][2]==2)&&(cubo[1][0][2]==1)&&(cubo[1][1][2]==2)));


}

	void guarda_datos(){
		int x,y,z;
		
		guarda_pasos=fopen("Visualizar pasos.txt","a+");
		for(z=0;z<6;z++){
			color(z);
			printf("Cara con centro %s\n",opc_color);
			for(y=0;y<3;y++){
				for(x=0;x<3;x++)
					fprintf(guarda_pasos,"%d", cubo[x][y][z]);
			}
		}
		fclose(guarda_pasos);
		
	}
	
	void lee_datos(){
		int lee[54];
		 
		guarda_pasos=fopen("Visualizar pasos.txt","r");
		if(guarda_pasos==NULL)
			printf("No existe el archivo\n");
		else
			fread(lee,sizeof(int),54,guarda_pasos);
			
		fclose(guarda_pasos);
	}

void caso1_1()/* Caso 1: arista en la capa inferior con el blanco hacia abajo. */
{
	printf("Tienes el primer caso\n");
	printf("Debes hacer una cruz arriba de color blanco \n realiza los siguientes pasos \n ");
	printf("1.- Toma la cara que tiene al rojo en el centro como frontal y la cara con centro blanco como superficie \n 2.- Gira la base 90° a la izquierda \n 3.-Gira 180° la cara frontal hacia la derecha \n");
	                        
						girototal(1,3);girototal(1,3);girototal(1,3);girototal(4,2);
						girototal(4,2);
}


void caso1_2()/*Caso 2 arista en la capa inferior con el blanco hacia abajo. */
{
	printf("Tienes el primer caso\n");
	printf("Debes hacer una cruz arriba de color blanco \n realiza los siguientes pasos \n ");
	printf("1.- Toma la cara que tiene al rojo en el centro \n 2.- Gira la base 90° a la derecha.\n");
	printf("3. Gira la cara derecha 90° hacia la derecha.\n 4. Gira la cara frontal 90° a la izquierda.\n");
	printf("5. Gira la cara derecha 90° hacia abajo.\n");
						
						girototal(1,3);girototal(5,2);girototal(5,1);girototal(1,1);
}



void caso1_3() /*  Caso 3: arista en la capa intermedia, se reduce a un caso anterior. */
{
	printf("Tienes el tercer caso\n");
	printf("Debes hacer una cruz arriba de color blanco \n realiza los siguientes pasos \n ");
	printf("1.- Toma la cara que tiene rojo  en el centro y a la dercha blanco como frente \n 2.- gira la cara derecha hacia abajo 90° \n 3.-Gira la base hacia la izquierda 90°\n 4.-Gira la cara derecha 90° hacia arriba \n");
			
						girototal(1,2);girototal(1,2);girototal(1,2);girototal(1,3);
						girototal(1,3);girototal(1,3);girototal(1,2);
}

	void busqueda_validacion2() /* paso 2: completar la cara superior */
{
	do{
		if ((cubo[0][1][0]==0)&&(cubo[1][0][0]==0)&&(cubo[1][1][0]==0)&&(cubo[1][2][0]==0)&&(cubo[2][1][0]==0)&&(cubo[0][1][1]==1)&&(cubo[1][1][1]==1)&&(cubo[2][2][1]==0) && (cubo[0][1][2]==2) && (cubo[1][1][2]==2) && (cubo[2][0][2]==2))
	{
		caso2_1();
		guarda_datos();
	}
	if ((cubo[0][1][0]==0)&&(cubo[1][0][0]==0)&&(cubo[1][1][0]==0) &&(cubo[1][2][0]==0)&&(cubo[2][1][0]==0)&&(cubo[0][1][1]==1)&&(cubo[1][1][1]==1)&&(cubo[2][2][1]==1)&&(cubo[0][1][2]==2)&&(cubo[1][1][2]==2)&&(cubo[2][0][2]==0))
	{
		caso2_2();
		guarda_datos();
	}
	if ((cubo[0][1][0]==0) && (cubo[1][0][0]==0) && (cubo[1][1][0]==0)  && (cubo[1][2][0]==0) && (cubo[2][1][0]==0)&& (cubo[0][1][1]==1) && (cubo[1][1][1]==1) && (cubo[2][2][1]==2) && (cubo[0][1][2]==2) && (cubo[1][1][2]==2) && (cubo[2][0][2]==1))		
	{
		caso2_3();
		guarda_datos();
	}
	}while(((cubo[0][1][0]==0)&&(cubo[1][0][0]==0)&&(cubo[1][1][0]==0)&&(cubo[1][2][0]==0)&&(cubo[2][1][0]==0)&&(cubo[0][1][1]==1)&&(cubo[1][1][1]==1)&&(cubo[2][2][1]==0) && (cubo[0][1][2]==2) && (cubo[1][1][2]==2) && (cubo[2][0][2]==2))||
	((cubo[0][1][0]==0)&&(cubo[1][0][0]==0)&&(cubo[1][1][0]==0) &&(cubo[1][2][0]==0)&&(cubo[2][1][0]==0)&&(cubo[0][1][1]==1)&&(cubo[1][1][1]==1)&&(cubo[2][2][1]==1)&&(cubo[0][1][2]==2)&&(cubo[1][1][2]==2)&&(cubo[2][0][2]==0))||
	((cubo[0][1][0]==0) && (cubo[1][0][0]==0) && (cubo[1][1][0]==0)  && (cubo[1][2][0]==0) && (cubo[2][1][0]==0)&& (cubo[0][1][1]==1) && (cubo[1][1][1]==1) && (cubo[2][2][1]==2) && (cubo[0][1][2]==2) && (cubo[1][1][2]==2) && (cubo[2][0][2]==1)));

}



void caso2_1() /* paso 2_1: el vértice tiene el color blanco en la cara frontal. */
{
	printf("Tienes el primer caso\n");
	printf("Debes completar la capa superior \n Realiza los siguientes pasos: \n ");
	printf("1. Toma de frente la cara que tiene rojo y blanco \n 2. Gira la base 90° a la izquierda \n");
	printf("3. Baja 90° la cara derecha \n 4. Gira 90° la base a la derecha\n 5. Sube 90° la cara derecha \n");
	printf(" \n");
						girototal(1,3);girototal(1,3);girototal(1,3);girototal(1,2);
						girototal(1,2);girototal(1,2);girototal(1,3);girototal(1,2);
}


void caso2_2() /* paso 2.2: el vértice tiene el color blanco en la cara derecha. */
{
	printf("Tienes el segundo caso\n");
	printf("Debes completar la capa superior\n Realiza los siguientes pasos:\n ");
	printf("1. Toma de frente la cara que tiene solo rojo \n 2. Gira la base 90° a la derecha \n");
	printf("3. Gira 90° la cara frontal hacia la derecha\n 4. Gira la base 90° a la izquierda \n");
	printf("5. Gira 90° la cara frontal hacia la izquierda\n");
						
						girototal(1,3);girototal(2,4);girototal(2,4);girototal(2,4);
						girototal(2,3);girototal(2,3);girototal(2,3);girototal(2,4);												
}




void caso2_3() /* paso 2.1: el vértice tiene el color blanco abajo.*/
{
	printf("Tienes el tercer caso\n");
	printf("Debes completar la capa superior \n Realiza los siguientes pasos: \n ");
	printf("1. Toma de frente la cara que tiene 2 rojos y un azul\n 2. Baja la cara derecha 90° hacia el frente \n");
	printf("3. Gira la base 180° a la izquierda \n 4. Gira la cara derecha 90° hacia arriba-ensentido de las manecillas\n");
	printf("5. Gira la base 180° hacia la derecha \n 6.Gira la base frontal 90° hacia la derecha\n");
	printf("7. Gira la base 90° a la izquierda\n 8. Gira la cara frontal 90° a la izquierda\n");
                     girototal(1,2);girototal(1,2);girototal(1,2);girototal(2,3);
                     girototal(2,3);girototal(1,2);girototal(1,3);girototal(1,3);
                     girototal(0,3);girototal(2,3);girototal(2,3);girototal(2,3);
                     girototal(2,4);
                     
}

	 void busqueda_validacion3() /* paso 3: completar la segunda capa */
{
	int j, ban1=0,ban2=0, i;
	do{
		for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			if (cubo[i][j][0]==0)
			{
				ban1=1;
			}
		}
	}
	
	for (j=0; j<3; j++)
		{
			if ((cubo[2][j][2]==2) && (cubo[2][j][1]==1) && (cubo[2][j][3]==3) && (cubo[2][j][4]==4))
		    {
		    
				ban2=1;
			}
		}
	
	if ((ban1==1)&&(ban2==1)&&(cubo[1][1][5]==5)&&(cubo[1][2][5]==4)&&(cubo[1][1][4]==4)&&(cubo[0][1][3]==3)&&(cubo[1][1][3]==3))
	{
		caso3_1();
		guarda_datos();
	}
	if ((ban1==1)&& (ban2==1)&&(cubo[1][1][5]==5)&&(cubo[2][1][5]==3)&&(cubo[0][1][4]==4)&&(cubo[1][1][4]==4)&&(cubo[1][1][3]==3))
	{
		caso3_2();
		guarda_datos();
	}
		
	}while(((ban1==1)&&(ban2==1)&&(cubo[1][1][5]==5)&&(cubo[1][2][5]==4)&&(cubo[1][1][4]==4)&&(cubo[0][1][3]==3)&&(cubo[1][1][3]==3))||
	((ban1==1)&& (ban2==1)&&(cubo[1][1][5]==5)&&(cubo[2][1][5]==3)&&(cubo[0][1][4]==4)&&(cubo[1][1][4]==4)&&(cubo[1][1][3]==3)));
}


void caso3_1() /* paso 3.1: la arista queda a la derecha del hueco donde va. */
{
	printf("Tienes el primer caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos: \n ");
	printf("1. Pon la cara blanca abajo y toma como frente la cara con centro verde\n 2. Gira la cara de arriba 90° a la derecha\n");
	printf("3. Gira la cara frontal 90° a la derecha\n 4. Gira 90° la cara superior a la derecha\n 5. Gira la cara frontal 90° a la derecha\n");
	printf("6. Gira la cara frontal 90° a la izquierda\n 7. Gira 90° la cara derecha hacia arriba\n");
	printf("8. Gira la cara frontal 90° a la derecha\n 9. Baja 90° la cara derecha\n ");
							
							girototal(4,1);girototal(3,4);girototal(4,1);girototal(4,1);
							girototal(4,1);girototal(3,4);girototal(3,4);girototal(3,4);
							girototal(3,1);girototal(3,1);girototal(3,1);girototal(4,2);
							girototal(4,1);girototal(4,2);girototal(4,2);girototal(4,2);					
}


void caso3_2() /* paso 3.2: el vértice tiene el color blanco en la cara derecha. */
{
	
	printf("Tienes el segundo caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara de arriba 90° a la derecha\n");
	printf("3. Gira la cara superior 90° a la izquierda\n 4. Gira la cara derecha 90° hacia la derecha\n 5. Gira la cara superior 90° a la derecha\n");
	printf("6. Gira la cara derecha 90° hacia abajo\n 7. Gira la cara superior 90° a la derecha\n");
	printf("8. Gira la cara frontal 90° a la izquierda\n 9. Gira la cara superior 90° a la izquierda\n 10. Gira la cara derecha 90° hacia abajo.\n");
						
						girototal(4,1);girototal(4,1);girototal(4,1);girototal(4,2);
						girototal(4,1);girototal(4,2);girototal(4,2);girototal(4,2);
						girototal(4,1);girototal(3,4);girototal(4,1);girototal(4,1);
						girototal(4,1);girototal(3,4);girototal(3,4);girototal(3,4);
}

	void busqueda_validacion4() /* paso 4: cruz en la última cara */
{
	int band1=0,band2=0, bandi3=0, i ,j;
	do{
		for (i=0; i<3; i++)
	{
		for (i=0; j<3; j++)
		{
			if (cubo[i][j][0]==0)
			{
			band1=1;
			}
		}
	}

	
	for (i=1; i<3; i++)
	{
		for (j=1; j<3; j++)
		{
			if ((cubo[i][j][1]==1) && (cubo[i][j][3]==3) && (cubo[i][j][4]==4) && (cubo[i][j][2]==2))
			{
			band2=1;
			}
		}
	}
	
	for (i=0; i<3; i++)
	{    
	     
		if (cubo[i][1][5]==5)
			bandi3++;
	}

	if ((band1==1)&&(band2==1)&&(bandi3==2))
	{
		caso4_1();
		guarda_datos();
	}
	if ((band1==1)&&(band2==1)&&(cubo[0][1][4]==5)&&(cubo[0][1][3]==5)&&(cubo[0][1][5]==5)&&(cubo[1][1][5]==5) && (cubo[2][1][5]==5))
	{
		caso4_2();
		guarda_datos();
	}
	if ((band1==1)&&(band2==1)&&(cubo[0][1][4]==5)&&(cubo[0][1][3]==5)&&(cubo[1][1][5]==5))
	{
		caso4_3();
		guarda_datos();
	}
	}while(((band1==1)&&(band2==1)&&(bandi3==2))||
	((band1==1)&&(band2==1)&&(cubo[0][1][4]==5)&&(cubo[0][1][3]==5)&&(cubo[0][1][5]==5)&&(cubo[1][1][5]==5) && (cubo[2][1][5]==5))||
	((band1==1)&&(band2==1)&&(cubo[0][1][4]==5)&&(cubo[0][1][3]==5)&&(cubo[1][1][5]==5)));
	
}



void caso4_1() /* paso 4.1: la arista queda a la derecha del hueco donde va. */
{
	printf("Tienes el primer caso\n");
	printf("Debes completar la segunda capa y tu frontal debe ser la cara verde\n Realiza los siguientes pasos: \n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara derecha 90° hacia abajo.\n");
	printf("3. Gira la cara frontal 90° a la izquierda.\n 4. Gira la cara superior 90° a la derecha.\n 5. Gira la cara frontal 90° a la derecha. \n");
	printf("6. Gira la cara superior 90° a la izquierda.\n 7. Gira la cara derecha 90° hacia la derecha.\n");
							
							girototal(5,2);girototal(5,2);girototal(5,2);girototal(3,4);
							girototal(3,1);girototal(5,3);girototal(3,1);girototal(3,1);
							girototal(3,1);girototal(5,2);	
}


void caso4_2() /* paso 4.2: el vértice tiene el color blanco en la cara derecha. */
{
	
	printf("Tienes el segundo caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara derecha 90° hacia abajo.\n");
	printf("3. Gira la cara superior 90° a la derecha.\n 4. Gira la cara frontal 90° a la izquierda.\n 5. Gira la cara superior 90° a la izquierda. \n");
	printf("6. Gira la cara frontal 90° a la derecha.\n 7. Gira la cara derecha 90° hacia la derecha.\n");
							
							girototal(5,2);girototal(5,2);girototal(5,2);girototal(4,1);
							girototal(3,4);girototal(3,1);girototal(3,1);girototal(3,1);
							girototal(5,3);girototal(5,2);
}


void caso4_3() /* paso 4.3: el vértice tiene el color blanco en la cara derecha. */
{
	
	printf("Tienes el tercer caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara derecha 90° hacia abajo.\n");
	printf("3. Gira la cara frontal 90° a la izquierda.\n 4. Gira la cara superior 90° a la derecha.\n");
	printf("5. gira la cara frontal 90° a la derecha.\n 6. Gira la cara superior 90° a la izquierda.\n");
	printf("7. Gira la cara derecha 90° hacia la derecha.\n 8. Gira la cara superior 180° a la izquierda.\n");
	printf("9. Gira la cara derecha 90° hacia abajo.\n  10. Gira la cara superior 90° a la derecha.\n");
	printf("11. Gira la cara frontal 90° a la izquierda.\n 12. Gira la cara superior 90° a la izquierda.\n");
	printf("13.Gira la cara frontal 90° a la derecha.\n 14. Gira la cara derecha 90° hacia la derecha.\n");
							
							girototal(4,2);girototal(4,2);girototal(4,2);girototal(3,2);
							girototal(4,1);girototal(4,2);girototal(3,1);girototal(3,1);
							girototal(4,2);girototal(4,2);girototal(4,2);girototal(4,1);
							girototal(3,4);girototal(3,1);girototal(3,1);girototal(3,1);
							girototal(5,3);girototal(4,2);
}

	void busqueda_validacion5() /* paso 5: Extender la cruz a la última capa */
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
		guarda_datos();
	}
	if ((bande1==1)&&(bande2==1)&&(cubo[0][1][3]==1)&&(cubo[0][1][4]==4)&&(cubo[0][1][5]==5)&&(cubo[1][0][5]==5)&&(cubo[1][1][5]==5)&&(cubo[1][2][5]==5)&&(cubo[2][1][5]==5))
	{
		caso5_2();
		guarda_datos();
	}	
	}while(((bande1==1)&&(bande2==1)&&(cubo[0][1][4]==4)&&(cubo[0][1][3]==3)&&(cubo[0][1][5]==5)&&(cubo[1][0][5]==5)&&(cubo[1][1][5]==5)&&(cubo[1][2][5]==5)&&(cubo[2][1][5]==5))||
	((bande1==1)&&(bande2==1)&&(cubo[0][1][3]==1)&&(cubo[0][1][4]==4)&&(cubo[0][1][5]==5)&&(cubo[1][0][5]==5)&&(cubo[1][1][5]==5)&&(cubo[1][2][5]==5)&&(cubo[2][1][5]==5)));
	
	

}


void caso5_1() /* paso 5.1: Conseguimos 2 aristas adyacentes colocadas en su sitio */
{
	printf("Tienes el primer caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos: \n ");
	printf("1. Pon la cara blanca abajo y tomar como frente la cara con centro verde\n 2. Gira la cara derecha 90° hacia abajo.\n");
	printf("3. Gira la cara superior 90° a la derecha.\n 4. Gira la cara derecha 90° hacia la derecha.\n");
	printf("5. Gira la cara superior 90° a la derecha.\n 6. Gira la cara derecha 90° hacia abajo.\n");
	printf("7. Gira la cara superior 90° a la izquierda.\n 8. Gira la cara derecha 180° hacia la derecha.\n");
	printf("9. Gira la cara superior 90° a la derecha.\n");
								
								girototal(5,2);girototal(5,2);girototal(5,2);girototal(4,1);
								girototal(4,2);girototal(4,1);girototal(4,2);girototal(4,2);
								girototal(4,2);girototal(4,1);girototal(4,1);girototal(4,2);
								girototal(4,1);
								
}


void caso5_2() /* paso 5.2: Conseguimos 2 aristas opuestas colocadas en su sitio.  */
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
	printf("17. Gira la cara superior 90° a la derecha.\n");
								
								girototal(4,2);girototal(4,2);girototal(4,2);girototal(4,1);
								girototal(4,2);girototal(4,1);girototal(4,2);girototal(4,1);
								girototal(4,1);girototal(4,2);girototal(3,2);girototal(3,2);
								girototal(3,2);girototal(3,1);girototal(3,2);girototal(3,1);
								girototal(3,2);girototal(3,2);girototal(3,2);girototal(3,1);
								girototal(3,1);girototal(3,2);girototal(3,1);							
}

	void busqueda_validacion6() /* Paso 6: colocar los últimos vértices (sin orientar) */
{   
  	int bandi1,bandi2,bandi3,bandi4,bandi5,i,j;
  	do{
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
									{
										caso6_1();
										guarda_datos();
									}
										
										
	/*1 */  if ((bandi1==1)&& (bandi2==1)&& (bandi4==1) && (bandi5==1) && (cubo[0][0][3]==5) && (cubo[0][2][3]==5) && (cubo[0][0][4]==4) && (cubo[0][2][4]==5) && (cubo[0][0][5]==3) && (cubo[0][2][5]==2) && (cubo[2][0][5]==2) && (cubo[2][2][5]==1))
									{
										caso6_2();
										guarda_datos();
									}	
										
	
	/*1 */  if ((bandi1==1)&& (bandi2==1) && (bandi3==1) && (bandi4==1) && (cubo[0][0][5]==1) && (cubo[0][2][5]==1) && (cubo[0][0][3]==4) && (cubo[0][2][3]==2) && (cubo[0][2][4]==2) && (cubo[0][0][4]==3)) 
									
										{
											caso6_3();
											guarda_datos();
										}
										
	/*1 */  if ((bandi1==1)&& (bandi2==1) && (bandi3==1) && (bandi4==1) && (cubo[0][0][5]==4) && (cubo[0][2][5]==2) && (cubo[0][0][3]==1) && (cubo[0][2][3]==1) && (cubo[0][2][4]==3) && (cubo[0][0][4]==2)) 
	 									
										 {
										 	caso6_4();
										 	guarda_datos();
										 }
  	}while(((bandi1==1)&& (bandi2==1)&& (bandi4==1) && (bandi5==1) && (cubo[0][0][3]==5) && (cubo[0][2][3]==5) && (cubo[0][0][4]==3) && (cubo[0][2][4]==5) && (cubo[0][0][5]==4) && (cubo[0][2][5]==3) && (cubo[2][0][5]==1) && (cubo[2][2][5]==4))||
	  ((bandi1==1)&& (bandi2==1)&& (bandi4==1) && (bandi5==1) && (cubo[0][0][3]==5) && (cubo[0][2][3]==5) && (cubo[0][0][4]==4) && (cubo[0][2][4]==5) && (cubo[0][0][5]==3) && (cubo[0][2][5]==2) && (cubo[2][0][5]==2) && (cubo[2][2][5]==1))||
	  ((bandi1==1)&& (bandi2==1) && (bandi3==1) && (bandi4==1) && (cubo[0][0][5]==1) && (cubo[0][2][5]==1) && (cubo[0][0][3]==4) && (cubo[0][2][3]==2) && (cubo[0][2][4]==2) && (cubo[0][0][4]==3))||
	  ((bandi1==1)&& (bandi2==1) && (bandi3==1) && (bandi4==1) && (cubo[0][0][5]==4) && (cubo[0][2][5]==2) && (cubo[0][0][3]==1) && (cubo[0][2][3]==1) && (cubo[0][2][4]==3) && (cubo[0][0][4]==2)));

}


void caso6_1() /* paso 6.1: Un vértice está en su sitio y los otros 3 se deben intercambiar en sentido horario. */
{
	
	printf("Tienes el primer caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara izquierda 90° hacia arriba/izquierda.\n");
	printf("3. Gira la cara superior 90° a la izquierda.\n 4. Gira la cara derecha 90° hacia la derecha.\n");
	printf("5. Gira la cara superior 90° a la derecha.\n 6. Gira la cara izquierda 90° hacia abajo/derecha.\n");
	printf("7. Gira la cara superior 90° a la izquierda.\n 8. Gira la cara derecha 90° hacia abajo.\n");
	printf("9. Gira la cara superior 90° a la derecha.\n 10. \n");
							
							girototal(3,4);girototal(3,1);girototal(3,1);girototal(3,1);
							girototal(3,2);girototal(3,1);girototal(3,4);girototal(3,4);
							girototal(3,4);girototal(3,1);girototal(3,1);girototal(3,1);
							girototal(3,2);girototal(3,2);girototal(3,2);girototal(3,1);
}


void caso6_2() /* paso 6.2: Un vértice está en su sitio y los otros 3 se deben intercambiar en sentido anti-horario. */
{
	printf("Tienes el segundo caso\n");
	printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara blanca abajo\n 2. Gira la cara derecha 90° hacia la derecha.\n");
	printf("3. Gira la cara superior 90° a la derecha.\n 4. Gira la cara izquierda 90° hacia arriba/izquierda.\n");
	printf("5. Gira la cara superior 90° a la izquierda.\n 6. Gira la cara derecha 90° hacia abajo.\n");
	printf("7. Gira la cara superior 90° a la derecha.\n 8. Gira la cara izquierda 90° hacia abajo/derecha.\n");
	printf("9. Gira la cara superior 90° a la izquierda.\n 10. \n");
							
							girototal(3,2);girototal(3,1);girototal(3,4);girototal(3,1);
							girototal(3,1);girototal(3,1);girototal(3,2);girototal(3,2);
							girototal(3,2);girototal(3,1);girototal(3,4);girototal(3,4);
							girototal(3,4);girototal(3,1);girototal(3,1);girototal(3,1);							
}


void caso6_3() /* Paso 6.3: Los dos vértices se deben intercambiar entre si y los dos frontales también.*/
	{
		printf("Tienes el tercer caso\n");
		printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
		printf("1. Pon la cara blanca abajo\n 2. Gira la cara frontal 90° a la derecha.\n");
		printf("3. Gira la cara superior 90° a la izquierda.\n 4. Gira la cara derecha 90° hacia la derecha.\n");
		printf("5. Gira la cara superior 90° a la derecha.\n 6. Gira la cara derecha 90° hacia abajo.\n");
		printf("7. Repetir 3 veces desde el #2 al 6#\n 8. Gira la cara frontal 90° a la izquierda.\n");
		printf("9. \n 10. \n");
							
							girototal(5,1);girototal(4,1);girototal(4,1);girototal(4,1);
							girototal(3,2);girototal(3,1);girototal(3,2);girototal(3,2);
							girototal(3,2);girototal(3,1);girototal(3,1);girototal(3,1);
							girototal(3,2);girototal(3,1);girototal(3,2);girototal(3,2);
							girototal(3,2);girototal(3,1);girototal(3,1);girototal(3,1);
							girototal(3,2);girototal(3,1);girototal(3,2);girototal(3,2);
							girototal(3,2);girototal(4,4);
	}	
	

void caso6_4() /* Paso 6.4: Los vértices se deben intercambiar en cruz.*/
	{
		printf("Tienes el cuarto caso\n");
		printf("Debes completar la segunda capa\n Realiza los siguientes pasos:\n ");
		printf("1. Pon la cara blanca abajo\n 2. Gira la cara frontal 90° a la derecha.\n");
		printf("3. Gira la cara trasera 90° a la izquierda.\n 4. Gira la cara superior 180° a la izquierda.\n");
		printf("5. Gira la cara frontal 90° a la izquierda.\n 6. Gira la cara trasera 90° a la derecha.\n");
		printf("7. Gira la cara derecha 90° hacia abajo.\n 8. Gira la cara izquierda 90° hacia arriba-izquierda.\n");
		printf("9. Gira la cara superior 180° a la izquierda.\n 10. Gira la cara derecha 90° hacia la derecha.\n");
		printf("11. Gira la cara izquierda 90° hacia abajo-derecha.\n 12. Gira la cara superior 180° a la izquierda.\n");
							
							girototal(5,1);girototal(4,2);girototal(4,1);girototal(4,1);
							girototal(4,2);girototal(5,1);girototal(3,2);girototal(3,2);
							girototal(3,2);girototal(3,4);girototal(3,1);girototal(3,1);
							girototal(3,2);girototal(3,4);girototal(3,4);girototal(3,4);
							girototal(3,1);girototal(3,1);
	}

void busqueda_validacion7()/* Caso 7: girar los vértices para ¡terminar el cubo! */
{
	int bandi1, bandi2, bandi3, bandi4, bandi5, bandi6, bandi7,i, j;
	do{
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
									{
										caso7_1();
										guarda_datos();
									}
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][2][4]==3) && (cubo[0][0][3]==5) && (cubo[2][2][5]==4))
									{
										caso7_2 ();
										guarda_datos();
									}
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi6==1) && (bandi7==1) && (cubo[0][0][3]==2)&& (cubo[0][2][3]==4) && (cubo[0][2][2]==5) && (cubo[0][2][5]==3) && (cubo[2][2][5]==3) && (cubo[0][0][4]==5))	
									{
										caso7_2 ();
										guarda_datos();
									}
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (bandi6==1) && (cubo[0][2][3]==4) && (cubo[0][0][3]==5) && (cubo[0][0][5]==4) && (cubo[2][2][5]==2) && (cubo[0][2][2]==3) && (cubo[0][2][5]==3) )
									{
										caso7_4 ();
										guarda_datos();
									}
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][2]==1) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==5) && (cubo[0][0][5]==4) && (cubo[0][2][5]==4) && (cubo[2][0][5]==2) && (cubo[2][2][5]==2))
									{
										caso7_5 ();
										guarda_datos();
									}
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (bandi7==1) && (cubo[0][0][5]==5) && (cubo[0][2][5]==5) && (cubo[2][0][5]==1) && (cubo[2][2][5]==3) && (cubo[0][0][2]==5) && (cubo[0][2][2]==5) && (cubo[0][0][3]==2) && (cubo[0][2][3]==3))
									{
										caso7_6 ();
										guarda_datos();
									}
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (bandi7==1) && (cubo[0][0][5]==5) && (cubo[0][2][5]==5) && (cubo[2][0][5]==2) && (cubo[2][2][5]==2) && (cubo[0][0][2]==1) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==3))
									{
										caso7_7 ();
										guarda_datos();
									}
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (bandi6==1) && (cubo[0][0][5]==1) && (cubo[0][2][5]==5) && (cubo[2][0][5]==5) && (cubo[2][2][5]==2) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==3))
									{
										caso7_8 ();
										guarda_datos();
									}
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][5]==5) && (cubo[0][2][5]==4) && (cubo[2][0][5]==2) && (cubo[2][2][5]==3) && (cubo[0][0][2]==1) && (cubo[0][2][2]==5) && (cubo[0][0][3]==2) && (cubo[0][2][3]==5))
									{
										caso7_9 ();
										guarda_datos();
									}
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][5]==5) && (cubo[0][2][5]==3) && (cubo[2][0][5]==1) && (cubo[2][2][5]==2) && (cubo[0][0][2]==5) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==4))  
									{
										caso7_10 ();
										guarda_datos();
									}
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][5]==1) && (cubo[0][2][5]==3) && (cubo[2][0][5]==3) && (cubo[2][2][5]==3) && (cubo[0][0][2]==5) && (cubo[0][2][2]==5) && (cubo[0][0][3]==2) && (cubo[0][2][3]==4)) 
									{
											caso7_11 ();
											guarda_datos();
									}
	
	if ((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][5]==1) && (cubo[0][2][5]==3) && (cubo[2][0][5]==2) && (cubo[2][2][5]==2) && (cubo[0][0][2]==1) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==4)) 
									{
										caso7_12 ();
										guarda_datos();
									}
		
	}while(((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][2][4]==5) && (cubo[0][0][3]==4) && (cubo[2][2][5]==3))||
	((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][2][4]==3) && (cubo[0][0][3]==5) && (cubo[2][2][5]==4))||
	((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi6==1) && (bandi7==1) && (cubo[0][0][3]==2)&& (cubo[0][2][3]==4) && (cubo[0][2][2]==5) && (cubo[0][2][5]==3) && (cubo[2][2][5]==3) && (cubo[0][0][4]==5))||
	((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (bandi6==1) && (cubo[0][2][3]==4) && (cubo[0][0][3]==5) && (cubo[0][0][5]==4) && (cubo[2][2][5]==2) && (cubo[0][2][2]==3) && (cubo[0][2][5]==3))||
	((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][2]==1) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==5) && (cubo[0][0][5]==4) && (cubo[0][2][5]==4) && (cubo[2][0][5]==2) && (cubo[2][2][5]==2))||
	((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (bandi7==1) && (cubo[0][0][5]==5) && (cubo[0][2][5]==5) && (cubo[2][0][5]==1) && (cubo[2][2][5]==3) && (cubo[0][0][2]==5) && (cubo[0][2][2]==5) && (cubo[0][0][3]==2) && (cubo[0][2][3]==3))||
	((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (bandi7==1) && (cubo[0][0][5]==5) && (cubo[0][2][5]==5) && (cubo[2][0][5]==2) && (cubo[2][2][5]==2) && (cubo[0][0][2]==1) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==3))||
	((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (bandi6==1) && (cubo[0][0][5]==1) && (cubo[0][2][5]==5) && (cubo[2][0][5]==5) && (cubo[2][2][5]==2) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==3))||
	((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][5]==5) && (cubo[0][2][5]==4) && (cubo[2][0][5]==2) && (cubo[2][2][5]==3) && (cubo[0][0][2]==1) && (cubo[0][2][2]==5) && (cubo[0][0][3]==2) && (cubo[0][2][3]==5))||
	((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][5]==5) && (cubo[0][2][5]==3) && (cubo[2][0][5]==1) && (cubo[2][2][5]==2) && (cubo[0][0][2]==5) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==4))||
	((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][5]==1) && (cubo[0][2][5]==3) && (cubo[2][0][5]==3) && (cubo[2][2][5]==3) && (cubo[0][0][2]==5) && (cubo[0][2][2]==5) && (cubo[0][0][3]==2) && (cubo[0][2][3]==4))||
	((bandi1==1) && (bandi2==1) && (bandi4==1) && (bandi5==1) && (cubo[0][0][5]==1) && (cubo[0][2][5]==3) && (cubo[2][0][5]==2) && (cubo[2][2][5]==2) && (cubo[0][0][2]==1) && (cubo[0][2][2]==3) && (cubo[0][0][3]==5) && (cubo[0][2][3]==4)));
	
}
	
void caso7_1() /* Caso7.1 forma 1: El vértice necesita un giro en el sentido horario. */
{
	printf("Tienes el primer caso\n");
	printf("Debes completar el cubo \n Realiza los siguientes pasos:\n ");
	printf("1. La cara blanca abajo\n 2. Gira la cara derecha 90° hacia abajo.\n");
	printf("3. Gira la base 90° a la derecha.\n 4. Gira la cara derecha 90° hacia la derecha.\n");
	printf("5. Gira la base 90° a la izquierda.\n 6. Gira la cara derecha 90° hacia abajo.\n");
	printf("7. Gira la base 90° a la derecha.\n 8. Gira la cara derecha 90° hacia la derecha. \n");
	printf("9. Gira la base 90° a la izquierda.\n 10. \n");
			
		girototal(5,2);girototal(5,2);girototal(5,2);girototal(4,3);
		girototal(4,2);girototal(4,3);girototal(4,3);girototal(4,3);
		girototal(4,2);girototal(4,2);girototal(4,2);girototal(4,1);
		girototal(4,2);girototal(4,1);girototal(4,1);girototal(4,1);
}


void caso7_2() /* Caso7.2 forma 1: El vértice necesita un giro en el sentido anti-horario. */
{
	printf("Tienes el segundo caso\n");
	printf("Debes completar el cubo\n Realiza los siguientes pasos:\n ");
	printf("1. La cara blanca abajo\n 2. Gira la base 90° a la derecha.\n");
	printf("3. Gira la cara derecha 90° hacia abajo.\n 4. Gira la base 90° a la izquierda.\n");
	printf("5. Gira la cara derecha 90° hacia la derecha.\n 6. Gira la base 90° a la derecha.\n");
	printf("7. Gira la cara derecha 90° hacia abajo.\n 8. Gira la base 90° a la izquierda.\n");
	printf("9. Gira la cara derecha 90° hacia la derecha. \n 10. \n");
	
		girototal(4,3);girototal(4,2);girototal(4,2);girototal(4,2);
		girototal(4,3);girototal(4,3);girototal(4,3);girototal(4,2);
		girototal(4,3);girototal(4,2);girototal(4,2);girototal(4,2);
		girototal(4,3);girototal(4,3);girototal(4,3);girototal(4,2);
}

void caso7_3()
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
		printf("17. Gira la base 90° a la izquierda. \n 18. Gira la cara derecha 90° hacia la derecha. \n");
		printf ("19. Gira la cara superior 90° a la derecha. \n");
			
		girototal(2,2);girototal(2,2);girototal(2,2);girototal(2,3);
		girototal(2,2);girototal(2,3);girototal(2,3);girototal(2,3);
		girototal(2,2);girototal(2,2);girototal(2,2);girototal(2,3);
		girototal(2,2);girototal(2,3);girototal(2,3);girototal(2,3);
		girototal(2,1);girototal(2,1);girototal(2,1);girototal(2,3);
		girototal(2,2);girototal(2,2);girototal(2,2);girototal(2,3);
		girototal(2,3);girototal(2,3);girototal(2,2);girototal(2,3);
		girototal(2,2);girototal(2,2);girototal(2,2);girototal(2,3);
		girototal(2,3);girototal(2,3);girototal(2,2);girototal(2,1);
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
	
		girototal(2,3);girototal(2,2);girototal(2,2);girototal(2,2);
		girototal(2,3);girototal(2,3);girototal(2,3);girototal(2,2);
		girototal(2,3);girototal(2,2);girototal(2,2);girototal(2,2);
		girototal(2,3);girototal(2,3);girototal(2,3);girototal(2,2);
		girototal(2,1);girototal(2,1);girototal(2,1);girototal(2,3);
		girototal(2,2);girototal(2,2);girototal(2,2);girototal(2,3);
		girototal(2,3);girototal(2,3);girototal(2,2);girototal(2,3);
		girototal(2,2);girototal(2,2);girototal(2,2);girototal(2,3);
		girototal(2,3);girototal(2,3);girototal(2,2);girototal(2,1);
		girototal(2,1);girototal(2,1);girototal(2,3);girototal(2,2);
		girototal(2,2);girototal(2,2);girototal(2,3);girototal(2,3);
		girototal(2,3);girototal(2,2);girototal(2,3);girototal(2,2);
		girototal(2,2);girototal(2,2);girototal(2,3);girototal(2,3);
		girototal(2,3);girototal(2,2);girototal(2,1);girototal(2,1);
}

void caso7_5 ()
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
		
		girototal(2,3);girototal(2,2);girototal(2,2);girototal(2,2);
		girototal(2,3);girototal(2,3);girototal(2,3);girototal(2,2);
		girototal(2,3);girototal(2,2);girototal(2,2);girototal(2,2);
		girototal(2,3);girototal(2,3);girototal(2,3);girototal(2,2);
		girototal(2,1);girototal(2,1);girototal(2,1);girototal(2,2);
		girototal(2,2);girototal(2,2);girototal(2,3);girototal(2,2);
		girototal(2,3);girototal(2,3);girototal(2,3);girototal(2,2);
		girototal(2,2);girototal(2,2);girototal(2,3);girototal(2,2);
		girototal(2,3);girototal(2,3);girototal(2,3);girototal(2,1);
		girototal(2,1);girototal(2,1);girototal(2,3);girototal(2,2);
		girototal(2,2);girototal(2,2);girototal(2,3);girototal(2,3);
		girototal(2,3);girototal(2,2);girototal(2,3);girototal(2,2);
		girototal(2,2);girototal(2,2);girototal(2,3);girototal(2,3);
		girototal(2,3);girototal(2,2);girototal(2,1);girototal(2,1);
		girototal(2,1);girototal(2,2);girototal(2,2);girototal(2,2);
		girototal(2,3);girototal(2,2);girototal(2,3);girototal(2,3);
		girototal(2,3);girototal(2,2);girototal(2,2);girototal(2,2);
		girototal(2,3);girototal(2,2);girototal(2,3);girototal(2,3);
		girototal(2,3);girototal(2,1);girototal(2,1);girototal(2,1);
	}

void caso7_6()
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
	
		girototal(2,2);girototal(2,2);girototal(2,1);girototal(2,1);
		girototal(2,1);girototal(3,2);girototal(3,2);girototal(2,1);
		girototal(2,2);girototal(5,3);girototal(5,3);girototal(2,2);
		girototal(2,2);girototal(2,2);girototal(2,1);girototal(2,1);
		girototal(2,1);girototal(3,2);girototal(3,2);girototal(2,1);
		girototal(2,2);girototal(3,4);girototal(3,2);girototal(2,2);
}

void caso7_7()
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
		
		girototal(5,3);girototal(5,3);girototal(2,3);girototal(2,3);
		girototal(2,3);girototal(5,3);girototal(5,3);girototal(2,1);
		girototal(2,1);girototal(2,1);girototal(3,4);girototal(2,4);
		girototal(2,4);girototal(2,1);girototal(2,1);girototal(2,1);
		girototal(2,2);girototal(2,2);girototal(2,1);girototal(3,4);
		girototal(3,4);girototal(2,3);girototal(3,4);girototal(2,1);
}

void caso7_8()
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
	
		girototal(5,3);girototal(2,4);girototal(2,3);girototal(2,3);
		girototal(2,4);girototal(2,4);girototal(2,4);girototal(3,4);
		girototal(2,1);girototal(2,1);girototal(5,3);girototal(2,4);
		girototal(2,3);girototal(2,3);girototal(2,4);girototal(2,4);
		girototal(2,4);girototal(3,4);girototal(2,1);girototal(2,1);
}

void caso7_9 ()
{
	printf("Debes completar el cubo\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara amarilla arriba\n 2.Gira la cara frontal 90° a la derecha. \n");
	printf("3.Gira la cara superior 90° a la derecha. \n 4.Gira la cara trasera 90° a la izquierda. \n");
	printf("5.Gira la cara superior 180° a la izquierda. \n 6.Gira la cara frontal 180° a la derecha. \n");
	printf("7.Gira la base 90° a la izquierda. \n 8.Gira la cara izquierda 180° hacia abajo/derecha. \n");
	printf("9.Gira la base 90° a la derecha. \n 10.Gira la cara superior 90° a la izquierda. \n");
	printf("11. Gira la cara trasera 90° a la derecha.\n 12.Gira la cara superior 90° a la derecha. \n");
	printf("13. Gira la cara frontal 90° a la derecha. \n 14.Gira la cara superior 90° a la derecha. \n");
	
		girototal(5,3);girototal(2,1);girototal(3,2);girototal(2,1);
		girototal(2,1);girototal(5,3);girototal(5,3);girototal(2,3);
		girototal(2,3);girototal(2,3);girototal(2,4);girototal(2,4);
		girototal(2,3);girototal(2,1);girototal(2,1);girototal(2,1);
		girototal(5,1);girototal(2,1);girototal(5,3);girototal(2,1);
	
}

void caso7_10 ()
{
	printf("Debes completar el cubo\n Realiza los siguientes pasos:\n ");
	printf("1. Pon la cara amarilla arriba\n 2.Gira la cara derecha 90° hacia abajo.\n");
	printf("3.Gira la cara superior 90° a la izquierda.\n 4.Gira la cara izquierda 90° hacia abajo/derecha.\n");
	printf("5.Gira la base 90° a la izquierda.\n 6.Gira la cara superior 90° a la derecha.\n");
	printf("7.Gira la cara frontal 180° a la derecha.\n 8.Gira la base 90° a la derecha.\n");
	printf("9.Gira la cara derecha 180° hacia la derecha.  \n 10.Gira la cara superior 180° a la izquierda. \n");
	printf("11.Gira la cara izquierda 90° hacia arriba/izquierda.  \n 12.Gira la cara superior 90° a la izquierda.\n");
	printf("13.Gira la cara derecha 90° hacia abajo. \n 14.Gira la cara superior 90° a la izquierda.\n");
	
		girototal(2,2);girototal(2,2);girototal(2,2);girototal(2,1);
		girototal(2,1);girototal(2,1);girototal(2,4);girototal(2,4);
		girototal(2,4);girototal(2,3);girototal(2,3);girototal(2,3);
		girototal(2,1);girototal(3,4);girototal(3,4);girototal(2,3);
		girototal(2,2);girototal(2,2);girototal(2,1);girototal(2,1);
		girototal(2,4);girototal(2,1);girototal(2,1);girototal(2,1);
		girototal(2,2);girototal(2,2);girototal(2,2);girototal(2,1);
		girototal(2,1);girototal(2,1);
		
}

void caso7_11 ()
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
	
		girototal(2,2);girototal(2,2);girototal(2,2);girototal(2,1);
		girototal(2,1);girototal(2,2);girototal(2,1);girototal(2,1);
		girototal(2,2);girototal(2,2);girototal(5,1);girototal(2,3);
		girototal(2,3);girototal(2,3);girototal(2,2);girototal(2,2);
		girototal(2,2);girototal(5,3);girototal(2,2);girototal(2,2);
		girototal(3,4);girototal(2,3);girototal(3,2);girototal(2,1);
		girototal(2,2);girototal(2,2);girototal(2,2);girototal(2,1);
}

void caso7_12 ()
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
	
		girototal(2,4);girototal(2,2);girototal(2,3);girototal(2,4);
		girototal(2,4);girototal(2,1);girototal(2,1);girototal(2,2);
		girototal(2,2);girototal(2,2);girototal(2,3);girototal(2,3);
		girototal(2,3);girototal(2,4);girototal(2,4);girototal(2,1);
		girototal(2,1);girototal(2,2);girototal(2,2);girototal(2,2);
		girototal(2,1);girototal(2,1);girototal(2,1);girototal(2,2);
		girototal(2,2);girototal(3,2);girototal(3,2);girototal(2,2);
		girototal(2,2);girototal(2,1);
}
	
	
	
