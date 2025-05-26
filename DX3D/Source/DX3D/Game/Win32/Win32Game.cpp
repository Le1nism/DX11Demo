#include <DX3D/Game/Game.h>
#include <Windows.h>
#include <iostream>

void dx3d::Game::run() {

	MSG msg{};

	// To exit the infinite loop the flag must be set to false
	while (m_isRunning) {

		// Each time PeekMessage is called it checks a special message queue.
		// The parameter PM_REMOVE removes the message just polled from it.
		// If there is at least a message in the queue, the function returns true

		// Therefore by placing the PeekMessage function as the condition of a while loop
		// it will process all the messages inside the queue.
		// Once the queue will be emptied, the loop will be terminated
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {

			// Handle the quit message added to the queue
			if (msg.message == WM_QUIT) {

				m_isRunning = false;

				break;
			}

			// At each iteration of the loop we need to process the message just retrieved
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// Suspend the execution of the program for a specified time, to prevent unnecessary CPU usage
		Sleep(1);
	}
}