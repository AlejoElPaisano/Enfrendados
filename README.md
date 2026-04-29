# ⚔️ Enfrentados (C++)

Juego de dados por turnos implementado en **C++**, con interfaz gráfica en consola usando arte ASCII, colores y animaciones. Dos jugadores se enfrentan apostando dados para igualar un número objetivo y llevarse la gloria.

---

## ⚙️ Características

- **Juego por Turnos:** Dos jugadores compiten en hasta 3 rondas.
- **Número Objetivo:** Cada turno se genera un número objetivo sumando dos dados de 12 caras. El jugador debe intentar igualarlo con sus dados disponibles.
- **Dinámica de Stock de Dados:**
  - ✅ Si se **iguala** el objetivo: el jugador suma `Objetivo × Dados Usados` puntos y transfiere los dados usados al oponente.
  - ❌ Si **no se iguala**: el jugador recibe un dado del stock del oponente.
- **Victoria Automática:** El jugador que se queda sin dados gana de forma inmediata con **10.000 puntos extra**.
- **Sistema de Estadísticas:** Guarda y muestra el **MVP** (mejor jugador histórico de la sesión).
- **Interfaz ASCII:** Menú navegable con flechas, arte ASCII propio, colores y pantallas animadas vía `rlutil`.
- **Sección de Créditos:** 3 páginas navegables con arte dedicado al equipo docente y desarrolladores.

---

## 🎮 Reglas del Juego

1. **Inicio:** Se ingresan los nombres de ambos jugadores (máximo 10 caracteres).
2. **Turno Inicial:** Se tira un dado de 6 caras para definir quién empieza primero.
3. **Rondas:** Se juegan hasta 3 rondas (o hasta que alguien quede sin dados).
4. **Desarrollo del Turno:**
   - Se genera el **Número Objetivo** (suma de 2 dados de 12 caras).
   - El jugador tira su stock de dados (inicialmente 6 dados de 6 caras).
   - El jugador elige qué dados sumar para intentar igualar el objetivo.
   - El resultado puede ser exitoso o fallido (ver Características).
5. **Fin de Partida:**
   - Un jugador queda sin dados → gana automáticamente con bonus de 10.000 pts.
   - Se completan las 3 rondas → gana quien tenga más puntos.
   - Si hay empate → se muestra pantalla especial de empate.
6. **Estadísticas:** Al finalizar, si el puntaje supera el récord de la sesión, se actualiza el MVP.

---

## 🛠️ Tecnologías Utilizadas

- **C++:** Lenguaje principal.
- **`rlutil.h`:** Librería de consola para colores, posicionamiento de cursor y manejo de teclas.
- **`cstdlib` / `ctime`:** Para la generación de números aleatorios con `srand(time(NULL))`.
- **IDE:** Code::Blocks (`.cbp`)

---

## 📂 Estructura del Proyecto

| Archivo | Descripción |
|---|---|
| `main.cpp` | Punto de entrada. Inicializa la semilla aleatoria y lanza el menú principal. |
| `Salas.cpp / Salas.h` | Control de las "salas" del juego: menú principal, flujo de partida, créditos y selección de opciones. |
| `FuncionesMatematicas.cpp / .h` | Lógica de dados: tiradas aleatorias, selección y suma de dados, validación de entradas, función `Clamp`. |
| `FuncionesGraficas.cpp / .h` | Todo el arte ASCII: dados, márgenes, pantallas de juego, resumen de jugada, trofeos, MVP, créditos y más. |
| `rlutil.h` | Librería externa para manejo de consola (colores, cursor, teclas). |

---

## 🚀 Cómo Compilar y Ejecutar

Necesitás un compilador de C++ (g++ o MinGW) y tener `rlutil.h` en el mismo directorio.

### Con g++:
```bash
g++ main.cpp Salas.cpp FuncionesMatematicas.cpp FuncionesGraficas.cpp -o Enfrentados
./Enfrentados
```

### Con Code::Blocks:
Abrí el archivo `Enfrentados.cbp` y presioná **Build & Run** (`F9`).

> ⚠️ Se recomienda ejecutar en una consola de **64 columnas × 40 filas** para que el arte ASCII se vea correctamente.

---

## 👨‍💻 Desarrollado por

**Alejo Martinez** — Tecnicatura Universitaria en Programación | UTN  
[![GitHub](https://img.shields.io/badge/GitHub-AlejoElPaisano-181717?style=flat&logo=github)](https://github.com/AlejoElPaisano)
