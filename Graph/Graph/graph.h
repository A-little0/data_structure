#ifndef __GRAPH_H
#define __GRAPH_H
#include "main.h"



/*
下面为图关系的存储方式
*/
//邻接矩阵
#define MXVEXNUM 15
typedef struct AdjacencyMatrix {

	int vexnum;//顶点数
	int (*linkarr)[15];//关系矩阵
}AM_to_Graph;

AM_to_Graph* creatAdjacencyMatrix_toGraph(int vnum);//构造关系矩阵
#endif
