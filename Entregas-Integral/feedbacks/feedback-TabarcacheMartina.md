# Devolución de Examen: 4to Recuperatorio Parcial (Módulo 4: AoS y Ordenamiento)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Tabarcache, Martina
- **Archivo Entregado:** `TABARCACHE_MARTINA_TEMA1_ M4.cpp`
- **Tema Asignado:** Tema 1 (*Gestión de Inventario de Tienda*)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Estado de Compilación:** Compilación impecable y limpia bajo C++17.
- **Calificación Final Módulo 4:** **5 (Cinco) — APROBADO (75% / 100%)** [Lab C++: 75.0/75 + Escrita Papel: 0/25]

---

Hola **Martina**, a continuación te comparto la devolución consolidada de tu examen de Módulo 4. Tu **calificación final es de 75 / 100 (Nota UCSE: 5 - Aprobado Aceptable)**, compuesta por un desempeño **perfecto de 75.0 / 75 puntos (100%) en el laboratorio de programación C++** y **0 / 25 puntos (0%) en la evaluación escrita en papel A4** (traza de Selección Directa no resuelta o no entregada).

Tu código representa el estándar ideal buscado por la cátedra para el Módulo 4:
- Definición rigurosa de la estructura `ProductoTienda` utilizando únicamente tipos primitivos y respetando el orden exacto para la compatibilidad con el código base.
- Inserción posicional (*Right-Shift*) impecable, con control de capacidad física, verificación de unicidad de clave mediante `buscarPorCodigo` y corrimiento contiguo seguro.
- Modificación *in-place* que preserva con total rigurosidad la inmutabilidad de la clave primaria (`codigo`).
- Algoritmo de **Burbuja Mejorada** completamente optimizado con bandera booleana para corte temprano e intercambio por referencia de la estructura completa.
- Excelente conexión e interactividad en cada uno de los casos del `switch` en `main()`.

---

## 📊 Calificación Final y Resumen de Evaluación

| Bloque Evaluativo (75% C++) | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **Bloque 1: Definición de Struct AoS** | 10% | **10.0%** | **Impecable:** Struct `ProductoTienda` declarado con tipos primitivos, nombres y orden idénticos a la consigna. |
| **Bloque 2: Inserción Posicional (*Right-Shift*)** | 20% | **20.0%** | **Impecable:** Protección de límites, unicidad mediante `buscarPorCodigo`, corrimiento a la derecha contiguo y `tam++`. |
| **Bloque 3: Modificación *in-place* (PK Inmutable)** | 15% | **15.0%** | **Impecable:** Reutilización modular, clave primaria `codigo` estrictamente inmutable y actualización atómica de campos. |
| **Bloque 4: Burbuja Mejorada e Intercambio** | 30% | **30.0%** | **Impecable:** Burbuja Mejorada ascendente con bandera `huboIntercambio`, pasadas dinámicas e intercambio completo por referencia. |
| **SUBTOTAL LABORATORIO C++** | **75%** | **75.0 / 75 pts** | **Desempeño técnico perfecto (100% de efectividad).** |
| **Instancia Escrita Individual (Papel A4)** | 25% | **0.0% (0 / 25)** | Traza manual de Selección Directa Ascendente sobre vector N=5: no desarrollada o no entregada. |
| **TOTAL FINAL MÓDULO 4** | **100%** | **75.0% (Nota UCSE: 5)** | **Aprobado (Aceptable: rango 68 - 75%).** |

---

## 🔍 Desglose Técnico por Criterio

### Bloque 1: Declaración de Struct `ProductoTienda` (10.0% / 10%)
* ✅ **Logrado:**
  - **100% Logrado:** Tipado primitivo riguroso (`TABARCACHE_MARTINA_TEMA1_ M4.cpp`, L12-19):
    ```cpp
    struct ProductoTienda {
        int codigo;
        int stock;
        char categoria;
        double precioBase;
        double valorUnitario;
        double valorStock;
    };
    ```

### Bloque 2: Inserción con Unicidad y Right-Shift (`insertarProducto`) (20.0% / 20%)
* ✅ **Logrado:**
  - **100% Logrado:** Verificación exhaustiva de precondiciones y desplazamiento a la derecha impecable (`TABARCACHE_MARTINA_TEMA1_ M4.cpp`, L205-218):
    ```cpp
    bool insertarProducto(ProductoTienda arr[], int &tam, int capacidad, int pos, const ProductoTienda &nuevo) {
        if (tam >= capacidad || pos < 0 || pos > tam) {
            return false;
        }
        if (buscarPorCodigo(arr, tam, nuevo.codigo) != -1) {
            return false;
        }
        for (int i = tam; i > pos; --i) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = nuevo;
        tam++;
        return true;
    }
    ```

### Bloque 3: Modificación in-place con Clave Primaria Inmutable (`modificarProducto`) (15.0% / 15%)
* ✅ **Logrado:**
  - **100% Logrado:** Búsqueda previa, clave primaria inalterable y mutación de atributos secundarios (`TABARCACHE_MARTINA_TEMA1_ M4.cpp`, L220-233):
    ```cpp
    bool modificarProducto(ProductoTienda arr[], int tam, const ProductoTienda &actualizado) {
        int pos = buscarPorCodigo(arr, tam, actualizado.codigo);
        if (pos == -1) {
            return false;
        }
        arr[pos].stock = actualizado.stock;
        arr[pos].categoria = actualizado.categoria;
        arr[pos].precioBase = actualizado.precioBase;
        arr[pos].valorUnitario = actualizado.valorUnitario;
        arr[pos].valorStock = actualizado.valorStock;
        return true;
    }
    ```

### Bloque 4: Burbuja Mejorada e Intercambio (`ordenarPorPrecioBaseBurbujaAsc`) (30.0% / 30%)
* ✅ **Logrado:**
  - **100% Logrado:** Función `intercambiar` por referencia e implementación canónica de Burbuja Mejorada con corte temprano por bandera (`TABARCACHE_MARTINA_TEMA1_ M4.cpp`, L199-203 y L235-246):
    ```cpp
    void intercambiar(ProductoTienda &a, ProductoTienda &b) {
        ProductoTienda aux = a;
        a = b;
        b = aux;
    }

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

---

## 💡 Recomendaciones de Mejora

1. ¡Continúa con este sobresaliente nivel de rigurosidad, buenas prácticas y pulcritud algorítmica en tus futuros proyectos de desarrollo de software!
