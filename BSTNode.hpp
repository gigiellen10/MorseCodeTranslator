/* Programmer name: Genevieve Kochel
Date: March 4th, 2024
File purpose: This file contains the class declarations and function prototypes for the BSTNode class */

#pragma once
#include "MorseCodeBST.hpp"

template <class T1, class T2>
class BSTNode {

public:
	/* Constructor and copy constructor */
	BSTNode(T1 newEnglish, T2 newMorse, BSTNode* newpRight = nullptr, BSTNode* newpLeft = nullptr);
	BSTNode(const BSTNode<T1, T2>& copyBSTNode);

	/* overloaded operators */
	BSTNode<T1, T2>& operator= (const BSTNode<T1, T2>& Node);

	/* Setters (non-const) and getters (const) */
	void setmEnglish(const T1& newData);
	void setmMorse(const T2& newData);
	void setmpRight(BSTNode<T1, T2>* newNode);
	void setmpLeft(BSTNode<T1, T2>* newNode);
	
	T1 getmEnglish(void) const;
	T2 getmMorse(void) const;
	BSTNode<T1, T2>* getmpRight(void) const;
	BSTNode<T1, T2>* getmpLeft(void) const;

	/* destructor for node */
	~BSTNode(void);


private:
	T1 mEnglish;
	T2 mMorse;
	BSTNode<T1, T2>* mpRight;
	BSTNode<T1, T2>* mpLeft;

};

template <class T1, class T2>
BSTNode<T1, T2>::BSTNode(T1 newEnglish, T2 newMorse, BSTNode<T1, T2>* newpRight, BSTNode<T1, T2>* newpLeft)
{
	mEnglish = newEnglish; // assuming overloaded '=' operator for the types used for T1 and T2

	mMorse = newMorse;

	mpRight = newpRight;
	mpLeft = newpLeft;

}

template <class T1, class T2>
BSTNode<T1, T2>::BSTNode(const BSTNode<T1, T2>& copyBSTNode)
{
	*this = copyBSTNode; // overloaded '=' operator
}

/* overloaded operators */

template <class T1, class T2>
BSTNode<T1, T2>& BSTNode<T1, T2>::operator= (const BSTNode<T1, T2>& Node)
{
	// overloaded '=' operator for whatever types these will be, assumed char and std::string for this program
	this->mEnglish = Node.mEnglish; 
	this->mMorse = Node.mMorse;
	this->mpRight = Node.mpRight;
	this->mpLeft = Node.mpLeft;

	return *this;
}


/* Setters (non-const) and getters (const) */
template <class T1, class T2>
void BSTNode<T1, T2>::setmEnglish(const T1& newData)
{
	// newData should be an english character here for purposes of program
	mEnglish = newData;
}

template <class T1, class T2>
void BSTNode<T1, T2>::setmMorse(const T2& newData)
{
	// overloaded = operator for type T2
	mMorse = newData;
}

template <class T1, class T2>
void BSTNode<T1, T2>::setmpRight(BSTNode<T1, T2>* newNode)
{
	mpRight = newNode;
}

template <class T1, class T2>
void BSTNode<T1, T2>::setmpLeft(BSTNode<T1, T2>* newNode)
{
	mpLeft = newNode;
}

template <class T1, class T2>
T1 BSTNode<T1, T2>::getmEnglish(void) const
{
	return mEnglish;
}

template <class T1, class T2>
T2 BSTNode<T1, T2>::getmMorse(void) const
{
	return mMorse;
}

template <class T1, class T2>
BSTNode<T1, T2>* BSTNode<T1, T2>::getmpRight(void) const
{
	return mpRight;
}

template <class T1, class T2>
BSTNode<T1, T2>* BSTNode<T1, T2>::getmpLeft(void) const
{
	return mpLeft;
}

template <class T1, class T2>
BSTNode<T1, T2>::~BSTNode()
{
	// allows recursion built into the delete tree function. each delete call will also call destructor for node.
	if (mpLeft != nullptr)
	{
		delete mpLeft;
	}
	if (mpRight != nullptr)
	{
		delete mpRight;
	}

}

