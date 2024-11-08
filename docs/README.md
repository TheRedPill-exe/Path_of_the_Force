# 🌌 Path of the Force 🌌  
### Un juego de rol en consola inspirado en *Star Wars*

---

![Banner](https://github.com/TheRedPill-exe/Path_of_the_Force/blob/main/assets/star-wars-chromebook-wallpaper.jpg) <!-- Imagen tipo banner que represente el tema del juego -->

**Path of the Force** es un juego de rol basado en consola que permite a los jugadores explorar el universo de *Star Wars* con sus propios personajes, enfrentarse en combates y vivir aventuras a través de perfiles personalizados.

--- 

## 🚀 Características

- **Sistema de creación y gestión de personajes**
- **Misiones y desafíos aleatorios** (en desarrollo)
- **Combate basado en atributos de personaje**
- **Perfiles con seguridad mediante encriptación básica**
- **Visualización en consola con arte ASCII** (en desarrollo)

---

## 📜 Descripción General

**Path of the Force** transporta al jugador a una galaxia lejana en una experiencia RPG inspirada en Star Wars. Con funcionalidades de gestión de datos en C++ y un sistema de combate por turnos, el jugador puede personalizar personajes, aceptar misiones y mejorar su equipo.

<!-- GIF que muestre el menú principal del juego  -->


---

## 🕹️ Instrucciones para Usar

1. **Clonar el repositorio**  
   ```bash
   git clone https://github.com/TheRedPIll-exe/Path_of_the_Force.git

---

## 🧙‍♂️ Funcionalidades

### 🔹 Combate por Turnos 
El sistema de combate está basado en atributos de personajes, con turnos que permiten planear estrategias en base a la salud, fuerza y habilidades. (en desarrollo)

<!-- Imagen mostrando un combate entre dos personajes -->
![Combate](https://github.com/TheRedPill-exe/Path_of_the_Force/blob/main/assets/star-wars-star-wars-the-rise-of-skywalker-movie-poster-poster-movie-characters-hd-wallpaper-preview.jpg)

### 🔹 Creación de Personajes
Los jugadores pueden crear personajes seleccionando diferentes atributos. Cada personaje puede pertenecer a facciones como Jedi, Sith, o Cazarrecompensas, y cuenta con atributos únicos.

<!-- Imagen de ejemplo del menú de creación de personajes -->
<p align="center">
  <img src="https://github.com/TheRedPill-exe/Path_of_the_Force/blob/main/assets/Menu.png" width="30%" />
  <img src="https://github.com/TheRedPill-exe/Path_of_the_Force/blob/main/assets/items.png" width="30%" />
  <img src="https://github.com/TheRedPill-exe/Path_of_the_Force/blob/main/assets/skills.png" width="30%" />
</p>

### 🔹 Sistema de Perfiles y Seguridad
Cada jugador puede crear un perfil protegido por contraseña. Los datos de cada perfil están encriptados para mayor seguridad.

<!-- GIF mostrando el acceso mediante contraseña y creación de perfil -->
![encrypt](https://github.com/user-attachments/assets/b050441d-7e1a-4c99-94b4-18b5b2877cca)

### 🔹 Misiones y Recompensas (en desarrollo)
Explora misiones únicas que recompensan al jugador con experiencia y objetos especiales para mejorar sus personajes.

<!-- GIF mostrando una misión o recompensa -->

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
│   ├── MissionSystem.cpp/h  # Lógica de misiones y recompensas / en desarrollo
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
```
## 🔒 Encriptación

Cada perfil de usuario está protegido con encriptación César, asegurando la privacidad de los datos almacenados. Los datos se guardan en archivos binarios en la carpeta `assets/data`.

---

## 📈 Contribuciones

Las contribuciones son bienvenidas. Si deseas agregar nuevas funcionalidades o mejoras, por favor crea una rama y envía un *pull request*.

