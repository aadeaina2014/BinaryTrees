/*************************************************************************
Florida Institute of Technology
College of Engineering
Electrical and Computer Engineering Department
ECE 2552 : Software Hardware Integration
FileName : main_eulerTour.cpp 
Application Driver for Euler Tour using linked Binary Trees DataStructure
*************************************************************************/

#include "Printexpressiontour.h"
#include <time.h>

using namespace std;
void printHeader(std::string LabName, std::string Date);
int main()
{
	printHeader("Lab 5: Binary Trees", "Date : March 14 2016");
	clock_t time;
	time = clock();
	LinkedBinaryTree myTree;
	myTree.addRoot();
	LinkedBinaryTree::Position myPosition;
	myPosition = myTree.root();

	PrintExpressionTour <string, int> myExpression;

	  ///////////////////////////////////
	 // Create First Half of the tree //
	///////////////////////////////////

	if (myPosition.isRoot())
	{
		*myPosition = "-";  //(1)
		myTree.expandExternal(myPosition);
		myPosition = myPosition.left();

		*myPosition = "/";  //(2)
		myTree.expandExternal(myPosition);
		myPosition = myPosition.left();

		*myPosition = "*";  //(3)
		myTree.expandExternal(myPosition);
		myPosition = myPosition.left();

		*myPosition = "+";  //(4)
		myTree.expandExternal(myPosition);
		myPosition = myPosition.left();

		*myPosition = "3";  //(5)
		myPosition = myPosition.parent();
		myPosition = myPosition.right();
		*myPosition = "1";  //(6)
		myPosition = myPosition.parent();

		myPosition = myPosition.parent();

		myPosition = myPosition.right();
		*myPosition = "3";  //(7)

		myPosition = myPosition.parent();
		myPosition = myPosition.parent();

		myPosition = myPosition.right();
		*myPosition = "+";  //(8)
		myTree.expandExternal(myPosition);

		myPosition = myPosition.left();
		*myPosition = "-";  //(9)

		myTree.expandExternal(myPosition);

		myPosition = myPosition.left();
		*myPosition = "9";  //(10)
		myPosition = myPosition.parent();
		myPosition = myPosition.right();
		*myPosition = "5";  //(11)
		myPosition = myPosition.parent();

		myPosition = myPosition.parent();
		myPosition = myPosition.right();
		*myPosition = "2";  //(12)
		myPosition = myPosition.parent();

		myPosition = myPosition.parent();
		myPosition = myPosition.parent();
	}

	  ///////////////////////////////////
	 // Create Right Half of the tree //
	///////////////////////////////////

	if (myPosition.isRoot())
	{
		myPosition = myPosition.right();
		*myPosition = "+";  //(13)
		myTree.expandExternal(myPosition);
		myPosition = myPosition.left();
		*myPosition = "*";  //(14)

		myTree.expandExternal(myPosition);
		myPosition = myPosition.left();
		*myPosition = "3"; //(15)
		myPosition = myPosition.parent();

		myPosition = myPosition.right();
		*myPosition = "-"; // (16)
		myTree.expandExternal(myPosition);



		myPosition = myPosition.left();
		*myPosition = "7";  //(17)
		myPosition = myPosition.parent();
		myPosition = myPosition.right();
		*myPosition = "4";  //(18)
		myPosition = myPosition.parent();

		myPosition = myPosition.parent();
		myPosition = myPosition.parent();
		myPosition = myPosition.right();

		*myPosition = "6";  //(19)
		myPosition = myPosition.parent();
		myPosition = myPosition.parent();

	}
    


	if (myPosition.isRoot())
	{
		cout << "Tree was successfully created" << endl;
		cout << "This tree has " << myTree.size() << " Nodes" << endl;

	}

	myExpression.initialize(myTree);
	myExpression.execute(myTree);

	time = time - clock();
	cout << "\n Program Execution Time:" << (time / CLOCKS_PER_SEC) << endl;
	system("pause");
	return EXIT_SUCCESS;
}


void printHeader(std::string LabName, std::string Date)
{
	// Header
	cout << "------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                                 Florida Institute of Technology                                          |" << endl;
	cout << "|                                      College of Engineering                                              |" << endl;
	cout << "|                               Electrical and Computer Engineering Department                             |" << endl;
	cout << "|                               ECE 2552 : Software Hardware Integration                                   |" << endl;
	cout << "|                                                                                                          |" << endl;
	cout << "| " << LabName << "                                                                                      |" << endl;
	cout << "| " << Date << "                                                                                     |" << endl;
	cout << "------------------------------------------------------------------------------------------------------------" << endl;

}