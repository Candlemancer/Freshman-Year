// Jonathan Petersen
// A01236750
// Mandelbrot PPM Generator

#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int testPoint(double, double);
int colorR(int, int);
int colorG(int, int);
int colorB(int, int);

int main(){

	const int pixels = 512;
	srand(time(NULL));

	double xPosIni = -3.0;
	double xPosFin =  3.0;
	double yPosIni =  3.0;
	double yPosFin = -3.0;
	double xPos = xPosIni;
	double yPos = yPosIni;
	double Re0  =    -3.0;
	double Re1  =     3.0;
	double Im0  =     3.0;
	double Im1  =    -3.0;

	int xPix = 0;
	int yPix = 0;

	int  z = 0;
	int  color;
	int  index;
	int scheme;

	ifstream fget;
	ofstream fput;
	fget.open ("mandelinput.txt");
	fput.open("mandeloutput.ppm");

	//Read input files
	fget >> Re0;
	fget >> Re1;
	fget >> Im0;
	Im1 = (abs(Re1) - abs(Re0)) - Im0;

	//Convert Dr. Watson's Input to my input style
	xPosIni = Re0;
	xPosFin = Re1;
	yPosIni = Im0;
	yPosFin = Im1;

	//Initialize the PPM File and color scheme
	fput << "P3\n";
	fput << pixels << " " << pixels << endl;
	fput << 255 << endl;
	scheme = rand() % 4;

	//
	//Position and calculate points
	//
	for(yPix; yPix < pixels; yPix++){

		//Orient in y dimension
		yPos = (yPix * ((yPosFin - yPosIni)/pixels) ) + yPosIni;

		for(xPix; xPix < pixels; xPix++){

			//Orient in x dimension
			xPos = (xPix * ((xPosFin - xPosIni)/pixels) ) + xPosIni;

			//Calculate value of point and assign an index
			z = testPoint(xPos, yPos);
			index  = z % 256;

			//Color point based on value
			color = colorR(index, scheme);
			fput << color << " ";
			color = colorG(index, scheme);
			fput << color << " ";
			color = colorB(index, scheme);
			fput << color << " ";
		}

		//Reinitialize line
		xPix = 0;
		fput << endl;
	}

	fget.close();
	fput.close();

	return 0;
}



int testPoint(double x0, double y0){

	double iteration    =    0;
	double iterationMax = 4096;
	double t = 0;
	double x = 0;
	double y = 0;
	double z = 0;

	//Count number of iterations
	while(x*x + y*y <= 2 && iteration < iterationMax){

		t = 2 * x * y + y0;
		x = x*x - y*y + x0;
		y = t;

		iteration++;
	}

	//Set result to number of iterations, or 0 if no result
	if(iteration != iterationMax) z = iteration;
	if(iteration == iterationMax) z = 0;

	return z;
}



int colorR(int index, int scheme){

	int r = 0;
	int r0,r1,r2,r3,r4;

	//Determine red color points
	switch (scheme){

	case 0:
		r0 =  31;
		r1 = 204;
 		r2 = 250;
		r3 = 250;
		r4 = 245;
		break;

	case 1:
		r0 =  89;
		r1 = 158;
		r2 = 196;
		r3 = 226;
		r4 = 240;
		break;

	case 2:
		r0 =  36;
		r1 =  75;
		r2 = 189;
		r3 = 231;
		r4 = 223;
		break;

	case 3:
		r0 =   0;
		r1 =  24;
		r2 =  98;
		r3 = 143;
		r4 = 226;
		break;
	}

	//Create red gradients based on index values
	if(index == 0);
	if(index >=   1 && index <=  51) r = ((index -   0) / 51.0) * r4;
	if(index >=  52 && index <= 102) r = ((index -  51) / 51.0) * r3;
	if(index >= 103 && index <= 153) r = ((index - 102) / 51.0) * r2;
	if(index >= 154 && index <= 204) r = ((index - 153) / 51.0) * r1;
	if(index >= 205 && index <= 255) r = ((index - 204) / 51.0) * r0;

	return r;
}



int colorG(int index, int scheme){

	int g = 0;
	int g0,g1,g2,g3,g4;

	//Determine green color points
	switch (scheme){

	case 0:
		g0 =  19;
		g1 = 141;
		g2 = 150;
		g3 = 177;
		g4 = 211;
		break;

	case 1:
		g0 = 168;
		g1 = 213;
		g2 = 237;
		g3 = 255;
		g4 = 242;
		break;

	case 2:
		g0 =  15;
		g1 =  36;
		g2 = 122;
		g3 = 144;
		g4 =  98;
		break;

	case 3:
		g0 =   0;
		g1 =  56;
		g2 = 116;
		g3 = 175;
		g4 = 223;
		break;
	}

	//Create green gradients based on index values
	if(index == 0);
	if(index >=   1 && index <=  51) g = ((index -   0) / 51.0) * g4;
	if(index >=  52 && index <= 102) g = ((index -  51) / 51.0) * g3;
	if(index >= 103 && index <= 153) g = ((index - 102) / 51.0) * g2;
	if(index >= 154 && index <= 204) g = ((index - 153) / 51.0) * g1;
	if(index >= 205 && index <= 255) g = ((index - 204) / 51.0) * g0;

	return g;
}



int colorB(int index, int scheme){

	int b = 0;
	int b0,b1,b2,b3,b4;

	//Determine blue color points
	switch (scheme){

	case 0:
		b0 =   6;
		b1 =  69;
		b2 = 150;
		b3 = 177;
		b4 = 211;
		break;

	case 1:
		b0 =  15;
		b1 =  76;
		b2 = 104;
		b3 = 158;
		b4 = 221;
		break;

	case 2:
		b0 =   3;
		b1 =   9;
		b2 =  34;
		b3 =  34;
		b4 =  28;
		break;

	case 3:
		b0 =   0;
		b1 =  77;
		b2 = 130;
		b3 = 154;
		b4 = 188;
		break;
	}

	//Create blue gradients based on index values
	if(index == 0);
	if(index >=   1 && index <=  51) b = ((index -   0) / 51.0) * b4;
	if(index >=  52 && index <= 102) b = ((index -  51) / 51.0) * b3;
	if(index >= 103 && index <= 153) b = ((index - 102) / 51.0) * b2;
	if(index >= 154 && index <= 204) b = ((index - 153) / 51.0) * b1;
	if(index >= 205 && index <= 255) b = ((index - 204) / 51.0) * b0;

	return b;
}
