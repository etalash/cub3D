# cub3D

> A minimal 3D game engine built with raycasting, inspired by *Wolfenstein 3D*.
> This project is part of the **42 School** curriculum.

## Overview

**cub3D** is a first-person 3D renderer written in C using the **MiniLibX** graphics library.  
The engine parses a `.cub` configuration file, loads textures, builds a 2D map, and renders a real-time 3D view using classic **raycasting** techniques.

No game engine. No shortcuts. Just math, pointers, and pain.

---

## Features

- Raycasting-based 3D rendering
- Wall textures (North, South, East, West)
- Player movement and rotation
- Collision detection
- Configurable maps via `.cub` file
- Floor and ceiling colors
- Window rendering with MiniLibX
- Error handling and input validation

---

## Controls

| Key        | Action            |
|------------|------------------|
| `W` / `S`  | Move forward/back |
| `A` / `D`  | Strafe left/right |
| `←` / `→`  | Rotate view       |
| `ESC`      | Exit game         |

---

## Map Rules

- Map must be fully closed by walls (`1`)
- Valid characters:
  - `0` — empty space
  - `1` — wall
  - `N`, `S`, `E`, `W` — player spawn & orientation
- Exactly **one** player spawn allowed
- Any invalid map = program exits with error

Bad maps are rejected. No mercy.

---

## Installation

### Requirements

- macOS or Linux
- `gcc`
- `make`
- MiniLibX

### Build

```bash
make
