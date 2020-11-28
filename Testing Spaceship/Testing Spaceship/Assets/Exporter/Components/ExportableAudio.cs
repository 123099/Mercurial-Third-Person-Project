using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(AudioSource))]
public class ExportableAudio : ExportableComponent
{
    [SerializeField] private string clipFileName;
    [SerializeField] private bool cacheClip;
    [SerializeField] private bool streamClip;

    public override string Export()
    {
        AudioSource audio = GetComponent<AudioSource>();
        bool is2DSound = audio.spatialBlend < 1.0f;
        print(is2DSound);
        return string.Format("\"audiosource\", \"{0}\", {1}, {2}, {3}, {4}, {5}, {6}, {7}" , 
                             clipFileName, streamClip, cacheClip, audio.playOnAwake,
                             audio.loop, audio.pitch, audio.volume, is2DSound);
    }
}
