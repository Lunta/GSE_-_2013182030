#include "stdafx.h"
#include "TitleScene.h"
#include "Framework.h"
#include "ArrowObject.h"

TitleScene::TitleScene(const Type& tag) : Scene(tag)
{
}
TitleScene::~TitleScene()
{
}

void TitleScene::BuildObjects()
{
	Scene::BuildObjects();
	m_pTestObject = new ArrowObject(
		Vec3f()
		, DEFAULT_ARROW_SIZE
		, ARROW_TEAM_1_COLOR
		, GameObject::ObjectTeam::OBJECT_TEAM_1
		, GameObject::ObjectType::OBJECT_ARROW);
}

void TitleScene::ReleaseObjects()
{
	delete m_pTestObject;
}

void TitleScene::Update(const double TimeElapsed)
{
	m_pTestObject->Update(TimeElapsed);
}

void TitleScene::PrepareUpdate(const double TimeElapsed)
{
}

void TitleScene::PhysicsProcess(const double TimeElapsed)
{
}

void TitleScene::Render()
{
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	m_pTestObject->Render(m_pRenderer);
}

void TitleScene::Input_Key(unsigned char key, int x, int y)
{
	switch (key)
	{
	case KEY_TAB:
		break;
	case KEY_BACKSPACE:
		break;
	case KEY_SPACE:
		GameFramework.ChangeScene(Scene::Type::Main);
		break;
	case KEY_ENTER:
		break;
	default:
		break;
	}
}

void TitleScene::Input_SpecialKey(int key, int x, int y)
{
	switch (key)
	{
	case SPECIAL_KEY_SHIFT:
		break;
	case SPECIAL_KEY_CTRL:
		break;
	case SPECIAL_KEY_ALT:
		break;
	case SPECIAL_KEY_LEFT:
		break;
	case SPECIAL_KEY_UP:
		break;
	case SPECIAL_KEY_RIGHT:
		break;
	case SPECIAL_KEY_DOWN:
		break;
	default:
		break;
	}
}

void TitleScene::Input_MouseButton(int button, int state, int x, int y)
{
	switch (button)
	{
	case MOUSE_LEFT_BUTTON:
		break;
	case MOUSE_WHEEL_BUTTON:
		break;
	case MOUSE_RIGHT_BUTTON:
		break;
	case MOUSE_WHEEL_UP:
		break;
	case MOUSE_WHEEL_DOWN:
		break;
	default:
		break;
	}
}
