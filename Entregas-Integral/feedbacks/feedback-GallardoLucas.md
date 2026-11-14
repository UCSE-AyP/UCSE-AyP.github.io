# Devolución de Examen: 4to Recuperatorio Parcial (Módulo 4: AoS y Ordenamiento)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Gallardo, Lucas Octavio
- **Archivo Entregado:** `LucasOctavioGallardo-Tema2Recuperatorio.cpp`
- **Tema Asignado:** Tema 2 (*Sistema de Gestión Hotelera*)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Condición Final de la Cursada:** **PROMOCIONADO**
- **Estado de Compilación:** Compilación impecable y limpia bajo C++17.
- **Calificación Final Módulo 4:** **10 (Diez) — SOBRESALIENTE (97% / 100%)** [Lab C++: 72.0/75 + Escrita Papel: 25/25]

---

Hola **Lucas**, a continuación te comparto la devolución definitiva de tu examen de Módulo 4. Tu **calificación final es de 97 / 100 (Nota UCSE: 10 - Sobresaliente)**, compuesta por un rendimiento extraordinario de **72.0 / 75 puntos (96.0%) en el laboratorio de programación C++** y **25 / 25 puntos (100%) en la evaluación escrita en papel A4**, habiendo resuelto de manera impecable la traza manual de ordenamiento por Inserción Directa.

Tu solución demostró un estándar profesional en todas las dimensiones requeridas: tipado estricto en el struct `ReservaHotel`, validaciones exhaustivas de dominio en la inserción con *Right-Shift* impecable, algoritmo de **Burbuja Mejorada** optimizado con bandera booleana e intercambio completo de registros por referencia, y una integración limpia y robusta en el menú de `main()`. El único detalle mínimo observado fue la omisión de actualizar el campo `tipo` dentro de `modificarReserva`.

---

## 📊 Calificación Final y Resumen de Evaluación

| Bloque Evaluativo (75% C++) | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **Bloque 1: Definición de Struct AoS** | 10% | **10.0%** | **Excelente:** Struct `ReservaHotel` definido con tipos primitivos exactos y orden canónico. |
| **Bloque 2: Inserción Posicional (*Right-Shift*)** | 20% | **20.0%** | **Excelente:** Control de capacidad, límites de índice, unicidad con `buscarPorHabitacion`, validación de dominio, corrimiento a la derecha y `tam++`. |
| **Bloque 3: Modificación *in-place* (PK Inmutable)** | 15% | **12.0%** | **Muy Bueno:** Localiza con búsqueda, mantiene inmutable la PK y recalcula importes derivados. Omitió reasignar el campo secundario `tipo` (`arr[pos].tipo = actualizada.tipo;`). |
| **Bloque 4: Burbuja Mejorada e Intercambio** | 30% | **30.0%** | **Excelente:** Algoritmo Burbuja Mejorada descendente con bandera `huboIntercambio`, reducción de pasadas e intercambio completo por referencia. |
| **SUBTOTAL LABORATORIO C++** | **75%** | **72.0 / 75 pts** | **Desempeño técnico sobresaliente (96.0% de efectividad).** |
| **Instancia Escrita Individual (Papel A4)** | 25% | **25.0% (25 / 25)** | **Sobresaliente:** Traza paso a paso de Inserción Directa Descendente ($N=5$) resuelta con total exactitud algorítmica. |
| **TOTAL FINAL MÓDULO 4** | **100%** | **97.0% (Nota UCSE: 10)** | **Aprobado con Calificación Sobresaliente (rango 96 - 100%).** |

---

## 🔍 Desglose Técnico por Criterio

### Bloque 1: Declaración de Struct `ReservaHotel` (10.0% / 10%)
* ✅ **Logrado:**
  - **100% Logrado:** Tipado perfecto con tipos primitivos (`LucasOctavioGallardo-Tema2Recuperatorio.cpp`, L11-19).

