#pragma once

#include "coreinclude.h"
#include <boost/signals2/signal.hpp>

namespace EE {
	class EntityEventFire
	{
	public:
		//void fireEntityAdd(const eId& id, Entity const* const address);

		// Fire when entity is removed to update system 
		void fireEntityRemove(EE::System* const currSys, const eId& id);

	private:
		//boost::signals2::signal<void(const eId&, Entity const* const)> entityAddSignal;
		boost::signals2::signal<void(EE::System* const, const eId&)> entityRemoveSignal;
		

		friend class Engine;
	};
}
