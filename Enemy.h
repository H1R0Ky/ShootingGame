#pragma once
#include"Actor.h"
#include"Math.h"
#include<vector>

class Enemy : public Actor {
public:
	Enemy(Game* game);
	~Enemy();
	void UpdateActor(float deltatime) override;
	void EnemyAI(float deltatime);

	int GetNumber() { return enemyNumber; }
	void SetNumber(int num) { enemyNumber = num; }

	void SetCooldown(int num) { cooldownNumber = num; }

	void GenerateBullet(int num_of_culc);

	void SetBulletStatus(class Bullet* bullet, int number);

	class EnemyPrefab* GetEnemyPrefab() { return ePrefab; }
	void SetEnemyPrefab(class EnemyPrefab* prefab) { ePrefab = prefab; }

	class CircleComponent* GetCircle() { return mCircle; }
	void SetCircle(class CircleComponent* cc) { mCircle = cc; }

private:
	int enemyNumber;
	int cooldownNumber;
	float VerticalSpeed;
	float HorizontalSpeed;
	float time;
	float Cooldown;
	class CircleComponent* mCircle;
	class EnemyPrefab* ePrefab;
};