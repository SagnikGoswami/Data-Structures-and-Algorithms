#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Queue {

	int front, rear;
	vector<int> arr;

	bool isEmpty(){
		return (front==rear);
	}
public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		arr[rear]=e;
		rear++;
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		if(isEmpty()) return -1;
		int frontElem=arr[front];
		front++;
		return frontElem;
	}
};