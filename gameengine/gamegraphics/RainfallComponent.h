#pragma once
#include "SpriteComponent.h"
#include <GameMath/Vector2.h>

namespace GameGraphics
{
	class RainfallComponent : public SpriteComponent
	{
	public:
		RainfallComponent(const char* texturePath) : GameGraphics::SpriteComponent(texturePath, "Rainfall.vert", "Rainfall.frag") {}
		void update(double deltaTime) override;
		
	private:
		double m_offsetX = 0;
		double m_offsetY = 0;
	};
}
