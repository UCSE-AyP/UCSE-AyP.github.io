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
	double importeTotal;
	bool confirmada;
	// TODO: Declarar los campos requeridos respetando tipos, nombres y el MISMO ORDEN EXACTO de la tabla del enunciado para compatibilidad con la inicializacion
};

// =========================================================================
// PROTOTIPOS DEL ESTUDIANTE: 4 funciones nucleares de Modulo 4
// =========================================================================
void calcularDatos(ReservaHotel& reservahotel);
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
		case 1: {
			mostrarTabla(reservas, tam);
			break;
		}
		case 2: {
			cout << ">>> CONSULTA DE RESERVA POR NUMERO DE HABITACION <<<" << endl;
			int nroABuscar;
			cout << "Ingrese Numero de Habitacion a buscar: ";
			cin >> nroABuscar;
			int pos = buscarPorHabitacion(reservas, tam, nroABuscar);
			if (pos!= -1) {
				mostrarFicha(reservas[pos]);
				cout << "Reserva encontrada";
			}
			else {
				cout << "Reserva no existente";
			}
			break;
		}
		
		case 3: {
			cout << ">>> REGISTRO / INSERCION DE NUEVA RESERVA <<<" << endl;
			ReservaHotel nuevo;
			int pos;
			cout << "Ingrese posicion donde desea insertar [0 .. 4]: ";
			cin >> pos;
			cout << "Ingrese Numero de Habitacion (entero unico): ";
			cin >> nuevo.nroHabitacion;
			cout << "Ingrese Cantidad de noches (> 0): ";
			cin >> nuevo.noches;
			cout << "Ingrese Tipo de Habitacion ('S' Simple, 'D' Doble, 'T' Triple): ";
			cin >> nuevo.tipo;
			cout << "Ingrese Tarifa Base por Noche (> 0): ";
			cin >> nuevo.precioNoche;
			cout << "Estado de la reserva (1: Confirmada, 0: Pendiente): " ;
			cin >> nuevo.confirmada;
			if (insertarReserva(reservas,tam, CAPACIDAD,pos,nuevo)) {
				cout <<"[OK] Reserva registrada exitosamente";
			}
			else {
				cout << "No se pudo registrar la reserva";
			}
			break;
		}
		case 4: {
			ReservaHotel actualizada;
			cout << ">>> MODIFICACION DE RESERVA (UPDATE / PK INMUTABLE) <<<" << endl;
			cout << "Ingrese Numero de Habitacion de la reserva a modificar: ";
			cin >> actualizada.nroHabitacion;
			cout << "Nuevas Noches de estadia (> 0): ";
			cin >> actualizada.noches;
			cout << "Nuevo Tipo de Habitacion ('S', 'D', 'T'): ";
			cin >> actualizada.tipo;
			cout << "Nueva Tarifa por Noche (> 0): ";
			cin >> actualizada.precioNoche;
			cout << "Nuevo Estado (1: Confirmada, 0: Pendiente): ";
			cin >> actualizada.confirmada;
			if (modificarReserva(reservas, tam, actualizada)) {
				cout << "[OK] Reserva modificada exitosamente.";
			}
			else {
				cout << "No se pudo modificar la reserva";
			}
			break;
		}
		case 5: {
			cout << ">>> CANCELACION / BAJA FISICA DE RESERVA (DELETE / COMPACTACION) <<<" << endl;
			int nroACancelar;
			cout << "Ingrese Numero de Habitacion a cancelar: ";
			cin >> nroACancelar;
			if (darDeBajaReserva(reservas,tam,nroACancelar)) {
				cout << "[OK] Registro eliminado y arreglo compactado correctamente.";
			}
			else {
				cout << "No se pudo eliminar el registro.";
			}
			break;
		}
		case 6: {
			cout << ">>> ORDENAMIENTO BURBUJA (DESCENDENTE POR IMPORTE TOTAL) <<<" << endl;
			ordenarPorImporteBurbujaDesc(reservas,tam);
			cout << "[OK] Reservas ordenadas de mayor a menor segun importe total con exito.";
			mostrarTabla(reservas,tam);
			break;
		}
		case 7: {
			cout << ">>> REPORTE ESTADISTICO: CALCULAR PROMEDIO DE FACTURACION POR RESERVA <<<" << endl;
			double promedio = calcularPromedioFacturacion(reservas,tam);
			cout << "[RESULTADO] Promedio calculado: " << fixed << setprecision(2) << promedio;
			break;
		}
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
void calcularDatos(ReservaHotel& reservahotel) {
	double recargo;
	if (reservahotel.tipo == 'S') {
		recargo = 0.0;
	}
	else if (reservahotel.tipo == 'D') {
		recargo = 0.10;
	}
	else {
		reservahotel.tipo == 'T';
		recargo = 0.20;
	}
	reservahotel.importeTotal = reservahotel.noches * reservahotel.precioNoche * (1.0 + recargo);
}
bool insertarReserva(ReservaHotel arr[], int &tam, int capacidad, int pos, const ReservaHotel &nueva) {
	int existe = buscarPorHabitacion(arr,tam,nueva.nroHabitacion);
	if (tam >= capacidad || pos < 0 || pos > tam || existe != -1 || nueva.nroHabitacion <= 0 || nueva.noches <= 0 || nueva.tipo != 'S' && nueva.tipo != 'D'
		&& nueva.tipo != 'T' || nueva.precioNoche <= 0) {
		return false;
	}
	ReservaHotel reservaHotel = nueva;
	calcularDatos(reservaHotel);
	for (int i = tam; i > pos; i--) {
		arr[i] = arr[i - 1];
	}
	arr[pos] = reservaHotel;
	tam++;
	return true;
}
bool modificarReserva(ReservaHotel arr[], int tam, const ReservaHotel &actualizada) {
	if (actualizada.noches <= 0 || actualizada.tipo != 'S' && actualizada.tipo != 'D' && actualizada.tipo != 'T' || actualizada.precioNoche <= 0) {
		return false;
	}
	int pos = buscarPorHabitacion(arr,tam,actualizada.nroHabitacion);
	if (pos!=-1) {
		arr[pos].noches = actualizada.noches;
		arr[pos].precioNoche = actualizada.precioNoche;
		arr[pos].nroHabitacion= actualizada.nroHabitacion;
		arr[pos].confirmada = actualizada.confirmada;
		calcularDatos(arr[pos]);
		return true;
	}
	return false;
}
void ordenarPorImporteBurbujaDesc(ReservaHotel arr[], int tam) {
	int i = 0;
	bool huboIntercambio = true;
	while (i < tam - 1 && huboIntercambio ) {
		huboIntercambio = false;
		for (int j = 0; j < tam - 1 - i; j++) {
			if (arr[j].importeTotal < arr[j + 1].importeTotal) {
				intercambiar(arr[j], arr[j+1]);
				huboIntercambio = true;
			}
		}
		i++;
	}
}

void intercambiar(ReservaHotel &a, ReservaHotel &b) {
	ReservaHotel aux = a;
	a = b;
	b = aux;
}

