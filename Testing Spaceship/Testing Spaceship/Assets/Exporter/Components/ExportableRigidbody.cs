using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Rigidbody))]
public class ExportableRigidbody : ExportableComponent
{
    public float friction=0.5f;
    public bool alwaysActive = false;
    public override string Export()
    {
        Rigidbody rigidbody = GetComponent<Rigidbody>();

        bool xPosFrozen = (rigidbody.constraints & RigidbodyConstraints.FreezePositionX) != RigidbodyConstraints.None;
        bool yPosFrozen = (rigidbody.constraints & RigidbodyConstraints.FreezePositionY) != RigidbodyConstraints.None;
        bool zPosFrozen = (rigidbody.constraints & RigidbodyConstraints.FreezePositionZ) != RigidbodyConstraints.None;

        bool xRotFrozen = (rigidbody.constraints & RigidbodyConstraints.FreezeRotationX) != RigidbodyConstraints.None;
        bool yRotFrozen = (rigidbody.constraints & RigidbodyConstraints.FreezeRotationY) != RigidbodyConstraints.None;
        bool zRotFrozen = (rigidbody.constraints & RigidbodyConstraints.FreezeRotationZ) != RigidbodyConstraints.None;



        return string.Format("\"rigidbody\", {0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}", rigidbody.useGravity ? rigidbody.mass : 0, rigidbody.isKinematic,
                                                                                      xPosFrozen, yPosFrozen, zPosFrozen,
                                                                                      xRotFrozen, yRotFrozen, zRotFrozen, 
                                                                                      friction, alwaysActive);
    }
}
