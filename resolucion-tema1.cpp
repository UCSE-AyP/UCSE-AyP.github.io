#include <iostream>
#include <iomanip>

using namespace std;

struct Paciente {
    // Estructura declarada respetando estrictamente el orden del enunciado para inicializacion por llaves
    int idPaciente;        // Clave Primaria univoca
    int anioNacimiento;    // Anio de nacimiento (<= 2026)
    int edad;              // 2026 - anioNacimiento
    char categoria;        // 'P' Pediatrico (<13), 'A' Adulto (13-59), 'G' Adulto mayor (>=60)
    double valorBase;      // Arancel base de la consulta (> 0)
    double importeConsulta;// valorBase + % segun categoria (P:+5%, A:+10%, G:+15%)
};

// Prototipos de funciones a implementar por el estudiante
void intercambiar(Paciente &a, Paciente &b);
int buscarPorId(const Paciente arr[], int tam, int idBuscado);
bool insertarPaciente(Paciente arr[], int &tam, int capacidad, int pos, const Paciente &nuevo);
bool modificarPaciente(Paciente arr[], int tam, const Paciente &actualizado);
bool darDeBajaPaciente(Paciente arr[], int &tam, int idABorrar);
void ordenarPorValorBaseBurbujaAsc(Paciente arr[], int tam);
double calcularPromedioConsulta(const Paciente arr[], int tam);

// Modulos meramente de escritura pre-implementados
void mostrarMenu();
void mostrarFicha(const Paciente &e);
void mostrarTabla(const Paciente arr[], int tam);

