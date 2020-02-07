#include<iostream>
#include<cstdlib>

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

void DFS(Graph& graph, int i){
	visited[i] = true;
	cout << graph.vexArr[i].vexName << "  ";
	eNode* p = graph.vexArr[i].vNext;
	while(p) {
		if(!visited[p->vexOrderNum]) {
			DFS(graph, p->vexOrderNum);
		}
		p = p->next;
	}
} 

void DFSTraverse(Graph &graph) {
	for(int i = 0; i < graph.vexNum; ++i) {
		visited[i] = false;
	}
	
	for(int i = 0; i < graph.vexNum; ++i) {
		if(!visited[i]) {
			DFS(graph, i); 
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
	DFSTraverse(graph);
	
	getchar();
	return 0;
} 
