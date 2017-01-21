// Implementation of the templated Vector class
// ECE4893/8893 lab 3
// C.V. Chaitanya Krishna

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
	elements=(T*)malloc(sizeof(T)*1);			//allocating memory
}

// Copy constructor
template <typename T>
Vector<T>::Vector(const Vector& rhs)
{
	count=rhs.count;
	reserved=rhs.reserved;
	elements=(T*)malloc(sizeof(T)*reserved);		//allocating 'reserved' amount of memory
	for(size_t i=0;i<count;i++)
	{
		new(&elements[i]) T(rhs.elements[i]);	//fill allocated memory with 'count'
	}											//number of elements using in-place new
}

// Assignment operator
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
	count=rhs.count;
	reserved=rhs.reserved;
	elements=(T*)malloc(sizeof(T)*reserved);	//allocating 'reserved' amount of memory
	for(size_t i=0;i<count;i++)
	{
		new(&elements[i]) T(rhs.elements[i]);	// copy 'count' number of elements to heap
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
	for(size_t i=0;i<n;i++)
	{
		new(&elements[i]) T(t);
	}
}

template <typename T>
void Vector<T>::Reserve(size_t n)
{// Reserve extra memory
	if(n>reserved)
	{
		T* tempVec;
		tempVec=(T*)malloc(sizeof(T)*n);
		for(size_t i=0;i<Size();i++)
		{
			new(&tempVec[i]) T(elements[i]);
		}
		Clear();
		free(elements);
		reserved=n;
		elements=tempVec;			
	}
}
#endif

// Destructor
template <typename T>
Vector<T>::~Vector()
{
	Clear();
	count=0;		//set count to 0
	reserved=0;		//set reserved to 0
	free(elements);	//free memory
}

// Add and access front and back
template <typename T>
void Vector<T>::Push_Back(const T& rhs)
{
	if(count>=reserved)			
	{
		T* tempVec;						
		size_t tempCount= count;
		reserved++;
		tempVec=(T*)malloc(sizeof(T)*reserved);	//create tempVec of size 'reserved+1'
		for(size_t i=0;i<Size();i++)
		{
			new(&tempVec[i]) T(elements[i]);	//copy old content in tempVec
			elements[i].~T();
		}
		new(&tempVec[Size()]) T(rhs);			//copy new content in last position
		free(elements);							//free memory
		count=tempCount+1;						
		elements=tempVec;	 					//copy content back from tempVec to elements
	}
	else 					//space is available
	{
		new(&elements[Size()]) T(rhs);	//copy the new content
		count++;
	}
}

template <typename T>
void Vector<T>::Push_Front(const T& rhs)
{
	if(count>=reserved)
	{
		T* tempVec;								
		size_t tempCount= count;
		reserved++;
		tempVec=(T*)malloc(sizeof(T)*reserved);	//create tempVec of size 'reserved+1'
		for(size_t i=0;i<count;i++)
		{
			new(&tempVec[i+1]) T(elements[i]);	//copy old content in tempVec starting from index 1
			elements[i].~T();
		}
		new(&tempVec[0]) T(rhs);				//copy new content at first position(index 0)
		free(elements);							//free memory
		count=tempCount+1;	
		elements=tempVec;	 					//copy content back from tempVec to elements	
	}
	else
	{
		for(size_t i=count-1;i>=0;i--)
		{
			new(&elements[i+1]) T(elements[i]);	//shift the content to right by 1 position
			elements[i].~T();
		}
		new(&elements[0]) T(rhs);		//copy new content to 1st position
		count++;
	}
}

template <typename T>
void Vector<T>::Pop_Back()
{ // Remove last element
	if (count!=0)
	{
		count--;
		elements[count].~T();
	}
}

template <typename T>
void Vector<T>::Pop_Front()
{ // Remove first element
	if (count!=0)
	{
		elements[0].~T();					//remove first element
		for(size_t i=0;i<Size()-1;i++)
		{
			new(&elements[i]) T(elements[i+1]);	//shift remaining elements to left by 1 position
			elements[i+1].~T();
		}
		count--;
	}
}

