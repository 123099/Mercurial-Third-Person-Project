using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test : MonoBehaviour {

	// Use this for initialization
	void Start () {
        print(transform.rotation + "," + transform.eulerAngles + "," + transform.rotation * new Vector3(0, 0, 1));
        transform.Translate(new Vector3(0, 0, 1), Space.World);
        print(transform.position + "," + transform.localPosition);
        transform.Translate(new Vector3(0, 0, -1), Space.World);
        transform.position = transform.position + new Vector3(1, 0, 0);
        print(transform.position + "," + transform.localPosition);
    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
