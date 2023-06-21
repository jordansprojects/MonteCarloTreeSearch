/***********************************************************************
 * gamestate.h - abstract class to interface with MCTS 
 * 
 ********************************************************************/
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>

/* Action must be implemented */
struct Action{
	virtual void print() = 0;	
	
};

class Gamestate{
	public :
	 
	    /* reward is only calculated for terminal states*/ 
		virtual int getReward() = 0;
		virtual std::vector<Action*> getActions()= 0;		
};

#endif
