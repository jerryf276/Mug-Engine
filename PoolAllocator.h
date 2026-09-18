#pragma once
#include <stdlib.h>
#include <iostream>
//#include "SingularLinkedList.h"

struct LinkedList {
	/**
	 * When a chunk is free, the `next` contains the
	 * address of the next chunk in a list.
	 *
	 * When it's allocated, this space is used by
	 * the user.
	 */
	LinkedList* next;
};


class PoolAllocator
{
	//Use a linked list to keep track of memory
	//Do not forget to override new and delete operators when making use of a pool allocator!
public:
	PoolAllocator(size_t pChunksPerBlock);

	void* allocate(size_t size);
	void deallocate(void* ptr, size_t size);
private:
	LinkedList * list = nullptr;
	size_t chunksPerBlock;
	size_t chunkSize;

	LinkedList* allocateBlock(size_t chunkSize);

protected:

};
