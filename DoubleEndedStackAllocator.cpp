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

void* DoubleEndedStackAllocator::allocBottomStack(const std::string& resourceName, size_t size)
{
	if (isDuplicated(resourceName)) {
		return nullptr;
	}

	//If someone attempts to allocate more space than is available
	if ((bottomCurrentSize + topCurrentSize) + size > sharedStackSize) {
		std::cout << "Not enough room in the stack! " << std::endl;
		throw std::runtime_error("Not enough room in the stack! ");
		return nullptr;
	}

	bottomCurrentSize += size;
	if (bottomBase == nullptr) {
		bottomBase = new size_t(size);
	}
	bottomHead = new size_t(size);
	bottomStackElements++;
	sharedStackElements++;
	bottomStackArray[bottomStackElements] = size;
//	bottomStackAllocations[bottomStackElements] = { size, resourceName };
//	sharedStackAllocations[sharedStackElements] = { size, resourceName };
	//std::cout << "Allocated " << size << " bytes to the bottom stack!" << std::endl;
	std::cout << "Allocated " << resourceName << " to the bottom stack!" << " (" << size << " bytes)" << std::endl;
	sharedStackAllocations.push_back({ size, resourceName });
	bottomStackAllocations.push_back({ size, resourceName });
	return nullptr;
}

void* DoubleEndedStackAllocator::allocTopStack(const std::string& resourceName, size_t size)
{
	if (isDuplicated(resourceName)) {
		return nullptr;
	}



	//If someone attempts to allocate more space than is available
	if ((bottomCurrentSize + topCurrentSize) + size > sharedStackSize) {
		std::cout << "Not enough room in the stack! " << std::endl;
		throw std::runtime_error("Not enough room in the stack! ");
		return nullptr;
	}


//	sharedStackAllocations.push_back({ size, resourceName });
	//topStackAllocations.push_back({ size, resourceName });

	topCurrentSize += size;
	if (topBase == nullptr) {
		topBase = new size_t(size);
	}
	topHead = new size_t(size);
	topStackElements++;
	sharedStackElements++;
	topStackArray[topStackElements] = size;
	std::cout << "Allocated " << resourceName << " to the top stack!" << " (" << size << " bytes)" << std::endl;
	//topStackAllocations[topStackElements] = { size, resourceName };
	//sharedStackAllocations[sharedStackElements] = { size, resourceName };
	sharedStackAllocations.push_back({ size, resourceName });
	topStackAllocations.push_back({ size, resourceName });
	return nullptr;
}

bool DoubleEndedStackAllocator::isDuplicated(const std::string& resourceName)
{
	for (const auto& data : sharedStackAllocations) {
		if (data.resourceName == resourceName) {
			std::cout << "Resource already allocated!" << std::endl;
			throw(std::runtime_error("Resource already allocated!"));
			return true;
		}
	}
	return false;
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
	std::cout << "Rolled back bottom stack by " << dist << " memory block(s)!" << std::endl;

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
	std::cout << "Rolled back top stack by " << dist << " memory block(s)!" << std::endl;
	return nullptr;
}

void DoubleEndedStackAllocator::clearBottomStack()
{
	free(bottomHead);

	for (int i = 0; i < bottomStackElements; i++) {
		//free(bottomHead);
		for (int j = 0; j < sharedStackAllocations.size(); j++) {
			if (sharedStackAllocations[j].resourceName == bottomStackAllocations[i].resourceName) {
				bottomStackAllocations.erase(bottomStackAllocations.begin() + i);
				sharedStackAllocations.erase(sharedStackAllocations.begin() + j);

			}
		}
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
		for (int j = 0; j < sharedStackAllocations.size(); j++) {
			if (sharedStackAllocations[j].resourceName == topStackAllocations[i].resourceName) {
				topStackAllocations.erase(topStackAllocations.begin() + i);
				sharedStackAllocations.erase(sharedStackAllocations.begin() + j);
			}
		}
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

	for (int i = 0; i < sharedStackAllocations.size(); i++) {
		for (int j = 0; j < bottomStackAllocations.size(); j++) {
			if (sharedStackAllocations[i].resourceName == bottomStackAllocations[j].resourceName) {
				sharedStackAllocations.erase(sharedStackAllocations.begin() + i);
				bottomStackAllocations.erase(bottomStackAllocations.begin() + j);
			}
		}
	}

	bottomCurrentSize -= size;
	bottomStackElements--;

	std::cout << "Deallocated " << size << " bytes from the bottom stack!" << std::endl;

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

	for (int i = 0; i < sharedStackAllocations.size(); i++) {
		for (int j = 0; j < topStackAllocations.size(); j++) {
			if (sharedStackAllocations[i].resourceName == topStackAllocations[j].resourceName) {
				sharedStackAllocations.erase(sharedStackAllocations.begin() + i);
				topStackAllocations.erase(topStackAllocations.begin() + j);
			}
		}
	}


	std::cout << "Deallocated " << size << " bytes from the top stack!" << std::endl;

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


