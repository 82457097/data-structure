#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct ReLink {
	int data;
	struct ReLink *next;
}Node;

void InsertByHead(Node &link, int data) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	if(link.next == &link) {
		newNode->data = data;
		newNode->next = &link;
		link.next = newNode;
	}
	else {
		newNode->data = data;
		newNode->next = link.next;
		link.next = newNode;
	}
}

int main() {
	Node head;
	head.data = 0;
	head.next = &head;
	InsertByHead(head, 1);
	InsertByHead(head, 2);
	InsertByHead(head, 3);
	InsertByHead(head, 4);
	InsertByHead(head, 5);
	Node* p = head.next;
	int i = 10;
	while(p && i--) {
		cout << p->data << endl;
		p = p->next;
	}
	
	
	return 0;
} 
