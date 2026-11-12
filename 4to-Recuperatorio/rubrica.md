# Rúbrica Oficial de Evaluación — 4to Examen Recuperatorio 2026
**Cátedra:** Algoritmos y Programación  
**Módulo 4:** Arreglos de Estructuras (AoS) y Ordenamiento (Alcance Integral sin Solapamiento)  
**Institución:** Universidad Católica de Santiago del Estero — Departamento Académico San Salvador  

---

## 1. Estructura y Modalidad de Evaluación Bimodal

La evaluación se estructura formalmente en dos instancias complementarias que totalizan el 100% de la calificación:

| Instancia | Soporte | Ponderación | Foco Pedagógico |
| :--- | :---: | :---: | :--- |
| **Laboratorio de Programación** | Computadora (C++) | **75%** | Declaración de modelo `struct` AoS (tipos primitivos) y desarrollo de las 4 funciones nucleares de Módulo 4 (`insertar*`, `modificar*`, `ordenarPor*` e `intercambiar`). |
| **Instancia Escrita Individual** | Lápiz y Papel (A4) | **25%** | Traza manual paso a paso de ordenamiento elemental sobre vector numérico ($N=5$). |

---

## 2. Desglose Detallado: Laboratorio de Programación (75% C++)

El código base provisto suministra el esqueleto del menú en `main()` (con el arreglo en RAM precargado y los `case` del `switch` marcados con `// TODO` para completar por el estudiante, igual que en el 4to Examen), las rutinas `<iomanip>` (`mostrarMenu`, `mostrarFicha`, `mostrarTabla`) y las primitivas auxiliares ya evaluadas en Módulo 3 (`buscarPor*`, `darDeBaja*` y `calcularPromedio*`). El estudiante debe declarar el `struct`, conectar los casos del `switch` y programar las **4 funciones nucleares del Módulo 4**:

### Bloque 1: Definición de Estructura AoS en Tipos Primitivos (10%)
- **Contrato:** `struct ProductoTienda` (Tema 1) / `struct ReservaHotel` (Tema 2).
- **Criterios de Evaluación:**
  - **10% (Completo / Excelente):** Declara los 6 miembros solicitados utilizando exclusivamente tipos primitivos (`int`, `char`, `double`, `bool`), respetando nombres exactos y el **mismo orden de la tabla del enunciado** para que el arreglo precargado en `main()` compile sin desfasaje de campos.
  - **5% (Parcial / Básico):** Declara todos los campos, pero altera algún tipo numérico (`float` vs `double` con pérdida de precisión) o requiere ajuste menor para compilar con los inicializadores.
  - **0% (Insuficiente):** Desordena los miembros rompiendo la inicialización `{...}`, emplea `std::string` o vectores paralelos.

### Bloque 2: Alta / Inserción con Unicidad de Clave y Right-Shift (20%)
- **Firma Conceptual:**
  ```cpp
  bool insertarRegistro(T arr[], int &tam, int capacidad, int posicion, const T &nuevo);
  ```
- **Parámetros:** Arreglo `arr[]`, tamaño lógico por referencia `&tam`, capacidad física máxima `capacidad`, índice de inserción `posicion` (`0 <= posicion <= tam`) y el registro a insertar `nuevo`.
- **Criterios de Evaluación:**
  - **20% (Completo / Excelente):** Validación rigurosa de límites físicos (`tam < capacidad` y `posicion` dentro de `[0 .. tam]`). Reutiliza la función provista `buscarPor*` para verificar unicidad de clave (`16%` lógica correcta + `4%` reutilización modular). Desplazamiento contiguo a la derecha (*Right-Shift: `for (int i = tam; i > pos; --i) arr[i] = arr[i - 1];`*), asignación de `nuevo` en `arr[posicion]` e incremento `tam++`. Retorno de `true` ante éxito o `false` ante rechazo.
  - **16% (Aceptable / Funcional):** Inserta desplazando correctamente y evita duplicados mediante bucle lineal in-line sin reutilizar la función provista.
  - **8% (Básico):** Inserta pero omite validar unicidad de clave o comete error de límites ("off-by-one") al desplazar.
  - **0% (Insuficiente):** Sobrescribe elementos sin desplazar, no incrementa `tam` o desborda `capacidad`.

### Bloque 3: Modificación in-place con Clave Primaria Inmutable (15%)
- **Firma Conceptual:** `bool modificarRegistro(T arr[], int tam, const T &actualizado);`
- **Criterios de Evaluación:**
  - **15% (Completo / Excelente):** Reutiliza la función provista `buscarPor*` para localizar el índice (`12%` lógica correcta + `3%` reutilización modular). Mutación *in-place* sobre `arr[pos]` de los atributos secundarios y derivados calculados preservando **estrictamente inmutable la clave primaria** (`codigo` / `nroHabitacion`). Retorna `true` si se modificó o `false` si no se encontró. *(Flexibilidad de recálculo: es válido tanto recalcular los campos derivados en el `switch` previo como dentro de la función).*
  - **12% (Aceptable / Funcional):** Modifica correctamente usando búsqueda in-line manteniendo inmutable la clave primaria.
  - **0% (Insuficiente):** Altera la clave primaria, no actualiza `arr[pos]` o genera inconsistencias.

