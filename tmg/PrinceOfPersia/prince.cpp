#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include <cstdlib> // rand, srand, system
#include <ctime>
// clock, clock_t, CLOCKS_PER_SEC, time
using namespace std;
/* Probability of turning at each step. */
const double kTurnRate = 0.5;
/* Time to wait, in seconds, between frames. */
const double kWaitTime = 2;
/* Number of food pellets that must be eaten to win. */
const int kMaxFood = 20;
/* Constants for the different tile types. */
const char kNoTile    = ' ';
const char kEmptyTile = '.';
const char kWallTile = 'o';
const char kFoodTile = '2';
const char kSnakeTile = '1';
/* The string used to clear the display before printing the game board. Windows
* systems should use "CLS", Mac OS X or Linux users should use "clear."
*/
const string kClearCommand = "clear";
/* A struct encoding a point in a two-dimensional grid. */
struct pointT
{
int row, col;
};
/* A struct containing relevant game information. */
struct gameT
{
vector<string> world; // The playing field
int numRows , numCols; // Size of the playing field
//deque<pointT> snake;
pointT prince;
int dx, dy;
int levels;
int numEaten;

};
// The snake body
// The snake direction
// How much food we've eaten.
/* Reads a line of text from the user. */

gameT init()
{
gameT p;
p.dx = 1;
p.dy = 0;
p.levels = 3;
p.numRows = 3;
p.numCols =3;

}

string GetLine()
{
string result;
getline(cin, result);
return result;
}
/* A helper function constructing a point at a given position. */
pointT MakePoint(int row, int col)
{
pointT result;
result.row = row;
result.col = col;
return result;
}

bool RandomChance(double probability)
{
return (rand() / (RAND_MAX + 1.0)) < probability;
}
/* Places a piece of food randomly on the board.
* is some free space remaining.
*/
void PlaceFood(gameT& game)
{
while(true)
{
int row = rand() % game.numRows;
int col = rand() % game.numCols;

/* If there the specified position is empty, place the food there. */
/*if(game.world[row][col] == kEmptyTile)
{
game.world[row][col] = kFoodTile;
return;     /* Returns the next position occupied by the head if the snake is moving
* in the direction dx, dy.
*/


}
}
/* Clears the display and prints the game board. */
void PrintWorld(vector<gameT>& game)
{
/* Use a system call to clear the display. */
system(kClearCommand.c_str());
/* Print each row. */

for(int i = 0   ; i < game.size(); ++i)
for(int j = 0; j < game[i].world.size(); ++j)//because we push the front() into function
{
    cout<<"i "<<i<<"---j "<<j <<" ";
    cout << game.at(i).world[j] << endl;
    }


//cout << "Food eaten: " << game.numEaten << endl;
cout << "Which level: " << game.front().levels   << endl;
cout << "dx: (" << game.front().dx <<")--- dy ("<<game.front().dy <<") "<< endl;

}

void LoadWorld(vector<gameT>& core, ifstream& input)
{
/* Read in the number of rows and columns. */
gameT game;
input >> game.numRows >> game.numCols;
game.world.resize(game.numRows);

gameT slave;

/* Read in the starting location. */
input >> game.dx >> game.dy;

/* Because we're going to be using getline() to read in the world
* data, we need to make sure that we consume the newline character
* at the end of the line containing the input data. We'll use
* getline() to handle this. See game.numRowsthe chapter on streams for why
* this is necessary.
*/
string dummy;
getline(input, dummy);
/* Read in the rows. */
int x = 0;
for(int row = 0; row < game.numRows; ++row)
{
string dd;
getline(input, dd);

if(!dd.empty())
{
game.world[row] = dd;


}else{
     //core.pop_back()
     game.numEaten = 0;
     core.push_back(game);
     core.pop_back();


}


/* Check to see if the * character (snake start position)
* is in this line. If so, make the snake.
*/
int col = game.world[row].find('1');
if(col != string::npos)
game.prince = MakePoint(row,col);


/* Set numEaten to zero - this needs to get done somewhere! */
}
    core.push_back(game);


}






bool InWorld(pointT& pt, gameT & game)
{
return pt.col >= 0 && pt.row >= 0 && pt.col < game.numCols && pt.row < game.numRows;
}

pointT GetNextPosition(vector<gameT>& game, int dx, int dy)
{
/* Get the head. */
pointT nextSpot = game.front().prince;
/* Update it. */
nextSpot.col += dx;
nextSpot.row += dy;
return nextSpot;
}


bool Crashed(pointT head, vector<gameT>& game)
{
/* We crashed if the head is out of bounds, on a wall, or on another
* snake piece.
*/


return !InWorld(head, game.front()) || game.front().world[head.row][head.col] == kWallTile || game.front().world[head.row][head.col] == kSnakeTile || game.front().world[head.row][head.col] == kNoTile;

}

