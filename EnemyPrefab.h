#pragma once
#include"Actor.h"
#include<vector>

class EnemyPrefab : public Actor 
{
public:
	EnemyPrefab(Game* game);
	void UpdateActor(float deltatime) override;

	void SetEnemyStatus(int num, Vector2 pos, float rot);

	bool GetRivalFlag() { return rivalFlag; }
	void SetRivalFlag(bool flag) { rivalFlag = flag; }

private:
	bool rivalFlag;
	int positionNumber;
	float time;
	float temp;
};