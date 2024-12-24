#pragma once
#include <iostream>
#include <vector>
class DoubleEndedStackAllocator
{
public:
	DoubleEndedStackAllocator(size_t maxSize);
	~DoubleEndedStackAllocator();

	void* allocBottomStack(size_t size);
	void* allocTopStack(size_t size);

	void* rollBackBottomStack(int dist);
	void* rollBackTopStack(int dist);

	void clearBottomStack();
	void clearTopStack();

	void* popBottomStack(size_t size);
	void* popTopStack(size_t size);


private:
	void* bottomHead;
	void* bottomBase;
	void* topHead;
	void* topBase;

	//int bottomStackSize;
	//int topStackSize;
	int sharedStackSize;
	int bottomCurrentSize = 0;
	int topCurrentSize = 0;
	int sharedCurrentSize = 0;

	int bottomStackElements = -1;
	int topStackElements = -1;

	std::vector<int> bottomStackArray;
	std::vector<int> topStackArray;

protected:

};

