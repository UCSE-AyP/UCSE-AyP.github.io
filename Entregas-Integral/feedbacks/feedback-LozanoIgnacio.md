# Devolución de Examen: Recuperatorio Integral (Módulos 3 y 4)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Lozano, Ignacio
- **Archivos Entregados:** `Lozanoignacio 3er parcial tema 2.cpp` (Módulo 3, Tema 2) y `4to parcial tema 2 Lozano ignacio.cpp` (Módulo 4, Tema 2)
- **Tema Asignado:** Tema 2 (*Parque Eólico Rawson* en M3 / *Sistema de Reservas Hoteleras* en M4)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Condición Final de la Cursada:** **NO REGULAR**
- **Estado de Compilación:** **No compila** en ninguno de los dos módulos por múltiples errores sintácticos severos (omisión masiva de punto y coma, palabras clave mal escritas, operadores inexistentes y llaves desbalanceadas).
- **Calificación Global:** **M3: 2 (No Aprobado - 15%) / M4: 2 (No Aprobado - 33% [Lab: 8/75 + Escrita: 25/25])**

---

Hola **Ignacio**, a continuación te comparto la devolución consolidada de tu examen integral. Tu calificación global es de **2 / 10 (No Aprobado)**, compuesta por un **15% / 100% en el Módulo 3 (Nota 2)** y **33 / 100 puntos (33.0% - Nota 2) en el Módulo 4**, integrando **8.0 / 75 puntos en el laboratorio C++** y un **sobresaliente 25 / 25 puntos (100%) en la evaluación escrita en papel A4**, donde realizaste con total precisión la traza de Inserción Directa.

Se evidencia que reconoces a grandes rasgos las operaciones que se te pidieron (validar con `while`, iterar para buscar y compactar el arreglo), pero tus entregas presentan un colapso sintáctico generalizado que impide totalmente su compilación bajo el estándar C++. Faltan puntos y coma en casi todas las líneas ejecutables, escribiste `cout` sin los operadores `<<`, asignaciones sin el signo `=`, condiciones de `if` sin paréntesis y bucles `for` con sintaxis rota como `for (int i=0; i - tam; i ++)`. En el Módulo 4, además, omitiste por completo las funciones de inserción, modificación y ordenamiento.

Es indispensable que realices prácticas de compilación incremental: escribir una función pequeña, compilarla, verificar que no tenga errores de sintaxis y recién avanzar con la siguiente.

---

## 📊 1. Resumen de Calificación — Módulo 3: Arreglos en C++ (Tema 2)

| Criterio Evaluado | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **1. Carga Controlada (`RegistrarAerogenerador`)** | 25% | **4%** | Intención de validar con `while` e incrementar `tam++`, pero colapso de sintaxis: `float` suelto, falta de punto y coma y asignación sin operador (`arr[tam] potencia`). |
| **2. Recorrido y Filtro (`ListarAerogeneradores`)** | 20% | **3%** | Sintaxis inválida en condición (`if tam = 0`) y bucle roto (`for (int i=0; i - tam; i ++)`). |
| **3. Búsqueda Secuencial (`BuscarPotencia`)** | 15% | **4%** | `for (int i = 0; i < tam; i++);` con punto y coma final que vacía el bucle y ejecuta la comparación fuera de contexto. |
| **4. Eliminación Física (*Shift-Left*) (`DarDeBajaAerogenerador`)** | 25% | **2%** | Llama a `BuscarPotencia`, pero el bucle de corrimiento está totalmente truncado e incompleto (`for(int i = posicion, i; tam - 1; i++;`). |
| **5. Estadísticas con Guarda (`CalcularEstadisticas`)** | 15% | **2%** | Cadena de texto sin cerrar (`cout << "estadisticas`), sintaxis rota en cálculo y bucle. |
| **SUBTOTAL MÓDULO 3** | **100%** | **15%** | **No Aprobado por errores sintácticos bloqueantes.** |

---

## 🔍 Desglose Técnico por Criterio — Módulo 3

### 1. Carga Controlada y Validación de Límites (`RegistrarAerogenerador`) (4% / 25%)
* ⚠️ **A mejorar (-21%):**
  - **Sintaxis elemental rota (`Lozanoignacio 3er parcial tema 2.cpp`, L80-95):**  
    Declaraciones incompletas, falta de operadores de flujo `<<`, asignaciones sin `=`, y ausencia sistemática de `;`:
    ```cpp
    // Líneas 80-95
    void RegistrarAerogenerador(float arr[], int &tam, int capacidad){
        float // Incompleto
        int capacidad // Falta punto y coma
        if (tam >= capacidad){
            cout << "el arreglo esta lleno. no se puede registrar" // Falta ;
            return;
        float potecia;
        cout <<"ingrese potencia kw";
        cin >> potencia;
        while (potencia < MIN_POTENCIA || potencia > MAX_POTENCIA)
        cout "valor invalido..."; // Falta << y faltan llaves en el while	
        cout "ingrese nuevamente";
        cin >> potencia;
        arr[tam] potencia // ¡Falta el signo de asignación '=' y ';' ! Debe ser arr[tam] = potencia;
        tam ++;
    ```

