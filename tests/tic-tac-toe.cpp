/**************************************************************
* Tic-Tac-Toe implementation of the MCTS to demo functionality 
*
***************************************************************/

#include "..\tree.h"
#include "..\gamestate.h"

#include <iostream>

class TicTacToeBoard : Gamestate{
	private:
	std::vector<Action*> actions;
	char* board = new char[DIM*DIM];
	const int DIM = 3;
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
	char who; /* This will either be an 'x' or an 'o' */ 
	int putIndex; /*where to place the 'x' or 'o' */
	void print(){
	}

};

int main(){


	TicTacToeBoard b;
	b.printBoard();

	std::cout<< "Tests Successful.\n";
	return 0;
}
