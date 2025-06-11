#pragma once

#include <DX3D/Core/Core.h>
#include <DX3D/Core/Base.h>
#include <d3d11.h>
#include <wrl.h>

namespace dx3d {

	class RenderSystem : public Base {

	public:

		RenderSystem();
		virtual ~RenderSystem() override;

	private:

		// Just like we did with the Window instance, we should use
		// smart pointers. Unlike the Window class, however, we can
		// choose a standard C++ smart pointer, like unique pointer

		// The 3D resources, like 3D devices are COM objects, which
		// use reference counting for memory management

		// Reference counting is a technique where each object keeps
		// track of how many references or owners point to it
		// When a new reference is created the count goes up
		// When a reference is released the count goes down
		// When the count reaches zero, the object is automatically destroyed
		// For these types of object we need to use COM pointer, a smart pointer
		// provided by the Windows Runtime C++ Template Library, which we can access
		// from the wrl.h header file

		Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice{};
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_d3dContext{};
	};

}