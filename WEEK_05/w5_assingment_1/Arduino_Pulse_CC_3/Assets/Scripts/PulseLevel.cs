using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using UnityEngine;

public class PulseLevel : MonoBehaviour {

    SerialPort port;

    public GameObject sphere;

	// Use this for initialization
	void Start () {
        //To find port name go in Arduino > Port > checkmark or something
        // 9600 = how fast we're talking together
        port = new SerialPort("COM3", 9600);
        port.Open();
    }
	
	// Update is called once per frame
	void Update () {
        //read from the port
        //when there is new data / waits for arduino to send a line (if too slow = unity will hang, "freeze" until
        //it gets new data, it doesn't let anything after this code happen
        string line = port.ReadLine();

        //arduino sends data much faster than unity can read it, so:
        //after you read the line, fluch/get rid of the log/line behind it/back up
        port.BaseStream.Flush();


        int data = int.Parse(line);

        Debug.Log(line);

        // incoming data: btwn 300 & 800
        // convert that to .5 and 2
        float size = map(data, 450, 900, .5F, 2.0F);

        sphere.transform.localScale = new Vector3(size, size, size);

        //if (size <= .9F)
        //{
        //    //use the data to transform sphere
        //    sphere.transform.localScale = new Vector3(1, 1, 1);
        //} else if (size >= 1.0F)
        //{
        //    sphere.transform.localScale = new Vector3(2, 2, 2);
        //}
	}

float map(float s, float a1, float a2, float b1, float b2)
{
    return b1 + (s - a1) * (b2 - b1) / (a2 - a1);
}

}