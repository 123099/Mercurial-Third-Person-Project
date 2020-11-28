using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[DisallowMultipleComponent]
[ExecuteInEditMode]
public class ExportableGameobject : Exportable
{
    private void Update()
    {
        IsRoot = transform.parent == null;
    }

    public static void Reset()
    {
        exportedObjects = 0;
    }

    private static int exportedObjects = 0;

    [Tooltip("This is the name of the model to be loaded in the game. The model should be located in the models folder in MGE assets and the name should include the file extension (.obj, .md2, etc.)")]
    [SerializeField] protected string modelFileName = "";

    [Tooltip("This is the name of the material to apply to the model. The material should be located in the materials folder in MGE assets and the name should NOT include the file extension")]
    [SerializeField] protected string materialName = "";

    [SerializeField]
    protected bool castShadows = true;

    [SerializeField]
    protected bool receiveShadows = true;

    private int indexInTable;

    public override string Export()
    {
        //Set the index we will have in the table
        indexInTable = exportedObjects;

        //Increase the number of exported objects
        ++exportedObjects;

        //Generate the create command for ourselves
        string basic = GetBasicGameObjectValues();
        string createCommand = string.Format("objects[{0}] = creategameobject({1}, \"{2}\", \"{3}\", {4}, {5})\n", indexInTable, basic, modelFileName, materialName.Split('.')[0], castShadows, receiveShadows);

        //Export all the components that we have
        ExportableComponent[] exportableComponents = transform.GetComponents<ExportableComponent>();
        foreach(ExportableComponent component in exportableComponents)
        {
            createCommand += string.Format("addbehaviour(objects[{0}], " + component.Export() + ")\n", indexInTable);
        }

        //Generate create commands for all the children and generate add children commands
        foreach (Transform child in transform)
        {
            ExportableGameobject exportableChild = child.GetComponent<ExportableGameobject>();
            if (exportableChild != null && exportableChild.IsProcessed == false)
            {
                createCommand += exportableChild.Export();

                //Mark the child as processed to not duplicate exporting
                exportableChild.IsProcessed = true;
            }
        }

        //Associate ourselves with parent
        if(transform.parent != null)
        {
            ExportableGameobject parent = transform.parent.GetComponent<ExportableGameobject>();
            if(parent != null)
            {
                int parentIndex = parent.indexInTable;
                bool worldPositionStays = false;
                createCommand += string.Format("addchild(objects[{0}], objects[{1}], {2})\n", parentIndex, indexInTable, worldPositionStays);
            }
        }

        return createCommand;
    }
}
