#include<iostream>
#include<queue>

using namespace std;

#define MAXVEX 20
#define INFINITY 7777	//用于初始化时填充邻接矩阵 

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

void MiniSpanTreeByPrim(Graph &graph) {
	int adjVex[MAXVEX];	//保存相关顶点下标 
	int lowCost[MAXVEX];//保存相关顶点间边的权值 
	lowCost[0] = 0;		//初始化第一个权值为0，代表顶点0加入生成树；
						//哪一个顶点对应的索引为0，表示该顶点已加入生成树 
	adjVex[0] = 0;		//初始化第一个顶点的下标为0；
	//循环除第0个顶点之外的所有顶点 
	for(int i = 0; i <graph.numVertexes; ++i) {
		lowCost[i] = graph.arc[0][i];	//将0号顶点对应的邻接矩阵中的哪一行拷入数组lowCost 
		adjVex[i] = 0;			//将所有顶点对应的下标都初始化为0号顶点的下标； 
	}
	
	int min, j, k;
	for(int i = 1; i < graph.numVertexes; ++i) {
		min = INFINITY;
		j = 1;
		k = 0;
		while(j < graph.numVertexes) {
			//判断j号顶点未加入生成树，且j与0号顶点的边的权值最小，然后将j的序号给k 
			if(lowCost[j] != 0 && lowCost[j] < min) {
				min = lowCost[j];
				k = j;
			}
			++j;
		}
		//打印当前顶点边中的最小权值边adjVex是已经被顶点更新的数组，
		//只要有与该顶点相关连的顶点，其相关顶点再邻接表中的位置就会被更新称该顶点 
		//很难解释清楚，建议对照着邻接表，来掩饰代码的每一步，再列出对应的adjVex数组和lowCost数组 
		cout << adjVex[k] << "--" << k << "\t";
		lowCost[k] = 0;//序号为k的顶点已经完成任务加入生成树，所以它在lowCost中的位置被置为0 
		
		//这个循环用来更新序号k的相关顶点对应的lowCost数组 
		for(int i = 1; i < graph.numVertexes; ++i) {
			if(lowCost[i] != 0 && graph.arc[k][i] < lowCost[i]) {
				lowCost[i] = graph.arc[k][i];
				adjVex[i] = k;//将于k顶点相关的顶点的序号都置为k，做占有标志，在下一次循环中使用 
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
	
	MiniSpanTreeByPrim(graph);
	
	getchar();
	return 0;
}
