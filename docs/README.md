# 🌌 Path of the Force 🌌  
### Un juego de rol en consola inspirado en *Star Wars*

---

![Banner](assets/banner.png) <!-- Imagen tipo banner que represente el tema del juego -->

**Path of the Force** es un juego de rol basado en consola que permite a los jugadores explorar el universo de *Star Wars* con sus propios personajes, enfrentarse en combates y vivir aventuras a través de perfiles personalizados.

--- 

## 🚀 Características

- **Sistema de creación y gestión de personajes**
- **Misiones y desafíos aleatorios**
- **Combate basado en atributos de personaje**
- **Perfiles con seguridad mediante encriptación básica**
- **Visualización en consola con arte ASCII**

---

## 📜 Descripción General

**Path of the Force** transporta al jugador a una galaxia lejana en una experiencia RPG inspirada en Star Wars. Con funcionalidades de gestión de datos en C++ y un sistema de combate por turnos, el jugador puede personalizar personajes, aceptar misiones y mejorar su equipo.

<!-- GIF que muestre el menú principal del juego -->
![Menu Principal](assets/gif/menu.gif)

---

## 🕹️ Instrucciones para Jugar

1. **Clonar el repositorio**  
   ```bash
   git clone https://github.com/TheRedPIll-exe/Path_of_the_Force.git

---

## 🧙‍♂️ Funcionalidades

### 🔹 Creación de Personajes
Los jugadores pueden crear personajes seleccionando diferentes atributos. Cada personaje puede pertenecer a facciones como Jedi, Sith, o Cazarrecompensas, y cuenta con atributos únicos.

<!-- Imagen de ejemplo del menú de creación de personajes -->
![Creación de Personajes](assets/images/character_creation.png)

### 🔹 Sistema de Perfiles y Seguridad
Cada jugador puede crear un perfil protegido por contraseña. Los datos de cada perfil están encriptados para mayor seguridad.

<!-- GIF mostrando el acceso mediante contraseña y creación de perfil -->
![Acceso de Perfil](assets/gif/perfil_acceso.gif)

### 🔹 Combate por Turnos
El sistema de combate está basado en atributos de personajes, con turnos que permiten planear estrategias en base a la salud, fuerza y habilidades.

<!-- Imagen mostrando un combate entre dos personajes -->
![Combate](assets/images/combat_example.png)

### 🔹 Misiones y Recompensas
Explora misiones únicas que recompensan al jugador con experiencia y objetos especiales para mejorar sus personajes.

<!-- GIF mostrando una misión o recompensa -->
![Misiones](assets/gif/misiones.gif)

---

## 📂 Estructura del Proyecto

La organización modular del proyecto facilita su mantenimiento y expansión. A continuación, se detalla la estructura principal:

```plaintext
Path_of_the_Force/
│
├── src/
│   ├── main.cpp             # Punto de entrada del programa
│   ├── Game.cpp/h           # Lógica principal del juego
│   ├── Character.cpp/h      # Gestión de los personajes y atributos
│   ├── BattleSystem.cpp/h   # Sistema de combate
│   ├── ProfileManager.cpp/h # Manejo de perfiles y encriptación
│   ├── Inventory.cpp/h      # Sistema de inventario
│   ├── MissionSystem.cpp/h  # Lógica de misiones y recompensas
│   ├── Display.cpp/h        # Funciones para mostrar arte ASCII
│   └── Utilities.cpp/h      # Funciones auxiliares y utilidades
│
├── assets/                   # Recursos del juego
│   ├── ascii_art/            # Arte ASCII de personajes
│   ├── data/                 # Archivos de datos de personajes y misiones
│
└── docs/
    └── README.md             # Documentación del proyecto
---

## 🔒 Encriptación

Cada perfil de usuario está protegido con encriptación César, asegurando la privacidad de los datos almacenados. Los datos se guardan en archivos binarios en la carpeta `assets/data`.

---

## 📈 Contribuciones

Las contribuciones son bienvenidas. Si deseas agregar nuevas funcionalidades o mejoras, por favor crea una rama y envía un *pull request*.

