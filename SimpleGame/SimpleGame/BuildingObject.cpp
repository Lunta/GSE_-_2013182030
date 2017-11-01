#include "stdafx.h"
#include "BuildingObject.h"
#include "Renderer.h"
#include "BoxObject.h"

BuildingObject::BuildingObject(ObjectType tag)
	: GameObject(tag)
{
	m_fLife = DEFAULT_BUILDING_MAX_LIFE;
}
BuildingObject::BuildingObject(const Vec3f& pos, float size, const Vec4f& color, ObjectType tag)
	: GameObject(pos, size, color, tag)
{
	m_fLife = DEFAULT_BUILDING_MAX_LIFE;
}
BuildingObject::BuildingObject(float x, float y, float z, float size, float r, float g, float b, float a, ObjectType tag)
	: GameObject(x, y, z, size, r, g, b, a, tag)
{
	m_fLife = DEFAULT_BUILDING_MAX_LIFE;
}
BuildingObject::~BuildingObject()
{
}

void BuildingObject::Update(const double TimeElapsed)
{
	if (!m_bActive) return;
	m_vec3fPos += m_vec3fDirection * m_fSpeed * TimeElapsed;
	m_fShootTimer += TimeElapsed;
	m_fLifeTimer -= TimeElapsed;

	m_BindingBox.SetPos(m_vec3fPos);
	if (m_bIsCollision)
	{
		m_fCollisionTimer += TimeElapsed;
		if (m_fCollisionTimer > COLLISION_TIME)
		{
			m_bIsCollision = false;
			m_fCollisionTimer = 0.0f;
			m_pTarget = nullptr;
			m_vec4fColor += Vec4f{ 0.1f, 0.1f, 0.1f, 0.0f };
		}
	}

	if (m_vec3fPos.x > CLIENT_WIDTH / 2 ||
		m_vec3fPos.x < -CLIENT_WIDTH / 2)
		m_vec3fDirection.x = -m_vec3fDirection.x;
	if (m_vec3fPos.y > CLIENT_HEIGHT / 2 ||
		m_vec3fPos.y < -CLIENT_HEIGHT / 2)
		m_vec3fDirection.y = -m_vec3fDirection.y;
}

void BuildingObject::Render(Renderer * pRenderer)
{
	if (!m_bActive) return;
	pRenderer->DrawSolidRect(
		m_vec3fPos.x, m_vec3fPos.y, m_vec3fPos.z, m_fSize,
		m_vec4fColor.r, m_vec4fColor.g, m_vec4fColor.b, m_vec4fColor.a);
}

void BuildingObject::CollideWith(GameObject * other)
{
	if (!m_bActive) return;
	if (other->GetTag() == GameObject::ObjectType::OBJECT_CHARACTER)
	{
		if (m_bIsCollision) return;
		m_bIsCollision = true;
		m_fCollisionTimer = 0.0f;
		m_pTarget = other;
		m_fLife -= other->GetLife();
		m_vec4fColor -= Vec4f{ 0.1f, 0.1f, 0.1f, 0.0f };
		if (m_fLife <= 0.0f)
		{
			m_fLife = 0.0f;
			m_bActive = false;
		}
	}
}

GameObject* BuildingObject::ShootBullet()
{
	if (m_fShootTimer <= DEFAULT_SHOOT_DELAY) return nullptr;
	m_fShootTimer = 0.f;
	GameObject* bullet = new BoxObject(
		m_vec3fPos
		, 10.f
		, Vec4f{ 0, 0, 0, 1 }
		, GameObject::ObjectType::OBJECT_BULLET);
	bullet->SetDirection(
		(1 - 2 * (rand() % 2))*(rand() % 100 / 100.0),
		(1 - 2 * (rand() % 2))*(rand() % 100 / 100.0));
	bullet->SetSpeed(300);
	bullet->SetLife(20);
	return bullet;
}