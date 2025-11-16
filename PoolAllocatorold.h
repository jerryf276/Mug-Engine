#pragma once
#include <iostream>
struct Chunk {
	/* When a chunk is free, the `next` contains the address of the next chunk in a list. When it's allocated, this space is used by the user. */
	Chunk* next;
	Chunk* prev;
};

class PoolAllocatorold
	//Features:
		//Parametrized by number of chunks per block
		//Keeps track of the allocation pointer
		//Bump-allocates chunks
		//Requests a new larger block when needed

{
public:
	PoolAllocatorold(size_t chunksPerBlock)
		: mChunksPerBlock(chunksPerBlock) {
	}

	void* allocate(size_t size);
	void deallocate(void* chunk, size_t size);

private:
	//Number of chunks per larger block.
	size_t mChunksPerBlock;

	//Allocation pointer.
	Chunk* mAlloc = nullptr;


	//Allocates a larger block (pool) for chunks.
	Chunk* allocateBlock(size_t size);

protected:

};

