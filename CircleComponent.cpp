#include"CircleComponent.h"
#include"Actor.h"

CircleComponent::CircleComponent(class Actor* owner) : 
	Component(owner),
	mRadius(0.0f)
{

}

float CircleComponent::GetRadius() const {
	return mOwner->GetScale() * mRadius;
}

const Vector2& CircleComponent::GetCenter() const {
	return mOwner->GetPosition();
}

bool Intersect(const CircleComponent& a, const CircleComponent& b) {
	Vector2 diff = a.GetCenter() - b.GetCenter();
	float diffSq = diff.LengthSq();

	float radiiSq = a.GetRadius() + b.GetRadius();
	radiiSq *= radiiSq;

	return (diffSq <= radiiSq);
}