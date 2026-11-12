# Devolución de Examen: 3er Recuperatorio Parcial (Módulo 3: Arreglos en C++)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Gallardo, Tiziana
- **Archivo Entregado:** `GallardoTiziana3erParcial.cpp`
- **Tema Asignado:** Tema 2 (*Parque Eólico Rawson*)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Estado de Compilación:** Compilación limpia y sin advertencias bajo C++17.
- **Calificación Final:** **10 (Diez) — SOBRESALIENTE (97% / 100%)**

---

Hola **Tiziana**, ¡felicitaciones! Tu examen práctico fue **excepcional**, alcanzando una calificación de **97% / 100% (Nota final: 10 - Sobresaliente)**.

Demostraste un dominio técnico sobresaliente de los algoritmos fundamentales sobre arreglos unidimensionales en C++. Tu código es limpio, modular, respeta estrictamente los prototipos provistos y maneja con elegancia y solidez matemática los casos borde: validaste la capacidad y el rango con total precisión, la búsqueda lineal cuenta con corte temprano, la compactación *Shift-Left* es de libro de texto y las estadísticas protegen contra división por cero obteniendo tanto el promedio como el mínimo con su índice correspondiente. El único detalle menor fue un desliz tipográfico al incrementar el valor del umbral en pantalla en lugar del contador de aerogeneradores destacados.

A continuación te comparto el desglose detallado de tu evaluación.

---

## 📊 Calificación Final y Resumen de Evaluación

| Criterio Evaluado | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **1. Carga Controlada (`RegistrarAerogenerador`)** | 25% | **25%** | **Impecable:** Protección estricta `tam >= capacidad`, validación con `while` de rango `[50.0, 600.0]`, asignación e incremento `tam++`. |
| **2. Recorrido y Filtro (`ListarAerogeneradores`)** | 20% | **17%** | Protege `tam == 0`, lista ordenadamente y filtra con `arr[i] > umbralOptimo`. Desliz menor: incrementó el parámetro `umbralOptimo++` en vez de la variable contadora. |
| **3. Búsqueda Secuencial (`BuscarPotencia`)** | 15% | **15%** | **Excelente:** Recorrido secuencial con salida temprana inmediata y valor centinela `-1`. |
| **4. Eliminación Física (*Shift-Left*) (`DarDeBajaAerogenerador`)** | 25% | **25%** | **Impecable:** Protege `tam == 0`, reutiliza `BuscarPotencia`, realiza la compactación perfecta `arr[i] = arr[i + 1]` y decrementa `tam--`. |
| **5. Estadísticas con Guarda (`CalcularEstadisticas`)** | 15% | **15%** | **Impecable:** Guarda contra división por cero, acumulador float inicializado, cálculo de promedio y búsqueda rigurosa de mínimo y `posmin`. |
| **TOTAL FINAL** | **100%** | **97% (Nota 10)** | **Aprobado con Calificación Sobresaliente.** |

---

## 🔍 Desglose Técnico por Criterio

### 1. Carga Controlada y Validación de Límites (`RegistrarAerogenerador`) (25% / 25%)
* ✅ **Logrado:**
  - **100% Logrado:** Verificación impecable de capacidad con mensaje descriptivo y retorno inmediato (`GallardoTiziana3erParcial.cpp`, L78-94):
    ```cpp
    void RegistrarAerogenerador(float arr[], int &tam, int capacidad){
        if(tam>=capacidad){
            cout<<"ERROR:CAPACIDAD MAXIMA ALCANZADA"<<capacidad<<" Aerogeneradores.No se pueden cargas mas registros"<<endl;
            return;
        }
        float pot;
        cout<<"ingrese potencia(kw):";
        cin >> pot;
        while(pot<MIN_POTENCIA || pot>MAX_POTENCIA){	
            cout<<"Valor fuera de rango.Ingrese entre 50.0 y 600.0 kw: ";
            cin >> pot;
        }
        arr[tam]=pot;
        cout<<"REGISTRO agregado en la posicion "<< tam << ".Total activos:"<< tam+1 <<"
"<<capacidad << endl;
        tam++;
    }
    ```

