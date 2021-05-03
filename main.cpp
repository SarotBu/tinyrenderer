#include "tgaimage.h"
#include "line.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);

	line(10, 15, 60, 25, image, white);
	line(20, 13, 40, 80, image, red);
	line(40, 70, 50, 70, image, red);
	line(30, 40, 30, 15, image, red);
	// image.set(52, 41, red);
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	return 0;
}

