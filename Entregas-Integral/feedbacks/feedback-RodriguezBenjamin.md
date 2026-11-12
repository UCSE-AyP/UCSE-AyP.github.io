# Devolución de Examen: Recuperatorio Integral (Módulos 3 y 4)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Rodríguez, Benjamín
- **Archivos Entregados:** `Parcial 3 tema 2 Rodriguez Benjamin.cpp` (Módulo 3, Tema 2) y `examen 4 unudad 2 Rodriguez Benjamin.cpp` (Módulo 4, Tema 2)
- **Tema Asignado:** Tema 2 (*Parque Eólico Rawson* en M3 / *Sistema de Reservas Hoteleras* en M4)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Estado de Compilación:** Módulo 3 compila con advertencias; Módulo 4 no compila por typos sintácticos (`reurn`, `cout` sin operador) y colisión de nombres de miembros en el struct.
- **Calificación Global:** **M3: 3 (Insuficiente - 48%) / M4: 2 (No Aprobado - 24% [Lab: 24/75 + Escrita: 0/25])**

---

Hola **Benjamín**, a continuación te comparto la devolución detallada de tu examen integral. Tu desempeño arrojó un **48% / 100% en el Módulo 3 (Nota UCSE: 3 - Insuficiente)**, quedando en condición de recuperar dicho parcial, y **24 / 100 puntos (24.0% - Nota UCSE: 2 - No Aprobado) en el Módulo 4**, producto de **24.0 / 75 puntos en el laboratorio C++** y **0 / 25 puntos (0%) en la instancia escrita en papel A4** (no registrada o no entregada).

En el **Módulo 3** lograste implementar una búsqueda secuencial excelente (15/15%) y una carga estructurada con validación mediante `do-while`. No obstante, la baja física no realiza el corrimiento *Shift-Left* (dejaste una expresión sin efecto `arr[tam - pos];`), en el listado omitiste mostrar los valores de los aerogeneradores (solo mostraste la cantidad que superaba el umbral) y eliminaste por completo la opción de estadísticas.  
En el **Módulo 4** mostraste muy buena iniciativa completando la integración en el menú de `main()`, pero nombraste al campo `precioTotal` en vez de `importeTotal` rompiendo la compatibilidad con el resto del código base; en la inserción invertiste la condición de existencia de clave y planteaste un bucle inalcanzable; en la modificación sobreescribiste la clave primaria pidiendo datos por teclado; y en el ordenamiento intercambiaste un campo numérico suelto en vez de permutar la estructura completa.

---

## 📊 1. Resumen de Calificación — Módulo 3: Arreglos en C++ (Tema 2)

| Criterio Evaluado | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **1. Carga Controlada (`RegistrarAerogenerador`)** | 25% | **15%** | Valida el rango numérico con `do-while` e incrementa `tam++`. Condición lógica defectuosa en el ciclo: `tam == capacidad` permite registrar cuando el arreglo está lleno en lugar de cortar. |
| **2. Recorrido y Filtro (`ListarAerogeneradores`)** | 20% | **10%** | Protege `tam == 0` y cuenta los que superan el umbral, pero omitió por completo imprimir los datos individuales de cada aerogenerador. |
| **3. Búsqueda Secuencial (`BuscarPotencia`)** | 15% | **15%** | **Excelente:** Recorrido secuencial con salida temprana y valor centinela `-1`. |
| **4. Eliminación Física (*Shift-Left*) (`DarDeBajaAerogenerador`)** | 25% | **8%** | Reutiliza `BuscarPotencia` correctamente, pero en lugar de desplazar con un bucle puso una sentencia sin efecto `arr[tam - pos]; tam--;`. |
| **5. Estadísticas con Guarda (`CalcularEstadisticas`)** | 15% | **0%** | Omitió por completo la implementación y eliminó la opción del switch en `main()`. |
| **SUBTOTAL MÓDULO 3** | **100%** | **48%** | **Rendimiento insuficiente en arreglos unidimensionales.** |

---

## 🔍 Desglose Técnico por Criterio — Módulo 3

### 1. Carga Controlada (`RegistrarAerogenerador`) (15% / 25%)
* ✅ **Logrado:**
  - Validaste el rango de potencia `[50.0, 600.0]` con ciclo `do-while` y actualizaste `tam++`.
