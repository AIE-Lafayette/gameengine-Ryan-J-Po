#include "Project1/Component.h"

class RotationComponent : public GameEngine::Component
{
public:
	void update(double deltaTime) override;
	
private:
	float _radians;
};