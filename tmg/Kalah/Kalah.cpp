#include <iostream>

// class Kalah: Kalah game main class
class Kalah{

	public static void main() {
	}
	// add code: run the game
	public void gameStart() {
	}
	// add code: the computer makes a move
	public void computerMove() {
	}
	// add code: the player makes a move
	public void playerMove() {
	}
	// add code: check whether the game is over
	public void checkForWin() {
	}

}

// class Gamestate: number of stones in each hole in a certain state
class Gamestate{

	private int* computerHoles;
	private int* playerHoles;
	private int computerKalah;
	private int playerKalah;

}

// class IOactions: input and output during the game
class IOactions{
	
	public void printState(Gamestate Holes){
		cout << "Current state" << endl <<endl;
		cout << "Computer Holes:	6	5	4	3	2	1"<<endl;
		cout << "		";
		for(int i=0;i<6;i++){
			cout << Holes.computerHoles[i] << "	";
		}
		cout  << endl;  
		cout << Holes.computerKalah + "									" + Holes.playerKalah + "\n");  
		cout << "		";
		for(int i=5;i>=0;i--){
			cout << Holes.playerHoles[i] << "	";
		}
		cout << endl;
		cout << "Human Holes:        6       5       4       3       2       1"<<endl<<endl; 
		cout << "State ends" << endl;
	}
	
	public int getHoleNumber(){  // return a hole number from 1~6
		cout << "Please enter the hole number (1/2/3/4/5/6)" <<endl;
		int hole;
		cin >> hole;
		return hole;
	}
	
	public void showGameOver(bool winner){
		if (winner==false) cout << "The winner is the COMPUTER!" <<endl;
		if (winner==true) cout << "The winner is YOU!"<<endl;
	}

	public bool startGameAgain(){
		cout << "Replay the game? (y/n)" << endl;
		char restart;
		cin >> restart;
		if (restart=='y') return true;
		else return false;
	}

	public bool whosFirst(){	// return true if human makes the first move
		cout << "Who makes the first move, human or computer? (h/c)" << endl;
		char turn;
		cin >> turn;
		if (restart=='h') return true;
		else return false;
	}

		
}
