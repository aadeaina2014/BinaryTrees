/********************************************************************
Florida Institute of Technology
College of Engineering
Electrical and Computer Engineering Department
ECE 2552: Software Hardware Integration
FileName : PrintExpressionTour.h
Code Author :  Ayokunle Ade-Aina [aadeaina2014@my.fit.edu] (c)2016
********************************************************************/

# ifndef PRINTEXPRESSIONTOUR_H_
# define PRINTEXPRESSIONTOUR_H_
# include "euler.h"
#include <iostream>
template <typename E, typename R>
class PrintExpressionTour : public EulerTour<E, R> {
protected: // ...same type name shortcuts as in EvaluateExpressionTour 
public:
	void execute(const BinaryTree& T) {		// execute the tour
		initialize(T);
		cout << "Expression: "; eulerTour(T.root()); cout << endl;
	}
protected:					// leaf: print value
	virtual void visitExternal(const Position& p, Result& r) const
	{
		LinkedBinaryTree::Position puax = p;
		cout << *puax;
	}
	// left: open new expression
	virtual void visitLeft(const Position& p, Result& r) const
	{
		cout << "(";
	}
	// below: print operator
	virtual void visitBelow(const Position& p, Result& r) const
	{
		LinkedBinaryTree::Position puax = p;
		cout << *puax;
	}
	// right: close expression
	virtual void visitRight(const Position& p, Result& r) const
	{
		cout << ")";
	}
};
#endif
