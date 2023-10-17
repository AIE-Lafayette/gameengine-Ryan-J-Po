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
#include <cstdlib>

void TestScene::onStart()
{
	
	//GameEngine::Entity* container = new GameEngine::Entity();
	////container->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE_CONTAINER));
	//GamePhysics::RigidBodyComponent* rigidBodyContainter = container->addComponent<GamePhysics::RigidBodyComponent>();
	//container->addComponent(new GamePhysics::CContainerColliderComponent(400));
	//container->getTransform()->setLocalPosition(0, 0);
	//container->getTransform()->setLocalScale(400, 400);

	//rigidBodyContainter->setIsKinematic(true);
	//rigidBodyContainter->setElasticity(0);

	////New entity - circle -------------------------------------------------------------------------------------------------------
	//GameEngine::Entity* circle = new GameEngine::Entity();
	//circle->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE));

	//GamePhysics::RigidBodyComponent* rigidBodyCircle = circle->addComponent <GamePhysics::RigidBodyComponent>();
	//circle->addComponent(new GamePhysics::CircleColliderComponent(30));

	//circle->getTransform()->setLocalPosition( 410, 410 );
	//circle->getTransform()->setLocalScale(30, 30);

	//rigidBodyCircle->setElasticity(1.3);

	////New entity - box -----------------------------------------------------------------------------------------------------------
	//GameEngine::Entity* box = new GameEngine::Entity();
	//box->addComponent(new GameGraphics::ShapeComponent(GameGraphics::BOX));

	//GamePhysics::RigidBodyComponent* rigidBodyBox = box->addComponent <GamePhysics::RigidBodyComponent>();
	//box->addComponent(new GamePhysics::AABBColliderComponent(30, 30));

	//box->getTransform()->setLocalPosition(410, 390);
	//box->getTransform()->setLocalScale(30, 30);

	////rigidBodyBox->setGravity(0);
	////rigidBodyBox->setIsKinematic(true);
	//rigidBodyBox->setElasticity(1.3);

	//addEntity(container);
	//addEntity(circle);
	////addEntity(circle2);
	//addEntity(box);

	GameEngine::Entity* rain = new GameEngine::Entity();

	GameGraphics::RainfallComponent* rainfallSprite = new GameGraphics::RainfallComponent("pixelflowersmall.png");
	rain->addComponent(rainfallSprite);
	//spaceShip->addComponent<RotationComponent>();
	rain->getTransform()->setLocalScale(100, 50);

	addEntity(rain);
}

void TestScene::onUpdate(double deltaTime)
{
	if (Input::getLeftMouseButton())
	{
		GameEngine::Entity* obj = new GameEngine::Entity();
		obj->getTransform()->setLocalPosition(Input::getMousePos().x, Input::getMousePos().y);
		obj->getTransform()->setLocalScale({ 20, 20, 0 });

		GameGraphics::ShapeComponent* shapeComponent = new GameGraphics::ShapeComponent(GameGraphics::CIRCLE);

		obj->addComponent(shapeComponent);
		obj->addComponent(new GamePhysics::CircleColliderComponent(20));

		GamePhysics::RigidBodyComponent* rigidBodyObj = obj->addComponent <GamePhysics::RigidBodyComponent>();
		rigidBodyObj->setElasticity(1.3);

		//shapeComponent->setColor((unsigned int)obj);
		addEntity(obj);

	}
	if (Input::getRightMouseButton())
	{
		GameEngine::Entity* obj = new GameEngine::Entity();
		obj->getTransform()->setLocalPosition(Input::getMousePos().x, Input::getMousePos().y);
		obj->getTransform()->setLocalScale({ 20, 20, 0 });

		GameGraphics::ShapeComponent* shapeComponent = new GameGraphics::ShapeComponent(GameGraphics::BOX);

		obj->addComponent(shapeComponent);
		obj->addComponent(new GamePhysics::AABBColliderComponent(20,20));

		GamePhysics::RigidBodyComponent* rigidBodyObj = obj->addComponent <GamePhysics::RigidBodyComponent>();
		rigidBodyObj->setElasticity(1.3);

		//shapeComponent->setColor((unsigned int)obj);
		addEntity(obj);

	}
}
