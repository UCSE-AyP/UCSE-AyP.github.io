# 📋 Rúbrica de Evaluación — 3er Examen Recuperatorio (Módulo 3: Arreglos en C++)

- **Cátedra:** Algoritmos y Programación (UCSE)
- **Evaluación:** Recuperatorio del 3er Examen Parcial — Ciclo Lectivo 2026 (`12/11/2026`)
- **Temas Evaluados:**
  - **Tema 1:** *Parque Solar Cauchari (Jujuy)* — Energía diaria por inversor (`kWh`, rango `[15.0, 250.0]`, Alta Irradiación `> 140.0`, Máximo)
  - **Tema 2:** *Parque Eólico Rawson (Chubut)* — Potencia media diaria por aerogenerador (`kW`, rango `[50.0, 600.0]`, Rendimiento Óptimo `> 350.0`, Mínimo)
- **Modalidad (Alcance Unificado / Integral):** 100% Código C++ sobre Plantilla Base Modular (`main()`, `switch` de 5 opciones y `MostrarMenu` provistos; **5 funciones algorítmicas puras** desarrolladas por el estudiante; sin Prueba de Escritorio, sin `Modificar*`, sin vectores paralelos, sin ordenamiento ni `struct`).

---

## Matriz de Calificación (100% Código Funcional y Modular)

| Bloque Evaluativo | Peso | Logrado (100% del bloque) | Parcial (50% del bloque) | Insuficiente (0% del bloque) |
| :--- | :---: | :--- | :--- | :--- |
| **1. Carga Controlada y Validación de Límites (`Registrar*`)** | **25%** | Verifica `tam < CAPACIDAD` (`15`) antes de insertar evitando desbordamiento. Valida mediante `while` el rango físico (`[15.0, 250.0]` o `[50.0, 600.0]`), almacena en `arr[tam]` e incrementa `tam` por referencia (`int &tam`). | Valida el rango con `while`, pero permite exceder `CAPACIDAD = 15`, o valida con `if` simple aceptando valores inválidos tras un rechazo, u olvida modificar `tam` por referencia. | No valida el rango numérico, provoca desbordamiento fuera de rango o no actualiza `tam`. |
| **2. Recorrido y Filtro Estricto por Umbral (`Listar*`)** | **20%** | Recibe `const float arr[]` y `tam` por valor. Protege `tam == 0`. Marca estrictamente `> 140.0` (Tema 1) o `> 350.0` (Tema 2) sin incluir el límite exacto (`>=`) e informa el conteo total. | Recorre el arreglo y lista elementos, pero incluye el borde (`>=` en lugar de `>`), omite el contador de umbral o falla al proteger `tam == 0`. | Bucle que excede `tam` leyendo basura (`CAPACIDAD` completo) o rompe la ejecución en arreglo vacío. |
| **3. Búsqueda Secuencial (`Buscar*`)** | **15%** | Recibe `const float arr[]`, realiza recorrido lineal con salida temprana y retorna el índice `[0 .. tam-1]` de la primera ocurrencia exacta o `-1` si no existe. | Retorna `bool` en lugar de `int`, o recorre innecesariamente todo el arreglo sin salida temprana devolviendo una ocurrencia posterior. | Búsqueda que corta en la primera iteración (`else return -1` dentro del `for`), o no retorna `-1` cuando no existe. |
| **4. Eliminación Física Shift-Left (`DarDeBaja*`)** | **25%** | Recibe `float arr[], int &tam`, protege `tam == 0`, reutiliza `Buscar*` para validar existencia (`pos != -1`), desplaza exactamente `for (int i = pos; i < tam - 1; i++) arr[i] = arr[i + 1];` y decrementa `tam--`, liberando el cupo. | Desplaza elementos, pero duplica la búsqueda manualmente sin reutilizar `Buscar*`, o se excede hasta `i < tam` leyendo `arr[tam]` fuera del arreglo activo, u olvida decrementar `tam--`. | Elimina colocando `0` o `-1` (borrado lógico inválido), invierte el sentido del desplazamiento (*Shift-Right* sobrescribiendo el arreglo) o corrompe `tam`. |
| **5. Estadísticas con Guarda (`CalcularEstadisticas`)** | **15%** | Recibe `const float arr[]`, protege `tam == 0` sin dividir por cero, calcula el promedio (`float`) e informa el extremo correcto (Máximo o Mínimo) junto con su índice `[i]`. | Calcula el promedio, pero omite la posición del extremo (`posMax`/`posMin`), confunde el sentido del extremo o inicializa erróneamente en `0` en lugar de `arr[0]`. | División por cero con `tam == 0`, bucle que lee posiciones no activas o cálculo incorrecto de promedio/extremo. |

---

## Penalizaciones Directas (Sobre la Nota Final)

| Infracción Técnica | Penalización | Justificación Curricular |
| :--- | :---: | :--- |
| **Violación de `const` o paso por referencia** | **-10%** | Omitir `const` en funciones de solo lectura (`Listar*`, `Buscar*`, `CalcularEstadisticas`), o alterar los prototipos provistos en la plantilla. |
| **Variables globales mutables** | **-10%** | Declarar el arreglo principal o `tam` de forma global (solo se permiten constantes simbólicas `const` como `CAPACIDAD = 15` o límites). |
| **Uso de librerías o técnicas fuera de Módulo 3** | **-15%** | Emplear `std::vector`, algoritmos de ordenamiento (`sort`/Burbuja/Selección/Inserción), arreglos paralelos o `struct`. |
| **Error de compilación o entrega ajena al tema asignado** | **Nota: 0 (Desaprobado)** | El código no compila con un compilador estándar C++11/C++17, contiene errores de sintaxis fatales o implementa el dominio de un tema distinto al asignado. |

---

## Protocolo de Verificación Docente

1. **Verificación de casos de borde mínimos:** Ejecutar los 3 casos documentados en [SDD.md](SDD.md) (flujo normal + baja Shift-Left, bordes de rango y umbral estricto con `tam == 0`, y saturación a `CAPACIDAD = 15` con liberación vía Shift-Left).
2. **Umbral estricto:** Verificar que un valor exactamente igual al umbral (`140.00 kWh` en Tema 1 o `350.00 kW` en Tema 2) **no** reciba etiqueta ni incremente el contador.
3. **Recarga post-baja:** Comprobar que tras llenar 15 registros y dar de baja al menos 1 elemento mediante Shift-Left, el sistema acepta nuevamente un nuevo ingreso en `[14]`.
4. **Criterios de aprobación:** Nota mínima **60%** de puntaje neto una vez aplicadas eventuales penalizaciones directas.
