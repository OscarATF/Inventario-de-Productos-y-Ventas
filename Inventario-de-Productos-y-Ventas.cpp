#include <iostream>
#include <string.h>
using namespace std;

struct Producto {
	string nombre;
	float precio;
};

struct Venta {
	int idVenta;
	string producto;
	int cantidad;
	float precioTotal;
};

void nuevoProducto(Producto arrElemento[],int& n) {
	system("cls");
	cout<<"Ingrese el nombre del producto : ";
	cin.ignore();
	getline(cin,arrElemento[n].nombre);
	(arrElemento[n].nombre)[0]=toupper((arrElemento[n].nombre)[0]);
	cout<<"Ingrese el precio del producto : ";
	cin>>arrElemento[n].precio;
	cout<<"\nRegistrado correctamente\n"<<endl;
	n++;
	system("pause");
}

int main() {
	const int MAX=1000;
	Producto elemento[MAX] = {
		{"Tarjeta de video",2000.0},
		{"Procesador intel",1200.0},
		{"Placa madre",900.0},
		{"Disipador",250.0}
	};
	Venta ventas[MAX]= {	
	    {100,elemento[0].nombre,2,4000.0},        
		{101,elemento[1].nombre,1,1200.0}
	};
	
	int id=101; //id de venta
	int op;
	int n=4;	//numero de productos inicial
	int m=2;	//numero de ventas inicial

	do {
		system("cls");
		cout<<"Inventario de Productos y Ventas\n"<<endl;
		cout<<"Menu:"<<endl;
		cout<<"1. Registrar un nuevo producto"<<endl
			<<"2. Listar los productos registrados"<<endl
			<<"3. Buscar un producto por nombre"<<endl
			<<"4. Actualizar los datos de un producto"<<endl
			<<"5. Eliminar un producto"<<endl
			<<"6. Registrar una venta"<<endl
			<<"7. Listar las ventas realizadas"<<endl
			<<"8. Calcular el total de ventas realizadas"<<endl
			<<"9. Salir del programa"<<endl;
		cin>>op;
		switch (op) {
			case 1: //agregar un producto
				nuevoProducto(elemento,n);
				break;
			case 2: //listar productos
				break;
			case 3: //buscar por nombre
				break;
			case 4: //actualizar datos producto
				break;
			case 5: //eliminar datos producto
				break;
			case 6: //Registrar una venta
				break;
			case 7: //Listar las ventas realizadas
				break;
			case 8:	//calcular el total de ventas realizadas
				break;
			case 9:	//salir del programa
				cout<<"Saliendo del programa"<<endl;
				break;
			default:
				cout<<"Ingrese una opcion valida\n"<<endl;
				system("pause");
		}
	} while (op!=9);
	return 0;
}