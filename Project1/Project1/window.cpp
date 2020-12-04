#include "window.h"

window::window(string a, int width, int height) :
	numberOfScreenWidth(width),numberOfScreenheight(height){
	closed = !init();
}

window::window(){
}

bool window::init(){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		return false;
	}
	else {
		gWindow = SDL_CreateWindow(
			"SnakeGame",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			numberOfScreenWidth,
			numberOfScreenheight,
			0
		);
	}
	if (gWindow == NULL) {
		return false;
	}
	_renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == NULL) {
		cout << "jhaha";
		return false;
	}
	return true;
}
void window::pollEvent() {
	SDL_Event _event;
	if (SDL_PollEvent(&_event)) {
		switch (_event.type){
		case SDL_QUIT:
			closed = true; break;
		default:
			break;
		}
	}
	
}
void window::clear() const {
	SDL_SetRenderDrawColor(_renderer, 0, 0, 200, 255);
	SDL_RenderClear(_renderer);
	SDL_Rect _rect;
	_rect.h = 50;
	_rect.w = 50;
	_rect.x = 150;
	_rect.y = 160;
	SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 255);
	SDL_RenderFillRect(_renderer, &_rect);
	SDL_RenderPresent(_renderer);
}