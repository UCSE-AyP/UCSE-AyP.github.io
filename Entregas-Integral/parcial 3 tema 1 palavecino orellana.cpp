#include <iostream>
#include <iomanip>

using namespace std;


const int CAPACIDAD = 15;
const float MIN_ENERGIA = 15.0f;
const float MAX_ENERGIA = 250.0f;
const float UMBRAL_ALTA_IRRADIACION = 140.0f;


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



void RegistrarInversor(float arr[], int &tam, int capacidad){
		if (tam>capacidad){
			cout<<"arreglo esta lleno"<<endl;
		return;}
			
			float lectura;
			cout<<"ingrese medicioones de lectura: ";
			cin>>lectura;
			
			while(lectura<MIN_ENERGIA ||lectura>MAX_ENERGIA){
				cout<<"valor incorrecto pruebe otra vez debe estar entre "<<MIN_ENERGIA<<" y "<<MAX_ENERGIA<<endl;
				cout<<"ingrese la medicion: ";
				cin>>lectura;
			}
			arr[tam]=lectura;
			tam++;
		cout<<"registrado con exito";
}
		
void ListarInversores(const float arr[], int tam, float umbralAltaIrradiacion){
	double contadorAlta;
	if (tam==0){
		cout<<"no hay inversor"<<endl;
	}
	else{
		cout<<"------ LISTA INVERSORES ---------"<<endl;
		int contadorALta=0;
		
		for(int i=0;i<tam;i++){
			cout<<"posicion [ "<<i<<" ]"<<arr[i]<<endl;
			if (arr[i]>umbralAltaIrradiacion){
				cout<<"alta radiacion"<<endl;
				contadorAlta++;
			}
		cout<<"total con radiacion alta: "<<contadorALta;
			
		}
	}
}
		
int  BuscarMedicion(const float arr[], int tam, float valorBuscado){
	
	for (int i=0;i<tam;i++){
		if (arr[i]== valorBuscado){
			return i;}
	}
return -1;	}

void DarDeBajaInversor(float arr[], int &tam){
	int pos, i;
	if (tam==0){
		cout<<"no hay inversor"<<endl;
	}
	else{
		double buscar;
		cout<<"ingrse buscar medicion: ";
		cin>>buscar;
	}
	if (pos==-1){
		cout<<"medicion no encontrada";
	return;}
	for (int pos=0 ; i<tam-1-i; i++){
		arr[i]=arr[i+1];
		tam--;
	}
	cout<<"medicion dada de baja "<<endl;
}
		
void CalcularEstadisticas(const float arr[], int tam){
	int i;
	if (tam==0){
		cout<<"no hay inversor"<<endl;
	}
	float suma=0, maximo=arr[0];
	int posmax=0;
	for(int i;i<tam;i++){
		suma+=arr[i];
		
	}
	if (arr[i]==maximo){
		posmax=arr[i];
	}
	float promedio=suma/tam;
	cout<<"---- ESTADISTICAS GENERALES-----";
	cout<<"energia promedio: "<<promedio<<"kwh"<<endl;
	cout<<"generacio maxima: "<<maximo<<"kwh en posicion"<<posmax<<endl;
}
		
		
		
		
		
		
		
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
