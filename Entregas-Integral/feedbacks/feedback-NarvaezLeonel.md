# Devolución de Examen: 3er Recuperatorio Parcial (Módulo 3: Arreglos en C++)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Narváez, Leonel L.
- **Archivo Entregado:** `NarvaezLeonel.cpp`
- **Tema Asignado:** Tema 1 (*Parque Solar Cauchari*)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Condición Final de la Cursada:** **NO REGULAR**
- **Estado de Compilación:** Compila con advertencias críticas de función sin valor de retorno (`BuscarMedicion`) y recursión infinita en runtime.
- **Calificación Final:** **1 (Uno) — NO APROBADO / REPROBADO (5% / 100%)**

---

Hola **Leonel**, a continuación te comparto la devolución formal y definitiva de tu examen de Módulo 3. Tu calificación final es de **1 / 10 (No Aprobado / Reprobado)**, habiendo alcanzado un **5% / 100%** neto, lo que ratifica tu condición de **NO REGULAR** en la cátedra para este Ciclo Lectivo 2026.

Si bien demostraste una intención modular al crear la función auxiliar `ValidacionDouble` en la carga, el resto del examen presenta fallas algorítmicas críticas y fatales que anulan por completo los bloques evaluados: en la búsqueda secuencial provocaste un desbordamiento de pila (*Stack Overflow*) inmediato al llamarse la función a sí misma indefinidamente sin caso base y sin retorno; en la baja física el bucle excede el tamaño lógico leyendo memoria residual y depende de la búsqueda colapsada; en el listado mutilaste la firma provista y no listaste los elementos del arreglo; y en las estadísticas omitiste la totalidad de los cálculos pedidos (promedio y máximo). 

Al no haber superado los requerimientos mínimos de funcionamiento y estabilidad del software exigidos por la rúbrica oficial, cuatro de las cinco funciones obtuvieron calificación de 0% (Insuficiente), a lo que se suma la penalización directa por alteración de los contratos de la plantilla base.

---

## 📊 Calificación Final y Resumen de Evaluación (Rúbrica Estricta)

| Bloque Evaluativo | Ponderación | Puntaje Obtenido | Calificación Técnica | Observaciones Principales |
| :--- | :---: | :---: | :---: | :--- |
| **1. Carga Controlada (`RegistrarInversor`)** | 25% | **15%** | **Parcial** | Validó mediante función auxiliar `ValidacionDouble` y controló capacidad máxima. Descuento por añadir bucle interactivo `do-while` interno que colisiona con el control del menú en `main()`. |
| **2. Recorrido y Filtro (`ListarInversores`)** | 20% | **0%** | **Insuficiente** | **Bloque anulado:** Alteró la firma eliminando el parámetro del umbral. Solo imprime celdas aisladas que superan 140.0, omitiendo listar el contenido general del arreglo. |
| **3. Búsqueda Secuencial (`BuscarMedicion`)** | 15% | **0%** | **Insuficiente** | **Bloque anulado (Falla Crítica):** No implementó búsqueda lineal. La función se invoca recursivamente a sí misma sin fin, colapsando el programa en ejecución (*Stack Overflow*), y carece de sentencia `return`. |
| **4. Eliminación Física (*Shift-Left*) (`DarDeBajaInversor`)** | 25% | **0%** | **Insuficiente** | **Bloque anulado:** Invoca la búsqueda recursiva rota. Además, el bucle `i < tam` accede fuera de rango a `arr[tam]` corrompiendo la memoria del arreglo con datos basura. |
| **5. Estadísticas con Guarda (`CalcularEstadisticas`)** | 15% | **0%** | **Insuficiente** | **Bloque anulado:** Omitió por completo el cálculo del promedio, la búsqueda del valor máximo y el registro de su índice. Se limitó a imprimir las celdas entre barras. |
| **Penalización Directa de Cátedra** | -10% | **-10%** | **Penalización** | Alteración general de los prototipos provistos en la plantilla base y mutilación de parámetros (`float` sustituido por `double`, omisión de umbral). |
| **TOTAL DEFINITIVO** | **100%** | **5% (Nota 1)** | **REPROBADO** | **No Aprobado / Reprobado (Rango 0 – 39%). Condición: NO REGULAR.** |

