/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include "Framework.h"
#include "GameTimer.h"

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GameFramework.Render();
	glutSwapBuffers();
}

void Idle(void)
{
	if (Timer.GetTick())
	{
		GameFramework.Update(Timer.GetTimeElapsed());
		RenderScene();
	}
	else return;

	glutSetWindowTitle(GameFramework.GetTitleStr());
}

// Ű���� ����
void KeyInput(unsigned char key, int x, int y)
{
	GameFramework.Input_Key(key, x, y);
	//std::cout << "KeyInput Key: " << key << " X: " << x << " Y: " << y << std::endl;
}

// ����Ű, ����Ʈ, ��Ʈ��
void SpecialKeyInput(int key, int x, int y)
{
	GameFramework.Input_SpecialKey(key, x, y);
	//std::cout << "Special Key Input Key: " << key << " X: " << x << " Y: " << y << std::endl;
}

// ���콺 Ŭ�� �� Ŭ���� ��ǥ
void MouseInput(int button, int state, int x, int y)
{
	GameFramework.Input_MouseButton(button, state, x, y);
	//std::cout << "Mouse Input Button: " << button
	//	<< " state: " << state << " X: " << x << " Y: " << y << std::endl;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);//optional
	glutInitWindowSize(CLIENT_WIDTH, CLIENT_HEIGHT); //optional
	glutCreateWindow(CLIENT_TITLE);
	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutSpecialFunc(SpecialKeyInput);
	glutMouseFunc(MouseInput);

	GameFramework.Init(CLIENT_WIDTH, CLIENT_HEIGHT);

	glutMainLoop();

    return 0;
}

