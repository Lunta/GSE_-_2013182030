#include "stdafx.h"
#include "GameTimer.h"

GameTimer::GameTimer()
{
}
GameTimer::~GameTimer()
{
}

void GameTimer::Init()
{
	m_tpCurrentTime = std::chrono::system_clock::now();
	m_dFps = 0.0;
}

bool GameTimer::GetTick()
{
	// Get tick
	m_dTimeElapsed = std::chrono::system_clock::now() - m_tpCurrentTime;
	if (m_dTimeElapsed.count() > MAX_FPS)
	{
		m_tpCurrentTime = std::chrono::system_clock::now();
		m_dFps = 1.0 / m_dTimeElapsed.count();
		return true;
	}
	// �ִ� FPS �̸��� �ð��� ����ϸ� ���� ����
	else return false;
}

GameTimer& GameTimer::GetInstance()
{
	static GameTimer instance;
	return instance;
}
