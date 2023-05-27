#pragma once

#include "pe/DbgGui/IComponent.h"

namespace pe {
namespace gui {

    class HeapViewer : public IComponent {
    public:
        virtual void update();
        virtual void draw();
    };

} // namespace gui
} // namespace pe
