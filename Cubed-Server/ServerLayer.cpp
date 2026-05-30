#include "ServerLayer.h"

#include <chrono>

namespace Cubed {

	void ServerLayer::OnAttach()
	{
		m_Console.SetMessageSendCallback([this](std::string_view message) { OnConsoleMessage(message);});

	}

	void ServerLayer::OnDetach()
	{

	}

	void ServerLayer::OnUpdate(float ts)
	{
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(5ms); // Slow down timestep.
	}

	void ServerLayer::OnUIRender()
	{

	}

	void ServerLayer::OnConsoleMessage(std::string_view message)
	{
		if (message.starts_with('/'))
		{
			// command
			std::cout << "You called the " << message << " command!\n";
		}
	}
}