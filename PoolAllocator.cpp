#include "PoolAllocator.h"


PoolAllocator::PoolAllocator(size_t pChunksPerBlock)
{
	chunksPerBlock = pChunksPerBlock;
}


void* PoolAllocator::allocate(size_t size)
{
	//No chunks left in the linked list block, or the linked list does not exist yet. This will create a new block for the memory pool, which passes in the chunk size
	if (list == nullptr) {
		list = allocateBlock(size);
	}

	std::cout << "Chunk size is: " << size << std::endl;

	LinkedList* freeChunk = list;

	list = list->next;

	return freeChunk;
}


//Puts the newly deleted chunk into the front of the free chunks list
void PoolAllocator::deallocate(void* ptr, size_t size)
{
	reinterpret_cast<LinkedList*>(ptr)->next = list;

	//the allocation pointer is now set to the new returned free chunk:

	list = reinterpret_cast<LinkedList*>(ptr);
}

LinkedList* PoolAllocator::allocateBlock(size_t chunkSize)
{
	std::cout << "Allocating memory block! (" << chunksPerBlock << " chunks)" << std::endl;
	size_t blockSize = chunksPerBlock * chunkSize;
	//The first chunk (item in linked list) of the new block
	LinkedList* blockStart = reinterpret_cast<LinkedList*>(malloc(blockSize));

	//Once block is allocated, we need to chain all the chunks (all linked list elements) in the block

	LinkedList* chunk = blockStart;

	for (int i = 0; i < chunksPerBlock; i++) {
		chunk->next = reinterpret_cast<LinkedList*>(reinterpret_cast<char*>(chunk) + chunkSize);
		chunk = chunk->next;
	}

	return blockStart;
}
