# Devolución de Examen: 3er Recuperatorio Parcial (Módulo 3: Arreglos en C++)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Narváez, Leonel
- **Archivo Entregado:** `NarvaezLeonel.cpp`
- **Tema Asignado:** Tema 1 (*Parque Solar Cauchari*)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Estado de Compilación:** Compila con advertencias de función sin valor de retorno (`BuscarMedicion`) y recursión infinita potencial.
- **Calificación Final:** **2 (Dos) — NO APROBADO (34% / 100%)**

---

Hola **Leonel**, a continuación te comparto la devolución detallada de tu examen de Módulo 3. Tu calificación final es de **2 / 10 (No Aprobado)**, alcanzando un **34% / 100%** neto.

Se reconoce tu iniciativa y prolijidad al crear una función auxiliar modular (`ValidacionDouble`) para controlar el ingreso de mediciones en la carga. Sin embargo, tu entrega presentó fallas conceptuales críticas en los algoritmos esenciales: en la búsqueda secuencial generaste una llamada recursiva infinita hacia la propia función sin base de parada (provocando desbordamiento de pila / *Stack Overflow*), en la compactación *Shift-Left* iteraste fuera del límite activo leyendo basura en `arr[tam]`, en el listado omitiste mostrar el arreglo completo (solo mostraste los valores que superaban el umbral), y en las estadísticas te limitaste a imprimir valores sin calcular promedio ni máximo. Además, cambiaste el tipo del arreglo de `float` a `double` y modificaste las firmas de los prototipos provistos en la plantilla.

---

## 📊 Calificación Final y Resumen de Evaluación

| Criterio Evaluado | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **1. Carga Controlada (`RegistrarInversor`)** | 25% | **22%** | Implementó una función auxiliar de validación modular `ValidacionDouble`, verificó capacidad e incrementó `tam++`. Descuento por cambio no autorizado de tipo a `double`. |
| **2. Recorrido y Filtro (`ListarInversores`)** | 20% | **8%** | Alteró la firma quitando el parámetro del umbral. Solo lista los elementos mayores a 140.0, omitiendo mostrar el arreglo completo. |
| **3. Búsqueda Secuencial (`BuscarMedicion`)** | 15% | **2%** | **Falla crítica:** En lugar de recorrer el arreglo, la función se invoca a sí misma recursivamente sin caso base (*Stack Overflow* en runtime) y carece de `return`. |
| **4. Eliminación Física (*Shift-Left*) (`DarDeBajaInversor`)** | 25% | **10%** | Desplaza hacia la izquierda pero con error *off-by-one* en el bucle (`i < tam`) leyendo basura en `arr[tam]`. Depende de una búsqueda rota. |
| **5. Estadísticas con Guarda (`CalcularEstadisticas`)** | 15% | **2%** | Solo imprime las celdas entre barras. No calculó el promedio ni buscó el máximo y su posición. |
| **Penalización Directa** | -10% | **-10%** | Violación de prototipos y tipos provistos en plantilla (`float` reemplazado por `double`). |
| **TOTAL FINAL** | **100%** | **34% (Nota 2)** | **No Aprobado.** |

---

## 🔍 Desglose Técnico por Criterio

### 1. Carga Controlada (`RegistrarInversor`) (22% / 25%)
* ✅ **Logrado:**
  - Buena modularización mediante la función `ValidacionDouble` y control de capacidad máxima `if (tam == capacidad) return;`.
* ⚠️ **A mejorar (-3%):**
  - **Sustitución de tipos primitivos (`NarvaezLeonel.cpp`, L51):**  
    El dominio establecía `float arr[]` y cambiaste los contratos a `double arr[]`.

### 2. Recorrido y Filtro (`ListarInversores`) (8% / 20%)
* ⚠️ **A mejorar (-12%):**
  - **Firma mutilada y omisión del listado general (`NarvaezLeonel.cpp`, L68-78):**  
    Eliminaste el parámetro `float umbralAltaIrradiacion` de la cabecera. Además, el `cout` está encerrado adentro de `if (arr[i] > 140.0)`, por lo que los inversores con producción menor o igual a 140 jamás se imprimen en pantalla:
    ```cpp
    // Líneas 68-78
    void ListarInversores(const double arr[], int tam) { // Firma modificada (falta umbral)
        int umbralTime=0;
        for (int i = 0; i < tam; ++i) {
            if (arr[i]>140.0) { // Solo imprime si supera 140
                cout << "|Posicion: " << i+1 << "Valor: " << arr[i] << "|
";
                umbralTime++;
            }
            // ¡Los inversores con <= 140.0 nunca se listan!
        }
        cout << "Bloques en Prime Time " << umbralTime << " de " << tam << endl;
    }
    ```

### 3. Búsqueda Secuencial (`BuscarMedicion`) (2% / 15%)
* ⚠️ **A mejorar (-13%):**
  - **Recursión infinita sin caso base y sin retorno (`NarvaezLeonel.cpp`, L80-94):**  
    En lugar de iterar sobre `arr[]`, pediste un dato por consola y llamaste a la misma función `BuscarMedicion` indefinidamente. Esto satura la pila de ejecución y provoca que el programa colapse:
    ```cpp
    // Líneas 80-94
    int BuscarMedicion(const double arr[], int tam, double valorBuscado) {
        // ...
        cin >> buscado;
        int pos = BuscarMedicion(arr, tam, valorBuscado); // ¡Llamada recursiva infinita!
        // ...
        // ¡La función no tiene sentencia 'return'!
    }
    ```

### 4. Eliminación Física Shift-Left (`DarDeBajaInversor`) (10% / 25%)
* ⚠️ **A mejorar (-15%):**
  - **Lectura fuera de rango en el bucle de desplazamiento (`NarvaezLeonel.cpp`, L103-107):**  
    Condición `i < tam`. Cuando `i` alcanza `tam - 1`, la asignación `arr[i] = arr[i + 1]` intenta leer `arr[tam]`, que es una posición inactiva con datos basura:
    ```cpp
    // Líneas 103-107
    for (int i = Pos; i < tam; ++i) { // ¡Debe ser i < tam - 1!
        arr[i]=arr[i+1];              // En la última vuelta lee arr[tam] fuera de rango
    }
    tam--;
    ```

### 5. Estadísticas con Guarda (`CalcularEstadisticas`) (2% / 15%)
* ⚠️ **A mejorar (-13%):**
  - **Métricas estadísticas omitidas (`NarvaezLeonel.cpp`, L111-115):**  
    Te limitaste a imprimir el arreglo en vez de acumular para el promedio y buscar el valor máximo:
    ```cpp
    // Líneas 111-115
    void CalcularEstadisticas(const double arr[], int tam) {
        for (int i = 0; i < tam; ++i) {
            cout << "|" << arr[i] << "|" << endl; // No calcula nada
        }
    }
    ```

---

## 💡 Recomendaciones de Mejora

1. **Algoritmo estándar de Búsqueda Secuencial en C++:**  
   Nunca uses recursión cuando un bucle `for` lineal resuelve el problema de forma directa y segura:
   ```cpp
   int BuscarMedicion(const float arr[], int tam, float valorBuscado) {
       for (int i = 0; i < tam; i++) {
           if (arr[i] == valorBuscado) {
               return i; // Hallazgo temprano
           }
       }
       return -1; // No existe
   }
   ```
2. **Cuidado con el límite del Shift-Left:**  
   Como accedes a `arr[i + 1]`, el bucle debe detenerse estrictamente en `i < tam - 1`.
3. **Respeta los prototipos provistos por la cátedra sin alterar tipos ni parámetros.**
