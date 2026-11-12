#include <iostream>
#include <iomanip>

using namespace std;

// =========================================================================
// DEFINICION DEL REGISTRO (STRUCT)
// TODO: El estudiante debe declarar la estructura segun la especificacion
// detallada en el enunciado (utilizar exclusivamente tipos primitivos)
// =========================================================================
struct ProductoTienda {
    int codigo ;
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
void calcularproductos(ProductoTienda& Productotienda);
void intercambiar(ProductoTienda &a, ProductoTienda &b);
bool insertarProducto(ProductoTienda arr[], int &tam, int capacidad, int pos,const  ProductoTienda &nuevo);
bool modificarProducto(ProductoTienda arr[], int tam,int codMod, const ProductoTienda &actualizado);
void ordenarPorPrecioBaseBurbujaAsc(ProductoTienda arr[], int tam);

// Modulos de presentacion y primitivas auxiliares pre-implementados en plantilla
int buscarPorCodigo(const ProductoTienda arr[], int tam, int codigoBuscado);
bool darDeBajaProducto(ProductoTienda arr[], int &tam, int codigoABorrar);
double calcularPromedioValorUnitario(const ProductoTienda arr[], int tam);
void mostrarMenu();
void mostrarFicha(const ProductoTienda &e);
void mostrarTabla(const ProductoTienda arr[], int tam);
const int CAPACIDAD = 15;
int main() {

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
                mostrarTabla ( catalogo, tam);
                // TODO: Implementar por el estudiante
                break;
            case 2: {
                int codigobuscar;
                cout << " Ingrese el codigo a modificar" << endl;
                cin >> codigobuscar;
                int pos = buscarPorCodigo(catalogo,tam,codigobuscar);
                if (pos != -1 ){
                    mostrarFicha(catalogo[pos]);
                }
            }


                // TODO: Implementar por el estudiante
                break;
            case 3: {
                ProductoTienda nuevo ;
                int pos ;
                cout << " Ingrese posicion donde desea insertar [0..4]" << endl ;
                cin >> pos ;
                cout << " Ingrese codigo del articulo (entero unico)" << endl ;
                cin >> nuevo.codigo;
                cout << " Ingrese stock inicial en deposito (>=0)" << endl;
                cin >> nuevo.stock;
                cout << " Ingrese precio base (> 0)";
                cin >> nuevo.precioBase ;
                if (nuevo.codigo >= 0 && nuevo.stock >= 0 && nuevo.precioBase > 0.0) {
                    calcularproductos(nuevo);
                    if (insertarProducto(catalogo,tam, CAPACIDAD, pos,nuevo)) {
                        cout << " se inserto correctamente " << endl;
                    }else {
                        cout << " no se pudo insertar " << endl;
                    }
                }else {
                    cout << " Codigo invalido " << endl;
                }
            }



                // TODO: Implementar por el estudiante
                break;
            case 4: {
                int codMod;
                int stock;
                double precioBase;
                ProductoTienda registro;

                cout << " Ingrese el codigo a modificar " << endl;
                cin >> codMod;
                cout << " nuevo stock en deposito (>=0)"<< endl;
                cin >> stock ;
                cout << " Nuevo precio base "<< endl;
                cin >> precioBase;
                if (modificarProducto(catalogo, tam, codMod, registro )) {
                    cout << " se modifico correctamente " << endl;
                }else {
                    cout << " No se modifico correctamente "<< endl;
                }
            }

                // TODO: Implementar por el estudiante
                break;
            case 5: {
                int codigoABorrar ;
                cout << " Ingrese codigo a borrar " << endl;
                cin >> codigoABorrar;
                if (darDeBajaProducto(catalogo, tam,codigoABorrar)) {
                    cout << " Se borro correctamente " << endl;
                }else {
                    cout << " No se pudo borrar" << endl;
                }
            }


                // TODO: Implementar por el estudiante
                break;
            case 6: {
                ordenarPorPrecioBaseBurbujaAsc(catalogo, tam);
                cout << " Se ordeno correcatamente" << endl;
                mostrarTabla(catalogo,tam);
            }

                // TODO: Implementar por el estudiante
                break;
            case 7: {
                double promedio = calcularPromedioValorUnitario(catalogo, tam);
                cout << " el promedio es" <<fixed << setprecision(2)<< promedio ;
            }

                // TODO: Implementar por el estudiante
                break;
            case 0: {
                cout << "  [SISTEMA]: Sesion finalizada. Fin del programa.\n";
            }

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

// =========================================================================
// PRIMITIVAS AUXILIARES Y MODULOS DE ESCRITURA PRE-IMPLEMENTADOS
// =========================================================================

void calcularproductos(ProductoTienda& Productotienda) {
    if (Productotienda.stock < 20 ) {
        Productotienda.categoria = 'B';
        Productotienda.valorUnitario = Productotienda.precioBase *1.20;
        Productotienda.valorStock = Productotienda.valorUnitario * Productotienda.stock;
    }else if (Productotienda.stock <= 50 ) {
        Productotienda.categoria = 'M';
        Productotienda.valorUnitario=Productotienda.precioBase * 1.15;
        Productotienda.valorStock=Productotienda.valorUnitario * Productotienda.stock;
    }else {
        Productotienda.categoria = 'A';
        Productotienda.valorUnitario=Productotienda.precioBase * 1.10;
        Productotienda.valorStock = Productotienda.valorUnitario * Productotienda.stock;
    }

}

bool insertarProducto(ProductoTienda arr[], int &tam, int capacidad, int pos,  const ProductoTienda &nuevo) {
    int  existe = buscarPorCodigo(arr, tam, nuevo.codigo );

    if (tam >= CAPACIDAD || pos < 0 || pos > tam || existe != -1 ) {
        return false ;
    }
    for (int i = tam;i > pos;i--) {
        arr[i]=arr[i-1];
    }
    arr[pos]= nuevo,
    tam++;
    return true ;
}


bool modificarProducto(ProductoTienda arr[], int tam,int codMod,  const ProductoTienda &actualizado) {
    if (actualizado.stock  >= 0|| actualizado.precioBase > 0.0) {
        return false ;
    }

    int pos = buscarPorCodigo(arr, tam,codMod);
    if (pos != -1) {
        arr[pos].stock = arr[pos].stock ;
        arr[pos].precioBase =arr[pos].precioBase;
            calcularproductos(arr[pos]);
        return true ;
    }
    return false ;
}

void intercambiar(ProductoTienda &a, ProductoTienda &b) {
    ProductoTienda aux = a;
    a=b;
    b=aux;
}

void ordenarPorPrecioBaseBurbujaAsc(ProductoTienda arr[], int tam) {
    int i = 0;
    bool hubointercambio = true ;
    while ( i < tam -1 && hubointercambio) {
        hubointercambio=false;
        for (int j =0;j<tam -1 -i;j++) {
            if (arr[j].precioBase > arr[j+1].precioBase) {
                intercambiar(arr[j], arr[j+1]);
                hubointercambio=true;
            }
        }
        i++;
    }

}

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
