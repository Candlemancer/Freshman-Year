#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class jkp : public gamePiece {
public:
	//return lft, rght, rear, goforward, attck, or nothing
	recommendation recommend(intel sitRep);

	// construct a living gamepiece
	jkp(int col, 
	    int row,
	    compassPoint direction,
	    int num,
	    provinceName p)
	    : gamePiece(col,row,direction,num,p){
	}
};
