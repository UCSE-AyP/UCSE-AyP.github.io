#include <iostream>
#include <iomanip>

using namespace std;

// =========================================================================
// CONSTANTES DEL DOMINIO (Tema 1: Parque Solar Cauchari)
// =========================================================================

const int CAPACIDAD = 15;
const float MIN_ENERGIA = 15.0f;
const float MAX_ENERGIA = 250.0f;
const float UMBRAL_ALTA_IRRADIACION = 140.0f;

// =========================================================================
// PROTOTIPOS DE FUNCIONES (5 Funciones a Implementar por el Estudiante)
// =========================================================================





void MostrarMenu(int &opc); // Pre-implementado al pie
void RegistrarInversor(float arr[], int &tam, int capacidad);
void ListarInversores(const float arr[], int tam, float umbralAltaIrradiacion);
int  BuscarMedicion(const float arr[], int tam, float valorBuscado);
void DarDeBajaInversor(float arr[], int &tam);
//void CalcularEstadisticas(const float arr[], int tam);






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
                //DarDeBajaInversor(mediciones, tam);
                break;
            case 5:
                //CalcularEstadisticas(mediciones, tam);
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





// =========================================================================
// ESPACIO PARA DESARROLLO DE FUNCIONES POR PARTE DEL ESTUDIANTE
// (Implemente aqui las 5 funciones solicitadas en la consigna)
// =========================================================================










void RegistrarInversor(float arr[], int &tam, int capacidad) {
    if (tam < capacidad) {
        float op;
        cout<<" ingrese valor"<<endl;
        cin>>op;
        while (op<MIN_ENERGIA||op>MAX_ENERGIA) {
            cout<<"Valor fuera de rango.Ingrese entre 15.0 y 250 kwh"<<endl;
            cin>>op;
        }
        arr[tam]=op;
        cout<<"Registro agregado en la posicion "<<tam<<endl;
        tam++;
    }
    else {
        cout<<"No hay cupo disponible"<<endl;
    }
}








void ListarInversores(const float arr[], int tam, float umbralAltaIrradiacion) {
    int contador=0;
    cout<<"-------Listados de nombres-------"<<endl;
    if (tam==0) {
        cout<<"No hay registro"<<endl;
    }
    else {

        for (int i=0;i<tam;i++) {
            if (arr[i]>umbralAltaIrradiacion) {
                cout<<"- ["<<i<<"] - "<<arr[i]<<  "- [ALTA IRRADIACION] - "<<endl;
                contador++;
            }
            else {
                if (arr[i]<umbralAltaIrradiacion) {
                    cout<<"- ["<<i<<"] - "<<arr[i]<<endl;

                }
            }
        }
        cout<<"Inversores con ALTA IRRADIACION(>140.00) "<<contador<<endl;

    }
}






int  BuscarMedicion(const float arr[], int tam, float valorBuscado){

    for (int i=0;i<tam;i++) {
        if (arr[i]==valorBuscado) {
            return i;
        }
    }
    return -1;

}








void DarDeBajaInversor(float arr[], int &tam) {

    if (tam==0) {
        cout<<" No hay bajas"<<endl;

    }else {
        float pas;
        cout<<"ingrese valor"<<endl;
        cin>>pas;


    }



}



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