#version 120
#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

void main() {
	vec2 st = gl_FragCoord.xy/u_resolution;

	float pct = 0.0;

    // from distance example in ofbook:
    pct = distance(st,vec2(0.5));

	vec3 color = vec3(pct, pct, 255);

	gl_FragColor = vec4( color, sin(u_time) );
	//gl_FragColor = vec4(atan(st.x),sin(st.y),sin(u_time),1.0);
}
