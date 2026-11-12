#include <iostream>
#include <iomanip>

using namespace std;

// =========================================================================
// CONSTANTES DEL DOMINIO (Tema 2: Parque Eólico Rawson)
// =========================================================================
const int CAPACIDAD = 15;
const float MIN_POTENCIA = 50.0f;
const float MAX_POTENCIA = 600.0f;
const float UMBRAL_RENDIMIENTO_OPTIMO = 350.0f;

// =========================================================================
// PROTOTIPOS DE FUNCIONES (5 Funciones a Implementar por el Estudiante)
// =========================================================================
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

void RegistrarAerogenerador(float arr[], int &tam, int capacidad)
{
	
	char continuar = 's';
	
	while(continuar == 's' || continuar == 'S' || tam == capacidad){
		float valor;
		do{
			cout << "Ingrese el valor del aerogenerador entre [50.0 y 600.0]: ";
			 cin >> valor;
			if (valor < 50.0f || valor > 600.0f){
				cout << "[ERROR] el valor añadido no cumple los requisitos" << endl;
			}
		}while(valor < 50.0f || valor > 600.0f);
		arr[tam] = valor;
		tam++;
		
		cout << "Desea ingresar otro dato: (S o N): ";
		cin >> continuar ;
		if (continuar != 's'){
			cout << "[Exito] dato registrado" << endl;
			}
	
}
}

void ListarAerogeneradores(const float arr[], int tam, float umbralOptimo)
{
	if (tam == 0){
		cout << "[ERROR] no se a registrado nada " << endl;
	}
	int destacado = 0;
	for(int i = 0 ; i < tam; i++){
		if (arr[i] > umbralOptimo){
			destacado++;
		}
	}
	cout << "==================================" << endl;
	cout << "La cantidad que superan el [" << umbralOptimo << "] es de [" << destacado << "]" << endl;
}

int  BuscarPotencia(const float arr[], int tam, float valorBuscado){
	for(int i = 0; i < tam; i++){
		if(arr[i] == valorBuscado){
			return i;
		}
	}
	return -1;
}
void DarDeBajaAerogenerador(float arr[], int &tam){
	if (tam == 0){
		cout << "[ERROR] no se a registrado nada " << endl;
		return;
	}
	float valorBuscado;
	cout << "Ingrese el lavor que desea dar de vaja: ";
	cin >> valorBuscado;
	int pos = BuscarPotencia(arr,tam,valorBuscado);
	
	if (pos == -1){
		cout << "[ERROR] valor no encontrado" << endl;
	} else{
		arr[tam - pos]; 
		tam--; 
		cout << "Archivo eleminado [CORRECTAMENTE]" << endl;
	}
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
