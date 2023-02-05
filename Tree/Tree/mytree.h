#ifndef __MYSTREE_H
#define __MYSTREE_H
#include "main.h"
#define TreeTypeName int
#define BinaryTreeTypeName int
#define TRUE 1
#define FALSE 0

//��
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

//������
typedef struct BinaryTree {

	BinaryTreeTypeName data;
	struct  
	{
		struct BinaryTree* parent;
		struct BinaryTree* leftchild;
		struct BinaryTree* rightchild;
	}ptr;

}BinaryTree;
enum LeftOrRight{L,R}LR;
BinaryTree* BinaryTreeInit();//��ʼ��������
BinaryTree* DestroyBinaryTree(BinaryTree* targettree);//�ݻٶ�����
BinaryTree* CreatBinaryTree(BinaryTree* targettree);
void ClearBinaryTree(BinaryTree* targettree);
int BinaryTreeEmpty(BinaryTree* targettree);
int BinaryTree_Depth(BinaryTree* targettree);//
BinaryTree* BinaryTree_Root(BinaryTree* targettree);
BinaryTreeTypeName BinaryTree_Value(BinaryTree* targettree);
void BinaryTree_Assign(BinaryTree* targettree,BinaryTreeTypeName value);//��������ֵ
void SonJudge(BinaryTree* targettree, BinaryTree* tree_e);
BinaryTree* BinaryTree_LeftChild(BinaryTree* targettree);
BinaryTree* BinaryTree_RightChild(BinaryTree* targettree);
BinaryTree* BinaryTree_LeftSibling(BinaryTree* targettree, BinaryTree* tree_e);
BinaryTree* BinaryTree_RightSibling(BinaryTree* targettree, BinaryTree* tree_e);
void BinaryTree_InsertChild(BinaryTree* targettree, BinaryTree* tree_e, BinaryTree* child, enum LeftOrRight LR);
void BinaryTree_DeleteChild(BinaryTree* targettree);
void PreOrderTraverse(BinaryTree* targettree);
void InOrderTraverse(BinaryTree* targettree);
void PostOrderTraverse(BinaryTree* targettree);
void LevelOrderTraverse(BinaryTree* targettree);

#endif