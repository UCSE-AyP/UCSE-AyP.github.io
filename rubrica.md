# Rúbrica Oficial de Evaluación — 4to Examen Parcial 2026
**Cátedra:** Algoritmos y Programación  
**Módulo 4:** Arreglos de Estructuras (AoS), ABM, Ordenamiento y Estadística  
**Institución:** Universidad Católica de Santiago del Estero — Departamento Académico San Salvador  

---

## 1. Estructura y Modalidad de Evaluación Bimodal

La evaluación se estructura formalmente en dos instancias complementarias que totalizan el 100% de la calificación:

| Instancia | Soporte | Ponderación | Foco Pedagógico |
| :--- | :---: | :---: | :--- |
| **Laboratorio de Programación** | Computadora (C++) | **75%** | Declaración de modelo AoS (tipos primitivos), integración con menú y desarrollo de las 6 funciones lógicas. |
| **Instancia Escrita Individual** | Lápiz y Papel (A4) | **25%** | Traza manual paso a paso de ordenamiento elemental sobre vector numérico ($N=5$). |

---

## 2. Desglose Detallado: Laboratorio de Programación (75% C++)

El código base provisto suministra el esqueleto del programa, el arreglo en RAM con datos precargados y las rutinas de visualización tabular con `<iomanip>`. El estudiante debe declarar los campos del struct según la tabla de dominio (admitiéndose tanto `double` como `float` para campos decimales sin penalización de puntaje), enlazar los `case` del menú interactivo y programar las **6 funciones de lógica algorítmica pura en C++**:

### Bloque 1: Búsqueda por Clave Primaria (10%)
- **Firma Conceptual:** `int buscarPorClave(const T arr[], int tam, int claveBuscada);`
- **Criterios de Evaluación:**
  - **10% (Completo / Excelente):** Recorrido secuencial respetando el tamaño lógico `tam`. Al encontrar la coincidencia, retorna inmediatamente la posición de celda `[0 .. tam-1]`. Esta salida temprana interrumpe inmediatamente el recorrido apenas se localiza la clave, sin recorrer celdas innecesarias. Retorno consistente del valor centinela `-1` si el elemento no existe. Uso de `const` para proteger el arreglo de entrada como parámetro de solo lectura.
  - **5% (Parcial / Básico):** Encuentra el registro pero no retorna `-1` cuando no existe, o no aplica salida temprana recorriendo innecesariamente todo el arreglo.
  - **0% (Insuficiente):** No compila, desborda los límites del arreglo o no localiza el elemento.

### Bloque 2: Alta / Inserción con Unicidad de Clave (15%)
- **Firma Conceptual:**
  ```cpp
  bool insertarRegistro(T arr[], int &tam, int capacidad, int posicion, const T &nuevo);
  ```
- **Parámetros:** Arreglo `arr[]`, tamaño lógico por referencia `&tam`, capacidad física máxima `capacidad`, índice de inserción `posicion` (`0 <= posicion <= tam`) y el registro a insertar `nuevo`.
- **Criterios de Evaluación:**
  - **15% (Completo / Excelente):** Validación rigurosa de límites físicos (`tam < capacidad` y `posicion` dentro de `[0 .. tam]`). **Modularidad de nivel excelente:** Para alcanzar la máxima valoración de modularidad, deberá reutilizar la función de búsqueda previamente implementada. Una búsqueda lineal integrada dentro de la función se considerará funcional, pero recibirá una valoración menor en el criterio de modularidad. Desplazamiento contiguo a la derecha (*Right-Shift: corrimiento de celdas posteriores para abrir espacio*), asignación de `nuevo` en `arr[posicion]` e incremento `tam++`. Retorno de `true` ante éxito o `false` ante rechazo.
  - **12% (Aceptable / Funcional):** Inserta en posición desplazando correctamente y evita duplicados mediante búsqueda lineal integrada in-line (alcanza el 80% correspondiente al funcionamiento algorítmico correcto, con menor valoración en modularidad).
  - **5% (Básico):** Inserta pero no valida unicidad de clave o comete error de límites ("off-by-one") al desplazar.
  - **0% (Insuficiente):** Sobrescribe elementos sin desplazar, no incrementa `tam` o desborda la capacidad física.

