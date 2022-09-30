#pragma once
#include"Actor.h"

class Title : public Actor {
public:
	Title(class Game* game);

	void UpdateActor(float deltatime) override;
	void ProcessInput(const uint8_t* state);

private:
	float time;
};