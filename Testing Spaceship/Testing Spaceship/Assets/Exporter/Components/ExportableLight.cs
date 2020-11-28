using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[DisallowMultipleComponent]
[RequireComponent(typeof(Light))]
public class ExportableLight : ExportableComponent
{
    public override string Export()
    {
        Light light = GetComponent<Light>();
        string type = "\"" + light.type.ToString().ToLower() + "\"";
        string color = string.Format("{0}, {1}, {2}, {3}", light.color.r, light.color.g, light.color.b, light.color.a);
        return string.Format("\"light\", {0}, {1}, {2}, {3}", type, color, light.intensity, light.spotAngle);
    }
}
