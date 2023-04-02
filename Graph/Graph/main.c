#include "main.h"
#include "graph.h"
#include "malloc.h"



void test01()
{
	char* p[3] = {
		"hello",
		"ok",
		"end"
	};
	printf("%s\r\n", *(p+1));
}
void test02()
{
	AM_to_Graph* mygraph = creatAdjacencyMatrix_toGraph(5);
	for (int i = 0; i < mygraph->vexnum; i++)
	{
		for (int j = 0; j < mygraph->vexnum; j++)
		{
			printf("arr[%d][%d]:%d  ", i, j,mygraph->linkarr[i][j]);
		}
		printf("\r\n");
	}
}
void test03()
{
	int* begin = (int*)malloc(sizeof(int) * 25);
	if (begin != NULL)
	{
		int* move = begin;
		for (int i = 0; i < 25; i++)
		{
			*(begin + i) = i;
		}
		for (int j = 0; j < 25; j++)
		{
			printf("%d\r\n", *(begin + j));
		}
		printf("----------------\r\n");
		int(*p)[5];// = begin;
		p = begin;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				printf("%d ", p[i][j]);
			}
			printf("\r\n");
		}

	}

}
//void test04()
//{
//	int* arr = (int*)malloc(sizeof(int) * 5);
//	int(*p)[10];
//	p = arr;
//	if (p != NULL)
//	{
//		for (int i = 0; i < 5; i++)
//		{
//			p[0][i] = i;
//		}
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d\r\n", p[0][j]);
//		}
//	}
//}
void test05()
{
	UnGraph* myUngraph = creatUnGraph(5);
	for (int i = 0; i < myUngraph->am->vexnum; i++)
	{
		for (int j = 0; j < myUngraph->am->vexnum; j++)
		{
			printf("AMarr[%d][%d]=%d ", i, j,myUngraph->am->linkarr[i][j]);
		}
		printf("\r\n");
	}
	printf("--------------------------------------------------------\r\n");
	for (int i = 0; i < myUngraph->am->vexnum; i++)
	{
		printf("Dataarr[%d}=%d", i, myUngraph->data[i]);
	}
	printf("\n");
}

void test06()
{
	UnGraph* myUngraph = creatUnGraph(5);
	for (int i = 0; i < myUngraph->am->vexnum; i++)
	{
		for (int j = 0; j < myUngraph->am->vexnum; j++)
		{
			printf("AMarr[%d][%d]=%d ", i, j, myUngraph->am->linkarr[i][j]);
		}
		printf("\r\n");
	}
	printf("--------------------------------------------------------\r\n");
	for (int i = 0; i < myUngraph->am->vexnum; i++)
	{
		printf("Dataarr[%d}=%d", i, myUngraph->data[i]);
	}
	printf("\n");

	int a = locateVex(myUngraph, 4);
	if (a == 4)
	{
		printf("success to func of locateVex\r\n ");
	}
	else
	{
		printf("fail to func of locateVex\r\n");
	}

	int b = getVex(myUngraph, 4);
	if (b == 4)
	{
		printf("success to func of getVex\r\n");
	}
	else
	{
		printf("fail to func of getVex\r\n");
	}

	putVex(myUngraph,4,10);
	if (myUngraph->data[4] == 10)
	{
		printf("success to func of putVex\r\n");
	}
	else
	{
		printf("fail to func of putVex\r\n");
	}
	int c = firstAdjVex(myUngraph, 0);
	if (myUngraph->am->linkarr[0][c] == 1)
	{
		for (int i = 0; i != c && i < myUngraph->am->vexnum; i++)
		{
			if (myUngraph->am->linkarr[0][i] == 1)
			{
				printf("fail to func of firstAdjVex\r\n");
			}
		}
		printf("success to func of firstAdjVex\r\n");
	}
	else
	{
		printf("fail to func of firstAdjVex\r\n");
	}
}


int main() {

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();

	system("pause");
	return 0;
}