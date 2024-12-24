#pragma once
#include <utility>

/// <summary>
/// This SmartPointer should end up with functionality similar to an std::unique_pointer
/// It shouldn't be able to be copied!
/// It should support movement!
/// </summary>
/// <typeparam name="T">The underlying type of this Smart Pointer</typeparam>

template <class T>
class UniquePointer
{
public:
	inline UniquePointer<T>() {
		//By default, our underlying pointer should be empty
		m_RawPointer = nullptr;

	}
	inline ~UniquePointer() {
		delete m_RawPointer;
	}

	//inline UniquePointer<T>(NoiseyObject* uniquePtr) {
	//	m_RawPointer = uniquePtr;
	//}

	//Removing copy constructor
	UniquePointer(const UniquePointer&) = delete;
	//Removing assignment operator
	UniquePointer& operator=(const UniquePointer&) = delete;

	//Adding move constructor
	UniquePointer(UniquePointer&& other) noexcept : m_RawPointer(other.m_RawPointer) {
		other.m_RawPointer = nullptr; //Transfering the object
	}

	//Adding move assignment operator
	UniquePointer& operator=(UniquePointer&& other) noexcept
	{
		if (this == &other) {
			return *this;
		}
		delete m_RawPointer;
		m_RawPointer = other.m_RawPointer;
		other.m_RawPointer = nullptr;
	}

	//Deference operator
	T& operator*() const {
		return *m_RawPointer;
	}

	//Arrow operator
	T* operator->() const {
		return m_RawPointer;
	}


	//Get function, getting the raw pointer
	T* get() const {
		return m_RawPointer;
	}

	T* release() {
		T* temp = m_RawPointer;
		m_RawPointer = nullptr;
		return temp;
	}

	void reset(T* rawPtr = nullptr) {
		delete m_RawPointer;
		m_RawPointer = rawPtr;
	}


	//Now do the rest
	//void DoThing(const std::unique_ptr<SmartPointer>& passedPtr) {

	//}
private:
	//The underlying pointer
	T* m_RawPointer;

};
