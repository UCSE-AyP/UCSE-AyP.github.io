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

El código base provisto suministra el esqueleto del menú en `main()` (con el arreglo en RAM precargado y los `case` del `switch` a completar por el estudiante, igual que en el 4to Examen), las rutinas de visualización con `<iomanip>` y las funciones auxiliares ya evaluadas en Módulo 3 (`buscarPor*`, `darDeBaja*` y `calcularPromedio*`). El estudiante debe declarar los campos del `struct` en su orden exacto, conectar las opciones del `switch` y programar las **4 funciones nucleares del Módulo 4**:

### Bloque 1: Definición de Estructura AoS en Tipos Primitivos (10%)
- **Contrato:** `struct ProductoTienda` (Tema 1) / `struct ReservaHotel` (Tema 2).
- **Criterios de Evaluación:**
  - **10% (Completo / Excelente):** Declara los 6 miembros usando exclusivamente tipos primitivos (`int`, `char`, `double`, `bool`), respetando nombres exactos y el **mismo orden de la tabla del enunciado** para compilar con los datos precargados.
  - **5% (Parcial / Básico):** Declara los campos con detalles menores de tipo sin romper la estructura.
  - **0% (Insuficiente):** Desordena miembros rompiendo la inicialización por llaves, usa `string` o vectores paralelos.

### Bloque 2: Alta / Inserción con Unicidad de Clave y Right-Shift (20%)
- **Firma Conceptual:**
  ```cpp
  bool insertarRegistro(T arr[], int &tam, int capacidad, int posicion, const T &nuevo);
  ```
- **Criterios de Evaluación:**
  - **20% (Completo / Excelente):** Control riguroso de límites físicos (`tam < capacidad` y `posicion` dentro de `[0 .. tam]`). Reutiliza la función provista `buscarPor*` para verificar unicidad de clave (`16%` funcionamiento correcto + `4%` reutilización modular). Desplazamiento contiguo a la derecha (*Right-Shift*), asignación de `nuevo` en `arr[posicion]` e incremento `tam++`. Retorno `true` ante éxito o `false` ante rechazo.
  - **16% (Aceptable / Funcional):** Inserta desplazando correctamente y evita duplicados con búsqueda lineal integrada in-line.
  - **8% (Básico):** Inserta pero no valida unicidad de clave o comete errores de límites al desplazar.
  - **0% (Insuficiente):** Sobrescribe sin desplazar, no incrementa `tam` o desborda `capacidad`.

### Bloque 3: Modificación in-place con Clave Primaria Inmutable (15%)
- **Firma Conceptual:** `bool modificarRegistro(T arr[], int tam, const T &actualizado);`
- **Criterios de Evaluación:**
  - **15% (Completo / Excelente):** Reutiliza la función provista `buscarPor*` (`12%` funcionamiento + `3%` modularidad). Mutación *in-place* sobre la celda hallada actualizando los atributos secundarios y derivados (calculados en el `switch` o dentro de la función), manteniendo **estrictamente inmutable la clave primaria**. Retorno `true` o `false`.
  - **12% (Aceptable / Funcional):** Modifica correctamente usando búsqueda in-line preservando la clave primaria.
  - **0% (Insuficiente):** Altera la clave primaria o no actualiza los datos en el arreglo.

### Bloque 4: Ordenamiento Burbuja Mejorada con Intercambio Completo de Estructuras (30%)
- **Firmas Conceptuales:** `void intercambiar(T &a, T &b);` y `void ordenarBurbuja(T arr[], int tam);`
- **Criterios de Evaluación:**
  - **30% (Completo / Excelente):** **Burbuja Mejorada** con bandera booleana `huboIntercambio` para corte anticipado. Criterio estricto: Tema 1 intercambia solo cuando `arr[j].precioBase > arr[j + 1].precioBase`; Tema 2 solo cuando `arr[j].importeTotal < arr[j + 1].importeTotal`. **Intercambio completo de estructuras** invocando `intercambiar(arr[j], arr[j + 1])`.
  - **16% (Aceptable / Funcional):** Implementa Burbuja clásica sin bandera de corte o realiza swap manual sin invocar `intercambiar()`.
  - **0% (Insuficiente):** No ordena, permuta campos sueltos o utiliza `std::sort`.

---

## 3. Desglose Detallado: Instancia Escrita Individual (25% Papel)

Se evalúa la comprensión algorítmica mediante la traza manual paso a paso en hoja A4 entregada al inicio de la prueba:
- **Tema 1: Selección Directa Ascendente (25 pts / 4 pasadas de 6.25 pts c/u):**
  Subarreglo analizado, detección del menor, swap efectuado y prefijo ordenado.
- **Tema 2: Inserción Directa Descendente (25 pts / 4 pasadas de 6.25 pts c/u):**
  Elemento clave (`aux`), comparaciones, desplazamientos a la derecha, inserción en hueco y prefijo ordenado.

---

## 4. Penalizaciones y Criterios Disciplinares

| Falta Técnica | Penalización | Justificación Pedagógica |
| :--- | :---: | :--- |
| **Uso de Vectores Paralelos** | **-50% del examen** | Violación directa de la arquitectura del Módulo 4 (Array of Structs). |
| **Uso de `std::sort` o librerías externas** | **-30% (Bloque 4 anulado)** | Se evalúa la codificación manual del algoritmo de ordenamiento. |
| **Errores de Compilación** | **Descuento en bloque (hasta -30%)** | El código entregado debe compilar bajo el estándar C++17. |
| **Permutación de campos sueltos en ordenamiento** | **-15%** | Desincroniza los registros destruyendo la integridad de los datos. |

> [!IMPORTANT]
> **Regla de No Acumulación:** Las penalizaciones no se acumularán cuando sancionen el mismo defecto ya considerado en el bloque correspondiente. La calificación final no podrá ser inferior a 0%.

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
