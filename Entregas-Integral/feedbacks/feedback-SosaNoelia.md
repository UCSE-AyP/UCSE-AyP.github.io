# Devolución de Examen: 3er Recuperatorio Parcial (Módulo 3: Arreglos en C++)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Sosa, Noelia Soledad
- **Archivo Entregado:** `SosaNoelia-PARCIAL3.cpp`
- **Tema Asignado:** Tema 2 (*Parque Eólico Rawson*)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Condición Final de la Cursada:** **NO REGULAR**
- **Estado de Compilación:** Compila con fallas lógicas críticas en tiempo de ejecución (bucle infinito colgante y guarda de carga bloqueada).
- **Calificación Final:** **1 (Uno) — NO APROBADO / REPROBADO (10% / 100%)**

---

Hola **Noelia**, a continuación te comparto la devolución formal y definitiva de tu examen de Módulo 3. Tu calificación final es de **1 / 10 (No Aprobado / Reprobado)**, habiendo alcanzado un **10% / 100%** neto, ratificando tu condición de **NO REGULAR** en la cátedra para el Ciclo Lectivo 2026.

Tras una revisión exhaustiva bajo los criterios estrictos de la rúbrica oficial, se determinó que la mayoría de los módulos evaluados presentan fallas estructurales y de ejecución graves que impiden su funcionamiento: la función de carga (`RegistrarAerogenerador`) invierte la guarda lógica bloqueando cualquier registro e incluye un ciclo infinito que congela el programa ante un valor inválido; la eliminación física (`DarDeBajaAerogenerador`) destruye siempre el primer elemento del arreglo e invade memoria basura; la búsqueda secuencial falla al omitir la última celda del vector; el listado no informa el total acumulado e imprime etiquetas incorrectas; y las estadísticas no fueron implementadas.

Al no alcanzarse los estándares mínimos de funcionamiento exigidos, no es posible otorgar puntaje en los bloques críticos, quedando la entrega reprobada sin margen de acreditación.

---

## 📊 Calificación Final y Resumen de Evaluación (Rúbrica Estricta)

| Bloque Evaluativo | Ponderación | Puntaje Obtenido | Calificación Técnica | Observaciones Principales |
| :--- | :---: | :---: | :---: | :--- |
| **1. Carga Controlada (`RegistrarAerogenerador`)** | 25% | **0%** | **Insuficiente** | **Bloque anulado (Falla Crítica):** La condición `tam < capacidad` rechaza la carga cuando hay cupo disponible, impidiendo registrar datos. Además, el `while` vacío congela la máquina en bucle infinito ante un valor fuera de rango. |
| **2. Recorrido y Filtro (`ListarAerogeneradores`)** | 20% | **5%** | **Deficiente** | Protege `tam == 0`, pero rotula erróneamente a todos los elementos como "El umbral Optimo", ignora el parámetro `umbralOptimo` y omite informar el conteo final de destacados. |
| **3. Búsqueda Secuencial (`BuscarPotencia`)** | 15% | **5%** | **Deficiente** | Búsqueda lineal incompleta por error *off-by-one* en el límite superior (`i < tam - 1`); si el valor buscado está en la última celda (`arr[tam - 1]`), la función no lo encuentra y retorna `-1`. |
| **4. Eliminación Física (*Shift-Left*) (`DarDeBajaAerogenerador`)** | 25% | **0%** | **Insuficiente** | **Bloque anulado (Corrupción de Datos):** El bucle inicia en `i = 0` en vez de `i = pos`, destruyendo siempre el elemento `arr[0]` independientemente de dónde esté el valor a borrar. Además, itera hasta `tam` leyendo memoria residual en `arr[tam]`. |
| **5. Estadísticas con Guarda (`CalcularEstadisticas`)** | 15% | **0%** | **Insuficiente** | **Bloque anulado:** Función no implementada (omitida en su totalidad). |
| **TOTAL DEFINITIVO** | **100%** | **10% (Nota 1)** | **REPROBADO** | **No Aprobado / Reprobado (Rango 0 – 39%). Condición: NO REGULAR.** |

