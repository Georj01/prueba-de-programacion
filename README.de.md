# Tic Tac Toe-Spiel in C++

## Überblick

Dies ist eine vollständige Implementierung des klassischen Tic Tac Toe-Spiels (Drei in einer Reihe) in C++. Das Spiel verfügt über einen unbesiegbaren KI-Gegner, der den **Minimax-Algorithmus** verwendet, um optimale Züge zu machen. Spieler können zwischen einer **Konsolenschnittstelle** oder einer **grafischen Schnittstelle** zum Spielen wählen.

## Merkmale

### Gemeinsame Merkmale (Beide Versionen)
- **Unbesiegbare KI**: Verwendet Minimax-Algorithmus mit tiefenbasierter Optimierung
- **Eingabevalidierung**: Robuste Fehlerbehandlung für ungültige Züge
- **Spielstatenverwaltung**: Verfolgt Siege, Niederlagen und Unentschieden
- **Intelligente Entscheidungsfindung**: KI spielt optimal

### Konsolversion
- **Interaktive Textschnittstelle**: Benutzerfreundliches menügesteuertes Spiel
- **Klare Anzeige des Spielbretts**: ASCII-Darstellung des Spielbretts
- **Tastatureingabe**: Geben Sie Zahlen 1-9 ein, um Ihre Markierungen zu platzieren

### Grafische Version (NEU!)
- **Moderne grafische Oberfläche**: Gebaut mit SFML (Simple and Fast Multimedia Library)
- **Mausinteraktion**: Klicken Sie direkt auf die Spielfeldfelder
- **Visuelle Markierungen**: Farbcodierte X (Rot) und O (Blau) Markierungen
- **Echtzeit-Rendering**: Reibungslose Grafik mit 60 FPS
- **Sofortiger Neustart**: Drücken Sie LEERTASTE zum erneuten Spielen
- **Statusmeldungen**: Klare Rückmeldung auf dem Bildschirm

## Projektstruktur

```
prueba-de-programación/
├── Spiellogik-Dateien
├── main.cpp                 # Einstiegspunkt der Konsolversion
├── main-gui.cpp             # Einstiegspunkt der GUI-Version
├── TicTacToe.h              # Deklaration der Spiellogik-Klasse
├── TicTacToe.cpp            # Implementierung der Spiellogik
├── GUI.h                    # Deklaration der grafischen Schnittstelle
├── GUI.cpp                  # Implementierung der grafischen Schnittstelle
├── CMakeLists.txt           # Build-Konfiguration
├── Makefile                 # Traditionelles Make-Build
├── README.md                # Diese Datei
├── GUI_BUILD_GUIDE.md       # SFML-Installationsanleitung
├── COMPILATION_GUIDE.md     # Windows-Kompilierungsanleitung
├── ALGORITHM_DOCUMENTATION.md  # Minimax-Algorithmusdetails
└── PROJECT_SUMMARY.md       # Projektübersicht
```

## Dateibeschreibungen

### Spielkern (Geteilt von Beiden Versionen)

**TicTacToe.h**
- Header-Datei mit Deklaration der Spiellogik-Klasse
- Definiert die Schnittstelle der `TicTacToe`-Klasse
- Dokumentiert alle öffentlichen Methoden und Funktionen

**TicTacToe.cpp**
- Implementierung der `TicTacToe`-Klasse
- Enthält den Minimax-Algorithmus für die KI
- Implementiert Spielbrettverwaltung und Spielstatusauswertung

### Konsolversion

**main.cpp**
- Einstiegspunkt für Konsolanwendung
- Enthält Spielschleife und textbasierte Benutzeroberfläche
- Handhabt Tastatureingabe und Menünavigation
- Zeigt Spielbrett mit ASCII-Zeichen an

### Grafische Version (NEU!)

**main-gui.cpp**
- Einstiegspunkt für GUI-Anwendung
- Initialisiert Spiel und übergibt es an GUI-Renderer

**GUI.h**
- Header-Datei für grafische Schnittstellen-Klasse
- Definiert `TicTacToeGUI`-Klasse unter Verwendung der SFML-Bibliothek
- Dokumentiert alle Rendering- und Eingabebehandlungsmethoden

