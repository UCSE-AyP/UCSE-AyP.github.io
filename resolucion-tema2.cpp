#include <iostream>
#include <iomanip>

using namespace std;

struct Alumno {
    // Estructura declarada respetando estrictamente el orden del enunciado para inicializacion por llaves
    int legajo;            // Clave Primaria univoca
    int anioIngreso;       // Anio de ingreso a la facultad (<= 2026)
    int materiasAprobadas; // Cantidad de asignaturas aprobadas (>= 0)
    double promedio;       // Promedio general academico (0.00 .. 10.00)
    double asistencia;     // Porcentaje de asistencia a clases (0.0 .. 100.0)
    char condicion;        // 'P' (Promociona), 'R' (Regular), 'L' (Libre)
};

// Prototipos de funciones a implementar por el estudiante
void intercambiar(Alumno &a, Alumno &b);
int buscarPorLegajo(const Alumno arr[], int tam, int legajoBuscado);
bool insertarAlumno(Alumno arr[], int &tam, int capacidad, int pos, const Alumno &nuevo);
bool modificarAlumno(Alumno arr[], int tam, const Alumno &actualizado);
bool darDeBajaAlumno(Alumno arr[], int &tam, int legajoABorrar);
void ordenarPorPromedioBurbujaDesc(Alumno arr[], int tam);
double calcularPromedioGeneralCohorte(const Alumno arr[], int tam);

// Modulos meramente de escritura pre-implementados
void mostrarMenu();
void mostrarFicha(const Alumno &e);
void mostrarTabla(const Alumno arr[], int tam);

