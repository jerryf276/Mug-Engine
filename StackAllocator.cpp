#include "StackAllocator.h"
#include <stdlib.h>

StackAllocator::StackAllocator(size_t Max_Size)
{
	//Allocate the data
	malloc(Max_Size);
	stackArray.resize(Max_Size);
	stackSize = Max_Size;
}

StackAllocator::~StackAllocator()
{
	//Deallocate the data
	free(Base);
}

void* StackAllocator::Alloc(size_t size)
{
	//If someone attempts to allocate more space than is available
	if (currentSize + size > stackSize) {
		std::cout << "Not enough room in the stack! " << std::endl;
		return nullptr;
	}

	currentSize += size;

	if (Base == nullptr) {
		Base = new size_t(size);
	}

	Head = new size_t(size);
	stackElements++;
	stackArray[stackElements] = size;

	return nullptr;
}

void* StackAllocator::Pop(size_t size)
{
	if (currentSize < 0) {
		std::cout << "There is nothing to deallocate!" << std::endl;
		return nullptr;
	}
	currentSize -= size;
	//The data is technically still there when popping in a stack allocator, therefore we don't pop any values in our vector.
	//stackArray.pop_back();
	stackElements--;

	if (stackElements > 0) {
		Head = new size_t(stackArray[stackElements]);
	}
	else if (stackElements == 0) {
		Base = new size_t(stackArray[stackElements]);
		Head = new size_t(stackArray[stackElements]);
	}
	else {
		free(Head);
		//	free(Base);
	}


	return nullptr;
}

void* StackAllocator::RollBack(int dist)
{
	for (int i = 0; i < dist; ++i) {
		if (i + 1 > stackElements) {
			//If we are rolling too far back
			std::cout << "There is nothing to rollback!" << std::endl;
			std::cout << "Rolled back by " << i + 1 << "!" << std::endl;
			return nullptr;
		}
		//Run the pop function 
		this->Pop(stackArray[stackElements]);
	}
	std::cout << "Rolled back by " << dist << "!" << std::endl;
	return nullptr;
}


void StackAllocator::Clear()
{
	//I'm not sure if I am supposed to free the head? I'd like to hear why I would/wouldn't in the feedback if possible?
	free(Head);
	//free(Base);

	for (int i = 0; i < stackElements; ++i) {
		currentSize -= stackArray[i];
		//The data is technically still there when popping in a stack allocator, therefore we don't pop any values in our vector.
	//	stackArray.pop_back();
		stackElements--;
	}
}
