#include <iostream>
#include <iomanip>

using namespace std;

// =========================================================================
// CONSTANTES DEL DOMINIO (Tema 1: Parque Solar Cauchari)
// =========================================================================
const int CAPACIDAD = 15;
const double MIN_ENERGIA = 15.0f;
const double MAX_ENERGIA = 250.0f;
const double UMBRAL_ALTA_IRRADIACION = 140.0f;

// =========================================================================
// PROTOTIPOS DE FUNCIONES (5 Funciones a Implementar por el Estudiante)
// =========================================================================


// =========================================================================
// ESPACIO PARA DESARROLLO DE FUNCIONES POR PARTE DEL ESTUDIANTE
// (Implemente aqui las 5 funciones solicitadas en la consigna)
// =========================================================================

// =========================================================================
// MODULO DE PRESENTACION PRE-IMPLEMENTADO
// =========================================================================

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

void ValidacionDouble(double &Valor, double Min, double Max, string Msj) {
    do {
        cout << Msj << endl;
        cin >> Valor;

        if (Valor<Min || Valor>Max) {
            cout << "Error. Intentelo de nuevo." << endl;
        }
    } while (Valor<Min || Valor>Max);
}

void RegistrarInversor(double arr[], int &tam, int capacidad) {

    char respuesta;

    do {
        if (tam==capacidad) {
            cout << "La capacidad esta llena." << endl;
            return;
        }

        ValidacionDouble( arr[tam], 15.0f, 250.0f, "Ingrese:");
        tam++;
        cout << "Desea continuar? (S/N)" << endl;
        cin >> respuesta;
    } while (respuesta!='N');
}

void ListarInversores(const double arr[], int tam) {
    int umbralTime=0;

    for (int i = 0; i < tam; ++i) {
        if (arr[i]>140.0) {
            cout << "|Posicion: " << i+1 << "Valor: " << arr[i] << "|\n";
            umbralTime++;
        }
    }
    cout << "Bloques en Prime Time " << umbralTime << " de " << tam << endl;
}

int BuscarMedicion(const double arr[], int tam, double valorBuscado) {
    if (tam == 0) {
        cout << "\nNo hay inversores registrados en el sistema.\n";
    } else {
        double buscado;
        cout << "\nIngrese medicion a buscar (kWh): ";
        cin >> buscado;
        int pos = BuscarMedicion(arr, tam, valorBuscado);
        if (pos != -1) {
            cout << "Medicion encontrada en la posicion [" << pos << "].\n";
        } else {
            cout << "Medicion no encontrada en el arreglo.\n";
        }
    }
}
void DarDeBajaInversor(double arr[], int &tam) {
    double valorBuscado;
    cout << "Ingrese el valor a dar de baja: " << endl;
    cin >> valorBuscado;
    int Pos=BuscarMedicion(arr, tam, valorBuscado);
    if (Pos==-1) {
        cout << "No se encontro el valor." << endl;
    } else {
        for (int i = Pos; i < tam; ++i) {
            arr[i]=arr[i+1];
        }
        tam--;
    }
}


void CalcularEstadisticas(const double arr[], int tam) {
    for (int i = 0; i < tam; ++i) {
        cout << "|" << arr[i] << "|" << endl;
    }
}


int main() {
    double mediciones[CAPACIDAD] = {150.5, 185.50, 95, 210.50};
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
                ListarInversores(mediciones, tam);
                break;
            case 3:
                if (tam == 0) {
                    cout << "\nNo hay inversores registrados en el sistema.\n";
                } else {
                    double buscado;
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