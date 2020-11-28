using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ExportableElevator : ExportableComponent
{
    public Vector3 pointB;
    public float speed;

    public override string Export()
    {
        return string.Format("\"elevator\", {0}, {1}, {2}, {3}", pointB.x, pointB.y, pointB.z, speed);
    }
}
