using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ExportableFog : ExportableComponent {
    public override string Export()
    {
        return "\"fog\"";
    }

}
