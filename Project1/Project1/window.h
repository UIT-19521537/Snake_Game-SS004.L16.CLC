#pragma once
#include <SDL.h>
#include <iostream>
#include <string.h>
using namespace std;

class window{
public:
	window(string a, int width, int height);
	window();
	~window() {};
	inline bool isClosed() { return closed; };
	void pollEvent();
	void clear() const;
private:
	bool init();
private:
	const int numberOfScreenWidth = 480;
	const int numberOfScreenheight = 600;
	SDL_Window* gWindow = NULL;
	bool closed = false;
	SDL_Renderer* _renderer = NULL;
};


