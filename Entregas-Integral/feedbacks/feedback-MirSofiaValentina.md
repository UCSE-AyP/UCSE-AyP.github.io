# Devolución de Examen: Recuperatorio Integral (Módulos 3 y 4)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Mir, Sofía Valentina
- **Archivos Entregados:** `3erParcial-MirSofiaValentina.cpp` (Módulo 3, Tema 1) y `4toParcial-MirSofiaValentina.cpp` (Módulo 4, Tema 1)
- **Tema Asignado:** Tema 1 (*Parque Solar Cauchari* en M3 / *Gestión de Inventario de Tienda* en M4)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Condición Final de la Cursada:** **NO REGULAR**
- **Estado de Compilación:** Compila con advertencias de variables no inicializadas y funciones sin valor de retorno en todos sus caminos.
- **Calificación Global:** **M3: 2 (No Aprobado - 22%) / M4: 2 (No Aprobado - 18% [Lab: 18/75 + Escrita: 0/25])**

---

Hola **Sofía**, a continuación te comparto la devolución consolidada de tu examen integral. Tu calificación final global es de **2 / 10 (No Aprobado)**, compuesta por un **22% / 100% en el Módulo 3 (Nota 2)** y **18 / 100 puntos (18.0% - Nota 2) en el Módulo 4**, compuesto por **18.0 / 75 puntos en laboratorio C++** y **0 / 25 puntos (0%) en la evaluación escrita en papel A4** (traza de Selección Directa no realizada o no entregada).

Se valora positivamente que declaraste con total precisión la estructura `ProductoTienda` respetando los tipos primitivos solicitados y que planteaste las cabeceras de las funciones principales. Sin embargo, en ambos módulos las rutinas críticas quedaron incompletas o presentan errores de lógica graves: en Módulo 3 omitiste el listado, el borrado no realiza la compactación *Shift-Left* y no incrementas el tamaño lógico al registrar; en Módulo 4 la inserción no desplaza ni inserta, no implementaste la modificación y el ordenamiento compara estructuras directamente llamando a un intercambio con variables inexistentes.

A continuación encontrarás el desglose exhaustivo de cada criterio evaluado junto con las líneas exactas de tu entrega y las recomendaciones para que puedas corregir estos conceptos.

---

## 📊 1. Resumen de Calificación — Módulo 3: Arreglos en C++ (Tema 1)

| Criterio Evaluado | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **1. Carga Controlada (`RegistrarInversor`)** | 25% | **5%** | Valida el rango con `while`, pero si se supera la capacidad solo muestra mensaje y continúa, acumula sobre memoria sin inicializar y nunca incrementa `tam`. |
| **2. Recorrido y Filtro (`ListarInversores`)** | 20% | **0%** | La función fue entregada completamente vacía `{}`. |
| **3. Búsqueda Secuencial (`BuscarMedicion`)** | 15% | **10%** | Búsqueda lineal con salida temprana correcta, pero con error de límite (*off-by-one* `tam-1`) que ignora el último elemento. |
| **4. Eliminación Física (*Shift-Left*) (`DarDeBajaInversor`)** | 25% | **2%** | Lee un `int` en lugar de `float`, no reutiliza `BuscarMedicion` y solo decrementa `tam--` sin desplazar ningún elemento a la izquierda. |
| **5. Estadísticas con Guarda (`CalcularEstadisticas`)** | 15% | **5%** | Protege `tam == 0`, pero `acumulador` no está inicializado (basura en RAM), calcula solo el promedio y omite completamente el cálculo del máximo y su posición. |
| **SUBTOTAL MÓDULO 3** | **100%** | **22%** | **Rendimiento insuficiente en arreglos unidimensionales.** |

---

## 🔍 Desglose Técnico por Criterio — Módulo 3

### 1. Carga Controlada y Validación de Límites (`RegistrarInversor`) (5% / 25%)
* ✅ **Logrado:**
  - Implementaste la validación del rango numérico `[15.0, 250.0]` mediante un ciclo interactivo `while`.
* ⚠️ **A mejorar (-20%):**
  - **Falta de corte ante saturación y no incremento de tamaño (`3erParcial-MirSofiaValentina.cpp`, L101-115):**  
    Verificas `if (tam >= capacidad)` pero no retornas, de modo que el programa sigue ejecutando la lectura. Además, haces `arr[tam] = arr[tam] + valor;` (acumulando sobre una celda que contiene basura) y jamás ejecutas `tam++;`, por lo que el arreglo nunca registra elementos nuevos:
    ```cpp
    // Líneas 101-113
    if(tam>=capacidad){
        cout<<"la capacidad a sido superada"<<endl;
        // ¡Falta return! Continúa ejecutando y puede desbordar el arreglo
    }
    float valor;
    cout<<"ingrese una valor"<<endl;
    cin>>valor;
    while(valor<15.0||valor>250.0){
        cout<<"valor fuera de rango"<<endl;
        cout<<"ingrese otro valor"<<endl;
        cin>>valor;
    }
    arr[tam]=arr[tam]+valor; // ¡Debe ser asignación directa: arr[tam] = valor;!
    // ¡Falta tam++;! El tamaño lógico permanece en 0
    ```

