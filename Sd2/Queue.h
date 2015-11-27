#pragma once
#include <iostream>

template<class T>
struct elemQ
{
	T data;
	elemQ<T>* next;
};

template<typename T>
class Queue
{
private:
	elemQ<T> *front, *rear;
	void delQueue();
	void copy(Queue const& other);
	int size;

public:
	Queue() : front(NULL), rear(NULL), size(0) {};
	~Queue();
	Queue(Queue const& other);
	Queue& operator=(Queue const& other);

	void push(T const& newElem);
	int pop();

	bool empty() const;
	T peek() const;
	int getSize() const;
};

template<class T>
Queue<T>::~Queue()
{
	delQueue();
}

template<class T>
Queue<T>::Queue(Queue const& other)
{
	copy(other);
}

template<class T>
Queue<T>& Queue<T>::operator=(Queue const& other)
{
	if (this != &other)
	{
		delQueue();
		copy(other);
	}

	return *this;
}

template<class T>
void Queue<T>::delQueue()
{
	while (pop());
	size = 0;
}

template<class T>
void Queue<T>::copy(Queue const& other)
{
	rear = NULL;
	if (other.rear)
	{
		elemQ<T> *p = other.front;
		while (p)
		{
			push(p->data);
			p = p->next;
		}
	}

	this->size = other.size;
}

template<class T>
void Queue<T>::push(T const& newElem)
{
	elemQ<T> *p = new elemQ<T>;
	p->data = newElem;
	p->next = NULL;
	if (rear)
		rear->next = p;
	else
		front = p;

	rear = p;
	size++;
}

template<class T>
int Queue<T>::pop()
{
	elemQ<T> *p;
	if (!rear)
		return 0;
	p = front;

	if (p == rear)
	{
		rear = NULL;
		front = NULL;
	}
	else
		front = p->next;

	size--;
	delete p;

	return 1;
}

template<class T>
bool Queue<T>::empty() const
{
	return rear == NULL;
}

template<class T>
T Queue<T>::peek() const
{
	if (empty())
	{
		throw "The Queue is empty!\n";
	}
	else
	{
		return front->data;
	}
}

template<class T>
int Queue<T>::getSize() const
{
	return size;
}