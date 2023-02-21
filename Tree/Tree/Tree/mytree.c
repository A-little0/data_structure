#include "mytree.h"
#include "malloc.h"
#pragma warning(disable:4996)


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
void DestroyTree(Tree* targettree)//�ݻ���
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
//CreatTree();//�����幹����
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
Tree* Root(Tree* targettree)//�����ڣ��򷵻�����
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
TreeTypeName Value( Tree* cur_e)//cur_e����t��ĳ����㣻          
{
	if (cur_e != NULL)
	{
		return cur_e->data;
	}
	else
	{
		printf("�����㲻����\r\n");
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
		printf("Assign error:�����㲻����\r\n");
	}
}
Tree* Parent(Tree* cur_e)//����cur_e������˫��
{
	if (cur_e != NULL)
	{
		return cur_e->ptr.par;
	}
	else
	{
		printf("Parent error:����ڵ㲻����\r\n");
	}
}
Tree* LeftChild(Tree* cur_e)//����cur_e����������
{
	if (cur_e != NULL)
	{
		return cur_e->ptr.son;
	}
	else
	{
		printf("LeftChild error:������Ϊ��\r\n");
	}
}
Tree* RightSibling(Tree* cur_e)//����cur_e���������ֵ�
{
	if (cur_e != NULL)
	{
		return cur_e->ptr.bro;
	}
	else
	{
		printf("RightSibiling error:�����㲻����\r\n");
	}
}
Tree* InsertChild(Tree* sontree, Tree* cur_e)//��cur_e��㴦���뺢��
{
	if (cur_e != NULL)
	{
		if (cur_e->ptr.son == NULL)
		{
			cur_e->ptr.son = sontree;
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
		printf("InsertChild error:�����㲻����\r\n");
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

void LevelOrderTraverse(BinaryTree* targettree)
{
	if (targettree != NULL)
	{
	    BiTreeQueue* queue = BiTreeQueueInit();
		Push(targettree, queue);
		BinaryTree* bitree=Pop(queue);
		int temp = bitree->data;
		printf("%d",temp);
		LevelOrderTraverse(targettree->ptr.leftchild);
		LevelOrderTraverse(targettree->ptr.rightchild);
		//Push(targettree->ptr.leftchild, queue);
		//Push(targettree->ptr.rightchild, queue);
	}
}

//��������
HuffmanTree* TreesArrInit(unsigned int treenum)
{
	HuffmanTree* TreesArr = (HuffmanTree*)calloc(treenum*2, sizeof(HuffmanTree));
	if (TreesArr != NULL)
	{
		//��ʼ��2n-1����
		HuffmanTree* trees = NULL;
		for (int i = 0; i < treenum * 2 ; i++)
		{
			trees = TreesArr;
			trees->weight = 0;
			trees->lefttree = NULL;
			trees->righttree = NULL;
			trees++;
		}
		//��n������Ȩֵ
		trees = TreesArr;
		trees++;//���±�Ϊ1��ʼ���룬��ŵ�Ȩֵ�洢���ĸ���
		for (int j = 0; j < treenum; j++)
		{
			int wightvalue = 0;
			printf("�������%d��Ȩֵ\r\n", j + 1);
			scanf("%d", &wightvalue);
			trees->weight = wightvalue;
			trees++;
		}

		trees = TreesArr;
		trees->weight = treenum; //��ŵ�Ȩֵ�洢���ĸ���

		return TreesArr;
	}
	else
	{
		printf("TreesArrInit error:no enough space to init\r\n");

		return NULL;
	}
}

void createHuffmanTree(HuffmanTree* treesarr)
{
	HuffmanTree* trees = treesarr;
	//int smallarr[2] = { 0 };//�ҵ���СȨ�ص�������������Ȩֵ���浽��������
	int nodenum = trees->weight;//���������ܸ���
	trees++;
	//
	int** comparearr = (int**)calloc(nodenum, sizeof(int*));
	for (int i = 0; i < nodenum; i++)
	{
		comparearr[i] = (int*)malloc(sizeof(int) * 2);
	}
	comparearr[0][0] = 0;
	comparearr[0][1] = 0;
	for (int i = 0; i < nodenum; i++)
	{
		comparearr[i][0] = trees->weight;
		comparearr[i][1] = i + 1;
		trees++;
	}
	trees = treesarr;
	trees++;
	for (int i = 0; i < nodenum; i++)
	{
		for (int j = 0; j < nodenum - i - 1; j++)
		{
			if (comparearr[j][0] > comparearr[j + 1][0])
			{
				int temp = comparearr[j][0];
				int temp2 = comparearr[j][1];
				comparearr[j][0] = comparearr[j + 1][0];
				comparearr[j][1] = comparearr[j + 1][1];
				comparearr[j + 1][0] = temp;
				comparearr[j + 1][1] = temp2;
			}
		}
	}

	//��ʼ�����������
	for (int i = 0; i < nodenum; i++) { trees++; }
	trees->weight = comparearr[0][0] + comparearr[1][0];
	trees->lefttree = treesarr + comparearr[0][1];
	trees->righttree = treesarr + comparearr[1][1];

	int j = 2;
	for(int i=0;i<nodenum-2;i++)
	{
		HuffmanTree* point = trees;
		if (j + 1< nodenum)
		{
			if (comparearr[j][0] != comparearr[j + 1][0])
			{
				trees++;
				trees->righttree = point;
				trees->lefttree = treesarr + comparearr[j][1];
				trees->weight = trees->lefttree->weight + trees->righttree->weight;
				printf("a:%d b:%d\r\n", trees->lefttree->weight, trees->righttree->weight);
				//printf("%d", trees->weight);
			}
			else if (comparearr[j][0] == comparearr[j + 1][0])
			{
				trees++;
				trees->weight = comparearr[j][0] * 2;
				j += 2;
			}
		}
		else
		{
			trees++;
			trees->righttree = point;
			trees->lefttree = treesarr + comparearr[j][1];
			trees->weight = trees->lefttree->weight + trees->righttree->weight;
			printf("a:%d b:%d\r\n", trees->lefttree->weight, trees->righttree->weight);
		}
		j++;
	}

	int* freepoint = NULL;
	for (int i = 0; i < nodenum; i++)
	{
		freepoint = comparearr[i];
		free(freepoint);
	}
	free(comparearr);
}