// Element Access
template <typename T>
T& Vector<T>::Front() const
{
	return(elements[0]);	//return 0th element
}

// Element Access
template <typename T>
T& Vector<T>::Back() const
{
	return(elements[count-1]);	//return last element
}

template <typename T>
T& Vector<T>::operator[](size_t i)     //Change here
{
	if (i<0 || i>=count)
	{
		cout<<"ERROR: index exceeds dimensions"<<endl;
		abort();
	}
	return *(elements+i);
}

template <typename T>
size_t Vector<T>::Size() const
{
	return(count);
}

template <typename T>
bool Vector<T>::Empty() const
{
	if(count==0)
		return true;
	else
		return false;
}

// Implement clear
template <typename T>
void Vector<T>::Clear()
{
	while(count!=0)
	{
		Pop_Back();	//remove elements till count is 0
	}
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
	return VectorIterator<T>(elements+count);
}

#ifdef GRAD_STUDENT

template <typename T>
void Vector<T>::Erase(const VectorIterator<T>& it)
{
	size_t position=0;
	VectorIterator<T> start;
	start=Begin();
	while(start != End())
	{
		if(start == it) break;	//if position is located, break
		position++;
		start++;
	}
	elements[position].~T();	//erase the element at required position
	for(size_t i=position+1;i<count;i++)
	{
		new(&elements[i-1]) T(elements[i]);	//left shift elements starting after the erased position by 1 position
		elements[i].~T();
	}
	count--;
}

template <typename T>
void Vector<T>::Insert(const T& rhs, const VectorIterator<T>& it)
{
	size_t position=0,tempCount;
	VectorIterator<T> start;
	start=Begin();
	while(start != End())
	{
		if(start == it) break;	//if position is located, break
		position++;
		start++;
	}
	reserved++;			
	T* tempVec;
	tempVec=(T*)malloc(sizeof(T)*reserved);	//create tempVec of size 'reserved+1'
	tempCount=count;
	for(size_t i=0;i<position;i++)
	{
		new(&tempVec[i]) T(elements[i]);	//copy elements from 0 index to 'position-1' to tempVec
	}
	new(&tempVec[position]) T(rhs);			//copy the inserted/new element to 'position' index
	position++;
	for(size_t i=position;i<reserved;i++)	
	{
		new(&tempVec[i]) T(elements[i-1]);	//copy remaining elements to tempVec
	}
	Clear();	
	free(elements);			//free memory
	elements=tempVec;		//copy elements from tempVec to elements vector
	count=tempCount;
	count++;
}
#endif

// Implement the iterators

// Constructors
template <typename T>
VectorIterator<T>::VectorIterator()
{
	current=NULL;
}

template <typename T>
VectorIterator<T>::VectorIterator(T* c)
{
	current=c;
}

// Copy constructor
template <typename T>
VectorIterator<T>::VectorIterator(const VectorIterator<T>& rhs)
{
	current=rhs.current;
}

// Iterator defeferencing operator
template <typename T>
T& VectorIterator<T>::operator*() const
{
	return(*current);
}

// Prefix increment
template <typename T>
VectorIterator<T>  VectorIterator<T>::operator++()
{
	return VectorIterator<T>(current++);
}

// Postfix increment
template <typename T>
VectorIterator<T> VectorIterator<T>::operator++(int)
{
	return VectorIterator<T>(current++);
}

// Comparison operators
template <typename T>
bool VectorIterator<T>::operator !=(const VectorIterator<T>& rhs) const
{
	if(current!=rhs.current)
		return true;
	else return false;
}

template <typename T>
bool VectorIterator<T>::operator ==(const VectorIterator<T>& rhs) const
{
	if (current==rhs.current)
		return true;
	else return false;
}