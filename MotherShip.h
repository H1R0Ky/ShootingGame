#pragma once
#include"Actor.h"

class MotherShip :public Actor 
{
public:
	MotherShip(Game* game);

	void UpdateActor(float deltatime) override;

	class CircleComponent* GetCircle() { return mCircle; }

private:
	int MotherShipHP;
	class CircleComponent* mCircle;
};