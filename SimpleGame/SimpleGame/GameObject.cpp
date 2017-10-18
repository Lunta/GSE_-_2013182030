#include "stdafx.h"
#include "GameObject.h"
#include "Renderer.h"


GameObject::GameObject() :
	m_vec3fPos({ 0, 0, 0 }),
	m_vec4fColor({ 0, 0, 0, 1 }),
	m_fSize(0.0f),
	m_vec3fDirection(0, 0, 0),
	m_fSpeed(0.0f),
	m_BindingBox(),
	m_bIsCollision(false)
{
}
GameObject::GameObject(const Vec3f& pos, float size, const Vec4f& color) :
	m_vec3fPos(pos),
	m_vec4fColor(color),
	m_fSize(size),
	m_vec3fDirection(0, 0, 0),
	m_fSpeed(0.0f),
	m_BindingBox(pos, size),
	m_bIsCollision(false)
{
}
GameObject::GameObject(float x, float y, float z, float size, float r, float g, float b, float a) :
	m_vec3fPos({ x, y, z }),
	m_vec4fColor({ r, g, b, a }),
	m_fSize(size),
	m_vec3fDirection(0, 0, 0),
	m_fSpeed(0.0f),
	m_BindingBox(x, y, size),
	m_bIsCollision(false)
{	
}
GameObject::~GameObject()
{
}

void GameObject::Collide()
{
	m_bIsCollision = true;
}

void GameObject::SetParameter(const Vec3f& pos, float size, const Vec4f& color)
{
	m_vec3fPos = pos;
	m_vec4fColor = color;
	m_fSize = size;
	m_BindingBox.SetPos(m_vec3fPos);
	m_BindingBox.SetSize(m_fSize);
}

void GameObject::SetParameter(float x, float y, float z, float size, float r, float g, float b, float a)
{
	m_vec3fPos = { x, y, z };
	m_vec4fColor = { r, g, b, a };
	m_fSize = size;
	m_BindingBox.SetPos(m_vec3fPos);
	m_BindingBox.SetSize(m_fSize);
}

void GameObject::SetPos(const Vec3f & pos)
{
	m_vec3fPos = pos;
	m_BindingBox.SetPos(pos);
}

void GameObject::SetPos(float x, float y, float z)
{
	m_vec3fPos = { x, y, z };
	m_BindingBox.SetPos(x, y);
}

void GameObject::SetColor(const Vec4f & color)
{
	m_vec4fColor = color;
}

void GameObject::SetColor(float r, float g, float b, float a)
{
	m_vec4fColor = { r, g, b, a };
}

void GameObject::SetSize(float size)
{
	m_fSize = size;
	m_BindingBox.SetSize(size);
}

void GameObject::SetDirection(const Vec3f & direction)
{
	m_vec3fDirection = direction;
}

void GameObject::SetDirection(float x, float y, float z)
{
	m_vec3fDirection = { x, y, z };
}

void GameObject::SetSpeed(float speed)
{
	m_fSpeed = speed;
}
