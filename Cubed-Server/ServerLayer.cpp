#include "Source/ServerLayer.h"

#include <chrono>

#include "Walnut/Core/Log.h"
#include "Walnut/Serialization/BufferStream.h"

#include ""

namespace Cubed {

	static Walnut::Buffer s_ScratchBuffer;

	void ServerLayer::OnAttach()
	{
		s_ScratchBuffer.Allocate(10 * 1024 * 1024); // 10MB

		m_Console.SetMessageSendCallback([this](std::string_view message) { OnConsoleMessage(message);});

		m_Server.SetClientConnectedCallback([this](const Walnut::ClientInfo& clientInfo) {OnClientConnected(clientInfo); });
		m_Server.SetClientDisconnectedCallback([this](const Walnut::ClientInfo& clientInfo) {OnClientDisconnected(clientInfo); });
		m_Server.SetDataReceivedCallback([this](const Walnut::ClientInfo& clientInfo, const Walnut::Buffer buffer) {OnDataReceived(clientInfo, buffer); });

		m_Server.Start();

	}

	void ServerLayer::OnDetach()
	{
		m_Server.Stop();
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

	void ServerLayer::OnClientConnected(const Walnut::ClientInfo& clientInfo)
	{
		WL_INFO_TAG("Server", "Client Connected! ID = {}", clientInfo.ID);


		Walnut::BufferStreamWriter stream(s_ScratchBuffer);

		// packet type - connected
		// id


		stream.WriteRaw(PacketType::ClientConnect);

		m_Server.SendBufferToClient(clientInfo.ID, stream.GetBuffer());
	}

	void ServerLayer::OnClientDisconnected(const Walnut::ClientInfo& clientInfo)
	{
		WL_INFO_TAG("Server", "Client Disconnected! ID = {}", clientInfo.ID);
	}

	void ServerLayer::OnDataReceived(const Walnut::ClientInfo& clientInfo, const Walnut::Buffer buffer)
	{
		//WL_INFO_TAG("Server", )
	}

}