using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(MeshCollider))]
public class ExportableMeshCollider : ExportableComponent
{
    public override string Export()
    {
        MeshCollider collider = GetComponent<MeshCollider>();
        return string.Format("\"meshcollider\", {0}", collider.convex);
    }
}
