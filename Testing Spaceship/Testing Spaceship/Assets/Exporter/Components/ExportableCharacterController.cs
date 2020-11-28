using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(CharacterController))]
public class ExportableCharacterController : ExportableComponent
{
    public override string Export()
    {
        CharacterController controller = GetComponent<CharacterController>();
        return string.Format("\"charactercontroller\", {0}, {1}, {2}, {3}", controller.slopeLimit, controller.stepOffset, controller.radius, controller.height);
    }
}
