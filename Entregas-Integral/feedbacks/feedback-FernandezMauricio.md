# Devolución de Examen: 4to Recuperatorio Parcial (Módulo 4: AoS y Ordenamiento)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Fernández, Facundo Mauricio
- **Archivo Entregado:** `Fernandez-ReservaHotelera.cpp`
- **Tema Asignado:** Tema 2 (*Sistema de Gestión Hotelera*)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Condición Final de la Cursada:** **REGULAR**
- **Estado de Compilación:** Compila con advertencia por cabecera duplicada de `buscarPorHabitacion`.
- **Calificación Final Módulo 4:** **5 (Cinco) — APROBADO (68% / 100%)** [Lab C++: 68.0/75 + Escrita Papel: 0/25]

---

Hola **Facundo**, a continuación te comparto la devolución consolidada de tu examen de Módulo 4. Tu **calificación final es de 68 / 100 (Nota UCSE: 5 - Aprobado Aceptable)**, producto de un excelente desempeño de **68.0 / 75 puntos (90.7%) en el laboratorio de programación C++** y **0 / 25 puntos (0%) en la evaluación escrita en papel A4** (traza de Inserción Directa no realizada o no entregada).

Demostraste una sólida comprensión de la arquitectura de arreglos de registros (AoS). Declaraste con exactitud la estructura `ReservaHotel`, implementaste una versión impecable de **Burbuja Mejorada** con bandera booleana para corte anticipado intercambiando la estructura completa por referencia, y en la modificación preservaste con total rigurosidad la inmutabilidad de la clave primaria. El único detalle técnico que impidió la calificación perfecta fue un sutil desfasaje de límites (*off-by-one*) en el bucle de desplazamiento a la derecha (*Right-Shift*) al insertar, y una modificación en la firma de la función de búsqueda pre-implementada.

---

## 📊 Calificación Final y Resumen de Evaluación

| Bloque Evaluativo (75% C++) | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **Bloque 1: Definición de Struct AoS** | 10% | **10.0%** | **Excelente:** Declaró los 6 campos solicitados con tipos primitivos exactos y en el orden estricto de la consigna. |
| **Bloque 2: Inserción Posicional (*Right-Shift*)** | 20% | **16.0%** | Verifica capacidad, rango de inserción y reutiliza `buscarPorHabitacion` para unicidad de clave. Detalle *off-by-one* en el corrimiento: `i > pos + 1` frena antes de tiempo y pierde un elemento. |
| **Bloque 3: Modificación *in-place* (PK Inmutable)** | 15% | **14.0%** | **Muy Bueno:** Localiza mediante `buscarPorHabitacion`, mantiene intacta la PK `nroHabitacion` y recalcula el importe total con recargo. |
| **Bloque 4: Burbuja Mejorada e Intercambio** | 30% | **28.0%** | **Excelente:** Algoritmo Burbuja Mejorada con corte temprano por bandera (`huboIntercambio`), comparando en orden descendente y permutando structs completos con `intercambiar`. |
| **SUBTOTAL LABORATORIO C++** | **75%** | **68.0 / 75 pts** | **Desempeño técnico sobresaliente en C++ (90.7%).** |
| **Instancia Escrita Individual (Papel A4)** | 25% | **0.0% (0 / 25)** | Traza manual de Inserción Directa Descendente ($N=5$): no desarrollada o no entregada. |
| **TOTAL FINAL MÓDULO 4** | **100%** | **68.0% (Nota UCSE: 5)** | **Aprobado (Aceptable: rango 68 - 75%).** |

---

## 🔍 Desglose Técnico por Criterio

### Bloque 1: Declaración de Struct `ReservaHotel` (10.0% / 10%)
* ✅ **Logrado:**
  - Declaraste la estructura respetando tipos primitivos exactos y el orden de la tabla (`Fernandez-ReservaHotelera.cpp`, L11-19):
    ```cpp
    struct ReservaHotel {
        int nroHabitacion;
        int noches;
        char tipo;
        double precioNoche;
        double importeTotal;
        bool confirmada;
    };
    ```

