using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(CapsuleCollider))]
public class ExportableCapsuleCollider : ExportableComponent
{
    public override string Export()
    {
        CapsuleCollider capsule = GetComponent<CapsuleCollider>();
        return string.Format("\"capsulecollider\", {0}, {1}", capsule.radius, capsule.height);
    }
}