int main() {
    const int CAPACIDAD = 15;
    Paciente padron[CAPACIDAD] = {
        {101, 1981, 45, 'A', 6500.0, 7150.0},
        {108, 1964, 62, 'G', 9200.0, 10580.0},
        {215, 2018, 8,  'P', 4800.0, 5040.0},
        {304, 1972, 54, 'A', 7400.0, 8140.0}
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
                mostrarTabla(padron, tam);
                break;
            case 2: {
                cout << ">>> CONSULTA DE PACIENTE POR ID <<<\n";
                int id;
                cout << "  Ingrese ID a buscar: ";
                cin >> id;
                int pos = buscarPorId(padron, tam, id);
                if (pos != -1) {
                    cout << "  [OK] Paciente localizado en celda [" << pos << "]:\n";
                    mostrarFicha(padron[pos]);
                } else {
                    cout << "  [-] Paciente con ID " << id << " no existe en la guardia.\n";
                }
                break;
            }
            case 3: {
                cout << ">>> REGISTRO / INSERCION DE PACIENTE <<<\n";
                int pos;
                cout << "  Ingrese posicion donde desea insertar [0 .. " << tam << "]: ";
                cin >> pos;
                Paciente nuevo;
                cout << "  Ingrese ID del paciente (entero unico): ";
                cin >> nuevo.idPaciente;
                cout << "  Ingrese Anio de nacimiento [1920..2026]: ";
                cin >> nuevo.anioNacimiento;
                cout << "  Ingrese Valor Base de la Consulta (> 0): $";
                cin >> nuevo.valorBase;

                nuevo.edad = 2026 - nuevo.anioNacimiento;
                if (nuevo.edad < 13) nuevo.categoria = 'P';
                else if (nuevo.edad < 60) nuevo.categoria = 'A';
                else nuevo.categoria = 'G';

                double rec = (nuevo.categoria == 'P' ? 0.05 : (nuevo.categoria == 'A' ? 0.10 : 0.15));
                nuevo.importeConsulta = nuevo.valorBase * (1.0 + rec);

                if (insertarPaciente(padron, tam, CAPACIDAD, pos, nuevo)) {
                    cout << "\n  [OK] Paciente registrado exitosamente en la celda [" << pos << "]. Total: " << tam << "/" << CAPACIDAD << "\n";
                } else {
                    cout << "\n  [!] ERROR: No se pudo registrar. Verifique ID duplicado, cupo agotado o posicion invalida.\n";
                }
                break;
            }
            case 4: {
                cout << ">>> MODIFICACION DE PACIENTE (UPDATE / PK INMUTABLE) <<<\n";
                int id;
                cout << "  Ingrese ID del paciente a modificar: ";
                cin >> id;
                int pos = buscarPorId(padron, tam, id);
                if (pos == -1) {
                    cout << "\n  [-] Paciente no encontrado.\n";
                } else {
                    Paciente modificado;
                    modificado.idPaciente = id; // Clave primaria inmutable
                    cout << "  Modificando paciente con ID: " << id << " (inalterable)\n";
                    cout << "  Nuevo Anio de nacimiento [1920..2026]: ";
                    cin >> modificado.anioNacimiento;
                    cout << "  Nuevo Valor Base de Consulta (> 0): $";
                    cin >> modificado.valorBase;

                    modificado.edad = 2026 - modificado.anioNacimiento;
                    if (modificado.edad < 13) modificado.categoria = 'P';
                    else if (modificado.edad < 60) modificado.categoria = 'A';
                    else modificado.categoria = 'G';

                    double rec = (modificado.categoria == 'P' ? 0.05 : (modificado.categoria == 'A' ? 0.10 : 0.15));
                    modificado.importeConsulta = modificado.valorBase * (1.0 + rec);

                    if (modificarPaciente(padron, tam, modificado)) {
                        cout << "\n  [OK] Datos del paciente modificados exitosamente.\n";
                    } else {
                        cout << "\n  [!] Error al modificar.\n";
                    }
                }
                break;
            }
            case 5: {
                cout << ">>> ALTA MEDICA / BAJA FISICA DE GUARDIA (DELETE / COMPACTACION) <<<\n";
                int id;
                cout << "  Ingrese ID del paciente a dar de baja: ";
                cin >> id;
                if (darDeBajaPaciente(padron, tam, id)) {
                    cout << "\n  [OK] Registro eliminado y arreglo compactado correctamente. Total activos: " << tam << "\n";
                } else {
                    cout << "\n  [-] ID no encontrado. No se realizo ninguna baja.\n";
                }
                break;
            }
            case 6:
                cout << ">>> ORDENAMIENTO BURBUJA (ASCENDENTE POR VALOR BASE DE CONSULTA) <<<\n";
                ordenarPorValorBaseBurbujaAsc(padron, tam);
                cout << "  [OK] Guardia ordenada de menor a mayor segun valor base con exito.\n";
                mostrarTabla(padron, tam);
                break;
            case 7: {
                cout << ">>> REPORTE ESTADISTICO: CALCULAR PROMEDIO DE ARANCELES DE CONSULTA <<<\n";
                double prom = calcularPromedioConsulta(padron, tam);
                cout << "  [RESULTADO] Promedio calculado: $" << fixed << setprecision(2) << prom << "\n";
                break;
            }
            case 0:
                cout << "  [SISTEMA]: Sesion finalizada. Fin del programa.\n";
                break;
            default:
                cout << "  [!] Opcion no valida. Seleccione una opcion valida del menu [0 a 6].\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}

void intercambiar(Paciente &a, Paciente &b) {
    Paciente aux = a;
    a = b;
    b = aux;
}

int buscarPorId(const Paciente arr[], int tam, int idBuscado) {
    for (int i = 0; i < tam; ++i) {
        if (arr[i].idPaciente == idBuscado) {
            return i;
        }
    }
    return -1;
}

bool insertarPaciente(Paciente arr[], int &tam, int capacidad, int pos, const Paciente &nuevo) {
    if (tam >= capacidad || pos < 0 || pos > tam) return false;
    if (buscarPorId(arr, tam, nuevo.idPaciente) != -1) return false;
    for (int i = tam; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = nuevo;
    tam++;
    return true;
}

bool modificarPaciente(Paciente arr[], int tam, const Paciente &actualizado) {
    int pos = buscarPorId(arr, tam, actualizado.idPaciente);
    if (pos == -1) return false;
    arr[pos].anioNacimiento = actualizado.anioNacimiento;
    arr[pos].edad = actualizado.edad;
    arr[pos].categoria = actualizado.categoria;
    arr[pos].valorBase = actualizado.valorBase;
    arr[pos].importeConsulta = actualizado.importeConsulta;
    return true;
}

bool darDeBajaPaciente(Paciente arr[], int &tam, int idABorrar) {
    int pos = buscarPorId(arr, tam, idABorrar);
    if (pos == -1) return false;
    for (int k = pos; k < tam - 1; ++k) {
        arr[k] = arr[k + 1];
    }
    tam--;
    return true;
}

void ordenarPorValorBaseBurbujaAsc(Paciente arr[], int tam) {
    bool huboIntercambio = true;
    for (int i = 0; i < tam - 1 && huboIntercambio; ++i) {
        huboIntercambio = false;
        for (int j = 0; j < tam - 1 - i; ++j) {
            if (arr[j].valorBase > arr[j + 1].valorBase) {
                intercambiar(arr[j], arr[j + 1]);
                huboIntercambio = true;
            }
        }
    }
}

double calcularPromedioConsulta(const Paciente arr[], int tam) {
    if (tam <= 0) return 0.0;
    double suma = 0.0;
    for (int i = 0; i < tam; ++i) {
        suma += arr[i].importeConsulta;
    }
    return suma / tam;
}

void mostrarMenu() {
    cout << "\n======================================================================\n";
    cout << "        SISTEMA DE GESTION HOSPITALARIA (ARRAY OF STRUCTS)            \n";
    cout << "======================================================================\n";
    cout << "  1. Listar Padron de Pacientes (Formato Tabular)\n";
    cout << "  2. Consultar Paciente por ID (Read)\n";
    cout << "  3. Registrar Paciente en Posicion (Create / Right-Shift)\n";
    cout << "  4. Modificar Paciente Existente (Update / PK Inmutable)\n";
    cout << "  5. Alta Medica / Baja Fisica (Delete / Left-Shift)\n";
    cout << "  6. Ordenar por Valor Base (Burbuja Ascendente)\n";
    cout << "  7. Calcular Promedio de Aranceles de Consulta (Estadistica / Const)\n";
    cout << "  0. Salir\n";
    cout << "======================================================================\n";
}

void mostrarFicha(const Paciente &e) {
    cout << "  +------------------------------------------------------------------+\n";
    cout << "  | FICHA CLINICA DE PACIENTE EN GUARDIA                             |\n";
    cout << "  +------------------------------------------------------------------+\n";
    cout << "  | ID Paciente:      " << left << setw(47) << e.idPaciente << "|\n";
    cout << "  | Anio Nacimiento:  " << left << setw(47) << e.anioNacimiento << "|\n";
    cout << "  | Edad:             " << left << setw(45) << e.edad << " anios|\n";
    cout << "  | Categoria:        " << left << setw(47) << (e.categoria == 'P' ? "P (Pediatrico)" : (e.categoria == 'A' ? "A (Adulto)" : "G (Adulto mayor)")) << "|\n";
    cout << "  | Valor Base Cons.:$" << left << setw(46) << fixed << setprecision(2) << e.valorBase << "|\n";
    cout << "  | Importe Total:   $" << left << setw(46) << fixed << setprecision(2) << e.importeConsulta << "|\n";
    cout << "  +------------------------------------------------------------------+\n" << right;
}

void mostrarTabla(const Paciente arr[], int tam) {
    if (tam == 0) {
        cout << "  [!] El padron de guardia esta vacio (tam = 0).\n";
        return;
    }

    cout << "\n+-----+--------+----------+------+-----+------------+------------+\n";
    cout << "| POS | ID PAC | ANIO NAC | EDAD | CAT | VALOR BASE | IMP. TOTAL |\n";
    cout << "+-----+--------+----------+------+-----+------------+------------+\n";

    cout << right;
    for (int i = 0; i < tam; ++i) {
        cout << "| [" << setw(1) << i << "] | "
             << setw(6) << arr[i].idPaciente << " |   "
             << setw(6) << arr[i].anioNacimiento << " |  "
             << setw(3) << arr[i].edad << " |  "
             << arr[i].categoria << "  | $"
             << setw(9) << fixed << setprecision(2) << arr[i].valorBase << " | $"
             << setw(9) << fixed << setprecision(2) << arr[i].importeConsulta << " |\n";
    }
    cout << "+-----+--------+----------+------+-----+------------+------------+\n";
    cout << "Total pacientes en guardia: " << tam << ".\n";
}
