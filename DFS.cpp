#include<iostream>

using namespace std;

typedef struct Graph {
	char vexs[20];
	int arc[20][20];
	int vexNum, edgeNum;
}*pGraph;

void CreateGraph(Graph &graph) {
	cout << "输入顶点数和边数:";
	cin >> graph.vexNum >> graph.edgeNum;
	
	for(int i = 0; i < graph.vexNum; ++i) {
		cout << "输入第" << i+1 << "个顶点的名称:";
		cin >> graph.vexs[i]; 
	}
	
	for(int i = 0; i < graph.vexNum; ++i) {
		for(int j = 0; j < graph.vexNum; ++j) {
			graph.arc[i][j] = 0;
		}
	}
	
	int x, y, w;
	for(int i = 0; i < graph.edgeNum; ++i) {
		cout << "请输入第" << i+1 << "条边的两个顶点x,y和权值w:"; 
		cin >> x >> y >>w;
		graph.arc[x][y] = w;
		graph.arc[y][x] = w;
	}
	
}

bool visited[20];

void DFS(Graph& graph, int i){
	visited[i] = true;
	cout << graph.vexs[i] << "  ";
	for(int j = 0; j < graph.vexNum; ++j) {
		if(graph.arc[i][j] && !visited[j]) {
			DFS(graph, j);
		}
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
		cout << "\t" << graph.vexs[i];
	}
	cout << "\n\n";
	for(int i = 0; i < graph.vexNum; ++i) {
		cout << graph.vexs[i] << "\t";
		for(int j = 0; j < graph.vexNum; ++j) {
			cout << graph.arc[i][j] << "\t";
		}
		cout << "\n\n";
	}
	
	cout << "深度优先遍历结果:"; 
	DFSTraverse(graph);
	
	getchar();
	return 0;
} 
