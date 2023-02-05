#include "mytree.h"
#include "malloc.h"



Tree* TreeInit()
{
	Tree* newtree = (Tree*)malloc(sizeof(Tree));
	if (newtree != NULL)
	{
		newtree->data = 0;
		newtree->ptr.bro = NULL;
		newtree->ptr.par = NULL;
		newtree->ptr.son = NULL;
	}
	else
	{
		printf("TreeInit error:no enough space to init\r\n");
	}
}
void DestroyTree(Tree* targettree)//摧毁树
{
	if (targettree != NULL)
	{
		if (targettree->ptr.son != NULL)
		{
			DestroyTree(targettree->ptr.son);
			free(targettree->ptr.son);
			printf("a\r\n");

		}
		if (targettree->ptr.bro != NULL)
		{
			DestroyTree(targettree->ptr.bro);
			free(targettree->ptr.bro);
			printf("b\r\n");
		}
	}
}
//CreatTree();//按定义构造树
void ClearTree(Tree* targettree)
{
	if (targettree->ptr.son != NULL)
	{
		DestroyTree(targettree->ptr.son);
		if (targettree->ptr.bro != NULL)
		{
			DestroyTree(targettree->ptr.son);
		}
	}
}
int TreeEmpty(Tree* targettree)
{
	if (targettree == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
unsigned int TreeDepth(Tree* targettree)
{
	if (targettree != NULL)
	{
		Tree* son_tree_max = targettree->ptr.son;
		Tree* son_tree_brother_move = son_tree_max->ptr.bro;
		while (son_tree_max != NULL || son_tree_brother_move != NULL)
		{
			int maxlength = TreeDepth(son_tree_max);
			int movelength = TreeDepth(son_tree_brother_move);

			if (maxlength > movelength)
			{
				son_tree_brother_move = son_tree_brother_move->ptr.bro;
				return 1 + maxlength;
			}
			else
			{
				son_tree_max = son_tree_brother_move;
				son_tree_brother_move = son_tree_brother_move->ptr.bro;
				return 1 + movelength;
			}

		}
	}
	else
	{
		return 0;
	}
}
Tree* Root(Tree* targettree)//树存在，则返回树根
{
	if (TreeEmpty(targettree))
	{
		return NULL;
	}
	else
	{
		return targettree;
	}
}
TreeTypeName Value( Tree* cur_e)//cur_e是树t的某个结点；          
{
	if (cur_e != NULL)
	{
		return cur_e->data;
	}
	else
	{
		printf("这个结点不存在\r\n");
	}
}
void Assign(Tree* cur_e, TreeTypeName value)
{
	if (cur_e != NULL)
	{
		cur_e->data = value;
	}
	else
	{
		printf("Assign error:这个结点不存在\r\n");
	}
}
Tree* Parent(Tree* cur_e)//返回cur_e处结点的双亲
{
	if (cur_e != NULL)
	{
		return cur_e->ptr.par;
	}
	else
	{
		printf("Parent error:这个节点不存在\r\n");
	}
}
Tree* LeftChild(Tree* cur_e)//返回cur_e处结点的左孩子
{
	if (cur_e != NULL)
	{
		return cur_e->ptr.son;
	}
	else
	{
		printf("LeftChild error:这个结点为空\r\n");
	}
}
Tree* RightSibling(Tree* cur_e)//返回cur_e处结点的右兄弟
{
	if (cur_e != NULL)
	{
		return cur_e->ptr.bro;
	}
	else
	{
		printf("RightSibiling error:这个结点不存在\r\n");
	}
}
Tree* InsertChild(Tree* sontree, Tree* cur_e)//在cur_e结点处插入孩子
{
	if (cur_e != NULL)
	{
		if (cur_e->ptr.son == NULL)
		{
			cur_e->ptr.son == sontree;
		}
		else
		{
			Tree* tempptr = cur_e->ptr.bro;
			while (tempptr->ptr.bro != NULL)
			{
				tempptr = tempptr->ptr.bro;
			}
			tempptr->ptr.bro = sontree;
		}
	}
	else
	{
		printf("InsertChild error:这个结点不存在\r\n");
	}

 }
void DeleteChild(Tree* cur_e,unsigned int order )//
{
	if (cur_e != NULL)
	{
		if (cur_e->ptr.son != NULL)
		{
			if (order == 1)
			{
				free(cur_e->ptr.son);
				cur_e->ptr.son = cur_e->ptr.bro;
				cur_e->ptr.bro = cur_e->ptr.bro->ptr.bro;
			}
			else if (order > 1&&cur_e->ptr.bro!=NULL)
			{
				Tree* tempptr=cur_e->ptr.bro;
				int i = 2;
				for (;tempptr!=NULL ; i++)
				{
					if (i == order)
					{
						free(tempptr);
						break;
					}
					tempptr = tempptr->ptr.bro;
				}
				if (i < order)
				{
					printf("this tree son < %d\r\n", order);
				}
			}
		}
		else
		{
			printf("detechild error:this tree have not son tree\r\n");
		}
	}
	else
	{
		printf("deletechild error:this tree is emptyr\r\n");
	}
}
void TraverseTree(Tree* targettree)
{
	if (targettree != NULL)
	{
		TraverseTree(targettree->ptr.son);
		TraverseTree(targettree->ptr.bro);
		
		TreeTypeName value=targettree->data;
		printf("value:%d\r\n", value);
	}
}

BinaryTree* BinaryTreeInit()
{
	BinaryTree* newbitree = (BinaryTree*)malloc(sizeof(BinaryTree));
	if (newbitree != NULL)
	{
		newbitree->data = 0;
		newbitree->ptr.parent = NULL;
		newbitree->ptr.leftchild = NULL;
		newbitree->ptr.rightchild = NULL;
	}
	else
	{
		printf("BinaryTreeInit error:no enough space to init\r\n");
	}
}
BinaryTree* DestroyBinaryTree(BinaryTree* targettree)
{
	if (targettree != NULL)
	{
		ClearBinaryTree(targettree);
		free(targettree);
		targettree = NULL;
		return targettree;
	}
	else
	{
		printf("DestroyBinaryTree error:this binarytree is empty\r\n");
	}
}
BinaryTree* CreatBinaryTree(BinaryTree* targettree);
void ClearBinaryTree(BinaryTree* targettree)
{
	if (targettree != NULL)
	{
		if (targettree->ptr.leftchild != NULL);
		{
			ClearBinaryTree(targettree->ptr.leftchild);
			free(targettree->ptr.leftchild);
			targettree->ptr.leftchild = NULL;
		}
		if (targettree->ptr.rightchild != NULL)
		{
			ClearBinaryTree(targettree->ptr.rightchild);
			free(targettree->ptr.rightchild);
			targettree->ptr.rightchild = NULL;
		}
	}
}

int BinaryTreeEmpty(BinaryTree* targettree)
{
	if (targettree == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int BinaryTree_Depth(BinaryTree* targettree)
{
	if (targettree != NULL)
	{
		int lefttreeLength = 0;
		int	righttreeLength = 0;
		lefttreeLength = BinaryTree_Depth(targettree->ptr.leftchild) + 1;
		righttreeLength = BinaryTree_Depth(targettree->ptr.rightchild) + 1;
		return (lefttreeLength >= righttreeLength ? lefttreeLength: righttreeLength);
	}
}
BinaryTree* BinaryTree_Root(BinaryTree* targettree)
{
	if (targettree != NULL)
	{
		return targettree;
	}
	else
	{
		return NULL;
	}
}
BinaryTreeTypeName BinaryTree_Value(BinaryTree* targettree)
{
	if (targettree != NULL)
	{
		return targettree->data;
	}
	else
	{
		printf("BinaryTree_Value error:this binarytree is empty\r\n");
	}
}
void BinaryTree_Assign(BinaryTree* targettree, BinaryTreeTypeName value)
{
	if (targettree != NULL)
	{
		targettree->data = value;
	}
	else
	{
		printf("BinaryTree_Assign error:this binarytree is empty\r\n");
	}
}
BinaryTree* BinaryTree_LeftChild(BinaryTree* targettree)
{
	if (!BinaryTreeEmpty(targettree))
	{
		return targettree->ptr.leftchild;
	}
}
BinaryTree* BinaryTree_RightChild(BinaryTree* targettree)
{
	if (!BinaryTreeEmpty(targettree))
	{
		return targettree->ptr.rightchild;
	}
}

int compare = 0;
void SonJudge(BinaryTree* targettree, BinaryTree* tree_e)
{
	if (targettree != NULL)
	{
		if (targettree->ptr.leftchild == tree_e || targettree->ptr.rightchild == tree_e)
		{
			compare = 1;
		}
		SonJudge(targettree->ptr.leftchild, tree_e);
		SonJudge(targettree->ptr.rightchild, tree_e);
	}
}
BinaryTree* BinaryTree_LeftSibling(BinaryTree* targettree, BinaryTree* tree_e)
{
	
	if (targettree != NULL)
	{
		SonJudge(targettree, tree_e);
		if (compare == 1)
		{
			compare = 0;
			return tree_e->ptr.leftchild;
		}
		else
		{
			printf("Left tree is not right tree's father\r\n");
			return NULL;
		}
	}
}
BinaryTree* BinaryTree_RightSibling(BinaryTree* targettree, BinaryTree* tree_e)
{
	if (targettree != NULL)
	{
		SonJudge(targettree, tree_e);
		if (compare == 1)
		{
			compare = 0;
			return tree_e->ptr.rightchild;
		}
		else
		{
			printf("Left tree is not right tree's father\r\n");
			return NULL;
		}
	}
}
void BinaryTree_InsertChild(BinaryTree* targettree, BinaryTree* tree_e, BinaryTree* child, enum LeftOrRight LR)
{
	if (targettree != NULL && child->ptr.rightchild==NULL)
	{
		SonJudge(targettree, tree_e);
		if (compare == 1)
		{
			compare = 0;
			if (LR == L)
			{
				child->ptr.rightchild = tree_e->ptr.leftchild;
				tree_e->ptr.leftchild = child;
			}
			else if (LR == R)
			{
				child->ptr.rightchild = tree_e->ptr.rightchild;
				tree_e->ptr.rightchild = child;
			}
		}
		else
		{
			printf("the first bitree is not the second bitree's partent\r\n");
		}
	}
}
void BinaryTree_DeleteChild(BinaryTree* targettree)
{
	if (targettree!= NULL)
	{
		DestroyBinaryTree(targettree->ptr.leftchild);
		DestroyBinaryTree(targettree->ptr.rightchild);
	}
	else
	{
		printf("this binary tree is emptytree\r\n");
	}
}
void PreOrderTraverse(BinaryTree* targettree)
{
	if (targettree != NULL)
	{
		printf("%d", targettree->data);
		//printf("%d", targettree->ptr.leftchild->data);
		//printf("%d", targettree->ptr.rightchild->data);
		PreOrderTraverse(targettree->ptr.leftchild);
		PreOrderTraverse(targettree->ptr.rightchild);
	}
}
void InOrderTraverse(BinaryTree* targettree)
{
	if (targettree != NULL)
	{	
		InOrderTraverse(targettree->ptr.leftchild);
		printf("%d", targettree->data);
		InOrderTraverse(targettree->ptr.rightchild);
	}
}
void PostOrderTraverse(BinaryTree* targettree)
{
	if (!BinaryTreeEmpty(targettree))
	{
		PostOrderTraverse(targettree->ptr.leftchild);
		PostOrderTraverse(targettree->ptr.rightchild);
		printf("%d", targettree->data);
	}
}
void LevelOrderTraverse(BinaryTree* targettree);

