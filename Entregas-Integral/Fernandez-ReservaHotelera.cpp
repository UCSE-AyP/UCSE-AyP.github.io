#include <iostream>
#include <iomanip>

using namespace std;

// =========================================================================
// DEFINICION DEL REGISTRO (STRUCT)
// TODO: El estudiante debe declarar la estructura segun la especificacion
// detallada en el enunciado (utilizar exclusivamente tipos primitivos)
// =========================================================================
struct ReservaHotel {
    // TODO: Declarar los campos requeridos respetando tipos, nombres y el MISMO ORDEN EXACTO de la tabla del enunciado para compatibilidad con la inicializacion
    int nroHabitacion;
    int noches;
    char tipo;
    double precioNoche;
    double importeTotal;
    bool confirmada;
};

// =========================================================================
// PROTOTIPOS DEL ESTUDIANTE: 4 funciones nucleares de Modulo 4
// =========================================================================
void intercambiar(ReservaHotel &a, ReservaHotel &b);
bool insertarReserva(ReservaHotel arr[], int &tam, int capacidad, int pos, const ReservaHotel &nueva);
bool modificarReserva(ReservaHotel arr[], int tam, const ReservaHotel &actualizada);
void ordenarPorImporteBurbujaDesc(ReservaHotel arr[], int tam);

// Modulos de presentacion y primitivas auxiliares pre-implementados en plantilla
int buscarPorHabitacion(const ReservaHotel arr[], int tam, int nroBuscado);
bool darDeBajaReserva(ReservaHotel arr[], int &tam, int nroABorrar);
double calcularPromedioFacturacion(const ReservaHotel arr[], int tam);
void mostrarMenu();
void mostrarFicha(const ReservaHotel &e);
void mostrarTabla(const ReservaHotel arr[], int tam);

void modificarReserva(ReservaHotel * arr, int tam, int actualizada);

void insertarReserva(ReservaHotel * arr, int tam, int capacidad, double pos, int nueva);

