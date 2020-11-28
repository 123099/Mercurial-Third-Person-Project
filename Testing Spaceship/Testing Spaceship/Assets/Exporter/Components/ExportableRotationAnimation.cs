using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ExportableRotationAnimation : ExportableComponent
{
    public Vector3 speed = new Vector3(0, 30, 0);

    public override string Export()
    {
        return string.Format("\"rotationanimation\", {0}, {1}, {2}", speed.x, speed.y, speed.z);
    }
}
