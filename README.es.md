# Juego de Tres en Línea en C++

## Descripción General

Esta es una implementación completa del clásico juego Tres en Línea en C++. El juego cuenta con un oponente de IA imbatible que utiliza el **algoritmo Minimax** para hacer movimientos óptimos. Los jugadores pueden elegir entre una **interfaz de consola** o una **interfaz gráfica** para jugar.

## Características

### Características Compartidas (Ambas Versiones)
- **IA Imbatible**: Utiliza algoritmo minimax con optimización basada en profundidad
- **Validación de Entrada**: Manejo robusto de errores para movimientos inválidos
- **Gestión del Estado del Juego**: Registra victorias, derrotas y empates
- **Toma de Decisiones Inteligente**: La IA juega de forma óptima

### Versión de Consola
- **Interfaz de Texto Interactiva**: Juego amigable basado en menú
- **Visualización Clara del Tablero**: Representación ASCII del tablero del juego
- **Entrada por Teclado**: Escribe números 1-9 para colocar tus marcas

### Versión Gráfica (¡NUEVA!)
- **Interfaz Gráfica Moderna**: Construida con SFML (Simple and Fast Multimedia Library)
- **Interacción con Ratón**: Haz clic directamente en las celdas del tablero
- **Marcas Visuales**: Marcas X (Rojo) y O (Azul) codificadas por color
- **Renderizado en Tiempo Real**: Gráficos suaves a 60 FPS
- **Reinicio Instantáneo**: Presiona ESPACIO para jugar nuevamente
- **Mensajes de Estado**: Retroalimentación clara en pantalla

## Estructura del Proyecto

```
prueba-de-programación/
├── Archivos de Lógica del Juego
├── main.cpp                 # Punto de entrada de la versión de consola
├── main-gui.cpp             # Punto de entrada de la versión GUI
├── TicTacToe.h              # Declaración de clase de lógica del juego
├── TicTacToe.cpp            # Implementación de lógica del juego
├── GUI.h                    # Declaración de interfaz gráfica
├── GUI.cpp                  # Implementación de interfaz gráfica
├── CMakeLists.txt           # Configuración de compilación
├── Makefile                 # Compilación make tradicional
├── README.md                # Este archivo
├── GUI_BUILD_GUIDE.md       # Instrucciones de configuración de SFML
├── COMPILATION_GUIDE.md     # Guía de compilación para Windows
├── ALGORITHM_DOCUMENTATION.md  # Detalles del algoritmo Minimax
└── PROJECT_SUMMARY.md       # Descripción general del proyecto
```

## Descripción de Archivos

### Núcleo del Juego (Compartido por Ambas Versiones)

**TicTacToe.h**
- Archivo de encabezado con declaración de clase de lógica del juego
- Define la interfaz de la clase `TicTacToe`
- Documenta todos los métodos y funciones públicas

**TicTacToe.cpp**
- Implementación de la clase `TicTacToe`
- Contiene el algoritmo minimax para la IA
- Implementa gestión de tablero y evaluación del estado del juego

### Versión de Consola

**main.cpp**
- Punto de entrada para aplicación de consola
- Contiene bucle de juego e interfaz de usuario basada en texto
- Maneja entrada de teclado y navegación de menú
- Muestra tablero del juego usando caracteres ASCII

### Versión Gráfica (¡NUEVA!)

**main-gui.cpp**
- Punto de entrada para aplicación GUI
- Inicializa el juego y lo pasa al renderizador GUI

**GUI.h**
- Archivo de encabezado para clase de interfaz gráfica
- Define clase `TicTacToeGUI` usando librería SFML
- Documenta todos los métodos de renderizado y manejo de entrada

**GUI.cpp**
- Implementación de interfaz gráfica
- Maneja renderizado SFML, gestión de ventanas y eventos
- Dibuja tablero del juego, marcas e información de estado
- Procesa clics del ratón e entrada de teclado

### Compilación y Configuración

