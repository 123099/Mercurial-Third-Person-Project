using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ExportableTV : ExportableComponent
{
    public override string Export()
    {
        return "\"tv\"";
    }
}
