using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ExportableSun : ExportableComponent
{
    public override string Export()
    {
        return "\"sun\"";
    }
}
