using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(AudioListener))]
public class ExportableAudioListener : ExportableComponent
{
    public override string Export()
    {
        return "\"audiolistener\"";
    }
}
