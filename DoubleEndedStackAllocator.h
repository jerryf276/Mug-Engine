#pragma once
#include <iostream>
#include <vector>
#include <string>
class DoubleEndedStackAllocator
{
public:
	DoubleEndedStackAllocator(size_t maxSize);
	~DoubleEndedStackAllocator();

	void* allocBottomStack(const std::string& resourceName, size_t size);
	void* allocTopStack(const std::string& resourceName, size_t size);

	bool isDuplicated(const std::string& resourceName);

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

	struct allocationData
	{
		size_t size;
		std::string resourceName;
	};

	std::vector<allocationData> sharedStackAllocations;

protected:

};

