#include"GameOver.h"
#include"Game.h"
#include"SpriteComponent.h"

GameOver::GameOver(Game* game) :Actor(game)
{
	SpriteComponent* sc = new SpriteComponent(this,101);
	SDL_Texture* gameover = game->GetTexture("Assets/GameOver.png");
	sc->SetTexture(gameover);
	SetPosition(Vector2(800.0f, 450.0f));
	SetScale(1.0f);
}