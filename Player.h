#pragma once
#include"Actor.h"

class Player : public Actor {
public:
	Player(class Game* game);
	void UpdateActor(float deltatime) override;
	void ProcessInput(const uint8_t* state);

	class CircleComponent* GetCircle() { return mCircle; }

private:
	float VerticalSpeed;
	float HorizontalSpeed;
	float Cooldown;
	class CircleComponent* mCircle;
};