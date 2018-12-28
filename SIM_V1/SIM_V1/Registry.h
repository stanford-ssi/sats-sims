#pragma once
#include "coreinclude.h"

// Include all Components and Systems:
#include "TestComponent.h"
#include "TestSystem.h"

namespace Register {
	
	std::unordered_map<EE::sType, EE::System* (*)()> sRegistry = { {"TestSystem", &EE::TestSystem::create},
		/* More Systems */
	};

	//std::unordered_map<cType, Component* (*)()> cRegistry = { {"TestComponent", &TestComponent::create},
	//	/* More Components */
	//};
}

