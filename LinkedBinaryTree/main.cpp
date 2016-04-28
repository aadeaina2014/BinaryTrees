/********************************************************************
Florida Institute of Technology
College of Engineering
Electrical and Computer Engineering Department
ECE 2552: Software Hardware Integration
FileName : main.cpp
Code Author :  Ayokunle Ade-Aina [aadeaina2014@my.fit.edu] (c)2016
********************************************************************/
#include"LinkedBinaryTree.h"
//#include "euler.h"
//#include "Printexpressiontour.h"
#include <time.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

const int n = 10;

using namespace std;



int treeData[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };





int i = 0;
queue<LinkedBinaryTree::Position> myQueue;

  ////////////////////////////////////////////////////
 // Iterative Implementation of Tree Ingest Method //
////////////////////////////////////////////////////

LinkedBinaryTree ingestTree(LinkedBinaryTree m)
{
	LinkedBinaryTree::Position temp;
	queue<LinkedBinaryTree::Position>tempQueue;
	if (m.empty())
	{
		m.addRoot();
	}

	temp = m.root();
	
	int treeDepth = 0;
	
	for (int j = 0; j < n; j++)

	{
		
		tempQueue.push(temp);
		*temp = treeData[j];
		
		cout << "Node" << *temp << ":\t"<< j << "th operation, current tree size: " << m.size() << endl;
		
		if (m.size() < n)
		{
		m.expandExternal(temp);//expand node of tree
		tempQueue.push(temp.left()); // push left child to queue
		tempQueue.push(temp.right()); // push right child to queue
	    }
			
		tempQueue.pop();// remove processed node from queue
		temp = tempQueue.front(); // set current node to front of queue
		treeDepth = log2(m.size());// track depth of tree
		
	}
	cout << "current tree size: " << m.size() << endl;
	cout << "current tree Depth: " << treeDepth << endl;
	return m;
}

  ////////////////////////////////////////////////////
 // Recursive Implementation of Tree Ingest Method //
////////////////////////////////////////////////////

LinkedBinaryTree populatetree(LinkedBinaryTree :: Position p , LinkedBinaryTree myTree)
{
	LinkedBinaryTree::Position temp;
	temp  = p;
	
	
		if (i < n)
		{
			*temp = treeData[i]; //write data o node
			if (myTree.size()<n)
			{ 
				myTree.expandExternal(temp);
				myQueue.push(temp.left());
				myQueue.push(temp.right());
			}
			
			if (!myQueue.empty())
			{
				myQueue.pop(); //remove front of queue
				temp = myQueue.front(); // set iterator to front
				populatetree(temp, myTree);	//recursive call
			}
			
			
			i++; //increment count
		}
		else
		{
			return myTree;
		}
}




int main()
{   
	clock_t time;
	time = clock();
	LinkedBinaryTree myTree;
	myTree.addRoot();
	LinkedBinaryTree::Position myPosition;
	myPosition = myTree.root();

	vector <int> myVector(100);

	
	
	/* Iterative Input*/
	myTree = ingestTree( myTree);
	
	

	cout << myTree.size() << endl;
	time = time - clock();
	cout << "\n Program Execution Time:" << (time / CLOCKS_PER_SEC) << endl;
	system("pause");
	return EXIT_SUCCESS;
}

/*Recursive Input*/
//myTree = populatetree(myPosition, myTree);

/*Manual Method* /
/*myTree.expandExternal(myPosition);
myPosition  = myPosition.left();
*myPosition = 1;
myPosition  = myPosition.parent();
myPosition  = myPosition.right();
*myPosition = 2;
myPosition = myPosition.parent();
myPosition = myPosition.left();
cout << " Current Tree Position is node : "<< *myPosition << endl;
*/
