# 3dModelLoader
Code represents a program for loading and rendering a 3D model using SDL (Simple DirectMedia Layer) and OpenGL. The program is designed to read a 3D model in OBJ format, apply rotation transformations to it, and display the rotated model on the screen. 

<p align="center">
  <br>
  <img src="" alt="pic" width="500">
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
  - triangles.h:
  - faces.h:
  - main.cpp: The main C++ source file that implements the graphics application.
- CMakeLists.txt: The CMake configuration file that manages the build process.

## Features
The main features of the graphics application include:

- 

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
