#pragma once
#include <DX3D/Core/Base.h>

namespace dx3d {

	// Final here is necessary to prevent the GraphicsEngine to be
	// further derived from other classes
	class GraphicsEngine final : public Base {

	public:

		GraphicsEngine();
		virtual ~GraphicsEngine() override;
	};
}