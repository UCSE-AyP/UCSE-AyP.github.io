# Devolución de Examen: 3er Recuperatorio Parcial (Módulo 3: Arreglos en C++)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Sosa, Noelia
- **Archivo Entregado:** `SosaNoelia-PARCIAL3.cpp`
- **Tema Asignado:** Tema 2 (*Parque Eólico Rawson*)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Estado de Compilación:** Compila limpio bajo C++17.
- **Calificación Final:** **2 (Dos) — NO APROBADO (35% / 100%)**

---

Hola **Noelia**, a continuación te comparto la devolución detallada de tu examen de Módulo 3. Tu calificación final es de **2 / 10 (No Aprobado)**, alcanzando un **35% / 100%**.

Se valora que comprendiste la necesidad de modularizar el código y que planteaste las funciones principales con la intención de validar y filtrar datos. Sin embargo, se presentaron fallas lógicas de alta criticidad: en la función `RegistrarAerogenerador` invertiste la condición de capacidad (provocando que el programa rechace la carga cuando hay lugar disponible) y escribiste un bucle `while` vacío que cuelga la máquina en un ciclo infinito ante un valor inválido; en la búsqueda secuencial cometiste un error de límite (*off-by-one*) ignorando el último elemento; en la baja física el corrimiento comenzó en el índice `0` en lugar de la posición encontrada, destruyendo el primer registro del arreglo; y omitiste por completo la función de cálculo estadístico.

---

## 📊 Calificación Final y Resumen de Evaluación

| Criterio Evaluado | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **1. Carga Controlada (`RegistrarAerogenerador`)** | 25% | **5%** | **Fallas críticas:** Condición de capacidad invertida (`tam < capacidad` rechaza cuando hay espacio) y `while` vacío que entra en bucle infinito ante un valor fuera de rango. |
| **2. Recorrido y Filtro (`ListarAerogeneradores`)** | 20% | **12%** | Protege `tam == 0` y filtra con `arr[i] > UMBRAL_RENDIMIENTO_OPTIMO`. Omitió informar en pantalla el conteo total de aerogeneradores destacados. |
| **3. Búsqueda Secuencial (`BuscarPotencia`)** | 15% | **10%** | Recorrido lineal con salida anticipada, pero con error *off-by-one* en el límite (`i < tam - 1`) que saltea la última celda. |
| **4. Eliminación Física (*Shift-Left*) (`DarDeBajaAerogenerador`)** | 25% | **8%** | Reutiliza `BuscarPotencia`, pero el bucle inicia en `i = 0` en vez de `i = pos` y va hasta `tam`, destruyendo el elemento `0` y leyendo fuera de rango. |
| **5. Estadísticas con Guarda (`CalcularEstadisticas`)** | 15% | **0%** | Función no implementada. |
| **TOTAL FINAL** | **100%** | **35% (Nota 2)** | **No Aprobado.** |

---

## 🔍 Desglose Técnico por Criterio

### 1. Carga Controlada y Validación de Límites (`RegistrarAerogenerador`) (5% / 25%)
* ⚠️ **A mejorar (-20%):**
  - **Condición de capacidad invertida y bucle infinito colgante (`SosaNoelia-PARCIAL3.cpp`, L76-88):**  
    Pusiste `if (tam < capacidad)` para decir "no hay cupo", lo que bloquea el sistema cuando el arreglo está vacío. Además, el `while` de validación quedó vacío (`while(...) {}`), por lo que si el usuario ingresa un número menor a 50 o mayor a 600, el programa se cuelga para siempre:
    ```cpp
    // Líneas 76-88
    void RegistrarAerogenerador(float arr[], int &tam, int capacidad){
        if (tam< capacidad) { // ¡Condición invertida! Debe ser: tam >= capacidad
            cout<<"No hay cupo disponible"<<endl; 
            return; 
        }
        float RangoOperativo; 
        cout<<"Ingrese el rango operativo (50.0-600.0): ";
        cin>>RangoOperativo;  
        
        while(RangoOperativo<50 || RangoOperativo>600){
            // ¡Cuerpo vacío! Bucle infinito que congela la ejecución
        } 
        cout<<"Rango invalido. Ingrese otra cantidad"; 
        cin>>RangoOperativo;
    ```

### 2. Recorrido y Filtro Estricto por Umbral (`ListarAerogeneradores`) (12% / 20%)
* ✅ **Logrado:**
  - Protegiste `tam == 0` y listaste con índice `i + 1`.
* ⚠️ **A mejorar (-8%):**
  - **Falta del informe totalizador (`SosaNoelia-PARCIAL3.cpp`, L101-108):**  
    Incrementaste `RendimientoOptimo++`, pero al terminar el bucle no imprimiste en pantalla la cantidad de aerogeneradores que alcanzaron el rendimiento óptimo.

### 3. Búsqueda Secuencial (`BuscarPotencia`) (10% / 15%)
* ✅ **Logrado:**
  - Recorrido secuencial con salida inmediata ante el hallazgo.
* ⚠️ **A mejorar (-5%):**
  - **Error off-by-one en límite superior (`SosaNoelia-PARCIAL3.cpp`, L111):**  
    Pusiste `i < tam - 1`, por lo que el último elemento (`arr[tam - 1]`) jamás es examinado por la búsqueda:
    ```cpp
    // Líneas 111-116
    for(int i=0; i<tam-1; i++){ // ¡Debe ser i < tam!
        if(arr[i]==valorBuscado){
            return i; 
        }
    }
    ```

### 4. Eliminación Física Shift-Left (`DarDeBajaAerogenerador`) (8% / 25%)
* ✅ **Logrado:**
  - Reutilizaste modularmente `BuscarPotencia`.
* ⚠️ **A mejorar (-17%):**
  - **Corrimiento desde posición cero y lectura fuera de rango (`SosaNoelia-PARCIAL3.cpp`, L132-135):**  
    El bucle debe iniciar en la posición donde se encontró el elemento (`i = pos`). Al iniciarlo en `i = 0`, sobreescribiste el elemento `arr[0]` con `arr[1]` y corriste todo el arreglo. Además, al llegar a `i = tam - 1`, hiciste `arr[tam - 1] = arr[tam]`, leyendo memoria basura:
    ```cpp
    // Líneas 132-135
    for (int i=0; i<tam; i++){ // ¡Error grave! Debe ser: for (int i = pos; i < tam - 1; i++)
        arr[i]=arr[i+1];
    }
    tam--;
    ```

### 5. Estadísticas con Guarda (`CalcularEstadisticas`) (0% / 15%)
* ⚠️ **A mejorar (-15%):**
  - Función no implementada.

---

## 💡 Recomendaciones de Mejora

1. **Cómo estructurar correctamente un `while` de validación:**  
   La lectura de corrección debe estar ADENTRO de las llaves del `while`:
   ```cpp
   while (RangoOperativo < MIN_POTENCIA || RangoOperativo > MAX_POTENCIA) {
       cout << "Rango invalido. Ingrese nuevamente (50.0 - 600.0 kW): ";
       cin >> RangoOperativo;
   }
   ```
2. **El desplazamiento en Shift-Left:**  
   Nunca comiences en `0` a menos que `pos` sea `0`. La regla es:
   ```cpp
   for (int i = pos; i < tam - 1; i++) {
       arr[i] = arr[i + 1];
   }
   tam--;
   ```
