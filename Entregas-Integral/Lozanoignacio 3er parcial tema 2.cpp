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

void RegistrarAerogenerador(float arr[], int &tam, int capacidad){
	float
	int capacidad
	if (tam >= capacidad){
		
		cout << "el arreglo esta lleno. no se puede registrar" 
		return;
	float potecia;
	cout <<"ingrese potencia kw";
	cin >> potencia;
	while (potencia < MIN_POTENCIA || potencia > MAX_POTENCIA)
	cout "valor invalido. debe estar entre (50.0kw y 600.0kw)";	
	cout "ingrese nuevamente";
	cin >> potencia;
		arr[tam] potencia
		tam ++;
	cout"potencia registrada correctemente" << tam;
	cout "total de aerogeneradores" << tam;
	}
};

void ListarAerogeneradores(const float arr[], int tam, float umbralOptimo){
	if tam = 0
		cout << " no hay aerogeneradores registrados en el sistema";
	return;
	int contadorOptimo 
		cout "listado de aerogeneradores";
	for (int i=0; i - tam; i ++){
		cout << "posicion " << i << "." << arr <<;
		if (arr [i]>umbralOptimo);{
			cout << "rendimiento optimo";
			contadorOptimo++;
			cout << "total de rendimiento optimo" << contadorOptimo;
		};
	}
};

int  BuscarPotencia(const float arr[], int tam, float valorBuscado){
	for (int i = 0; i < tam; i++); {
		if (arr[i] == valorBuscado); {
			return i;
		}
	} return -1;
}
void DarDeBajaAerogenerador(float arr[], int &tam){
	if (tam == 0){
		cout <<" no hay generadores para dar de baja";
		return;
	float potenciaAbuscar;
	cout <<"ingrese la potencia a dar de baja"
	cin >> potencia;{
	int posicion = BuscarPotencia (arr,tam,potenciaAbuscar);
	int posicion - 1;{
		cout "potencia no encontrada en el sistema";
		return;
	for(int i = posicion, i; tam - 1; i++;
	tam--;
	cout << "aerogenerador dado de baja correctamente";
	cout << "aerogenerador restante" << tam;
	};
};

void CalcularEstadisticas(const float arr[], int tam){
	if (tam = 0){
		cout "no hay generadores para calcular estadisticas";
		return;
	float suma= 0;
	float min = arr [0];
	int posminimo = 0;
	
	for (int i = 0, i << tam; i++){
		suma += arr[i];
		if arr[i] < minimo {
		minimo = arr[i];
		posminimo =i;
		};
		float promedio suma/tam-m
			
			cout <<  "estadisticas
			cout
			cout
	}
};
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
