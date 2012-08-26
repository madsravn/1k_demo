//--------------------------------------------------------------------------//
// iq / rgba  .  tiny codes  .  2008                                        //
//--------------------------------------------------------------------------//
/*
const static char *vertexShader=\
"varying vec4 v;"
"void main()"
"{"
"v=vec4(gl_Vertex.xy,64.0*gl_Color.xy);"
"gl_Position=gl_Vertex;"
"}";
*/
/*
const static char *fragmentShader=\
//"varying vec4 v;"
"void main()"
"{"
"vec2 v=-1.+gl_FragCoord.xy/vec2(400.,300.);"
// tunnel
"float r=pow(pow(abs(v.x),18.)+pow(abs(v.y),10.),1.8/28.);"
"vec2 t=vec2(gl_Color.x*64.+1./r,atan(v.x,v.y));"
// texture
"t=fract(2*t)-.5;"
"vec4 col=(1-pow(dot(t.xy,t.xy),.3))*vec4(2,1.8,1.6,0)+vec4(.3,.2,.1,0)+.12*vec4(v,0,0);"
// final color
"gl_FragColor=col/(2.*r);"
"}";
*/

const static char *fragmentShader=\
	"void main() {"
	"vec2 resolution = vec2(800.,600.);"
	"vec2 uPos = ( gl_FragCoord.xy / resolution.y ); //normalize wrt y axis"
	"uPos -= vec2((resolution.x/resolution.y)/2.0, 0.5); //shift origin to center"
	"float time = gl_Color.x; // The time sent by color"
	"float multiplier = 0.005; // Grosseur"
	"const float step = 0.2; //segmentation"
	"const float loop = 100.0; //Longueur"
	"const float timeSCale = 1.05; // Vitesse"
	
	"vec3 blueGodColor = vec3(0.0);"
	"float i = 0.0;"
	"for(i=1.0;i<loop;i++){	"	
	"	float t = time*timeSCale-step*i;"
		"vec2 point = vec2(0.75*sin(t), 0.5*sin(t*.02));"
		"point += vec2(0.75*cos(t*0.1), 0.5*sin(t*0.3));"
		"point /= 4. * sin(i);"
		"float componentColor= multiplier/((uPos.x-point.x)*(uPos.x-point.x) + (uPos.y-point.y)*(uPos.y-point.y))/i;"
		"blueGodColor += vec3(componentColor/2.0, componentColor/3.0, componentColor);"
	"}"
	
	
	"vec3 color = vec3(0,0,0);"
	"color += pow(blueGodColor,vec3(1.1,1.1,0.8));"
   
	
	"gl_FragColor = vec4(1.0,0.0,1.0, 1.0);"
"}";
	