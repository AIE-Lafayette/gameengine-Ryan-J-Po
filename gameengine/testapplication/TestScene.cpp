#include "TestScene.h"
#include "Project1/Entity.h"
#include "gamegraphics/ShapeComponent.h"
#include "gamephysics/RigidBodyComponent.h"
#include "gamephysics/CircleColliderComponent.h"
#include "gamephysics/AABBColliderComponent.h"
#include "gamephysics/CContainerColliderComponent.h"
#include "Raylib/raylib.h"

void TestScene::onStart()
{
	GameEngine::Entity* container = new GameEngine::Entity();
	//container->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE_CONTAINER));
	GamePhysics::RigidBodyComponent* rigidBodyContainter = container->addComponent<GamePhysics::RigidBodyComponent>();
	container->addComponent(new GamePhysics::CContainerColliderComponent(400));
	container->getTransform()->setLocalPosition(400, 400);
	container->getTransform()->setLocalScale(400, 400);

	rigidBodyContainter->setIsKinematic(true);
	rigidBodyContainter->setElasticity(0);

	//New entity - circle -------------------------------------------------------------------------------------------------------
	GameEngine::Entity* circle = new GameEngine::Entity();
	circle->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE));

	GamePhysics::RigidBodyComponent* rigidBodyCircle = circle->addComponent <GamePhysics::RigidBodyComponent>();
	circle->addComponent(new GamePhysics::CircleColliderComponent(31));

	//rigidBodyCircle->applyForce({ 100, -100 });

	circle->getTransform()->setLocalPosition( 410, 410 );
	circle->getTransform()->setLocalScale(30, 30);

	//rigidBodyCircle->setGravity(0);
	rigidBodyCircle->setElasticity(2);

	//New entity - circle2 -------------------------------------------------------------------------------------------------------
	GameEngine::Entity* circle2 = new GameEngine::Entity();
	circle2->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE));

	GamePhysics::RigidBodyComponent* rigidBodyCircle2 = circle2->addComponent <GamePhysics::RigidBodyComponent>();
	circle2->addComponent(new GamePhysics::CircleColliderComponent(60));

	//rigidBody->applyForce({ 100, -100 });

	circle2->getTransform()->setLocalPosition(400, 400);
	circle2->getTransform()->setLocalScale(50, 50);

	//rigidBodyCircle2->setGravity(0);
	rigidBodyCircle2->setElasticity(1);

	//New entity - box -----------------------------------------------------------------------------------------------------------
	GameEngine::Entity* box = new GameEngine::Entity();
	box->addComponent(new GameGraphics::ShapeComponent(GameGraphics::BOX));

	GamePhysics::RigidBodyComponent* rigidBodyBox = box->addComponent <GamePhysics::RigidBodyComponent>();
	box->addComponent(new GamePhysics::AABBColliderComponent(31, 31));

	box->getTransform()->setLocalPosition(500, 430);
	box->getTransform()->setLocalScale(30, 30);

	//rigidBodyBox->setGravity(0);
	//rigidBodyBox->setIsKinematic(true);
	rigidBodyBox->setElasticity(1.8);

	addEntity(container);
	addEntity(circle);
	//addEntity(circle2);
	addEntity(box);
}

void TestScene::onUpdate(double deltaTime)
{
	if (IsMouseButtonPressed(0))
	{
		GameEngine::Entity* obj = new GameEngine::Entity();
		obj->getTransform()->setLocalPosition({ (float)GetMouseX(), (float)GetMouseY(), 0 });
		obj->getTransform()->setLocalScale({ 20, 20, 0 });
		obj->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE));
		obj->addComponent(new GamePhysics::CircleColliderComponent(20));
		GamePhysics::RigidBodyComponent* rigidBodyObj = obj->addComponent <GamePhysics::RigidBodyComponent>();
		addEntity(obj);

	}
	if (IsMouseButtonPressed(1))
	{
		GameEngine::Entity* obj = new GameEngine::Entity();
		obj->getTransform()->setLocalPosition(200,200);
		obj->getTransform()->setLocalScale({ 20, 20, 0 });
		obj->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE));
		obj->addComponent(new GamePhysics::CircleColliderComponent(20));
		GamePhysics::RigidBodyComponent* rigidBodyObj = obj->addComponent <GamePhysics::RigidBodyComponent>();
		addEntity(obj);

	}
}
