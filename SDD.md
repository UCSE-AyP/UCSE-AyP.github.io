# Software Design Document (SDD) — 4to Examen 2026
**Módulo 4: Arreglos de Estructuras (AoS) y Algoritmos de Ordenamiento**  
**Universidad Católica de Santiago del Estero — DASS**  
**Cátedra:** Algoritmos y Programación  
**Ciclo Lectivo:** 2026  

---

## 1. Visión General y Objetivos de Evaluación

El presente documento formaliza la arquitectura técnica, estructuras de datos, contratos algorítmicos e invariantes de memoria para el **4to Examen Parcial 2026**.

### Modalidad Bimodal Obligatoria
1. **75% Laboratorio de Programación (C++):**
   - Resolución en computadora sobre un arreglo estático de registros (`struct` + array AoS).
   - **Tipos de datos exclusivamente primitivos (`int`, `char`, `double`):** Se evita el tipo `string` para eliminar cualquier problema con `cin.ignore()`, `cin.getline()` o desincronización de caracteres de nueva línea en el buffer. Toda la carga se realiza mediante `cin >>`.
   - Implementación de las 6 operaciones fundamentales de la lógica pura (Búsqueda por clave, Inserción con unicidad y corrimiento a derecha, Modificación in-place con clave primaria inmutable, Baja física con compactación del arreglo mediante corrimiento a la izquierda, Ordenamiento Burbuja Mejorada con swap integral y Cálculo Estadístico Seguro con guarda defensiva).
   - Capa de presentación por consola (menús, tablas formateadas con `<iomanip>`, fichas y buffers) **100% pre-implementada** por la cátedra para optimizar el tiempo de examen.
2. **25% Instancia Escrita Individual (Lápiz y Papel):**
   - Trazabilidad manual paso a paso en hoja A4 de un algoritmo clásico de ordenamiento sobre un vector de 5 elementos enteros.
   - Tema 1: **Selección Directa (Selection Sort)** en sentido **Ascendente**.
   - Tema 2: **Inserción Directa (Insertion Sort)** en sentido **Descendente**.

---

## 2. Definición de Temas y Modelos de Datos

### Tema 1: Sistema Hospitalario de Pacientes
- **Entidad:** `Paciente`
- **Contexto:** Gestión en RAM del padrón de guardia hospitalaria, cálculo de edad, clasificación por categorías de edad y cálculo de aranceles de consulta.
- **Estructura C++:**
```cpp
struct Paciente {
    int idPaciente;        // Clave Primaria unívoca (estrictamente inmutable)
    int anioNacimiento;    // Año de nacimiento (<= 2026)
    int edad;              // Calculado: 2026 - anioNacimiento
    char categoria;        // 'P' (Pediátrico < 13), 'A' (Adulto 13-59), 'G' (Geriátrico >= 60)
    double valorBase;      // Valor base de la consulta médica (> 0)
    double importeConsulta;// Calculado: valorBase * (1.0 + recargoCategoria)
};
```
- **Algoritmo en C++:** Burbuja Mejorada **Ascendente** por `valorBase`.
- **Instancia Escrita:** Selección Directa Ascendente sobre $V = [50, 15, 80, 32, 9]$.

### Tema 2: Sistema de Gestión Académica Universitaria
- **Entidad:** `Alumno`
- **Contexto:** Administración del padrón estudiantil de la facultad, cómputo de materias aprobadas, promedios, asistencias y determinación de condición académica.
- **Estructura C++:**
```cpp
struct Alumno {
    int legajo;            // Clave Primaria unívoca (estrictamente inmutable)
    int anioIngreso;       // Año de ingreso a la facultad (<= 2026)
    int materiasAprobadas; // Cantidad total de materias acreditadas (>= 0)
    double promedio;       // Promedio general acumulado (0.00 a 10.00)
    double asistencia;     // Porcentaje de asistencia a clases (0.0 a 100.0%)
    char condicion;        // 'P' (Promocionadodo), 'R' (Regular), 'L' (Libre)
};
```
- **Algoritmo en C++:** Burbuja Mejorada **Descendente** por `promedio`.
- **Instancia Escrita:** Inserción Directa Descendente sobre $V = [38, 14, 62, 8, 27]$.

