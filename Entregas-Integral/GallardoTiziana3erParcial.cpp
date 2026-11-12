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
		if(tam>=capacidad){
			cout<<"ERROR:CAPACIDAD MAXIMA ALCANZADA"<<capacidad<<" Aerogeneradores.No se pueden cargas mas registros"<<endl;
			return;
		}
	float pot;
	cout<<"ingrese potencia(kw):";
	cin >> pot;
	while(pot<MIN_POTENCIA || pot>MAX_POTENCIA){	
		cout<<"Valor fuera de rango.Ingrese entre 50.0 y 600.0 kw: ";
		cin >> pot;
	}
	
	arr[tam]=pot;
	cout<<"REGISTRO agregado en la posicion "<< tam << ".Total activos:"<< tam+1 <<"\n"<<capacidad << endl;
	tam++;
}



void ListarAerogeneradores(const float arr[], int tam, float umbralOptimo){
	if(tam==0){
		cout<<"No hay aerogeneradores registrados en el sistema."<<endl;
		return;	
	}
	int contoptimo=0;
	cout <<"\n Listado de aerogeneradores "<< tam<<"/15" <<endl;
	for(int i=0;i<tam;i++){
		cout<<"["<<i<<"] ->"<<arr[i]<<"kW";
		if(arr[i]>umbralOptimo){
			cout<<"[Rendimiento optimo]:";
			cout<< umbralOptimo++;	
		}
		cout<<"\n";
	}
	cout<<"Aerogeneradores en rendimiento optimo(>350.00kW): "<< umbralOptimo <<endl;
	
}
int  BuscarPotencia(const float arr[], int tam, float valorBuscado){
	for(int i=0;i<tam;i++){
		if(arr[i]==valorBuscado){
			return i;	
		}
	}
	return -1;
}
void DarDeBajaAerogenerador(float arr[], int &tam){
	if(tam==0){
		cout<<"No hay aerogeneradores registrados en el sistema"<<endl;
		return;
	}
	float valor;
	cout<<"Ingrese potencia a dar de baja kW: ";
	cin >> valor;
	int pos = BuscarPotencia(arr,tam,valor);
	if(pos==-1){
		cout<<"Potencia no encontrada en el arreglo"<<endl;
	} else {
		for(int i = pos;i<tam-1;i++){
			arr[i]=arr[i+1];
		}
		tam--;
		cout<<"Aerogenerador Eliminado (compactacion Shift-left).Total activos: "<<tam<<"/15"<<endl;
	}
	
}
void CalcularEstadisticas(const float arr[], int tam){
	if(tam==0){
		cout<<"No hay registros para calcular estadisticas."<<endl;
		return;
	}
	float suma=0.0f;
	float minimo = arr[0];
	int posmin=0;
	for(int i= 0;i<tam;i++){
		suma += arr[i];
		if(arr[i]<minimo){
			minimo=arr[i];
			posmin=i;
		}
	}
	float promedio=suma/tam;
	cout<<"\nESTADISTICAS RAWSON"<<endl;
	cout<<"Potencia promedio generada: "<<promedio<<" kW"<<endl;
	cout<<"Potencia minima: "<< minimo <<" kW (Aerogenerador en posicion ["<<posmin<<"])"<<endl;
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
