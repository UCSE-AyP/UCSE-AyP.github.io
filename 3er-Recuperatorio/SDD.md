# 📐 Especificación Dirigida por Especificaciones (SDD) — 3er Examen Recuperatorio (Módulo 3: Arreglos en C++)

- **Cátedra:** Algoritmos y Programación (Ingeniería en Informática — UCSE)
- **Evaluación:** Recuperatorio del 3er Examen Parcial — Módulo 3 (Arreglos Unidimensionales y Operaciones Fundamentales)
- **Ciclo Lectivo:** 2026 (`12/11/2026`)
- **Eje Temático:** *Monitoreo de Energías Renovables y Generación Eléctrica en Argentina*
- **Alcance de Temas:** **2 Temas únicamente** (Tema 1: *Parque Solar Cauchari* y Tema 2: *Parque Eólico Rawson*). *No se genera Tema 3 por definición de cátedra.*
- **Modalidad (Recorte Integral Sin Solapamientos):** **100% En Línea — Código Base Modular Provisto (`main()`, `switch` de 5 opciones y `MostrarMenu` pre-implementados + 5 funciones algorítmicas puras a desarrollar por el estudiante)**, sin modificación in-place (evaluada en Módulo 4), sin vectores paralelos, sin ordenamiento (`sort`), sin estructuras (`struct`) ni prueba de escritorio manual.
- **Trazabilidad Curricular:** Clases 28 y 29 (*Declaración, recorrido, validación de capacidad `tam`/`CAPACIDAD`, carga controlada, filtrado por umbral, búsqueda secuencial y eliminación física mediante compactación Shift-Left con `const` y paso por referencia*).

---

## 1. Matriz de Paridad Temática y Simetría Cognitiva

Ambos temas evalúan exactamente las mismas 5 competencias técnicas y ponderaciones sobre **arreglos unidimensionales reales (`float`)** con capacidad fija compartida (`CAPACIDAD = 15`), diferenciándose únicamente en el contexto energético, las unidades físicas, los umbrales numéricos y el sentido del extremo estadístico (Máximo vs. Mínimo):

| Atributo Estructural | Tema 1: Parque Solar Cauchari (Jujuy) | Tema 2: Parque Eólico Rawson (Chubut) |
| :--- | :--- | :--- |
| **Entidad Monitoreada** | Inversores fotovoltaicos | Aerogeneradores eólicos |
| **Tipo de Arreglo** | `float mediciones[CAPACIDAD]` | `float potencias[CAPACIDAD]` |
| **Capacidad Máxima** | `const int CAPACIDAD = 15;` | `const int CAPACIDAD = 15;` |
| **Variable Física y Unidad** | Energía diaria generada (`kWh`) | Potencia media diaria (`kW`) |
| **Rango de Validación** | `[15.0, 250.0]` kWh (`while`) | `[50.0, 600.0]` kW (`while`) |
| **Umbral de Filtrado** | **Alta Irradiación:** `> 140.0` kWh (estricto) | **Rendimiento Óptimo:** `> 350.0` kW (estricto) |
| **Búsqueda Secuencial (Opc. 3)** | Primera ocurrencia exacta (`int`, `-1` si no existe) | Primera ocurrencia exacta (`int`, `-1` si no existe) |
| **Eliminación Física (Opc. 4)** | Busca medición reutilizando `BuscarMedicion` y compacta **Shift-Left** (`tam--`) | Busca potencia reutilizando `BuscarPotencia` y compacta **Shift-Left** (`tam--`) |
| **Estadísticas (Opc. 5)** | Promedio general + **Generación MÁXIMA** y posición `[i]` | Promedio general + **Potencia MÍNIMA** y posición `[i]` |
| **Ponderación (Rúbrica)** | `25%` Carga/Validación · `20%` Listado/Umbral · `15%` Búsqueda · `25%` Baja Shift-Left · `15%` Estadísticas | `25%` Carga/Validación · `20%` Listado/Umbral · `15%` Búsqueda · `25%` Baja Shift-Left · `15%` Estadísticas |

---

## 2. Contratos Modulares y Reglas de Memoria (Obligatorios)

Se exige programación modular estricta, **prohibición total de variables globales mutables** y respeto riguroso por el calificador `const` y el paso por valor o referencia según el efecto colateral de cada función:

### 2.1. Prototipos Exactos — Tema 1 (`resolucion-tema1.cpp`)

