using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : ExportableComponent
{
    public float walkVelocity;

    public override string Export()
    {
        return string.Format("\"player\", {0}", walkVelocity);
    }
}
