# Devolución de Examen: 4to Recuperatorio Parcial (Módulo 4: AoS y Ordenamiento)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Jerez, Ulises Joaquín
- **Archivo Entregado:** `Jerez_tema1.cpp`
- **Tema Asignado:** Tema 1 (*Gestión de Inventario de Tienda*)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Condición Final de la Cursada:** **REGULAR**
- **Estado de Compilación:** Compila correctamente bajo C++17.
- **Calificación Final Módulo 4:** **9 (Nueve) — EXCELENTE (93% / 100%)** [Lab C++: 68.0/75 + Escrita Papel: 25/25]

---

Hola **Joaquín**, a continuación te comparto la devolución definitiva de tu examen de Módulo 4. Tu **calificación final es de 93 / 100 (Nota UCSE: 9 - Excelente)**, compuesta por un desempeño muy sólido de **68.0 / 75 puntos (90.7%) en el laboratorio C++** y **25 / 25 puntos (100%) en la evaluación escrita en papel A4**, habiendo completado con total rigor la traza de Selección Directa.

Sobresaliste en la declaración de la estructura `ProductoTienda`, en la inserción con *Right-Shift* y unicidad de clave (20/20%), y en el algoritmo de **Burbuja Mejorada** con corte por bandera booleana e intercambio por referencia (30/30%). Además, modularizaste la derivación de categorías y precios en una función auxiliar muy prolija (`calcularproductos`).  
El único punto donde se concentraron los descuentos fue en la función `modificarProducto`, donde alteraste la firma agregando un parámetro adicional, invertiste la condición de validación rechazando valores válidos y realizaste una auto-asignación redundante.

---

## 📊 Calificación Final y Resumen de Evaluación

| Bloque Evaluativo (75% C++) | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **Bloque 1: Definición de Struct AoS** | 10% | **10.0%** | **Excelente:** Declaró los 6 campos solicitados con tipos primitivos y orden exacto para inicialización directa. |
| **Bloque 2: Inserción Posicional (*Right-Shift*)** | 20% | **20.0%** | **Excelente:** Límites verificados, reutiliza `buscarPorCodigo` para unicidad, corrimiento hacia la derecha perfecto e incremento de `tam++`. |
| **Bloque 3: Modificación *in-place* (PK Inmutable)** | 15% | **8.0%** | Reutiliza búsqueda y mantiene la PK. Descuento por alterar la cabecera (parámetro extra `codMod`), condición de validación invertida y auto-asignación (`arr[pos].stock = arr[pos].stock`). |
| **Bloque 4: Burbuja Mejorada e Intercambio** | 30% | **30.0%** | **Excelente:** Algoritmo Burbuja Mejorada completo, bandera de corte anticipado, criterio ascendente por `precioBase` y permutación por referencia con `intercambiar`. |
| **SUBTOTAL LABORATORIO C++** | **75%** | **68.0 / 75 pts** | **Desempeño técnico sobresaliente en C++ (90.7%).** |
| **Instancia Escrita Individual (Papel A4)** | 25% | **25.0% (25 / 25)** | **Sobresaliente:** Traza paso a paso de Selección Directa Ascendente ($N=5$) resuelta con precisión matemática. |
| **TOTAL FINAL MÓDULO 4** | **100%** | **93.0% (Nota UCSE: 9)** | **Aprobado con Calificación Excelente (rango 92 - 95%).** |

---

## 🔍 Desglose Técnico por Criterio

### Bloque 1: Declaración de Struct `ProductoTienda` (10.0% / 10%)
* ✅ **Logrado:**
  - Declaración perfecta de los 6 miembros primitivos (`Jerez_tema1.cpp`, L11-19).

### Bloque 2: Inserción con Unicidad y Right-Shift (`insertarProducto`) (20.0% / 20%)
* ✅ **Logrado:**
  - **100% Logrado:** Manejo impecable de límites, clave única mediante `buscarPorCodigo`, corrimiento y alta (`Jerez_tema1.cpp`, L195-207):
    ```cpp
    bool insertarProducto(ProductoTienda arr[], int &tam, int capacidad, int pos,  const ProductoTienda &nuevo) {
        int existe = buscarPorCodigo(arr, tam, nuevo.codigo);
        if (tam >= CAPACIDAD || pos < 0 || pos > tam || existe != -1 ) {
            return false ;
        }
        for (int i = tam; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = nuevo;
        tam++;
        return true;
    }
    ```

