#pragma once
#include <iostream>
#pragma once

//Stack container:
template<typename T>
struct Box
{
	Box<T>* pNext;
	T data;
};


template<typename T>
class Stack
{
private:
	Box<T>* pTop;
	size_t length;

	void delStack();
public:
	Stack<T>();
	~Stack<T>();

	void push(const T& elem);
	void pop();

	bool isEmpty() const;
	int getLength() const;
	T peek() const;
};

template<typename T>
void Stack<T>::delStack()
{
	while (pTop)
	{
		Box<T>* prev = pTop->pNext;
		delete pTop;
		pTop = prev;
	}
}

template<typename T>
Stack<T>::Stack()
{
	length = 0;
	pTop = NULL;
}


template<typename T>
Stack<T>::~Stack()
{
	delStack();
}

template<typename T>
void Stack<T>::push(const T& elem)
{
	Box<T>* pn = new Box<T>;
	pn->data = elem;
	pn->pNext = pTop;
	pTop = pn;

	length++;
}

template<typename T>
void Stack<T>::pop()
{
	if (isEmpty())
		throw "Trying to pop from empty stack!\n";

	Box<T>* prev = pTop->pNext;
	delete pTop;
	pTop = prev;

	length--;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
	return pTop == NULL;
}

template<typename T>
int Stack<T>::getLength() const
{
	return length;
}

template<typename T>
T Stack<T>::peek() const
{
	if (isEmpty())
		throw "Trying to peek from empty stack!\n";

	return pTop->data;
}

