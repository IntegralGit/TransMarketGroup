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
const double kWaitTime = 0.5;
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
int numRows, numCols; // Size of the playing field
deque<pointT> snake;
int dx, dy;
int numEaten;

};
// The snake body
// The snake direction
// How much food we've eaten.
/* Reads a line of text from the user. */
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
if(game.world[row][col] == kEmptyTile)
{
game.world[row][col] = kFoodTile;
return;
}
}
}
/* Clears the display and prints the game board. */
void PrintWorld(gameT& game)
{
/* Use a system call to clear the display. */
system(kClearCommand.c_str());
/* Print each row. */
for(int i = 0; i < game.world.size(); ++i)
cout << game.world[i] << endl;
cout << "Food eaten: " << game.numEaten << endl;
}

void LoadWorld(gameT& game, ifstream& input)
{
/* Read in the number of rows and columns. */
input >> game.numRows >> game.numCols;
game.world.resize(game.numRows);
/* Read in the starting location. */
input >> game.dx >> game.dy;
/* Because we're going to be using getline() to read in the world
* data, we need to make sure that we consume the newline character
* at the end of the line containing the input data. We'll use
* getline() to handle this. See the chapter on streams for why
* this is necessary.
*/
string dummy;
getline(input, dummy);
/* Read in the rows. */
for(int row = 0; row < game.numRows; ++row)
{
getline(input, game.world[row]);
/* Check to see if the * character (snake start position)
* is in this line. If so, make the snake.
*/
int col = game.world[row].find('1');
if(col != string::npos)
game.snake.push_back(MakePoint(row, col));
}
/* Set numEaten to zero - this needs to get done somewhere! */
game.numEaten = 0;
}

bool InWorld(pointT& pt, gameT& game)
{
return pt.col >= 0 &&
pt.row >= 0 &&
pt.col < game.numCols &&
pt.row < game.numRows;
}

bool Crashed(pointT head, gameT& game)
{
/* We crashed if the head is out of bounds, on a wall, or on another
* snake piece.
*/


return !InWorld(head, game) ||
game.world[head.row][head.col] == kSnakeTile /*||
game.world[head.row][head.col] == kWallTile*/  || game.world[head.row][head.col] == kNoTile;
}
/* Returns the next position occupied by the head if the snake is moving
* in the direction dx, dy.
*/
pointT GetNextPosition(gameT& game, int dx, int dy)
{
/* Get the head. */
pointT nextSpot = game.snake.front();
/* Update it. */
nextSpot.col += dx;
nextSpot.row += dy;
return nextSpot;
}

/*void checkWall(gameT& game)
{
int leftDx = -game.dy;
int leftDy = game.dx;
int rightDx = game.dy;
int rightDy = -game.dx;

pointT nextSpot = GetNextPosition(game,game.dx,game.dy);
//pointT lookOver = GetNextPosition(game,nextSpot.row,nextSpot.col);
bool isWall = game.world[nextSpot.row][nextSpot.col] == kWallTile; //checks to see if there is a wall
//bool clearPath = game.world[lookOver.row][lookOver.col] == kEmptyTile; //checks to see if there is nothing on other side of wall
if(isWall)
{
    game.world[game.snake.front().row][game.snake.front().col] = kEmptyTile;
    game.dx = leftDx;
    game.dy = rightDy;

    *//*game.dx = nextSpot.row;
    cout<<game.dx;
    game.dy = nextSpot.col;
    cout<<game.dy;*//*
    //game.snake.push_front(nextSpot);

}
}*/


void PerformAI(gameT& game)
{
/* Look where we're going to be next step. */
pointT nextSpot = GetNextPosition(game, game.dx, game.dy);
pointT nextnextSpot = GetNextPosition(game, nextSpot.row, nextSpot.col);//we want to break the wall

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
int leftDx = -game.dy;
int leftDy = game.dx;
int rightDx = game.dy;
int rightDy = -game.dx;

/* Check if turning left or right will cause us to crash. */
bool canLeft = !Crashed(GetNextPosition(game, leftDx, leftDy), game);
bool canRight = !Crashed(GetNextPosition(game, rightDx, rightDy), game);
/* Now determine which direction to turn based on what direction
* we're facing. If we can choose either direction, pick one
* randomly. If we can't turn, don't.
*/
    bool isWall;
    bool isEmpty;
    isWall = (game.world[nextSpot.row][nextSpot.col] == kWallTile); //break wall if nothing on other side
    //isEmpty = (game.world[nextnextSpot.row][nextnextSpot.col] == kEmptyTile);


    //if not wall left and right go down
    //



    //bool isWall = game.world[nextSpot.row][nextSpot.col] == kWallTile;
    if (isWall){
        if(game.world[nextnextSpot.row][nextnextSpot.col] == kEmptyTile){
        game.world[nextSpot.row][nextSpot.col] = kEmptyTile;
        game.world[nextSpot.row][nextSpot.col] = kSnakeTile;
        /* Push new head. */
        game.snake.push_front(nextSpot);
        game.world[game.snake.back().row][game.snake.back().col] = kEmptyTile;
        game.snake.pop_back();


        //game.dx += 1;// : rightDx;
        //game.dy = rightDy;// : rightDy;
        }
    }


/*
bool willTurnLeft;

if(!canLeft && !canRight)
return;

else if(canLeft && !canRight)
willTurnLeft = true;
else if(!canLeft && canRight)
willTurnLeft = false;
else
willTurnLeft = RandomChance(0.5);


*/
/* Based on the direction, turn appropriately. *//*


game.dx = willTurnLeft? leftDx : rightDx;
game.dy = willTurnLeft? leftDy : rightDy;

*/


}
}
bool MoveSnake(gameT& game)
{
/* Compute new head. */
pointT nextSpot = GetNextPosition(game, game.dx, game.dy);
/* Check for dead. */
if(Crashed(nextSpot, game))
 return false;

/* Remember whether we just ate food. */
bool isFood = (game.world[nextSpot.row][nextSpot.col] == kFoodTile);
/* Update the display. */
game.world[nextSpot.row][nextSpot.col] = kSnakeTile;
/* Push new head. */
game.snake.push_front(nextSpot);




/* If we got food, pick a new spot and don't remove the tail. This causes us
* to extend by one spot.
*/
if(isFood)
{
PlaceFood(game);
++game.numEaten;

}
else
{
/* Clear the tail and remove it from the snake. */
game.world[game.snake.back().row][game.snake.back().col] = kEmptyTile;
game.snake.pop_back();
}
return true;
}
void Pause()
{
clock_t start = clock();
while(static_cast<double>(clock() - start) / CLOCKS_PER_SEC < kWaitTime);
}
/* Displays the result of the game. */
void DisplayResult(gameT& game)
{
PrintWorld(game);
if(game.numEaten == kMaxFood)
cout << "Yay! The snake won!" << endl;
else
cout << "Oh no! The snake crashed!" << endl;
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
void InitializeGame(gameT& game)
{
/* Seed the randomizer. */
srand(static_cast<int>(time(NULL)));
ifstream input;
OpenUserFile(input);
LoadWorld(game, input);
}
/* Runs the simulation and displays the result. */
void RunSimulation(gameT& game)
{
/* Keep looping while we haven't eaten too much. */
while(game.numEaten < kMaxFood)
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
gameT game;
InitializeGame(game);
RunSimulation(game);
return 0;
}






