#include <DX3D/Graphics/RenderSystem.h>

dx3d::RenderSystem::RenderSystem() {

	// We can combine multiple flags using the bitwise OR operator
	// In this case we only want to add the flag that enables the
	// D3D debug layer, which helps us get error and warning messages during runtime
	UINT createDeviceFlags{};

	// Where the feature level chosen internally by the function will be stored
	D3D_FEATURE_LEVEL featureLevel{};

#ifdef _DEBUG

	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;

#endif

	// This fucntion allows us to create the D3D11 device for which we
	// will be able to create all the graphics resources we need to render
	// our window

	// DXGI Adapter represents a GPU installed on the system, it can also represent
	// other adapters, passing NULL as the first parameter and as the second, D3D will
	// take the primary GPU.

	// The next parameter expects a handle to a DLL that implements a custom software
	// rasterizer. Since we are not using one, we can just pass null

	// Then we can pass some flag values defined above

	// The function requires a pointer to an array of feature level. By passing NULL D3D
	// will simply pick the best feature level supported by the system.
	// For now this behavior is good enough

	// The next parameter is the size of the previous array, since we passed NULL we can
	// safely pass 0

	// Now that we handled those we need to pass the SDK version parameter
	// This is a safety check used by Microsoft to prevent version mismatch and ensures our program
	// links with the correct D3D runtime

	// The first output parameter is the most important, the D3D device, it represents the virtual GPU
	// and is used to create and manage all GPU related resources, like textures, shaders, buffers...

	// To pass the COM pointer we use the & operator, this gives us a double pointer, which is what
	// the function expects

	// The next output parameter is the feature level chosen internally by the function

	// Last we need to retrieve the device context
	auto hr = D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0, D3D11_SDK_VERSION,
		&m_d3dDevice, &featureLevel, &m_d3dContext);

	// At this point we need to check the return function so we can throw an exception
	// if something goes wrong

	// In this case we can use an handy macro called FAILED
	if (FAILED(hr)) {

		throw std::runtime_error("Direct3D11 initialization failed");
	}

}

dx3d::RenderSystem::~RenderSystem() {

}
