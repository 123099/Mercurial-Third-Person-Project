using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RotatingBehaviour : ExportableComponent
{
    [SerializeField] private float rotationSpeed = 0;

    public override string Export()
    {
        return string.Format("\"rotatingbehaviour\", {0}", rotationSpeed);
    }
}
