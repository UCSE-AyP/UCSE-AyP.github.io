#include <iostream>
#include <iomanip>

using namespace std;

struct ReservaHotel {
    // Estructura declarada respetando estrictamente el orden del enunciado para inicializacion por llaves
    int nroHabitacion;     // Clave Primaria univoca
    int noches;            // Cantidad de noches reservadas (> 0)
    char tipo;             // 'S' (Simple 0%), 'D' (Doble +10%), 'T' (Triple +20%)
    double precioNoche;    // Tarifa base diaria (> 0)
    double importeTotal;   // Calculado: noches * precioNoche * (1 + recargoTipo)
    bool confirmada;       // true: Confirmada, false: Pendiente
};

// Prototipos de funciones a implementar por el estudiante (nucleo Modulo 4)
void intercambiar(ReservaHotel &a, ReservaHotel &b);
bool insertarReserva(ReservaHotel arr[], int &tam, int capacidad, int pos, const ReservaHotel &nueva);
bool modificarReserva(ReservaHotel arr[], int tam, const ReservaHotel &actualizada);
void ordenarPorImporteBurbujaDesc(ReservaHotel arr[], int tam);

// Modulos de presentacion y primitivas auxiliares pre-implementados en la plantilla
int buscarPorHabitacion(const ReservaHotel arr[], int tam, int nroBuscado);
bool darDeBajaReserva(ReservaHotel arr[], int &tam, int nroABorrar);
double calcularPromedioFacturacion(const ReservaHotel arr[], int tam);
void mostrarMenu();
void mostrarFicha(const ReservaHotel &e);
void mostrarTabla(const ReservaHotel arr[], int tam);

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

        cout << "\n----------------------------------------------------------------------\n";
        switch (opcion) {
            case 1:
                mostrarTabla(reservas, tam);
                break;
            case 2: {
                cout << ">>> CONSULTA DE RESERVA POR NUMERO DE HABITACION <<<\n";
                int nro;
                cout << "  Ingrese Numero de Habitacion a buscar: ";
                cin >> nro;
                int pos = buscarPorHabitacion(reservas, tam, nro);
                if (pos != -1) {
                    cout << "  [OK] Reserva localizada en celda [" << pos << "]:\n";
                    mostrarFicha(reservas[pos]);
                } else {
                    cout << "  [-] Habitacion " << nro << " no encontrada en el sistema de reservas.\n";
                }
                break;
            }
            case 3: {
                cout << ">>> REGISTRO / INSERCION DE NUEVA RESERVA <<<\n";
                int pos;
                cout << "  Ingrese posicion donde desea insertar [0 .. " << tam << "]: ";
                cin >> pos;
                ReservaHotel nueva;
                cout << "  Ingrese Numero de Habitacion (entero unico): ";
                cin >> nueva.nroHabitacion;
                cout << "  Ingrese Cantidad de noches (> 0): ";
                cin >> nueva.noches;
                cout << "  Ingrese Tipo de Habitacion ('S' Simple, 'D' Doble, 'T' Triple): ";
                cin >> nueva.tipo;
                cout << "  Ingrese Tarifa Base por Noche (> 0): $";
                cin >> nueva.precioNoche;
                int conf;
                cout << "  Estado de la reserva (1: Confirmada, 0: Pendiente): ";
                cin >> conf;
                while (conf != 0 && conf != 1) {
                    cout << "  [ERROR] Estado invalido. Ingrese 1 (Confirmada) o 0 (Pendiente): ";
                    cin >> conf;
                }
                nueva.confirmada = (conf == 1);

                double rec = 0.0;
                if (nueva.tipo == 'D' || nueva.tipo == 'd') rec = 0.10;
                else if (nueva.tipo == 'T' || nueva.tipo == 't') rec = 0.20;
                nueva.importeTotal = nueva.noches * nueva.precioNoche * (1.0 + rec);

                if (insertarReserva(reservas, tam, CAPACIDAD, pos, nueva)) {
                    cout << "\n  [OK] Reserva registrada exitosamente en la celda [" << pos << "]. Total: " << tam << "/" << CAPACIDAD << "\n";
                } else {
                    cout << "\n  [!] ERROR: No se pudo registrar. Verifique numero duplicado o cupo agotado.\n";
                }
                break;
            }
            case 4: {
                cout << ">>> MODIFICACION DE RESERVA (UPDATE / PK INMUTABLE) <<<\n";
                int nro;
                cout << "  Ingrese Numero de Habitacion de la reserva a modificar: ";
                cin >> nro;
                int pos = buscarPorHabitacion(reservas, tam, nro);
                if (pos == -1) {
                    cout << "\n  [-] Reserva no encontrada.\n";
                } else {
                    ReservaHotel modificada;
                    modificada.nroHabitacion = nro; // Clave primaria inmutable
                    cout << "  Modificando reserva de Habitacion: " << nro << " (inalterable)\n";
                    cout << "  Nuevas Noches de estadia (> 0): ";
                    cin >> modificada.noches;
                    cout << "  Nuevo Tipo de Habitacion ('S', 'D', 'T'): ";
                    cin >> modificada.tipo;
                    cout << "  Nueva Tarifa por Noche (> 0): $";
                    cin >> modificada.precioNoche;
                    int conf;
                    cout << "  Nuevo Estado (1: Confirmada, 0: Pendiente): ";
                    cin >> conf;
                    while (conf != 0 && conf != 1) {
                        cout << "  [ERROR] Estado invalido. Ingrese 1 (Confirmada) o 0 (Pendiente): ";
                        cin >> conf;
                    }
                    modificada.confirmada = (conf == 1);

                    double rec = 0.0;
                    if (modificada.tipo == 'D' || modificada.tipo == 'd') rec = 0.10;
                    else if (modificada.tipo == 'T' || modificada.tipo == 't') rec = 0.20;
                    modificada.importeTotal = modificada.noches * modificada.precioNoche * (1.0 + rec);

                    if (modificarReserva(reservas, tam, modificada)) {
                        cout << "\n  [OK] Reserva modificada exitosamente.\n";
                    } else {
                        cout << "\n  [!] Error al modificar.\n";
                    }
                }
                break;
            }
            case 5: {
                cout << ">>> CANCELACION / BAJA FISICA DE RESERVA (DELETE / COMPACTACION) <<<\n";
                int nro;
                cout << "  Ingrese Numero de Habitacion a cancelar: ";
                cin >> nro;
                if (darDeBajaReserva(reservas, tam, nro)) {
                    cout << "\n  [OK] Registro eliminado y arreglo compactado correctamente. Total activas: " << tam << "\n";
                } else {
                    cout << "\n  [-] Numero de habitacion no encontrado. No se realizo ninguna baja.\n";
                }
                break;
            }
            case 6:
                cout << ">>> ORDENAMIENTO BURBUJA (DESCENDENTE POR MONTO TOTAL) <<<\n";
                ordenarPorImporteBurbujaDesc(reservas, tam);
                cout << "  [OK] Reservas ordenadas de mayor a menor segun monto total con exito.\n";
                mostrarTabla(reservas, tam);
                break;
            case 7: {
                cout << ">>> REPORTE ESTADISTICO: CALCULAR PROMEDIO DE FACTURACION POR RESERVA <<<\n";
                double prom = calcularPromedioFacturacion(reservas, tam);
                cout << "  [RESULTADO] Promedio calculado: $" << fixed << setprecision(2) << prom << "\n";
                break;
            }
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

void intercambiar(ReservaHotel &a, ReservaHotel &b) {
    ReservaHotel aux = a;
    a = b;
    b = aux;
}

int buscarPorHabitacion(const ReservaHotel arr[], int tam, int nroBuscado) {
    for (int i = 0; i < tam; ++i) {
        if (arr[i].nroHabitacion == nroBuscado) {
            return i;
        }
    }
    return -1;
}

bool insertarReserva(ReservaHotel arr[], int &tam, int capacidad, int pos, const ReservaHotel &nueva) {
    if (tam >= capacidad || pos < 0 || pos > tam) return false;
    if (buscarPorHabitacion(arr, tam, nueva.nroHabitacion) != -1) return false;
    for (int i = tam; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = nueva;
    tam++;
    return true;
}

bool modificarReserva(ReservaHotel arr[], int tam, const ReservaHotel &actualizada) {
    int pos = buscarPorHabitacion(arr, tam, actualizada.nroHabitacion);
    if (pos == -1) return false;
    arr[pos].noches = actualizada.noches;
    arr[pos].tipo = actualizada.tipo;
    arr[pos].precioNoche = actualizada.precioNoche;
    arr[pos].importeTotal = actualizada.importeTotal;
    arr[pos].confirmada = actualizada.confirmada;
    return true;
}

bool darDeBajaReserva(ReservaHotel arr[], int &tam, int nroABorrar) {
    int pos = buscarPorHabitacion(arr, tam, nroABorrar);
    if (pos == -1) return false;
    for (int k = pos; k < tam - 1; ++k) {
        arr[k] = arr[k + 1];
    }
    tam--;
    return true;
}

void ordenarPorImporteBurbujaDesc(ReservaHotel arr[], int tam) {
    bool huboIntercambio = true;
    for (int i = 0; i < tam - 1 && huboIntercambio; ++i) {
        huboIntercambio = false;
        for (int j = 0; j < tam - 1 - i; ++j) {
            if (arr[j].importeTotal < arr[j + 1].importeTotal) {
                intercambiar(arr[j], arr[j + 1]);
                huboIntercambio = true;
            }
        }
    }
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
