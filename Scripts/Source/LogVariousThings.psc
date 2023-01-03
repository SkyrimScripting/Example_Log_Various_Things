scriptName LogVariousThings extends Actor
{!BIND}

function Log(string text) global
    Debug.Trace("[Log Various Things] " + text)
endFunction

event OnInit()
    Log("OnInit!")
    RegisterForUpdate(5)
endEvent

event OnUpdate()
    int secondsElapsed = Utility.GetCurrentRealTime() as int
    Log("The game has been running for " + secondsElapsed + " seconds")
endEvent

event OnItemAdded(Form baseObject, int count, ObjectReference ref, ObjectReference source)
    Log("Player OnItemAdded " + count + "x " + baseObject.GetName())
endEvent

event OnItemRemoved(Form baseObject, int count, ObjectReference ref, ObjectReference destination)
    Log("Player OnItemRemoved " + count + "x " + baseObject.GetName())
endEvent

event OnObjectEquipped(Form baseObject, ObjectReference ref)
    Log("Player Equipped " + baseObject.GetName())
endEvent

event OnObjectUnequipped(Form baseObject, ObjectReference ref)
    Log("Player Unequipped " + baseObject.GetName())
endEvent
