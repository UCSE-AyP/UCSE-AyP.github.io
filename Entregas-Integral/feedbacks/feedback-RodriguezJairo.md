# Devolución de Examen: 3er Recuperatorio Parcial (Módulo 3: Arreglos en C++)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Rodríguez, Jairo
- **Archivo Entregado:** `rodriguezjairo_modulo3.cpp`
- **Tema Asignado:** Tema 1 (*Parque Solar Cauchari*)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Estado de Compilación:** Compila limpio bajo C++17.
- **Calificación Final:** **3 (Tres) — INSUFICIENTE (59% / 100%)**

---

Hola **Jairo**, a continuación te comparto la devolución detallada de tu examen de Módulo 3. Tu desempeño técnico alcanzó un **59% / 100% (Nota final: 3 - Insuficiente)**, quedando a tan solo **1 punto porcentual** del umbral mínimo de aprobación (60%).

Desarrollaste con total solidez técnica las dos primeras funciones: la carga controlada con validación `while` (`RegistrarInversor`) fue impecable (25/25%) y la búsqueda secuencial con salida temprana (`BuscarMedicion`) fue perfecta (15/15%). Asimismo, tu listado con filtro de umbral funcionó muy bien, presentando únicamente un detalle en el caso borde exacto.  
Sin embargo, no lograste alcanzar la aprobación debido a que dejaste incompleta la función de baja física (*Shift-Left*), donde solo leíste la variable pero no buscaste ni desplazaste los elementos, y omitiste por completo el desarrollo de la función de cálculo estadístico (promedio y máximo).

---

## 📊 Calificación Final y Resumen de Evaluación

| Criterio Evaluado | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **1. Carga Controlada (`RegistrarInversor`)** | 25% | **25%** | **Excelente:** Control de cupo `tam < capacidad`, validación con `while` de rango `[15.0, 250.0]`, inserción e incremento de `tam++`. |
| **2. Recorrido y Filtro (`ListarInversores`)** | 20% | **16%** | Protege `tam == 0`, lista ordenadamente y cuenta con etiqueta. Detalle borde: usa `arr[i] < umbral` en el `else`, omitiendo listar mediciones exactamente iguales a 140.0. |
| **3. Búsqueda Secuencial (`BuscarMedicion`)** | 15% | **15%** | **Excelente:** Recorrido secuencial canónico con salida anticipada y valor centinela `-1`. |
| **4. Eliminación Física (*Shift-Left*) (`DarDeBajaInversor`)** | 25% | **3%** | Protege `tam == 0` y lee la variable `pas`, pero no invoca la búsqueda, no realiza corrimiento a la izquierda ni decrementa `tam`. |
| **5. Estadísticas con Guarda (`CalcularEstadisticas`)** | 15% | **0%** | Función no implementada (comentada en el menú). |
| **TOTAL FINAL** | **100%** | **59% (Nota 3)** | **Insuficiente (a 1 punto de acreditar el módulo).** |

---

## 🔍 Desglose Técnico por Criterio

### 1. Carga Controlada y Validación de Límites (`RegistrarInversor`) (25% / 25%)
* ✅ **Logrado:**
  - **100% Logrado:** Implementación pulcra de la guarda de cupo, ciclo `while` interactivo y actualización correcta (`rodriguezjairo_modulo3.cpp`, L104-120):
    ```cpp
    void RegistrarInversor(float arr[], int &tam, int capacidad) {
        if (tam < capacidad) {
            float op;
            cout<<" ingrese valor"<<endl;
            cin>>op;
            while (op<MIN_ENERGIA||op>MAX_ENERGIA) {
                cout<<"Valor fuera de rango.Ingrese entre 15.0 y 250 kwh"<<endl;
                cin>>op;
            }
            arr[tam]=op;
            cout<<"Registro agregado en la posicion "<<tam<<endl;
            tam++;
        }
        else {
            cout<<"No hay cupo disponible"<<endl;
        }
    }
    ```

### 2. Recorrido y Filtro Estricto por Umbral (`ListarInversores`) (16% / 20%)
* ✅ **Logrado:**
  - Guarda de arreglo vacío `tam == 0`.
  - Recorrido completo y discriminación con etiqueta `[ALTA IRRADIACION]`.
* ⚠️ **A mejorar (-4%):**
  - **Omisión en listado del valor borde exacto (`rodriguezjairo_modulo3.cpp`, L137-148):**  
    Evaluaste `if (arr[i] > umbralAltaIrradiacion)` y luego en la alternativa pusiste `if (arr[i] < umbralAltaIrradiacion)`. Si una celda contiene exactamente `140.0`, ninguna de las dos ramas se cumple y ese inversor no se muestra en pantalla:
    ```cpp
    // Líneas 137-148
    for (int i=0;i<tam;i++) {
        if (arr[i]>umbralAltaIrradiacion) {
            cout<<"- ["<<i<<"] - "<<arr[i]<<  "- [ALTA IRRADIACION] - "<<endl;
            contador++;
        }
        else {
            if (arr[i]<umbralAltaIrradiacion) { // ¡Error de borde! Si arr[i] == 140.0 queda en blanco
                cout<<"- ["<<i<<"] - "<<arr[i]<<endl;
            }
        }
    }
    ```

### 3. Búsqueda Secuencial (`BuscarMedicion`) (15% / 15%)
* ✅ **Logrado:**
  - **100% Logrado:** Búsqueda lineal canónica (`rodriguezjairo_modulo3.cpp`, L159-168).

### 4. Eliminación Física Shift-Left (`DarDeBajaInversor`) (3% / 25%)
* ⚠️ **A mejorar (-22%):**
  - **Función truncada e incompleta (`rodriguezjairo_modulo3.cpp`, L177-192):**  
    Protegiste el caso `tam == 0` y leíste el dato a borrar en `pas`, pero no llamaste a `BuscarMedicion`, no hiciste el bucle `for` de corrimiento y no decrementaste `tam--`:
    ```cpp
    // Líneas 177-192
    void DarDeBajaInversor(float arr[], int &tam) {
        if (tam==0) {
            cout<<" No hay bajas"<<endl;
        }else {
            float pas;
            cout<<"ingrese valor"<<endl;
            cin>>pas;
            // ¡Incompleto! Faltó buscar, compactar y tam--
        }
    }
    ```

### 5. Estadísticas con Guarda (`CalcularEstadisticas`) (0% / 15%)
* ⚠️ **A mejorar (-15%):**
  - No implementada (comentada en líneas 71-72 de `main()`).

---

## 💡 Recomendaciones de Mejora

1. **Estructura para la Baja Física (Shift-Left):**  
   Una vez leída la medición a eliminar, debes encadenar los tres pasos fundamentales:
   ```cpp
   int pos = BuscarMedicion(arr, tam, pas);
   if (pos == -1) {
       cout << "Medicion no encontrada." << endl;
       return;
   }
   for (int i = pos; i < tam - 1; i++) {
       arr[i] = arr[i + 1];
   }
   tam--;
   ```
2. **Cuidado con las ramas en bifurcaciones:**  
   Si la condición principal es `if (arr[i] > umbral)`, en el `else` no vuelvas a preguntar `if (arr[i] < umbral)` porque dejarás afuera el valor igual al umbral (`140.0`). Usa simplemente `else { cout << ...; }`.
