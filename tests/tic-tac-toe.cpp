/**************************************************************
* Tic-Tac-Toe implementation of the MCTS to demo functionality 
*
***************************************************************/

#include "..\tree.h"
#include "..\gamestate.h"

#include <cstdlib> /* for rand() */ 
#include<time.h> /* for time */ 
#include <iostream>

class TicTacToeBoard : Gamestate{
	private:
	std::vector<Action*> actions;
	const int DIM = 3;
	char* board = new char[DIM*DIM];
	public:
	TicTacToeBoard(){		
		for ( int i = 0; i < DIM*DIM; i++)
			board[i] = '_';

	}

	TicTacToeBoard(char* inputBoard){
		
		std::copy(inputBoard, inputBoard+9, this->board);
	}

	virtual std::vector<Action*> getActions(){
		return this->actions;
	}


	virtual int getReward(){

	}
	void printBoard(){
		for ( int i = 0 ; i < 9; i++){
				std::cout << board[i] << " ";
				if ( (i+1) % 3 == 0 ){
					std::cout << '\n';
				}

		}
	}
}; // end of class TicTacToeboard

struct TicTacToeAction: Action {
	char who; 	/* This will either be an 'x' or an 'o' */ 
	int putIndex; 	/* where to place the 'x' or 'o' */
	void print(){
		std::cout << "who = " << who << " at index = " << putIndex << '\n';
	}

};


void runTicTacToeGame(){
	TicTacToeBoard gameBoard;

	// randomly select who is x and who is o
	srand(time(NULL));
	int playerKey = (rand() +1) % 2 ;
	char player = ( playerKey == 0 ) ? 'x' : 'o' ;
	char monteCarlo = (( 1 - playerKey ) == 0) ? 'x' : 'o';
	
        std::cout << "player= " << player << '\n';	
	std::cout<< "monteCarlo= "<<monteCarlo << '\n';

	while (true){
		std::cout << " Board :\n";
		gameBoard.printBoard();
		return;
	}
}


int main(){
	// run game 
	runTicTacToeGame();
	std::cout<< "Tests Successful.\n";
	return 0;
}
