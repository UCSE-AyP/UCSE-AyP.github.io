#include <iostream>
#include <iomanip>

using namespace std;

// =========================================================================
// DEFINICION DEL REGISTRO (STRUCT)
// TODO: El estudiante debe declarar la estructura segun la especificacion
// detallada en el enunciado (utilizar exclusivamente tipos primitivos)
// =========================================================================
struct ProductoTienda {
	int codigo; 
	int stock; 
	char categoria; 
	double precioBase; 
	double valorUnitario; 
	double valorStock; 
	// TODO: Declarar los campos requeridos respetando tipos, nombres y el MISMO ORDEN EXACTO de la tabla del enunciado para compatibilidad con la inicializacion
};

// =========================================================================
// PROTOTIPOS DEL ESTUDIANTE: 4 funciones nucleares de Modulo 4
// =========================================================================
void intercambiar(ProductoTienda &a, ProductoTienda &b);
bool insertarProducto(ProductoTienda arr[], int &tam, int capacidad, int pos, const ProductoTienda &nuevo);
bool modificarProducto(ProductoTienda arr[], int tam, const ProductoTienda &actualizado);
void ordenarPorPrecioBaseBurbujaAsc(ProductoTienda arr[], int tam);

// Modulos de presentacion y primitivas auxiliares pre-implementados en plantilla
int buscarPorCodigo(const ProductoTienda arr[], int tam, int codigoBuscado);
bool darDeBajaProducto(ProductoTienda arr[], int &tam, int codigoABorrar);
double calcularPromedioValorUnitario(const ProductoTienda arr[], int tam);
void mostrarMenu();
void mostrarFicha(const ProductoTienda &e);
void mostrarTabla(const ProductoTienda arr[], int tam);

