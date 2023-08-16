/*---------------------------------------------------------------------------
Copyright (C), 2022-2023, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: triangles.h
@version: I
Creation: 10/08/2023
Last modification: 10/08/2023
*Some parts were made using the AIs Bard and ChatGPT
------------------------------------------------------------------------------*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glm/glm.hpp>
#include "colors.h"
#include <SDL2/SDL.h>

void drawTriangle(SDL_Renderer* renderer, const glm::vec3& v1, const glm::vec3& v2, const glm::vec3& v3, const Color& currentColor);
#endif