### 2. Recorrido y Filtro Estricto por Umbral (`ListarAerogeneradores`) (17% / 20%)
* ✅ **Logrado:**
  - Guarda de arreglo vacío `tam == 0` con `return;`.
  - Recorrido completo `for (int i = 0; i < tam; i++)` formateando cada elemento con su índice.
  - Filtro estricto `arr[i] > umbralOptimo`.
* ⚠️ **A mejorar (-3%):**
  - **Mutación del parámetro de umbral en lugar del contador (`GallardoTiziana3erParcial.cpp`, L103, 109, 113):**  
    Declaraste `int contoptimo = 0;`, pero adentro del `if` hiciste `cout << umbralOptimo++;` y al final imprimiste `umbralOptimo` en vez de `contoptimo`. Esto provocó que el umbral aumentara en cada vuelta en lugar de acumular la cantidad de aerogeneradores:
    ```cpp
    // Líneas 103-113
    int contoptimo=0;
    // ...
    if(arr[i]>umbralOptimo){
        cout<<"[Rendimiento optimo]:";
        cout<< umbralOptimo++; // ¡Mutaste el umbral! Debió ser: contoptimo++;
    }
    cout<<"Aerogeneradores en rendimiento optimo(>350.00kW): "<< umbralOptimo <<endl; // Debió ser contoptimo
    ```

### 3. Búsqueda Secuencial (`BuscarPotencia`) (15% / 15%)
* ✅ **Logrado:**
  - **100% Logrado:** Búsqueda lineal canónica (`GallardoTiziana3erParcial.cpp`, L116-123):
    ```cpp
    int BuscarPotencia(const float arr[], int tam, float valorBuscado){
        for(int i=0;i<tam;i++){
            if(arr[i]==valorBuscado){
                return i;	
            }
        }
        return -1;
    }
    ```

### 4. Eliminación Física Shift-Left (`DarDeBajaAerogenerador`) (25% / 25%)
* ✅ **Logrado:**
  - **100% Logrado:** Reutilización modular de `BuscarPotencia`, corrimiento hacia la izquierda exacto y decremento del tamaño lógico (`GallardoTiziana3erParcial.cpp`, L124-143):
    ```cpp
    void DarDeBajaAerogenerador(float arr[], int &tam){
        if(tam==0){
            cout<<"No hay aerogeneradores registrados en el sistema"<<endl;
            return;
        }
        float valor;
        cout<<"Ingrese potencia a dar de baja kW: ";
        cin >> valor;
        int pos = BuscarPotencia(arr,tam,valor);
        if(pos==-1){
            cout<<"Potencia no encontrada en el arreglo"<<endl;
        } else {
            for(int i = pos;i<tam-1;i++){
                arr[i]=arr[i+1];
            }
            tam--;
            cout<<"Aerogenerador Eliminado (compactacion Shift-left).Total activos: "<<tam<<"/15"<<endl;
        }
    }
    ```

### 5. Estadísticas con Guarda (`CalcularEstadisticas`) (15% / 15%)
* ✅ **Logrado:**
  - **100% Logrado:** Guarda inicial para evitar división por cero, acumulador `float suma = 0.0f;`, inicialización correcta de `minimo = arr[0]; posmin = 0;` y reporte detallado de métricas (`GallardoTiziana3erParcial.cpp`, L144-163).

---

## 💡 Recomendaciones de Mejora

1. **Revisión de variables contadoras:**  
   Cuando crees un contador como `int contoptimo = 0;`, asegúrate en el cuerpo del `if` de incrementar ese mismo identificador (`contoptimo++`) y no confundirlo con el parámetro de comparación (`umbralOptimo`).
2. ¡Continúa manteniendo este excelente nivel de orden, tipado y modularidad en las materias superiores de programación!
