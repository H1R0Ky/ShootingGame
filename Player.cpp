#include"Player.h"
#include"Game.h"
#include"AnimSpriteComponent.h"
#include"Bullet.h"
#include"CircleComponent.h"
#include<iostream>

using namespace std;

Player::Player(Game* game) :
	Actor(game),
	VerticalSpeed(0.0f),
	HorizontalSpeed(0.0f),
	Cooldown(0.5f),
	mCircle(nullptr)
{
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player2.png"),
		game->GetTexture("Assets/Player3.png"),
		game->GetTexture("Assets/Player4.png"),
		game->GetTexture("Assets/Player3.png"),
		game->GetTexture("Assets/Player2.png"),
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player.png"),
		game->GetTexture("Assets/Player.png"),
	};
	asc->SetAnimTextures(anims);
	SetPosition(Vector2(300.0f, 450.0f));
	SetRotation(0.0f);
	SetScale(0.4f);

	mCircle = new CircleComponent(this);
	mCircle->SetRadius(64.0f);
}

void Player::UpdateActor(float deltatime) 
{
	Actor::UpdateActor(deltatime);

	Vector2 pos = GetPosition();
	pos.x += HorizontalSpeed * deltatime;
	pos.y += VerticalSpeed * deltatime;

	if (pos.x < 25.0f) {
		pos.x = 25.0f;
	}
	else if (pos.x > 1575.0f) {
		pos.x = 1575.0f;
	}
	if (pos.y < 25.0f) {
		pos.y = 25.0f;
	}
	else if (pos.y > 875.0f) {
		pos.y = 875.0f;
	}
	SetPosition(pos);
	Cooldown -= deltatime;
}

void Player::ProcessInput(const uint8_t* state) 
{
	VerticalSpeed = 0.0f;
	HorizontalSpeed = 0.0f;

	if (state[SDL_SCANCODE_S]) {
		VerticalSpeed += 300.0f;
	}
	if (state[SDL_SCANCODE_W]) {
		VerticalSpeed -= 300.0f;
	}
	if (state[SDL_SCANCODE_D]) {
		HorizontalSpeed += 300.0f;
	}
	if (state[SDL_SCANCODE_A]) {
		HorizontalSpeed -= 300.0f;
	}

	if (state[SDL_SCANCODE_SPACE] && Cooldown <= 0.0f) {
		Bullet* bullet = new Bullet(GetGame());
		bullet->SetPosition(Vector2(GetPosition()));
		bullet->SetRotation(GetRotation());
		bullet->SetScale(0.4f);

		SpriteComponent* sc = new SpriteComponent(bullet, 99);
		SDL_Texture* bullet_tex = GetGame()->GetTexture("Assets/Ball.png");
		sc->SetTexture(bullet_tex);

		bullet->SetPlayer(this);
		Cooldown = 0.5f;
	}
}