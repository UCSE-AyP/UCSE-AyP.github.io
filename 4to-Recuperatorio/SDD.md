# Software Design Document (SDD) — 4to Recuperatorio 2026
**Módulo 4: Arreglos de Estructuras (AoS) y Algoritmos de Ordenamiento (Alcance Integral)**  
**Universidad Católica de Santiago del Estero — DASS**  
**Cátedra:** Algoritmos y Programación  
**Ciclo Lectivo:** 2026  

---

## 1. Visión General y Objetivos de Evaluación

El presente documento formaliza la arquitectura técnica, estructuras de datos, contratos algorítmicos e invariantes de memoria para el **4to Examen Recuperatorio 2026**, ajustado bajo esquema integral para evitar solapamientos con el Módulo 3.

### Modalidad Bimodal Obligatoria
1. **75% Laboratorio de Programación (C++):**
   - Resolución en computadora sobre un arreglo estático de registros (`struct` + array AoS).
   - Estructuras modeladas **100% con tipos primitivos** (`int`, `char`, `double`, `bool`), omitiendo el tipo `string` para permitir lectura limpia y directa con `cin >>` sin problemas de sincronización de buffers.
   - El estudiante debe definir el `struct` (`10%`) e implementar únicamente las **4 funciones nucleares de Módulo 4**: Alta con unicidad y desplazamiento a derecha (*Right-Shift*, `20%`), Modificación *in-place* con clave primaria inmutable (`15%`), y Ordenamiento Burbuja Mejorada con función auxiliar de intercambio de estructuras (`30%`).
   - La estructura base de `main()` (con el arreglo inicial precargado, lectura del menú y `switch` con `// TODO` por opción para que el estudiante conecte los casos y calcule campos derivados, igual que en el 4to Examen), la capa de presentación tabular (`mostrarMenu`, `mostrarFicha`, `mostrarTabla`) y las primitivas repetidas del Módulo 3 (`buscarPor*`, `darDeBaja*`, `calcularPromedio*`) **se entregan pre-implementadas** en la plantilla base.
2. **25% Instancia Escrita Individual (Lápiz y Papel):**
   - Trazabilidad manual paso a paso en hoja A4 de un algoritmo clásico de ordenamiento sobre un vector de 5 elementos enteros.
   - Tema 1: **Selección Directa (Selection Sort)** en sentido **Ascendente**.
   - Tema 2: **Inserción Directa (Insertion Sort)** en sentido **Descendente**.

---

## 2. Definición de Temas y Modelos de Datos (10%)

### Tema 1: Sistema de Inventario de Tienda Comercial
- **Entidad:** `ProductoTienda`
- **Contexto:** Gestión en RAM del catálogo comercial de una tienda departamental, cálculo de recargo según nivel de stock y valorización del inventario.
- **Estructura C++ (100% Primitivos):**
```cpp
struct ProductoTienda {
    int codigo;            // Clave Primaria unívoca (estrictamente inmutable)
    int stock;             // Existencias en depósito (>= 0)
    char categoria;        // 'B' (Bajo < 20), 'M' (Medio 20..50), 'A' (Alto > 50)
    double precioBase;     // Precio base del producto (> 0)
    double valorUnitario;  // Calculado: precioBase + % segun categoria (B:+20%, M:+15%, A:+10%)
    double valorStock;     // Calculado: valorUnitario * stock
};
```
- **Algoritmo en C++:** Burbuja Mejorada **Ascendente** por `precioBase`.
- **Instancia Escrita:** Selección Directa Ascendente sobre $V = [45, 11, 72, 28, 6]$.

