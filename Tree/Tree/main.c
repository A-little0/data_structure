#include "main.h"
#include "mytree.h"

int test01(int a)
{
	if (a < 10)
	{
		int temp = a + 1;
		test01(temp);
		printf("%d", temp);
	}
}

void test02()
{
	Tree* mytree = TreeInit();

	Tree* mytree1 = TreeInit();
	Tree* mytree1_son = TreeInit();
	Tree* mytree1_son_bro = TreeInit();

	Tree* mytree1_2 = TreeInit();
	Tree* mytree1_3 = TreeInit();
	Tree* mytree1_4 = TreeInit();
	Tree* mytree1_3_son = TreeInit();

	mytree->data = 10;
	mytree1->data = 20;
	mytree1_son->data = 30;
	mytree1_son_bro->data= 40;
	mytree1_2->data = 50;
	mytree1_3->data = 60;
	mytree1_4->data = 70;
	mytree1_3_son->data = 80;

	mytree->ptr.son = mytree1;
	mytree->ptr.bro = mytree1_2;
	mytree->ptr.bro->ptr.bro = mytree1_3;
	mytree->ptr.bro->ptr.bro->ptr.bro = mytree1_4;

	mytree1->ptr.son = mytree1_son;
	mytree1->ptr.bro = mytree1_son_bro;

	mytree1_3->ptr.son = mytree1_3_son;

	TraverseTree(mytree);

	//DestroyTree(mytree);
	//if (mytree != NULL)
	//{
	//	printf("the circle root live\r\n");
	//	free(mytree->ptr.son);
	//}
	//else
	//{
	//	printf("this tree is emptytree\r\n");
	//}
}
void test03()
{
	BinaryTree* mybitree = BinaryTreeInit();

	BinaryTree* mybitree1 = BinaryTreeInit();
	BinaryTree* mybitree2 = BinaryTreeInit();

	BinaryTree* mybitree1_3 = BinaryTreeInit();
	BinaryTree* mybitree1_4 = BinaryTreeInit();
	BinaryTree* mybitree2_5 = BinaryTreeInit();
	BinaryTree* mybitree2_6 = BinaryTreeInit();

	BinaryTree* mybitree1_3_7 = BinaryTreeInit();
	BinaryTree* mybitree1_3_8 = BinaryTreeInit();

	BinaryTree* mybitree2_5_9 = BinaryTreeInit();
	BinaryTree* mybitree2_5_9_10 = BinaryTreeInit();


	mybitree->data = 0;
	mybitree1->data = 1;
	mybitree2->data = 2;
	mybitree1_3->data = 3;
	mybitree1_4->data = 4;
	mybitree2_5->data = 5;
	mybitree2_6->data = 6;
	mybitree1_3_7->data = 7;
	mybitree1_3_8->data = 8;
	mybitree2_5_9->data = 9;
	mybitree2_5_9_10->data = 10;

	mybitree->ptr.leftchild = mybitree1;
	mybitree->ptr.rightchild = mybitree2;
	//int a = BinaryTree_Depth(mybitree);
	//printf("depth:%d\r\n", a);
	mybitree1->ptr.leftchild = mybitree1_3;
	mybitree1->ptr.rightchild = mybitree1_4;
	mybitree2->ptr.leftchild = mybitree2_5;
	mybitree2->ptr.rightchild = mybitree2_6;
	//int a = BinaryTree_Depth(mybitree);
	//printf("depth:%d\r\n", a);
	mybitree1_3->ptr.leftchild = mybitree1_3_7;
	mybitree1_3->ptr.rightchild = mybitree1_3_8;
	//int a = BinaryTree_Depth(mybitree);
	//printf("depth:%d\r\n", a);
	mybitree2_5->ptr.leftchild = mybitree2_5_9;
	mybitree2_5_9->ptr.leftchild = mybitree2_5_9_10;

	int depth = BinaryTree_Depth(mybitree);
	if (depth == 6)
	{
		printf("function of depth successed\r\n");
	}
	else
	{
		printf("function of depth fail\r\n");
	}
	BinaryTree_Assign(mybitree, -1);
	if (mybitree->data == -1)
	{
		printf("function of BinaryTree_Assign succssed\r\n");
	}
	else
	{
		printf("function of BinaryTree_Assign fail\r\n");
	}

	SonJudge(mybitree, mybitree2_5_9_10);
	extern int compare;
	if (compare == 1)
	{
		compare = 0;
		printf("function of SonJudge successed\r\n");
	}
	else
	{
		printf("function of SonJudge fail\r\n");
	}
	PreOrderTraverse(mybitree);//-1 //-1 1 3 7 8 4 2 5 9 10 6
							//1     2	
						//3 4      5 6
					//7 8		 9
							 //10
	printf("function of PrOrderTraverse successed\r\n");
	InOrderTraverse(mybitree);//7 3 8 1 4 -1 10 9 5 2 6
	printf("function of InOrderTraverse successed\r\n");
	PostOrderTraverse(mybitree);//7 8  3 4 1 10 9 5 6 2 -1
	printf("functon of PostOrderTraverse successed\r\n");


	//DestroyBinaryTree(mybitree);
	ClearBinaryTree(mybitree);
	if (mybitree->ptr.leftchild == NULL && mybitree->ptr.rightchild == NULL)
	{
		printf("function of ClearBinaryTree successed\r\n");
	}
	else
	{
		printf("finction of ClearBinaryTree failed\r\n");
	}	
	
	mybitree = DestroyBinaryTree(mybitree);
	if (mybitree == NULL)
	{
		printf("function of DestroyBinaryTree successed\r\n");
	}
	else
	{
		printf("function of DestroyBinaryTree fail\r\n");
	}
}
int main(){
	//test01(1);
	test03();

	system("pause");
	return 0;
}