```cpp
const int CAPACIDAD = 15;

void MostrarMenu(int &opc); // Pre-implementado en la plantilla
void RegistrarInversor(float arr[], int &tam, int capacidad);
void ListarInversores(const float arr[], int tam, float umbralAltaIrradiacion);
int  BuscarMedicion(const float arr[], int tam, float valorBuscado);
void DarDeBajaInversor(float arr[], int &tam);
void CalcularEstadisticas(const float arr[], int tam);
```

### 2.2. Prototipos Exactos — Tema 2 (`resolucion-tema2.cpp`)

```cpp
const int CAPACIDAD = 15;

void MostrarMenu(int &opc); // Pre-implementado en la plantilla
void RegistrarAerogenerador(float arr[], int &tam, int capacidad);
void ListarAerogeneradores(const float arr[], int tam, float umbralOptimo);
int  BuscarPotencia(const float arr[], int tam, float valorBuscado);
void DarDeBajaAerogenerador(float arr[], int &tam);
void CalcularEstadisticas(const float arr[], int tam);
```

### 2.3. Invariantes de Seguridad y Memoria

1. **Invariante de tamaño lógico:** `0 <= tam <= CAPACIDAD` en todo instante de la ejecución.
2. **Solo lectura (`const float arr[]`):** `Listar*`, `Buscar*` y `CalcularEstadisticas` deben recibir el arreglo como `const float arr[]` y `tam` por valor.
3. **Mutación estructural (`float arr[]`, `int &tam`):** `Registrar*` y `DarDeBaja*` reciben `tam` por referencia porque incrementan o decrementan la cantidad lógica de elementos activos.
4. **Reutilización modular y compactación Shift-Left:**
   - `DarDeBaja*` invoca obligatoriamente a `Buscar*` para localizar la primera ocurrencia (`pos != -1`).
   - La eliminación realiza desplazamiento hacia la izquierda desde `pos` hasta `tam - 2`:
     ```cpp
     for (int i = pos; i < tam - 1; i++) {
         arr[i] = arr[i + 1];
     }
     tam--;
     ```
5. **Protección de arreglo vacío y lleno:**
   - Si `tam >= CAPACIDAD`, `Registrar*` informa capacidad máxima alcanzada y retorna sin escribir fuera de rango.
   - Si `tam == 0`, las opciones `2`, `3` (validada en `main()`), `4` y `5` informan ausencia de datos sin dividir por cero ni acceder a `arr[0]`.
6. **Formato decimal en salida estándar:** `cout << fixed << setprecision(2);` provisto en `main()`.

---

## 3. Contrato de Interfaz HTML (`index.html`, `tema1.html`, `tema2.html`)

- **Estilo Base Institucional UCSE (alineado a `4to-Recuperatorio`):** Paleta institucional UCSE clara (`#1f3763`, `#2a5298`, `#ffd800`, `#00bfff`, `#c90063` sobre `#f8fafc`/`#ffffff`), Font Awesome 6.4.0, Google Fonts `Fira Code` y terminales/bloques de código oscuros (`#0f172a`).
- **`index.html`:** Encabezado institucional UCSE, tarjeta `.welcome-card` con reglas y grilla `.grid-temas` de **2 columnas** enlazando únicamente a `tema1.html` y `tema2.html`.
- **`tema1.html` y `tema2.html`:**
  - Enlaces de navegación sticky, `.requirements-alert`, `.mission-list` con **5 tarjetas** (`25%`, `20%`, `15%`, `25%`, `15%`), pestañas accesibles de **3 casos de prueba** y bloque `codigo_base_tema*.cpp` con `main()`, `switch` de 5 opciones y `MostrarMenu` pre-implementados.

---

## 4. Casos de Prueba Formales Verificados (3 por Tema)

> Todos los valores reales utilizados terminan en `.0` o `.5` (fracciones binarias exactas en IEEE-754 `float` de 32 bits) para garantizar comparaciones exactas `arr[i] == valorBuscado` sin error de redondeo.

### 4.1. Tema 1 — Parque Solar Cauchari (`kWh`, rango `[15.0, 250.0]`, Alta Irradiación `> 140.0`, Máximo)

#### Caso 1: Carga con rechazo de rango, listado inicial, baja Shift-Left y estadísticas
- **Objetivo:** Verificar carga normal (`4` registros, incluyendo rechazo `while` ante `10.0` previo a `150.5`), listado con marcado de Alta Irradiación, eliminación física Shift-Left del segundo elemento (`Opc 4`) y cálculo final de promedio y máximo (`Opc 5`).
- **Entrada (`stdin`):**
  ```text
  1 10.0 150.5
  1 185.5
  1 95.0
  1 210.5
  2
  4 185.5
  2
  5
  0
  ```
