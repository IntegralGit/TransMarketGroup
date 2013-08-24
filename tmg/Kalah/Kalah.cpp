#include <iostream>
#include <string>
#include <math.h>
#include <time.h>
#include <cstdlib>

using namespace std;

void initGame();

class Player {
public:
	int house[7];
	string playerName;

	void sowSeeds(int houseNum, Player &player) {
		int numSeed = house[houseNum];
		house[houseNum] = 0;
		int finalHouse = (houseNum+numSeed) % 7;
		bool tf = (finalHouse != 6 && (isEmpty(finalHouse)) && (!player.isEmpty(finalHouse)));
		for (int i = 1; i <= numSeed; i++) {
			house[(houseNum+i) % 7]++;
		}
		
		if (tf) {
			house[6] += (house[finalHouse] + player.getSeedNum(finalHouse));
			clearSeeds(finalHouse);
			player.clearSeeds(finalHouse); 
		}
	}

	string getName() {
		return playerName;
	}

	bool keepsPlaying(int houseNum) {
		int numSeed = house[houseNum];
		return houseNum+numSeed == 6;
	}

	bool isEmpty(int houseNum) {
		int numSeed = house[houseNum];
		return numSeed == 0;
	}

	void addSeeds(int seedNum, int houseNum) {
		house[houseNum] = seedNum;
	}

	void clearSeeds(int houseNum) {
		house[houseNum] = 0;
	}

	int getSeedNum(int houseNum) {
		return house[houseNum];
	}

	bool isDone() {
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			sum += house[i];
		}
		return sum == 0;
	}

	Player(string name) {
		playerName = name;
	}
};

int main() {

	string name1;
	string name2;
	cout << "\nWhat's Player 1's name?" << endl;
	cin >> name1;
	Player player1(name1);
	for (int i = 0; i < 7; i++) {
		player1.addSeeds(0,i);
	}

	cout << "What's Player 2's name?" << endl;
	cin >> name2;
	Player player2(name2);
	for (int i = 0; i < 7; i++) {
		player2.addSeeds(0,i);
	}

	// Randomly allocate 30 seeds
	int randNum[12];
	srand(time(NULL));
	// int count = 0;
	for (int i = 0; i < 11; i++) {
		randNum[i] = rand() % 30;
	}
	int sum = 0;
	for (int i = 0; i < 11; i++) {
		sum += randNum[i];
	}
	for (int i = 0; i < 11; i++) {
		randNum[i] = 30*randNum[i]/sum;
		randNum[11] = 30-sum;
	}
	int sum2 = 0;
	for (int i = 0; i < 11; i++) {
		sum2 += randNum[i];
	}	
	randNum[11] = 30-sum2;
	for (int i = 0; i < 12; i++) {
		// cout << randNum[i] << endl;
	}
	for (int i = 0; i < 6; i++) {
		player1.addSeeds(randNum[i],i);
	}
	for (int i = 6; i < 12; i++) {
		player2.addSeeds(randNum[i],i-6);
	}

	cout << "Welcome to Kalah, " << player1.getName() << ", " << player2.getName() << "!" << endl;
	
	int turn = 1;
	while (!player1.isDone() && !player2.isDone()) {
		int h1;
		int h2;

		while (turn == 1) {
			h1 = 0;
			cout << "\nThe following is " << player1.getName() << "'s" << " house and store configuration" << endl;
			for (int i = 0; i < 6; i++) {
				cout << "House " << i << ": " << player1.getSeedNum(i) << endl;
			}
			cout << "Store" << ": " << player1.getSeedNum(6) << endl << endl;

			cout << "The following is " << player2.getName() << "'s" << " house and store configuration" << endl;
			for (int i = 0; i < 6; i++) {
				cout << "House " << i << ": " << player2.getSeedNum(i) << endl;
			}
			cout << "Store" << ": " << player2.getSeedNum(6) << endl << endl;

			cout << player1.getName() << "'s turn." << endl;
			
			cout << "What house do you want to sow? (Pick an integer from 0 to 5): ";
			cin >> h1;
			cout << endl;
			while (h1 > 5 || h1 < 0) {
				cout << "What house do you want to sow? (Pick an integer from 0 to 5): ";
				cin >> h1;
				cout << endl;
			}

			
			if (player1.keepsPlaying(h1)) {
				turn = 1;
			} else {
				turn = 2;
			}
			player1.sowSeeds(h1,player2);
		}

		while (turn == 2) {
			h2 = 0;
			cout << "\nThe following is " << player2.getName() << "'s" << " house and store configuration" << endl;
			for (int i = 0; i < 6; i++) {
				cout << "House " << i << ": " << player2.getSeedNum(i) << endl;
			}
			cout << "Store" << ": " << player2.getSeedNum(6) << endl << endl;

			cout << "The following is " << player1.getName() << "'s" << " house and store configuration" << endl;
			for (int i = 0; i < 6; i++) {
				cout << "House " << i << ": " << player1.getSeedNum(i) << endl;
			}
			cout << "Store" << ": " << player1.getSeedNum(6) << endl << endl;

			cout << player2.getName() << "'s turn." << endl;

			cout << "What house do you want to sow? (Pick an integer from 0 to 5): ";
			cin >> h2;
			cout << endl;
			while (h2 > 5 || h2 < 0) {
				cout << "What house do you want to sow? (Pick an integer from 0 to 5): ";
				cin >> h2;
				cout << endl;
			}
			
			if (player2.keepsPlaying(h2)) {
				turn = 2;
			} else {
				turn = 1;
			}
			player2.sowSeeds(h2,player1);
		}

	}

	if (player1.getSeedNum(6) == player2.getSeedNum(6)) {
		cout << "It's a tie!" << endl;
	}

	else if (player1.getSeedNum(6) > player2.getSeedNum(6)) {
		cout << "Congratulations, " << player1.getName() << " wins!" << endl;
	}

	else {
		cout << "Congratulations, " << player2.getName() << " wins!" << endl;
	}

	return 0;
}
