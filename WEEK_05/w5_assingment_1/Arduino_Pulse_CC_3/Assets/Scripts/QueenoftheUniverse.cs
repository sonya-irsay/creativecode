using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class QueenoftheUniverse : MonoBehaviour {

    public GameObject myPrefab;
    public GameObject myCylinder;
    public GameObject myTarget;

	// Use this for initialization
	void Start () {

        MySphere.globalSpeed = 100.0f;
        //this is setting the target to (0,0,0) - Queen, but we can set it to follow another object
        MySphere.globalTarget = myTarget;
        MySphere.globalYawing = 270.0f;

        StartCoroutine( CreateSpheres() );

	}

    //can do some process, wait an amount of time, then continue (neater than doing it in update)
    //the type is IEnumerator
    //this is the co-routine:
    IEnumerator CreateSpheres()
    {
        for (int i = 0; i < 40; i++)
        {
            //setting random number
            Vector3 pos = new Vector3(Random.Range(-5, 5), Random.Range(-5, 5), Random.Range(-5, 5));
            //telling it which one to instantiate
            GameObject newObject = Instantiate(myPrefab);
            //making the position the random number we instantiated
            newObject.transform.position = pos;

            //wait for some seconds
            yield return new WaitForSeconds(0.5f);

            //CYLINDER
            //setting random number
            Vector3 pos2 = new Vector3(Random.Range(-5, 5), Random.Range(-5, 5), Random.Range(-5, 5));
            //telling it which one to instantiate
            GameObject newObject2 = Instantiate(myCylinder);
            //making the position the random number we instantiated
            newObject.transform.position = pos2;

            //wait for some seconds
            yield return new WaitForSeconds(0.5f);
        }
    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