### Bloque 3: Modificación in-place con Clave Primaria Inmutable (`modificarProducto`) (8.0% / 15%)
* ✅ **Logrado:**
  - Reutilizaste `buscarPorCodigo` para localizar el registro.
  - Mantuviste inalterable la clave primaria `codigo`.
  - Recalculaste los valores derivados mediante `calcularproductos(arr[pos])`.
* ⚠️ **A mejorar (-7%):**
  - **Firma alterada, condición invertida y auto-asignación (`Jerez_tema1.cpp`, L210-223):**  
    Modificaste el contrato provisto agregando `int codMod` en lugar de leer el código desde `actualizado.codigo`. Además, la condición `if (actualizado.stock >= 0 || actualizado.precioBase > 0.0) return false;` está invertida (aborta si los datos son válidos), y asignaste el valor contra sí mismo en vez de tomarlo de `actualizado`:
    ```cpp
    // Líneas 210-220
    bool modificarProducto(ProductoTienda arr[], int tam, int codMod, const ProductoTienda &actualizado) { // Firma modificada
        if (actualizado.stock >= 0 || actualizado.precioBase > 0.0) { // Condición invertida: ¡rechaza datos válidos!
            return false ;
        }
        int pos = buscarPorCodigo(arr, tam, codMod);
        if (pos != -1) {
            arr[pos].stock = arr[pos].stock ;           // ¡Auto-asignación! Debió ser: arr[pos].stock = actualizado.stock;
            arr[pos].precioBase = arr[pos].precioBase; // ¡Auto-asignación! Debió ser: arr[pos].precioBase = actualizado.precioBase;
            calcularproductos(arr[pos]);
            return true ;
        }
        return false ;
    }
    ```

### Bloque 4: Ordenamiento Burbuja e Intercambio (`ordenarPorPrecioBaseBurbujaAsc`) (30.0% / 30%)
* ✅ **Logrado:**
  - **100% Logrado:** `intercambiar` canónico por referencia y algoritmo de Burbuja Mejorada ascendente con bandera `hubointercambio` y reducción del rango interno `tam - 1 - i` (`Jerez_tema1.cpp`, L225-245).

---

## 💡 Recomendaciones de Mejora

1. **Respeta la firma exacta provista en la consigna:**  
   El prototipo original es `bool modificarProducto(ProductoTienda arr[], int tam, const ProductoTienda &actualizado);`. El código que identifica al producto ya viene adentro del struct (`actualizado.codigo`).
2. **Cuidado con las condiciones de rechazo:**  
   Para validar que el stock sea no negativo y el precio mayor a cero, debes rechazar si alguna de las dos es inválida:
   ```cpp
   if (actualizado.stock < 0 || actualizado.precioBase <= 0.0) {
       return false; // Rechaza datos inválidos
   }
   ```
3. **Asigna los datos del registro entrante:**  
   Recuerda escribir `arr[pos].stock = actualizado.stock;` en lugar de asignar la celda a sí misma.

---

## 🎓 Condición Final de la Cursada y Cierre de Ciclo Lectivo 2026

- **Condición Académica Definitiva:** **REGULAR**
- **Coloquio Teórico:** 0 (Acreditación por examen práctico / instancia regularizadora)
- **Situación en Actas:** Materia Regularizada (Habilitado/a para Examen Final)

> [!TIP]
> ### 📘 ¡Felicitaciones por la Regularización de la Asignatura!
> Has alcanzado formalmente la condición de alumno **REGULAR** en la cátedra de **Algoritmos y Programación (Ciclo Lectivo 2026)**. Esto te otorga el derecho académico a presentarte a rendir el **Examen Final Regular** en cualquiera de las mesas ordinarias habilitadas por la universidad (Diciembre 2026, Febrero-Marzo 2027 o turnos subsiguientes dentro del período de regularidad reglamentario).
>
> **Recomendaciones para Preparar el Examen Final:**
> 1. **Eje Práctico (Laboratorio C++):** Practicar de forma intensiva la arquitectura de Arreglos de Estructuras (*Array of Structs - AoS*), asegurando la implementación fluida de:
>    - Búsqueda secuencial con salida anticipada.
>    - Alta posicional (*Right-Shift*) con preservación de unicidad de clave primaria.
>    - Baja física (*Shift-Left*) compactando el arreglo contiguo y liberando cupo.
>    - Ordenamiento por método de Burbuja Mejorada (con bandera booleana) e intercambio completo de registros por referencia.
> 2. **Eje Teórico y Trazas en Papel:** Ejercitar la resolución manual paso a paso de ordenamientos elementales (Selección Directa e Inserción Directa) sobre vectores numéricos ($N=5$).
> 3. ¡Excelente esfuerzo durante el cuatrimestre y muchos éxitos en el examen final!