**GUI.cpp**
- Implementierung der grafischen Schnittstelle
- Handhabt SFML-Rendering, Fensterverwaltung und Ereignisse
- Zeichnet Spielbrett, Markierungen und Statusinformationen
- Verarbeitet Mausklicks und Tastatureingaben

### Build & Konfiguration

**CMakeLists.txt**
- Build-Konfiguration für plattformübergreifende Kompilierung
- Unterstützt C++11-Standard
- Erkennt und verlinkt SFML automatisch, falls verfügbar
- Erstellt sowohl Konsolen- als auch GUI-Versionen

**Makefile**
- Traditionelles Unix-Make-Build-Skript
- Alternative zu CMake für einfache Kompilierung

### Dokumentation

**README.md** (diese Datei)
- Vollständige Projektübersicht und Nutzungsanleitung

**GUI_BUILD_GUIDE.md** (NEU!)
- Anleitung zur Installation von SFML
- Plattformspezifische Build-Verfahren
- Fehlerbehebungsanleitung

**COMPILATION_GUIDE.md**
- Detaillierte Windows-Kompilierungsanleitung
- Mehrere Kompilierungsmethoden

**ALGORITHM_DOCUMENTATION.md**
- Technische Erklärung des Minimax-Algorithmus
- Spieltheorischer Hintergrund
- Leistungsanalyse

**PROJECT_SUMMARY.md**
- Projektstatistiken und Highlights
- Funktionsmatrix und Vergleiche

## Kompilierung

### Schnellstart (Konsolversion)

**Windows (Eingabeaufforderung)**
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

### Kompilieren Sie beide Versionen mit CMake

#### Voraussetzungen
- **C++-Compiler**: g++, MSVC oder Clang (C++11 oder höher)
- **CMake**: Version 3.10 oder höher
- **SFML** (optional, für GUI): Siehe GUI_BUILD_GUIDE.md für Installation

#### Build-Schritte

```bash
# Zum Projekt navigieren
cd prueba-de-programación

# Build-Verzeichnis erstellen
mkdir build
cd build

# Dateien generieren
cmake ..

# Kompilieren
cmake --build .

# Ergebnis: Ausführbare Dateien TicTacToe und TicTacToe-GUI
```

#### Nur Konsolversion

```bash
cd build
./bin/TicTacToe          # Linux/macOS
bin\TicTacToe.exe        # Windows
```

#### Grafische Version

Für die GUI-Version **installieren Sie zuerst SFML** (siehe GUI_BUILD_GUIDE.md), dann:

```bash
cd build
./bin/TicTacToe-GUI      # Linux/macOS
bin\TicTacToe-GUI.exe    # Windows
```

### Manuelle Kompilierung mit g++

```bash
cd prueba-de-programación
g++ -std=c++11 -o TicTacToe main.cpp TicTacToe.cpp
./TicTacToe
```

#### Verwendung von Visual Studio (Windows)

```bash
# Im Projektverzeichnis
mkdir build
cd build
cmake ..

# Dies generiert Visual Studio-Projektdateien
# Öffnen Sie die generierte .sln-Datei in Visual Studio und führen Sie den Build aus
```

## Wie man spielt

### Spielregeln

1. **Spieler**: Du spielst als 'X' und die KI spielt als 'O'
2. **Spielbrett**: Das Spielbrett besteht aus einem 3x3-Gitter mit Positionen nummeriert 1-9:
   ```
   1 | 2 | 3
   ---------
   4 | 5 | 6
   ---------
   7 | 8 | 9
   ```

3. **Ziel**: Sei der erste, der drei deiner Markierungen in einer Reihe hat (horizontal, vertikal oder diagonal)
4. **Spielablauf**: 
   - Geben Sie eine Nummer (1-9) ein, um Ihre Markierung auf dieser Position zu platzieren
   - Die KI wird dann ihren Zug machen
   - Das Spiel wird fortgesetzt, bis es einen Gewinner gibt oder das Spielbrett voll ist (Unentschieden)

### Strategietipps

- Die Mitte (Position 5) ist oft eine strategische Startposition
- Ecken sind wertvoll, um Diagonalsiege zu blockieren
- Die KI spielt optimal, daher ist ein Unentschieden das Beste, das Sie erreichen können

## Algorithmuserklärung

### Minimax-Algorithmus

Die KI verwendet den **Minimax-Algorithmus**, einen Entscheidungsalgorithmus, der:

1. **Alle möglichen zukünftigen Spielzustände rekursiv erforscht**
2. **Endzustände evaluiert**: Weist +10 für KI-Sieg, -10 für menschlichen Sieg, 0 für Unentschieden zu
3. **Maximiert** wenn es der KI-Zug ist (höchste Punktzahl wählen)
4. **Minimiert** wenn es der menschliche Zug ist (niedrigste Punktzahl aus KI-Perspektive wählen)
5. **Wählt** den Zug, der zum besten Ergebnis führt

**Tiefenbasierte Optimierung**: Der Algorithmus bevorzugt schnellere Siege und verzögert Verluste durch Anpassung der Ergebnisse basierend auf Rekursionstiefe.

### Zeitkomplexität

- **Worst Case**: O(9!) - erforscht alle möglichen Spielzustände
- **Durchschnittlicher Fall**: Viel schneller aufgrund frühzeitiger Spielbeendigung und Pruning

## Code-Dokumentation

Der gesamte Codebase enthält:
- **Doxygen-Stil-Kommentare** für umfassende Dokumentation
- **Funktionsdokumentation** mit Parameter- und Rückgabewertbeschreibungen
- **Klassendokumentation** erklären Zweck und Design
- **Algorithmuserklärung** innerhalb des Codes

## Beispiel-Spielsitzung

```
═══════════════════════════════════════════
   TIC TAC TOE-SPIEL IN C++
═══════════════════════════════════════════

╔════════════════════════════════╗
║     TIC TAC TOE - HAUPTMENÜ    ║
╚════════════════════════════════╝

1. Neues Spiel starten
2. Anleitung
3. Beenden

Wählen Sie eine Option (1-3): 1

╔════════════════════════════════╗
║   Willkommen zu TIC TAC TOE!   ║
║   Sie sind X, KI ist O         ║
╚════════════════════════════════╝

     |     |     
  1  |  2  |  3  
-----------+-----------+-----------
  4  |  5  |  6  
-----------+-----------+-----------
  7  |  8  |  9  
     |     |     

Geben Sie Ihren Zug ein (1-9): 5

     |     |     
  1  |  2  |  3  
-----------+-----------+-----------
  4  |  X  |  6  
-----------+-----------+-----------
  7  |  8  |  9  
     |     |     

KI überlegt...

     |     |     
  1  |  O  |  3  
-----------+-----------+-----------
  4  |  X  |  6  
-----------+-----------+-----------
  7  |  8  |  9  
     |     |     

... (Spiel wird fortgesetzt)
```

## Mögliche Verbesserungen

- Schwierigkeitsstufen hinzufügen (Leicht, Mittel, Schwer)
- Alpha-Beta-Pruning für schnellere Berechnung implementieren
- GUI mit grafischem Spielbrett hinzufügen
- Zwei-Spieler-Modus unterstützen (ohne KI)
- Spielstatistiken und Punkteverfolgung hinzufügen
- Eröffnungsbuch für schnellere KI-Züge implementieren
- Rückgängig/Wiederherstellen-Funktionalität hinzufügen

## Systemanforderungen

- **OS**: Windows, macOS, Linux
- **C++-Standard**: C++11 oder höher
- **Speicher**: Minimal (weniger als 1 MB)
- **CPU**: Jeder moderne Prozessor

## Lizenz

Dieses Projekt wird wie besehen zu Bildungs- und Freizeitzwecken bereitgestellt.

## Autor

Jorge

## Version

1.0 - Erste Veröffentlichung

## Support & Fehlerbehebung

### F: Die KI scheint beim ersten Zug langsam zu sein
A: Die Berechnung des ersten Zuges erforscht viele Möglichkeiten. Dies ist normal und die KI entscheidet sich für die Mitte als optimal.

### F: Das Programm wird nicht kompiliert
A: Stellen Sie sicher, dass Sie folgende haben:
- Einen C++11-kompatiblen Compiler
- CMake installiert (wenn CMake verwendet wird)
- Alle drei Quelldateien (main.cpp, TicTacToe.h, TicTacToe.cpp) im gleichen Verzeichnis

### F: Kann ich die KI besiegen?
A: Die KI ist unbesiegbar, wenn sie zuerst geht, und sollte nur unentschieden sein, wenn Sie zuerst gehen und optimal spielen.

---

**Viel Spaß beim Spiel!**