### Bloque 3: Modificación con Clave Inmutable (10%)
- **Firma Conceptual:** `bool modificarRegistro(T arr[], int tam, const T &actualizado);`
- **Criterios de Evaluación:**
  - **10% (Completo / Excelente):** Para alcanzar la máxima valoración de modularidad, deberá reutilizar la función de búsqueda previamente implementada. Una búsqueda lineal integrada dentro de la función se considerará funcional, pero recibirá una valoración menor en el criterio de modularidad.
    - **Tema 1 (Pacientes):** Modificación in-place de año de nacimiento y valor base de consulta, recálculo de edad de referencia, categoría e importe final, y preservación inalterable del ID de paciente.
    - **Tema 2 (Alumnos):** Modificación in-place de materias aprobadas, promedio y asistencia, recálculo de condición académica (Promocionado, Regular o Libre), y preservación inalterable de legajo y año de ingreso.
    - *Flexibilidad de recálculo:* Se considera válido tanto el recálculo interno en la función de modificación como la recepción de una estructura temporal consolidada desde el switch, acreditando el 100% del puntaje funcional.
    - Retorno de `true` ante éxito o `false` si el registro no existe.
  - **8% (Aceptable / Funcional):** Modifica el registro correctamente usando búsqueda lineal integrada in-line sin alterar la clave primaria (alcanza el 80% correspondiente al funcionamiento algorítmico correcto).
  - **0% (Insuficiente):** Permite modificar la clave primaria, no actualiza el registro o genera inconsistencias en memoria.

### Bloque 4: Baja Física con Compactación del Arreglo mediante Corrimiento a la Izquierda (15%)
- **Firma Conceptual:** `bool darDeBajaFisica(T arr[], int &tam, int claveABorrar);`
- **Criterios de Evaluación:**
  - **15% (Completo / Excelente):** Para alcanzar la máxima valoración de modularidad, deberá reutilizar la función de búsqueda previamente implementada. Una búsqueda lineal integrada dentro de la función se considerará funcional, pero recibirá una valoración menor en el criterio de modularidad. Desplazamiento contiguo a la izquierda (*Left-Shift: corrimiento de las celdas posteriores hacia adelante para compactar el arreglo sin dejar celdas vacías intermedias*). Decremento del tamaño lógico `tam--`. Retorno de `true` ante éxito o `false` si no existe.
  - **12% (Aceptable / Funcional):** Realiza la baja física compactando correctamente mediante búsqueda lineal integrada in-line (alcanza el 80% correspondiente al funcionamiento algorítmico correcto).
  - **5% (Básico):** Aplica baja lógica en lugar de física, o comete errores de límites dejando datos residuales al final.
  - **0% (Insuficiente):** Decrementa `tam` sin compactar el arreglo o no reduce el tamaño lógico.

### Bloque 5: Ordenamiento Burbuja Mejorada con Intercambio de Estructuras (15%)
- **Firma Conceptual:** `void ordenarBurbuja(T arr[], int tam);`
- **Criterios de Evaluación:**
  - **15% (Completo / Excelente):** Algoritmo de **Burbuja Mejorada** con bandera booleana `huboIntercambio` para corte anticipado si el arreglo ya está ordenado. Criterio de comparación estricto por campo clave (valorBase Ascendente en Tema 1 / promedio Descendente en Tema 2). **Intercambio de estructuras** *(intercambio de la estructura completa mediante una función auxiliar modular o variable auxiliar de tipo struct, garantizando la integridad de todos sus campos)*.
  - **8% (Aceptable / Funcional):** Implementa Burbuja clásica elemental sin bandera de corte, o con detalles menores en la comparación.
  - **0% (Insuficiente):** No ordena, bucle infinito, permuta campos sueltos en vez del struct completo o utiliza `std::sort`.

### Bloque 6: Cálculo Estadístico Seguro con Guarda Defensiva (10%)
- **Firma Conceptual:** `double calcularPromedio(const T arr[], int tam);`
- **Criterios de Evaluación:**
  - **10% (Completo / Excelente):** Recorrido secuencial acumulando la métrica solicitada (importe de consulta médica (importeConsulta) en Tema 1 / promedio académico general (promedio) en Tema 2). **Guarda defensiva** *(verificación previa `if (tam <= 0) return 0.0;` para prevenir divisiones por cero ante arreglos vacíos)*. División segura en punto flotante retornando `double`. Arreglo recibido con calificador `const`.
  - **5% (Aceptable / Parcial):** Calcula el promedio correctamente pero omite la guarda defensiva o no aplica `const`.
  - **0% (Insuficiente):** No realiza el recorrido, divide por variable errónea o genera error aritmético en tiempo de ejecución.

---

## 3. Desglose Detallado: Instancia Escrita Individual (25% Papel)

Se evalúa la comprensión algorítmica profunda mediante la traza manual paso a paso en hoja de examen A4:

### Tema 1: Selección Directa Ascendente ($V = [50, 15, 80, 32, 9]$)

