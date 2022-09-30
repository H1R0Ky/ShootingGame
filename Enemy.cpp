#include"Enemy.h"
#include"Game.h"
#include"SpriteComponent.h"
#include"Bullet.h"
#include"CircleComponent.h"
#include<iostream>

const static int Number_of_bullet[6] = { 2,3,1,1,1,1 };

const static float Number_of_Scale[6] = { 0.8f,0.8f,1.2f,0.8f,0.9f,0.5f };

const static float Bullet_Cooldown[6] = { 1.0f,1.2f,2.0f,2.5f,2.5f,0.8f };

const static std::string Kind_of_Bullet[6] =
{
	"Assets/Ball.png",
	"Assets/Ball.png",
	"Assets/Ball2.png",
	"Assets/Ball3_001.png",
	"Assets/Ball4.png",
	"Assets/Ball5.png"
};


Enemy::Enemy(Game* game) :
	Actor(game),
	enemyNumber(0),
	cooldownNumber(0),
	VerticalSpeed(0.0f),
	HorizontalSpeed(0.0f),
	time(0.0f),
	Cooldown(3.0f),
	mCircle(nullptr)
{

}

Enemy::~Enemy() 
{
	GetGame()->RemoveActor(this);
}

void Enemy::UpdateActor(float deltatime) 
{
	EnemyAI(deltatime);
}

void Enemy::EnemyAI(float deltatime) 
{
	Cooldown -= deltatime;
	Vector2 pos = GetPosition();
	Vector2 direction = GetForward();
	if (pos.x > 1200.0f) 
	{
		HorizontalSpeed = 200 * deltatime * direction.x;
	}
	else
	{
		HorizontalSpeed = 0.0f;
		if (Cooldown <= 0.0f) 
		{
			GenerateBullet(enemyNumber);
			Cooldown = Bullet_Cooldown[cooldownNumber];
		}
	}
	pos.x += HorizontalSpeed;
	pos.y += VerticalSpeed;
	SetPosition(pos);
}

void Enemy::GenerateBullet(int num)
{
	switch (num)
	{
	case 0:
		for (int i = 0; i < Number_of_bullet[enemyNumber]; i++)
		{
			Bullet* bullet = new Bullet(GetGame());
			bullet->SetPosition(GetPosition() + Vector2(0.0f, (float)pow(-1.0f, i) * 10.0f));
			bullet->SetRotation(GetRotation());
			bullet->SetScale(GetScale() * Number_of_Scale[num]);
			SetBulletStatus(bullet, num);
		}
		break;
	case 1:
		for (int i = 0; i < Number_of_bullet[enemyNumber]; i++) 
		{
			Bullet* bullet = new Bullet(GetGame());
			bullet->SetPosition(GetPosition());
			bullet->SetRotation(GetRotation() + Math::Pi * (1 - i) / 6);
			bullet->SetScale(GetScale() * Number_of_Scale[num]);
			SetBulletStatus(bullet, num);
		}
		break;
	case 2:
		for (int i = 0; i < Number_of_bullet[enemyNumber]; i++) 
		{
			Bullet* bullet = new Bullet(GetGame());
			bullet->SetPosition(GetPosition());
			bullet->SetScale(GetScale() * Number_of_Scale[num]);
			SetBulletStatus(bullet, num);
		}
		break;
	case 3:
		for (int i = 0; i < Number_of_bullet[enemyNumber]; i++) 
		{
			Bullet* bullet = new Bullet(GetGame());
			bullet->SetPosition(GetPosition());
			bullet->SetScale(GetScale() * Number_of_Scale[num]);
			SetBulletStatus(bullet, num);
		}
		break;
	case 4:
		for (int i = 0; i < Number_of_bullet[enemyNumber]; i++) 
		{
			Bullet* bullet = new Bullet(GetGame());
			bullet->SetPosition(GetPosition());
			bullet->SetScale(GetScale() * Number_of_Scale[num]);
			SetBulletStatus(bullet, num);
		}
		break;
	case 5:
		for (int i = 0; i < Number_of_bullet[enemyNumber]; i++) 
		{
			Bullet* bullet = new Bullet(GetGame());
			bullet->SetPosition(GetPosition());
			bullet->SetScale(GetScale() * Number_of_Scale[num]);
			SetBulletStatus(bullet, num);
		}
		break;
	default:
		break;
	}
}

void Enemy::SetBulletStatus(Bullet* bullet, int number) 
{
	SpriteComponent* sc = new SpriteComponent(bullet, 99);
	SDL_Texture* bullet_tex = GetGame()->GetTexture(Kind_of_Bullet[number]);
	sc->SetTexture(bullet_tex);

	bullet->SetEnemy(this);
	bullet->SetNumber(enemyNumber);
}