**CMakeLists.txt**
- Configuración de compilación para compilación multiplataforma
- Soporta estándar C++11
- Detecta automáticamente y vincula SFML si está disponible
- Construye tanto versión de consola como GUI

**Makefile**
- Script de compilación make Unix tradicional
- Alternativa a CMake para compilación simple

### Documentación

**README.md** (este archivo)
- Descripción general completa del proyecto y guía de uso

**GUI_BUILD_GUIDE.md** (¡NUEVO!)
- Instrucciones para instalar SFML
- Procedimientos de compilación específicos de plataforma
- Guía de solución de problemas

**COMPILATION_GUIDE.md**
- Instrucciones detalladas de compilación para Windows
- Múltiples métodos de compilación

**ALGORITHM_DOCUMENTATION.md**
- Explicación técnica del algoritmo minimax
- Antecedentes de teoría de juegos
- Análisis de rendimiento

**PROJECT_SUMMARY.md**
- Estadísticas y aspectos destacados del proyecto
- Matriz de características y comparaciones

## Compilación

### Inicio Rápido (Versión de Consola)

**Windows (Símbolo del Sistema)**
```cmd
cd C:\Users\Jorge\Documents\GitHub\prueba-de-programación
g++ -std=c++11 -o TicTacToe main.cpp TicTacToe.cpp
TicTacToe.exe
```

**Linux/macOS (Terminal)**
```bash
cd ~/path/to/prueba-de-programación
g++ -std=c++11 -o TicTacToe main.cpp TicTacToe.cpp
./TicTacToe
```

### Compilar Ambas Versiones con CMake

#### Requisitos Previos
- **Compilador C++**: g++, MSVC, o Clang (C++11 o posterior)
- **CMake**: Versión 3.10 o superior
- **SFML** (opcional, para GUI): Ver GUI_BUILD_GUIDE.md para instalación

#### Pasos de Compilación

```bash
# Navegar al proyecto
cd prueba-de-programación

# Crear directorio de compilación
mkdir build
cd build

# Generar archivos de compilación
cmake ..

# Compilar
cmake --build .

# Resultado: Ejecutables TicTacToe y TicTacToe-GUI
```

#### Solo Versión de Consola

```bash
cd build
./bin/TicTacToe          # Linux/macOS
bin\TicTacToe.exe        # Windows
```

#### Versión Gráfica

Para la versión GUI, primero **instala SFML** (ver GUI_BUILD_GUIDE.md), luego:

```bash
cd build
./bin/TicTacToe-GUI      # Linux/macOS
bin\TicTacToe-GUI.exe    # Windows
```

### Compilación Manual con g++

```bash
cd prueba-de-programación
g++ -std=c++11 -o TicTacToe main.cpp TicTacToe.cpp
./TicTacToe
```

#### Usando Visual Studio (Windows)

```bash
# En el directorio del proyecto
mkdir build
cd build
cmake ..

# Esto genera archivos de proyecto de Visual Studio
# Abre el archivo .sln generado en Visual Studio y compila
```

## Cómo Jugar

### Reglas del Juego

1. **Jugadores**: Juegas como 'X' y la IA juega como 'O'
2. **Tablero**: El tablero del juego consta de una cuadrícula 3x3 con posiciones numeradas 1-9:
   ```
   1 | 2 | 3
   ---------
   4 | 5 | 6
   ---------
   7 | 8 | 9
   ```

3. **Objetivo**: Ser el primero en obtener tres de tus marcas en fila (horizontal, vertical o diagonal)
4. **Jugabilidad**: 
   - Ingresa un número (1-9) para colocar tu marca en esa posición
   - Luego la IA hará su movimiento
   - El juego continúa hasta que haya un ganador o el tablero esté lleno (empate)

### Consejos de Estrategia

- El centro (posición 5) es a menudo una posición estratégica de inicio
- Las esquinas son valiosas para bloquear victorias diagonales
- La IA juega de forma óptima, así que el empate es lo mejor que puedes lograr

