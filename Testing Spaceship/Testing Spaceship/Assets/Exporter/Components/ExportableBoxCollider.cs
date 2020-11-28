using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(BoxCollider))]
public class ExportableBoxCollider : ExportableComponent
{
    public override string Export()
    {
        BoxCollider box = GetComponent<BoxCollider>();
        return string.Format("\"boxcollider\", {0}, {1}, {2}", box.bounds.size.z*0.5f, box.bounds.size.y * 0.5f, box.bounds.size.x * 0.5f);
    }
}