### 2. Recorrido y Filtro Estricto por Umbral (`ListarAerogeneradores`) (3% / 20%)
* ⚠️ **A mejorar (-17%):**
  - **Condiciones y bucles mal formados (`Lozanoignacio 3er parcial tema 2.cpp`, L100-113):**  
    Pusiste `if tam = 0` (falta paréntesis y es asignación en lugar de comparación `==`), `return;` incondicional que aborta la función, y un ciclo con resta `i - tam`:
    ```cpp
    // Líneas 100-106
    void ListarAerogeneradores(const float arr[], int tam, float umbralOptimo){
        if tam = 0 // Error: debe ser if (tam == 0)
            cout << " no hay aerogeneradores registrados en el sistema";
        return; // ¡Este return se ejecuta siempre! No permite listar nada
        int contadorOptimo 
            cout "listado de aerogeneradores";
        for (int i=0; i - tam; i ++){ // Error: debe ser i < tam
    ```

### 3. Búsqueda Secuencial (`BuscarPotencia`) (4% / 15%)
* ⚠️ **A mejorar (-11%):**
  - **Punto y coma al final del `for` y del `if` (`Lozanoignacio 3er parcial tema 2.cpp`, L116-121):**  
    Un punto y coma inmediatamente después del `for` o del `if` convierte la estructura en una sentencia vacía:
    ```cpp
    // Líneas 116-121
    int  BuscarPotencia(const float arr[], int tam, float valorBuscado){
        for (int i = 0; i < tam; i++); { // ¡Punto y coma indebido!
            if (arr[i] == valorBuscado); { // ¡Punto y coma indebido!
                return i;
            }
        } return -1;
    }
    ```

### 4. Eliminación Física Shift-Left (`DarDeBajaAerogenerador`) (2% / 25%)
* ⚠️ **A mejorar (-23%):**
  - **Bucle de desplazamiento destruido sintácticamente (`Lozanoignacio 3er parcial tema 2.cpp`, L127-138):**  
    Llamas a la búsqueda pero la comprobación y el bucle de corrimiento no compilan:
    ```cpp
    // Líneas 130-135
    int posicion = BuscarPotencia (arr,tam,potenciaAbuscar);
    int posicion - 1;{ // Expresión sin sentido
        cout "potencia no encontrada en el sistema";
        return;
    for(int i = posicion, i; tam - 1; i++; // Bucle roto
    tam--;
    ```

### 5. Estadísticas con Guarda (`CalcularEstadisticas`) (2% / 15%)
* ⚠️ **A mejorar (-13%):**
  - **Cadena sin cerrar y sentencias truncadas (`Lozanoignacio 3er parcial tema 2.cpp`, L149-160):**  
    ```cpp
    for (int i = 0, i << tam; i++){
        suma += arr[i];
        if arr[i] < minimo {
        minimo = arr[i];
        posminimo =i;
        };
        float promedio suma/tam-m
        cout <<  "estadisticas // ¡Cadena de texto sin cerrar comillas! Error fatal
        cout
        cout
    }
    ```

---

## 📊 2. Resumen de Calificación — Módulo 4: AoS y Ordenamiento (Tema 2)

| Bloque Evaluativo (75% C++) | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **Bloque 1: Struct Primitivo AoS** | 10% | **6.0%** | Declaró todos los campos, pero utilizó nombres en minúsculas (`nrohabitacion`, `precionoche`, `importetotal`) que desincronizan con la inicialización y el resto del programa. |
| **Bloque 2: Inserción Posicional (*Right-Shift*)** | 20% | **0.0%** | No implementada. |
| **Bloque 3: Modificación *in-place* (PK Inmutable)** | 15% | **0.0%** | No implementada. |
| **Bloque 4: Burbuja Mejorada e Intercambio** | 30% | **2.0%** | `ordenarPorImporteBurbujaDesc` no implementada. `intercambiar` usa tipo `reserva` inexistente y carece de puntos y coma. |
| **SUBTOTAL LABORATORIO C++** | **75%** | **8.0 / 75 pts** | **Desempeño técnico insuficiente (10.7%).** |
| **Instancia Escrita Individual (Papel A4)** | 25% | **25.0% (25 / 25)** | **Sobresaliente:** Traza paso a paso de Inserción Directa Descendente en papel A4 completada a la perfección. |
| **TOTAL MÓDULO 4** | **100%** | **33.0% (Nota UCSE: 2)** | **No Aprobado (rango 0 - 39%).** |

