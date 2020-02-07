#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct StackNode {
	int data;
	struct StackNode* next;
}Node;

typedef struct LinkStack {
	Node* top;
	int count;
}Stack;

bool Empty(Stack &stack) {
	if(!stack.count) {
		cout << "空栈！" << endl; 
		return true;
	}
	return false;
}

void Push(Stack &stack, int data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = stack.top;
	stack.top = newNode;
	stack.count++;
	cout << "成功将数据" << data << "入栈！" << endl; 
}

void Pop(Stack &stack, int &data) {
	if(Empty(stack)) {
		return;
	}
	
	data = stack.top->data;
	Node* popNode;
	popNode = stack.top;
	stack.top = stack.top->next;
	free(popNode);
	stack.count--;
	cout << "成功将数据" << data << "弹出！" << endl; 
}

int main() {
	Stack stack;
	stack.count = 0;
	stack.top = NULL;
	Empty(stack);
	Push(stack, 1);
	Push(stack, 2);
	
	int data = 0;
	while(stack.count) {
		Pop(stack, data);
	}
	 
	getchar();
	return 0;
} 
