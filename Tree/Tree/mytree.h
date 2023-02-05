#ifndef __MYSTREE_H
#define __MYSTREE_H
#include "main.h"
#define TreeTypeName int
#define BinaryTreeTypeName int
#define TRUE 1
#define FALSE 0

//树
typedef struct Tree {
	//数据域
	TreeTypeName data;
	//指针域
	struct 
	{ 
		struct Tree* bro;//指向兄弟
		struct Tree* par;//指向双亲
		struct Tree* son;//指向儿子
	}ptr;
}Tree;//有序树

Tree* TreeInit();
void DestroyTree(Tree* targettree);//摧毁树
//CreatTree();//按定义构造树
void ClearTree(Tree* targettree);
int TreeEmpty(Tree* targettree);
unsigned int TreeDepth(Tree* targetree);
Tree* Root(Tree* targettree);//树存在，则返回树根
TreeTypeName Value(Tree* cur_e);//cur_e是树t的某个结点；
void Assign(Tree* cur_e, TreeTypeName value);
Tree* Parent(Tree* cur_e);//返回cur_e处结点的双亲
Tree* LeftChild(Tree* cur_e);//返回cur_e处结点的左孩子
Tree* RightSibling(Tree* cur_e);//返回cur_e处结点的有兄弟
Tree* InsertChild(Tree* sontree, Tree* cur_e);//在cur_e结点处插入孩子
void DeleteChild(Tree* cur_e, unsigned int order);//
void TraverseTree(Tree* targeettree);

//二叉树
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
BinaryTree* BinaryTreeInit();//初始化二叉树
BinaryTree* DestroyBinaryTree(BinaryTree* targettree);//摧毁二叉树
BinaryTree* CreatBinaryTree(BinaryTree* targettree);
void ClearBinaryTree(BinaryTree* targettree);
int BinaryTreeEmpty(BinaryTree* targettree);
int BinaryTree_Depth(BinaryTree* targettree);//
BinaryTree* BinaryTree_Root(BinaryTree* targettree);
BinaryTreeTypeName BinaryTree_Value(BinaryTree* targettree);
void BinaryTree_Assign(BinaryTree* targettree,BinaryTreeTypeName value);//给结点分配值
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