* ⚠️ **A mejorar (-10%):**
  - **Condición de corte invertida en capacidad (`Parcial 3 tema 2 Rodriguez Benjamin.cpp`, L81-83):**  
    Pusiste `tam == capacidad` con operador `||` en el `while`. Esto significa que si el arreglo está lleno, la condición se vuelve verdadera y permite seguir agregando datos fuera de memoria:
    ```cpp
    // Líneas 81-83
    while(continuar == 's' || continuar == 'S' || tam == capacidad){ // ¡Error grave! Debe ser: && tam < capacidad
    ```

### 2. Recorrido y Filtro (`ListarAerogeneradores`) (10% / 20%)
* ✅ **Logrado:**
  - Contabilizaste correctamente los elementos con potencia mayor a 350.0 kW.
* ⚠️ **A mejorar (-10%):**
  - **No imprime los elementos del arreglo (`Parcial 3 tema 2 Rodriguez Benjamin.cpp`, L109-117):**  
    Recorres el arreglo solo para contar, pero la función debe listar en pantalla cada aerogenerador con su índice y valor:
    ```cpp
    // Líneas 109-114
    for(int i = 0 ; i < tam; i++){
        if (arr[i] > umbralOptimo){
            destacado++;
        }
        // ¡Falta cout << "[" << i << "] Potencia: " << arr[i] << " kW" << endl;!
    }
    ```

### 3. Búsqueda Secuencial (`BuscarPotencia`) (15% / 15%)
* ✅ **Logrado:**
  - **100% Logrado:** Búsqueda limpia y con salida anticipada.

### 4. Eliminación Física Shift-Left (`DarDeBajaAerogenerador`) (8% / 25%)
* ✅ **Logrado:**
  - Reutilizaste correctamente `BuscarPotencia` para localizar la posición a eliminar.
* ⚠️ **A mejorar (-17%):**
  - **Sentencia sin efecto en lugar de bucle de corrimiento (`Parcial 3 tema 2 Rodriguez Benjamin.cpp`, L139-143):**  
    Pusiste `arr[tam - pos];`, que es una expresión que calcula un valor pero no modifica el arreglo. No hay corrimiento hacia la izquierda:
    ```cpp
    // Líneas 139-143
    } else{
        arr[tam - pos]; // ¡Sentencia sin efecto! No desplaza nada
        tam--; 
        cout << "Archivo eleminado [CORRECTAMENTE]" << endl;
    }
    ```

### 5. Estadísticas con Guarda (`CalcularEstadisticas`) (0% / 15%)
* ⚠️ **A mejorar (-15%):**
  - No implementada.

---

## 📊 2. Resumen de Calificación — Módulo 4: AoS y Ordenamiento (Tema 2)

| Bloque Evaluativo (75% C++) | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **Bloque 1: Struct Primitivo AoS** | 10% | **7.0%** | Nombró el campo como `precioTotal` en lugar de `importeTotal`, rompiendo la compatibilidad con las funciones auxiliares de la plantilla. |
| **Bloque 2: Inserción Posicional (*Right-Shift*)** | 20% | **6.0%** | Typo `reurn false;`. Condición invertida al validar existencia (`!= -1`). Bucle con condición inalcanzable (`for (int i=tam; i<pos; i--)`). |
| **Bloque 3: Modificación *in-place* (PK Inmutable)** | 15% | **5.0%** | Pide datos por teclado adentro de la función en lugar de usar el parámetro `actualizada`. Destruye la clave primaria `nroHabitacion`. |
| **Bloque 4: Burbuja Mejorada e Intercambio** | 30% | **6.0%** | `intercambiar` con errores sintácticos (`reserva = aux`). En el ordenamiento intercambió el campo suelto `precioTotal` violando la integridad del struct. |
| **SUBTOTAL LABORATORIO C++** | **75%** | **24.0 / 75 pts** | **Rendimiento técnico del 32.0% en C++.** |
| **Instancia Escrita Individual (Papel A4)** | 25% | **0.0% (0 / 25)** | Traza de Inserción Directa Descendente en papel A4: no registrada o no entregada. |
| **TOTAL MÓDULO 4** | **100%** | **24.0% (Nota UCSE: 2)** | **No Aprobado (rango 0 - 39%).** |

---

## 🔍 Desglose Técnico por Criterio — Módulo 4