---

## 3. Contratos de Funciones Algorítmicas (Lógica Pura C++)

### 3.1. Búsqueda por Clave Primaria (10%)
- **Firma Tema 1:** `int buscarPorId(const Paciente arr[], int tam, int idBuscado);`
- **Firma Tema 2:** `int buscarPorLegajo(const Alumno arr[], int tam, int legajoBuscado);`
- **Contrato:**
  - Recorrido secuencial con salida temprana inmediata al coincidir la clave.
  - Retorna índice `[0 .. tam-1]` o `-1` (centinela). Const-correctness.

### 3.2. Alta / Inserción con Unicidad de Clave (15%)
- **Firma:** `bool insertar(T arr[], int &tam, int capacidad, int pos, const T &nuevo);`
- **Contrato:**
  - Control de cupo (`tam < capacidad`) y límites de posición.
  - Verificación obligatoria de unicidad reutilizando la función de búsqueda.
  - Right-Shift, copia del registro e incremento `tam++`. Retorna booleano.

### 3.3. Modificación con Clave Inmutable (10%)
- **Firma:** `bool modificar(T arr[], int tam, const T &actualizado);`
- **Contrato:**
  - Reutiliza la búsqueda para obtener la posición de memoria.
  - Mutación *in-place* de campos mutables.
  - **Invariante:** Clave primaria inmutable. Retorna booleano.

### 3.4. Baja Física con Compactación del Arreglo mediante Corrimiento a la Izquierda (15%)
- **Firma:** `bool darDeBaja(T arr[], int &tam, int claveABorrar);`
- **Contrato:**
  - Reutiliza la búsqueda para hallar el índice.
  - Left-Shift para compactar la memoria contigua y `tam--`. Retorna booleano.

### 3.5. Ordenamiento Burbuja Mejorada con Intercambio de Estructuras (15%)
- **Firma:** `void ordenarBurbuja(T arr[], int tam);`
- **Contrato:**
  - Control con bandera `huboIntercambio` para corte anticipado.
  - Permutación atómica de registros completos vía `intercambiar(T &a, T &b)`.

### 3.6. Cálculo Estadístico Seguro con Guarda Defensiva (10%)
- **Firma:** `double calcularPromedioConsulta(const Paciente arr[], int tam);` (Tema 1) / `double calcularPromedioGeneralCohorte(const Alumno arr[], int tam);` (Tema 2)
- **Contrato:**
  - Recorrido secuencial acumulando la métrica clave (importe de consulta (importeConsulta) en Tema 1 / promedio académico (promedio) en Tema 2).
  - Guarda defensiva: si `tam <= 0` retorna inmediatamente `0.0` para prevenir división por cero.
  - Retorno de promedio en punto flotante `double` y preservación de solo lectura con calificador `const`.

---

## 4. Matriz de Ponderación Oficial

| Bloque | Contenido | Soporte | Pts |
| :---: | :--- | :---: | :---: |
| 1 | Búsqueda por Clave Primaria (Índice, Centinela -1, Const) | C++ | 10% |
| 2 | Alta / Inserción con Unicidad de Clave (Capacidad, Unicidad, Right-Shift, tam++) | C++ | 15% |
| 3 | Modificación con Clave Inmutable (Reutilización búsqueda, Mutación in-place) | C++ | 10% |
| 4 | Baja Física con Compactación del Arreglo mediante Corrimiento a la Izquierda (Reutilización búsqueda, Left-Shift, tam--) | C++ | 15% |
| 5 | Ordenamiento Burbuja Mejorada con Intercambio de Estructuras (Bandera, Comparación, Intercambio) | C++ | 15% |
| 6 | Cálculo Estadístico Seguro con Guarda Defensiva (Acumulador, tam <= 0, Const) | C++ | 10% |
| 7 | Instancia Escrita: Traza de Ordenamiento (Pasadas, Mín/Aux, Desplazamientos) | Papel | 25% |
| **Total** | **Acreditación Bimodal de Competencias Módulo 4** | **100%** |
