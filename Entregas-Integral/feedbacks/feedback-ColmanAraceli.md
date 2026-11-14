# Devolución de Examen: Recuperatorio Integral (Módulos 3 y 4)
### Cátedra de Algoritmos y Programación — UCSE DASS
**Ciclo Lectivo 2026**

- **Estudiante:** Colman, Araceli Rafaela
- **Archivos Entregados:** `COLMAN ARACELI PARCIAL 3 TEMA 1.cpp` (Módulo 3, Tema 1) y `COLMAN ARACELI TEMA 1- PARCIAL 4.cpp` (Módulo 4, Tema 1)
- **Tema Asignado:** Tema 1 (*Parque Solar Cauchari* en M3 / *Gestión de Inventario de Tienda* en M4)
- **Fecha de Evaluación:** 12 de Noviembre de 2026
- **Condición Final de la Cursada:** **NO REGULAR**
- **Estado de Compilación:** **No compila** por código colocado fuera del cuerpo de funciones (ámbito global) y errores severos de sintaxis en cabeceras y parámetros.
- **Calificación Global:** **M3: 1 (No Aprobado - 8%) / M4: 2 (No Aprobado - 37% [Lab: 12/75 + Escrita: 25/25])**

---

Hola **Araceli**, a continuación te comparto la devolución consolidada de tu examen integral. Tu calificación global es de **2 / 10 (No Aprobado)**, compuesta por un **8% / 100% en el Módulo 3 (Nota 1)** y **37 / 100 puntos (37.0% - Nota 2) en el Módulo 4**, integrando **12.0 / 75 puntos en laboratorio C++** y un **sobresaliente 25 / 25 puntos (100%) en la evaluación escrita en papel A4**, donde realizaste con éxito la traza de ordenamiento manual.

Se evidencia que recuerdas nombres de variables y la estructura general de los algoritmos pedidos (como la intención de desplazar con un bucle decreciente `for (int i=tam; i>pos; i--)` o chequear la capacidad máxima). Sin embargo, ambas entregas presentan un problema estructural crítico: colocaste sentencias ejecutables (`if`, `while`, asignaciones, `cout`) en el ámbito global del archivo, fuera de cualquier función, lo cual en C++ constituye un error de compilación fatal inmediato. Asimismo, en el Módulo 3 omitiste tres de las cinco funciones solicitadas y en el Módulo 4 la estructura quedó desvinculada y las funciones de modificación y ordenamiento truncadas.

Es indispensable que afiances el concepto de función en C++: todo código ejecutable debe residir obligatoriamente entre las llaves `{ ... }` del cuerpo de la función correspondiente.

---

## 📊 1. Resumen de Calificación — Módulo 3: Arreglos en C++ (Tema 1)

| Criterio Evaluado | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **1. Carga Controlada (`RegistrarInversor`)** | 25% | **5%** | Encabezado terminado en punto y coma. Sentencias ejecutables escritas a nivel global fuera de la función con sintaxis rota (`"capacidad<< "bloques"`, `tam capacidad`). |
| **2. Recorrido y Filtro (`ListarInversores`)** | 20% | **3%** | Parámetro `umbralAltaIrradiacion` sin tipo de dato (`float`). Código ejecutable huérfano fuera de la función (`int contador Prime++`, `for (int =0;i< tam; i++);`). |
| **3. Búsqueda Secuencial (`BuscarMedicion`)** | 15% | **0%** | Función no implementada. |
| **4. Eliminación Física (*Shift-Left*) (`DarDeBajaInversor`)** | 25% | **0%** | Función no implementada. |
| **5. Estadísticas con Guarda (`CalcularEstadisticas`)** | 15% | **0%** | Función no implementada. |
| **SUBTOTAL MÓDULO 3** | **100%** | **8%** | **No Aprobado por fallas estructurales y funciones faltantes.** |

---

## 🔍 Desglose Técnico por Criterio — Módulo 3

