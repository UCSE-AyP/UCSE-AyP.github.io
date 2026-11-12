# Devolución de Examen: Recuperatorio Integral (Módulos 3 y 4)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Palavecino Orellana, Ignacio Matías
- **Archivos Entregados:** `parcial 3 tema 1 palavecino orellana.cpp` (Módulo 3, Tema 1) y `parcial 4 tema 1 palavecino orellana.cpp` (Módulo 4, Tema 1)
- **Tema Asignado:** Tema 1 (*Parque Solar Cauchari* en M3 / *Gestión de Inventario de Tienda* en M4)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Estado de Compilación:** Módulo 3 compila con advertencias; Módulo 4 no compila por código truncado en el switch de `main()` y falta de punto y coma al declarar el struct.
- **Calificación Global:** **M3: 3 (Insuficiente - 58%) / M4: 2 (No Aprobado - 34% [Lab: 14/75 + Escrita: 20/25])**

---

Hola **Ignacio**, a continuación te comparto la devolución consolidada de tu examen integral. Tu desempeño arrojó un **58% / 100% en el Módulo 3 (Nota UCSE: 3 - Insuficiente)**, quedando a tan solo 2 puntos de aprobar arreglos unidimensionales, y **34 / 100 puntos (34.0% - Nota UCSE: 2 - No Aprobado) en el Módulo 4**, compuesto por **14.0 / 75 puntos en laboratorio C++** y un muy buen desempeño de **20 / 25 puntos (80%) en la evaluación escrita en papel A4**, donde realizaste correctamente casi toda la traza de ordenamiento.

En el **Módulo 3** demostraste un avance muy valioso: implementaste una búsqueda secuencial impecable (15/15%), realizaste una carga controlada sólida con validación `while` y un listado estructurado con filtro. Sin embargo, en la baja física no reutilizaste la búsqueda, dejaste la variable `pos` sin inicializar y decrementaste `tam--` dentro del bucle dañando la estructura del arreglo; en las estadísticas no actualizaste el máximo y omitiste el `return` en la guarda de arreglo vacío.  
En el **Módulo 4**, por su parte, declaraste muy bien los campos del struct pero olvidaste el punto y coma de cierre, y en lugar de codificar las 4 funciones nucleares en el espacio designado, intentaste programar la lógica directamente adentro del `switch` de `main()` de manera incompleta.

---

## 📊 1. Resumen de Calificación — Módulo 3: Arreglos en C++ (Tema 1)

| Criterio Evaluado | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **1. Carga Controlada (`RegistrarInversor`)** | 25% | **18%** | Validación con `while` e inserción correcta. La condición `tam > capacidad` permite el ingreso en `tam == 15` generando desbordamiento fuera de rango (`tam >= capacidad`). |
| **2. Recorrido y Filtro (`ListarInversores`)** | 20% | **15%** | Protege `tam == 0` y filtra con `arr[i] > umbralAltaIrradiacion`. Colocó el mensaje del total acumulado adentro del ciclo `for` en lugar de imprimirlo al final. |
| **3. Búsqueda Secuencial (`BuscarMedicion`)** | 15% | **15%** | **Excelente:** Recorrido lineal con salida temprana inmediata y valor centinela `-1`. |
| **4. Eliminación Física (*Shift-Left*) (`DarDeBajaInversor`)** | 25% | **5%** | No invoca `BuscarMedicion`. Variable `pos` no inicializada. Bucle `for` con condición `i < tam - 1 - i` y decremento `tam--` adentro del bucle en cada iteración. |
| **5. Estadísticas con Guarda (`CalcularEstadisticas`)** | 15% | **5%** | Protege con mensaje `tam == 0` pero no retorna (continúa y divide por cero). Variable `maximo` se inicializa pero jamás se actualiza en el bucle. |
| **SUBTOTAL MÓDULO 3** | **100%** | **58%** | **Rendimiento cercano a la aprobación (requiere afianzar baja física y estadísticas).** |

---

## 🔍 Desglose Técnico por Criterio — Módulo 3

### 1. Carga Controlada (`RegistrarInversor`) (18% / 25%)
* ✅ **Logrado:**
  - Validaste el rango numérico `[15.0, 250.0]` con ciclo interactivo `while`.
  - Asignaste en `arr[tam]` e incrementaste `tam++` por referencia.
