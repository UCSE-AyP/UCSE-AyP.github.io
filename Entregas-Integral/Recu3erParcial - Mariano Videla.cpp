//
// Created by Mariianii on 12/11/2026.
//
#include <iostream>
#include <iomanip>

using namespace std;

// =========================================================================
// CONSTANTES DEL DOMINIO (Tema 2: Parque Eólico Rawson)
// =========================================================================

const int CAPACIDAD = 15;
const double MIN_POTENCIA = 50.0;
const double MAX_POTENCIA = 600.0;
const double UMBRAL_RENDIMIENTO_OPTIMO = 350.0;

// =========================================================================
// PROTOTIPOS DE FUNCIONES (5 Funciones a Implementar por el Estudiante)
// =========================================================================

void MostrarMenu(int &opc); // Pre-implementado al pie
void RegistrarAerogenerador(double arr[], int &tam, int capacidad);
void ListarAerogeneradores(const double arr[], int tam, double umbralOptimo);
int  BuscarPotencia(const double arr[], int tam, double valorBuscado);
void DarDeBajaAerogenerador(double arr[], int &tam);
void CalcularEstadisticas(const double arr[], int tam);

int main() {
    double potencias[CAPACIDAD];
    int tam = 0;
    int opc = -1;

    cout << fixed << setprecision(2);

    do {
        MostrarMenu(opc);

        switch (opc) {
            case 1:
                RegistrarAerogenerador(potencias, tam, CAPACIDAD);
                break;
            case 2:
                ListarAerogeneradores(potencias, tam, UMBRAL_RENDIMIENTO_OPTIMO);
                break;
            case 3:
                if (tam == 0) {
                    cout << "\nNo hay aerogeneradores registrados en el sistema.\n";
                } else {
                    double buscado;
                    cout << "\nIngrese potencia a buscar (kW): ";
                    cin >> buscado;
                    int pos = BuscarPotencia(potencias, tam, buscado);
                    if (pos != -1) {
                        cout << "Potencia encontrada en la posicion [" << pos << "].\n";
                    } else {
                        cout << "Potencia no encontrada en el arreglo.\n";
                    }
                }
                break;
            case 4:
                DarDeBajaAerogenerador(potencias, tam);
                break;
            case 5:
                CalcularEstadisticas(potencias, tam);
                break;
            case 0:
                cout << "\nFinalizando sistema de monitoreo Rawson...\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
                break;
        }
    } while (opc != 0);

    return 0;
}

// =========================================================================
// ESPACIO PARA DESARROLLO DE FUNCIONES POR PARTE DEL ESTUDIANTE
// (Implemente aqui las 5 funciones solicitadas en la consigna)
// =========================================================================

void RegistrarAerogenerador(double arr[], int &tam, int capacidad) { // 1. Opción 1: Registro Controlado de Aerogenerador.

    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        if (tam >= capacidad) {
            cout << "Error: Ya se alcanzo la capacidad Maxima alcanzada (" << capacidad << " aerogeneradores). No se pueden cargar mas registros." << endl;
            return;
        }

        double valor;
        cout << "[Opc 1] Carga: ";
        cin >> valor;

        while (valor < 50.0 || valor > 600.0) {
            cout << "Valor fuera de rango... Ingrese entre " << MIN_POTENCIA << " y " << MAX_POTENCIA << " kW: ";
            cin >> valor;
        }

        arr[tam] = valor;
        cout << "-> Registro agregado en la posicion [" << tam << "]. Total activos: " << tam + 1 << "/15" << endl;
        tam++;

        if (tam < capacidad) {
            cout << "Desea continuar? (s/n) > ";
            cin >> continuar;
        } else {
            cout << "Error: Capacidad maxima alcanzada (" << capacidad << " aerogeneradores). No se pueden cargar mas registros." << endl;
            break;
        }
    }
}

void ListarAerogeneradores(const double arr[], int tam, double umbralOptimo) { // 2. Opción 2: Listado con Filtro Estricto por Umbral.

    if (tam == 0) {
        cout << "No hay aerogeneradores registrados en el sistema." << endl;
        return;
    }
    int contUmbralOptimo = 0;

    cout << "--- LISTADO DE AEROGENERADORES (" << tam << "/" << CAPACIDAD << ") ---" << endl;

    for (int i = 0; i < tam; i++) {
        if (arr[i] > umbralOptimo) {
            contUmbralOptimo++;
            cout << "[" << i << "] -> " << arr[i] << "kW" << " [RENDIMIENTO OPTIMO]" << endl;
        } else {
            cout << "[" << i << "] -> " << arr[i] << "kW" << endl;
        }

    }
    cout << "Aerogeneradores en Rendimiento Optimo (> " << umbralOptimo << " kW): " << contUmbralOptimo << endl;
}

int BuscarPotencia(const double arr[], int tam, double valorBuscado) { // 3. Opción 3: Búsqueda Secuencial en Arreglo.

    for (int i = 0; i < tam; i++) {
        if (arr[i] == valorBuscado) {
            return i;
        }
    }
    return -1;
}

void DarDeBajaAerogenerador(double arr[], int &tam) { // Opción 4: Baja Física con Compactación Shift-Left.

    if (tam == 0) {
        cout << "[Aviso] No hay ningún Aerogenerador en esa posición para eliminar." << endl;
        return;
    }

    double eliminar;
    cout << "[Opc 4] Baja: ";
    cin >> eliminar;

    int pos = BuscarPotencia(arr, tam, eliminar);

    if (pos == -1) {

        cout << "[Error] Valor no encontrado. No se realizó ninguna eliminación." << endl;
        return;
    }

    for (int i = pos; i < tam; i++) {
        arr[i] = arr[i + 1];
    }

    tam--;

    cout << "Aerogenerador eliminado (compactación Shift-Left). Total activos: " << tam << "/" << CAPACIDAD << endl;
}
void CalcularEstadisticas(const double arr[], int tam) { // 5. Opción 5: Estadísticas Seguras (Promedio y Mínimo).

    if (tam == 0) {
        cout << "No hay registros para calcular estadisticas." << endl;
        return;
    }

    double suma = 0.0;
    double minVal = arr[0];
    int posMax = 0;

    for (int i = 0; i < tam; i++) {
        suma += arr[i];

        if (arr[i] < minVal) {
            minVal = arr[i];
            posMax = i;
        }
    }

    double promedio = suma / tam;

    cout << "--- ESTADISTICAS RAWSON ---" << endl;
    cout << "Potencia promedio generada: " << promedio << " kW" << endl;
    cout << "Potencia minima: " << minVal << " Kw (Aerogenerador en posicion [" << posMax << "])" << endl;

}

// =========================================================================
// MODULO DE PRESENTACION PRE-IMPLEMENTADO
// =========================================================================

void MostrarMenu(int &opc) {
    cout << "\n=== PARQUE EOLICO RAWSON - GESTION DE AEROGENERADORES ===\n";
    cout << "1. Registrar potencia media diaria (kW)\n";
    cout << "2. Listar aerogeneradores y verificar Rendimiento Optimo\n";
    cout << "3. Buscar potencia registrada\n";
    cout << "4. Dar de baja aerogenerador (Compactacion Shift-Left)\n";
    cout << "5. Calcular estadisticas (Promedio y Minimo)\n";
    cout << "0. Salir\n";
    cout << "Ingrese una opcion: ";
    cin >> opc;
}