### Bloque 4: Ordenamiento Burbuja Mejorada con Intercambio Completo de Estructuras (30%)
- **Firmas Conceptuales:**
  - `void intercambiar(T &a, T &b);`
  - `void ordenarBurbuja(T arr[], int tam);`
- **Criterios de Evaluación:**
  - **30% (Completo / Excelente):** Algoritmo **Burbuja Mejorada** con bandera booleana `huboIntercambio` para corte anticipado si el arreglo ya está ordenado. Criterio estricto: Tema 1 intercambia solo si `arr[j].precioBase > arr[j + 1].precioBase` (Ascendente); Tema 2 solo si `arr[j].importeTotal < arr[j + 1].importeTotal` (Descendente). **Intercambio completo de estructuras** invocando `intercambiar(arr[j], arr[j + 1])` con ambos parámetros por referencia `T &a, T &b`.
  - **16% (Aceptable / Funcional):** Implementa Burbuja clásica elemental sin bandera de corte o realiza el swap inline sin utilizar `intercambiar()`.
  - **0% (Insuficiente):** No ordena, permuta campos sueltos en vez del `struct` completo o utiliza `std::sort`.

---

## 3. Desglose Detallado: Instancia Escrita Individual (25% Papel)

Se evalúa la comprensión algorítmica profunda mediante la traza manual paso a paso en hoja de examen A4:

### Tema 1: Selección Directa Ascendente ($V = [45, 11, 72, 28, 6]$)

| Pasada | Rango Subarreglo | Menor Detectado | Swap Realizado | [0] | [1] | [2] | [3] | [4] | Subarreglo Ordenado |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Inicial** | - | - | Ninguno | 45 | 11 | 72 | 28 | 6 | Vacío |
| **i = 0** | [0..4]: {45, 11, 72, 28, 6} | $6$ en índice [4] | $V[0] \leftrightarrow V[4]$ | **6** | 11 | 72 | 28 | 45 | {6} (6.25 pts) |
| **i = 1** | [1..4]: {11, 72, 28, 45} | $11$ en índice [1] | $\text{posMin} == i$ (Sin swap) | **6** | **11** | 72 | 28 | 45 | {6, 11} (6.25 pts) |
| **i = 2** | [2..4]: {72, 28, 45} | $28$ en índice [3] | $V[2] \leftrightarrow V[3]$ | **6** | **11** | **28** | 72 | 45 | {6, 11, 28} (6.25 pts) |
| **i = 3** | [3..4]: {72, 45} | $45$ en índice [4] | $V[3] \leftrightarrow V[4]$ | **6** | **11** | **28** | **45** | **72** | {6, 11, 28, 45, 72} (6.25 pts) |

### Tema 2: Inserción Directa Descendente ($V = [33, 19, 58, 12, 41]$)

| Pasada | Elemento Clave | Comparaciones y Desplazamientos | Inserción en Hueco | [0] | [1] | [2] | [3] | [4] | Subarreglo Ordenado |
| :---: | :---: | :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Inicial** | - | Primer elemento ordenado trivialmente | - | 33 | 19 | 58 | 12 | 41 | {33} |
| **i = 1** | $\text{aux} = 19$ | $33 \ge 19$ (No desplaza, 0 corrimientos) | $V[1] = 19$ | **33** | **19** | 58 | 12 | 41 | {33, 19} (6.25 pts) |
| **i = 2** | $\text{aux} = 58$ | $19 < 58$ (desplaza $19$), $33 < 58$ (desplaza $33$) | $V[0] = 58$ | **58** | **33** | **19** | 12 | 41 | {58, 33, 19} (6.25 pts) |
| **i = 3** | $\text{aux} = 12$ | $19 \ge 12$ (No desplaza, 0 corrimientos) | $V[3] = 12$ | **58** | **33** | **19** | **12** | 41 | {58, 33, 19, 12} (6.25 pts) |
| **i = 4** | $\text{aux} = 41$ | $12 < 41$ (desplaza $12$), $19 < 41$ (desplaza $19$), $33 \ge 41$ (frena) | $V[2] = 41$ | **58** | **41** | **33** | **19** | **12** | {58, 41, 33, 19, 12} (6.25 pts) |

---

## 4. Penalizaciones y Criterios Disciplinares

| Falta Técnica | Penalización | Justificación Pedagógica |
| :--- | :---: | :--- |
| **Uso de Vectores Paralelos** | **-50% del examen** | Violación directa de la arquitectura del Módulo 4 (Array of Structs). |
| **Uso de `std::sort` o librerías externas** | **-30% (Bloque 4 anulado)** | Se evalúa la comprensión y codificación del algoritmo de ordenamiento manual. |
| **Errores de Compilación** | **Descuento en bloque (hasta -30%)** | El código entregado debe compilar bajo el estándar C++17. Se descuenta dentro del bloque afectado; si una corrección sintáctica mínima permite evaluar la lógica desarrollada, podrá reconocerse puntaje parcial. |
| **Permutación de campos sueltos en ordenamiento** | **-15%** | Desincroniza los registros destruyendo la integridad de los datos. |

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
