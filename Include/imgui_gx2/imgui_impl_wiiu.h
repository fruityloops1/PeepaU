#pragma once
#include "imgui/imgui.h" // IMGUI_IMPL_API

#include "dynlibs/padscore/functions.h"
#include "dynlibs/vpad/functions.h"
// Controller Input

struct ImGui_ImplWiiU_ControllerInput {
    VPADStatus* vpad;
    KPADStatus* kpad[4];

    ImGui_ImplWiiU_ControllerInput() { memset(this, 0, sizeof(*this)); }
};

enum ImGui_ImplWiiU_KeyboardOverlayType {
    //! Draw for the DRC
    ImGui_KeyboardOverlay_DRC,
    //! Draw for the TV
    ImGui_KeyboardOverlay_TV,
    //! Draw for the controller which requested the keyboard
    ImGui_KeyboardOverlay_Auto
};

IMGUI_IMPL_API bool ImGui_ImplWiiU_Init();
IMGUI_IMPL_API void ImGui_ImplWiiU_Shutdown();
IMGUI_IMPL_API bool ImGui_ImplWiiU_ProcessInput(ImGui_ImplWiiU_ControllerInput* input);
IMGUI_IMPL_API void ImGui_ImplWiiU_DrawKeyboardOverlay(ImGui_ImplWiiU_KeyboardOverlayType type = ImGui_KeyboardOverlay_Auto);