### Tema 2: Sistema de Reservas Hoteleras
- **Entidad:** `ReservaHotel`
- **Contexto:** Administración del registro de reservas de un complejo hotelero, con recargos según tipo de habitación e importes totales calculados.
- **Estructura C++ (100% Primitivos):**
```cpp
struct ReservaHotel {
    int nroHabitacion;     // Clave Primaria unívoca (estrictamente inmutable)
    int noches;            // Cantidad de noches reservadas (> 0)
    char tipo;             // 'S' (Simple 0%), 'D' (Doble +10%), 'T' (Triple +20%)
    double precioNoche;    // Tarifa base diaria (> 0)
    double importeTotal;   // Calculado: noches * precioNoche * (1 + recargoTipo)
    bool confirmada;       // Estado de reserva: true (Confirmada), false (Pendiente)
};
```
- **Algoritmo en C++:** Burbuja Mejorada **Descendente** por `importeTotal`.
- **Instancia Escrita:** Inserción Directa Descendente sobre $V = [33, 19, 58, 12, 41]$.

---

## 3. Contratos de Funciones Algorítmicas

### 3.1. Primitivas Auxiliares Provistas en la Plantilla Base (Pre-implementadas)
Para evitar re-evaluar lógica elemental de Módulo 3, la plantilla entrega listas para invocar:
- **Búsqueda lineal:** `int buscarPorCodigo(const ProductoTienda arr[], int tam, int codigoBuscado);` / `int buscarPorHabitacion(const ReservaHotel arr[], int tam, int nroBuscado);`
- **Baja física Left-Shift:** `bool darDeBajaProducto(ProductoTienda arr[], int &tam, int codigoABorrar);` / `bool darDeBajaReserva(ReservaHotel arr[], int &tam, int nroABorrar);`
- **Promedio estadístico:** `double calcularPromedioValorUnitario(const ProductoTienda arr[], int tam);` / `double calcularPromedioFacturacion(const ReservaHotel arr[], int tam);`

### 3.2. Alta / Inserción con Unicidad de Clave y Right-Shift (20%) — Estudiante
- **Firma Tema 1:** `bool insertarProducto(ProductoTienda arr[], int &tam, int capacidad, int pos, const ProductoTienda &nuevo);`
- **Firma Tema 2:** `bool insertarReserva(ReservaHotel arr[], int &tam, int capacidad, int pos, const ReservaHotel &nueva);`
- **Contrato:**
  - Control de capacidad: rechaza si `tam >= capacidad` o `pos < 0` o `pos > tam`.
  - Reutilización modular de la función provista `buscarPor*`: rechaza si la clave primaria ya existe (`buscar != -1`).
  - Right-Shift: desplaza desde `tam` hasta `pos + 1` una celda a la derecha.
  - Inserción e incremento: `arr[pos] = nuevo`, `tam++`. Retorna `true`.

### 3.3. Modificación in-place con Clave Inmutable (15%) — Estudiante
- **Firma Tema 1:** `bool modificarProducto(ProductoTienda arr[], int tam, const ProductoTienda &actualizado);`
- **Firma Tema 2:** `bool modificarReserva(ReservaHotel arr[], int tam, const ReservaHotel &actualizada);`
- **Contrato:**
  - Reutilización modular de `buscarPor*` para hallar la posición de memoria (`pos == -1 -> false`).
  - Muta *in-place* los atributos secundarios y derivados calculados sobre `arr[pos]` (`stock`, `categoria`, `precioBase`, `valorUnitario`, `valorStock` en T1; `noches`, `tipo`, `precioNoche`, `importeTotal`, `confirmada` en T2).
  - **Invariante:** La clave primaria (`codigo` / `nroHabitacion`) no se modifica bajo ninguna circunstancia.
  - Retorna `true` si se modificó o `false` si no se encontró.

