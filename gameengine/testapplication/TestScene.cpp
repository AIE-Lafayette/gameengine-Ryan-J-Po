#include "TestScene.h"
#include "Project1/Entity.h"
#include "gamegraphics/ShapeComponent.h"
#include "gamephysics/RigidBodyComponent.h"
#include "gamephysics/CircleColliderComponent.h"
#include "gamephysics/AABBColliderComponent.h"
#include "gamephysics/CContainerColliderComponent.h"

void TestScene::onStart()
{
	GameEngine::Entity* container = new GameEngine::Entity();
	container->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE_CONTAINER));
	GamePhysics::RigidBodyComponent* rigidBodyContainter = container->addComponent<GamePhysics::RigidBodyComponent>();
	container->addComponent(new GamePhysics::CContainerColliderComponent(300));
	container->getTransform()->setLocalPosition(400, 400);
	container->getTransform()->setLocalScale(300, 300);

	//New entity - circle
	GameEngine::Entity* circle = new GameEngine::Entity();
	circle->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE));

	GamePhysics::RigidBodyComponent* rigidBodyCircle = circle->addComponent <GamePhysics::RigidBodyComponent>();
	circle->addComponent(new GamePhysics::CircleColliderComponent(31));

	//rigidBodyCircle->applyForce({ 100, -100 });

	circle->getTransform()->setLocalPosition( 110, 100 );
	circle->getTransform()->setLocalScale(30, 30);

	//rigidBodyCircle->setGravity(0);
	rigidBodyCircle->setElasticity(1);

	//New entity - circle2
	GameEngine::Entity* circle2 = new GameEngine::Entity();
	circle2->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE));

	GamePhysics::RigidBodyComponent* rigidBodyCircle2 = circle2->addComponent <GamePhysics::RigidBodyComponent>();
	circle2->addComponent(new GamePhysics::CircleColliderComponent(60));

	//rigidBody->applyForce({ 100, -100 });

	circle2->getTransform()->setLocalPosition(100, 200);
	circle2->getTransform()->setLocalScale(50, 50);

	rigidBodyCircle2->setGravity(0);

	//New entity - box
	GameEngine::Entity* box = new GameEngine::Entity();
	box->addComponent(new GameGraphics::ShapeComponent(GameGraphics::BOX));

	GamePhysics::RigidBodyComponent* rigidBodyBox = box->addComponent <GamePhysics::RigidBodyComponent>();
	box->addComponent(new GamePhysics::AABBColliderComponent(31, 31));

	box->getTransform()->setLocalPosition(100, 500);
	box->getTransform()->setLocalScale(30, 30);

	//rigidBodyBox->setGravity(0);
	rigidBodyBox->setIsKinematic(true);
	rigidBodyBox->setElasticity(.75);

	addEntity(circle);
	//addEntity(circle2);
	addEntity(box);
}