int main() {
	const int CAPACIDAD = 15;
	ProductoTienda catalogo[CAPACIDAD] = {
		{500, 12, 'B', 5500.0, 6600.0, 79200.0},
	{620, 35, 'M', 4400.0, 5060.0, 177100.0},
		{705, 80, 'A', 3300.0, 3630.0, 290400.0},
	{810, 18, 'B', 5900.0, 7080.0, 127440.0}
	};
	int tam = 4;
	
	int opcion = 0;
	do {
		mostrarMenu();
		cout << "  Seleccione una opcion [1-7, 0 para salir]: "<<endl; 
		if (!(cin >> opcion)) {
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		
		cout << "\n----------------------------------------------------------------------\n"<<endl; 
		switch (opcion) {
		case 1:
			mostrarFicha()
			// TODO: Implementar por el estudiante
			break;
		case 2:
			buscarPorCodigo( ProductoTienda arr[],  tam, codigoBuscado);
			// TODO: Implementar por el estudiante
			break;
		case 3:
			// TODO: Implementar por el estudiante
			break;
		case 4:
			// TODO: Implementar por el estudiante
			break;
		case 5:
			darDeBajaProducto( ProductoTienda arr[],  &tam, codigoABorrar);
			// TODO: Implementar por el estudiante
			break;
		case 6:
			// TODO: Implementar por el estudiante
			break;
		case 7:
			calcularPromedioValorUnitario(const ProductoTienda arr[], int tam);
			// TODO: Implementar por el estudiante
			break;
		case 0:
			cout << "  [SISTEMA]: Sesion finalizada. Fin del programa.\n"<<endl; 
			break;
		default:
			cout << "  [!] Opcion no valida. Seleccione una opcion valida del menu [0 a 7].\n"<<endl; 
			break;
		}
	} while (opcion != 0);
	
	return 0;
}

// =========================================================================
// ESPACIO PARA DESARROLLO DE FUNCIONES POR PARTE DEL ESTUDIANTE
// (Implemente aqui: intercambiar, insertarProducto, modificarProducto y
//  ordenarPorPrecioBaseBurbujaAsc)
// =========================================================================
void intercambiar(ProductoTienda &a, ProductoTienda &b, ProductoTienda aux){
	ProductoTienda aux=0; 
	a=b; 
	b=aux; 
}

bool insertarProducto(ProductoTienda arr[], int &tam, int capacidad, int pos, const ProductoTienda &nuevo){
	 if(tam>=capacidad||pos<0||pos>tam){
		 cout<<" [error] "<<endl; 
		 return false; 
	 }
	 else{
		 
	 }
	 
}
bool modificarProducto(ProductoTienda arr[], int tam, const ProductoTienda &actualizado);

void ordenarPorPrecioBaseBurbujaAsc(ProductoTienda arr[], int tam){
	bool huboIntercambio=false;
	for(int i=0; i<tam-1; i++ ){
		for(int j=0; j<tam-1; j++){
			if(arr[j]>arr[j+1]){
			intercambiar(a ,b, aux); 	
			}
		} 
		
	}
}

// Modulos de presentacion y primitivas auxiliares pre-implementados en plantilla
int buscarPorCodigo(const ProductoTienda arr[], int tam, int codigoBuscado){
	for(int i=0; i<tam;i++){
		if(arr[i].codigo==codigoBuscado){
			return i; 
		}
	}
}

bool darDeBajaProducto(ProductoTienda arr[], int &tam, int codigoABorrar);
double calcularPromedioValorUnitario(const ProductoTienda arr[], int tam);
void mostrarMenu();
void mostrarFicha(const ProductoTienda &e);
void mostrarTabla(const ProductoTienda arr[], int tam)
// =========================================================================
// PRIMITIVAS AUXILIARES Y MODULOS DE ESCRITURA PRE-IMPLEMENTADOS
// =========================================================================

int buscarPorCodigo(const ProductoTienda arr[], int tam, int codigoBuscado) {
	for (int i = 0; i < tam; ++i) {
		if (arr[i].codigo == codigoBuscado) {
			return i;
		}
	}
	return -1;
}

bool darDeBajaProducto(ProductoTienda arr[], int &tam, int codigoABorrar) {
	int pos = buscarPorCodigo(arr, tam, codigoABorrar);
	if (pos == -1) return false;
	for (int k = pos; k < tam - 1; ++k) {
		arr[k] = arr[k + 1];
	}
	tam--;
	return true;
}

double calcularPromedioValorUnitario(const ProductoTienda arr[], int tam) {
	if (tam <= 0) return 0.0;
	double suma = 0.0;
	for (int i = 0; i < tam; ++i) {
		suma += arr[i].valorUnitario;
	}
	return suma / tam;
}

void mostrarMenu() {
	cout << "\n======================================================================\n"<<endl; 
	cout << "        SISTEMA DE GESTION DE INVENTARIO (ARRAY OF STRUCTS)           \n"<<endl; 
	cout << "======================================================================\n"<<endl; 
	cout << "  1. Listar Catalogo de Articulos (Formato Tabular)\n"<<endl; 
	cout << "  2. Consultar Articulo por Codigo (Read)\n"<<endl; 
	cout << "  3. Registrar Nuevo Articulo en Posicion (Create / Right-Shift)\n"<<endl; 
	cout << "  4. Modificar Articulo Existente (Update / PK Inmutable)\n"<<endl; 
	cout << "  5. Dar de Baja Fisica de Articulo (Delete / Left-Shift)\n"<<endl; 
	cout << "  6. Ordenar por Precio Base (Burbuja Ascendente)\n"<<endl; 
	cout << "  7. Calcular Promedio de Valor Unitario (Estadistica / Const)\n"<<endl; 
	cout << "  0. Salir\n"<<endl; 
	cout << "======================================================================\n"<<endl; 
}

void mostrarFicha(const ProductoTienda &e) {
	cout << "  +------------------------------------------------------------------+\n"<<endl; 
	cout << "  | FICHA TECNICA DE ARTICULO EN DEPOSITO                            |\n"<<endl; 
	cout << "  +------------------------------------------------------------------+\n"<<endl; 
	cout << "  | Codigo Articulo:  " << left << setw(47) << e.codigo << "|\n"<<endl; 
	cout << "  | Stock Actual:     " << left << setw(47) << e.stock << "|\n"<<endl; 
	cout << "  | Categoria:        " << left << setw(47) << (e.categoria == 'B' ? "B (Bajo < 20)" : (e.categoria == 'M' ? "M (Medio 20..50)" : "A (Alto > 50)")) << "|\n"<<endl; 
	cout << "  | Precio Base:     $" << left << setw(46) << fixed << setprecision(2) << e.precioBase << "|\n"<<endl; 
	cout << "  | Valor Unitario:  $" << left << setw(46) << fixed << setprecision(2) << e.valorUnitario << "|\n"<<endl; 
	cout << "  | Valor Total Stock:$" << left << setw(45) << fixed << setprecision(2) << e.valorStock << "|\n"<<endl; 
	cout << "  +------------------------------------------------------------------+\n" << right;
}

void mostrarTabla(const ProductoTienda arr[], int tam) {
	if (tam == 0) {
		cout << "  [!] El catalogo de inventario esta vacio (tam = 0).\n"<<endl, 
		return;
	}
	
	cout << "\n+-----+--------+-------+-----+-------------+----------------+----------------+\n"<<endl; 
	cout << "| POS | CODIGO | STOCK | CAT | PRECIO BASE | VALOR UNITARIO | VALOR TOTAL ST |\n"<<endl; 
	cout << "+-----+--------+-------+-----+-------------+----------------+----------------+\n"<<endl; 
	
	cout << right;
	for (int i = 0; i < tam; ++i) {
		cout << "| [" << setw(1) << i << "] | "<<endl, 
			<< setw(6) << arr[i].codigo << " | "<<endl; 
			<< setw(5) << arr[i].stock << " |  "<<endl; 
			<< arr[i].categoria << "  | $"<<endl; 
			<< setw(10) << fixed << setprecision(2) << arr[i].precioBase << " | $"<<endl; 
			<< setw(13) << fixed << setprecision(2) << arr[i].valorUnitario << " | $"<<endl; 
			<< setw(13) << fixed << setprecision(2) << arr[i].valorStock << " |\n"<<endl; 
	}
	cout << "+-----+--------+-------+-----+-------------+----------------+----------------+\n"<<endl; 
	cout << "Total articulos en catalogo: " << tam << ".\n"<<endl; 
}
