using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FreeLookCamera : ExportableComponent
{
    [SerializeField] private float moveSpeed;
    [SerializeField] private float rotationSpeed;

    public override string Export()
    {
        return string.Format("\"freelookcamera\", {0}, {1}", moveSpeed, rotationSpeed);
    }
}