- **Estado del arreglo:**
  - Tras cargas (`tam = 4`): `[150.50, 185.50, 95.00, 210.50]` → Alta Irradiación: `3` (`150.50`, `185.50`, `210.50`).
  - Tras dar de baja `185.50` (`pos = 1`, Shift-Left, `tam = 3`): `[150.50, 95.00, 210.50]` → Alta Irradiación: `2` (`150.50`, `210.50`).
- **Salida esperada (`stdout`):**
  - Carga 1: `Valor fuera de rango. Ingrese entre 15.0 y 250.0 kWh:` → `Registro agregado en la posicion [0]. Total activos: 1/15`
  - Listado 1: `Inversores con Alta Irradiacion (> 140.00 kWh): 3`
  - Baja (`Opc 4`): `Inversor eliminado (compactacion Shift-Left). Total activos: 3/15`
  - Listado 2: `[0] -> 150.50 kWh [ALTA IRRADIACION]`, `[1] -> 95.00 kWh`, `[2] -> 210.50 kWh [ALTA IRRADIACION]` → `Inversores con Alta Irradiacion (> 140.00 kWh): 2`
  - Estadísticas (`456.00 / 3`):
    - `Energia promedio generada: 152.00 kWh`
    - `Generacion maxima: 210.50 kWh (Inversor en posicion [2])`

#### Caso 2: Validación de bordes, umbral estricto (`140.0`), arreglo vacío y búsqueda fallida
- **Objetivo:** Comprobar protección cuando `tam == 0`, rechazo fuera de `[15.0, 250.0]`, aceptación exacta de `15.0` y `250.0`, verificación de que `140.0` **no** cuenta como Alta Irradiación (`>` estricto), búsqueda inexistente (`-1`) y actualización del máximo tras baja (`Opc 4`).
- **Entrada (`stdin`):**
  ```text
  2
  5
  1 14.5 250.5 15.0
  1 140.0
  1 250.0
  3 999.0
  3 140.0
  2
  4 250.0
  5
  0
  ```
- **Salida esperada (`stdout`):**
  - Arreglo vacío: `No hay inversores registrados en el sistema.` y `No hay registros para calcular estadisticas.`
  - Búsquedas: `Medicion no encontrada en el arreglo.` / `Medicion encontrada en la posicion [1].`
  - Listado: `Inversores con Alta Irradiacion (> 140.00 kWh): 1` (`140.00` sin etiqueta).
  - Baja `250.0`: `Inversor eliminado (compactacion Shift-Left). Total activos: 2/15`
  - Estadísticas (`155.00 / 2`):
    - `Energia promedio generada: 77.50 kWh`
    - `Generacion maxima: 140.00 kWh (Inversor en posicion [1])`

#### Caso 3: Saturación máxima (`CAPACIDAD = 15`), bloqueo de overflow y liberación de cupo con Shift-Left
- **Entrada (`stdin`):**
  ```text
  1 50.0  1 80.5  1 110.0  1 140.5  1 160.0
  1 175.5 1 190.0 1 200.5  1 215.0  1 225.5
  1 240.0 1 130.5 1 155.0  1 90.5   1 180.0
  1
  2
  5
  4 50.0
  1 250.0
  2
  5
  0
  ```
- **Salida esperada (`stdout`):**
  - Intento 16 (`tam == 15`): `Error: Capacidad maxima alcanzada (15 inversores). No se pueden cargar mas registros.`
  - Listado inicial (`tam = 15`): `Inversores con Alta Irradiacion (> 140.00 kWh): 10`
  - Estadísticas iniciales (`2343.50 / 15`):
    - `Energia promedio generada: 156.23 kWh`
    - `Generacion maxima: 240.00 kWh (Inversor en posicion [10])`
  - Baja `50.0` (`pos = 0`): `Inversor eliminado (compactacion Shift-Left). Total activos: 14/15`
  - Nueva carga `250.0`: `Registro agregado en la posicion [14]. Total activos: 15/15`
  - Listado final: `Inversores con Alta Irradiacion (> 140.00 kWh): 11`
  - Estadísticas finales (`2543.50 / 15`):
    - `Energia promedio generada: 169.57 kWh`
    - `Generacion maxima: 250.00 kWh (Inversor en posicion [14])`

