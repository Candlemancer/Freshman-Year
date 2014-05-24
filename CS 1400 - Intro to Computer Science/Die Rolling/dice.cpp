// Jonathan Petersen
// A01236750
// Die Rolling

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){

	int Sides = 6;
	int t = 0;
	int Result;
	char Input;
	srand(time(NULL));

	cout << "Enter R to roll the die, C to change the number of sides, or Q to quit. ";
	while(Input != 'q' && Input != 'Q'){
		cout << "[R, C, Q] ";
		cin >> Input;
		if(Input == 'r' || Input == 'R'){
			Result = ((rand()%Sides)+1);
			cout << Result << "\n";
		}else{
			if(Input == 'c' || Input == 'C'){
				cout << "How many sides does your die have? ";
				cin >> Sides;

			}else{
				if(Input == 'q' || Input == 'Q'){
					return 0;
				}else{
					cout << "Input not recognized, try again.\n";
				}
			}
		}
	}

	return 0;

}


