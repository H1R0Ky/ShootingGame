#pragma once
#include"Actor.h"

class Bullet : public Actor {
public:
	Bullet(Game* game);
	~Bullet();
	void UpdateActor(float deltatime) override;
	class Player* GetParentPlayer() { return mPlayer; }
	void SetPlayer(class Player* player) { mPlayer = player; }
	class Enemy* GetParentEnemy() { return mEnemy; }
	void SetEnemy(class Enemy* enemy) { mEnemy = enemy; }

	void SetNumber(int num) { enemyNumber = num; }

	class CircleComponent* GetCircle() { return mCircle; }

private:
	int enemyNumber;
	float VerticalSpeed;
	float HorizontalSpeed;
	class Player* mPlayer;
	class Enemy* mEnemy;
	class CircleComponent* mCircle;
};
