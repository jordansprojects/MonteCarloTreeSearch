/***********************************************************************
 * gamestate.h - abstract class to interface with MCTS 
 * 
 ********************************************************************/
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>

/* Action must be implemented */
struct Action{
};

class Gamestate{
	public :
		virtual void getReward() = 0;
		virtual std::vector<Action> getActions()= 0;		
};

#endif
