#include <iostream>
#include <iomanip>
using namespace std;

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