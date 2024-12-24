#pragma once
#include <iostream>
#include <vector>
/// <summary>
/// The interface of a small stack allocator.
/// It is unimplemented and has very few safety features.
/// </summary>
class StackAllocator
{
public:
	StackAllocator(size_t Max_Size);
	~StackAllocator();

	/// <summary>
	/// "Allocate" size bytes and move the marker up by the same distance
	/// </summary>
	/// <param name="size">How far do we move the Head?</param>
	/// <returns>A pointer to the start of the "allocated" block</returns>
	void* Alloc(size_t size);
	/// <summary>
	/// Move the stack back to a previous point.
	/// There's nothing in here to keep track of where this point *should* be
	/// </summary>
	/// <param name="size">How many bytes are we going back?</param>
	/// <returns>A pointer to where we moved back to</returns>
	void* Pop(size_t size);

	void* RollBack(int dist);
	//void GetBase();


	/// <summary>
	/// Reset the stack back to zero
	/// </summary>
	void Clear();

private:
	void* Head;	//This is intended to be a pointer to the top of the stack
	void* Base;	//This is intended to be a pointer to the bottom of the stack

	int stackSize;
	int currentSize = 0;

	//Stack pointer position
	int stackElements = -1;


	std::vector<int> stackArray;
};

