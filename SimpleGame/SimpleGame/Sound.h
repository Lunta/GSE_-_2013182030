#pragma once

#include <map>
#include "Dependencies/IrrKlang.h"
#pragma comment(lib, "irrKlang.lib") 

using namespace irrklang;

class Sound
{
public:
	Sound();
	~Sound();

	int CreateSound(char* filePath);
	void DeleteSound(int index);
	void PlaySound(int index, bool bLoop, float volume);
	void StopAllSounds();
		

private:
	ISoundEngine* m_engine = NULL;

	std::map<int, ISoundSource*> m_soundList;
};

