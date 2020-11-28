using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ExportableDoor : ExportableComponent
{
    public override string Export()
    {
        return "\"door\"";
    }
}
