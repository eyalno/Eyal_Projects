#include <vector>

using namespace std;
class Node{

public:
	Node(const int num):num(num),left(NULL),right(NULL){}
	// ~Node() no need
	int getData()const {return num;}
	Node * getLeft(){return left;}  //is it the correct design **
	Node * getRight(){return right;}


	int num;
	Node * left;
	Node * right;
};

//Binary tree
//pre order set every node reach 
//inorder Sorted down... up right  left  
//post order down ... not up down  


//post order the comparison on the way up 

int treeHeightP(Node* node)
{
	if (node ==  NULL)
		return 0;
	else
	{
		int leftHeight  = treeHeightP(node->getLeft());
		int rightHeight  = treeHeightP(node->getRight());

		if (leftHeight > rightHeight)
			return leftHeight + 1;
		else
			return rightHeight + 1;

	}
}

// design if funcion arg is ref i can assume is not null
// for reference we ask before the next recursive step if null
int treeHeightR(Node& node)
{
	int leftHeight = 0;
	int rightHeight  = 0;
	
	if (node.getRight() !=  NULL)
		rightHeight = treeHeightR(*(node.getRight()));
	
	if (node.getLeft() !=  NULL)
		leftHeight = treeHeightR(*(node.getLeft()));

	if (leftHeight > rightHeight)
		return leftHeight + 1;
	else
		return rightHeight + 1;
}

//same as tree height but with incresing vector
//copy vector
vector<int> longestPath(Node * node)
{
	if (node ==  NULL)
	{
		vector<int> a;//stack vector
		return a; 
	}
	else
	{
		vector<int> leftVector  = longestPath(node->getLeft());
		vector<int> rightVector  = longestPath(node->getRight());
		
		if (leftVector.size() > rightVector.size())
		{
			leftVector.push_back(node->getData());
			return leftVector ;
		}
		else
		{
			rightVector.push_back(node->getData());
			return rightVector ;
		}
	}
}


vector<int> & longestPathRef(Node * node)
{
	if (node ==  NULL)
	{
		vector<int> * myVec = new vector<int>;//dynamic vector and return *
		return *myVec; 
	}
	else
	{
		vector<int> & leftVector  = longestPathRef(node->getLeft());
		vector<int> & rightVector = longestPathRef(node->getRight());
		
		if (leftVector.size() > rightVector.size())
		{
			leftVector.push_back(node->getData());
			delete &rightVector;
			return leftVector ;
		}
		else
		{
			rightVector.push_back(node->getData());
			delete &leftVector;
			return rightVector;
		}
	}
}



vector<int> * longestPathPtr(Node * node)
{
	if (node ==  NULL)
	{
		vector<int> * myVec= new vector<int>;//dynamic vector and return *
		return myVec; 
	}
	else
	{
		vector<int> * leftVector  = longestPathPtr(node->getLeft());
		vector<int> * rightVector = longestPathPtr(node->getRight());
		
		if (leftVector->size() > rightVector->size())
		{
			leftVector->push_back(node->getData());
			delete rightVector;
			return leftVector ;
		}
		else
		{
			rightVector->push_back(node->getData());
			delete leftVector;
			return rightVector;
		}
	}
}