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