### 2. Recorrido y Filtro Estricto por Umbral (`ListarInversores`) (0% / 20%)
* ⚠️ **A mejorar (-20%):**
  - **Función vacía (`3erParcial-MirSofiaValentina.cpp`, L117):**  
    Entregaste la función con el cuerpo vacío. Te faltó verificar `if (tam == 0)`, iterar con `for (int i = 0; i < tam; i++)`, marcar con etiqueta los registros con `arr[i] > 140.0f` y totalizar los que cumplieron la condición:
    ```cpp
    // Línea 117
    void ListarInversores(const float arr[], int tam, float umbralAltaIrradiacion){}
    ```

### 3. Búsqueda Secuencial (`BuscarMedicion`) (10% / 15%)
* ✅ **Logrado:**
  - Planteaste un recorrido secuencial retornando inmediatamente el índice `i` ante la coincidencia y `-1` al finalizar el bucle.
* ⚠️ **A mejorar (-5%):**
  - **Error de límite superior off-by-one (`3erParcial-MirSofiaValentina.cpp`, L120):**  
    Pusiste `i < tam - 1`, lo que hace que el último elemento válido del arreglo (`arr[tam - 1]`) nunca sea inspeccionado:
    ```cpp
    // Líneas 120-125
    for(int i=0; i<tam-1; i++){ // ¡Debe ser i < tam!
        if(arr[i]==valorBuscado){
            return i;
        }
    }
    return -1;
    ```

### 4. Eliminación Física Shift-Left (`DarDeBajaInversor`) (2% / 25%)
* ⚠️ **A mejorar (-23%):**
  - **Ausencia de corrimiento Shift-Left y falta de reutilización modular (`3erParcial-MirSofiaValentina.cpp`, L128-137):**  
    No reutilizaste la función `BuscarMedicion`. Solicitaste por teclado `int valorBorrar` perdiendo los decimales de la medición `float`, y ante el hallazgo únicamente decrementaste `tam--`. Si el elemento borrado está al principio o en el medio, simplemente ocultas el último valor del arreglo y el elemento supuestamente eliminado sigue existiendo:
    ```cpp
    // Líneas 128-137
    void DarDeBajaInversor(float arr[], int &tam){
        int valorBorrar; // ¡Debe ser float!
        cout<<"ingrese el valor que quiera borrar"<<endl;
        cin>>valorBorrar;
        for(int i=0; i<tam-1; i++){
            if(arr[i]==valorBorrar){
                tam--; // ¡No desplazas los elementos! Faltó for (int k = pos; k < tam - 1; k++) arr[k] = arr[k+1];
            }
        }
    }
    ```

### 5. Estadísticas con Guarda (`CalcularEstadisticas`) (5% / 15%)
* ✅ **Logrado:**
  - Validaste la guarda `if (tam == 0)` protegiendo contra división por cero en el promedio.
* ⚠️ **A mejorar (-10%):**
  - **Variable acumuladora sin inicializar y omisión de valor máximo (`3erParcial-MirSofiaValentina.cpp`, L145-151):**  
    Declaraste `float acumulador;` sin inicializar en `0.0f`, sumando sobre memoria residual arbitraria. Además, no buscaste el valor máximo de irradiación ni su posición en el arreglo:
    ```cpp
    // Líneas 145-151
    float acumulador; // ¡Peligro! Contiene basura de la pila. Debe ser float acumulador = 0.0f;
    for(int i=0; i<tam; i++){
        acumulador=acumulador+arr[i];
    }
    cout<<"energia promedio generada: "<<acumulador/tam<<endl;
    // ¡Falta determinar maximo y posMax!
    ```

---

## 📊 2. Resumen de Calificación — Módulo 4: AoS y Ordenamiento (Tema 1)

| Bloque Evaluativo (75% C++) | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **Bloque 1: Struct Primitivo AoS** | 10% | **10.0%** | Definición perfecta de `ProductoTienda` con los 6 campos requeridos, tipos primitivos y orden exacto. |
| **Bloque 2: Inserción Posicional (*Right-Shift*)** | 20% | **3.0%** | Validó la guarda de límites con `if`, pero el bloque `else` quedó vacío sin verificar clave única, sin desplazar y sin insertar. |
| **Bloque 3: Modificación *in-place* (PK Inmutable)** | 15% | **0.0%** | Solo dejaste la declaración del prototipo en L117 sin implementar la función. |
| **Bloque 4: Burbuja Mejorada e Intercambio** | 30% | **5.0%** | `intercambiar` altera la firma a 3 parámetros y sobreescribe `a=b` sin resguardo. En `ordenar` comparas structs enteros y pasas identificadores inexistentes. |
| **SUBTOTAL LABORATORIO C++** | **75%** | **18.0 / 75 pts** | **Rendimiento técnico del 24.0% en programación de estructuras.** |
| **Instancia Escrita Individual (Papel A4)** | 25% | **0.0% (0 / 25)** | Traza manual de Selección Directa en papel A4: no desarrollada o no entregada. |
| **TOTAL MÓDULO 4** | **100%** | **18.0% (Nota UCSE: 2)** | **No Aprobado (rango 0 - 39%).** |

