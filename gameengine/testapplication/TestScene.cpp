#include "TestScene.h"
#include <Entity.h>
#include <ShapeComponent.h>
#include <RigidBodyComponent.h>

void TestScene::onStart()
{
	GameEngine::Entity* circle = new GameEngine::Entity();
	circle->addComponent(new GameGraphics::ShapeComponent(GameGraphics::CIRCLE));

	GamePhysics::RigidBodyComponent* rigidBody = circle->addComponent <GamePhysics::RigidBodyComponent>();
	rigidBody->applyForce({ 100, -100 });

	circle->getTransform()->setLocalPosition( 100, 100 );
	circle->getTransform()->setLocalScale(50, 50);

	addEntity(circle);
}
