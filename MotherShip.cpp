#include"MotherShip.h"
#include"Game.h"
#include"SpriteComponent.h"
#include"CircleComponent.h"
#include"Bullet.h"
#include"GameOver.h"
#include<iostream>

MotherShip::MotherShip(Game* game) :
	Actor(game),
	MotherShipHP(100)
{
	SpriteComponent* sc = new SpriteComponent(this);
	SDL_Texture* motherShip_tex = game->GetTexture("Assets/MotherShip.png");
	sc->SetTexture(motherShip_tex);
	SetPosition(Vector2(-350.0f, 450.0f));
	SetRotation(0.0f);
	SetScale(1.1f);

	mCircle = new CircleComponent(this);
	mCircle->SetRadius(400.0f);
}

void MotherShip::UpdateActor(float deltatime) 
{
	std::vector<class Bullet*> bullet = GetGame()->GetBullet();
	for (auto i : bullet) 
	{
		if (Intersect(*mCircle, *(i->GetCircle())))
		{
			std::cout << "HIT!?!?" << std::endl;
			i->SetState(EDead);
			MotherShipHP--;
			if (MotherShipHP <= 0) 
			{
				GameOver* go = new GameOver(GetGame());
				GetGame()->SetFlag(2);
				break;
			}
		}
	}
}