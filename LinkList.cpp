#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

typedef struct LinkList {
	int data;
	struct LinkList* next;
}Node;

void InsertByHead(Node& list, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = list.next;
	list.next = newNode;
}

void CreateList(Node& list, int len) {
	int data;
	srand((unsigned)time(NULL));
	for(int i = 0; i < len; ++i) {
		data = rand() % 100;
		InsertByHead(list, data);
	}
	cout << "成功创建长度为 " << len << " 的链表！" << endl; 
}

void GetData(Node &list, int index, int *data) {
	Node* p;
	int i = 1;
	p = list.next;
	while(p && i < index) {
		p = p->next;
		++i;
	}
	if(!p || i > index) {
		cout << "不存在该节点！" << endl;
		return; 
	} 
	*data = p->data;
	cout << "链表中第"  << index << "个元素的值为：" << *data << endl; 
}

void ListInsert(Node& list, int index, int data) {
	int i = 1;
	Node* newNode,*p;
	p = &list;
	while(p && i < index) {
		p = p->next;
		++i;
	}
	if(!p || i > index) {
		cout << "不存在第" << index << "个位置！" <<endl;
		return; 
	}
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = p->next;
	p->next = newNode;
	cout << "成功在链表中第"  << index << "个位置插入：" << data << endl;
}

void ListDelete(Node& list, int index, int *data) {
	Node* p,*delNode;
	p = &list;
	int i = 1;
	while(p && i < index) {
		p = p->next;
		++i;
	}
	if(!p || i > index) {
		cout << "不存在第" << index << "个位置！" <<endl;
		return; 
	}
	delNode = p->next;
	*data = delNode->data;
	p->next = delNode->next;
	delNode->next = NULL;
	cout << "成功删除链表中第"  << index << "个元素：" << *data << endl;
}

void ClearList(Node& list) {
	Node* p,*temp;
	p = list.next;
	while(p) {
		temp = p->next;
		free(p);
		p = temp;
	} 
	list.next = NULL;
	cout << "成功销毁链表！" << endl;
} 

int main() {
	Node list;
	list.next = NULL;
	CreateList(list, 10);
	int data;
	GetData(list, 5, &data); 
	ListInsert(list, 6, 1234); 
	ListDelete(list, 9, &data);
	
	Node* p = list.next;
	while(p) {
		cout << p->data << endl;
		p = p->next; 
	} 
	
	ClearList(list);
	
	getchar();
	return 0;
}
