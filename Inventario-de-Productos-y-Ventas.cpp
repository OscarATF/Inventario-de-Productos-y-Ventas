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

void listaProducto(Producto arr[],int n) {
	system("cls");
	cout<<"Listado de productos registrados:\n"<<endl;
	for (int i=0;i<n;i++) {
		cout<<"Producto "<<i+1<<" :\n"<<endl;
		cout<<"Nombre: "<<arr[i].nombre<<endl;
		cout<<"precio: s/"<<arr[i].precio<<endl<<endl;
	}
	system("pause");
}

void buscarProducto(Producto arr[],int& n) {
    string nombreBuscar;
    system("cls");
    cout<<"Ingrese el nombre del producto a buscar: ";
    cin.ignore();
	getline(cin,nombreBuscar);
	nombreBuscar[0]=toupper(nombreBuscar[0]);
    bool encontrado=false;
    for (int i=0;i<n;i++) {
        if (arr[i].nombre==nombreBuscar) {
            cout<<"Producto encontrado\n"
				<<"Nombre: " <<arr[i].nombre 
				<<", Precio: s/"<< arr[i].precio<<endl;
            encontrado=true;
            break;
        }
	}
    if (encontrado!=true) {
        cout<<"Producto no encontrado."<<endl;
    }
    system("pause");
}

void actualizarProducto(Producto arr[],int& n) {
	int indice;
	int numeroProducto;
	system("cls");
	cout<<"Lista de Productos:\n"<<endl;
		for (int i=0;i<n;i++) {
			cout<<"PRODUCTO "<<i+1<<" :\n"<<endl;
			cout<<"Nombre: "<<arr[i].nombre<<endl;
			cout<<"Precio: s/"<<arr[i].precio<<endl<<endl;
		}
			cout<<"Digite el numero de producto que desea actualizar: ";
			cin>>numeroProducto;
			indice=numeroProducto-1;
			cout<<"\nProducto "<<numeroProducto<<" seleccionado\n"<<endl;
			cout<<"Ingrese el nuevo nombre del producto : ";
			cin.ignore();
			getline(cin,arr[indice].nombre);
			(arr[indice].nombre)[0]=toupper((arr[indice].nombre)[0]);
			cout<<"Ingrese el precio del producto : ";
			cin>>arr[indice].precio;
			cout<<"\n\nProducto actualizado\n"<<endl;
	system("pause");
}

void eliminarProducto(Producto arr[],int& n) {
	int indice;
	int numeroProducto;
	system("cls");
	cout<<"Lista de Productos:\n"<<endl;
		for (int i=0;i<n;i++) {
			cout<<"PRODUCTO "<<i+1<<" :\n"<<endl;
			cout<<"Nombre: "<<arr[i].nombre<<endl;
			cout<<"Precio: s/"<<arr[i].precio<<endl<<endl;
		}
			cout<<"Digite el numero de producto que desea eliminar: ";
			cin>>numeroProducto;
			indice=numeroProducto-1;
		if (indice >= 0 && indice < n) {
			for (int i=indice;i<n-1;++i) {
				arr[i]=arr[i+1];
			}
			n--;
			cout<<"\nProducto eliminado\n"<<endl;
		} else {
		cout<<"\nIndice no valido\n"<<endl;
		}
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
				listaProducto(elemento,n);
				break;
			case 3: //buscar por nombre
				buscarProducto(elemento,n);
				break;
			case 4: //actualizar datos producto
				actualizarProducto(elemento,n);
				break;
			case 5: //eliminar datos producto
				eliminarProducto(elemento,n);
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
				cout<<"\nIngrese una opcion valida\n"<<endl;
				system("pause");
		}
	} while (op!=9);
	return 0;
}