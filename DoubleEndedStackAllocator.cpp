#include "DoubleEndedStackAllocator.h"

DoubleEndedStackAllocator::DoubleEndedStackAllocator(size_t maxSize)
{
	//Allocate the data
	malloc(maxSize);
	bottomStackArray.resize(maxSize);
	topStackArray.resize(maxSize);
	sharedStackSize = maxSize;
}

DoubleEndedStackAllocator::~DoubleEndedStackAllocator()
{
	//Deallocate the data
	free(bottomBase);
	free(topBase);
}

void* DoubleEndedStackAllocator::allocBottomStack(size_t size)
{
	//If someone attempts to allocate more space than is available
	if ((bottomCurrentSize + topCurrentSize) + size > sharedStackSize) {
		std::cout << "Not enough room in the stack! " << std::endl;
		return nullptr;
	}
	bottomCurrentSize += size;
	if (bottomBase == nullptr) {
		bottomBase = new size_t(size);
	}
	bottomHead = new size_t(size);
	bottomStackElements++;
	bottomStackArray[bottomStackElements] = size;
	return nullptr;
}

void* DoubleEndedStackAllocator::allocTopStack(size_t size)
{
	//If someone attempts to allocate more space than is available
	if ((bottomCurrentSize + topCurrentSize) + size > sharedStackSize) {
		std::cout << "Not enough room in the stack! " << std::endl;
		return nullptr;
	}
	topCurrentSize += size;
	if (topBase == nullptr) {
		topBase = new size_t(size);
	}
	topHead = new size_t(size);
	topStackElements++;
	topStackArray[topStackElements] = size;
	return nullptr;
}

void* DoubleEndedStackAllocator::rollBackBottomStack(int dist)
{
	for (int i = 0; i < dist; i++) {
		if (i + 1 > bottomStackElements) {
			std::cout << "There is nothing to deallocate!" << std::endl;
			std::cout << "Rolled back by " << i + 1 << "!" << std::endl;
			return nullptr;
		}
		this->popBottomStack(bottomStackArray[bottomStackElements]);
	}
	std::cout << "Rolled back by " << dist << "!" << std::endl;

	return nullptr;
}

void* DoubleEndedStackAllocator::rollBackTopStack(int dist)
{
	for (int i = 0; i < dist; i++) {
		if (i + 1 > topStackElements) {
			std::cout << "There is nothing to deallocate!" << std::endl;
			std::cout << "Rolled back by " << i + 1 << "!" << std::endl;
			return nullptr;
		}
		this->popTopStack(topStackArray[topStackElements]);
	}
	std::cout << "Rolled back by " << dist << "!" << std::endl;
	return nullptr;
}

void DoubleEndedStackAllocator::clearBottomStack()
{
	free(bottomHead);

	for (int i = 0; i < bottomStackElements; i++) {
		//free(bottomHead);
		bottomCurrentSize -= bottomStackArray[i];
		bottomStackElements--;
	}
	//free(bottomBase);
}

void DoubleEndedStackAllocator::clearTopStack()
{
	free(topHead);
	for (int i = 0; i < topStackElements; i++) {
		//free(topHead);
		topCurrentSize -= topStackArray[i];
		topStackElements--;
	}
	//free(topBase);
}

void* DoubleEndedStackAllocator::popBottomStack(size_t size)
{
	if (bottomCurrentSize < 0) {
		std::cout << "There is nothing to deallocate!" << std::endl;
		return nullptr;
	}

	bottomCurrentSize -= size;
	bottomStackElements--;

	if (bottomStackElements > 0) {
		bottomHead = new size_t(bottomStackArray[bottomStackElements]);
	}

	else if (bottomStackElements == 0) {
		bottomBase = new size_t(bottomStackArray[bottomStackElements]);
		bottomHead = new size_t(bottomStackArray[bottomStackElements]);
	}
	else {
		free(bottomHead);
	}

	return nullptr;

}

void* DoubleEndedStackAllocator::popTopStack(size_t size)
{
	if (topCurrentSize < 0) {
		std::cout << "There is nothing to deallocate!" << std::endl;
		return nullptr;
	}
	topCurrentSize -= size;
	topStackElements--;

	if (topStackElements > 0) {
		topHead = new size_t(topStackArray[topStackElements]);
	}
	else if (topStackElements == 0) {
		topBase = new size_t(topStackArray[topStackElements]);
		topHead = new size_t(topStackArray[topStackElements]);
	}
	else {
		free(topHead);
	}

	return nullptr;
}


