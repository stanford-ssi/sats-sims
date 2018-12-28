#pragma once

#include "System.h"
//#include "TestComponent.h"

namespace EE {
	class TestSystem
		: public EE::System
	{
	public:
		TestSystem();
		static System* create() { return new TestSystem(); }

	private:
		virtual void update(timeUnit dt);

	};
}