void checkForCol(vector<gameT> & core)
{

gameT game = core.front();
pointT nextSpot = GetNextPosition(core, game.dx, game.dy);

{


        bool isTile = (game.world[nextSpot.row][nextSpot.col] == kEmptyTile);
        if (isTile){

             bool under = (game.world[nextSpot.row + 5 ][nextSpot.col] == kEmptyTile);
             if(under){
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n "<< nextSpot.row + 5 <<" --- "<<nextSpot.col<< " under "<<under<<"\n";
                //game.world[2][game.prince.col] = kSnakeTile;
                /* Push new head. */
                game.prince.row = 1;
                game.prince.col = 0;

                for(int i = 0   ; i < core.size(); ++i)
                for(int j = 0; j < core[i].world.size(); ++j)//because we push the front() into function
                {
                    cout<<"i "<<i<<"---j "<<j <<" ";
                    cout << core.at(i).world[j] << endl;
                    }

             }

        }





}

}


void PerformAI(vector<gameT>& game)
{
/* Look where we're going to be next step. */
pointT nextSpot = GetNextPosition(game, game.front().dx, game.front().dy);
//pointT nextnextSpot = GetNextPosition(game, nextSpot.row, nextSpot.col);//we want to break the wall

/* If this crashes us or we just feel like turning, turn. */

if(Crashed(nextSpot, game) || RandomChance(kTurnRate))
{




/* Compute what direction we'd be facing if we turned left or
* right. From linear algebra we have the following:
*
* For a left turn:
* |x'|
|0 -1||x| --> x' = -y
* |y'| = |1 0||y| --> y' = x
*
* For a right turn:
* |x'|
|0 1||x| --> x' = y
* |y'| = |-1 0||y| --> y' = -x
*/
int leftDx = -game.front().dy;
int leftDy = game.front().dx;
int rightDx = game.front().dy;
int rightDy = -game.front().dx;

/* Check if turning left or right will cause us to crash. */
bool canLeft = !Crashed(GetNextPosition(game, leftDx, leftDy), game);
bool canRight = !Crashed(GetNextPosition(game, rightDx, rightDy), game);

/* Now determine which direction to turn based on what direction
* we're facing. If we can choose either direction, pick one
* randomly. If we can't turn, don't.
*/
  /*  bool isWall;
    bool isEmpty;
    isWall = (game.world[nextSpot.row][nextSpot.col] == kWallTile); //break wall if nothing on other side
    isEmpty = (game.world[nextnextSpot.row][nextnextSpot.col] == kNoTile);
*/

    bool willTurnLeft;

    if(!canLeft && !canRight)
    return;

    else if(canLeft && !canRight)
    willTurnLeft = true;
    else if(!canLeft && canRight)
    willTurnLeft = false;
    else
    willTurnLeft = RandomChance(0.5);



    game.front().dx = willTurnLeft? leftDx : rightDx;
    game.front().dy = willTurnLeft? leftDy : rightDy;




    //game.world[game.dx][game.dy] = kEmptyTile;


}
}
bool MoveSnake(vector<gameT>& game)
{
/* Compute new head. */
pointT nextSpot = GetNextPosition(game, game.front().dx, game.front().dy);
/* Check for dead. */
if(Crashed(nextSpot, game))
 return false;

/* Remember whether we just ate food. */
bool isFood = (game.front().world[nextSpot.row][nextSpot.col] == kFoodTile);
//bool noColUnder = (game.world[underSpot.row][underSpot.col] == kWallTile)

checkForCol(game);

/* Update the display. */
game.front().world[game.front().prince.row][game.front().prince.col] = kEmptyTile;
game.front().world[nextSpot.row][nextSpot.col] = kSnakeTile;
/* Push new head. */
game.front().prince = nextSpot;



/* Update the display. *//*
game.front().world[game.front().prince.row][game.front().prince.col] = kEmptyTile;
game.front().world[nextSpot.row][nextSpot.col] = kSnakeTile;
*//* Push new head. *//*
game.front().prince = nextSpot;*/

/* If we got food, pick a new spot and don't remove the tail. This causes us
* to extend by one spot.
*/
if(isFood)
{
//PlaceFood(game);
++game.front().numEaten;
}

return true;
}
void Pause()
{
clock_t start = clock();
while(static_cast<double>(clock() - start) / CLOCKS_PER_SEC < kWaitTime);
}
/* Displays the result of the game. */
void DisplayResult(vector<gameT>& game)
{
PrintWorld(game);
if(game.front().numEaten == kMaxFood)
cout << "Yay! Saved Princess" << endl;
else
cout << "Oh no! Crashed !" << endl;
}
void OpenUserFile(ifstream& input)
{
while(true)
{
cout << "Enter level file: ";
input.open(GetLine().c_str());
if(!input.fail()) return;
cout << "Sorry, I can't open that file." << endl;
input.clear();
}
}
/* Initializes the game and loads the level file. */
void InitializeGame(vector<gameT>& game)
{
/* Seed the randomizer. */
srand(static_cast<int>(time(NULL)));
ifstream input;
OpenUserFile(input);
LoadWorld(game, input);
}
/* Runs the simulation and displays the result. */
void RunSimulation(vector<gameT> & game)
{
/* Keep looping while we haven't eaten too much. */
while(game.front().numEaten < kMaxFood)
{
PrintWorld(game);
PerformAI(game);
/* Move the snake and abort if we crashed. */
if(!MoveSnake(game))
break;//destroyWall
Pause();
}
DisplayResult(game);
}
int main()
{
vector<gameT> game;
//gameT game;
InitializeGame(game);
RunSimulation(game);
return 0;
}






