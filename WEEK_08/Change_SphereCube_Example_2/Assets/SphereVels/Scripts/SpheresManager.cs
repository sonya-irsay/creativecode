using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Collections.Generic;

public class SpheresManager : MonoBehaviour {

	public GameObject spherePrefab;
	List<GameObject> mySpheres = new List<GameObject>();

	// Use this for initialization
	void Start () {

        for (int x = 0; x < 10; x++){
			for(int y = 0; y < 10; y++){
				for(int z = 0; z < 10; z++){
                    var randomRotation = Quaternion.Euler(Random.Range(0, 360), 0, 0);
                    mySpheres.Add ( Instantiate(spherePrefab, new Vector3(x*.125f,y*.125f,z*.125f), randomRotation));
                    
                    // Calculate a color based on it's position
                    Color color = new Color();
                    color.r = (float)x / 10.0F;
                    color.g = (float)y / 10.0F;
                    color.b = (float)z / 10.0F;
                    color.a = 0.25F;

                    Material oldMat = spherePrefab.GetComponent<Renderer>().sharedMaterial;
                    Material newMat = new Material(oldMat);
                    newMat.name = "Mat_" + name;
                    newMat.color = color;
                    spherePrefab.GetComponent<Renderer>().sharedMaterial = newMat;
                }
			}
		}

    }
	
	// Update is called once per frame
	void Update () {



		if (Input.GetKeyDown ("a")) {
			foreach (GameObject sphere in mySpheres) {
				sphere.GetComponent<Rigidbody> ().isKinematic = false;
			}
		}else if (Input.GetKeyDown ("s")) {
			foreach (GameObject sphere in mySpheres) {
				sphere.GetComponent<Rigidbody> ().isKinematic = true;
			}
		}

		RaycastHit hit;
		Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

        if ( /*Input.GetMouseButtonDown(0) &&*/  Physics.Raycast(ray, out hit) && hit.transform.tag == "Sphere")
        {
            foreach (GameObject sphere in mySpheres)
            {
                Vector3 repel = sphere.transform.position - hit.transform.position;
                float dist = repel.magnitude;
                if (dist < 1.5f)
                {
                    repel.Normalize();
                    sphere.GetComponent<Sphere>().addVelocity(repel * dist * .1f);
                }

            }
        }


    }
}
