#pragma once

#include "coreinclude.h"
#include <boost/signals2/signal.hpp>

namespace EE {
	class Event
	{
	public:
		Event();
		~Event();

		// Fired when system adds dependency
		// Implimentation: cycle through entity's and add ptr to their component to return vector if
		// the component matches the cType
		std::vector<idCompPtrPair> fireSystemAddDependency(const cType& dependency);
		
		// Fired when an entity removes a component
		
		//idCompPtrPair fireSystemAddDependency(Component* const, const cType&);

	private:

		//boost::signals2::signal<void(EE::System* const, const eId&)> entityRemoveSignal;

		//boost::signals2::signal<void(EE::System* const, const eId&)> entityRemoveSignal;

	
		// Entity fires this when a new component is added
		// System must connect
		boost::signals2::signal<void(System* const, const eId&, const cType&, Component* const)> entityAddComponentEvent;
		// Entity fires this when a component is removed
		// System must connect
		boost::signals2::signal<void(System* const, const eId&, const cType&)> entityRemoveComponentEvent;

		// aggregate_values is a combiner which places all the values returned
		// from slots into a container
		template<typename Container>
		struct aggregate_values
		{
			typedef Container result_type;

			template<typename InputIterator>
			Container operator()(InputIterator first, InputIterator last) const
			{
				Container values;

				while (first != last) {
					values.push_back(*first);
					++first;
				}
				return values;
			}
		};

		// Returns a vector of pairs of id:component for new component dependency
		// System class fires event
		// Entity method must connect
		boost::signals2::signal< idCompPtrPair(Entity* const, const cType&),
			aggregate_values<std::vector<idCompPtrPair>> > systemAddDependencyEvent;

		friend class Engine;

	};
}

