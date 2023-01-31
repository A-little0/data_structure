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
int main(){
	//test01(1);
	test02();

	system("pause");
	return 0;
}