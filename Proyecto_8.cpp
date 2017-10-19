#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include <math.h>

/*Comentario
Programa que muestra metodos de ordenamiento 2 no eficientes y 2 eficientes, 
tambien dos metodos de busqueda (Binario y Secuencial), el tiempo de ejecucion de 
cada metodo.
Fecha: 16 Octubre 2017
Elaborado por:Viviana Rojas Ruiz, Alejandro Gonzalez y Leyder Mejia*/

void Generar_Vector(int vector[],int tam);
void Metodos_Ordenamiento(int tam);
int Burbuja(int tam);
void qs(int vector[],int limite_izq,int limite_der);
void Quicksort(int tam);	
void Mostrar_Vector(int vector[],int tam);
void Insercion(int tam);
void Binario(int tam);
void Busqueda(int tam);
void Secuencial(int tam);
void Mezclar(int vector1[],int n1,int vector2[],int n2,int vector3[]);
void Mezcla(int vector[],int n);
void Menu();

int vector[500000],tam;

int main()
{
	Menu();
	return 0;
}

void Menu()
{
	int opcion, tam;
	
	
	printf("<<<Metodos de Ordenamiento y Busqueda>>>\n");
		printf("Ingrese una Opcion:\n");
		printf("1.Metodos de Ordenamiento\n");
		printf("2.Metodos de Busqueda\n");
		printf("0.Salir\n");
		scanf("%d",&opcion);
	while(opcion!=0)
	{
      switch(opcion)
	  {
	  case 0:		  
		  exit(0);		  
	  case 1:
		  printf("<<Primero Debemos Generar Vector>>\n\n");
		  printf("Ingrese Tamaño del Vector, puede ser:\n100000\n200000\n300000\n500000\n");
		  scanf("%d",&tam);
		  Generar_Vector(vector,tam);
		  break; 		  
	  case 2:
		  printf("<<Primero Debemos Generar Vector>>\n\n");
		  printf("Ingrese Tamaño del Vector, puede ser:\n100000\n200000\n300000\n500000\n");
		  scanf("%d",&tam);
		  printf("Primero debe ordenar Vector:\n\n");
		  Generar_Vector(vector,tam);
		  Busqueda(tam);
		  break;
	  }
	}
}

void Generar_Vector(int vector[],int tam)
{
	int generacion;	
	
	srand(time(NULL));	
	for(int i=0;i<=tam;i++)
	{		
		vector[i]=(rand()%999999)-999998;			
	}
	generacion=clock();
	printf("Mostrando Vector:\n");
	for(int i=0;i<tam;i++)
	{
		printf("%d\n",vector[i]);
	}
	printf("\nTiempo Transcurrido Generando Vector: %f s\n\n",(clock()-generacion)/(double)CLOCKS_PER_SEC);
	Metodos_Ordenamiento(tam);
}

void Metodos_Ordenamiento(int tam)
{
	int opcion;
	printf("Metodos de ordenamiento\n");
	printf("Que Metodo desea utilizar, escoja una opcion:\n1.Eficiente\n2.No Eficiente\n");
	scanf("%d",&opcion);
	switch(opcion){
	case 1:
		printf("Metodos Eficientes, escoja una opcion:\n1.Quicksort\n2.Merge\n");
		scanf("%d",&opcion);
		switch(opcion){
		case 1:
			printf("Metodo de Ordenamiento Quicksort\n");
			int generacion;
			Quicksort(tam);
			generacion=clock();
			Mostrar_Vector(vector,tam);
			printf("\nTiempo desde que inicio Ordenamiento Quicksort: %f s\n",(clock()-generacion)/(double)CLOCKS_PER_SEC);			
			break;			
		case 2:
			printf("Metodo de Ordenamiento Merge\n");
			Mezcla(vector,tam);
			generacion=clock();
			Mostrar_Vector(vector,tam);
			printf("\nTiempo desde que inicio Ordenamiento Merge: %f s\n",(clock()-generacion)/(double)CLOCKS_PER_SEC);			
			break;
		}
		break;
	case 2:
		printf("Metodos No Eficientes, escoja una opcion:\n1.Burbuja\n2.Insercion\n");
		scanf("%d",&opcion);
		switch(opcion){
		case 1:			
			printf("Metodo de Ordenamiento Burbuja:\n");				   
			int generacion;				   
			Burbuja(tam);
			generacion=clock();				   
			Mostrar_Vector(vector,tam);
			printf("\nTiempo desde que inicio Ordenamiento Burbuja: %f s\n",(clock()-generacion)/(double)CLOCKS_PER_SEC);				   
			break;			
		case 2:
			printf("Metodo de Ordenamiento Insercion\n");
			Insercion(tam);
			generacion=clock();
			printf("\nTiempo desde que inicio Ordenamiento Insercion: %f s\n",(clock()-generacion)/(double)CLOCKS_PER_SEC);				   
			break;			
		}
		break;
	}	
}

