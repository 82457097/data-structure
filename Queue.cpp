#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct QueueNode {
	int data;
	struct QueueNode* next;
}Node;

typedef struct LinkQueue {
	Node *front, *rear;
}Queue;

void InQueue(Queue &queue, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	queue.rear->next = newNode;
	queue.rear = newNode;
	cout << data << "成功入队！" << endl; 
}

void OutQueue(Queue &queue, int &data) {
	Node* outNode;
	if(queue.front == queue.rear) {
		cout << "空队列！" << endl;
		return;
	}
	
	outNode = queue.front->next;
	data = outNode->data;
	queue.front->next = outNode->next;
	if(outNode == queue.rear) {
		queue.rear = queue.front;
	}
	free(outNode);
	cout << data << "成功出队！" << endl; 
}

int main() {
	Queue queue;
	queue.rear = queue.front;
	int data = 0;
	OutQueue(queue, data);
	InQueue(queue, 1);
	InQueue(queue, 2);
	OutQueue(queue, data);
	OutQueue(queue, data);
	
	getchar(); 
	return 0;
} 
