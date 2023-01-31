#ifndef __MYSTREE_H
#define __MYSTREE_H
#include "main.h"
#define TreeTypeName int
#define TRUE 1
#define FALSE 0
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

#endif