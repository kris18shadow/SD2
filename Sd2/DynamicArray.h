#pragma once

template<class T>
class DynamicArray
{
	T* arr;
	size_t size, currentSize;
	void resize();
public:
	DynamicArray() : arr(NULL), size(0), currentSize(0) {};
	~DynamicArray();
	T& operator[](size_t i);
	size_t getCurrSize() const;

	void pushBack(T& elem);
};

template<class T>
void DynamicArray<T>::resize()
{
	size_t newSize;
	if (size > 0)
	{
		newSize = size * 2;

		T* newArr = new T[newSize];
		for (size_t i = 0; i < currentSize; i++)
		{
			newArr[i] = this->arr[i];
		}
		delete[] arr;
		this->arr = newArr;
	}
	else
	{
		newSize = 5;

		T* newArr = new T[newSize];
		for (size_t i = 0; i < currentSize; i++)
		{
			newArr[i] = this->arr[i];
		}
		delete[] arr;
		this->arr = newArr;
	}

	this->size = newSize;
}

template<class T>
DynamicArray<T>::~DynamicArray()
{
	delete[] this->arr;
}

template<class T>
T& DynamicArray<T>::operator[](size_t i)
{
	if (i <= currentSize)
		return arr[i];
	else
		return arr[currentSize];
}

template<class T>
size_t DynamicArray<T>::getCurrSize() const
{
	return this->currentSize;
}

template<class T>
void DynamicArray<T>::pushBack(T& elem)
{
	if (currentSize < size)
	{
		arr[currentSize] = elem;
		currentSize++;
	}
	else
	{
		resize();
		arr[currentSize] = elem;
		currentSize++;
	}
}