# 📋 4to Examen Parcial 2026 — Módulo 4: Arreglos de Estructuras (AoS)

**Universidad Católica de Santiago del Estero — Departamento Académico San Salvador**  
**Facultad de Ciencias de la Salud y Tecnologías de la Información**  
**Cátedra:** Algoritmos y Programación  
**Ciclo Lectivo:** 2026  

---

## 🏛️ Modalidad Bimodal Obligatoria

El presente examen evalúa competencias bimodales en C++17 (75% Laboratorio de Programación) e Instancia Escrita manuscrita (25% Lápiz y Papel sobre hoja A4):

### 1. Entorno Web Interactivo
- **`index.html`:** Portal institucional de acceso para alumnos.
- **`tema1.html`:** Enunciado interactivo — **Tema 1: Sistema Hospitalario de Pacientes (`Paciente`)**.
- **`tema2.html`:** Enunciado interactivo — **Tema 2: Sistema de Gestión Académica Universitaria (`Alumno`)**.
- **`admin.html`:** Panel docente centralizado con accesos a especificaciones y matrices.
- **`prueba_escritorio_imprimir.html`:** Hoja A4 lista para impresión con grillas de traza manuscrita.
- **`prueba_escritorio_resuelto.html`:** Solución paso a paso de las trazas de ordenamiento elemental (Tema 1: Selección Directa Ascendente; Tema 2: Inserción Directa Descendente).

---

### 2. Resoluciones de Referencia en C++
- **`resolucion-tema1.cpp`:** Implementación de referencia para Tema 1 (Pacientes: Búsqueda por id, Inserción con corrimiento, Modificación in-place, Baja física con compactación, Ordenamiento Burbuja Mejorada Ascendente por `valorBase`, Estadístico con guarda defensiva y capa `<iomanip>`).
- **`resolucion-tema2.cpp`:** Implementación de referencia para Tema 2 (Alumnos: Búsqueda por legajo, Inserción con corrimiento, Modificación in-place, Baja física con compactación, Ordenamiento Burbuja Mejorada Descendente por `promedio`, Estadístico con guarda defensiva y capa `<iomanip>`).

#### Compilación y Ejecución (Estándar C++17)
```bash
# Tema 1
g++ -std=c++17 -Wall -Wextra resolucion-tema1.cpp -o tema1.exe
./tema1.exe

# Tema 2
g++ -std=c++17 -Wall -Wextra resolucion-tema2.cpp -o tema2.exe
./tema2.exe
```

---

### 3. Documentación Pedagógica y de Diseño
- **`SDD.md` (Software Design Document):** Especificación formal de arquitectura, modelos de structs (100% tipos primitivos), contratos de precondición/postcondición y matrices de prueba.
- **`rubrica.md`:** Rúbrica analítica oficial de corrección para el equipo docente (ponderación 75% C++ / 25% Escrita).
- **`rubrica_estudiantes.md`:** Criterios de evaluación y escalas de acreditación en lenguaje transparente para estudiantes.
