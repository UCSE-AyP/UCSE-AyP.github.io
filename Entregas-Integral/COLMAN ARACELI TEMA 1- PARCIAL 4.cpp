#include <iostream>
#include <iomanip>

using namespace std;

// =========================================================================
// DEFINICION DEL REGISTRO (STRUCT)
// TODO: El estudiante debe declarar la estructura segun la especificacion
// detallada en el enunciado (utilizar exclusivamente tipos primitivos)
// =========================================================================
struct ProductoTienda {
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
        cout << "  Seleccione una opcion [1-7, 0 para salir]: ";
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cout << "\n----------------------------------------------------------------------\n";
        switch (opcion) {
            case 1:
                // TODO: Implementar por el estudiante
                break;
            case 2:
                // TODO: Implementar por el estudiante
                break;
            case 3:
                // TODO: Implementar por el estudiante
                break;
            case 4:
                // TODO: Implementar por el estudiante
                break;
            case 5:
                // TODO: Implementar por el estudiante
                break;
            case 6:
                // TODO: Implementar por el estudiante
                break;
            case 7:
                // TODO: Implementar por el estudiante
                break;
            case 0:
                cout << "  [SISTEMA]: Sesion finalizada. Fin del programa.\n";
                break;
            default:
                cout << "  [!] Opcion no valida. Seleccione una opcion valida del menu [0 a 7].\n";
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
struct ProductoTienda();

 int codigo;
 int stock;
 char categoria;
 double precioBase;
 double valorUnitario;
 double valorStock;
 
 bool insertarProducto (ProductoTienda arr[], int &tam;int capacidad, int pos, const ProductoTienda &nuevo){
    if 	(tam >= capacidad);
	 return false;
	if (pos < 0 || pos > tam);
	return false;
	if (buscarPorCodigo(arr[],tam,codigoBuscado)!=-1);
	return false;
	for (int i=tam;i>pos;i--);{
	  arr[i]==arr[i-1];{
	  }
	arr[pos]=nuevo;
	tam++;
	return true;
  } 
}

bool modificarProducto (ProductoTienda arr[], int tam,const ProductoTienda &actualizado);{
 int pos= buscarPorCodigo(arr[],tam,codigoBuscado);{
 if (pos==-1);
}
 return false;
 arr[pos].stock = nuevoStock;
 arr[pos].categoria = nuevaCategoria;
 arr[pos].precioBase = nuevoPrecio;
 arr[pos].valorUnitario = nuevoValor;
 arr[pos].valorStock = nuevoValorStock;
 calcular Derivadas (arr[pos]);
 return true;
}

// =========================================================================
// PRIMITIVAS AUXILIARES Y MODULOS DE ESCRITURA PRE-IMPLEMENTADOS
  int auxiliarProductoTienda (Producto &a, Producto &b){
  	auxliarProducto= a;
  	a=b;
  	b=auxiliar;
  	return 0;
  }
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
    cout << "\n======================================================================\n";
    cout << "        SISTEMA DE GESTION DE INVENTARIO (ARRAY OF STRUCTS)           \n";
    cout << "======================================================================\n";
    cout << "  1. Listar Catalogo de Articulos (Formato Tabular)\n";
    cout << "  2. Consultar Articulo por Codigo (Read)\n";
    cout << "  3. Registrar Nuevo Articulo en Posicion (Create / Right-Shift)\n";
    cout << "  4. Modificar Articulo Existente (Update / PK Inmutable)\n";
    cout << "  5. Dar de Baja Fisica de Articulo (Delete / Left-Shift)\n";
    cout << "  6. Ordenar por Precio Base (Burbuja Ascendente)\n";
    cout << "  7. Calcular Promedio de Valor Unitario (Estadistica / Const)\n";
    cout << "  0. Salir\n";
    cout << "======================================================================\n";
}

void mostrarFicha(const ProductoTienda &e) {
    cout << "  +------------------------------------------------------------------+\n";
    cout << "  | FICHA TECNICA DE ARTICULO EN DEPOSITO                            |\n";
    cout << "  +------------------------------------------------------------------+\n";
    cout << "  | Codigo Articulo:  " << left << setw(47) << e.codigo << "|\n";
    cout << "  | Stock Actual:     " << left << setw(47) << e.stock << "|\n";
    cout << "  | Categoria:        " << left << setw(47) << (e.categoria == 'B' ? "B (Bajo < 20)" : (e.categoria == 'M' ? "M (Medio 20..50)" : "A (Alto > 50)")) << "|\n";
    cout << "  | Precio Base:     $" << left << setw(46) << fixed << setprecision(2) << e.precioBase << "|\n";
    cout << "  | Valor Unitario:  $" << left << setw(46) << fixed << setprecision(2) << e.valorUnitario << "|\n";
    cout << "  | Valor Total Stock:$" << left << setw(45) << fixed << setprecision(2) << e.valorStock << "|\n";
    cout << "  +------------------------------------------------------------------+\n" << right;
}

void mostrarTabla(const ProductoTienda arr[], int tam) {
    if (tam == 0) {
        cout << "  [!] El catalogo de inventario esta vacio (tam = 0).\n";
        return;
    }

    cout << "\n+-----+--------+-------+-----+-------------+----------------+----------------+\n";
    cout << "| POS | CODIGO | STOCK | CAT | PRECIO BASE | VALOR UNITARIO | VALOR TOTAL ST |\n";
    cout << "+-----+--------+-------+-----+-------------+----------------+----------------+\n";

    cout << right;
    for (int i = 0; i < tam; ++i) {
        cout << "| [" << setw(1) << i << "] | "
             << setw(6) << arr[i].codigo << " | "
             << setw(5) << arr[i].stock << " |  "
             << arr[i].categoria << "  | $"
             << setw(10) << fixed << setprecision(2) << arr[i].precioBase << " | $"
             << setw(13) << fixed << setprecision(2) << arr[i].valorUnitario << " | $"
             << setw(13) << fixed << setprecision(2) << arr[i].valorStock << " |\n";
    }
    cout << "+-----+--------+-------+-----+-------------+----------------+----------------+\n";
    cout << "Total articulos en catalogo: " << tam << ".\n";
}
