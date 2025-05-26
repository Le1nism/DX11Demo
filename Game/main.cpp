#include <DX3D/All.h>

int main() {

	try {

		// The game instance
		dx3d::Game game{};
		game.run();
	}

	catch (const std::runtime_error&) {

		return EXIT_FAILURE;
	}

	catch (const std::exception&) {

		return EXIT_FAILURE;
	}

	// Catch-all-handler block
	catch (...) {

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}