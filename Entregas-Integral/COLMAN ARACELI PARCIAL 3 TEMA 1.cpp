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

// =========================================================================
// ESPACIO PARA DESARROLLO DE FUNCIONES POR PARTE DEL ESTUDIANTE
// (Implemente aqui las 5 funciones solicitadas en la consigna)
// =========================================================================
void RegistrarInversor (float arr[],int &tam, int capacidad);
char continuar= 's';
 if tam < capacidad;{
  cout<<"[AVISO] El arreglo a alcanzado su capacidad maxima"
  {"capacidad<< "bloques" << endl;
  }
 return;
}
while (continuar =='s'||continuar=='s' && tam capacidad);
 float valor;
 cout<< "Ingrese los kwh de [rango 15.0, 250.0 ]"<<endl;
  cin>> valor;
     arr[tam]=valor;
tam ++;
cout <<" [EXITO:] Se guardo correctmente los kwh"<< endl;

if ()tam<capacidad){
	cout<<"Desea continuar? (s\n)"<< endl;
	cin>> continuar;
}else {
 cout <<" \n [AVISO:]se alcanzo la capacidad maxima ("capacidad<< bloque")" endl;
}
}

void ListarInversores (const float arr[], int tam, umbralAltaIrradiacion);{
 if (tam=0);
  cout <<"\n Aviso no hay irradiacion registrada"<< endl;;
return;
}
cout <<"\n------Listado de inversores de los bloques---"<< endl;
  int contador Prime++;
for (int =0;i< tam; i++);
cout<<"** Prime time**";
contador prime++;
}
cout <<"-----------------------" << endl;
cout <<" Total de bloques registrados"<< tam<< endl;
cout <<"Bloque que supera prime time";
umbralPrimeTime<< "k:"<<contadorPrime << endl;

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
