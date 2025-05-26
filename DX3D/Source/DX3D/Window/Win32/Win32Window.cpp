#include <DX3D/Window/Window.h>
#include <Windows.h>
#include <stdexcept>

static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {

	// Handle the message parameter
	switch (msg) {

		// When the close button of the window is pressed
	case WM_CLOSE: {

		// Adds a WM_QUIT message to the message queue, signaling that
		// there is a request to terminate the application
		PostQuitMessage(0);

		break;
	}

	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return 0;
}

// RAII: Resource Acquisition In Initialization
// The initialization code of the window is inside the constructor, and
// the release code of the window is in the destructor
// This idiom will be useful for smart pointers, as resources are acquired during
// object initialization, and released in object destruction
dx3d::Window::Window() : Base() {

	// Lambda function, a function without a name, that can be defined
	// inline within the body of a function (small throwaway functions for short time use)
	auto registerWindowClassFunction = []() {

		// Brace initialization sets the deafult parameters
		WNDCLASSEX wc{};
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.lpszClassName = L"DX3DWindow";
		wc.lpfnWndProc = &WindowProcedure;

		return RegisterClassEx(&wc);
		};

	// If another window is created and RegisterClassEx is called two or more times from
	// the same class, the function would fail, and return 0.
	// To avoid this issue, this variable is static const so that registerWindowClassFunction,
	// on subsequent calls, will not be executed again, and the same class ID will be reused
	static const auto windowClassId = std::invoke(registerWindowClassFunction);

	// Checks whether the return values are valid
	// If the ID is 0, something has gone wrong, an exception has to be thrown
	if (!windowClassId)
		throw std::runtime_error("RegisterClassEx failed");

	RECT rc{ 0, 0, 1280, 720 };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);
	
	m_handle = CreateWindowEx(NULL, MAKEINTATOM(windowClassId), L"DX11 Demo",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top,
		NULL, NULL, NULL, NULL);

	if (!m_handle)
		throw std::runtime_error("CreateWindowEx failed");
	
	// Since it is being used a void pointer, it needs to be casted to the HWND type
	ShowWindow(static_cast<HWND>(m_handle), SW_SHOW);
}

dx3d::Window::~Window() {

	// Destroy the window instance
	DestroyWindow(static_cast<HWND>(m_handle));
}

