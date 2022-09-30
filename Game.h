#pragma once
#include"SDL.h"
#include<unordered_map>
#include<string>
#include<vector>

class Game {
public:
	Game();
	bool Initialize();
	void RunLoop();
	void ShutDown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	SDL_Texture* GetTexture(const std::string& fileName);

	class Player* GetPlayer() { return mPlayer; }
	void SetPlayer(class Player* player) { mPlayer = player; }

	std::vector<class Enemy*> GetEnemy() { return mEnemies; }
	void SetEnemy(std::vector<class Enemy*>& enemy) { mEnemies = enemy; }

	class EnemyPrefab* GetEPrefab() { return EPrefab; }
	void SetEPrefab(class EnemyPrefab* ePrefab) { EPrefab = ePrefab; }

	std::vector<class Bullet*> GetBullet() { return mBullets; }
	void SetBullet(std::vector<class Bullet*>& bullet) { mBullets = bullet; }

	void AddEnemy(class Enemy* enemy);
	void RemoveEnemy(class Enemy* enemy);

	void AddBullet(class Bullet* bullet);
	void RemoveBullet(class Bullet* bullet);

	int GetFlag() { return mGameProcessFlag; }
	void SetFlag(int flag) { mGameProcessFlag = flag; }

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();

	// Map of textures loaded
	std::unordered_map<std::string, SDL_Texture*> mTextures;

	// All the actors in the game
	std::vector<class Actor*> mActors;
	// Any pending actors
	std::vector<class Actor*> mPendingActors;

	// All the sprite components drawn
	std::vector<class SpriteComponent*> mSprites;

	std::vector<class Title*> mTitles;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Uint32 mTicksCount;
	bool mIsRunning;
	bool mUpdatingActors;
	class Player* mPlayer;
	class EnemyPrefab* EPrefab;

	std::vector<class Enemy*> mEnemies;
	std::vector<class Bullet*> mBullets;

	int mGameProcessFlag;
};