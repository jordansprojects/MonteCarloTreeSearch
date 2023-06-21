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


template <typename T>
struct TreeNode {
	
	private:
		std::vector<TreeNode*> children;
		T data;

		constexpr static double C = 1.41421356237; 	// This is approximately the square root of 2 
		int wins,	 								/* number of wins for the node considered after the i-th move*/
		    n,   									/* number of simulations for the node considered after the i-th move */ 
		    N;   									/* the total number of simulations after the i-th move run 
				   									by the parent node of the one conisdered */


		

	public:
		TreeNode(T data){
				// all values start at zero
				wins = n = N = 0;

				// initialize vector 
				children = std::vector<TreeNode<T>*>();
			}
		TreeNode() = delete;

		void addChild(T data){
			children.push_back(new TreeNode(data));
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



template <typename T>
class Tree {
	public:
		TreeNode<T> *root;
		Tree() = delete;
		Tree(T rootData){
			*root =  new TreeNode<T>(rootData);	
		}
		void runMCTS(double wins, double totalSimulations){}
		

		void print(){
			print(this->root);
		}

		~Tree(){
			deleteAll(this->root);
		}

	private:
	   /*  Deletes all leaf nodes
		* referenced GeeksforGeeks for this function
		* https://www.geeksforgeeks.org/remove-all-leaf-nodes-from-a-generic-tree-or-n-ary-tree/
		*/
		TreeNode<T> * deleteAll(TreeNode<T> *root){
			if ( root == nullptr) return nullptr;
			if (root->children.size() == 0){
				delete root;
				return nullptr;
			}
			// loop through all current roots children
			for ( int i = 0; i < root->children.size(); i++){
				TreeNode<T> *child = root->children[i];

				// if this child has no children, delete it
				if(child->children.size() == 0){
					delete child;

					// shift values after deletion
					for ( int j = 0; j < root->children.size() -1; j++){
						root->children[i] = root->children[j+1];
					}
					// pop null pointer from children vector
					root->children.pop_back();
					i--;
				}
			}
			// make recursive call for all children
			for ( int i = 0 ; i < root->children.size(); i++){
				root-> children[i] = deleteAll(root->children[i]);

			}
		}
		

}; // end of Tree class
#endif
