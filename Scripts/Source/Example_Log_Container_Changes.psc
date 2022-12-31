scriptName Example_Log_Container_Changes extends Actor

Function Log(string text) global
    Debug.Trace("[Log Container Change] " + text)
EndFunction

Event OnItemAdded(Form akBaseItem, int aiItemCount, ObjectReference akItemReference, ObjectReference akSourceContainer)
    Log("Player OnItemAdded " + akBaseItem.GetFormID())
EndEvent

Event OnItemRemoved(Form akBaseItem, int aiItemCount, ObjectReference akItemReference, ObjectReference akDestContainer)
    Log("Player OnItemRemoved " + akBaseItem.GetFormID())
EndEvent
