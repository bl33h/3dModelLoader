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

// Function to draw the model using lines, vertices, and triangles
void drawModel(const std::vector<glm::vec3>& vertex) 
{   
    // Clear the renderer with the background color
    SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
    SDL_RenderClear(renderer);

    // Set the renderer color for drawing lines
    SDL_SetRenderDrawColor(renderer, currentColor.r, currentColor.g, currentColor.b, currentColor.a);

    // Iterate through vertices and draw triangles using lines
    for (size_t i = 0; i < vertex.size(); i += 3) {
        if (i + 2 < vertex.size()) {
            glm::vec3 v1 = vertex[i];
            glm::vec3 v2 = vertex[i + 1];
            glm::vec3 v3 = vertex[i + 2];
            int offsetX = windowWidth / 2;
            int offsetY = windowHeight / 1.5;
            trianglesDrawing(v1 + glm::vec3(offsetX, offsetY, 0), v2 + glm::vec3(offsetX, offsetY, 0), v3 + glm::vec3(offsetX, offsetY, 0));
        }
    }
}

// Function to load a 3D object from an OBJ file
bool load3Dobject(const std::string& path, std::vector<glm::vec3>& outputVertex, std::vector<Face>& out_faces) 
{   
    // Open the OBJ file
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cout << "Error: Couldn't open file " << path << std::endl;
        return false;
    }

    // Temporary storage for vertices and faces
    std::vector<glm::vec3> temporaryVertex;
    std::vector<std::array<int, 3>> temp_faces;

    // Read through the file line by line
    std::string line;
    while (std::getline(file, line)) 
    {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        // Parse vertex data
        if (type == "v") {
            glm::vec3 vertex;
            iss >> vertex.x >> vertex.y >> vertex.z;
            temporaryVertex.push_back(vertex);
        
        // Parse face data
        } else if (type == "f") {
            std::array<int, 3> faceID{};
            for (int i = 0; i < 3; i++) {
                std::string faceIndexStr;
                iss >> faceIndexStr;
                faceID[i] = std::stoi(faceIndexStr) - 1;
            }
            temp_faces.push_back(faceID);
        }
    }

    // Store the parsed data into output vectors
    outputVertex = temporaryVertex;
    out_faces.reserve(temp_faces.size());
    for (const auto& face : temp_faces) {
        out_faces.push_back({ face });
    }

    return true;
}

// Function to set up the vertex array for rendering
std::vector<glm::vec3> setupVertexArray(const std::vector<glm::vec3>& vertex, const std::vector<Face>& faces)
{    
    // Scale factor for vertices
    float scale = 40.0f;

    // Initialize vertex array
    std::vector<glm::vec3> vertexArray;

    // Process object's faces
    for (const auto& face : faces)
    {   
        // Get vertex positions and scale
        glm::vec3 vertexPosition1 = vertex[face.vertexIndices[0]];
        glm::vec3 vertexPosition2 = vertex[face.vertexIndices[1]];
        glm::vec3 vertexPosition3 = vertex[face.vertexIndices[2]];
        glm::vec3 vertexScaled1 = glm::vec3(vertexPosition1.x * scale, -vertexPosition1.y * scale, vertexPosition1.z * scale);
        glm::vec3 vertexScaled2 = glm::vec3(vertexPosition2.x * scale, -vertexPosition2.y * scale, vertexPosition2.z * scale);
        glm::vec3 vertexScaled3 = glm::vec3(vertexPosition3.x * scale, -vertexPosition3.y * scale, vertexPosition3.z * scale);

        // Add scaled vertices to the vertex array
        vertexArray.push_back(vertexScaled1);
        vertexArray.push_back(vertexScaled2);
        vertexArray.push_back(vertexScaled3);
    }

    return vertexArray;
}

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        std::cout << "Error: SDL_Init failed." << std::endl;
        return 1;
    }

    // Create SDL window
    SDL_Window* window = SDL_CreateWindow("3dModelLoader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    if (!window) 
    {
        std::cout << "Error: Could not create SDL window." << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create SDL renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) 
    {
        std::cout << "Error: Could not create SDL renderer." << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Load 3D model from OBJ file (here you can change the path in case you did not place the file in the objects folder)
    std::string filePath = "src/objects/spaceship.obj";
    std::cout << "Loading OBJ file: " << filePath << std::endl;

    // Initialize vectors to store vertex and face data
    std::vector<glm::vec3> vertex;
    std::vector<Face> faces;

    // Load the 3D model from the OBJ file
    if (!load3Dobject(filePath, vertex, faces)) 
    {
        std::cout << "Error: Could not load OBJ file." << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Set up the vertex array for rendering
    std::vector<glm::vec3> vertexArray = setupVertexArray(vertex, faces);

    // Clear the renderer and set drawing color
    SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
    SDL_RenderClear(renderer);

    // Draw the initial model
    SDL_SetRenderDrawColor(renderer, currentColor.r, currentColor.g, currentColor.b, currentColor.a);
    drawModel(vertexArray);
    SDL_RenderPresent(renderer);

    // Main loop for rendering and interaction
    bool running = true;
    SDL_Event event;
    float angle = 0.0f;

    while (running) {

        // Check for events
        while (SDL_PollEvent(&event)) 
        {
            // Exit the loop if the window is closed
            if (event.type == SDL_QUIT) 
            {
                running = false;
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        SDL_RenderClear(renderer);

        // Update rotation angle
        angle += 0.01f;

        // Create a rotation matrix around the Y-axis
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f));

        // Create a rotation matrix around the X-axis (vertical rotation)
        glm::mat4 rotationMatrixVertical = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0f, 0.0f, 0.0f));

        // Combine the rotation matrices for horizontal and vertical rotations
        glm::mat4 combinedRotationMatrix = rotationMatrixVertical * rotationMatrix;

        // Apply combined rotation to each vertex in the vertex array
        std::vector<glm::vec3> rotatedVertexArray;
        for (const auto& vertex : vertexArray) 
        {
            glm::vec4 rotatedVertex = combinedRotationMatrix * glm::vec4(vertex, 1.0f);
            rotatedVertexArray.push_back(glm::vec3(rotatedVertex));
        }

        // Draw the rotated model
        drawModel(rotatedVertexArray);
        SDL_RenderPresent(renderer);
    }

    // Clean up and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}