int main() {
    const int CAPACIDAD = 15;
    Alumno padron[CAPACIDAD] = {
        {10521, 2023, 14, 8.75, 85.0, 'P'},
        {10640, 2024, 8,  6.40, 75.0, 'R'},
        {10712, 2021, 22, 9.50, 92.0, 'P'},
        {10830, 2025, 5,  5.20, 60.0, 'L'}
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
                cout << ">>> CONSULTA DE ALUMNO POR LEGAJO <<<\n";
                int leg;
                cout << "  Ingrese Legajo a buscar: ";
                cin >> leg;
                int pos = buscarPorLegajo(padron, tam, leg);
                if (pos != -1) {
                    cout << "  [OK] Alumno localizado en celda [" << pos << "]:\n";
                    mostrarFicha(padron[pos]);
                } else {
                    cout << "  [-] Alumno con Legajo " << leg << " no existe en el padron.\n";
                }
                break;
            }
            case 3: {
                cout << ">>> ALTA / INSERCION DE ALUMNO EN PADRON <<<\n";
                int pos;
                cout << "  Ingrese posicion donde desea insertar [0 .. " << tam << "]: ";
                cin >> pos;
                Alumno nuevo;
                cout << "  Ingrese Legajo del alumno (entero unico): ";
                cin >> nuevo.legajo;
                cout << "  Ingrese Anio de ingreso [2000..2026]: ";
                cin >> nuevo.anioIngreso;
                cout << "  Ingrese Materias Aprobadas (>= 0): ";
                cin >> nuevo.materiasAprobadas;
                cout << "  Ingrese Promedio General (0.00 a 10.00): ";
                cin >> nuevo.promedio;
                cout << "  Ingrese Asistencia % (0.0 a 100.0): ";
                cin >> nuevo.asistencia;

                if (nuevo.promedio >= 8.0 && nuevo.asistencia >= 80.0) nuevo.condicion = 'P';
                else if (nuevo.promedio >= 6.0 && nuevo.asistencia >= 70.0) nuevo.condicion = 'R';
                else nuevo.condicion = 'L';

                if (insertarAlumno(padron, tam, CAPACIDAD, pos, nuevo)) {
                    cout << "\n  [OK] Alumno registrado exitosamente en la celda [" << pos << "]. Total: " << tam << "/" << CAPACIDAD << "\n";
                } else {
                    cout << "\n  [!] ERROR: No se pudo registrar. Verifique legajo duplicado, cupo agotado o posicion invalida.\n";
                }
                break;
            }
            case 4: {
                cout << ">>> MODIFICACION DE ALUMNO (UPDATE / PK INMUTABLE) <<<\n";
                int leg;
                cout << "  Ingrese Legajo del alumno a modificar: ";
                cin >> leg;
                int pos = buscarPorLegajo(padron, tam, leg);
                if (pos == -1) {
                    cout << "\n  [-] Alumno no encontrado.\n";
                } else {
                    Alumno modificado;
                    modificado.legajo = leg; // Clave primaria inmutable
                    cout << "  Modificando alumno con Legajo: " << leg << " (inalterable)\n";
                    cout << "  Nuevo Anio de ingreso [2000..2026]: ";
                    cin >> modificado.anioIngreso;
                    cout << "  Nuevas Materias Aprobadas (>= 0): ";
                    cin >> modificado.materiasAprobadas;
                    cout << "  Nuevo Promedio General (0.00 a 10.00): ";
                    cin >> modificado.promedio;
                    cout << "  Nueva Asistencia % (0.0 a 100.0): ";
                    cin >> modificado.asistencia;

                    if (modificado.promedio >= 8.0 && modificado.asistencia >= 80.0) modificado.condicion = 'P';
                    else if (modificado.promedio >= 6.0 && modificado.asistencia >= 70.0) modificado.condicion = 'R';
                    else modificado.condicion = 'L';

                    if (modificarAlumno(padron, tam, modificado)) {
                        cout << "\n  [OK] Datos academicos modificados exitosamente.\n";
                    } else {
                        cout << "\n  [!] Error al modificar.\n";
                    }
                }
                break;
            }
            case 5: {
                cout << ">>> BAJA FISICA DE ALUMNO (DELETE / COMPACTACION) <<<\n";
                int leg;
                cout << "  Ingrese Legajo del alumno a dar de baja: ";
                cin >> leg;
                if (darDeBajaAlumno(padron, tam, leg)) {
                    cout << "\n  [OK] Registro eliminado y arreglo compactado correctamente. Total activos: " << tam << "\n";
                } else {
                    cout << "\n  [-] Legajo no encontrado. No se realizo ninguna baja.\n";
                }
                break;
            }
            case 6:
                cout << ">>> ORDENAMIENTO BURBUJA (DESCENDENTE POR PROMEDIO) <<<\n";
                ordenarPorPromedioBurbujaDesc(padron, tam);
                cout << "  [OK] Padron ordenado de mayor a menor segun promedio con exito.\n";
                mostrarTabla(padron, tam);
                break;
            case 7: {
                cout << ">>> REPORTE ESTADISTICO: CALCULAR PROMEDIO GENERAL ACADEMICO <<<\n";
                double prom = calcularPromedioGeneralCohorte(padron, tam);
                cout << "  [RESULTADO] Promedio calculado: " << fixed << setprecision(2) << prom << "\n";
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

void intercambiar(Alumno &a, Alumno &b) {
    Alumno aux = a;
    a = b;
    b = aux;
}

int buscarPorLegajo(const Alumno arr[], int tam, int legajoBuscado) {
    for (int i = 0; i < tam; ++i) {
        if (arr[i].legajo == legajoBuscado) {
            return i;
        }
    }
    return -1;
}

bool insertarAlumno(Alumno arr[], int &tam, int capacidad, int pos, const Alumno &nuevo) {
    if (tam >= capacidad || pos < 0 || pos > tam) return false;
    if (buscarPorLegajo(arr, tam, nuevo.legajo) != -1) return false;
    for (int i = tam; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = nuevo;
    tam++;
    return true;
}

bool modificarAlumno(Alumno arr[], int tam, const Alumno &actualizado) {
    int pos = buscarPorLegajo(arr, tam, actualizado.legajo);
    if (pos == -1) return false;
    arr[pos].anioIngreso = actualizado.anioIngreso;
    arr[pos].materiasAprobadas = actualizado.materiasAprobadas;
    arr[pos].promedio = actualizado.promedio;
    arr[pos].asistencia = actualizado.asistencia;
    arr[pos].condicion = actualizado.condicion;
    return true;
}

bool darDeBajaAlumno(Alumno arr[], int &tam, int legajoABorrar) {
    int pos = buscarPorLegajo(arr, tam, legajoABorrar);
    if (pos == -1) return false;
    for (int k = pos; k < tam - 1; ++k) {
        arr[k] = arr[k + 1];
    }
    tam--;
    return true;
}

void ordenarPorPromedioBurbujaDesc(Alumno arr[], int tam) {
    bool huboIntercambio = true;
    for (int i = 0; i < tam - 1 && huboIntercambio; ++i) {
        huboIntercambio = false;
        for (int j = 0; j < tam - 1 - i; ++j) {
            if (arr[j].promedio < arr[j + 1].promedio) {
                intercambiar(arr[j], arr[j + 1]);
                huboIntercambio = true;
            }
        }
    }
}

double calcularPromedioGeneralCohorte(const Alumno arr[], int tam) {
    if (tam <= 0) return 0.0;
    double suma = 0.0;
    for (int i = 0; i < tam; ++i) {
        suma += arr[i].promedio;
    }
    return suma / tam;
}

void mostrarMenu() {
    cout << "\n======================================================================\n";
    cout << "        SISTEMA DE GESTION ACADEMICA (ARRAY OF STRUCTS)               \n";
    cout << "======================================================================\n";
    cout << "  1. Listar Padron de Alumnos (Formato Tabular)\n";
    cout << "  2. Consultar Alumno por Legajo (Read)\n";
    cout << "  3. Registrar Nuevo Alumno en Posicion (Create / Right-Shift)\n";
    cout << "  4. Modificar Alumno Existente (Update / PK Inmutable)\n";
    cout << "  5. Dar de Baja Fisica de Alumno (Delete / Left-Shift)\n";
    cout << "  6. Ordenar por Promedio (Burbuja Descendente)\n";
    cout << "  7. Calcular Promedio General Academico (Estadistica / Const)\n";
    cout << "  0. Salir\n";
    cout << "======================================================================\n";
}

void mostrarFicha(const Alumno &e) {
    cout << "  +------------------------------------------------------------------+\n";
    cout << "  | LEGAJO ACADEMICO DE ESTUDIANTE                                   |\n";
    cout << "  +------------------------------------------------------------------+\n";
    cout << "  | Legajo:           " << left << setw(47) << e.legajo << "|\n";
    cout << "  | Anio Ingreso:     " << left << setw(47) << e.anioIngreso << "|\n";
    cout << "  | Materias Aprob.:  " << left << setw(47) << e.materiasAprobadas << "|\n";
    cout << "  | Asistencia:       " << fixed << setprecision(1) << e.asistencia << "%" << left << setw(e.asistencia >= 100.0 ? 41 : 42) << "" << "|\n";
    cout << "  | Promedio General: " << left << setw(47) << fixed << setprecision(2) << e.promedio << "|\n";
    cout << "  | Condicion Final:  " << left << setw(47) << (e.condicion == 'P' ? "P (Promocionado)" : (e.condicion == 'R' ? "R (Regular)" : "L (Libre)")) << "|\n";
    cout << "  +------------------------------------------------------------------+\n" << right;
}

void mostrarTabla(const Alumno arr[], int tam) {
    if (tam == 0) {
        cout << "  [!] El padron academico esta vacio (tam = 0).\n";
        return;
    }

    cout << "\n+-----+--------+----------+------+----------+--------+-----+--------------+\n";
    cout << "| POS | LEGAJO | ANIO ING | MATS | PROMEDIO | ASIST% | CND | CONDICION    |\n";
    cout << "+-----+--------+----------+------+----------+--------+-----+--------------+\n";

    cout << right;
    for (int i = 0; i < tam; ++i) {
        cout << "| [" << setw(1) << i << "] | "
             << setw(6) << arr[i].legajo << " |   "
             << setw(6) << arr[i].anioIngreso << " |  "
             << setw(3) << arr[i].materiasAprobadas << " |    "
             << setw(5) << fixed << setprecision(2) << arr[i].promedio << " |  "
             << setw(4) << fixed << setprecision(1) << arr[i].asistencia << "% |  "
             << arr[i].condicion << "  | "
             << left << setw(12) << (arr[i].condicion == 'P' ? "Promocionado" : (arr[i].condicion == 'R' ? "Regular" : "Libre")) << right << " |\n";
    }
    cout << "+-----+--------+----------+------+----------+--------+-----+--------------+\n";
    cout << "Total alumnos en padron: " << tam << ".\n";
}
