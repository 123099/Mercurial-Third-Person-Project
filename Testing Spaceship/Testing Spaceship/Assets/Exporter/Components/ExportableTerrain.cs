using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Terrain))]
public class ExportableTerrain : ExportableComponent
{

    public override string Export()
    {
        TerrainData terrainData = GetComponent<Terrain>().terrainData;
        return string.Format("\"terrain\", {0}, {1}, {2}", terrainData.size.x, terrainData.size.y, terrainData.size.z);
    }
}
