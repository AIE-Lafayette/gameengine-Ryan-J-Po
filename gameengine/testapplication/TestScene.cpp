#include "TestScene.h"
#include "Project1/Entity.h"
#include "gamegraphics/ShapeComponent.h"
#include "gamephysics/RigidBodyComponent.h"
#include "gamephysics/CircleColliderComponent.h"
#include "gamephysics/AABBColliderComponent.h"
#include "gamephysics/CContainerColliderComponent.h"
#include "Project1/Input.h"
#include "gamegraphics/SpriteComponent.h"
#include "RotationComponent.h"
#include "gamegraphics/RainfallComponent.h"
#include "gamegraphics/SnowfallComponent.h"
#include <cstdlib>

GameEngine::Entity* rain = new GameEngine::Entity();
GameEngine::Entity* snow = new GameEngine::Entity();
GameEngine::Entity* shop = new GameEngine::Entity();
GameEngine::Entity* shop2 = new GameEngine::Entity();

void TestScene::onStart()
{

	//New Entity - rain ----------------------------------------------------------------------------------------------
	//GameEngine::Entity* rain = new GameEngine::Entity();

	rain->getTransform()->setLocalPosition(0, 0);

	GameGraphics::RainfallComponent* rainfallSprite = new GameGraphics::RainfallComponent("raintest2.png");
	rain->addComponent(rainfallSprite);
	rain->getTransform()->setLocalScale(800, 600);

	addEntity(rain);
	rain->setEnabled(false);
	//New Entity - snow ----------------------------------------------------------------------------------------------
	//GameEngine::Entity* snow = new GameEngine::Entity();

	snow->getTransform()->setLocalPosition(0, 0);

	GameGraphics::SnowfallComponent* snowfallSprite = new GameGraphics::SnowfallComponent("snowtest2.png");
	snow->addComponent(snowfallSprite);
	snow->getTransform()->setLocalScale(800, 600);

	addEntity(snow);
	snow->setEnabled(false);

	//New Entity - shop -----------------------------------------------------------------------------------------------
	//GameEngine::Entity* shop = new GameEngine::Entity();

	GameGraphics::SpriteComponent* shopSprite = new GameGraphics::SpriteComponent("Cool_night_shop-0.png");
	shop->addComponent(shopSprite);
	shop->getTransform()->setLocalScale(800, 600);

	addEntity(shop);
	shop->setEnabled(false);

	//New Entity - shop2 ----------------------------------------------------------------------------------------------
	//GameEngine::Entity* shop2 = new GameEngine::Entity();

	GameGraphics::SpriteComponent* shop2Sprite = new GameGraphics::SpriteComponent("Cool_day_shop-0.png");
	shop2->addComponent(shop2Sprite);
	shop2->getTransform()->setLocalScale(800, 600);

	addEntity(shop2);
	shop2->setEnabled(false);

	//New Entity - InputManager ---------------------------------------------------------------------------------------
	//Input* inputManager = new Input();

	/*if (Input::getLeftMouseButton())
	{
		rain->setEnabled(true);
	}*/
}

void TestScene::onUpdate(double deltaTime)
{
	if (Input::getLeftMouseButton())
	{	
		snow->setEnabled(false);
		rain->setEnabled(true);
	}
	if (!Input::getLeftMouseButton())
	{
		rain->setEnabled(false);
		snow->setEnabled(true);
	}
	if (Input::getRightMouseButton())
	{
		shop2->setEnabled(false);
		shop->setEnabled(true);
	}
	if (!Input::getRightMouseButton())
	{
		shop->setEnabled(false);
		shop2->setEnabled(true);
	}
}
