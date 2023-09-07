#include "TestScene.h"
#include "Project1/Entity.h"
#include "gamegraphics/ShapeComponent.h"
#include "gamephysics/RigidBodyComponent.h"
#include "gamephysics/CircleColliderComponent.h"
#include "gamephysics/AABBColliderComponent.h"

void TestScene::onStart()
{
	GameEngine::Entity* circle = new GameEngine::Entity();
	circle->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE));

	GamePhysics::RigidBodyComponent* rigidBodyCircle = circle->addComponent <GamePhysics::RigidBodyComponent>();
	circle->addComponent(new GamePhysics::CircleColliderComponent(60));

	//rigidBody->applyForce({ 100, -100 });

	circle->getTransform()->setLocalPosition( 100, 100 );
	circle->getTransform()->setLocalScale(50, 50);

	//New entity - circle2
	GameEngine::Entity* circle2 = new GameEngine::Entity();
	circle2->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE));

	//GamePhysics::RigidBodyComponent* rigidBodyCircle2 = circle2->addComponent <GamePhysics::RigidBodyComponent>();
	circle2->addComponent(new GamePhysics::CircleColliderComponent(60));

	//rigidBody->applyForce({ 100, -100 });

	circle2->getTransform()->setLocalPosition(100, 500);
	circle2->getTransform()->setLocalScale(50, 50);

	//New entity - box
	GameEngine::Entity* box = new GameEngine::Entity();
	box->addComponent(new GameGraphics::ShapeComponent(GameGraphics::BOX));

	GamePhysics::RigidBodyComponent* rigidBodyBox = box->addComponent <GamePhysics::RigidBodyComponent>();
	box->addComponent(new GamePhysics::AABBColliderComponent(35, 35));

	box->getTransform()->setLocalPosition(100, 550);
	box->getTransform()->setLocalScale(25, 25);

	addEntity(circle);
	addEntity(circle2);
	addEntity(box);
}