---

## 🔍 Desglose Técnico Exhaustivo por Criterio

### 1. Carga Controlada y Validación de Límites (`RegistrarInversor`) (15% / 25%)
* ✅ **Logrado:**
  - Control de capacidad `if (tam == capacidad) return;` e incremento del tamaño lógico `tam++`.
  - Validación de rango operativo `[15.0, 250.0]` delegada en `ValidacionDouble`.
* ⚠️ **A mejorar (-10%):**
  - **Inclusión indebida de ciclo interactivo interno (`NarvaezLeonel.cpp`, L55-65):**  
    El menú modular en `main()` es el encargado de gobernar la ejecución de cada opción. Al introducir un bucle `do ... while (respuesta != 'N')` adentro de `RegistrarInversor`, alteras el contrato del sistema modular:
    ```cpp
    // Líneas 55-65: Bucle innecesario dentro de la función de carga
    do {
        if (tam==capacidad) {
            cout << "La capacidad esta llena." << endl;
            return;
        }
        ValidacionDouble( arr[tam], 15.0f, 250.0f, "Ingrese:");
        tam++;
        cout << "Desea continuar? (S/N)" << endl;
        cin >> respuesta;
    } while (respuesta!='N');
    ```

---

### 2. Recorrido y Filtro Estricto por Umbral (`ListarInversores`) (0% / 20%)
* ⚠️ **A mejorar (-20% — Insuficiente 0%):**
  - **Alteración de cabecera y omisión del listado general (`NarvaezLeonel.cpp`, L68-78):**  
    Mutilaste el prototipo provisto eliminando el parámetro `float umbralAltaIrradiacion`. Adicionalmente, encerraste la salida por consola adentro del condicional `if (arr[i] > 140.0)`, por lo cual todas las mediciones menores o iguales a 140.0 jamás se muestran en pantalla. La función incumple el objetivo de listar el arreglo:
    ```cpp
    // Líneas 68-78: La función no lista el arreglo
    void ListarInversores(const double arr[], int tam) { // Firma modificada (falta umbralAltaIrradiacion)
        int umbralTime=0;
        for (int i = 0; i < tam; ++i) {
            if (arr[i]>140.0) { // ¡Solo muestra si supera 140!
                cout << "|Posicion: " << i+1 << "Valor: " << arr[i] << "|\n";
                umbralTime++;
            }
            // Los inversores con valores normales nunca se listan
        }
        cout << "Bloques en Prime Time " << umbralTime << " de " << tam << endl;
    }
    ```

---

### 3. Búsqueda Secuencial (`BuscarMedicion`) (0% / 15%)
* ⚠️ **A mejorar (-15% — Insuficiente 0%):**
  - **Recursión infinita bloqueante y ausencia de retorno (`NarvaezLeonel.cpp`, L80-94):**  
    En lugar de programar un recorrido lineal indexado sobre el arreglo `arr[]`, solicitaste una entrada por consola y llamaste recursivamente a la propia función `BuscarMedicion` sin condición de parada. Esta instrucción colapsa la memoria de pila de ejecución (*Stack Overflow*) provocando el cierre abrupto del programa. Además, la función no posee sentencia `return`:
    ```cpp
    // Líneas 80-94: Falla crítica de ejecución
    int BuscarMedicion(const double arr[], int tam, double valorBuscado) {
        if (tam == 0) {
            cout << "\nNo hay inversores registrados en el sistema.\n";
        } else {
            double buscado;
            cout << "\nIngrese medicion a buscar (kWh): ";
            cin >> buscado;
            int pos = BuscarMedicion(arr, tam, valorBuscado); // ¡Llamada recursiva infinita! Destruye la pila
            if (pos != -1) {
                cout << "Medicion encontrada en la posicion [" << pos << "].\n";
            } else {
                cout << "Medicion no encontrada en el arreglo.\n";
            }
        }
        // ¡ERROR FATAL: La función int no retorna ningún valor en ningún camino!
    }
    ```

---

