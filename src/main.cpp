#include <Canvas.hpp>
#include <Ray.hpp>

using namespace war;
int main() {
	Canvas canvas(255,255);
	canvas.exportImage("render.png");
	Ray r(point_t(0),vec_t(1));

       	return 0; 
}
