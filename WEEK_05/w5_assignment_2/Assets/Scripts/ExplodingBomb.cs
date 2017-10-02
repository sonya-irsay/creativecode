using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ExplodingBomb : MonoBehaviour {

	public GameObject Explosion;
	public GameObject Fire;
	public bool Exploded = false;

	// Use this for initialization
	void Start () {

	}
	
	// Update is called once per frame
	void Update () {

		    // If the bomb falls off the floor, destroy it.
		//if (this.transform.position.y < -10) {
			//Destroy (this.gameObject);
		//}


		// If the bomb has already exploded, we want to get rid of it as soon as 
		// all of the various particles it has emitted are gone.
		if (Exploded) {
			
			int particleCount = 0;
			foreach (ParticleSystem ps in this.GetComponentsInChildren<ParticleSystem>()) {
				particleCount += ps.particleCount;
			}

			if (particleCount == 0) {
				Destroy (this.gameObject);
			}
		}
	}

	void OnCollisionEnter(Collision collision) {

        if (collision.gameObject.tag == "seesaw") {
			
			// Disable the mesh renderers of the bomb parts.
			// This will make the bomb dissappear 
			foreach (MeshRenderer mr in this.GetComponentsInChildren<MeshRenderer>()) {
				mr.enabled = false;
			}

			// Stop the particle systems on the fuses. 
			// The particles that have already been emitted will remain.
			foreach (ParticleSystem ps in this.GetComponentsInChildren<ParticleSystem>()) {
				ps.Stop ();
			}

			// Instantiate the explosion and the prefab
			Instantiate (Explosion, this.transform.position, Quaternion.identity);
			Instantiate (Fire, this.transform.position, Quaternion.identity);
            //Destroy(collision.gameObject);

            Exploded = true;
		}
	}
}
