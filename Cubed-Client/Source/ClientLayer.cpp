#include "ClientLayer.h"

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

	}

	void ClientLayer::OnUIRender()
	{
		ImGui::ShowDemoWindow();

	}

}