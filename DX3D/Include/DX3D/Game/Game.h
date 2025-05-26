#pragma once
#include <DX3D/Core/Base.h>
#include <DX3D/Core/Core.h>

namespace dx3d {

	class Game : public Base {

	public:

		Game();
		virtual ~Game() override;

		// Main game loop, cannot be further overridden or inherited
		// to prevent unintended extensions or overrides in the right classes
		virtual void run() final;

	private:

		// Holds a pointer to a Window instance
		// When the destructor is called, it automatically deletes
		// the instance, avoiding memory leaks
		std::unique_ptr<Window> m_display{};

		// Flag to break outside the infinite loop
		bool m_isRunning{ true };
	};
}
