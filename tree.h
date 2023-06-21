/****************************************
 * tree.h - defines tree to facilitate a Monte Carlo Tree Search 
 *
 *  "The focus of MCTS is on the analysis of the most promosing moves, expanding the search tree
 *  based on ramdom sampling of the search space."
 * 
 *
 */

#ifndef TREE_H
#define TREE_H

#include <vector> /* to store children pointers */ 
#include <math.h> /* to compute sqrt() */ 


struct TreeNode {
		constexpr static double C = sqrt(2);
		int wins,	 /* number of wins for the node considered after the i-th move*/
		    n,   	 /* number of simulations for the node considered after the i-th move */ 
		    N;   	/* the total number of simulations after the i-th move run 
				   by the parent node of the one conisdered */


		TreeNode(){
			// all values start at zero
			wins = n = N = 0;
		}

		// UCT formula introduced by Levente Kocsis and Csaba Szepesvari in 2006
		double evaluateUCT(){
			// type cast integer values to double
			double N = (double)(this->N);
			double wins = (double) (this->wins);
			double n = (double)(this->n);

			// return value 
			return ( wins / n )  + C * (sqrt(  ( log (N) ) / n ));
		}

};  // end of TreeNode struct 




class Tree {
	public:
		Tree(){}
		void runMCTS(double wins, double totalSimulations){}
		TreeNode root;
		std::vector<TreeNode*> children;
}; // end of Tree class
#endif
