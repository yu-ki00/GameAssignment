#pragma once

#define KEY_UP		(0b1)
#define KEY_DOWN	(0b10)
#define KEY_RIGHT	(0b100)
#define KEY_LEFT	(0b1000)
#define KEY_SHOT	(0b10000)
#define MOUSE_RIGHT	(0b100000)
#define KEY_SELECT	(0b1000000)
#define KEY_JUMP	(0b10000000)
#define KEY_E		(0b100000000)
#define KEY_Q		(0b1000000000)
#define KEY_SHIFT	(0b10000000000)
class CInput {
public:
	static void Init();
	static void Update();
	static bool IsRep(unsigned int key);
	static bool IsTrg(unsigned int key);
	static bool IsRelease(unsigned int key);
};


