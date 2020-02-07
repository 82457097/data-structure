#include<iostream>
#include<queue>

using namespace std;

#define MAXVEX 20
#define INFINITY 0	//用于初始化时填充邻接矩阵 

typedef struct Graph {
	char vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}*pGraph; 

void CreateGraph(Graph &graph) {
	cout << "输入顶点数和边数:";
	cin >>  graph.numVertexes >> graph.numEdges;
	
	//建立顶点表 
	for(int i = 0; i < graph.numVertexes; ++i) {
		cout << "请输入第" << i + 1 << "个顶点名:"; 
		cin >> graph.vexs[i];
	}
	
	//初始化邻接矩阵
	for(int i = 0; i < graph.numVertexes; ++i) {
		for(int j = 0; j < graph.numVertexes; ++j) {
			graph.arc[i][j] = INFINITY;
		}
	} 
	
	//建立邻接矩阵
	int x, y, w;
	for(int i = 0; i < graph.numEdges; ++i) {
		cout << "输入边的下标x,y和权值w:";
		cin >> x >> y >> w;
		graph.arc[x][y] = w;
		graph.arc[y][x] = w;
	}
}

bool visited[MAXVEX];

int OutQueue(Graph &graph, queue<char> &queue) {
	char tempVex = queue.front();
	for(int i = 0; i < graph.numVertexes; ++i) {
		if(tempVex == graph.vexs[i]) {
			queue.pop();
			return i;
		}
	}
}

void BFSTraverse(Graph &graph) {
	queue<char> queue;
	for(int i = 0; i < graph.numVertexes; ++i) {
		visited[i] = false;
	}
	for(int i = 0; i < graph.numVertexes; ++i) {
		if(!visited[i]) {
			visited[i] = true;
			cout << graph.vexs[i] << "  ";
			queue.push(graph.vexs[i]);
			while(!queue.empty()) {
				int i = OutQueue(graph, queue);
				for(int j = 0; j < graph.numVertexes; ++j) {
					if(graph.arc[i][j] && !visited[j]) {
						visited[j] = true;
						cout << graph.vexs[j] << "  ";
						queue.push(graph.vexs[j]);
					}
				}
			}
		}
	}
}

int main() {
	Graph graph;
	CreateGraph(graph);
	
	for(int i = 0; i < graph.numVertexes; ++i) {
		cout << "\t" << graph.vexs[i];
	}
	cout << "\n\n";
	for(int i = 0; i < graph.numVertexes; ++i) {
		cout << graph.vexs[i] << "\t";
		for(int j = 0; j < graph.numVertexes; ++j) {
			cout << graph.arc[i][j] << "\t";
		}
		cout << "\n\n";
	}
	
	cout << "广度优先遍历结果:";
	BFSTraverse(graph);
	
	getchar();
	return 0;
}