| Pasada | Rango Subarreglo | Menor Detectado | Swap Realizado | [0] | [1] | [2] | [3] | [4] | Subarreglo Ordenado |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Inicial** | - | - | Ninguno | 50 | 15 | 80 | 32 | 9 | Vacío |
| **i = 0** | [0..4]: {50, 15, 80, 32, 9} | $9$ en índice [4] | $V[0] \leftrightarrow V[4]$ | **9** | 15 | 80 | 32 | 50 | {9} (6.25 pts) |
| **i = 1** | [1..4]: {15, 80, 32, 50} | $15$ en índice [1] | $\text{posMin} == i$ (Sin swap) | **9** | **15** | 80 | 32 | 50 | {9, 15} (6.25 pts) |
| **i = 2** | [2..4]: {80, 32, 50} | $32$ en índice [3] | $V[2] \leftrightarrow V[3]$ | **9** | **15** | **32** | 80 | 50 | {9, 15, 32} (6.25 pts) |
| **i = 3** | [3..4]: {80, 50} | $50$ en índice [4] | $V[3] \leftrightarrow V[4]$ | **9** | **15** | **32** | **50** | **80** | {9, 15, 32, 50, 80} (6.25 pts) |

### Tema 2: Inserción Directa Descendente ($V = [38, 14, 62, 8, 25]$)

| Pasada | Elemento Clave | Comparaciones y Desplazamientos | Inserción en Hueco | [0] | [1] | [2] | [3] | [4] | Subarreglo Ordenado |
| :---: | :---: | :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Inicial** | - | Primer elemento ordenado trivialmente | - | 38 | 14 | 62 | 8 | 25 | {38} |
| **i = 1** | $\text{aux} = 14$ | $38 \ge 14$ (No desplaza, 0 corrimientos) | $V[1] = 14$ | **38** | **14** | 62 | 8 | 25 | {38, 14} (6.25 pts) |
| **i = 2** | $\text{aux} = 62$ | $14 < 62$ (desplaza $14$), $38 < 62$ (desplaza $38$) | $V[0] = 62$ | **62** | **38** | **14** | 8 | 25 | {62, 38, 14} (6.25 pts) |
| **i = 3** | $\text{aux} = 8$ | $14 \ge 8$ (No desplaza, 0 corrimientos) | $V[3] = 8$ | **62** | **38** | **14** | **8** | 25 | {62, 38, 14, 8} (6.25 pts) |
| **i = 4** | $\text{aux} = 25$ | $8 < 25$ (desplaza $8$), $14 < 25$ (desplaza $14$), $38 \ge 25$ (frena) | $V[2] = 25$ | **62** | **38** | **25** | **14** | **8** | {62, 38, 25, 14, 8} (6.25 pts) |

---

## 4. Penalizaciones y Criterios Disciplinares

| Falta Técnica | Penalización | Justificación Pedagógica |
| :--- | :---: | :--- |
| **Uso de Vectores Paralelos** | **-50% del examen** | Violación directa de la arquitectura del Módulo 4 (Array of Structs). |
| **Uso de `std::sort` o librerías externas** | **-15% (Bloque 5 anulado)** | Se evalúa la comprensión y codificación del algoritmo de ordenamiento manual. |
| **Errores de Compilación** | **Descuento en bloque (hasta -30%)** | El código entregado debe compilar bajo el estándar C++17. Se descuenta dentro del bloque afectado; si una corrección sintáctica mínima permite evaluar la lógica desarrollada, podrá reconocerse puntaje parcial. |
| **Permutación de campos sueltos en ordenamiento** | **-10%** | Desincroniza los registros destruyendo la integridad de los datos. |

> [!IMPORTANT]
> **Regla de No Acumulación:** Las penalizaciones no se acumularán cuando sancionen el mismo defecto ya considerado en el bloque correspondiente. La calificación final del examen no podrá ser inferior a 0%.

---

## 5. Tabla de Conversión a Nota Final (Escala UCSE 1 a 10)

| Puntaje Total (%) | Nota UCSE | Condición Académica |
| :---: | :---: | :--- |
| **0 – 39%** | **1 – 2** | No Aprobado / Reprobado |
| **40 – 59%** | **3** | Insuficiente (Recupera) |
| **60 – 67%** | **4** | **Aprobado (Mínimo de acreditación)** |
| **68 – 75%** | **5** | Aprobado (Aceptable) |
| **76 – 83%** | **6** | Bueno |
| **84 – 87%** | **7** | Muy Bueno |
| **88 – 91%** | **8** | Distinguido |
| **92 – 95%** | **9** | Excelente |
| **96 – 100%** | **10** | Sobresaliente |
