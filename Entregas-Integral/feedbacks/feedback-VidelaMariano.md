# Devolución de Examen: 3er Recuperatorio Parcial (Módulo 3: Arreglos en C++)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Videla, Mariano
- **Archivo Entregado:** `Recu3erParcial - Mariano Videla.cpp`
- **Tema Asignado:** Tema 2 (*Parque Eólico Rawson*)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Estado de Compilación:** Compila limpio y sin advertencias bajo estándar C++17.
- **Calificación Final:** **6 (Seis) — BUENO (82% / 100%)**

---

Hola **Mariano**, a continuación te comparto la devolución detallada de tu examen de Módulo 3. Tu desempeño técnico alcanzó un **82% / 100% (Nota final: 6 - Bueno)**, logrando la **aprobación del módulo**.

Demostraste un nivel muy sólido y prolijo en la estructuración de algoritmos sobre arreglos unidimensionales. Tu entrega destaca por una excelente carga interactiva con control de capacidad estricto, una búsqueda secuencial canónica con corte temprano, un listado con filtro de umbral impecable y estadísticas protegidas contra división por cero que calculan con éxito el promedio y el mínimo del parque eólico.

Los únicos dos aspectos que impidieron una calificación sobresaliente fueron:
1. Un sutil error de límites (*off-by-one*) en el bucle de compactación *Shift-Left*, donde la condición `i < tam` provoca que en la última vuelta se lea la posición `arr[tam]` (fuera del arreglo activo).
2. La sustitución sistemática del tipo de dato `float` por `double` en las constantes, prototipos y el arreglo de `main()`, lo cual incurre en la penalización reglamentaria por modificación de firmas provistas en plantilla.

---

## 📊 Calificación Final y Resumen de Evaluación

| Criterio Evaluado | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **1. Carga Controlada (`RegistrarAerogenerador`)** | 25% | **25%** | **Excelente:** Control de cupo `tam >= capacidad`, validación con `while` de rango `[50.0, 600.0]`, asignación e incremento `tam++` por referencia, con opción interactiva de carga continua. |
| **2. Recorrido y Filtro (`ListarAerogeneradores`)** | 20% | **20%** | **Impecable:** Protección de arreglo vacío `tam == 0`, filtro estricto por umbral `> 350.0`, formateo claro con etiqueta `[RENDIMIENTO OPTIMO]` y reporte de conteo final. |
| **3. Búsqueda Secuencial (`BuscarPotencia`)** | 15% | **15%** | **Excelente:** Recorrido secuencial canónico con salida anticipada inmediata ante el hallazgo y centinela `-1` ante ausencia. |
| **4. Eliminación Física (*Shift-Left*) (`DarDeBajaAerogenerador`)** | 25% | **18%** | **Muy Bueno:** Protege `tam == 0`, reutiliza modularmente `BuscarPotencia` y decrementa `tam--`. Detalle *off-by-one*: el bucle `i < tam` lee datos inactivos en `arr[tam]` en la última iteración. |
| **5. Estadísticas con Guarda (`CalcularEstadisticas`)** | 15% | **14%** | Protege contra división por cero, calcula promedio y busca mínimo. Desliz menor de nomenclatura: variable del índice denominada `posMax` en lugar de `posMin`. |
| **Penalización Directa** | -10% | **-10%** | Alteración de prototipos y contratos provistos en plantilla (sustitución de `float` por `double` en constantes, funciones y arreglo). |
| **TOTAL FINAL** | **100%** | **82% (Nota 6)** | **Aprobado (Bueno: rango 76 - 83%).** |

---

## 🔍 Desglose Técnico por Criterio

### 1. Carga Controlada y Validación de Límites (`RegistrarAerogenerador`) (25% / 25%)
* ✅ **Logrado:**
  - **100% Logrado:** Manejo impecable de la capacidad máxima con mensaje descriptivo y retorno inmediato.
  - Validación interactiva con bucle `while` para exigir valores dentro del rango `[50.0, 600.0]`.
  - Asignación directa en `arr[tam]` e incremento del tamaño lógico por referencia (`tam++`).
  - Excelente diseño con menú interactivo de repetición (`char continuar`) que previene desbordamiento en cada iteración (`Recu3erParcial - Mariano Videla.cpp`, L84-115):
    ```cpp
    void RegistrarAerogenerador(double arr[], int &tam, int capacidad) {
        char continuar = 's';
        while (continuar == 's' || continuar == 'S') {
            if (tam >= capacidad) {
                cout << "Error: Ya se alcanzo la capacidad Maxima alcanzada (" << capacidad << " aerogeneradores)..." << endl;
                return;
            }
            double valor;
            cout << "[Opc 1] Carga: ";
            cin >> valor;
            while (valor < 50.0 || valor > 600.0) {
                cout << "Valor fuera de rango... Ingrese entre " << MIN_POTENCIA << " y " << MAX_POTENCIA << " kW: ";
                cin >> valor;
            }
            arr[tam] = valor;
            cout << "-> Registro agregado en la posicion [" << tam << "]. Total activos: " << tam + 1 << "/15" << endl;
            tam++;
            // ...
        }
    }
    ```

