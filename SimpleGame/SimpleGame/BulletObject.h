#pragma once
#include "GameObject.h"

#define DEFAULT_BULLET_MAX_LIFE		20.0f
#define DEFAULT_BULLET_SPEED		300.0f
#define DEFAULT_BULLET_SIZE			2.0f

#define BULLET_TEAM_1_COLOR			Vec4f(1, 0, 0, 1)
#define BULLET_TEAM_2_COLOR			Vec4f(0, 0, 1, 1)

class BulletObject : public GameObject
{
private:
	GameObject*					m_pLaunchedBy;

public:
	BulletObject(ObjectTeam team, ObjectType tag = ObjectType::OBJECT_BULLET);
	BulletObject(
		const Vec3f& pos
		, float size
		, const Vec4f& color
		, ObjectTeam team
		, ObjectType tag);
	BulletObject(
		float x, float y, float z, float size
		, float r, float g, float b, float a
		, ObjectTeam team
		, ObjectType tag);
	virtual ~BulletObject();

	virtual void Update(const double TimeElapsed);
	virtual void Render(Renderer * pRenderer);

	virtual void CollideWith(GameObject* other);

	void SetLaunchedBy(GameObject* other);
	GameObject* GetLaunchedBy() const { return m_pLaunchedBy; }
};
