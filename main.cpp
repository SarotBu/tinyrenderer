#include "tgaimage.h"
#include "line.h"
#include "model.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

Model *model = NULL;
const int width = 800;
const int height = 800;

int main(int argc, char** argv) {
	if (argc == 2){
		model = new Model(argv[1]);
	}else{
		model = new Model("obj/african_head/african_head.obj");
	}

	TGAImage image(width, height, TGAImage::RGB);
	int face_idx = 0;
	for (int i=0;i<model->nfaces();i++, face_idx+=3){
		for (int j=0;j<3;j++){
			vec3 v0 = model->vert(i, j);
			vec3 v1 = model->vert(i, (j+1)%3);
			int x0 = (v0.x+1.)*width/2.;
			int y0 = (v0.y+1.)*height/2.;
			int x1 = (v1.x+1.)*width/2.;
			int y1 = (v1.y+1.)*height/2.;
			line(x0, y0, x1, y1, image, white);
			// std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << "\n";
		}
	}
	/*
	TGAImage image(100, 100, TGAImage::RGB);
	line(10, 15, 60, 25, image, white);
	line(20, 13, 40, 80, image, red);
	line(40, 70, 50, 70, image, red);
	line(30, 40, 30, 15, image, red);
	*/
	// image.set(52, 41, red);
	// image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	return 0;
}

