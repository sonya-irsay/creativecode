using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MySphere : MonoBehaviour {

    public static GameObject globalTarget;

    //static variable will be the same for all instances
    public static float globalSpeed = 0.1f;
    public static float globalYawing = 90.0f;

    public float mySpeed;

    float speedScale = 1.0f;
    float yawingScale = 1.0f;

    // Use this for initialization
    void Start () {

        speedScale = Random.Range(.1f, .5f);
	}
	
	// Update is called once per frame
	void Update () {
        //this is just to show that static speed changes all instances
        mySpeed = globalSpeed;

        //position update
        //multiplying its forward vector/direction by the global speed * local speed * time
        transform.position += transform.forward * (globalSpeed * speedScale * Time.deltaTime);

        // rotation update
        //Quaternion strange math formula that no one understands, everyone uses (takes care of certain properties
        //of rotating values)
        //FromToRotation = (from point, to point) ---- {get, set}
        Quaternion rotation = Quaternion.FromToRotation(
            transform.forward,
            globalTarget.transform.position - transform.position);

        transform.rotation = Quaternion.RotateTowards(
            Quaternion.identity,
            rotation,
            globalYawing * yawingScale * Time.deltaTime) * transform.rotation;
    }
}
