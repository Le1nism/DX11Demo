#pragma once

namespace dx3d {

	class Base {

	public:

		Base();
		virtual ~Base();

	protected:

		// By adding = delete to the copy and move methods, we prevent this class
		// and all its derived classes from being copied or moved in any way

		// The resources will manage dynamically allocated memory and handles
		// so it makes sense to share this behavior in these classes
		Base(const Base&) = delete;
		Base(Base&&) = delete;
		Base& operator = (const Base&) = delete;
		Base& operator = (Base&&) = delete;
	};
}