### 2. Recorrido y Filtro Estricto por Umbral (`ListarAerogeneradores`) (20% / 20%)
* ✅ **Logrado:**
  - **100% Logrado:** Guarda inicial para arreglo vacío `tam == 0` con retorno temprano.
  - Recorrido completo formateando cada registro con su índice `[i]`.
  - Filtro estricto `arr[i] > umbralOptimo` (sin incluir el borde con `>=`).
  - Contador específico `contUmbralOptimo` e impresión al pie del total de generadores destacados (`Recu3erParcial - Mariano Videla.cpp`, L117-137):
    ```cpp
    void ListarAerogeneradores(const double arr[], int tam, double umbralOptimo) {
        if (tam == 0) {
            cout << "No hay aerogeneradores registrados en el sistema." << endl;
            return;
        }
        int contUmbralOptimo = 0;
        cout << "--- LISTADO DE AEROGENERADORES (" << tam << "/" << CAPACIDAD << ") ---" << endl;
        for (int i = 0; i < tam; i++) {
            if (arr[i] > umbralOptimo) {
                contUmbralOptimo++;
                cout << "[" << i << "] -> " << arr[i] << "kW" << " [RENDIMIENTO OPTIMO]" << endl;
            } else {
                cout << "[" << i << "] -> " << arr[i] << "kW" << endl;
            }
        }
        cout << "Aerogeneradores en Rendimiento Optimo (> " << umbralOptimo << " kW): " << contUmbralOptimo << endl;
    }
    ```

### 3. Búsqueda Secuencial (`BuscarPotencia`) (15% / 15%)
* ✅ **Logrado:**
  - **100% Logrado:** Búsqueda lineal canónica con salida temprana inmediata ante coincidencia (`return i;`) y retorno de centinela `-1` si no existe (`Recu3erParcial - Mariano Videla.cpp`, L139-147).

### 4. Eliminación Física Shift-Left (`DarDeBajaAerogenerador`) (18% / 25%)
* ✅ **Logrado:**
  - Guarda de arreglo vacío `tam == 0`.
  - Reutilización modular obligatoria de `BuscarPotencia(arr, tam, eliminar)`.
  - Validación de existencia (`pos == -1`) con mensaje y retorno temprano.
  - Decremento del tamaño lógico `tam--;` y mensaje de estado.
* ⚠️ **A mejorar (-7%):**
  - **Error off-by-one en límite superior del Shift-Left (`Recu3erParcial - Mariano Videla.cpp`, L168-170):**  
    Pusiste la condición `i < tam`. Al llegar a la última iteración del bucle (`i = tam - 1`), la instrucción `arr[i] = arr[i + 1]` intenta leer de `arr[tam]`. Dicha celda está fuera del arreglo activo y contiene datos residuales/basura:
    ```cpp
    // Líneas 168-170
    for (int i = pos; i < tam; i++) { // ¡Debe ser i < tam - 1!
        arr[i] = arr[i + 1];          // En la última vuelta lee arr[tam] fuera de rango
    }
    tam--;
    ```

### 5. Estadísticas con Guarda (`CalcularEstadisticas`) (14% / 15%)
* ✅ **Logrado:**
  - Guarda estricta para evitar división por cero si `tam == 0`.
  - Acumulador inicializado en `0.0` y valor mínimo en `arr[0]`.
  - Detección correcta del valor mínimo y reporte detallado de métricas (`Recu3erParcial - Mariano Videla.cpp`, L176-202).
* ⚠️ **A mejorar (-1%):**
  - **Nomenclatura confusa de variable (`Recu3erParcial - Mariano Videla.cpp`, L185, 192, 200):**  
    Llamaste `posMax` a la variable que almacena la posición del **mínimo**:
    ```cpp
    int posMax = 0; // Desliz semántico: almacena el índice del mínimo, debió ser posMin
    ```

### 6. Penalización Directa (-10%)
* ⚠️ **A mejorar (-10%):**
  - **Sustitución de tipo base provisto en plantilla (`Recu3erParcial - Mariano Videla.cpp`, L14-16, L23-27, L30):**  
    La plantilla oficial establecía trabajar con `float` (`MIN_POTENCIA = 50.0f`, `float arr[]`, etc.). Reemplazaste todos los tipos por `double`, incurriendo en la penalización reglamentaria por alteración de firmas provistas.

---

## 💡 Recomendaciones de Mejora

1. **Límite exacto del bucle Shift-Left:**  
   Como dentro del bucle lees la celda siguiente `arr[i + 1]`, para que `i + 1` nunca exceda el último elemento válido (`tam - 1`), el bucle debe detenerse en:
   ```cpp
   for (int i = pos; i < tam - 1; i++) {
       arr[i] = arr[i + 1];
   }
   tam--;
   ```
2. **Respeta los tipos de datos de los contratos provistos:**  
   Si la plantilla define `float arr[]`, mantén siempre `float` para no quebrar la compatibilidad de firmas en proyectos colaborativos o suites de testeo automático.
3. ¡Felicitaciones por la claridad, orden y calidad lógica demostrada en tu código!

