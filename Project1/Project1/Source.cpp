#include "window.h"

int main(int argc, char* argv[]) {
	window a("snake",800,600);
	while (!a.isClosed()){
		a.pollEvent();
		a.clear();
	}
	
	return 0;
}