* ⚠️ **A mejorar (-7%):**
  - **Condición de desbordamiento de capacidad (`parcial 3 tema 1 palavecino orellana.cpp`, L73-75):**  
    Pusiste `if (tam > capacidad)` en vez de `>=`. Si `tam` llega a 15 (`CAPACIDAD`), la condición da falsa, permitiendo que el usuario ingrese un valor y se escriba en `arr[15]`, que está fuera del arreglo:
    ```cpp
    // Líneas 73-75
    void RegistrarInversor(float arr[], int &tam, int capacidad){
        if (tam>capacidad){ // ¡Debe ser: if (tam >= capacidad)!
            cout<<"arreglo esta lleno"<<endl;
            return;
        }
    ```

### 2. Recorrido y Filtro (`ListarInversores`) (15% / 20%)
* ✅ **Logrado:**
  - Protegiste `tam == 0` y aplicaste el filtro estricto `arr[i] > umbralAltaIrradiacion`.
* ⚠️ **A mejorar (-5%):**
  - **Mensaje totalizador dentro del bucle (`parcial 3 tema 1 palavecino orellana.cpp`, L100-108):**  
    Colocaste `cout << "total con radiacion alta: " << contadorALta;` adentro del `for`, imprimiendo el total repetidas veces en cada vuelta:
    ```cpp
    // Líneas 100-108
    for(int i=0;i<tam;i++){
        cout<<"posicion [ "<<i<<" ]"<<arr[i]<<endl;
        if (arr[i]>umbralAltaIrradiacion){
            cout<<"alta radiacion"<<endl;
            contadorAlta++;
        }
        cout<<"total con radiacion alta: "<<contadorALta; // ¡Debe ir AFUERA del for!
    }
    ```

### 3. Búsqueda Secuencial (`BuscarMedicion`) (15% / 15%)
* ✅ **Logrado:**
  - **100% Logrado:** Búsqueda lineal pulcra con corte temprano ante el primer hallazgo y retorno de `-1`:
    ```cpp
    // Líneas 112-118
    int  BuscarMedicion(const float arr[], int tam, float valorBuscado){
        for (int i=0;i<tam;i++){
            if (arr[i]== valorBuscado){
                return i;
            }
        }
        return -1;	
    }
    ```

### 4. Eliminación Física Shift-Left (`DarDeBajaInversor`) (5% / 25%)
* ⚠️ **A mejorar (-20%):**
  - **Variable sin inicializar y decremento dentro del bucle (`parcial 3 tema 1 palavecino orellana.cpp`, L120-138):**  
    Pediste la variable `buscar` por teclado pero jamás llamaste a `BuscarMedicion`. Evaluaste `if (pos == -1)` con `pos` conteniendo basura de memoria. Luego, en el bucle pusiste `tam--` adentro, provocando que el arreglo reduzca su tamaño en cada paso del corrimiento:
    ```cpp
    // Líneas 120-136
    void DarDeBajaInversor(float arr[], int &tam){
        int pos, i; // 'pos' no está inicializada
        // ...
        if (pos==-1){ // 'pos' nunca recibió el resultado de BuscarMedicion
            cout<<"medicion no encontrada";
            return;
        }
        for (int pos=0 ; i<tam-1-i; i++){ // Redefinición de 'pos' y condición corrupta
            arr[i]=arr[i+1];
            tam--; // ¡Peligro! 'tam--' debe ejecutarse UNA SOLA VEZ fuera del bucle
        }
    ```

### 5. Estadísticas con Guarda (`CalcularEstadisticas`) (5% / 15%)
* ⚠️ **A mejorar (-10%):**
  - **Falta de return en guarda y máximo no actualizado (`parcial 3 tema 1 palavecino orellana.cpp`, L140-158):**  
    Si `tam == 0`, muestras el mensaje pero la función sigue de largo y ejecuta `suma / tam`, provocando división por cero. Además, en el bucle no comparas para actualizar `maximo`:
    ```cpp
    // Líneas 142-154
    if (tam==0){
        cout<<"no hay inversor"<<endl;
        // ¡Falta return! Sigue y divide por cero en promedio = suma/tam
    }
    float suma=0, maximo=arr[0];
    int posmax=0;
    for(int i;i<tam;i++){ // 'i' sin inicializar en 0 (int i = 0)
        suma+=arr[i];
        // ¡Falta if (arr[i] > maximo) { maximo = arr[i]; posmax = i; }!
    }
    if (arr[i]==maximo){ posmax=arr[i]; } // Fuera de rango y asigna el valor al índice
    ```