### Bloque 2: Inserción con Unicidad y Right-Shift (`insertarReserva`) (20.0% / 20%)
* ✅ **Logrado:**
  - **100% Logrado:** Validación exhaustiva de límites físicos, clave primaria única mediante `buscarPorHabitacion`, recálculo de campos derivados y corrimiento hacia la derecha estricto (`LucasOctavioGallardo-Tema2Recuperatorio.cpp`, L266-280):
    ```cpp
    bool insertarReserva(ReservaHotel arr[], int &tam, int capacidad, int pos, const ReservaHotel &nueva) {
        int existe = buscarPorHabitacion(arr,tam,nueva.nroHabitacion);
        if (tam >= capacidad || pos < 0 || pos > tam || existe != -1 || nueva.nroHabitacion <= 0 || nueva.noches <= 0 || nueva.tipo != 'S' && nueva.tipo != 'D'
            && nueva.tipo != 'T' || nueva.precioNoche <= 0) {
            return false;
        }
        ReservaHotel reservaHotel = nueva;
        calcularDatos(reservaHotel);
        for (int i = tam; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = reservaHotel;
        tam++;
        return true;
    }
    ```

### Bloque 3: Modificación in-place con Clave Primaria Inmutable (`modificarReserva`) (12.0% / 15%)
* ✅ **Logrado:**
  - Localizó la posición con `buscarPorHabitacion`.
  - Mantuvo la clave primaria inmutable y recalculó `importeTotal` mediante `calcularDatos`.
* ⚠️ **A mejorar (-3%):**
  - **Omisión de actualización del tipo de habitación (`LucasOctavioGallardo-Tema2Recuperatorio.cpp`, L286-293):**  
    Actualizaste `noches`, `precioNoche` y `confirmada`, pero olvidaste asignar `arr[pos].tipo = actualizada.tipo;`. Esto hace que si un huésped cambia su habitación de Simple a Doble, el tipo anterior permanece guardado:
    ```cpp
    // Líneas 286-293
    if (pos!=-1) {
        arr[pos].noches = actualizada.noches;
        arr[pos].precioNoche = actualizada.precioNoche;
        arr[pos].nroHabitacion= actualizada.nroHabitacion; // Redundante pero seguro
        arr[pos].confirmada = actualizada.confirmada;
        // ¡Faltó: arr[pos].tipo = actualizada.tipo;!
        calcularDatos(arr[pos]);
        return true;
    }
    ```

### Bloque 4: Burbuja Mejorada e Intercambio (`ordenarPorImporteBurbujaDesc`) (30.0% / 30%)
* ✅ **Logrado:**
  - **100% Logrado:** Implementación perfecta de Burbuja Mejorada descendente por `importeTotal` con bandera y función `intercambiar` por referencia (`LucasOctavioGallardo-Tema2Recuperatorio.cpp`, L296-316).

---

## 💡 Recomendaciones de Mejora

1. **Checklist completo de campos en modificación:**  
   Al programar la actualización de un registro, repasa miembro por miembro la estructura para verificar que ningún atributo secundario (`tipo`) quede sin actualizar.
2. ¡Felicitaciones por la excelente calidad algorítmica y prolijidad demostradas en tu entrega!

---

## 🎓 Condición Final de la Cursada y Cierre de Ciclo Lectivo 2026

- **Condición Académica Definitiva:** **PROMOCIONADO**
- **Calificación en Coloquio Teórico:** **67 / 100**
- **Nota Definitiva de Promoción:** **9 (Nueve)** — *Sobresaliente*

> [!IMPORTANT]
> ### 🎉 ¡Felicitaciones por la Promoción Directa!
> Has acreditado formalmente todos los módulos prácticos y teóricos requeridos por la cátedra de **Algoritmos y Programación (Ciclo 2026)**. Tu calificación final asentada en las actas oficiales de examen es **9 (Nueve)**, quedando formalmente **eximido de rendir examen final**.
>
> **Próximos Pasos y Recomendaciones:**
> 1. Tu condición de promoción directa ya ha sido registrada para el cierre de actas ante la Sección Alumnos de la UCSE DASS.
> 2. Cuentas con una base algorítmica y de estructuras de datos excelente para afrontar las materias correlativas del próximo ciclo (*Programación Orientada a Objetos*, *Programación II* y *Estructuras de Datos*).
> 3. ¡Muchas felicitaciones por tu gran dedicación, prolijidad y excelencia técnica a lo largo de todo el año!
