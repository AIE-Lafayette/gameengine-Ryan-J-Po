#include "SnowfallComponent.h"

void GameGraphics::SnowfallComponent::update(double deltaTime)
{
	m_offsetX = m_offsetX + deltaTime * 0;
	m_offsetY = m_offsetY + deltaTime / 6;
	getShader()->setVec2("offset", m_offsetX, m_offsetY);
}