### Bloque 2: Inserción con Unicidad y Right-Shift (`insertarReserva`) (16.0% / 20%)
* ✅ **Logrado:**
  - Validaste saturación física (`tam >= capacidad`), límites de posición (`pos < 0 || pos > tam`) y reutilizaste modularmente `buscarPorHabitacion` para garantizar la unicidad del número de habitación.
* ⚠️ **A mejorar (-4%):**
  - **Desfasaje off-by-one en el límite inferior del Right-Shift (`Fernandez-ReservaHotelera.cpp`, L118-120):**  
    Pusiste la condición `i > pos + 1`. Al llegar a `pos + 1`, la condición resulta falsa, por lo que el elemento que estaba en `arr[pos]` nunca se copia a `arr[pos + 1]`. En la siguiente línea haces `arr[pos] = nueva;`, sobreescribiendo y destruyendo el registro que residía originalmente en `pos`:
    ```cpp
    // Líneas 118-122
    for (int i=tam;i>pos+1;--i) { // ¡Debe ser i > pos!
        arr[i]=arr[i-1];
    }
    arr[pos]=nueva; // Si el bucle frenó antes, este paso destruye arr[pos] sin haberlo respaldado
    tam++;
    return true;
    ```

### Bloque 3: Modificación in-place con Clave Primaria Inmutable (`modificarReserva`) (14.0% / 15%)
* ✅ **Logrado:**
  - Reutilizaste `buscarPorHabitacion` para validar existencia.
  - Mantuviste estrictamente inmutable `nroHabitacion` (PK) actualizando únicamente los datos operativos (`noches`, `tipo`, `precioNoche`, `confirmada`) y recalculando el `importeTotal`.
* ⚠️ **A mejorar (-1%):**
  - **Fórmula de recargo con base inflada (`Fernandez-ReservaHotelera.cpp`, L134):**  
    Multiplicaste por `(1.8 + recargo)` en lugar de `(1.0 + recargo)`, inflando el importe base un 80% extra sobre la tarifa calculada.

### Bloque 4: Ordenamiento Burbuja Mejorada (`ordenarPorImporteBurbujaDesc`) (28.0% / 30%)
* ✅ **Logrado:**
  - Implementaste la optimización de corte temprano con la bandera booleana `huboIntercambio`.
  - Ordenaste en sentido descendente estricto (`arr[j].importeTotal < arr[j+1].importeTotal`).
  - Invocaste `intercambiar(arr[j], arr[j+1])` pasando estructuras completas por referencia.
* ⚠️ **A mejorar (-2%):**
  - **Modificación de cabecera en función pre-implementada (`Fernandez-ReservaHotelera.cpp`, L159):**  
    Alteraste la firma de `buscarPorHabitacion` cambiando el último parámetro a referencia `int &nroBuscado` y agregando una lectura `cin` adentro de la primitiva auxiliar, lo que generó una advertencia de compilación por firma duplicada en L170.

---

## 💡 Recomendaciones de Mejora

1. **Asegura el límite del Right-Shift:**  
   Para insertar en `pos`, el corrimiento debe mover el elemento de la celda `pos` hacia la celda `pos + 1`. Por lo tanto, el bucle debe continuar mientras `i > pos`:
   ```cpp
   for (int i = tam; i > pos; --i) {
       arr[i] = arr[i - 1]; // Cuando i = pos + 1, traslada arr[pos] a arr[pos + 1]
   }
   arr[pos] = nueva;
   tam++;
   ```
2. **Respeta los prototipos pre-implementados:**  
   Evita modificar las firmas o agregar interacciones por consola (`cin`) adentro de las primitivas de búsqueda o de cálculo; el ingreso de datos debe gestionarse siempre en el `main()`.

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
