#include "Gizmos.h"
#include <glad/glad.h>
#include <iostream>

unsigned int GameGraphics::Gizmos::m_vertexBufferID = 0;
unsigned int GameGraphics::Gizmos::m_fragBufferID = 0;
char* GameGraphics::Gizmos::m_vertexShader = nullptr;
char* GameGraphics::Gizmos::m_fragShader = nullptr;

void GameGraphics::Gizmos::init()
{
	//Create a new buffer on the GPU that can store data about our objects.
	glGenBuffers(1, &m_vertexBufferID);
	glGenBuffers(1, &m_fragBufferID);

	FILE* vertexShaderFile;
	fopen_s(&vertexShaderFile, "GizmoShader.vert", "rb");

	if (!vertexShaderFile)
	{
		std::cout << "Could not open vertex shader file." << std::endl;
		return;
	}
}