#ifndef __GRAPH_H
#define __GRAPH_H
#include "main.h"



/*
����Ϊͼ��ϵ�Ĵ洢��ʽ
*/
//�ڽӾ���
#define VEXNUM 5
typedef struct AdjacencyMatrix {

	int vexnum;//������
	int (*linkarr)[VEXNUM];//��ϵ����
}AM_to_Graph;

AM_to_Graph* creatAdjacencyMatrix_toGraph(int vnum);//�����ϵ����

/*
����ͼ
*/
typedef  int Undeirected_Graph_Type;
typedef struct Undirected_Graph {
	Undeirected_Graph_Type data[VEXNUM];//���ݱ�
	AM_to_Graph* am;//��ϵ����
}UnGraph;

UnGraph* creatUnGraph(int vnum);//��������ͼ
void destoryUnGraph(UnGraph* target_ungraph);//�ݻ�����ͼ
void locateVex(const UnGraph* target_ungraph, int uvex);//���ؽ��uvex������ͼ��λ��(�����±���Ϣ)
void getVex(int pos);//�����±�Ϊpos����Ϣ
void putVex(UnGraph* target_ungraph, int pos, Undeirected_Graph_Type value);//Ϊ�±�Ϊpos�Ľ�㸳ֵvalue
void firstAdjVex(const UnGraph* target_ungraph, int pos);//�����±�Ϊpos�ĵ�һ���ڽӵ���±�
void nextAdjVex(const UnGraph* target_ungraph, int pos);//����nexpos
void insertVex(UnGraph* target_ungraph, Undeirected_Graph_Type value);//����ֵΪvalue�Ľ�� 
void deleteVex(UnGraph* target_ungraph, int pos);//ɾ���±�Ϊpos�Ľ��
void insertArc(UnGraph* target_ungraph, int pos1, int pos2);//���±�Ϊpos1��pos2֮�佨����
void deleteArc(UnGraph* target_ungraph, int pos1, int pos2);//ɾ���±�Ϊpos1��pos2֮��Ļ�
void DFSTraverse(const UnGraph* target_ungraph);//������ȱ���
void BFSTraverse(const UnGraph* target_ungraph);//������ȱ���
#endif
