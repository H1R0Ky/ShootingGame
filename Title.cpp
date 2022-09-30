#include"Title.h"
#include"Game.h"
#include"Actor.h"
#include"SpriteComponent.h"
#include"BGSpriteComponent.h"
#include"Player.h"
#include"Enemy.h"
#include"EnemyPrefab.h"
#include"MotherShip.h"

Title::Title(class Game* game) :
	Actor(game),
	time(0.0f)
{

}

void Title::UpdateActor(float deltatime) 
{

}

void Title::ProcessInput(const uint8_t* state) 
{
	if (state[SDL_SCANCODE_RETURN]) 
	{
		EnemyPrefab* prefab = new EnemyPrefab(GetGame());
		Player* player = new Player(GetGame());
		GetGame()->SetPlayer(player);
		MotherShip* motherShip = new MotherShip(GetGame());
		// Create actor for the background (this doesn't need a subclass)
		Actor* temp = new Actor(GetGame());
		temp->SetPosition(Vector2(800.0f, 450.0f));
		// Create the "Back" background
		BGSpriteComponent* bg = new BGSpriteComponent(temp);
		bg->SetScreenSize(Vector2(1760.0f, 990.0f));
		std::vector<SDL_Texture*> bgtexs = {
			GetGame()->GetTexture("Assets/Back001.png"),
			GetGame()->GetTexture("Assets/Back002.png")
		};
		bg->SetBGTextures(bgtexs);
		bg->SetScrollSpeed(-100.0f);

		GetGame()->SetFlag(1);
		SetState(EDead);
	}
}