---

## 🔍 Desglose Técnico por Criterio — Módulo 4

### Bloque 1: Declaración de Struct `ProductoTienda` (10.0% / 10%)
* ✅ **Logrado:**
  - Declaraste correctamente la estructura respetando tipos primitivos y el orden exacto para compatibilidad con la inicialización en `main()` (`4toParcial-MirSofiaValentina.cpp`, L11-19):
    ```cpp
    struct ProductoTienda {
        int codigo;
        int stock;
        char categoria;
        double precioBase;
        double valorUnitario;
        double valorStock;
    };
    ```

### Bloque 2: Inserción con Unicidad y Right-Shift (`insertarProducto`) (3.0% / 20%)
* ✅ **Logrado:**
  - Planteaste la validación de saturación física y rango de índice `if (tam >= capacidad || pos < 0 || pos > tam)`.
* ⚠️ **A mejorar (-17%):**
  - **Cuerpo de función incompleto (`4toParcial-MirSofiaValentina.cpp`, L107-116):**  
    El bloque `else` quedó totalmente en blanco. No llamaste a `buscarPorCodigo` para rechazar claves duplicadas, no hiciste el desplazamiento contiguo a la derecha (`for (int i = tam; i > pos; --i) arr[i] = arr[i - 1];`), no asignaste `arr[pos] = nuevo;` ni incrementaste `tam++`:
    ```cpp
    // Líneas 107-115
    bool insertarProducto(ProductoTienda arr[], int &tam, int capacidad, int pos, const ProductoTienda &nuevo){
        if(tam>=capacidad||pos<0||pos>tam){
            cout<<" [error] "<<endl; 
            return false; 
        }
        else{
            // ¡Quedó vacío! No hay búsqueda de unicidad, ni Right-Shift, ni asignación, ni tam++
        }
    }
    ```

### Bloque 3: Modificación in-place con Clave Primaria Inmutable (`modificarProducto`) (0.0% / 15%)
* ⚠️ **A mejorar (-15%):**
  - **Función no implementada (`4toParcial-MirSofiaValentina.cpp`, L117):**  
    Solo figura la declaración del prototipo:
    ```cpp
    // Línea 117
    bool modificarProducto(ProductoTienda arr[], int tam, const ProductoTienda &actualizado);
    ```

### Bloque 4: Ordenamiento Burbuja e Intercambio (`ordenarPorPrecioBaseBurbujaAsc`) (5.0% / 30%)
* ⚠️ **A mejorar (-25%):**
  - **Firma incorrecta y pérdida de datos en `intercambiar` (`4toParcial-MirSofiaValentina.cpp`, L101-105):**  
    Modificaste los parámetros agregando `ProductoTienda aux`, pero adentro declaras `ProductoTienda aux=0;` (incompatible con structs) y asignas `a=b; b=aux;` perdiendo el valor original de `a`:
    ```cpp
    // Líneas 101-105
    void intercambiar(ProductoTienda &a, ProductoTienda &b, ProductoTienda aux){
        ProductoTienda aux=0; // Error de tipo
        a=b; // Se destruye el contenido original de 'a' antes de respaldarlo
        b=aux; 
    }
    ```
  - **Comparación de estructuras completas y variables no declaradas (`4toParcial-MirSofiaValentina.cpp`, L119-129):**  
    En C++ no se pueden comparar structs con `arr[j] > arr[j+1]`; debes comparar el miembro numérico `arr[j].precioBase > arr[j+1].precioBase`. Además, llamaste a `intercambiar(a, b, aux)` pasando variables que no existen en ese ámbito:
    ```cpp
    // Líneas 119-129
    void ordenarPorPrecioBaseBurbujaAsc(ProductoTienda arr[], int tam){
        bool huboIntercambio=false;
        for(int i=0; i<tam-1; i++ ){
            for(int j=0; j<tam-1; j++){
                if(arr[j]>arr[j+1]){ // Error: comparación entre structs completos
                    intercambiar(a ,b, aux); // Error: 'a', 'b', 'aux' no existen aquí
                }
            } 
        }
    }
    ```

---

## 💡 Recomendaciones de Mejora

1. **Afianza el algoritmo de Shift-Left (Baja) y Shift-Right (Alta):**
   - Para eliminar un elemento en `pos`:
     ```cpp
     for (int i = pos; i < tam - 1; i++) {
         arr[i] = arr[i + 1];
     }
     tam--;
     ```
   - Para insertar un elemento en `pos`:
     ```cpp
     for (int i = tam; i > pos; i--) {
         arr[i] = arr[i - 1];
     }
     arr[pos] = nuevo;
     tam++;
     ```
2. **Implementa siempre la función de intercambio clásica por referencia:**
   ```cpp
   void intercambiar(ProductoTienda &a, ProductoTienda &b) {
       ProductoTienda aux = a;
       a = b;
       b = aux;
   }
   ```
3. **Inicializa siempre las variables acumuladoras y extremas antes de utilizarlas (`float suma = 0.0f;`).**

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
