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
		float m_offsetX = 0;
		float m_offsetY = 0;
	};
}
