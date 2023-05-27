#pragma once

#include <sead/container/seadPtrArray.h>
#include <sead/heap/seadDisposer.h>

struct ProductSequence;

namespace pe {
namespace gui {

    class IComponent;

    class DbgGui {
        SEAD_SINGLETON_DISPOSER(DbgGui);

        sead::PtrArray<IComponent> mComponents;

    public:
        struct SharedData {
            ProductSequence* productSequence;

            bool showDemoWindow;
            bool showHeapViewer;

            SharedData()
                : productSequence(NULL)
                , showDemoWindow(false)
                , showHeapViewer(false)
            {
            }

        } mSharedData;

        DbgGui();

        void update();
        void draw();

        friend class IComponent;
    };

} // namespace gui
} // namespace pe
