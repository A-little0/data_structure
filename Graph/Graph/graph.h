#ifndef __GRAPH_H
#define __GRAPH_H
#include "main.h"



/*
����Ϊͼ��ϵ�Ĵ洢��ʽ
*/
//�ڽӾ���
#define MXVEXNUM 15
typedef struct AdjacencyMatrix {

	int vexnum;//������
	int (*linkarr)[15];//��ϵ����
}AM_to_Graph;

AM_to_Graph* creatAdjacencyMatrix_toGraph(int vnum);//�����ϵ����
#endif