void Busqueda(int tam)
{
	int opcion;
	printf("Metodos de Busqueda, escoja una opcion:\n1.Busqueda Binaria\n2.Busqueda Secuencial\n");
	scanf("%d",&opcion);
	switch(opcion)
	{
	case 1:
		printf("Busqueda Binaria\n");
		int generacion;
		Binario(tam);
		generacion=clock();
		printf("\nTiempo desde que inicio Busqueda Binaria: %f s\n",(clock()-generacion)/(double)CLOCKS_PER_SEC);
		break;
	case 2:
		printf("Busqueda Secuencial\n");
		Secuencial(tam);
		generacion=clock();
		printf("\nTiempo desde que inicio Busqueda Secuencial: %f s\n",(clock()-generacion)/(double)CLOCKS_PER_SEC);
		break;
	}
	Menu();
}

int Burbuja(int tam)
{
	int aux;
	printf("Vector Ordenado:\n");
	
	for (int i=0;i<tam;i++)
	{
		for (int j=0;j<tam;j++)
		{
			if (vector[j]>vector[j+1])
			{
				aux=vector[j];
				vector[j]=vector[j+1];
				vector[j+1]=aux;				
			}
		}
	}
	return *vector;
}

void qs(int vector[],int limite_izq,int limite_der)
{
	int izq,der,temporal,pivote;
	izq=limite_izq;
	der = limite_der;
	pivote = vector[(izq+der)/2];	
	do{
		while(vector[izq]<pivote && izq<limite_der)izq++;
		
		while(pivote<vector[der] && der > limite_izq)der--;
		if(izq <=der)
		{
			temporal= vector[izq];
			vector[izq]=vector[der];
			vector[der]=temporal;
			izq++;
			der--;
		}
	}while(izq<=der);
	
	if(limite_izq<der)
	{ 
		qs(vector,limite_izq,der);
	}
	if(limite_der>izq)
	{
		qs(vector,izq,limite_der);
	}
}

void Quicksort(int n)
{
	qs(vector,0,n-1);
}

void Mostrar_Vector(int vector[],int tam)
{
	printf("Mostrando Vector Ordenado:\n");
	for(int i=0;i<=tam;i++)
	{
		printf("%d\n",vector[i]);
	}
}

void Insercion(int tam)
{
	int i,a,indice;	
	printf("Elementos ordenados \n");
	for(i=1;i<tam;i++){
		indice=vector[i];
		a=i-1;
		while(a>=0&&vector[a]>indice){
			vector[a + 1]=vector[a];
			a--;
		}
		vector[a+1]=indice;
	}
	for(i=0;i<tam;i++){
		printf("%d\n",vector[i]);
	}
}

void Binario(int tam)
{	
	int inf,sup,dato,mitad;
	char band = 'F';	
	printf ("ingrese el dato a buscar;\n");
	scanf ("%d",&dato);	
	inf = 0;
	sup = tam;	
		while((inf <= sup) && (band == 'F')) {
		mitad =((inf+sup)/2);
		if(vector[mitad]==dato){
			band = 'V';
		}
		else 
		   if(vector[mitad]>dato){
			  sup = mitad - 1;
		}
		else{
			inf = mitad + 1;
		}
	}	
	if(band == 'F'){
		printf("Elemento no encontrado ");
	} 
	else if(band=='V'){
		printf("Elemento encontrado, en la pos: %i",mitad);
	}
}

void Secuencial(int tam)
{
	int num;
	int encontrado=0;
	printf("Ingrese Numero a Buscar:\n");
	scanf("%d",&num);
	for(int i=0;i<tam;i++)
	{
		if(vector[i]==num)
		{
			encontrado=1;
		}
	}
	if(encontrado==1)
	{
		printf("Numero Encontrado\n");
	}else{
		printf("Numero NO Encontrado en la Lista\n");
	}
}

void Mezclar(int vector1[],int n1,int vector2[],int n2,int vector3[])
{
	int x1=0;
	int x2=0;
	int x3=0;
	
	while(x1<n1 && x2<n2)
	{
		if(vector1[x1]<vector2[x2])
		{
			vector3[x3]=vector1[x1];
			x1++;
		}else{
			vector3[x3]=vector2[x2];
			x2++;
		}
		x3++;
	}
	while(x1<n1)
	{
		vector3[x3]=vector1[x1];
		x1++;
		x3++;
	}
	while(x2<n2)
	{
		vector3[x3]=vector2[x2];
		x2++;
		x3++;
	}	
}

void Mezcla(int vector[],int n)
{
	int *vector1,*vector2,n1,n2,x,y;
	if(n>1)
	{
		if(n%2==0)
		{
			n1=n2=(int)n/2;
		}else{
			n1=(int)n/2;
			n2=n1+1;
		}
		vector1=(int*)malloc(sizeof(int)*n1);
		vector2=(int*)malloc(sizeof(int)*n2);
		for(x=0;x<n1;x++)
		{
			vector1[x]=vector[x];
		}
		for(y=0;y<n2;y++)
		{
			vector2[y]=vector[x];
		}		
		Mezcla(vector1,n1);
		Mezcla(vector2,n2);
		Mezclar(vector1,n1,vector2,n2,vector);
		free(vector1);
		free(vector2);
	}
}
