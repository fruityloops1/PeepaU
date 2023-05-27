#include "pe/DbgGui/DbgGui.h"
#include "pe/DbgGui/MenuBar.h"
#include "pe/DbgGui/Windows/HeapViewer.h"
#include "pe/DbgGui/Windows/ImGuiDemo.h"
#include "pe/Util/DbgHeap.h"
#include "pe/Util/Log.h"

namespace pe {
namespace gui {

    SEAD_SINGLETON_DISPOSER_IMPL(DbgGui)

    DbgGui::DbgGui()
    {
        mComponents.allocBuffer(16, pe::getDbgHeap());
        mComponents.pushBack(new (pe::getDbgHeap()) MenuBar);
        mComponents.pushBack(new (pe::getDbgHeap()) ImGuiDemo);
        mComponents.pushBack(new (pe::getDbgHeap()) HeapViewer);
    }

    void DbgGui::draw()
    {
        for (int i = 0; i < mComponents.size(); i++)
            mComponents[i]->draw();
    }

    void DbgGui::update()
    {
        for (int i = 0; i < mComponents.size(); i++)
            mComponents[i]->update();
    }

} // namespace gui
} // namespace pe
