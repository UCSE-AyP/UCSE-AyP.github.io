# Devolución de Examen: 4to Recuperatorio Parcial (Módulo 4: AoS y Ordenamiento)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Velásquez, Hernán
- **Archivo Entregado:** `VELASQUEZ HERNAN Recuperatorio parcial°4.cpp`
- **Tema Asignado:** Tema 1 (*Gestión de Inventario de Tienda*)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Condición Final de la Cursada:** **REGULAR**
- **Estado de Compilación:** Compila limpio bajo C++17.
- **Calificación Final Módulo 4:** **3 (Tres) — INSUFICIENTE (48% / 100%)** [Lab C++: 48.0/75 + Escrita Papel: 0/25]

---

Hola **Hernán**, a continuación te comparto la devolución consolidada de tu examen de Módulo 4. Tu **calificación final es de 48 / 100 (Nota UCSE: 3 - Insuficiente)**, compuesta por **48.0 / 75 puntos (64.0%) en el laboratorio C++** y **0 / 25 puntos (0%) en la evaluación escrita en papel A4** (traza no desarrollada o no entregada). Al no alcanzar el 60% mínimo de acreditación sobre el total del examen, quedas en condición de recuperar el módulo.

Demostraste un manejo muy sólido y prolijo en la declaración de la estructura `ProductoTienda` y en la inserción con desplazamiento a la derecha (*Right-Shift*) y clave única (20/20%). Además, mostraste un gran criterio modular al programar funciones auxiliares para el cálculo de categorías y valores derivados (`calcularcategoria`, `calcularvalorU`, `calcularvalorS`), y programaste correctamente la función `intercambiar` por referencia.  
El factor determinante que redujo tu calificación fue la **omisión total del algoritmo de ordenamiento por Burbuja Mejorada** (dejaste el case 6 del menú vacío y no programaste la función `ordenarPorPrecioBaseBurbujaAsc`), junto con una alteración en la firma de `modificarProducto` al recibir parámetros sueltos en vez de la referencia al struct.

---

## 📊 Calificación Final y Resumen de Evaluación

| Bloque Evaluativo (75% C++) | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **Bloque 1: Definición de Struct AoS** | 10% | **10.0%** | **Excelente:** Estructura declarada con tipos primitivos, campos y orden exactos. |
| **Bloque 2: Inserción Posicional (*Right-Shift*)** | 20% | **20.0%** | **Excelente:** Control de límites, validación de clave única con `buscarPorCodigo`, corrimiento a la derecha, inserción e incremento de `tam++`. |
| **Bloque 3: Modificación *in-place* (PK Inmutable)** | 15% | **12.0%** | Modificación in-place preservando la clave primaria y recalculando campos derivados con funciones auxiliares. Descuento por alterar la cabecera recibiendo parámetros sueltos. |
| **Bloque 4: Burbuja Mejorada e Intercambio** | 30% | **6.0%** | Programó `intercambiar` por referencia correctamente (6 pts). Omitió por completo la implementación del algoritmo de ordenamiento `ordenarPorPrecioBaseBurbujaAsc` (0/24 pts). |
| **SUBTOTAL LABORATORIO C++** | **75%** | **48.0 / 75 pts** | **Aprobado en laboratorio (64.0% de efectividad).** |
| **Instancia Escrita Individual (Papel A4)** | 25% | **0.0% (0 / 25)** | Traza de Selección Directa Ascendente ($N=5$): no desarrollada o no entregada. |
| **TOTAL FINAL MÓDULO 4** | **100%** | **48.0% (Nota UCSE: 3)** | **Insuficiente (Recupera: rango 40 - 59%, mínimo de acreditación 60%).** |

---

## 🔍 Desglose Técnico por Criterio

### Bloque 1: Declaración de Struct `ProductoTienda` (10.0% / 10%)
* ✅ **Logrado:**
  - **100% Logrado:** Tipado primitivo impecable (`VELASQUEZ HERNAN Recuperatorio parcial°4.cpp`, L11-19).

### Bloque 2: Inserción con Unicidad y Right-Shift (`insertarProducto`) (20.0% / 20%)
* ✅ **Logrado:**
  - **100% Logrado:** Algoritmo de libro de texto con guardas, búsqueda de clave y corrimiento a la derecha (`VELASQUEZ HERNAN Recuperatorio parcial°4.cpp`, L150-160):
    ```cpp
    bool insertarProducto(ProductoTienda arr[], int &tam, int capacidad, int pos, const ProductoTienda &nuevo){
        if (tam >= capacidad) return false;
        if (pos < 0 || pos > tam) return false;
        if (buscarPorCodigo(arr,tam,nuevo.codigo) != -1) return false;
        for (int i = tam; i > pos; i--){
            arr[i] = arr[i - 1];
        }
        arr[pos] = nuevo;
        tam++;
        return true;
    }
    ```

### Bloque 3: Modificación in-place con Clave Primaria Inmutable (`modificarProducto`) (12.0% / 15%)
* ✅ **Logrado:**
  - Localizó la posición con `buscarPorCodigo`, mantuvo inmutable la clave primaria `codigo` y recalculó con gran claridad los valores derivados utilizando rutinas auxiliares bien estructuradas.
* ⚠️ **A mejorar (-3%):**
  - **Alteración de los parámetros de la cabecera (`VELASQUEZ HERNAN Recuperatorio parcial°4.cpp`, L161):**  
    En lugar de recibir `const ProductoTienda &actualizado`, desempaquetaste los campos sueltos en la firma:
    ```cpp
    // Línea 161
    bool modificarProducto(ProductoTienda arr[], int tam, int codigo, double precioBase, int stock){ // Firma modificada
    ```

### Bloque 4: Ordenamiento Burbuja e Intercambio (`ordenarPorPrecioBaseBurbujaAsc`) (6.0% / 30%)
* ✅ **Logrado:**
  - Programaste la función `intercambiar` por referencia de manera limpia (L144-149).
* ⚠️ **A mejorar (-24%):**
  - **Función de ordenamiento no implementada (`VELASQUEZ HERNAN Recuperatorio parcial°4.cpp`, L118-120):**  
    El case 6 del menú quedó vacío y no desarrollaste la función `ordenarPorPrecioBaseBurbujaAsc`.

---

## 💡 Recomendaciones de Mejora

1. **Asegura la implementación de los algoritmos de ordenamiento:**  
   Burbuja Mejorada es una de las competencias centrales de la materia. Una plantilla estándar para recordarla es:
   ```cpp
   void ordenarPorPrecioBaseBurbujaAsc(ProductoTienda arr[], int tam) {
       bool huboIntercambio = true;
       for (int i = 0; i < tam - 1 && huboIntercambio; ++i) {
           huboIntercambio = false;
           for (int j = 0; j < tam - 1 - i; ++j) {
               if (arr[j].precioBase > arr[j + 1].precioBase) {
                   intercambiar(arr[j], arr[j + 1]);
                   huboIntercambio = true;
               }
           }
       }
   }
   ```
2. **Respeta los contratos de estructuras completas:**  
   Al modificar o insertar, acostúmbrate a recibir el registro empaquetado (`const ProductoTienda &actualizado`) para mantener la interfaz homogénea.

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