---

### 4.2. Tema 2 — Parque Eólico Rawson (`kW`, rango `[50.0, 600.0]`, Rendimiento Óptimo `> 350.0`, Mínimo)

#### Caso 1: Carga con rechazo de rango, listado inicial, baja Shift-Left y estadísticas
- **Entrada (`stdin`):**
  ```text
  1 280.0
  1 650.0 390.5
  1 195.0
  1 510.5
  2
  4 280.0
  2
  5
  0
  ```
- **Estado del arreglo:**
  - Tras cargas (`tam = 4`, rechazando `650.0` previo a `390.5`): `[280.00, 390.50, 195.00, 510.50]` → Rendimiento Óptimo: `2`.
  - Tras dar de baja `280.00` (`pos = 0`, Shift-Left, `tam = 3`): `[390.50, 195.00, 510.50]` → Rendimiento Óptimo: `2`.
- **Salida esperada (`stdout`):**
  - Carga 2: `Valor fuera de rango. Ingrese entre 50.0 y 600.0 kW:` → `Registro agregado en la posicion [1]. Total activos: 2/15`
  - Listado 1: `Aerogeneradores en Rendimiento Optimo (> 350.00 kW): 2`
  - Baja (`Opc 4`): `Aerogenerador eliminado (compactacion Shift-Left). Total activos: 3/15`
  - Listado 2: `[0] -> 390.50 kW [RENDIMIENTO OPTIMO]`, `[1] -> 195.00 kW`, `[2] -> 510.50 kW [RENDIMIENTO OPTIMO]` → `Aerogeneradores en Rendimiento Optimo (> 350.00 kW): 2`
  - Estadísticas (`1096.00 / 3`):
    - `Potencia promedio generada: 365.33 kW`
    - `Potencia minima: 195.00 kW (Aerogenerador en posicion [1])`

#### Caso 2: Validación de bordes, umbral estricto (`350.0`), arreglo vacío y búsqueda fallida
- **Entrada (`stdin`):**
  ```text
  2
  5
  1 49.5 600.5 50.0
  1 350.0
  1 600.0
  3 120.0
  3 350.0
  2
  4 50.0
  5
  0
  ```
- **Salida esperada (`stdout`):**
  - Arreglo vacío: `No hay aerogeneradores registrados en el sistema.` y `No hay registros para calcular estadisticas.`
  - Búsquedas: `Potencia no encontrada en el arreglo.` / `Potencia encontrada en la posicion [1].`
  - Listado: `Aerogeneradores en Rendimiento Optimo (> 350.00 kW): 1` (`350.00` sin etiqueta).
  - Baja `50.0`: `[350.00, 600.00]` (`tam = 2`).
  - Estadísticas (`950.00 / 2`):
    - `Potencia promedio generada: 475.00 kW`
    - `Potencia minima: 350.00 kW (Aerogenerador en posicion [0])`

#### Caso 3: Saturación máxima (`CAPACIDAD = 15`), bloqueo de overflow y desplazamiento de nuevo mínimo
- **Entrada (`stdin`):**
  ```text
  1 100.0 1 200.5 1 300.0 1 350.5 1 400.0
  1 425.5 1 450.0 1 475.5 1 500.0 1 525.5
  1 550.0 1 250.5 1 380.0 1 150.5 1 410.0
  1
  2
  5
  4 100.0
  1 600.0
  2
  5
  0
  ```
- **Salida esperada (`stdout`):**
  - Intento 16 (`tam == 15`): `Error: Capacidad maxima alcanzada (15 aerogeneradores). No se pueden cargar mas registros.`
  - Listado inicial (`tam = 15`): `Aerogeneradores en Rendimiento Optimo (> 350.00 kW): 10`
  - Estadísticas iniciales (`5468.50 / 15`):
    - `Potencia promedio generada: 364.57 kW`
    - `Potencia minima: 100.00 kW (Aerogenerador en posicion [0])`
  - Baja `100.0` (`pos = 0`): `Aerogenerador eliminado (compactacion Shift-Left). Total activos: 14/15`
  - Nueva carga `600.0`: `Registro agregado en la posicion [14]. Total activos: 15/15`
  - Listado final: `Aerogeneradores en Rendimiento Optimo (> 350.00 kW): 11`
  - Estadísticas finales (`5968.50 / 15`):
    - `Potencia promedio generada: 397.90 kW`
    - `Potencia minima: 150.50 kW (Aerogenerador en posicion [12])`
