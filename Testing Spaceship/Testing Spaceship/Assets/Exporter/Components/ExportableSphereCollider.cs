using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(SphereCollider))]
public class ExportableSphereCollider : ExportableComponent
{
    public override string Export()
    {
        SphereCollider sphereCollider = GetComponent<SphereCollider>();
        return string.Format("\"spherecollider\", {0}", sphereCollider.radius);
    }
}
