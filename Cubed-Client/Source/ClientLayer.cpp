#include "ClientLayer.h"
#include "Walnut/Input/Input.h"

#include "imgui.h"
#include "imgui_internal.h"

namespace Cubed {

	static void DrawRect(float x, float y, float width, float height, uint32_t color)
	{
		ImDrawList* drawList = ImGui::GetForegroundDrawList();

		ImVec2 min = ImGui::GetWindowPos() + ImVec2(x, y);
		ImVec2 max = min + ImVec2(width, height);

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

		if (Walnut::Input::IsKeyDown(KeyCode::W))
			dir.y = -1;
		else if (Walnut::Input::IsKeyDown(KeyCode::S))
			dir.y = 1;

		if (Walnut::Input::IsKeyDown(KeyCode::A))
			dir.y = -1;
		else if (Walnut::Input::IsKeyDown(KeyCode::D))
			dir.y = 1;

	   
	}

	void ClientLayer::OnUIRender()
	{
		ImGui::ShowDemoWindow();

	}

}