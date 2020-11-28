using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class Exportable : MonoBehaviour
{
    public bool IsRoot { get { return isRoot; } set { isRoot = value; } }
    [SerializeField] private bool isRoot = false;

    public bool IsProcessed { get { return isProcessed; } set { isProcessed = value; } }
    private bool isProcessed = false;

    public abstract string Export();

    protected string GetBasicGameObjectValues()
    {
        //Get the local position
        Vector3 pos = transform.localPosition;

        //Get the local rotation
        Quaternion rotation = transform.localRotation;

        //Flip camera 180 to match OpenGL
        if(GetComponent<Camera>())
        {
            rotation = rotation * Quaternion.Euler(0, 180, 0);
        }

        //Get the local scale
        Vector3 scale = transform.localScale;

        string transformText = string.Format("{0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}",
                                             -pos.x, pos.y, pos.z,
                                             rotation.x, -rotation.y, -rotation.z, rotation.w,
                                             scale.x, scale.y, scale.z);

        return string.Format("\"{0}\", {1}, {2}", name, gameObject.isStatic, transformText);
    }
}