---

## 🔍 Desglose Técnico Exhaustivo por Criterio

### 1. Carga Controlada y Validación de Límites (`RegistrarAerogenerador`) (0% / 25%)
* ⚠️ **A mejorar (-25% — Insuficiente 0%):**
  - **Condición de capacidad invertida y congelamiento por bucle infinito (`SosaNoelia-PARCIAL3.cpp`, L76-88):**  
    Pusiste `if (tam < capacidad)` para imprimir "No hay cupo disponible" y retornar. Cuando el arreglo está vacío (`tam = 0`), como `0 < 15` es verdadero, la función aborta de inmediato y **nunca permite cargar ningún dato**. Adicionalmente, el `while` de validación quedó con llaves vacías (`while(...) {}`), por lo que si se ingresa un valor fuera de rango, el programa entra en un ciclo infinito que congela la ejecución del sistema:
    ```cpp
    // Líneas 76-88: Función inoperativa y bucle infinito
    void RegistrarAerogenerador(float arr[], int &tam, int capacidad){
        if (tam< capacidad) { // ¡Condición invertida! Si hay lugar (tam < 15), rechaza la carga y sale
            cout<<"No hay cupo disponible"<<endl; 
            return; 
        }
        float RangoOperativo; 
        cout<<"Ingrese el rango operativo (50.0-600.0): ";
        cin>>RangoOperativo;  
        
        while(RangoOperativo<50 || RangoOperativo>600){
            // ¡Cuerpo vacío! Se cuelga el programa para siempre
        } 
        cout<<"Rango invalido. Ingrese otra cantidad"; 
        cin>>RangoOperativo;
    ```

---

### 2. Recorrido y Filtro Estricto por Umbral (`ListarAerogeneradores`) (5% / 20%)
* ✅ **Logrado:**
  - Guarda inicial para `tam == 0` con retorno temprano.
* ⚠️ **A mejorar (-15%):**
  - **Etiquetado confuso, parámetro ignorado y omisión de total (`SosaNoelia-PARCIAL3.cpp`, L96-109):**  
    Imprimes a cada elemento con el texto `"El umbral Optimo"`, dando a entender que todos superan la condición. Utilizaste la constante global en vez del parámetro `float umbralOptimo`, y al finalizar el bucle omitiste por completo imprimir cuántos aerogeneradores alcanzaron el rendimiento óptimo:
    ```cpp
    // Líneas 101-108
    int RendimientoOptimo=0; 
    for (int i=0; i<tam; i++){
        cout<<"El umbral Optimo"<<i+1<<": "<<arr[i]<<"kw"<<endl; // Etiqueta engañosa para todo el arreglo
        if (arr[i]>UMBRAL_RENDIMIENTO_OPTIMO ){ // Ignoró el parámetro umbralOptimo
            RendimientoOptimo++;
        }
    }
    // ¡Falta cout informando el total de RendimientoOptimo!
    ```

---

### 3. Búsqueda Secuencial (`BuscarPotencia`) (5% / 15%)
* ✅ **Logrado:**
  - Intención de recorrido lineal con corte temprano ante coincidencia.
* ⚠️ **A mejorar (-10%):**
  - **Falla en frontera superior off-by-one (`SosaNoelia-PARCIAL3.cpp`, L110-119):**  
    Pusiste `i < tam - 1`. Si un aerogenerador registrado se encuentra en la última celda del arreglo (`arr[tam - 1]`), el bucle frena antes de revisarlo y la función retorna `-1`, informando falsamente que el valor no existe:
    ```cpp
    // Líneas 111-117: Omite el último elemento
    for(int i=0; i<tam-1; i++){ // ¡Error off-by-one! Debe ser i < tam
        if(arr[i]==valorBuscado){
            return i; 
        }
    }
    return -1; 
    ```

