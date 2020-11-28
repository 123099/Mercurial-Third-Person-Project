using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System.IO;

public static class TerrainExporter
{
    [MenuItem("MGE/Export Terrain Heightmap")]
    public static void Export()
    {
        //Retrieve the selected object in the scene
        GameObject selected = Selection.activeGameObject;
        Terrain terrain = null;

        //Make sure we selected something
        if (selected != null)
        {
            //Check that the game object is a terrain
            terrain = selected.GetComponent<Terrain>();
        }

        if(terrain == null)
        {
            EditorUtils.ShowNotificationInSceneWindow("Please select a terrain first.");
        }
        else
        {
            ExportHeightMap(terrain.name, terrain.terrainData);
            EditorUtils.ShowNotificationInSceneWindow("Terrain " + terrain.name + " saved successfully!");
        }
    }

    private static void ExportHeightMap(string terrainName, TerrainData terrainData)
    {
        //Create a heightmap texture
        Texture2D heightMap = new Texture2D(terrainData.heightmapWidth, terrainData.heightmapHeight, TextureFormat.RGBA32, false);

        //Retrieve the normalized heights of the terrain
        float[,] heights = terrainData.GetHeights(0, 0, heightMap.width, heightMap.height);

        //Go through every height and put it in the texture
        for(int height = 0; height < heightMap.height; ++height)
        {
            for(int width = 0; width < heightMap.width; ++width)
            {
                //Retrieve the normalized height
                float h = heights[height, width];

                //Construct grayscale color to represent height
                Color color = new Color(h, h, h);

                //Gamma correct the color
                color = GammaCorrectColor(color);

                heightMap.SetPixel(width, heightMap.height - height - 1, color); //Flip along the y axis
            }
        }

        //Apply pixels
        heightMap.Apply();

        //Export to PNG
        File.WriteAllBytes(Application.dataPath + "/" + terrainName + "_heightMap.png",  heightMap.EncodeToPNG());
        AssetDatabase.Refresh();
    }

    [MenuItem("MGE/Export Terrain SplatMap")]
    public static void ExportSplatMap()
    {
        Object selected = Selection.activeObject;

        if(selected == null || selected is Texture2D == false)
        {
            EditorUtils.ShowNotificationInSceneWindow("Please select terrain splat map from project folder first.");
        }
        else
        {
            Texture2D selectedTexture = selected as Texture2D;
            Texture2D splatMap = new Texture2D(selectedTexture.width, selectedTexture.height, TextureFormat.ARGB32, false);

            //Copy the pixels from the selected texture to the splatmap, flipping across the y axis
            for(int height = 0; height < splatMap.height; ++height)
            {
                for(int width = 0; width < splatMap.width; ++width)
                {
                    //Retrieve the pixel from the selected texture
                    Color color = selectedTexture.GetPixel(width, height);

                    //Gamma correct the pixel
                    color = GammaCorrectColor(color);

                    //Save the pixel into splat map
                    splatMap.SetPixel(width, splatMap.height - height - 1, color);
                }
            }

            File.WriteAllBytes(Application.dataPath + "/splatMap.png", splatMap.EncodeToPNG());
            EditorUtils.ShowNotificationInSceneWindow("Splat map exported successfully!");
            AssetDatabase.Refresh();
        }
    }

    private static Color GammaCorrectColor(Color color)
    {
        color.r = Mathf.Pow(color.r, 1.0f/2.2f);
        color.g = Mathf.Pow(color.g, 1.0f/2.2f);
        color.b = Mathf.Pow(color.b, 1.0f/2.2f);
        color.a = Mathf.Pow(color.a, 1.0f/2.2f);

        return color;
    }
}
