#include"EnemyPrefab.h"
#include"Enemy.h" 
#include"Game.h"
#include"SpriteComponent.h"
#include"CircleComponent.h"
#include<string>
#include<iostream>

const static std::string Kind_of_Enemy[6] =
{ 
	"Assets/Enemy01.png",
	"Assets/Enemy02.png",
	"Assets/Enemy03.png",
	"Assets/Enemy04.png",
	"Assets/Enemy05.png",
	"Assets/Enemy06.png"
};

const static float Kind_of_Radius[6] = { 51.0f,58.0f,46.0f,32.0f,32.0f,52.0f };

const static float Kind_of_Scale[6] = { 0.3f,0.8f,1.5f,0.4f,0.5f,0.7f };

EnemyPrefab::EnemyPrefab(Game* game) :
	Actor(game),
	rivalFlag(false),
	positionNumber(0),
	time(0.0f),
	temp(3.0f)
{

}

void EnemyPrefab::UpdateActor(float deltatime) 
{
	time += deltatime;
	if (time >= 60.0f) 
	{
		if (positionNumber < 1) 
		{
			SetEnemyStatus(5, Vector2(1800.0f, 450.0f), Math::Pi);
			positionNumber++;
		}
		else if(GetRivalFlag())
		{
			time = 0.0f;
			temp = 3.0f;
			positionNumber = 0;
			SetRivalFlag(false);
		}
	}
	else if (time >= 45.0f) 
	{
		if (time - temp >= 0.6f && time < 50.0f && positionNumber < 10)
		{
			SetEnemyStatus(1, Vector2(1800.0f, 80.0f * (positionNumber + 1)), Math::Pi);
			SetEnemyStatus(1, Vector2(1800.0f, 80.0f * (positionNumber + 1) + 30.0f), Math::Pi);
			positionNumber++;
			temp = time;
		}
		else if (time >= 50.0f)
		{
			positionNumber = 0;
		}
	}
	else if (time >= 30.0f) 
	{
		if (time - temp >= 1.0f && time < 40.0f && positionNumber < 10)
		{
			SetEnemyStatus(0, Vector2(1800.0f, 80.0f * (positionNumber + 1)), Math::Pi);
			SetEnemyStatus(1, Vector2(1800.0f, 80.0f * (positionNumber + 1) + 40.0f), Math::Pi);
			positionNumber++;
			temp = time;
		}
		else if (time >= 40.0f)
		{
			positionNumber = 0;
		}
	}
	else if (time >= 15.0f) 
	{
		if (time - temp >= 0.2f && time < 16.0f && positionNumber < 5) 
		{
			SetEnemyStatus(1, Vector2(1800.0f, 150.0f * (positionNumber + 1)), Math::Pi);
			positionNumber++;
			temp = time;
		}
		else if (time >= 16.0f) 
		{
			positionNumber = 0;
		}
	}
	else if (time >= 3.0f) 
	{
		if (time - temp >= 0.1f && time < 4.0f && positionNumber < 10)
		{
			SetEnemyStatus(0, Vector2(1800.0f, 80.0f * (positionNumber + 1)), Math::Pi);
			positionNumber++;
			temp = time;
		}
		else if (time >= 4.0f)
		{
			positionNumber = 0;
		}
	}
}

void EnemyPrefab::SetEnemyStatus(int num, Vector2 pos, float rot)
{
	Enemy* enemy = new Enemy(GetGame());
	SpriteComponent* sc = new SpriteComponent(enemy);
	SDL_Texture* enemy_tex = GetGame()->GetTexture(Kind_of_Enemy[num]);
	sc->SetTexture(enemy_tex);
	enemy->SetPosition(pos);
	enemy->SetRotation(rot);
	enemy->SetScale(Kind_of_Scale[num]);
	enemy->SetNumber(num);
	enemy->SetCooldown(num);

	enemy->SetEnemyPrefab(this);

	CircleComponent* cc = new CircleComponent(enemy);
	cc->SetRadius(Kind_of_Radius[num]);
	enemy->SetCircle(cc);

	GetGame()->AddEnemy(enemy);
}
