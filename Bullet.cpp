#include"Bullet.h"
#include"Game.h"
#include"SpriteComponent.h"
#include"CircleComponent.h"
#include"Player.h"
#include"Enemy.h"
#include"EnemyPrefab.h"
#include<iostream>

const static float bulletSpeed[6] = { 600.0f,600.0f,450.0f,650.0f,300.0f,800.0f };

Bullet::Bullet(Game* game) :
	Actor(game),
	enemyNumber(0),
	VerticalSpeed(0.0f),
	HorizontalSpeed(0.0f),
	mPlayer(nullptr),
	mEnemy(nullptr),
	mCircle(nullptr)
{
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(16.0f);
	game->AddBullet(this);
}

Bullet::~Bullet() 
{
	GetGame()->RemoveBullet(this);
	GetGame()->RemoveActor(this);
}

void Bullet::UpdateActor(float deltatime) 
{
	Actor::UpdateActor(deltatime);

	HorizontalSpeed = bulletSpeed[enemyNumber];
	VerticalSpeed = bulletSpeed[enemyNumber];
	Vector2 pos = GetPosition();
	Vector2 direction = GetForward();
	pos.x += HorizontalSpeed * deltatime * direction.x;
	pos.y += VerticalSpeed * deltatime * direction.y;
	SetPosition(pos);

	if (pos.x >= 1600.0f || pos.x <= 0.0f) {
		SetState(EDead);
	}

	if (GetParentPlayer() == nullptr) {
		//Player‚Æ‚ÌÕ“Ëˆ—
		Player* player = GetGame()->GetPlayer();
		if (Intersect(*mCircle, *(player->GetCircle()))) {
			std::cout << "Damage..." << std::endl;
			SetState(EDead);
			GetGame()->RemoveBullet(this);
		}
	}
	else if (GetParentEnemy() == nullptr) {
		//Enemy‚Æ‚ÌÕ“Ëˆ—
		std::vector<class Enemy*> enemies = GetGame()->GetEnemy();
		for (auto i : enemies) {
			if (Intersect(*mCircle, *(i->GetCircle()))) {
				std::cout << "HIT!" << std::endl;
				SetState(EDead);
				GetGame()->RemoveBullet(this);
				i->SetState(EDead);
				GetGame()->RemoveEnemy(i);
				if (i->GetNumber() == 5) 
				{
					i->GetEnemyPrefab()->SetRivalFlag(true);
				}
				break;
			}
		}
	}
}