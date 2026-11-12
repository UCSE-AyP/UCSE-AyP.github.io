#include <iostream>
#include <iomanip>

using namespace std;

// =========================================================================
// DEFINICION DEL REGISTRO (STRUCT)
// TODO: El estudiante debe declarar la estructura segun la especificacion
// detallada en el enunciado (utilizar exclusivamente tipos primitivos)
// =========================================================================
struct ReservaHotel {
    int nroHabitacion;
    int noches;
    char tipo;
    double precioNoche;
    double precioTotal;
    bool confirmada;
};

// =========================================================================
// PROTOTIPOS DEL ESTUDIANTE: 4 funciones nucleares de Modulo 4
// =========================================================================
void intercambiar(ReservaHotel &a, ReservaHotel &b);
bool insertarReserva(ReservaHotel arr[], int &tam, int capacidad, int pos, const ReservaHotel &nueva);
bool modificarReserva(ReservaHotel arr[], int tam, const ReservaHotel &actualizada);
void ordenarPorImporteBurbujaDesc(ReservaHotel arr[], int tam);

// Modulos de presentacion y primitivas auxiliares pre-implementados en plantilla
int buscarPorHabitacion(const ReservaHotel arr[], int tam, int nroBuscado);
bool darDeBajaReserva(ReservaHotel arr[], int &tam, int nroABorrar);
double calcularPromedioFacturacion(const ReservaHotel arr[], int tam);
void mostrarMenu();
void mostrarFicha(const ReservaHotel &e);
void mostrarTabla(const ReservaHotel arr[], int tam);

