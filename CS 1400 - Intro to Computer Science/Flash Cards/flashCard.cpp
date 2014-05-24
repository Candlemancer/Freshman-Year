// Jonathan Petersen
// A01236750
// Flash Cards

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

	int x, y, answer, response;
	int correct, total;
	srand(562);

	cout << "Welcome to FlashMaster!\n";
	cout << "Here come your problems!\n";

	//Begin "Loop"
	for (int i = 0; i < 5; i++) {

		x = rand()%13;
		y = rand()%13;

		cout << "What is " << x << "*" << y << "?\n";
		cin >> response;
		answer = x * y;

		if (answer == response) {
			//Just Like Misty.
			cout << "You're a brilliant genius!\n";
			correct++;
		}
		else {
			cout << "Not so much.\n";
		}

		total++;
		cout << "You have answered " << correct << " out of " << total << " questions correct.\n";
	}

	return 0;
}



// //Begin "Loop"
// 	x = rand()%13;
// 	y = rand()%13;
// 	cout << "What is " << x << "*" << y << "?\n";
// 	cin >> response;
// 	answer = x * y;
// 	if(answer == response){
// //Just Like Misty.
// 		cout << "You're a brilliant genius!\n";
// 		correct++;
// 	}else{
// 		cout << "Not so much.\n";
// 	}
// 	total++;
// 	cout << "You have answered " << correct << " out of " << total << " questions correct.\n";

// //Begin "Loop"
// 	x = rand()%13;
// 	y = rand()%13;
// 	cout << "What is " << x << "*" << y << "?\n";
// 	cin >> response;
// 	answer = x * y;
// 	if(answer == response){
// //Just Like Misty.
// 		cout << "You're a brilliant genius!\n";
// 		correct++;
// 	}else{
// 		cout << "Not so much.\n";
// 	}
// 	total++;
// 	cout << "You have answered " << correct << " out of " << total << " questions correct.\n";


// //Begin "Loop"
// 	x = rand()%13;
// 	y = rand()%13;
// 	cout << "What is " << x << "*" << y << "?\n";
// 	cin >> response;
// 	answer = x * y;
// 	if(answer == response){
// //Just Like Misty.
// 		cout << "You're a brilliant genius!\n";
// 		correct++;
// 	}else{
// 		cout << "Not so much.\n";
// 	}
// 	total++;
// 	cout << "You have answered " << correct << " out of " << total << " questions correct.\n";

// //Begin "Loop"
// 	x = rand()%13;
// 	y = rand()%13;
// 	cout << "What is " << x << "*" << y << "?\n";
// 	cin >> response;
// 	answer = x * y;
// 	if(answer == response){
// //Just Like Misty.
// 		cout << "You're a brilliant genius!\n";
// 		correct++;
// 	}else{
// 		cout << "Not so much.\n";
// 	}
// 	total++;
// 	cout << "You have answered " << correct << " out of " << total << " questions correct.\n";

// 	return 0;

// }

