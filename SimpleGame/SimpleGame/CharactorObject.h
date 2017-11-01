#pragma once
#include "GameObject.h"

#define DEFAULT_CHARACTOR_MAX_LIFE	5.0f

class CharactorObject : public GameObject
{
private:

public:
	CharactorObject(ObjectType tag = ObjectType::OBJECT_CHARACTER);
	CharactorObject(const Vec3f& pos, float size, const Vec4f& color, ObjectType tag = ObjectType::OBJECT_CHARACTER);
	CharactorObject(float x, float y, float z, float size, float r, float g, float b, float a, ObjectType tag = ObjectType::OBJECT_CHARACTER);
	virtual ~CharactorObject();

	virtual void Update(const double TimeElapsed);
	virtual void Render(Renderer * pRenderer);

	virtual void CollideWith(GameObject* other);
};