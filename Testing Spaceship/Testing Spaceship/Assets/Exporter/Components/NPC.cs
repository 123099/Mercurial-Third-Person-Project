using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NPC : ExportableComponent
{
    [SerializeField] private int npcID;
    [SerializeField] private bool isInteractble = true;
    [SerializeField] private bool runEveryFrame = false;

    public override string Export()
    {
        return string.Format("\"npc\", {0}, {1}, {2}", npcID, isInteractble, runEveryFrame);
    }
}
