#ifndef __MYSTREE_H
#define __MYSTREE_H
#include "main.h"
#define TreeTypeName int
#define TRUE 1
#define FALSE 0
typedef struct Tree {
	//������
	TreeTypeName data;
	//ָ����
	struct 
	{ 
		struct Tree* bro;//ָ���ֵ�
		struct Tree* par;//ָ��˫��
		struct Tree* son;//ָ�����
	}ptr;
}Tree;//������

Tree* TreeInit();
void DestroyTree(Tree* targettree);//�ݻ���
//CreatTree();//�����幹����
void ClearTree(Tree* targettree);
int TreeEmpty(Tree* targettree);
unsigned int TreeDepth(Tree* targetree);
Tree* Root(Tree* targettree);//�����ڣ��򷵻�����
TreeTypeName Value(Tree* cur_e);//cur_e����t��ĳ����㣻
void Assign(Tree* cur_e, TreeTypeName value);
Tree* Parent(Tree* cur_e);//����cur_e������˫��
Tree* LeftChild(Tree* cur_e);//����cur_e����������
Tree* RightSibling(Tree* cur_e);//����cur_e���������ֵ�
Tree* InsertChild(Tree* sontree, Tree* cur_e);//��cur_e��㴦���뺢��
void DeleteChild(Tree* cur_e, unsigned int order);//
void TraverseTree(Tree* targeettree);

#endif