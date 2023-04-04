#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define longitud_Nombres 20


int main (){
	
	char **nombres;
	
	int i,cantidad_Nombres;
	
	printf("\nCantidad de nombres que desea ingresar : ");
	
	scanf("%d",&cantidad_Nombres);
	
	fflush(stdin);
	
	nombres = (char **) malloc(sizeof(char*) * cantidad_Nombres); //Reservamos la memoria para el puntero principal
	
	printf("\n\tIngresar %d nombres de longitud %d a continuacion : \n",cantidad_Nombres,longitud_Nombres);
	
	for(i=0 ; i<cantidad_Nombres ; i++){
		
		nombres[i] = (char*) malloc(sizeof(char) * longitud_Nombres); //Reservamos la memoria para cada nombre dentro del puntero
		
		printf("\nIngresar el nombre %d : ",i+1);
		
		gets(nombres[i]);  // obtenemos los nombres
		
	}
	
	
	for(i=0 ; i<cantidad_Nombres ; i++){//Mostramos todos los nombres
		
		printf("\nNombre %d : %s",i+1,nombres[i]);  
		
	}
	
	for(i=0 ; i<cantidad_Nombres ; i++){//Liberamos el espacio ocupado por cada nombre
		
		free(nombres[i]);
		
	}
	
	free(nombres); //Liberamos el puntero principal
	
	
	
	return 0;
}
