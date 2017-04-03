#include "MyQueue.h"
#include <string>


MyQueue::MyQueue()
{
}


MyQueue::~MyQueue()
{
	
}

void MyQueue::enqueue(int num) {
	mlist.push_back(num);
}

int MyQueue::dequeue()
{
	int num = mlist.front();
	mlist.pop_front();
	return num;
}

int MyQueue::peek()
{
	return mlist.front();
}

int MyQueue::size()
{
	return mlist.size();
}
