#include "ClientLayer.h"
#include "Walnut/Input/Input.h"

#include "imgui.h"
#include "imgui_internal.h"

namespace Cubed {

	static void DrawRect(glm::vec2 position, glm::vec2 size, uint32_t color)
	{
		ImDrawList* drawList = ImGui::GetForegroundDrawList();

		ImVec2 min = ImGui::GetWindowPos() + ImVec2(position.x, position.y);
		ImVec2 max = min + ImVec2(size.x, size.y);

		drawList->AddRectFilled(min, max, color);

	}


	void ClientLayer::OnAttach()
	{

	}

	void ClientLayer::OnDetach()
	{

	}

	void ClientLayer::OnUpdate(float ts)
	{
		glm::vec2 dir{ 0.0f, 0.0f };

		if (Walnut::Input::IsKeyDown(Walnut::KeyCode::W))
			dir.y = -1;
		else if (Walnut::Input::IsKeyDown(Walnut::KeyCode::S))
			dir.y = 1;

		if (Walnut::Input::IsKeyDown(Walnut::KeyCode::A))
			dir.x = -1;
		else if (Walnut::Input::IsKeyDown(Walnut::KeyCode::D))
			dir.x = 1;

	
		if (glm::length(dir) > 0.0f)
		{   
			const float speed = 50.0f;
			// Optional
			dir = glm::normalize(dir);
			m_PlayerVelocity = dir * speed;
		}

		m_PlayerPosition += m_PlayerVelocity * ts;

		m_PlayerVelocity = glm::mix(m_PlayerVelocity, glm::vec2(0.0f), 12.0f * ts);
		m_PlayerVelocity = { 0, 0 };

	}

	void ClientLayer::OnUIRender()
	{
		if (m_Client.GetConnectionStatus() == Walnut::Client::ConnectionStatus::Connected)
		{
			// play game
			DrawRect(m_PlayerPosition, { 50.0f, 50.0f }, 0xffff00ff);
			
		}

		ImGui::ShowDemoWindow();

		DrawRect(m_PlayerPosition, { 50.0f, 50.0f }, 0xffff00ff);

	}

}