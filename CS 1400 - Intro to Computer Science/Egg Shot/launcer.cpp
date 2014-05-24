// Jonathan Petersen
// A01236750
// Egg Slingshot

#include <iostream>
#include <cmath>

using namespace std;

int main(){

	float x;
	float m = 0.065;
	float g = 9.8;
	float k = 25;
	float d;
	float tRad;
	float tDeg;
	
	cout << "What is the distance to the target in meters?\n";
	cin >> d;
	// d = 100;
	cout << "What is the angle of elevation in degrees?\n";
	cin >> tDeg;
	// tDeg = 60;


// Convert Degrees to Radians

	float pi = 3.1415926535;

	tRad = tDeg * (pi / 180);
	
// Calculate pull-back distance

	x = sqrt((m*g*d)/(k*sin(2*tRad)));
	
	cout << "You would need a draw length of " << x << " meters.\n";
	
	
	return 0;
}
