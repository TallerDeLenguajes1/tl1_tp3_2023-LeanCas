#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	
	int prod[5][12];
	
	int i,j;
	
	srand(time(NULL));
	
	//CARGO EL ARREGLO
	
	for(i=0 ; i<5 ; i++){
		
		
		for(j=0 ; j<12 ; j++){
			
			
			prod[i][j] = rand() % 50001 + 10000;
			
		}
	
	}
	
	//MUESTRO POR PANTALLA
	
	for(i=0 ; i<5 ; i++){
		
		
		for(j=0 ; j<12 ; j++){
			
			
			printf(" %d",prod[i][j]);
			
		}
		
		printf("\n");
	
	}
	
	//SACAMOS EL PROMEDIO POR AÑO
	
	int suma,prom;
	
	for(i=0 ; i<5 ; i++){
		
		suma = 0;
		
		
		for(j=0 ; j<12 ; j++){
			
			
			suma += prod[i][j];
			
		}
		
		prom = (suma/j);
		
		printf("\n\nLa ganancia promedio del anio %d es : %d",i+1,prom);
	
	}
	
	//SACAMOS EL MAXIMO Y EL MINIMO
	
	int max = 0, min = 50000;
	
	int anioMax, mesMax, anioMin, mesMin;
	
	
	for(i=0 ; i<5 ; i++){
		
		
		for(j=0 ; j<12 ; j++){
			
			
			if(prod[i][j] > max){
				
				max = prod[i][j];
				
				anioMax = i;
				
				mesMax = j;
				
			}
			
			if(prod[i][j] < min){
				
				min = prod[i][j];
				
				anioMin = i;
				
				mesMin = j;
				
			}
				
		}
		
	}
	
	printf("\n\nEl maximo valor es %d obtenido el año %d y en el mes %d",max,anioMax+1,mesMax+1);
	
	printf("\n\nEl minimo valor es %d obtenido el año %d y en el mes %d",min,anioMin+1,mesMin+1);
	
	
	return 0;
}
