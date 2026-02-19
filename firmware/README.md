# Continuity Tester - Arduino IDE Version

Diese Version ist für die Arduino IDE optimiert und kann direkt als Sketch geladen werden.

## Anforderungen

- **Mikrocontroller**: ATmega88PA
- **Taktfrequenz**: 1 MHz (niedrig, für Energiesparen)
- **Arduino IDE**: Version 1.8.x oder höher

## Installation

### Option 1: Direkt in Arduino IDE öffnen
1. Die Datei `ct.ino` in der Arduino IDE öffnen
2. Die erforderlichen Header-Dateien sollten automatisch erkannt werden

### Option 2: Als Sketchbook-Verzeichnis hinzufügen
1. Das `ct`-Verzeichnis in dein Arduino Sketchbook kopieren
2. In der Arduino IDE: `File > Sketchbook > ct > ct` öffnen

## Board-Konfiguration

1. **Board**: ATmega88PA (oder ein kompatibles Board auswählen)
2. **Programmer**: USBasp (oder dein Programmer)
3. **Clock Speed**: 1 MHz internal
4. **Fuses**: 
   - Low Fuse: 0x62
   - High Fuse: 0xdf
   - Extended Fuse: 0xf9

## Kompilierung und Upload

```bash
# Flash-Speicher programmieren
Tools > Burn Bootloader  # Setzt die Fuses

# Oder direkt über Makefile im Original-Verzeichnis:
cd ../
make all
make program-flash
make program-fuses
```

## Code-Struktur

- **ct.ino**: Hauptprogramm mit `setup()` und `loop()` Funktionen
- **gpio.hpp/cpp**: Abstraktion für GPIO-Operationen
- **delay.hpp**: Cycle-accurate Verzögerungsfunktionen
- **common.hpp**: Template-Hilfsfunktionen
- **volatile.hpp**: Volatile und Atomic-Operationen
- **tones.hpp**: Auto-generierte Tonfrequenztabelle

## Besonderheiten

- Das Projekt nutzt C++17 Features (constexpr, templates)
- Es wird mit Optimierungsstufe `-O3` und LTO kompiliert
- Exceptions sind deaktiviert (`-fno-exceptions`)
- Alle Fuses sind für 1 MHz interner Oszillator konfiguriert

## Original-Project

Für die Verwendung mit Standard-AVR-Tools (avr-gcc, avrdude) siehe das `firmware/` Verzeichnis mit Makefile.