### Bloque 1: Struct `ReservaHotel` (7.0% / 10%)
* ⚠️ **A mejorar (-3%):**
  - **Discrepancia en el nombre del campo total (`examen 4 unudad 2 Rodriguez Benjamin.cpp`, L11-18):**  
    El enunciado y las rutinas provistas (`mostrarTabla`, `calcularPromedioFacturacion`) utilizan `importeTotal`. Al renombrarlo como `precioTotal`, el código no compila al acceder a dicho campo:
    ```cpp
    // Línea 16
    double precioTotal; // Debe ser: double importeTotal;
    ```

### Bloque 2: Inserción con Unicidad y Right-Shift (`insertarReserva`) (6.0% / 20%)
* ⚠️ **A mejorar (-14%):**
  - **Lógica invertida y bucle inalcanzable (`examen 4 unudad 2 Rodriguez Benjamin.cpp`, L165-183):**  
    Error tipográfico `reurn false;`. Buscas `pos` en vez del número de habitación y solo intentas insertar si la clave YA EXISTÍA (`!= -1`). Además, el bucle `for (int i = tam; i < pos; i--)` inicia con `i = tam` y como `tam >= pos`, la condición `i < pos` es falsa de entrada:
    ```cpp
    // Líneas 168-177
    reurn false; // Error de compilación: typo en 'return'
    
    if (buscarPorHabitacion(arr,tam,pos) != -1){ // ¡Debe ser == -1 para insertar si NO existe!
        for (int i = tam ; i < pos; i--){ // ¡Condición inalcanzable! Debe ser i > pos
            arr[i] = arr[pos + 1];
            arr[pos] = nueva;
            tam++ // Falta punto y coma
            return true; // Retorna en la 1ra iteración adentro del for
        }
    ```

### Bloque 3: Modificación in-place (`modificarReserva`) (5.0% / 15%)
* ⚠️ **A mejorar (-10%):**
  - **Sobreescritura de clave primaria y lectura interactiva (`examen 4 unudad 2 Rodriguez Benjamin.cpp`, L185-204):**  
    Creas un struct vacío `nuevo`, pides los campos por consola pero dejas `nuevo.nroHabitacion` en 0. Al hacer `arr[pos] = nuevo;`, borras la clave primaria del registro:
    ```cpp
    // Líneas 185-202
    bool modificarReserva(ReservaHotel arr[], int tam, const ReservaHotel &actualizada){
        ReservaHotel nuevo;
        int pos = buscarPorHabitacion(reserva,tam,actualizada); // Error: pasar actualizada.nroHabitacion
        // ... pides cin >> nuevo.noches, etc.
        arr[pos] = nuevo; // ¡Peligro! 'nuevo.nroHabitacion' quedó en 0, destruyendo la PK
        return true;
    }
    ```

### Bloque 4: Burbuja e Intercambio (`ordenarPorImporteBurbujaDesc`) (6.0% / 30%)
* ⚠️ **A mejorar (-24%):**
  - **Intercambio de campos sueltos y sintaxis rota (`examen 4 unudad 2 Rodriguez Benjamin.cpp`, L219-236):**  
    En `intercambiar` pusiste `reserva = aux` sin tipos ni puntos y coma. En el ordenamiento invocaste `intercambiar(arr[j].precioTotal, arr[j+1].precioTotal);`, permutando únicamente los montos y desfasándolos del resto de los datos de cada reserva:
    ```cpp
    // Líneas 219-234
    void intercambiar(ReservaHotel &a, ReservaHotel &b){
        reserva = aux // Variables y tipos inexistentes, faltan ;
        a = b
        b = aux
    }
    // En ordenar:
    intercambiar(arr[j].precioTotal,arr[j + 1].precioTotal); // ¡Penalización directa: permuta campos sueltos!
    ```

---

## 💡 Recomendaciones de Mejora

1. **Nunca permutes campos sueltos durante un ordenamiento:**  
   En un arreglo de registros, siempre se intercambia el `struct` completo:
   ```cpp
   intercambiar(arr[j], arr[j + 1]); // Pasa los registros completos
   ```
2. **Cuidado con la condición del Right-Shift:**  
   Para desplazar hacia la derecha y abrir hueco en `pos`, el bucle debe decrementar mientras `i > pos`:
   ```cpp
   for (int i = tam; i > pos; i--) {
       arr[i] = arr[i - 1];
   }
   arr[pos] = nuevo;
   tam++;
   ```
3. **No alteres los nombres de los miembros provistos en la consigna (`importeTotal`).**
