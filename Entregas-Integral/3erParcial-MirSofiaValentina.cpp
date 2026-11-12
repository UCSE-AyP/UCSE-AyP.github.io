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
			char continuar; 
			do{
				RegistrarInversor(mediciones, tam, CAPACIDAD);
				cout<<"desea continuar agregando valores?"<<endl;
				cin>>continuar; 
			}while(continuar=='s'||continuar=='S'); 
			
			break;
		case 2:
			ListarInversores(mediciones, tam, UMBRAL_ALTA_IRRADIACION);
			break;
		case 3:
			if (tam == 0) {
				cout << "\nNo hay inversores registrados en el sistema.\n"<<endl; 
			} else {
				float buscado;
				cout << "\nIngrese medicion a buscar (kWh): "<<endl; 
				cin >> buscado;
				int pos = BuscarMedicion(mediciones, tam, buscado);
				if (pos != -1) {
					cout << "Medicion encontrada en la posicion [" << pos << "].\n"<<endl; 
				} else {
					cout << "Medicion no encontrada en el arreglo.\n"<<endl; 
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
			cout << "\nFinalizando sistema de monitoreo Cauchari...\n"<<endl; 
			break;
		default:
			cout << "\nOpcion invalida. Intente nuevamente.\n"<<endl; 
			break;
		}
	} while (opc != 0);
	
	return 0;
}

// =========================================================================
// ESPACIO PARA DESARROLLO DE FUNCIONES POR PARTE DEL ESTUDIANTE
// (Implemente aqui las 5 funciones solicitadas en la consigna)
// =========================================================================

void RegistrarInversor(float arr[], int &tam, int capacidad){
	/*if(tam>=capacidad){
		cout<<"la capacidad esta siendo superada"<<endl; 
	}
	else{
		cout<<"ingrese una medicion entre[15.0 y 250.0]"<<endl;
		cin>>tam; 
		while(tam<15.0||medicion>250.0){
			cout<<"medicion no valida"<<endl;
			cout<<"ingrese una medicion entre[15.0 y 250.0]"<<endl; 
			cin>>tam; 
			
		} 
		arr[tam];  
	}*/
	
	if(tam>=capacidad){
		cout<<"la capacidad a sido superada"<<endl; 
	}
	float valor; 
	cout<<"ingrese una valor"<<endl; 
	cin>>valor; 
	while(valor<15.0||valor>250.0){
		cout<<"valor fuera de rango"<<endl; 
		cout<<"ingrese otro valor"<<endl; 
		cin>>valor; 
	}
	arr[tam]=arr[tam]+valor; 
	
	
}
	
void ListarInversores(const float arr[], int tam, float umbralAltaIrradiacion){}

int BuscarMedicion(const float arr[], int tam, float valorBuscado){
	for(int i=0; i<tam-1; i++){
		if(arr[i]==valorBuscado){
			return i;  
		}
	}
	return -1; 
}

void DarDeBajaInversor(float arr[], int &tam){
	int valorBorrar; 
	cout<<"ingrese el valor que quiera borrar"<<endl;
	cin>>valorBorrar; 
	for(int i=0; i<tam-1; i++){
		if(arr[i]==valorBorrar){
			tam--; 
		}
	}
}

void CalcularEstadisticas(const float arr[], int tam){
	
	if (tam==0){
		cout<<"error"<<endl; 
	}
	else{
		float acumulador;
		for(int i=0; i<tam; i++){
			acumulador=acumulador+arr[i];
		}
		cout<<"energia promedio generada: "<<acumulador/tam<<endl; 
	}
	 
}
// =========================================================================
// MODULO DE PRESENTACION PRE-IMPLEMENTADO
// =========================================================================

void MostrarMenu(int &opc) {
	cout << "\n=== PARQUE SOLAR CAUCHARI - GESTION DE INVERSORES ===\n"<<endl; 
	cout << "1. Registrar medicion diaria de inversor (kWh)\n"<<endl; 
	cout << "2. Listar inversores y verificar Alta Irradiacion\n"<<endl; 
	cout << "3. Buscar medicion registrada\n"<<endl; 
	cout << "4. Dar de baja inversor (Compactacion Shift-Left)\n"<<endl; 
	cout << "5. Calcular estadisticas (Promedio y Maximo)\n"<<endl; 
	cout << "0. Salir\n"<<endl; 
	cout << "Ingrese una opcion: "<<endl; 
	cin >> opc;
}
