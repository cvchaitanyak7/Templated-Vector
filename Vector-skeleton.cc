// Implementation of the templated Vector class
// ECE4893/8893 lab 3
// YOUR NAME HERE

#include <iostream> // debugging
#include "Vector.h"

// Your implementation here
// Fill in all the necessary functions below
using namespace std;

// Default constructor
template <typename T>
Vector<T>::Vector()
{
	count=0;
	reserved=0;
	elements=(T*)malloc(sizeof(T)*1);
}

// Copy constructor
template <typename T>
Vector<T>::Vector(const Vector& rhs)
{
	count=rhs.size();
	reserved=count;
	elements=(T*)malloc(sizeof(T)*count);
	for (size_t i=0; i<count; i++)
	{
		new(&elements[i]) T(rhs.elements[i]);
	}
}

// Assignment operator
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
	count=rhs.size();
	reserved=count;
	elements=(T*)malloc(sizeof(T)*count);
	for (size_t i=0; i<count; i++)
	{
		new(&elements[i]) T(rhs.elements[i]);
	}
}

#ifdef GRAD_STUDENT
// Other constructors
template <typename T>
Vector<T>::Vector(size_t nReserved)
{ // Initialize with reserved memory
	count=0;
	reserved=nReserved;
	elements=(T*)malloc(sizeof(T)*reserved);
}

template <typename T>
Vector<T>::Vector(size_t n, const T& t)
{ // Initialize with "n" copies of "t"
	count=n;
	reserved=n;
	elements=(T*)malloc(sizeof(T)*count);
	for (size_t i=0; i<count; i++)
	{
		new(&elements[i]) T(t);
	}
}

template <typename T>
void Vector<T>::Reserve(size_t n)
{ // Reserve extra memory
	if (n>reserved)
	{
		T* tempVar;
		tempVar=(T*)malloc(sizeof(T)*n);
		for (size_t i=0; i<Size(); i++)
		{
			new(&tempVar[i]) T(elements[i]);
		}
		Clear();
		free(elements);
		reserved=n;
		elements=tempVar;
	}
}

#endif

// Destructor
template <typename T>
Vector<T>::~Vector()
{
	Clear();
	count=0;
	reserved=0;
	free(elements);
}

// Add and access front and back
template <typename T>
void Vector<T>::Push_Back(const T& rhs)
{
	if (count>=reserved)
	{
		T* tempVar;
		size_t tempCount=count;
		reserved++;
		tempVar=(T*)malloc(sizeof(T)*reserved);
		for (size_t i=0; i<Size(); i++)
		{
			new(&tempVar[i]) T(elements[i]);
			elements[i].~T();
		}
		new(&tempVar[Size()]) T(rhs);
		free(elements);
		count=tempCount+1;
		elements=tempVar;
	}
	else
	{
		new(&elements[Size()]) T(rhs);
		count++;
	}
}

template <typename T>
void Vector<T>::Push_Front(const T& rhs)
{
	if(count>=reserved)
	{
		T* tempVar;
		size_t tempCount= count;
		reserved++;
		tempVar=(T*)malloc(sizeof(T)*reserved);
		for(size_t i=0;i<count;i++)
		{
			new(&tempVar[i+1]) T(elements[i]);
			elements[i].~T();
		}
		new(&tempVar[0]) T(rhs);
		//Clear();
		free(elements);
		count=tempCount+1;	
		elements=tempVar;	 	
	}
	else
	{
		for(size_t i=count-1;i>=0;i--)
		{
			new(&elements[i+1]) T(elements[i]);
			elements[i].~T();
		}
		new(&elements[0]) T(rhs);
		count++;
	}
}

template <typename T>
void Vector<T>::Pop_Back()
{ // Remove last element
}

template <typename T>
void Vector<T>::Pop_Front()
{ // Remove first element
}

// Element Access
template <typename T>
T& Vector<T>::Front() const
{
}

// Element Access
template <typename T>
T& Vector<T>::Back() const
{
}

template <typename T>
const T& Vector<T>::operator[](size_t i) const
{ // const element access
}

template <typename T>
T& Vector<T>::operator[](size_t i)
{//nonconst element access
}

template <typename T>
size_t Vector<T>::Size() const
{
}

template <typename T>
bool Vector<T>::Empty() const
{
}

// Implement clear
template <typename T>
void Vector<T>::Clear()
{
}

// Iterator access functions
template <typename T>
VectorIterator<T> Vector<T>::Begin() const
{
  return VectorIterator<T>(elements);
}

template <typename T>
VectorIterator<T> Vector<T>::End() const
{
}

#ifdef GRAD_STUDENT
// Erase and insert
template <typename T>
void Vector<T>::Erase(const VectorIterator<T>& it)
{
}

template <typename T>
void Vector<T>::Insert(const T& rhs, const VectorIterator<T>& it)
{
}
#endif

// Implement the iterators

// Constructors
template <typename T>
VectorIterator<T>::VectorIterator()
{
}

template <typename T>
VectorIterator<T>::VectorIterator(T* c)
{
}

// Copy constructor
template <typename T>
VectorIterator<T>::VectorIterator(const VectorIterator<T>& rhs)
{
}

// Iterator defeferencing operator
template <typename T>
T& VectorIterator<T>::operator*() const
{
}

// Prefix increment
template <typename T>
VectorIterator<T>  VectorIterator<T>::operator++()
{
}

// Postfix increment
template <typename T>
VectorIterator<T> VectorIterator<T>::operator++(int)
{;
}

// Comparison operators
template <typename T>
bool VectorIterator<T>::operator !=(const VectorIterator<T>& rhs) const
{
}

template <typename T>
bool VectorIterator<T>::operator ==(const VectorIterator<T>& rhs) const
{
}