int main() {
    const int CAPACIDAD = 15;
    ReservaHotel reservas[CAPACIDAD] = {
        {101, 2, 'S', 38000.0, 76000.0,  true},
        {204, 5, 'D', 52000.0, 286000.0, false},
        {305, 3, 'T', 61000.0, 219600.0, true},
        {408, 1, 'S', 38000.0, 38000.0,  true}
    };
    int tam = 4;

    int opcion = 0;
    do {
        mostrarMenu();
        cout << "  Seleccione una opcion [1-7, 0 para salir]: ";
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cout << "\n----------------------------------------------------------------------\n";
        switch (opcion) {
            case 1:
                mostrarTabla(reservas,tam);
                break;
            case 2:
            	int nroLocalizado;
                cout << "Ingrese el numero de abitacion que decea consultar: ";
                cin >> nroLocalizado;
                
                int pos;
								
								pos = buscarPorHabitacion(reservas,tam,nroLocalizado);
                
                mostrarFicha(reservas[pos]);
                break;
                
            case 3:
            	
            	int insertar;
            	 ReservaHotel archivo;
    
                cout << "Ingrese el numero de habitacion: "; cin >> archivo.nroHabitacion; 
                cout << "Ingrese las noches que pasaran: "; cin >> archivo.noches;
                cout << "Ingrese el tipo: "; cin >> archivo.tipo;
								cout << "Ingrese el precio de noche: "; cin >> archivo.precioNoche;
								cout << "Ingrese el precio total: "; cin >> archivo.precioTotal;
								cout << "Confirmadas (S o N): "; cin >> archivo.confirmada;
							
							cout << "Ingrese la habitacion donde desea insertar: ";
							cin >> insertar;
							 insertarReserva(reservas,tam,capacidad,insertar,archivo);
							 mostrarTabla(reservas,tam);
                break;
            case 4:
            	int modificar;
                cout <<"Ingrese el numero de habitacion que desea modificar: ";
                cin >> modificar;
                
								
								modificarReserva(reservas,tam,modificar);
								
								}
                break;
            case 5:
            	int baja;
                cout <<"Ingrese el numero de habitacion a dar de baja: ";
                cin >> baja;
                
                darDeBajaReserva(reservas,tam,baja);
                break;
            case 6:
                ordenarPorImporteBurbujaDesc(reservas,tam);
                mostarTabla(reservas,tam);
                break;
            case 7:
                double promedio = calcacularPromedioFacturacion(reservas,tam);
                cout << "El promedio de la facturacion seria de: [" << promedio << "]" << endl; 
                break;
            case 0:
                cout << "  [SISTEMA]: Sesion finalizada. Fin del programa.\n";
                break;
            default:
                cout << "  [!] Opcion no valida. Seleccione una opcion valida del menu [0 a 7].\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}

// =========================================================================
// ESPACIO PARA DESARROLLO DE FUNCIONES POR PARTE DEL ESTUDIANTE
// (Implemente aqui: intercambiar, insertarReserva, modificarReserva y
//  ordenarPorImporteBurbujaDesc)
// =========================================================================

// =========================================================================
// PRIMITIVAS AUXILIARES Y MODULOS DE ESCRITURA PRE-IMPLEMENTADOS
// =========================================================================

int buscarPorHabitacion(const ReservaHotel arr[], int tam, int nroBuscado) {
    for (int i = 0; i < tam; ++i) {
        if (arr[i].nroHabitacion == nroBuscado) {
            return i;
        }
    }
    return -1;
}

bool darDeBajaReserva(ReservaHotel arr[], int &tam, int nroABorrar) {
    int pos = buscarPorHabitacion(arr, tam, nroABorrar);
    if (pos == -1) return false;
    for (int k = pos; k < tam - 1; ++k) {
        arr[k] = arr[k + 1];
    }
    tam--;
    return true;
}

double calcularPromedioFacturacion(const ReservaHotel arr[], int tam) {
    if (tam <= 0) return 0.0;
    double suma = 0.0;
    for (int i = 0; i < tam; ++i) {
        suma += arr[i].importeTotal;
    }
    return suma / tam;
}

bool insertarReserva(ReservaHotel arr[], int &tam, int capacidad, int pos, const ReservaHotel &nueva){
	if(tam >= capacidad || pos < 0 || pos > tam){
		cout << "[ERROR] " <<endl;
		reurn false;
	}
	
	if (buscarPorHabitacion(arr,tam,pos) != -1){
		for (int i = tam ; i < pos; i--){
			arr[i] = arr[pos + 1];
			arr[pos] = nueva;
			tam++
			return true;
		}
	}else{
		cout "Habitacion no encontrada" << endl;
		return false;
	}
	
}

bool modificarReserva(ReservaHotel arr[], int tam, const ReservaHotel &actualizada){
	 ReservaHotel nuevo;
	int pos = buscarPorHabitacion(reserva,tam,actualizada);
  
  if(pos == -1){
	cout << "[ERROR] habitacion no registrada"<<endl;
	return false;
	}else{
  cout <<"========= Ingrese los nuevos datos ==========" << endl;
	cout << "Ingrese las noches que pasaran: "; cin >> nuevo.noches;
  cout << "Ingrese el tipo: "; cin >> nuevo.tipo;
	cout << "Ingrese el precio de noche: "; cin >> nuevo.precioNoche;
	cout << "Ingrese el precio total: "; cin >> nuevo.precioTotal;
  cout << "Confirmadas (S o N): "; cin >> nuevo.confirmada;
  
  arr[pos] = nuevo;
  return true;
}

}

bool darDeBajaReserva(ReservaHotel arr[], int &tam, int nroABorrar){
	
	int pos = buscarPorHabitacion(arr,tam,nroABorrar);
	
	if(pos != -1 ){
		arr[pos - 1];
		tam--;
		cout << "[EXITO] Habitacion dada de baja" << endl;
	}else{
		cout << "[ERROR] Habitacion no encontrada" << endl;
	}
}

void intercambiar(ReservaHotel &a, ReservaHotel &b){
	reserva = aux
	a = b
	b = aux
}

void ordenarPorImporteBurbujaDesc(ReservaHotel arr[], int tam){
	bool hubointercambio;
	for(int i = 0; i < tam - 1 ; i++){
		hubiIntercambio = false;
		for (int j = 0; j < tam - 1 - i; j++){
			if (arr[j].precioTotal < arr[j + 1].precioTotal){
				intercambiar(arr[j].precioTotal,arr[j + 1].precioTotal);
				huboIntercambio = true;
			}
		}
	}
}

void mostrarMenu() {
    cout << "\n======================================================================\n";
    cout << "        SISTEMA DE GESTION HOTELERA (ARRAY OF STRUCTS)                \n";
    cout << "======================================================================\n";
    cout << "  1. Listar Libro de Reservas (Formato Tabular)\n";
    cout << "  2. Consultar Reserva por Numero de Habitacion (Read)\n";
    cout << "  3. Registrar Nueva Reserva en Posicion (Create / Right-Shift)\n";
    cout << "  4. Modificar Reserva Existente (Update / PK Inmutable)\n";
    cout << "  5. Cancelar Reserva / Baja Fisica (Delete / Left-Shift)\n";
    cout << "  6. Ordenar por Importe Total (Burbuja Descendente)\n";
    cout << "  7. Calcular Promedio de Facturacion por Reserva (Estadistica / Const)\n";
    cout << "  0. Salir\n";
    cout << "======================================================================\n";
}

void mostrarFicha(const ReservaHotel &e) {
    cout << "  +------------------------------------------------------------------+\n";
    cout << "  | VOUCHER DE RESERVA HOTELERA                                      |\n";
    cout << "  +------------------------------------------------------------------+\n";
    cout << "  | Nro Habitacion:   " << left << setw(47) << e.nroHabitacion << "|\n";
    cout << "  | Noches Estadia:   " << left << setw(47) << e.noches << "|\n";
    cout << "  | Tipo Habitacion:  " << left << setw(47) << (e.tipo == 'S' ? "S (Simple)" : (e.tipo == 'D' ? "D (Doble)" : "T (Triple)")) << "|\n";
    cout << "  | Tarifa por Noche:$" << left << setw(46) << fixed << setprecision(2) << e.precioNoche << "|\n";
    cout << "  | Importe Total:   $" << left << setw(46) << fixed << setprecision(2) << e.importeTotal << "|\n";
    cout << "  | Estado Reserva:   " << left << setw(47) << (e.confirmada ? "Confirmada" : "Pendiente") << "|\n";
    cout << "  +------------------------------------------------------------------+\n" << right;
}

void mostrarTabla(const ReservaHotel arr[], int tam) {
    if (tam == 0) {
        cout << "  [!] El registro de reservas esta vacio (tam = 0).\n";
        return;
    }

    cout << "\n+-----+--------+--------+-----+--------------+---------------+------------+\n";
    cout << "| POS | HABIT. | NOCHES | TIP | TARIFA NOCHE | IMPORTE TOTAL | ESTADO     |\n";
    cout << "+-----+--------+--------+-----+--------------+---------------+------------+\n";

    cout << right;
    for (int i = 0; i < tam; ++i) {
        cout << "| [" << setw(1) << i << "] | "
             << setw(6) << arr[i].nroHabitacion << " | "
             << setw(6) << arr[i].noches << " |  "
             << arr[i].tipo << "  | $"
             << setw(11) << fixed << setprecision(2) << arr[i].precioNoche << " | $"
             << setw(12) << fixed << setprecision(2) << arr[i].importeTotal << " | "
             << left << setw(10) << (arr[i].confirmada ? "Confirmada" : "Pendiente") << right << " |\n";
    }
    cout << "+-----+--------+--------+-----+--------------+---------------+------------+\n";
    cout << "Total reservas activas: " << tam << ".\n";
}

