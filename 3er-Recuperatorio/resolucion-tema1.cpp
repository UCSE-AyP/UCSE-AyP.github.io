/*
 * Cátedra: Algoritmos y Programación (Ingeniería en Informática - UCSE)
 * Evaluación: 3er Examen Recuperatorio (Módulo 3: Arreglos Unidimensionales)
 * Tema 1: Parque Solar Cauchari (Jujuy) - Monitoreo de Inversores Fotovoltaicos
 * Modalidad: Plantilla Modular Provista (main() y MostrarMenu pre-implementados; 5 funciones del estudiante)
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Constantes del dominio (Tema 1: Parque Solar Cauchari)
const int CAPACIDAD = 15;
const float MIN_ENERGIA = 15.0f;
const float MAX_ENERGIA = 250.0f;
const float UMBRAL_ALTA_IRRADIACION = 140.0f;

// Prototipos obligatorios (5 funciones a implementar por el estudiante)
void MostrarMenu(int &opc); // Pre-implementado al pie
void RegistrarInversor(float arr[], int &tam, int capacidad);
void ListarInversores(const float arr[], int tam, float umbralAltaIrradiacion);
int  BuscarMedicion(const float arr[], int tam, float valorBuscado);
void DarDeBajaInversor(float arr[], int &tam);
void CalcularEstadisticas(const float arr[], int tam);

int main() {
    float mediciones[CAPACIDAD];
    int tam = 0;
    int opc = -1;

    cout << fixed << setprecision(2);

    do {
        MostrarMenu(opc);

        switch (opc) {
            case 1:
                RegistrarInversor(mediciones, tam, CAPACIDAD);
                break;

            case 2:
                ListarInversores(mediciones, tam, UMBRAL_ALTA_IRRADIACION);
                break;

            case 3:
                if (tam == 0) {
                    cout << "\nNo hay inversores registrados en el sistema.\n";
                } else {
                    float buscado;
                    cout << "\nIngrese medicion a buscar (kWh): ";
                    cin >> buscado;

                    int pos = BuscarMedicion(mediciones, tam, buscado);
                    if (pos != -1) {
                        cout << "Medicion encontrada en la posicion [" << pos << "].\n";
                    } else {
                        cout << "Medicion no encontrada en el arreglo.\n";
                    }
                }
                break;

            case 4:
                DarDeBajaInversor(mediciones, tam);
                break;

            case 5:
                CalcularEstadisticas(mediciones, tam);
                break;

            case 0:
                cout << "\nFinalizando sistema de monitoreo Cauchari...\n";
                break;

            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
                break;
        }
    } while (opc != 0);

    return 0;
}

void MostrarMenu(int &opc) {
    cout << "\n=== PARQUE SOLAR CAUCHARI - GESTION DE INVERSORES ===\n";
    cout << "1. Registrar medicion diaria de inversor (kWh)\n";
    cout << "2. Listar inversores y verificar Alta Irradiacion\n";
    cout << "3. Buscar medicion registrada\n";
    cout << "4. Dar de baja inversor (Compactacion Shift-Left)\n";
    cout << "5. Calcular estadisticas (Promedio y Maximo)\n";
    cout << "0. Salir\n";
    cout << "Ingrese una opcion: ";
    cin >> opc;
}

void RegistrarInversor(float arr[], int &tam, int capacidad) {
    if (tam >= capacidad) {
        cout << "\nError: Capacidad maxima alcanzada (" << capacidad
             << " inversores). No se pueden cargar mas registros.\n";
        return;
    }

    float energia;
    cout << "\nIngrese energia diaria generada (15.0 a 250.0 kWh): ";
    cin >> energia;

    while (energia < MIN_ENERGIA || energia > MAX_ENERGIA) {
        cout << "Valor fuera de rango. Ingrese entre 15.0 y 250.0 kWh: ";
        cin >> energia;
    }

    arr[tam] = energia;
    cout << "Registro agregado en la posicion [" << tam << "]. Total activos: "
         << (tam + 1) << "/" << capacidad << "\n";
    tam++;
}

void ListarInversores(const float arr[], int tam, float umbralAltaIrradiacion) {
    if (tam == 0) {
        cout << "\nNo hay inversores registrados en el sistema.\n";
        return;
    }

    int cantAltaIrradiacion = 0;
    cout << "\n--- LISTADO DE INVERSORES (" << tam << "/" << CAPACIDAD << ") ---\n";

    for (int i = 0; i < tam; i++) {
        cout << "[" << i << "] -> " << arr[i] << " kWh";
        if (arr[i] > umbralAltaIrradiacion) {
            cout << " [ALTA IRRADIACION]";
            cantAltaIrradiacion++;
        }
        cout << "\n";
    }

    cout << "Inversores con Alta Irradiacion (> " << umbralAltaIrradiacion
         << " kWh): " << cantAltaIrradiacion << "\n";
}

int BuscarMedicion(const float arr[], int tam, float valorBuscado) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == valorBuscado) {
            return i;
        }
    }
    return -1;
}

void DarDeBajaInversor(float arr[], int &tam) {
    if (tam == 0) {
        cout << "\nNo hay inversores registrados en el sistema.\n";
        return;
    }

    float valorEliminar;
    cout << "\nIngrese medicion del inversor a dar de baja (kWh): ";
    cin >> valorEliminar;

    int pos = BuscarMedicion(arr, tam, valorEliminar);
    if (pos == -1) {
        cout << "Medicion no encontrada. No se realizaron bajas.\n";
        return;
    }

    // Compactación física Shift-Left para mantener contiguos los datos activos
    for (int i = pos; i < tam - 1; i++) {
        arr[i] = arr[i + 1];
    }
    tam--;

    cout << "Inversor eliminado (compactacion Shift-Left). Total activos: "
         << tam << "/" << CAPACIDAD << "\n";
}

void CalcularEstadisticas(const float arr[], int tam) {
    if (tam == 0) {
        cout << "\nNo hay registros para calcular estadisticas.\n";
        return;
    }

    float suma = 0.0f;
    float maxEnergia = arr[0];
    int posMax = 0;

    for (int i = 0; i < tam; i++) {
        suma += arr[i];
        if (arr[i] > maxEnergia) {
            maxEnergia = arr[i];
            posMax = i;
        }
    }

    float promedio = suma / tam;

    cout << "\n--- ESTADISTICAS CAUCHARI ---\n";
    cout << "Energia promedio generada: " << promedio << " kWh\n";
    cout << "Generacion maxima: " << maxEnergia
         << " kWh (Inversor en posicion [" << posMax << "])\n";
}
