#pragma once
#include "SpriteComponent.h"

namespace GameGraphics
{
	class SnowfallComponent : public SpriteComponent
	{
	public:
		SnowfallComponent(const char* texturePath) : GameGraphics::SpriteComponent(texturePath, "Rainfall.vert", "Rainfall.frag") {}
		//Constantly updates the texture by the X and Y offsets. Sets offsetX to be 0 and offsetY to be incremented by deltaTime / 6.
		void update(double deltaTime) override;

	private:
		double m_offsetX = 0;
		double m_offsetY = 0;
	};
}
