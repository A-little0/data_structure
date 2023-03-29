#ifndef __GRAPH_H
#define __GRAPH_H
#include "main.h"



/*
下面为图关系的存储方式
*/
//邻接矩阵
#define VEXNUM 5
typedef struct AdjacencyMatrix {

	int vexnum;//顶点数
	int (*linkarr)[VEXNUM];//关系矩阵
}AM_to_Graph;

AM_to_Graph* creatAdjacencyMatrix_toGraph(int vnum);//构造关系矩阵

/*
无向图
*/
typedef  int Undeirected_Graph_Type;
typedef struct Undirected_Graph {
	Undeirected_Graph_Type data[VEXNUM];//数据表
	AM_to_Graph* am;//关系矩阵
}UnGraph;

UnGraph* creatUnGraph(int vnum);//创建无向图
void destoryUnGraph(UnGraph* target_ungraph);//摧毁无相图
void locateVex(const UnGraph* target_ungraph, int uvex);//返回结点uvex在无向图的位置(返回下标信息)
void getVex(int pos);//返回下标为pos的信息
void putVex(UnGraph* target_ungraph, int pos, Undeirected_Graph_Type value);//为下表为pos的结点赋值value
void firstAdjVex(const UnGraph* target_ungraph, int pos);//返回下标为pos的第一个邻接点的下标
void nextAdjVex(const UnGraph* target_ungraph, int pos);//返回nexpos
void insertVex(UnGraph* target_ungraph, Undeirected_Graph_Type value);//插入值为value的结点 
void deleteVex(UnGraph* target_ungraph, int pos);//删除下标为pos的结点
void insertArc(UnGraph* target_ungraph, int pos1, int pos2);//在下标为pos1和pos2之间建立弧
void deleteArc(UnGraph* target_ungraph, int pos1, int pos2);//删除下标为pos1和pos2之间的弧
void DFSTraverse(const UnGraph* target_ungraph);//深度优先遍历
void BFSTraverse(const UnGraph* target_ungraph);//广度优先遍历
#endif
