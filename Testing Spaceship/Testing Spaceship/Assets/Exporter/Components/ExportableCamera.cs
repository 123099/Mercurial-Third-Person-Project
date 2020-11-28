using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Camera))]
public class ExportableCamera : ExportableComponent
{
    public override string Export()
    {
        Camera camera = GetComponent<Camera>();
        return string.Format("\"camera\", {0}, {1}, {2}, {3}", camera.fieldOfView, camera.nearClipPlane, camera.farClipPlane, Camera.main == camera);
    }
}
