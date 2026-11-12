#include <iostream>
#include <iomanip>

using namespace std;

// =========================================================================
// DEFINICION DEL REGISTRO (STRUCT)
// TODO: El estudiante debe declarar la estructura segun la especificacion
// detallada en el enunciado (utilizar exclusivamente tipos primitivos)
// =========================================================================
struct ReservaHotel {
	// TODO: Declarar los campos requeridos respetando tipos, nombres y el MISMO ORDEN EXACTO de la tabla del enunciado para compatibilidad con la inicializacion
	int nrohabitacion;
	int noches;
	char tipo;
	double precionoche;
	double importetotal;
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
			mostrarTabla(reserva, tam, CAPACIDAD);
			break;
		case 2:
			int nro
				cout "ingrese numeros de habitacion a consultar"
				cin >> numero
				int pos = buscarPorHabitacion (reserva,tam,nro)
				if ( pos == -1){
					cout"no existe reservaa para esta habitacion";
				} else {
					mostrarFicha(reserva [pos]
				}
			break;
		case 3:
			// TODO: Implementar por el estudiante
			break;
		case 4:
			
	
			
			break;
		case 5:
			int nro
			cout<< "numero de habitacion a dar de baja";
			cin >> nro;
			if (darDeBajaReserva(reserva, tam,nro)) {
				cout << "reserva elimina.quedan)" << tam << "reservas"
			} else {
				cout << " [-] no se encontraron la habitacion"
			}
			break;
		case 6:
			cout << "ordenamientoporburbuja"
				ordenamientoPorImporteburbujadesc (reserva,tam){
				cout"reservas ordenas por importe total de descuento"
				mostrartabla (reserva,tam)	
			}
			break;
		case 7:
			cout << "promedio de facturacion de reserva"
			<< fixed << setprecision(2)
			calcularPromedioFacturacion (reserva,tam) << "\n)"
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
void intercambiar(ReservaHotel &a, ReservaHotel &b) {
	reserva aux = a
	a=b
	b=aux
} return;
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