int main() {
    const int CAPACIDAD = 15;
    ReservaHotel reservas[CAPACIDAD] = {
        {101, 2, 'S', 38000.0, 76000.0,  true},
        {204, 5, 'D', 52000.0, 286000.0, false},
        {305, 3, 'T', 61000.0, 219600.0, true},
        {408, 1, 'S', 38000.0, 38000.0,  true}
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
        double pos = 0;
        int  nroBuscado = 0, nueva = 0, actualizada = 0, nroABorrar = 0;
        cout << "\n----------------------------------------------------------------------\n";
        switch (opcion) {
            case 1:
                // TODO: Implementar por el estudiante
                mostrarTabla(reservas, tam);
                break;
            case 2:
                // TODO: Implementar por el estudiante
                buscarPorHabitacion(reservas, tam, nroBuscado);
                break;
            case 3:
                // TODO: Implementar por el estudiante
                insertarReserva(reservas, tam, CAPACIDAD, pos, nueva);
                break;
            case 4:
                // TODO: Implementar por el estudiante
                modificarReserva(reservas, tam, actualizada);
                break;
            case 5:
                // TODO: Implementar por el estudiante
                darDeBajaReserva(reservas, tam, nroABorrar);
                break;
            case 6:
                // TODO: Implementar por el estudiante
                ordenarPorImporteBurbujaDesc(reservas, tam);
                break;
            case 7:
                // TODO: Implementar por el estudiante
                calcularPromedioFacturacion(reservas, tam);
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
// (Implemente aqui: intercambiar, insertarReserva, modificarReserva y
//  ordenarPorImporteBurbujaDesc)
void intercambiar(ReservaHotel &a, ReservaHotel &b) {
    ReservaHotel aux = a;
    a=b;
    b=aux;
}

bool insertarReserva(ReservaHotel arr[], int &tam, int capacidad, int pos, const ReservaHotel &nueva) {
    if (tam >= capacidad)return false;
    if (pos < 0 || pos > tam)return false;
    if (buscarPorHabitacion(arr, tam, nueva.nroHabitacion)!= -1)return false;
    for (int i=tam;i>pos+1;--i) {
        arr[i]=arr[i-1];
    }
    arr[pos]=nueva;
    tam++;
    return true;
}

bool modificarReserva(ReservaHotel arr[], int tam, const ReservaHotel &actualizada) {
    int pos = buscarPorHabitacion(arr, tam, actualizada.nroHabitacion);
    if(pos==-1)return false;
    double recargo=0.0;
    if (actualizada.tipo=='D') recargo=0.20;
    arr[pos].noches              = actualizada.noches;
    arr[pos].tipo                = actualizada.tipo;
    arr[pos].precioNoche         = actualizada.precioNoche;
    arr[pos].importeTotal        = actualizada.noches*actualizada.precioNoche*(1.8 + recargo);
    arr[pos].confirmada          = actualizada.confirmada;
    return true;
}

void ordenarPorImporteBurbujaDesc(ReservaHotel arr[], int tam) {
    int i=0;
    bool huboIntercambio=true;
    while (i<tam-1 && huboIntercambio) {
        huboIntercambio=false;
        for (int j=0;j<tam-1-i;++j) {
            if (arr[j].importeTotal<arr[j+1].importeTotal) {
                intercambiar(arr[j], arr[j+1]);
                huboIntercambio=true;
            }
        }
    }
}

// =========================================================================

// =========================================================================
// PRIMITIVAS AUXILIARES Y MODULOS DE ESCRITURA PRE-IMPLEMENTADOS
// =========================================================================

int buscarPorHabitacion(const ReservaHotel arr[], int tam, int &nroBuscado) {
    cout<<"Ingrese el numero a buscar\n";
    cin>>nroBuscado;
    for (int i = 0; i < tam; ++i) {
        if (arr[i].nroHabitacion == nroBuscado) {
            return i;
        }
    }
    return -1;
}

int buscarPorHabitacion(ReservaHotel * arr, int tam, int nro_buscado);

bool darDeBajaReserva(ReservaHotel arr[], int &tam, int nroABorrar) {
    int pos = buscarPorHabitacion(arr, tam, nroABorrar);
    if (pos == -1) return false;
    for (int k = pos; k < tam - 1; ++k) {
        arr[k] = arr[k + 1];
    }
    tam--;
    return true;
}

double calcularPromedioFacturacion(const ReservaHotel arr[], int tam) {
    if (tam <= 0) return 0.0;
    double suma = 0.0;
    for (int i = 0; i < tam; ++i) {
        suma += arr[i].importeTotal;
    }
    return suma / tam;
}

void mostrarMenu() {
    cout << "\n======================================================================\n";
    cout << "        SISTEMA DE GESTION HOTELERA (ARRAY OF STRUCTS)                \n";
    cout << "======================================================================\n";
    cout << "  1. Listar Libro de Reservas (Formato Tabular)\n";
    cout << "  2. Consultar Reserva por Numero de Habitacion (Read)\n";
    cout << "  3. Registrar Nueva Reserva en Posicion (Create / Right-Shift)\n";
    cout << "  4. Modificar Reserva Existente (Update / PK Inmutable)\n";
    cout << "  5. Cancelar Reserva / Baja Fisica (Delete / Left-Shift)\n";
    cout << "  6. Ordenar por Importe Total (Burbuja Descendente)\n";
    cout << "  7. Calcular Promedio de Facturacion por Reserva (Estadistica / Const)\n";
    cout << "  0. Salir\n";
    cout << "======================================================================\n";
}

void mostrarFicha(const ReservaHotel &e) {
    cout << "  +------------------------------------------------------------------+\n";
    cout << "  | VOUCHER DE RESERVA HOTELERA                                      |\n";
    cout << "  +------------------------------------------------------------------+\n";
    cout << "  | Nro Habitacion:   " << left << setw(47) << e.nroHabitacion << "|\n";
    cout << "  | Noches Estadia:   " << left << setw(47) << e.noches << "|\n";
    cout << "  | Tipo Habitacion:  " << left << setw(47) << (e.tipo == 'S' ? "S (Simple)" : (e.tipo == 'D' ? "D (Doble)" : "T (Triple)")) << "|\n";
    cout << "  | Tarifa por Noche:$" << left << setw(46) << fixed << setprecision(2) << e.precioNoche << "|\n";
    cout << "  | Importe Total:   $" << left << setw(46) << fixed << setprecision(2) << e.importeTotal << "|\n";
    cout << "  | Estado Reserva:   " << left << setw(47) << (e.confirmada ? "Confirmada" : "Pendiente") << "|\n";
    cout << "  +------------------------------------------------------------------+\n" << right;
}

void mostrarTabla(const ReservaHotel arr[], int tam) {
    if (tam == 0) {
        cout << "  [!] El registro de reservas esta vacio (tam = 0).\n";
        return;
    }

    cout << "\n+-----+--------+--------+-----+--------------+---------------+------------+\n";
    cout << "| POS | HABIT. | NOCHES | TIP | TARIFA NOCHE | IMPORTE TOTAL | ESTADO     |\n";
    cout << "+-----+--------+--------+-----+--------------+---------------+------------+\n";

    cout << right;
    for (int i = 0; i < tam; ++i) {
        cout << "| [" << setw(1) << i << "] | "
             << setw(6) << arr[i].nroHabitacion << " | "
             << setw(6) << arr[i].noches << " |  "
             << arr[i].tipo << "  | $"
             << setw(11) << fixed << setprecision(2) << arr[i].precioNoche << " | $"
             << setw(12) << fixed << setprecision(2) << arr[i].importeTotal << " | "
             << left << setw(10) << (arr[i].confirmada ? "Confirmada" : "Pendiente") << right << " |\n";
    }
    cout << "+-----+--------+--------+-----+--------------+---------------+------------+\n";
    cout << "Total reservas activas: " << tam << ".\n";
}
