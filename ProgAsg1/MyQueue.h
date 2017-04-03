#include<list>

using namespace std;

class MyQueue
{
public:
	MyQueue();
	~MyQueue();
	void enqueue(int num);
	int dequeue();
	int peek();
	int size();

private:
	list<int> mlist;
};

