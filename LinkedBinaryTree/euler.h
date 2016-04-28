/********************************************************************
/********************************************************************
Florida Institute of Technology
College of Engineering
Electrical and Computer Engineering Department
ECE 2552: Software Hardware Integration
FileName : euler.h
Code Author :  Ayokunle Ade-Aina [aadeaina2014@my.fit.edu] (c)2016
********************************************************************/
# ifndef EULER_H_
# define EULER_H_

#include "LinkedBinaryTree.h"

template <typename E, typename R>		// element and result types
class EulerTour {				// a template for Euler tour
protected:
	struct Result {				// stores tour results
		R leftResult;				// result from left subtree
		R rightResult;				// result from right subtree
		R finalResult; 				// combined result
	};
	typedef LinkedBinaryTree  BinaryTree;		// the tree
	typedef typename BinaryTree::Position Position; // a position in the tree
protected:					// data member
	const BinaryTree* tree;			// pointer to the tree
public:
	void initialize(const BinaryTree& T) 	// initialize
	{
		tree = &T;
	}
protected:					// local utilities
	int eulerTour(const Position& p) const;	// perform the Euler tour
	// functions given by subclasses
	virtual void visitExternal(const Position& p, Result& r) const {}
	virtual void visitLeft(const Position& p, Result& r) const {}
	virtual void visitBelow(const Position& p, Result& r) const {}
	virtual void visitRight(const Position& p, Result& r) const {}
	Result initResult() const { return Result(); }
	int result(const Result& r) const { return r.finalResult; }
};


template <typename E, typename R>		// do the tour
int EulerTour<E, R>::eulerTour(const Position& p) const {
	Result r = initResult();
	if (p.isExternal()) {			// external node
		visitExternal(p, r);
	}
	else {					// internal node
		visitLeft(p, r);
		r.leftResult = eulerTour(p.left());	// recurse on left
		visitBelow(p, r);
		r.rightResult = eulerTour(p.right());	// recurse on right
		visitRight(p, r);
	}
	return result(r);
}

#endif
