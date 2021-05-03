#include "line.h"

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color){
	float dx = (float) (x1 - x0);
	float dy = (float) (y1 - y0);
	float diffx, diffy;
	if (dy != 0) diffx = dx/dy;
	else diffx = 0;
	if (dx != 0) diffy = dy/dx;
	else diffy = 0;
	float x = x0;
	float y = y0;
	if (x0 > x1){ std::swap(x0, x1); }
	if (y0 > y1){ std::swap(y0, y1); }
	if (y1 - y0 > x1 - x0){
		for (int i=y0;i<=y1;i++){
			image.set((int) x, i, color);
			x += diffx;
		}
	}else{
		for (int i=x0;i<=x1;i++){
			image.set(i, (int) y, color);
			y += diffy;
		}
	}
}