---

## 🔍 Desglose Técnico por Criterio — Módulo 4

### Bloque 1: Declaración de Struct `ReservaHotel` (6.0% / 10%)
* ⚠️ **A mejorar (-4%):**
  - **Identificadores en minúscula desfasados de la plantilla (`4to parcial tema 2 Lozano ignacio.cpp`, L11-19):**  
    Al declarar `nrohabitacion`, `precionoche` e `importetotal` en minúsculas en lugar de CamelCase (`nroHabitacion`, `precioNoche`, `importeTotal`), los inicializadores de `reservas[]` en `main()` y las llamadas auxiliares no compilan:
    ```cpp
    // Líneas 11-19
    struct ReservaHotel {
        int nrohabitacion;    // Debe ser: nroHabitacion
        int noches;
        char tipo;
        double precionoche;   // Debe ser: precioNoche
        double importetotal;  // Debe ser: importeTotal
        bool confirmada;
    };
    ```

### Bloque 2, 3 y 4: Funciones Nucleares de Módulo 4 (2.0% / 65%)
* ⚠️ **A mejorar (-63%):**
  - **Funciones de Inserción, Modificación y Ordenamiento omitidas (`4to parcial tema 2 Lozano ignacio.cpp`, L115-125):**  
    No implementaste `insertarReserva`, ni `modificarReserva`, ni `ordenarPorImporteBurbujaDesc`. Solo intentaste programar `intercambiar` con errores léxicos:
    ```cpp
    // Líneas 120-124
    void intercambiar(ReservaHotel &a, ReservaHotel &b) {
        reserva aux = a // Error: el tipo es ReservaHotel, no 'reserva', y falta ';'
        a=b             // Falta ';'
        b=aux           // Falta ';'
    } return;           // Sentencia fuera de función
    ```

---

## 💡 Recomendaciones de Mejora

1. **Compila en cada paso:** No escribas cientos de líneas sin compilar. Cada dos líneas que escribas, presiona Compilar (`F9` en Dev-C++ o tu IDE habitual) para corregir el punto y coma o la llave de inmediato.
2. **Repasa la sintaxis de sentencias básicas en C++:**
   - Salida: `cout << "Texto" << variable << endl;`
   - Bucle `for`: `for (int i = 0; i < tam; i++) { ... }` (¡nunca con `;` al final de la línea del `for`!).
   - Asignación: `arr[tam] = valor;` (el signo `=` es obligatorio).

---

## 🎓 Condición Final de la Cursada y Cierre de Ciclo Lectivo 2026

- **Condición Académica Definitiva:** **NO REGULAR**
- **Coloquio Teórico:** 0
- **Situación en Actas:** Deberá recursar la asignatura en el Ciclo Lectivo 2027.

> [!NOTE]
> ### 💬 Mensaje de Cierre y Orientación Académica
> Al no haberse alcanzado el puntaje mínimo de acreditación requerido en las instancias de recuperación práctica, tu condición final en la materia es **NO REGULAR**.
> 
> Queremos transmitirte un mensaje constructivo y de aliento: el aprendizaje de la programación estructurada y el pensamiento algorítmico es un proceso que demanda práctica continua y maduración conceptual. A lo largo del cuatrimestre has transitado temas complejos (estructuras de control, modularización por funciones, pasaje por referencia y arreglos), sentando las bases necesarias para afianzar el razonamiento lógico.
> 
> **Recomendaciones Clave para el Recursado 2027:**
> 1. **Práctica de Compilación Incremental:** Adquirir el hábito de compilar cada 2 o 3 líneas escritas; esto previene errores sintácticos acumulativos (puntos y coma, llaves, tipos) que bloquean la evaluación de la lógica.
> 2. **Entrenamiento en Algoritmos de Arreglos:** Dedicar tiempo en el receso a implementar de manera autónoma los algoritmos nucleares: búsqueda lineal con centinela `-1`, corrimiento a la izquierda (*Shift-Left*) para bajas, corrimiento a la derecha (*Right-Shift*) para inserciones, y ordenamiento por Burbuja.
> 3. La cátedra estará a tu disposición para consultas y acompañamiento pedagógico desde el inicio del ciclo 2027. ¡A no desanimarse y a encarar la próxima cursada con renovado compromiso y confianza!
