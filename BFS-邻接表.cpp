#include<iostream>
#include<cstdlib>
#include<queue> 

#define MAXVEX 20

using namespace std;

typedef struct EdgeNode {
	int vexOrderNum;
	int weight;
	struct EdgeNode* next;
}eNode;

typedef struct VertexNode {
	char vexName;
	eNode* vNext;
}vNode, vArr[MAXVEX];

typedef struct Graph {
	vArr vexArr;
	int vexNum, edgeNum;
}pGraph;

void CreateGraph(Graph &graph) {
	cout << "请输入顶点数和边数:";
	cin >> graph.vexNum >> graph.edgeNum;
	
	for(int i = 0; i < graph.vexNum; ++i) {
		cout << "输入顶点名:";
		cin >> graph.vexArr[i].vexName;
		graph.vexArr[i].vNext = NULL; 
	}
	
	int x, y, w;
	eNode *newENode;
	for(int i = 0; i < graph.edgeNum; ++i) {
		cout << "输入第" << i+1 << "条边的两个顶点的序号x,y和权重w:";
		cin >> x >> y >> w;
		
		newENode = (eNode*)malloc(sizeof(eNode));
		newENode->vexOrderNum = x;
		newENode->weight = w;
		newENode->next = graph.vexArr[y].vNext;
		graph.vexArr[y].vNext = newENode;
		
		newENode = (eNode*)malloc(sizeof(eNode));
		newENode->vexOrderNum = y;
		newENode->weight = w;
		newENode->next = graph.vexArr[x].vNext;
		graph.vexArr[x].vNext = newENode;
	}
}

bool visited[MAXVEX];

int OutQueue(Graph &graph, queue<char> &queue) {
	char tempVex = queue.front();
	for(int i = 0; i < graph.vexNum; ++i) {
		if(tempVex == graph.vexArr[i].vexName) {
			queue.pop();
			return i;
		}
	}
}

void BFSTraverse(Graph &graph) {
	queue<char> queue;
	eNode* p;
	for(int i = 0; i < graph.vexNum; ++i) {
		visited[i] = false;
	}
	
	for(int i = 0; i < graph.vexNum; ++i) {
		if(!visited[i]) {
			visited[i] = true;
			cout << graph.vexArr[i].vexName << "  ";
			queue.push(graph.vexArr[i].vexName);
			while(!queue.empty()) {
				int i = OutQueue(graph, queue);
				p = graph.vexArr[i].vNext;
				while(p) {
					if(!visited[p->vexOrderNum]) {
						visited[p->vexOrderNum] = true;
						cout << graph.vexArr[p->vexOrderNum].vexName << "  ";
						queue.push(graph.vexArr[p->vexOrderNum].vexName);						
					}
					p = p->next;
				}
			}
		}
	}
}

int main() {
	Graph graph;
	CreateGraph(graph);
	
	for(int i = 0; i < graph.vexNum; ++i) {
		cout << graph.vexArr[i].vexName << "->";
		eNode *p;
		p = graph.vexArr[i].vNext; 
		while(p) {
			cout << p->vexOrderNum << "->";
			p = p->next;
		}
		cout << "NULL\n"; 
	}
	
	cout << "深度优先遍历结果:"; 
	BFSTraverse(graph);
	
	getchar();
	return 0;
} 
