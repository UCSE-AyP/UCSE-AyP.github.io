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


void calcularCamposDerivados(ProductoTienda &p) {
	if (p.stock < 20) {
		p.categoria = 'B';
		p.valorUnitario = p.precioBase * 1.20;
	} else if (p.stock <= 50) {
		p.categoria = 'M';
		p.valorUnitario = p.precioBase * 1.15;
	} else {
		p.categoria = 'A';
		p.valorUnitario = p.precioBase * 1.10;
	}
	p.valorStock = p.valorUnitario * p.stock;
}

int main() {
	const int CAPACIDAD = 15;
	ProductoTienda catalogo[CAPACIDAD] = {
		{500, 12, 'B', 5500.0, 6600.0,  79200.0},
	{620, 35, 'M', 4400.0, 5060.0, 177100.0},
		{705, 80, 'A', 3300.0, 3630.0, 290400.0},
	{810, 18, 'B', 5900.0, 7080.0, 127440.0}
	};
	int tam = 4;
	int opcion = 0;
	
	do {
		mostrarMenu();
		cout << " Seleccione una opcion [1-7, 0 para salir]: ";
		if (!(cin >> opcion)) {
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		cout << "\n----------------------------------------------------------------------\n";
		
		switch (opcion) {
		case 1: {
			mostrarTabla(catalogo, tam);
			break;
		}
		case 2: {
			int codBuscado;
			cout << " >>> CONSULTA DE ARTICULO POR CODIGO <<<\n";
			cout << " Ingrese Codigo a buscar: ";
			cin >> codBuscado;
			
			int pos = buscarPorCodigo(catalogo, tam, codBuscado);
			if (pos != -1) {
				cout << " [OK] Articulo encontrado en posicion [" << pos << "]:\n";
				mostrarFicha(catalogo[pos]);
			} else {
				cout << " [!] No existe ningun articulo registrado con el codigo " << codBuscado << ".\n";
			}
			break;
		}
		case 3: {
			cout << " >>> ALTA / INSERCION DE ARTICULO EN INVENTARIO <<<\n";
			if (tam >= CAPACIDAD) {
				cout << " [!] Error: El catalogo ha alcanzado su capacidad maxima (" << CAPACIDAD << ").\n";
				break;
			}
			
			int pos;
			cout << " Ingrese posicion donde desea insertar [0 .. " << tam << "]: ";
			cin >> pos;
			
			ProductoTienda nuevo;
			cout << " Ingrese Codigo del articulo (entero unico): ";
			cin >> nuevo.codigo;
			cout << " Ingrese Stock inicial en deposito (>= 0): ";
			cin >> nuevo.stock;
			cout << " Ingrese Precio Base (> 0): $";
			cin >> nuevo.precioBase;
			
			if (nuevo.codigo <= 0 || nuevo.stock < 0 || nuevo.precioBase <= 0.0) {
				cout << " [!] Error: Datos invalidos (codigo > 0, stock >= 0, precioBase > 0).\n";
				break;
			}
			
			calcularCamposDerivados(nuevo);
			
			if (insertarProducto(catalogo, tam, CAPACIDAD, pos, nuevo)) {
				cout << " [OK] Articulo registrado exitosamente en la celda [" << pos << "]. Total: " << tam << "/" << CAPACIDAD << "\n";
			} else {
				cout << " [!] Error: No se pudo insertar (posicion fuera de rango o codigo duplicado).\n";
			}
			break;
		}
		case 4: {
			cout << " >>> MODIFICACION DE ARTICULO EXISTENTE <<<\n";
			ProductoTienda actualizado;
			cout << " Ingrese Codigo del articulo a modificar: ";
			cin >> actualizado.codigo;
			
			if (buscarPorCodigo(catalogo, tam, actualizado.codigo) == -1) {
				cout << " [!] Error: No se encontro ningun articulo con codigo " << actualizado.codigo << ".\n";
				break;
			}
			
			cout << " Ingrese nuevo Stock (>= 0): ";
			cin >> actualizado.stock;
			cout << " Ingrese nuevo Precio Base (> 0): $";
			cin >> actualizado.precioBase;
			
			if (actualizado.stock < 0 || actualizado.precioBase <= 0.0) {
				cout << " [!] Error: Datos invalidos (stock >= 0, precioBase > 0).\n";
				break;
			}
			
			calcularCamposDerivados(actualizado);
			
			if (modificarProducto(catalogo, tam, actualizado)) {
				cout << " [OK] Articulo con codigo " << actualizado.codigo << " actualizado correctamente.\n";
			}
			break;
		}
		case 5: {
			cout << " >>> BAJA FISICA DE ARTICULO <<<\n";
			int codBorrar;
			cout << " Ingrese Codigo del articulo a dar de baja: ";
			cin >> codBorrar;
			
			if (darDeBajaProducto(catalogo, tam, codBorrar)) {
				cout << " [OK] Articulo eliminado y catalogo compactado. Total: " << tam << "/" << CAPACIDAD << "\n";
			} else {
				cout << " [!] Error: No existe articulo con codigo " << codBorrar << ".\n";
			}
			break;
		}
		case 6: {
			cout << " >>> ORDENAMIENTO POR PRECIO BASE (ASCENDENTE) <<<\n";
			ordenarPorPrecioBaseBurbujaAsc(catalogo, tam);
			cout << " [OK] Catalogo ordenado ascendentemente por Precio Base.\n";
			mostrarTabla(catalogo, tam);
			break;
		}
		case 7: {
			cout << " >>> ESTADISTICA: PROMEDIO DE VALOR UNITARIO <<<\n";
			double prom = calcularPromedioValorUnitario(catalogo, tam);
			cout << " Promedio de Valor Unitario (" << tam << " articulos): $" 
				<< fixed << setprecision(2) << prom << "\n";
			break;
		}
		case 0:
			cout << " [SISTEMA]: Sesion finalizada. Fin del programa.\n";
			break;
		default:
			cout << " [!] Opcion no valida. Seleccione una opcion valida del menu [0 a 7].\n";
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

void intercambiar(ProductoTienda &a, ProductoTienda &b) {
	ProductoTienda aux = a;
	a = b;
	b = aux;
}

bool insertarProducto(ProductoTienda arr[], int &tam, int capacidad, int pos, const ProductoTienda &nuevo) {
	if (tam >= capacidad || pos < 0 || pos > tam) {
		return false;
	}
	if (buscarPorCodigo(arr, tam, nuevo.codigo) != -1) {
		return false;
	}
	for (int i = tam; i > pos; --i) {
		arr[i] = arr[i - 1];
	}
	arr[pos] = nuevo;
	tam++;
	return true;
}

bool modificarProducto(ProductoTienda arr[], int tam, const ProductoTienda &actualizado) {
	int pos = buscarPorCodigo(arr, tam, actualizado.codigo);
	if (pos == -1) {
		return false;
	}
	
	arr[pos].stock = actualizado.stock;
	arr[pos].categoria = actualizado.categoria;
	arr[pos].precioBase = actualizado.precioBase;
	arr[pos].valorUnitario = actualizado.valorUnitario;
	arr[pos].valorStock = actualizado.valorStock;
	
	return true;
}

void ordenarPorPrecioBaseBurbujaAsc(ProductoTienda arr[], int tam) {
	bool huboIntercambio = true;
	for (int i = 0; i < tam - 1 && huboIntercambio; ++i) {
		huboIntercambio = false;
		for (int j = 0; j < tam - 1 - i; ++j) {
			if (arr[j].precioBase > arr[j + 1].precioBase) {
				intercambiar(arr[j], arr[j + 1]);
				huboIntercambio = true;
			}
		}
	}
}

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
