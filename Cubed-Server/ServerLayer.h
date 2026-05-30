#pragma once

#include "Walnut/Layer.h"

namespace Cubed {

	class ServerLayer : public Walnut::Layer
	{
	public:
		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnUpdate(float ts) override;
		virtual void OnUIRender() override;
	};
}