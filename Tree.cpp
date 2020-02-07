#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct BinaryTree {
	char data;
	struct BinaryTree *lChild, *rChild;
}Node, *pNode;

void CreateTree(pNode &newNode) {
	char data;
	cout << "请输入节点数据:";
	cin >> data;
	if('#' == data) {
		newNode = NULL;
	}
	else {
		newNode = (pNode)malloc(sizeof(Node)); 
		newNode->data = data;
		CreateTree(newNode->lChild);
		CreateTree(newNode->rChild);
	}
}

void PreOrderShow(Node *bTree) {
	if(bTree == NULL)
		return;
	cout << bTree->data << "\t";
	PreOrderShow(bTree->lChild);
	PreOrderShow(bTree->rChild);
}

void MidOrderShow(Node *bTree) {
	if(bTree == NULL)
		return;
	MidOrderShow(bTree->lChild);
	cout << bTree->data << "\t";
	MidOrderShow(bTree->rChild);
} 

void LastOrderShow(Node *bTree) {
	if(bTree == NULL)
		return;
	LastOrderShow(bTree->lChild);
	LastOrderShow(bTree->rChild);
	cout << bTree->data << "\t";
} 


int main() {
	pNode bTree;
	CreateTree(bTree);
	cout << "二叉树创建成功！";
	cout << "\n前序遍历：";
	PreOrderShow(bTree); 
	cout << "\n中序遍历：";
	MidOrderShow(bTree);
	cout << "\n后序遍历：";
	LastOrderShow(bTree);
	
	getchar();
	return 0;
} 
