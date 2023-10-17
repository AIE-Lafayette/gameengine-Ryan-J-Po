#include "RainfallComponent.h"

void GameGraphics::RainfallComponent::update(double deltaTime)
{
	m_offsetX = m_offsetX + deltaTime;
	m_offsetY = m_offsetY + deltaTime;
	getShader()->setVec2("offset", m_offsetX, m_offsetY);
}
