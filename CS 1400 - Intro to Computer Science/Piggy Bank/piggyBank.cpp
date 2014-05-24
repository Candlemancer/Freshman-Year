// Jonathan Petersen
// A01236750
// Piggy Bank Class

#include <iostream>

using namespace std;

class PiggyBank {
public:
	int  getCoins(   );
	int  breakPig(   );
	void addCoins(int);
	void pigState(   );
	 PiggyBank();
	~PiggyBank();

private:
	int  total;
	bool smash;
};

int PiggyBank::getCoins() {
	return total;
}

int PiggyBank::breakPig() {
	smash = true;
	cout << "You smash the bank to the ground!\n";
	cout << "There were " << total << " coins inside!\n";
	return total;
}

void PiggyBank::addCoins(int coins) {
	if(smash != true) total += coins;
}

void PiggyBank::pigState() {
	if (smash ==  true) cout << "The piggy bank is currently broken!\n";
	if (smash == false) cout << "The piggy bank has not been broken.\n";
	if (smash ==  true) cout << "There were " << total << " coins in the bank when it was broken.\n";
	if (smash == false) cout << "There are currently " << total << " coins in the bank.\n";
}

PiggyBank:: PiggyBank() {
	total = 0;
	smash = 0;
};

PiggyBank::~PiggyBank() {
	cout << "The final number of coins was " << total << endl;
};


int main() {

	PiggyBank Piglet;
	PiggyBank Pig;
	Pig.addCoins(2);
	Pig.pigState();
	Piglet.addCoins(5);
	Piglet.breakPig();
	Piglet.addCoins( Pig.getCoins() + 5 );
	Pig.breakPig();
	Piglet.pigState();
	Pig.addCoins(2);

	return 0;

}
