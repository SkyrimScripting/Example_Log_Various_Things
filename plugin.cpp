#include <SkyrimScripting/Plugin.h>

EventHandlers {
    On<RE::TESContainerChangedEvent>([](const RE::TESContainerChangedEvent* event) {
        if (event->newContainer == 0x14) {
            auto* baseForm = RE::TESForm::LookupByID(event->baseObj);
            logger::info("Player acquired {}", baseForm->GetName());
        } else if (event->oldContainer == 0x14) {
            auto* baseForm = RE::TESForm::LookupByID(event->baseObj);
            logger::info("Player lost {}", baseForm->GetName());
        }
    });

    On<RE::TESActivateEvent>([](const RE::TESActivateEvent* event) {
        auto activated = event->objectActivated->GetBaseObject()->GetName();
        auto activator = event->actionRef->GetBaseObject()->GetName();
        logger::info("{} activated {}", activator, activated);
    });
}