### 1. Carga Controlada (`RegistrarInversor`) (5% / 25%)
* ⚠️ **A mejorar (-20%):**
  - **Punto y coma en cabecera y código fuera de función (`COLMAN ARACELI PARCIAL 3 TEMA 1.cpp`, L78-100):**  
    Al poner `;` al final de la firma `void RegistrarInversor(...);`, la función termina inmediatamente como un prototipo, y todo el código siguiente queda suelto en el archivo:
    ```cpp
    // Líneas 78-86
    void RegistrarInversor (float arr[],int &tam, int capacidad); // ¡Punto y coma fatal!
    char continuar= 's';
     if tam < capacidad;{ // Código suelto a nivel global
      cout<<"[AVISO] El arreglo a alcanzado su capacidad maxima"
      {"capacidad<< "bloques" << endl;
      }
     return;
    }
    while (continuar =='s'||continuar=='s' && tam capacidad); // Sintaxis rota
    ```

### 2. Recorrido y Filtro (`ListarInversores`) (3% / 20%)
* ⚠️ **A mejorar (-17%):**
  - **Falta de tipo en parámetro y sentencias fuera de cuerpo (`COLMAN ARACELI PARCIAL 3 TEMA 1.cpp`, L102-117):**  
    Omitiste la palabra clave `float` en el parámetro `umbralAltaIrradiacion` y cerraste la llave en la línea 106, dejando el bucle `for` a la intemperie:
    ```cpp
    // Líneas 102-109
    void ListarInversores (const float arr[], int tam, umbralAltaIrradiacion);{ // ¡Falta float en el 3er parámetro!
     if (tam=0);
      cout <<"
 Aviso no hay irradiacion registrada"<< endl;;
    return;
    } // ¡Se cerró la función aquí!
    cout <<"
------Listado de inversores de los bloques---"<< endl;
      int contador Prime++; // Nombre de variable con espacio 'contador Prime'
    for (int =0;i< tam; i++); // Declaración del for rota: falta la variable 'int i = 0;'
    ```

### 3, 4 y 5. Búsqueda, Baja y Estadísticas (0% / 55%)
* ⚠️ **A mejorar (-55%):**
  - No desarrollaste `BuscarMedicion`, `DarDeBajaInversor` ni `CalcularEstadisticas`.

---

## 📊 2. Resumen de Calificación — Módulo 4: AoS y Ordenamiento (Tema 1)

| Bloque Evaluativo (75% C++) | Ponderación | Puntaje Obtenido | Observaciones Principales |
| :--- | :---: | :---: | :--- |
| **Bloque 1: Struct Primitivo AoS** | 10% | **4.0%** | Dejó el struct vacío en L11-13. Luego intentó declararlo en L91 como `struct ProductoTienda();` dejando los miembros como variables globales sueltas. |
| **Bloque 2: Inserción Posicional (*Right-Shift*)** | 20% | **4.0%** | Planteó la condición de shift decreciente, pero con coma y punto y coma mezclados en parámetros (`int &tam;int capacidad`), asignación con `==` y llamadas rotas (`arr[]`). |
| **Bloque 3: Modificación *in-place* (PK Inmutable)** | 15% | **3.0%** | Colocó `return false;` incondicional antes de modificar, usó variables no declaradas (`nuevoStock`) y sintaxis rota en cálculo derivado. |
| **Bloque 4: Burbuja Mejorada e Intercambio** | 30% | **1.0%** | No implementó `ordenarPorPrecioBaseBurbujaAsc`. Creó una función auxiliar con tipos inexistentes (`Producto`). |
| **SUBTOTAL LABORATORIO C++** | **75%** | **12.0 / 75 pts** | **Rendimiento técnico del 16.0% en C++.** |
| **Instancia Escrita Individual (Papel A4)** | 25% | **25.0% (25 / 25)** | **Sobresaliente:** Traza manual paso a paso de Selección Directa en papel A4 resuelta a la perfección. |
| **TOTAL MÓDULO 4** | **100%** | **37.0% (Nota UCSE: 2)** | **No Aprobado (rango 0 - 39%).** |

---

## 🔍 Desglose Técnico por Criterio — Módulo 4