### 4. Eliminación Física Shift-Left (`DarDeBajaInversor`) (0% / 25%)
* ⚠️ **A mejorar (-25% — Insuficiente 0%):**
  - **Dependencia de función colapsada y acceso a memoria inválida (`NarvaezLeonel.cpp`, L95-108):**  
    Invocas a `BuscarMedicion` (que rompe la pila). Pero aun si encontrara la posición, tu bucle de desplazamiento tiene la condición `i < tam`. Al llegar a la última iteración (`i = tam - 1`), la instrucción `arr[i] = arr[i + 1];` intenta leer `arr[tam]`, que es memoria inactiva fuera del rango lógico del arreglo:
    ```cpp
    // Líneas 99-107: Corrimiento fuera de límites
    int Pos=BuscarMedicion(arr, tam, valorBuscado); // Invocación a función rota
    if (Pos==-1) {
        cout << "No se encontro el valor." << endl;
    } else {
        for (int i = Pos; i < tam; ++i) { // ¡Debe ser estrictamente i < tam - 1!
            arr[i]=arr[i+1];              // En la última vuelta lee arr[tam] fuera de rango
        }
        tam--;
    }
    ```

---

### 5. Estadísticas con Guarda (`CalcularEstadisticas`) (0% / 15%)
* ⚠️ **A mejorar (-15% — Insuficiente 0%):**
  - **Omisión total de cálculos estadísticos (`NarvaezLeonel.cpp`, L111-115):**  
    La función no realiza ninguna operación de agregación ni análisis. No acumulaste para calcular el promedio (`float`), no comparaste para encontrar el valor máximo ni registraste el índice `posMax`. Te limitaste a un bucle de impresión que no responde a la consigna:
    ```cpp
    // Líneas 111-115: Ninguna estadística calculada
    void CalcularEstadisticas(const double arr[], int tam) {
        for (int i = 0; i < tam; ++i) {
            cout << "|" << arr[i] << "|" << endl; // No calcula promedio ni máximo
        }
    }
    ```

---

## 💡 Recomendaciones de Mejora

1. **Búsqueda Secuencial canónica en arreglos:**  
   La búsqueda lineal en un arreglo unidimensional debe resolverse de forma imperativa iterando celda por celda:
   ```cpp
   int BuscarMedicion(const float arr[], int tam, float valorBuscado) {
       for (int i = 0; i < tam; i++) {
           if (arr[i] == valorBuscado) {
               return i; // Retorno temprano del índice encontrado
           }
       }
       return -1; // Retorno centinela si no existe
   }
   ```
2. **Límites estrictos en corrimientos (Shift-Left):**  
   Al asignar `arr[i] = arr[i + 1]`, el índice `i + 1` jamás debe alcanzar `tam`. Por ello, el bucle debe terminar en `tam - 1`:
   ```cpp
   for (int i = pos; i < tam - 1; i++) {
       arr[i] = arr[i + 1];
   }
   tam--;
   ```
3. **Respeto irrestricto de las especificaciones y prototipos de cátedra:**  
   No elimines parámetros provistos ni alteres los tipos de las cabeceras (`float arr[]`); el software debe integrarse limpiamente con el resto de la aplicación sin romper los contratos modulares.

---

## 🎓 Condición Final de la Cursada y Cierre de Ciclo Lectivo 2026

- **Condición Académica Definitiva:** **NO REGULAR**
- **Coloquio Teórico:** 0
- **Situación en Actas:** Deberá recursar la asignatura en el Ciclo Lectivo 2027.

> [!NOTE]
> ### 💬 Notificación Oficial de Cierre
> Con un puntaje neto definitivo de **5% / 100% (Nota 1 - Reprobado)**, tu condición final en actas de cursada es **NO REGULAR**.
> 
> Esta calificación no admite instancias de redondeo al encontrarse a más de 55 puntos porcentuales del umbral mínimo de acreditación (60%). Deberás reinscribirte para **recursar la asignatura en el Ciclo Lectivo 2027**.
> 
> Te instamos a aprovechar el receso para practicar la implementación en C++ de algoritmos elementales sobre arreglos, habituándote a la compilación incremental paso a paso para evitar errores fatales de ejecución. La cátedra estará a tu disposición desde el inicio del próximo período académico.
