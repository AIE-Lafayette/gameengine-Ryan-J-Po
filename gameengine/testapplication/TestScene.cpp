#include "TestScene.h"
#include "Project1/Entity.h"
#include "gamegraphics/ShapeComponent.h"
#include "gamephysics/RigidBodyComponent.h"
#include "gamephysics/CircleColliderComponent.h"

void TestScene::onStart()
{
	GameEngine::Entity* circle = new GameEngine::Entity();
	circle->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE));

	GamePhysics::RigidBodyComponent* rigidBody = circle->addComponent <GamePhysics::RigidBodyComponent>();
	circle->addComponent(new GamePhysics::CircleColliderComponent(60));

	//rigidBody->applyForce({ 100, -100 });

	circle->getTransform()->setLocalPosition( 100, 100 );
	circle->getTransform()->setLocalScale(50, 50);

	GameEngine::Entity* circle2 = new GameEngine::Entity();
	circle2->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE));

	circle2->addComponent(new GamePhysics::CircleColliderComponent(60));

	//rigidBody->applyForce({ 100, -100 });

	circle2->getTransform()->setLocalPosition(100, 500);
	circle2->getTransform()->setLocalScale(50, 50);

	addEntity(circle);
	addEntity(circle2);
}