### Bloque 1: Struct `ProductoTienda` (4.0% / 10%)
* ⚠️ **A mejorar (-6%):**
  - **Estructura vacía y declaración como función (`COLMAN ARACELI TEMA 1- PARCIAL 4.cpp`, L11-13 y L91-98):**  
    En la cabecera dejaste el struct vacío (`struct ProductoTienda {};`), lo que rompe la inicialización de `catalogo[]` en `main()`. Más abajo escribiste `struct ProductoTienda();` con paréntesis, dejando los campos como variables globales sueltas:
    ```cpp
    // Líneas 91-98
    struct ProductoTienda(); // ¡Sintaxis errónea con paréntesis!
     int codigo;
     int stock;
     char categoria;
     double precioBase;
     double valorUnitario;
     double valorStock;
    ```

### Bloque 2: Inserción Posicional (`insertarProducto`) (4.0% / 20%)
* ⚠️ **A mejorar (-16%):**
  - **Sintaxis de parámetros y asignación con comparación (`COLMAN ARACELI TEMA 1- PARCIAL 4.cpp`, L100-114):**  
    Pusiste `;` en la lista de parámetros en vez de `,`, pasaste `arr[]` a la búsqueda sin índice, y usaste `==` en vez de `=` para desplazar:
    ```cpp
    // Líneas 100-114
    bool insertarProducto (ProductoTienda arr[], int &tam;int capacidad, int pos, const ProductoTienda &nuevo){ // ¡Punto y coma en parámetros!
        if (tam >= capacidad); // Punto y coma tras if
         return false;
        if (pos < 0 || pos > tam);
        return false;
        if (buscarPorCodigo(arr[],tam,codigoBuscado)!=-1); // 'arr[]' es sintaxis inválida y 'codigoBuscado' no existe aquí
        return false;
        for (int i=tam;i>pos;i--);{
          arr[i]==arr[i-1]; // ¡Doble igual '==' compara, no asigna! Debe ser arr[i] = arr[i-1];
        }
        arr[pos]=nuevo;
        tam++;
        return true;
    }
    ```

### Bloque 3: Modificación in-place (`modificarProducto`) (3.0% / 15%)
* ⚠️ **A mejorar (-12%):**
  - **Retorno prematuro y variables no declaradas (`COLMAN ARACELI TEMA 1- PARCIAL 4.cpp`, L116-128):**  
    Colocaste `return false;` incondicional en la línea 120, por lo que las asignaciones nunca se ejecutan. Además, inventaste identificadores (`nuevoStock`, `nuevoPrecio`) en vez de leer del objeto `actualizado`:
    ```cpp
    // Líneas 116-128
    bool modificarProducto (ProductoTienda arr[], int tam,const ProductoTienda &actualizado);{
     int pos= buscarPorCodigo(arr[],tam,codigoBuscado);{
     if (pos==-1);
    }
     return false; // ¡Retorna siempre false! Todo lo que sigue es código inalcanzable
     arr[pos].stock = nuevoStock; // Error: debe ser actualizado.stock
     arr[pos].categoria = nuevaCategoria;
     // ...
     calcular Derivadas (arr[pos]); // Error de sintaxis: 'calcular Derivadas' con espacio
    ```

---

## 💡 Recomendaciones de Mejora

1. **Estructura correcta de una función en C++:**  
   Una función NUNCA debe llevar punto y coma al final de su cabecera, y todo su código debe ir entre llaves:
   ```cpp
   tipoRetorno nombreFuncion(parametros) {
       // Todo el código va acá adentro
       return valor;
   }
   ```
2. **Declaración correcta de un `struct`:**  
   El struct se define una sola vez al principio del archivo y sus miembros van entre llaves seguidos de `;`:
   ```cpp
   struct ProductoTienda {
       int codigo;
       int stock;
       char categoria;
       double precioBase;
       double valorUnitario;
       double valorStock;
   }; // Punto y coma obligatorio al final
   ```
3. **No uses `==` cuando quieras asignar un valor:**  
   Para guardar un dato o desplazar una posición usa `=`, reservando `==` únicamente para condiciones en `if` o `while`.

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
