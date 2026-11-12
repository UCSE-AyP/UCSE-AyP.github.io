/*
 * Cátedra: Algoritmos y Programación (Ingeniería en Informática - UCSE)
 * Evaluación: 3er Examen Recuperatorio (Módulo 3: Arreglos Unidimensionales)
 * Tema 2: Parque Eólico Rawson (Chubut) - Monitoreo de Aerogeneradores
 * Modalidad: Plantilla Modular Provista (main() y MostrarMenu pre-implementados; 5 funciones del estudiante)
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Constantes del dominio (Tema 2: Parque Eólico Rawson)
const int CAPACIDAD = 15;
const float MIN_POTENCIA = 50.0f;
const float MAX_POTENCIA = 600.0f;
const float UMBRAL_RENDIMIENTO_OPTIMO = 350.0f;

// Prototipos obligatorios (5 funciones a implementar por el estudiante)
void MostrarMenu(int &opc); // Pre-implementado al pie
void RegistrarAerogenerador(float arr[], int &tam, int capacidad);
void ListarAerogeneradores(const float arr[], int tam, float umbralOptimo);
int  BuscarPotencia(const float arr[], int tam, float valorBuscado);
void DarDeBajaAerogenerador(float arr[], int &tam);
void CalcularEstadisticas(const float arr[], int tam);

int main() {
    float potencias[CAPACIDAD];
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
                    float buscado;
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

void RegistrarAerogenerador(float arr[], int &tam, int capacidad) {
    if (tam >= capacidad) {
        cout << "\nError: Capacidad maxima alcanzada (" << capacidad
             << " aerogeneradores). No se pueden cargar mas registros.\n";
        return;
    }

    float potencia;
    cout << "\nIngrese potencia media diaria (50.0 a 600.0 kW): ";
    cin >> potencia;

    while (potencia < MIN_POTENCIA || potencia > MAX_POTENCIA) {
        cout << "Valor fuera de rango. Ingrese entre 50.0 y 600.0 kW: ";
        cin >> potencia;
    }

    arr[tam] = potencia;
    cout << "Registro agregado en la posicion [" << tam << "]. Total activos: "
         << (tam + 1) << "/" << capacidad << "\n";
    tam++;
}

void ListarAerogeneradores(const float arr[], int tam, float umbralOptimo) {
    if (tam == 0) {
        cout << "\nNo hay aerogeneradores registrados en el sistema.\n";
        return;
    }

    int cantOptimos = 0;
    cout << "\n--- LISTADO DE AEROGENERADORES (" << tam << "/" << CAPACIDAD << ") ---\n";

    for (int i = 0; i < tam; i++) {
        cout << "[" << i << "] -> " << arr[i] << " kW";
        if (arr[i] > umbralOptimo) {
            cout << " [RENDIMIENTO OPTIMO]";
            cantOptimos++;
        }
        cout << "\n";
    }

    cout << "Aerogeneradores en Rendimiento Optimo (> " << umbralOptimo
         << " kW): " << cantOptimos << "\n";
}

int BuscarPotencia(const float arr[], int tam, float valorBuscado) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == valorBuscado) {
            return i;
        }
    }
    return -1;
}

void DarDeBajaAerogenerador(float arr[], int &tam) {
    if (tam == 0) {
        cout << "\nNo hay aerogeneradores registrados en el sistema.\n";
        return;
    }

    float valorEliminar;
    cout << "\nIngrese potencia del aerogenerador a dar de baja (kW): ";
    cin >> valorEliminar;

    int pos = BuscarPotencia(arr, tam, valorEliminar);
    if (pos == -1) {
        cout << "Potencia no encontrada. No se realizaron bajas.\n";
        return;
    }

    // Compactación física Shift-Left para mantener contiguos los datos activos
    for (int i = pos; i < tam - 1; i++) {
        arr[i] = arr[i + 1];
    }
    tam--;

    cout << "Aerogenerador eliminado (compactacion Shift-Left). Total activos: "
         << tam << "/" << CAPACIDAD << "\n";
}

void CalcularEstadisticas(const float arr[], int tam) {
    if (tam == 0) {
        cout << "\nNo hay registros para calcular estadisticas.\n";
        return;
    }

    float suma = 0.0f;
    float minPotencia = arr[0];
    int posMin = 0;

    for (int i = 0; i < tam; i++) {
        suma += arr[i];
        if (arr[i] < minPotencia) {
            minPotencia = arr[i];
            posMin = i;
        }
    }

    float promedio = suma / tam;

    cout << "\n--- ESTADISTICAS RAWSON ---\n";
    cout << "Potencia promedio generada: " << promedio << " kW\n";
    cout << "Potencia minima: " << minPotencia
         << " kW (Aerogenerador en posicion [" << posMin << "])\n";
}
