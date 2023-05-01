#include<iostream>
using namespace std;

int q[10];
int front = -1;
int rear = -1;

int isEmpty(){
	if(front == rear)
		return -1;
	else
		return 0;
}

void insert(int item){
	rear = rear+1;
	q[rear] = item;
}

int delete(){
	front = front+1;
	return q[front];
}