### 3.4. Ordenamiento Burbuja Mejorada con Intercambio Completo de Estructuras (30%) — Estudiante
- **Firmas Tema 1:** `void intercambiar(ProductoTienda &a, ProductoTienda &b);` y `void ordenarPorPrecioBaseBurbujaAsc(ProductoTienda arr[], int tam);`
- **Firmas Tema 2:** `void intercambiar(ReservaHotel &a, ReservaHotel &b);` y `void ordenarPorImporteBurbujaDesc(ReservaHotel arr[], int tam);`
- **Contrato:**
  - Control de banderas: `huboIntercambio` para terminación anticipada en arreglos ya ordenados.
  - Criterio de permutación estricto:
    - *Tema 1:* Solo intercambia si `arr[j].precioBase > arr[j + 1].precioBase`.
    - *Tema 2:* Solo intercambia si `arr[j].importeTotal < arr[j + 1].importeTotal`.
  - Permutación: Invocación a `intercambiar(arr[j], arr[j + 1])` pasando ambos `struct` por referencia.

---

## 4. Instancia Escrita Individual (25% Papel)

### Tema 1: Selección Directa Ascendente ($V = [45, 11, 72, 28, 6]$)
1. **Pasada 0 ($i=0$):** Menor en subarreglo $[45, 11, 72, 28, 6]$ es $6$ en índice $4$. Swap $V[0] \leftrightarrow V[4]$. Result: $[6, 11, 72, 28, 45]$.
2. **Pasada 1 ($i=1$):** Menor en subarreglo $[11, 72, 28, 45]$ es $11$ en índice $1$. Sin swap ($\text{minIdx} == i$). Result: $[6, 11, 72, 28, 45]$.
3. **Pasada 2 ($i=2$):** Menor en subarreglo $[72, 28, 45]$ es $28$ en índice $3$. Swap $V[2] \leftrightarrow V[3]$. Result: $[6, 11, 28, 72, 45]$.
4. **Pasada 3 ($i=3$):** Menor en subarreglo $[72, 45]$ es $45$ en índice $4$. Swap $V[3] \leftrightarrow V[4]$. Result: $[6, 11, 28, 45, 72]$.

### Tema 2: Inserción Directa Descendente ($V = [33, 19, 58, 12, 41]$)
1. **Pasada 1 ($i=1$):** $\text{aux} = 19$. Comp: ¿$33 < 19$? Falso. 0 desplazamientos. Insertar en [1]. Result: $[33, 19, 58, 12, 41]$.
2. **Pasada 2 ($i=2$):** $\text{aux} = 58$. Comp: ¿$19 < 58$? Sí. ¿$33 < 58$? Sí. 2 desplazamientos. Insertar en [0]. Result: $[58, 33, 19, 12, 41]$.
3. **Pasada 3 ($i=3$):** $\text{aux} = 12$. Comp: ¿$19 < 12$? Falso. 0 desplazamientos. Insertar en [3]. Result: $[58, 33, 19, 12, 41]$.
4. **Pasada 4 ($i=4$):** $\text{aux} = 41$. Comp: ¿$12 < 41$? Sí. ¿$19 < 41$? Sí. ¿$33 < 41$? Sí. ¿$58 < 41$? Falso. 3 desplazamientos. Insertar en [2]. Result: $[58, 41, 33, 19, 12]$.

---

## 5. Matriz de Ponderación Oficial

| Bloque | Contenido | Soporte | Pts |
| :---: | :--- | :---: | :---: |
| 1 | Definición de `struct` AoS (6 campos en tipos primitivos y orden exacto) | C++ | 10% |
| 2 | Alta / Inserción con Unicidad de Clave (Capacidad, Unicidad, Right-Shift, `tam++`) | C++ | 20% |
| 3 | Modificación *in-place* con Clave Inmutable (Reutilización búsqueda, Mutación sin alterar PK) | C++ | 15% |
| 4 | Ordenamiento Burbuja Mejorada con Intercambio Completo (`huboIntercambio`, Criterio, `intercambiar`) | C++ | 30% |
| 5 | Instancia Escrita: Traza de Ordenamiento (Pasadas, Mín/Aux, Desplazamientos) | Papel | 25% |
| **Total** | **Acreditación Bimodal de Competencias Módulo 4** | **100%** |
