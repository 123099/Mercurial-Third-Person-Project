using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ExportableContrast : ExportableComponent {
    public float contrast;
    public override string Export()
    {
        return string.Format("\"contrast\", {0}", contrast);
    }
}
