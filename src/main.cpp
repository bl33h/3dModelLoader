/*---------------------------------------------------------------------------
Copyright (C), 2022-2023, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: main.cpp
@version: I
Creation: 12/08/2023
Last modification: 17/08/2023
*Some parts were made using the AIs Bard and ChatGPT
------------------------------------------------------------------------------*/

#include "colors.h"
#include "faces.h"
#include "triangles.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <array>
#include <fstream>
#include <sstream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Window dimentions and render
const int windowWidth = 900;
const int windowHeight = 900;
SDL_Renderer* renderer = nullptr;

// Background and drawing colors
Color clearColor(111, 99, 143, 0);
Color currentColor(255, 255, 255, 255);

// Function to draw lines between two points
void linesDrawing(const glm::vec3& start, const glm::vec3& end) 
{
    SDL_RenderDrawLine(renderer, static_cast<int>(start.x), static_cast<int>(start.y),
    static_cast<int>(end.x), static_cast<int>(end.y));
}

// Function to draw triangles using lines between three vertices
void trianglesDrawing(const glm::vec3& v1, const glm::vec3& v2, const glm::vec3& v3) 
{
    linesDrawing(v1, v2);
    linesDrawing(v2, v3);
    linesDrawing(v3, v1);
}