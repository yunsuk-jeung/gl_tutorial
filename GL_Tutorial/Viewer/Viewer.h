#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string>
#include  <Eigen/Dense>
#include <vector>

class Viewer {
public:
	Viewer() {
	}
	~Viewer() {
	}

	void initialize(int argc, char** argv, std::string);
	void setData();
	void onDraw();

private:

	GLuint VertexArrayID;
	std::vector<Eigen::Vector3f> vertexData;
	GLuint vertexBuffer;

};