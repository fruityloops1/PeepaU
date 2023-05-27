#include "imgui/imgui.h"
#include "pe/DbgGui/Windows/ImGuiDemo.h"

namespace pe {
namespace gui {

    void ImGuiDemo::update()
    {
    }

    void ImGuiDemo::draw()
    {
        if (getDbgGuiSharedData().showDemoWindow)
            ImGui::ShowDemoWindow(&getDbgGuiSharedData().showDemoWindow);
    }

} // namespace gui
} // namespace pe