## Explicación del Algoritmo

### Algoritmo Minimax

La IA utiliza el **algoritmo Minimax**, un algoritmo de toma de decisiones que:

1. **Explora recursivamente** todos los posibles estados futuros del juego
2. **Evalúa estados terminales**: Asigna +10 para victoria de IA, -10 para victoria del humano, 0 para empate
3. **Maximiza** cuando es el turno de la IA (eligiendo la puntuación más alta)
4. **Minimiza** cuando es el turno del humano (eligiendo la puntuación más baja desde la perspectiva de la IA)
5. **Selecciona** el movimiento que conduce al mejor resultado

**Optimización Basada en Profundidad**: El algoritmo prefiere victorias más rápidas y retrasa pérdidas ajustando puntuaciones según la profundidad de recursión.

### Complejidad de Tiempo

- **Caso peor**: O(9!) - explora todos los posibles estados del juego
- **Caso promedio**: Mucho más rápido debido a terminación temprana del juego y poda

## Documentación del Código

El código completo incluye:
- **Comentarios estilo Doxygen** para documentación completa
- **Documentación de funciones** con descripciones de parámetros y valores de retorno
- **Documentación de clases** explicando propósito y diseño
- **Explicación de algoritmos** dentro del código

## Sesión de Juego de Ejemplo

```
═══════════════════════════════════════════
   JUEGO TRES EN LÍNEA EN C++
═══════════════════════════════════════════

╔════════════════════════════════╗
║     MENÚ PRINCIPAL             ║
╚════════════════════════════════╝

1. Jugar Nuevo Juego
2. Instrucciones
3. Salir

Selecciona una opción (1-3): 1

╔════════════════════════════════╗
║   ¡Bienvenido a TRES EN LÍNEA! ║
║   Eres X, la IA es O           ║
╚════════════════════════════════╝

     |     |     
  1  |  2  |  3  
-----------+-----------+-----------
  4  |  5  |  6  
-----------+-----------+-----------
  7  |  8  |  9  
     |     |     

Ingresa tu movimiento (1-9): 5

     |     |     
  1  |  2  |  3  
-----------+-----------+-----------
  4  |  X  |  6  
-----------+-----------+-----------
  7  |  8  |  9  
     |     |     

La IA está pensando...

     |     |     
  1  |  O  |  3  
-----------+-----------+-----------
  4  |  X  |  6  
-----------+-----------+-----------
  7  |  8  |  9  
     |     |     

... (el juego continúa)
```

## Posibles Mejoras

- Agregar niveles de dificultad (Fácil, Medio, Difícil)
- Implementar poda alfa-beta para computación más rápida
- Agregar interfaz gráfica con tablero gráfico
- Soportar modo multijugador (sin IA)
- Agregar estadísticas de juego y seguimiento de puntuación
- Implementar libro de aperturas para movimientos de IA más rápidos
- Agregar funcionalidad deshacer/rehacer

## Requisitos del Sistema

- **SO**: Windows, macOS, Linux
- **Estándar C++**: C++11 o superior
- **Memoria**: Mínima (menos de 1 MB)
- **CPU**: Cualquier procesador moderno

## Licencia

Este proyecto se proporciona tal cual para propósitos educativos y recreativos.

## Autor

Jorge

## Versión

1.0 - Lanzamiento inicial

## Soporte y Solución de Problemas

### P: La IA parece lenta en el primer movimiento
R: La computación del primer movimiento explora muchas posibilidades. Esto es normal y la IA se decide por el centro como óptimo.

### P: El programa no se compila
R: Asegúrate de tener:
- Un compilador compatible con C++11
- CMake instalado (si usas CMake)
- Los tres archivos de origen (main.cpp, TicTacToe.h, TicTacToe.cpp) en el mismo directorio

### P: ¿Puedo vencer a la IA?
R: La IA es imbatible cuando va primero y solo debería ser empateable cuando tú vas primero y juegas óptimamente.

---

**¡Disfruta el juego!**
