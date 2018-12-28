#pragma once
#include "coreinclude.h"

namespace EE 
{
	class SystemListener
	{
	public:
		void operator()(SystemListenerCommand, Entity::id_type);
	};
}

