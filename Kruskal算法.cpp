#include<iostream>

using namespace std;

#define MAXVEX 20
#define INFINITY 7777	//用于初始化时填充邻接矩阵 

typedef struct Graph {
	char vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}*pGraph; 

struct Edge {
	int begin;
	int end;
	int weight;
};

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

void TransAndSort(Graph &graph, Edge edges[]) {
	int index = 0;
	for(int i = 0; i < graph.numVertexes; ++i) {
		for(int j = i + 1; j < graph.numVertexes; ++j) {
			if(graph.arc[i][j] != 7777) {
				edges[index].begin = i;
				edges[index].end = j;
				edges[index].weight = graph.arc[i][j];
				++index;
			}
		}
	}
	
	Edge temp;
	for(int i = 0; i < graph.numEdges; ++i) {
		for(int j = i + 1; j < graph.numEdges; ++j) {
			if(edges[i].weight > edges[j].weight) {
				temp = edges[i];
				edges[i] = edges[j];
				edges[j] = temp;
			}
		}
	}
	
	cout << "生成边集数组：" << endl;
	for(int i = 0; i < graph.numEdges; ++i) {
		cout << edges[i].begin << "  " << edges[i].end << "  " << edges[i].weight << endl;
	}	
}

int Find(int *parent, int i) {
	while(parent[i] > 0) {
		i = parent[i];
	}
	
	return i;
}

void MiniSpanTreeByKruskal(Graph graph) {
	Edge edges[graph.numEdges];
	int parent[graph.numVertexes];

	TransAndSort(graph, edges);
	
	for(int i = 0; i < graph.numVertexes; ++i) {
		parent[i] = 0;
	}
	
	int n, m;
	for(int i = 0; i < graph.numEdges; ++i) {
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if(n != m) {
			parent[n] = m;
			cout << edges[i].begin << "--" << edges[i].end << "  ";
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

	MiniSpanTreeByKruskal(graph);
	
	getchar();
	return 0;
}
