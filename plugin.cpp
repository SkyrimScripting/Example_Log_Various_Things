#include <SkyrimScripting/Plugin.h>

OnInit { spdlog::set_pattern("%v"); }

EventHandlers {
    On<RE::TESContainerChangedEvent>(
        [](const RE::TESContainerChangedEvent* event) {
            auto item = RE::TESForm::LookupByID(event->baseObj)->GetName();
            std::string from{};
            std::string to{};
            if (event->oldContainer)
                from = RE::TESForm::LookupByID(event->oldContainer)->GetName();
            if (event->newContainer)
                to = RE::TESForm::LookupByID(event->newContainer)->GetName();
            logger::info("{}x {} from '{}' 0x{:x} ---> '{}' 0x{:x}",
                         event->itemCount, item, from, event->oldContainer, to,
                         event->newContainer);
        });

    On<RE::TESEquipEvent>([](const RE::TESEquipEvent* event) {
        auto owner = event->actor->GetBaseObject()->GetName();
        auto item = RE::TESForm::LookupByID(event->baseObject)->GetName();
        if (event->equipped)
            logger::info("{} equipped {}", owner, item);
        else
            logger::info("{} unequipped {}", owner, item);
    });

    On<RE::TESActivateEvent>([](const RE::TESActivateEvent* event) {
        auto activated = event->objectActivated->GetBaseObject()->GetName();
        auto activator = event->actionRef->GetBaseObject()->GetName();
        logger::info("{} activated {}", activator, activated);
    });
}
