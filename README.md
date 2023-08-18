# 3dModelLoader
The code represents a program for loading and rendering a 3D model using SDL (Simple DirectMedia Layer) and OpenGL. The program is designed to read a 3D model in OBJ format, apply rotation transformations to it, and display the rotated model on the screen. 

<p align="center">
  <br>
  <img src="https://media3.giphy.com/media/v1.Y2lkPTc5MGI3NjExeDIya3ZwemRyMG9wNDl2ZDJhbGU4bGtrYzRuMnhpZ2s2cmo0bTEyaCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/2KYs49eO9V2VDGy3QX/giphy.gif" alt="pic" width="500">
  <br>
</p>

<p align="center" >
  <a href="#Files">Files</a> •
  <a href="#Features">Features</a> •
  <a href="#how-to-use">How To Use</a> 
</p>

## Files

- configure.sh: A shell script to set up the project dependencies and environment.
- build.sh: A shell script to build the project using CMake.
- run.sh: A shell script to execute the compiled graphics application.
- clean.sh: A shell script to clean up build artifacts and generated files.
- src: A directory containing the source code files for the graphics application.
  - colors.h: Header file that defines the Color struct and functions for manipulating colors in the application.
  - triangles.h: Header file that enables drawing triangles using SDL_Renderer with 3D vertices and colors from colors.h.
  - faces.h: Header file that defines the 'Face' struct containing a trio of integer vertex indices.
  - main.cpp: The main C++ source file that implements the graphics application.
- CMakeLists.txt: The CMake configuration file that manages the build process.

## Features
The main features of the graphics application include:

- 3D Model Loading and Rendering: The program can load 3D models in OBJ format and render them on the screen using SDL and OpenGL.
- Model Rotation: The application can apply horizontal and vertical rotation transformations to the loaded 3D model, allowing users to visualize the model from different angles.
- Interactive Display: The program provides an interactive display where users can view the loaded 3D model, rotate it using real-time transformations, and observe the changes in its orientation.
- Wireframe Rendering: The application renders the 3D model as wireframes, showing the edges and faces of the model using lines.
- Graphical User Interface: The program features a graphical user interface that utilizes SDL to create a window for rendering the 3D model, enabling easy interaction and visualization.
- User-Friendly Controls: Users can conveniently control the rotation of the model using the interface, allowing them to explore various viewpoints

## How To Use
To clone and run this application, you'll need [wsl](https://learn.microsoft.com/en-us/windows/wsl/install) and the following tools installed on it: [Git](https://git-scm.com), [C++ compiler](https://www.fdi.ucm.es/profesor/luis/fp/devtools/mingw.html), [CMake](https://cmake.org/download/), [Make](https://linuxhint.com/install-make-ubuntu/), [glm](https://sourceforge.net/projects/glm.mirror/), and [SDL2](https://www.oreilly.com/library/view/rust-programming-by/9781788390637/386c15eb-41b2-41b4-bd65-154a750a58d8.xhtml). From your command line:

```bash
# Clone this repository
$ git clone https://github.com/bl33h/3dModelLoader

# Open the project
$ cd 3dModelLoader

# Give execution permissions
$ chmod +x configure.sh
$ chmod +x build.sh
$ chmod +x run.sh

# Run the app
$ ./run.sh
```
