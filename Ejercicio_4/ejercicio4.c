#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

	typedef struct Producto {
		int ProductoID; //Numerado en ciclo iterativo
		int Cantidad; // entre 1 y 10
		char *TipoProducto; // Algún valor del arreglo TiposProductos
		float PrecioUnitario; // entre 10 - 100
	}producto;

	typedef struct Cliente {
		int ClienteID; // Numerado en el ciclo iterativo
		char *NombreCliente; // Ingresado por usuario
		int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
		struct Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
	}cliente;
	
	
//DECLARACION DE FUNCIONES

void cargar_lista (cliente *listado, int cantidad);

void mostrar (cliente *listado, int cantidad);

float calcular_total (struct Producto* tipo);



int main(){
	
	int cantidad_Clientes,bandera = 0;
	
	cliente *cliente_lista;
	
	//COMPROBAMOS QUE LA CANTIDAD DE CLIENTES SEA MENOR A 5

	do{
		
		if(bandera == 1){
			
			printf("\nLa cantidad de clientes debe ser menor a 5, volver a ingresar.");
			
		}
				
		printf("\nIngresar la cantidad de clientes : ");
		
		scanf("%d",&cantidad_Clientes);	
		
		bandera = 1;
		
	}while(cantidad_Clientes > 5);
	
	//RESERVAMOS MEMORIA PARA EL LISTADO PRINCIPAL DE CLIENTES
	
	cliente_lista = (cliente*) malloc(sizeof(cliente) * cantidad_Clientes);
	
	
	//HACEMOS USO DE LAS FUNCIONES
	
	cargar_lista(cliente_lista,cantidad_Clientes);
	
	mostrar(cliente_lista,cantidad_Clientes);
		
		
		
		
		
		
		
		
		
		
	
	return 0;
}


float calcular_total (struct Producto* tipo){
	
	return (tipo->Cantidad * tipo->PrecioUnitario);
	
}





void cargar_lista (cliente *listado, int cantidad){
	
	int i,j,randomAux;
	
	producto *producto_aux;
	
	char nombreAux[20];
	
	
	for(i=0 ; i<cantidad ; i++){
		
		listado->ClienteID = i+1;
				
		printf("\nIngresar el nombre del cliente %d : ",i+1);
		
		scanf("%s",nombreAux);
		
		//HACEMOS EL PROCESO DE RESERVA DE MEMORIA Y COPIADO DEL NOMBRE DESDE LA VARIABLE AUXILIAR
		
		listado->NombreCliente = malloc(sizeof(char) * (strlen(nombreAux) + 1));//Sumamos el +1 para el fin de carrera
		
		strcpy(listado->NombreCliente, nombreAux); //Copiamos el contenido de la variable auxiliar al puntero
		
		listado->CantidadProductosAPedir = rand() % 5 + 1;
		
		listado->Productos = malloc(sizeof(producto) * listado->CantidadProductosAPedir); //Reservamos memoria para el puntero "productos"
		
		
		producto_aux = listado->Productos;
		
		for(j=0 ; j<listado->CantidadProductosAPedir ; j++){
							
			producto_aux  ->ProductoID = j+1;
			
			producto_aux ->Cantidad = rand() % 10 + 1;
			
			randomAux = rand() % 4;
			
			producto_aux->TipoProducto = TiposProductos[randomAux];
			
			producto_aux->PrecioUnitario = (float)(rand()%10000 + 10)/100;
			
			producto_aux ++;
					
			
		}
		
		listado++;
		
	}
	
}

void mostrar (cliente *listado, int cantidad){
	
	int i,j;
	
	producto *producto_aux;
	
	for(i=0 ; i<cantidad ; i++){

		printf("\n\n\t\tCLIENTE : %d \n",listado->ClienteID);
		
		printf("\n\tNombre : %s ",listado->NombreCliente);
		
		printf("\n");
		
		producto_aux = listado->Productos;
		
		for(j=0 ; j<listado->CantidadProductosAPedir ; j++){
			
			printf("\n===== Producto : %d =====",producto_aux->ProductoID);
			
			printf("\nCantidad : %d",producto_aux->Cantidad);
			
			printf("\nTipo de producto : %s",producto_aux->TipoProducto);
			
			printf("\nPrecio unitario : %.2f ",producto_aux->PrecioUnitario);
			
			printf("\nPrecio total : %.2f ",calcular_total(producto_aux));
			
			printf("\n============================\n\n");
			
			producto_aux++;
			
		}
		
		listado++;
	
	}
	
	
	
}







