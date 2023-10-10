#include "SpriteComponent.h"
#define STB_IMAGE_IMPLEMENTATION
#include "Include/stb_image.h"
#include <glad/glad.h>
#include <iostream>


GameGraphics::SpriteComponent::SpriteComponent()
{
	m_spriteShader = new Shader("SpriteShader.ver", "SpriteShader.frag");
}