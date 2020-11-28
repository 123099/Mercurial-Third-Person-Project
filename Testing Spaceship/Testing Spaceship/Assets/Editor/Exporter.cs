using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System.IO;
using UnityEditor.SceneManagement;

public static class Exporter
{
    private static string previousSaveLocation = "";

	[MenuItem("MGE/Export Level")]
    public static void ExportScene()
    {
        EditorSceneManager.SaveCurrentModifiedScenesIfUserWantsTo();

        string fileContents = "";

        //Retrieve all exportable objects in the scene
        Exportable[] exportables = Object.FindObjectsOfType<Exportable>();
        
        //Reset all the exportables
        for(int i = 0; i < exportables.Length; ++i)
        {
            exportables[i].IsProcessed = false;
        }

        //Create a table for the created game objects
        fileContents += "objects = {}\n";

        //Go through all the exportable objects in the scene and export them
        for(int i = 0; i < exportables.Length; ++i)
        {
            if (exportables[i].IsRoot == true && exportables[i].IsProcessed == false)
            {
                fileContents += exportables[i].Export() + "\n";
                exportables[i].IsProcessed = true;
            }
        }

        //Fix case for booleans
        fileContents = fileContents.Replace("True", "true").Replace("False", "false");

        string levelName = EditorSceneManager.GetActiveScene().name;

        string path = EditorUtility.SaveFilePanel("Save " + levelName, previousSaveLocation, levelName, "lua");

        if (path.Length > 0)
        {
            previousSaveLocation = path.Substring(0, path.Length - levelName.Length - 3);

            //Save to file
            File.WriteAllText(path, fileContents);

            EditorUtils.ShowNotificationInSceneWindow("Successfully exported the level " + levelName);
            Debug.Log("Successfully exported the level " + levelName);

            ExportableGameobject.Reset();
        }
    }
}
