#pragma once
#include <DX3D/Core/Base.h>

namespace dx3d {

	class Window : public Base {

	public:

		Window();
		virtual ~Window() override;

	private:

		// We don't want to expose platform specific definitions (Win32Api) in the public header file of the engine
		void* m_handle{};
	};
}

