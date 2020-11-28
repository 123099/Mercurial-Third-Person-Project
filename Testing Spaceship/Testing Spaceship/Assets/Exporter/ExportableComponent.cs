using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(ExportableGameobject))]
public abstract class ExportableComponent : MonoBehaviour
{
    public abstract string Export();
}
