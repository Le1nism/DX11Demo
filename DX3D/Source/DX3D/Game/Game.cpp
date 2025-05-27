#include <DX3D/Game/Game.h>
#include <DX3D/Window/Window.h>

dx3d::Game::Game() {

	// There is no need to call delete in the destructor
	m_display = std::make_unique<Window>();

	// Window win{};

	// Shallow copy of the window object, only the top-level structure
	// is duplicated but not the dynamically allocated memory, handles and so on

	// Both the original and the copy share the same underlying resources
	// Here we copy the Win32 window handle from the win object into the w object

	// We end up with two window objects that share the same underlying window
	// This is something that should be avoided in all components of the engine

	// To solve this issue we can apply the "rule of 5" (see base class)
	// It consists in implementing 5 specific methods in a class:
	//		- Destructor
	//		- Copy constructor
	//		- Move constructor
	//		- Copy assignment operator
	//		- Move assignment operator

	// If our class manages resources manually (Win32 handle in the Window class)
	// and we need to implement at least one of these methods, we need to implement all 5
	
	// This won't work as we're trying to copy a window object, which is forbidden
	//auto w = win;
}

dx3d::Game::~Game() {

}