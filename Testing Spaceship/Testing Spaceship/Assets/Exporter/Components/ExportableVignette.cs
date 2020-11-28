using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ExportableVignette : ExportableComponent
{
    public override string Export()
    {
        return string.Format("\"vignette\"");
    }
}