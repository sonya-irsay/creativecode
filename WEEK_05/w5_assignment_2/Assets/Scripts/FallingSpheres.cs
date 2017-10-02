using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FallingSpheres : MonoBehaviour {

	public GameObject sphere;

	// Use this for initialization
	void Start () {
		InvokeRepeating("MakeSphere", 0.0f, 0.3f);
	}
	
	// Update is called once per frame
	void Update () {
	}

	void MakeSphere () {

		Vector3 pos;
		pos.y = 15;
		pos.x = Random.Range (-5, 5);
		pos.z = Random.Range (-5, 5);

		GameObject instance = Instantiate(sphere, pos, Quaternion.identity) as GameObject;
	}
}
