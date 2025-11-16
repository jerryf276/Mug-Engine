#include "PoolAllocatorold.h"

void* PoolAllocatorold::allocate(size_t size)
{

    //No chunks left in the current block, or no any block exists yet. Allocate a new one, passing the chunk size:
    if (mAlloc == nullptr) {
        mAlloc = allocateBlock(size);
    }

    //The return value is the current position of the allocation pointer:
    Chunk* freeChunk = mAlloc;

    //Advance (bump) the allocation pointer to the next chunk.
    //When no chunks left, the `mAlloc` will be set to `nullptr`, and this will cause allocation of a new block on the next request:
    mAlloc->prev = mAlloc;
	mAlloc = mAlloc->next;
    return freeChunk;

   // return nullptr;
}

void PoolAllocatorold::deallocate(void* chunk, size_t size)
{

    reinterpret_cast<Chunk*>(chunk)->next = mAlloc;

    //And the allocation pointer is now set to the returned (free) chunk:
	mAlloc = reinterpret_cast<Chunk*>(chunk);

}

Chunk* PoolAllocatorold::allocateBlock(size_t chunkSize)
{
	std::cout << "\nAllocating block (" << mChunksPerBlock << "chunks):" << std::endl << std::endl;

    size_t blockSize = mChunksPerBlock * chunkSize;

    //The first chunk of the new block
    Chunk* blockBegin = reinterpret_cast<Chunk*>(malloc(blockSize));


    //Once the block is allocated, we need to chain all the chunks in this block

    Chunk* chunk = blockBegin;
	for (size_t i = 0; i < mChunksPerBlock - 1; ++i) {
		chunk->next = reinterpret_cast<Chunk*>(reinterpret_cast<char*>(chunk) + chunkSize);
        chunk->prev = chunk;
		chunk = chunk->next;
	}

	chunk->next = nullptr; // Last chunk points to null

    return blockBegin;
}