---

### 4. Eliminación Física Shift-Left (`DarDeBajaAerogenerador`) (0% / 25%)
* ⚠️ **A mejorar (-25% — Insuficiente 0%):**
  - **Desplazamiento destructivo desde posición cero y lectura fuera de rango (`SosaNoelia-PARCIAL3.cpp`, L120-144):**  
    Invocas `BuscarPotencia`, pero al momento de desplazar ignoras la posición encontrada `pos` e inicias el bucle en `i = 0`. Esto provoca que se sobreescriba `arr[0]` con `arr[1]` y se desplace todo el arreglo desde el inicio, borrando el primer registro en lugar del elemento solicitado. Además, el bucle va hasta `i < tam`, por lo que en la última vuelta ejecuta `arr[tam - 1] = arr[tam]`, copiando basura de memoria inactiva:
    ```cpp
    // Líneas 130-137: Destruye el arreglo
    int pos=BuscarPotencia(arr, tam, valorBuscado); 
    if (pos !=-1){
        cout<<"Potencia encontrada con exito"; 
        for (int i=0; i<tam; i++){ // ¡FATAL! Inicia en 0 (debe ser i = pos) y va hasta tam (debe ser tam - 1)
            arr[i]=arr[i+1];
        }
        tam--; 
        cout<<"Aerogenerador eliminado"<<endl; 
    ```

---

### 5. Estadísticas con Guarda (`CalcularEstadisticas`) (0% / 15%)
* ⚠️ **A mejorar (-15% — Insuficiente 0%):**
  - **Función no desarrollada:**  
    Omitiste completamente la implementación de la función; no se calcula promedio ni mínimo.

---

## 💡 Recomendaciones de Mejora

1. **Condición de guarda correcta para evitar desbordamiento:**  
   Para rechazar la carga cuando el arreglo está saturado, debes verificar si el tamaño alcanzó o superó la capacidad física:
   ```cpp
   if (tam >= capacidad) {
       cout << "Capacidad maxima alcanzada (" << capacidad << "). No se pueden registrar mas datos." << endl;
       return;
   }
   ```
2. **Validación interactiva con `while`:**  
   La re-lectura del dato debe colocarse **adentro** del cuerpo del `while`:
   ```cpp
   while (RangoOperativo < MIN_POTENCIA || RangoOperativo > MAX_POTENCIA) {
       cout << "Valor fuera de rango. Ingrese entre 50.0 y 600.0 kW: ";
       cin >> RangoOperativo;
   }
   ```
3. **Algoritmo canónico de Shift-Left:**  
   El desplazamiento debe arrancar en la posición localizada `pos` y finalizar en `tam - 1`:
   ```cpp
   for (int i = pos; i < tam - 1; i++) {
       arr[i] = arr[i + 1];
   }
   tam--;
   ```

---

## 🎓 Condición Final de la Cursada y Cierre de Ciclo Lectivo 2026

- **Condición Académica Definitiva:** **NO REGULAR**
- **Coloquio Teórico:** 0
- **Situación en Actas:** Deberá recursar la asignatura en el Ciclo Lectivo 2027.

> [!NOTE]
> ### 💬 Notificación Oficial de Cierre
> Con una calificación definitiva de **10% / 100% (Nota 1 - Reprobado)**, tu condición académica final en actas es **NO REGULAR**.
> 
> Este resultado no admite solicitudes de redondeo al encontrarse a 50 puntos porcentuales del mínimo de aprobación reglamentario (60%). Deberás reinscribirte para **recursar la asignatura en el Ciclo Lectivo 2027**.
> 
> Te alentamos a utilizar el período de receso para afianzar el trazado manual de algoritmos y practicar la programación incremental en C++. La cátedra estará disponible para guiarte y acompañar tu proceso de aprendizaje desde el inicio del próximo año lectivo.
