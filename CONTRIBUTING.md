# Contributing to Tic Tac Toe Game

¡Gracias por tu interés en contribuir! Las contribuciones son muy bienvenidas.

## Cómo Contribuir

### Reportar Bugs

Si encuentras un bug, por favor crea un **Issue** describiendo:
- Qué hiciste
- Qué pasó
- Qué esperabas que pasara
- Tu sistema operativo y versión de C++

### Sugerir Mejoras

¿Tienes una idea para mejorar el proyecto? Abre un **Issue** con la etiqueta `enhancement` explicando:
- La mejora propuesta
- Por qué sería útil
- Ejemplos de cómo funcionaría

### Crear un Pull Request

1. **Fork** el repositorio
2. **Crea una rama** para tu característica:
   ```bash
   git checkout -b feature/tu-caracteristica
   ```
3. **Realiza tus cambios** y escribe código limpio
4. **Prueba tu código**:
   ```bash
   g++ -std=c++11 -o TicTacToe main.cpp TicTacToe.cpp
   ./TicTacToe
   ```
5. **Haz commit** con mensajes claros:
   ```bash
   git commit -m "Add: descripción de lo que agregaste"
   git commit -m "Fix: descripción del bug que arreglaste"
   ```
6. **Push** a tu fork:
   ```bash
   git push origin feature/tu-caracteristica
   ```
7. **Abre un Pull Request** describiendo qué cambios hiciste

## Guías de Estilo

### Código C++
- Usa **camelCase** para variables y funciones: `getWinner()`
- Usa **PascalCase** para clases: `TicTacToe`
- Comenta el código complejo
- Mantén líneas menores a 80 caracteres
- Usa espacios (2 o 4) para indentación, NO tabs

### Commits
- Mensajes en inglés
- Primera línea: máximo 50 caracteres
- Si es necesario, agrega descripción después de una línea en blanco
- Ejemplos:
  - `Add minimax optimization for AI`
  - `Fix: incorrect winner detection on diagonal`
  - `Refactor: simplify board evaluation logic`

### Documentación
- Comenta funciones públicas con Doxygen
- Mantén README.md actualizado
- Documenta cambios importantes en ALGORITHM_DOCUMENTATION.md

## Áreas de Contribución

### Fácil (para principiantes)
- Mejorar documentación
- Agregar comentarios al código
- Corregir typos
- Mejorar mensajes de error

### Intermedia
- Agregar validación de entrada mejorada
- Optimizar algoritmo minimax
- Agregar más comentarios sobre la IA
- Mejorar interfaz de usuario

### Avanzada
- Implementar dificultades (Easy, Medium, Hard)
- Alpha-beta pruning
- Interfaz gráfica mejorada
- Tests unitarios

## Proceso de Review

1. Un mantenedor revisará tu PR
2. Podría haber solicitudes de cambios
3. Una vez aprobado, se hará merge
4. ¡Tu contribución estará en el proyecto!

## Código de Conducta

- Sé respetuoso con otros contribuidores
- No hagas spam
- Enfócate en el contenido, no en las personas
- Ayuda a otros a aprender

## Preguntas o Dudas

Si tienes preguntas, abre un **Discussion** o una **Issue** con la etiqueta `question`.

---

¡Gracias por contribuir! 🎉
