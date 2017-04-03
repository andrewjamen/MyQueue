#include "MyQueue.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int randomize(int num) {

	num = rand() % num + 1;

	return num;
}

int main()
{
	srand(time(NULL));
	MyQueue queue;
	int x;
	int maxSize = 0;
	int maxWait = 0;
	int customerService = 1000;
	int waitTime = 0;

	cout << "How often can a customer possibly take to get in line or be serviced?" << endl;
	cout << "Answer must be geater than 0 and in whole number minutes:" << endl;;
	cin >> x;
	cout << endl << endl;

	int firstArival = randomize(x);
	int customerCount = 2;
	cout << "Customer 1 arrived at " << firstArival << " minutes" << endl;
	int firstService = randomize(x) + firstArival;

	int customerArival = firstArival + randomize(x);

	//TODO: change to 720

	for (int i = 0; i < 720; i++) {

		if (customerArival == i) {
			cout << "Customer " << customerCount << " arrived at " << i << " minutes" << endl;
			queue.enqueue(customerCount);
			customerCount++;
			customerArival = randomize(x) + i;
			
		}
		if (firstService == i) {
			cout << "Customer 1 left at " << i << " minutes" << endl;
			customerService = i + randomize(x);
		}
		if (customerService == i) {
			if (queue.size() != 0) {
				cout << "Customer " << queue.dequeue() << " left at " << i << " minutes" << endl;
			}
			customerService = i + randomize(x);
			
		}

		if (queue.size() > maxSize) {
			maxSize = queue.size() - 1;
		}

		waitTime = customerArival - customerService;
		if (waitTime > maxWait){
			maxWait = waitTime;
		}


	}

	cout << endl << "Maximum number of customers in line at once: " << maxSize << endl;
	cout << "Maximum number of minutes one customer waited in line: " << maxWait << endl;


	
	cout << endl << endl;
    return 0;
}

