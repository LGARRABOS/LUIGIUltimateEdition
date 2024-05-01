#pragma once
#include "..\..\Includes\Object\Player.h"

Player::~Player()
{
}

void Player::Start()
{
	transformInitial.x = 500;
	transformInitial.y = 400;
	TransformComponent* c_transform = ObjectManager::GetInstance()->CreateObject<TransformComponent>(TransformComponent::StaticClass().ClassID);
	RenderComponent* c_render = ObjectManager::GetInstance()->CreateObject<RenderComponent>(RenderComponent::StaticClass().ClassID);
	ColliderComponent* c_collider = ObjectManager::GetInstance()->CreateObject<ColliderComponent>(ColliderComponent::StaticClass().ClassID);
	componentList.insert(std::make_pair("Transform", c_transform));
	componentList.insert(std::make_pair("Render",c_render));
	componentList.insert(std::make_pair("Collider", c_collider));
	Cast<TransformComponent>(componentList.at("Transform"))->UpdatePosition(transformInitial);
	if (!texture.loadFromFile("../../LUIGIUltimateEdition/Ressources/mario_projet.png"))
	{
	}
	Cast<RenderComponent>(componentList.at("Render"))->LoadSprite(texture, Cast<TransformComponent>(componentList.at("Transform"))->position);
	
}

void Player::PlayerMove(float speed,float deltaTime)
{
	Cast<RenderComponent>(componentList.at("Render"))->spriteComp.move(speed * deltaTime,0);
}

void Player::PlayerJump(FVector2D velocity,float deltaTime)
{
	Cast<RenderComponent>(componentList.at("Render"))->spriteComp.move(velocity.x * deltaTime, velocity.y);
	
}

void Player::Collide()
{
}