---

## 📊 2. Resumen de Calificación — Módulo 4: AoS y Ordenamiento (Tema 1)

| Bloque Evaluativo (75% C++) | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **Bloque 1: Struct Primitivo AoS** | 10% | **8.0%** | Declaró todos los campos primitivos en orden correcto. Omitió el punto y coma final al cerrar la llave del struct (`};`). |
| **Bloque 2: Inserción Posicional (*Right-Shift*)** | 20% | **4.0%** | No implementó `insertarProducto()`. Intentó programar validaciones en el case 3 de `main()` pero quedó truncado. |
| **Bloque 3: Modificación *in-place* (PK Inmutable)** | 15% | **2.0%** | No implementó `modificarProducto()`. Lógica parcial en case 4 sin función modular. |
| **Bloque 4: Burbuja Mejorada e Intercambio** | 30% | **0.0%** | No implementó `intercambiar` ni `ordenarPorPrecioBaseBurbujaAsc`. |
| **SUBTOTAL LABORATORIO C++** | **75%** | **14.0 / 75 pts** | **Rendimiento técnico del 18.7% en C++.** |
| **Instancia Escrita Individual (Papel A4)** | 25% | **20.0% (20 / 25)** | **Muy Bueno:** Traza paso a paso de Selección Directa en papel A4 desarrollada con gran claridad y rigor. |
| **TOTAL MÓDULO 4** | **100%** | **34.0% (Nota UCSE: 2)** | **No Aprobado (rango 0 - 39%).** |

---

## 🔍 Desglose Técnico por Criterio — Módulo 4

### Bloque 1: Struct `ProductoTienda` (8.0% / 10%)
* ⚠️ **A mejorar (-2%):**
  - **Falta de punto y coma en cierre de estructura (`parcial 4 tema 1 palavecino orellana.cpp`, L7-14):**  
    Los campos y tipos son perfectos, pero al omitir el `;` tras la llave de cierre el compilador arroja error de sintaxis:
    ```cpp
    // Líneas 7-14
    struct ProductoTienda {
        int codigo;
        int stock;
        char categoria;
        double precioBase;
        double valorUnitario;
        double valorStock;
    } // ¡Falta punto y coma ';' obligatorio aquí!
    ```

### Bloques 2, 3 y 4: Funciones Nucleares de Módulo 4 (6.0% / 65%)
* ⚠️ **A mejorar (-59%):**
  - **Funciones no implementadas en el espacio modular (`parcial 4 tema 1 palavecino orellana.cpp`, L144-149):**  
    El espacio reservado para las 4 funciones nucleares quedó totalmente vacío. Intentaste escribir el código directamente adentro de `main()`:
    ```cpp
    // Líneas 144-149: Quedó en blanco
    // =========================================================================
    // ESPACIO PARA DESARROLLO DE FUNCIONES POR PARTE DEL ESTUDIANTE
    // =========================================================================
    ```

---

## 💡 Recomendaciones de Mejora

1. **Reutiliza siempre las funciones que ya programaste:**  
   En `DarDeBajaInversor`, el primer paso debe ser llamar a la búsqueda:
   ```cpp
   int pos = BuscarMedicion(arr, tam, valorABorrar);
   if (pos == -1) {
       cout << "Medicion no encontrada." << endl;
       return;
   }
   for (int i = pos; i < tam - 1; i++) {
       arr[i] = arr[i + 1];
   }
   tam--; // Afuera del bucle, una sola vez
   ```
2. **Cuidado con el límite de capacidad:**  
   Siempre evalúa `if (tam >= capacidad)` para no permitir que el índice alcance el tamaño físico del arreglo.
3. **No traslades la lógica de las funciones al `main()`:**  
   En exámenes modulares, el `switch` de `main()` solo debe encargarse de pedir los datos al usuario y llamar a la función técnica desarrollada.
