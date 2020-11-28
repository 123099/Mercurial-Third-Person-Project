using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(ExportableLight))]
public class LightIdentifier : ExportableComponent
{
    public int ID;

    public override string Export()
    {
        return string.Format("\"lightidentifier\", {0}", ID);
    }
}
