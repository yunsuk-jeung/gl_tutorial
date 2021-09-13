attribute vec3 vertexModel;

uniform mat4 MVPMatrix;
varying vec4 color;

void main(){
	gl_Position = MVPMatrix * vec4(vertexModel, 1.0);
	color = vec4(1.0,0.0,0.0,1.0);

}