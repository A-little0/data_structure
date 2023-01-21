#include "main.h"
#include "myqueue.h"


void test01()
{
	Queue* myqueue = QueueInit();
	if (QueueEmpty(myqueue))
	{
		printf("queue init and funtion QueueEmpty success\r\n");
	}
	else
	{
		printf("queue init and funtion QueueEmpty fail\r\n");
	}
	EnQueue(10, myqueue);
	if (QueueEmpty(myqueue))
	{
		printf("Enqueue fail\r\n");
	}
	else
	{
		if (myqueue->dataarr[0]==10&&myqueue->rear==1)
		{
			printf("enqueue success\r\n");
		}
		else
		{
			printf("enqueue fail\r\n");
		}
	}
	int value = DeQueue(myqueue);
	if (value == 10)
	{
		if (QueueEmpty(myqueue))
		{
			printf("DeQueue success\r\n");
		}
		else
		{
			printf("DeQueue fail\r\n");
		}
	}
	else
	{
		printf("return value error\r\n");
	}
}

void test02()
{
	Queue* myqueue = QueueInit();
	if (QueueEmpty(myqueue))
	{
		printf("queue init and funtion QueueEmpty success\r\n");
	}
	else
	{
		printf("queue init and funtion QueueEmpty fail\r\n");
	}
	for (int i = 0; i < 10; i++)
	{
		EnQueue(10+i, myqueue);
	}
	//EnQueue(10, myqueue);
	int length = QueueLength(myqueue);
	printf("length:%d\r\n", length);
	//for (int j = 0; j < 10; j++)
	//{
	//	int temp = DeQueue(myqueue);
	//	printf("the %d yuanshu:\r\n", temp);
	//}
	//QueueTraverse(myqueue);
	DeQueue(myqueue);
	//QueueTraverse(myqueue);
	ClearQueue(myqueue);
	QueueTraverse(myqueue);

}

void test03()
{
	CQueue* mycqueue = CQueueInit();
	if (CQueueEmpty(mycqueue))
	{
		printf("cqueue init success\r\n");
	}
	else
	{
		printf("cqueue init fail\r\n");
	}

	EnCQueue(10, mycqueue);
	if (CQueueEmpty(mycqueue))
	{
		printf("EnCQueue fail\r\n");
	}
	else
	{
		if (10 == GetHead_C(mycqueue))
		{
			printf("put value success\r\n");
		}
		else
		{
			printf("put value fail\r\n");
		}
	}

	for (int i = 1; i <= 9; i++)
	{
		EnCQueue(10+i*10, mycqueue);
	}
	CQueueTraverse(mycqueue);
	EnCQueue(10, mycqueue);

	int popvalue=DeCQueue(mycqueue);
	printf("popvalue:%d\r\n", popvalue);
	CQueueTraverse(mycqueue);
}

void test04()
{
	CQueue* mycqueue = CQueueInit();

	EnCQueue(10, mycqueue);
	for (int i = 1; i <= 9; i++)
	{
		EnCQueue(10 + i * 10, mycqueue);
	}
	//CQueueTraverse(mycqueue);
	//EnCQueue(10, mycqueue);

	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	//CQueueTraverse(mycqueue);

	EnCQueue(10, mycqueue);
	EnCQueue(20, mycqueue);
	EnCQueue(30, mycqueue);
	EnCQueue(40, mycqueue);
	//CQueueTraverse(mycqueue);

	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	//CQueueTraverse(mycqueue);
	EnCQueue(50, mycqueue);
	EnCQueue(60, mycqueue);
	EnCQueue(70, mycqueue);
	EnCQueue(80, mycqueue);
	EnCQueue(90, mycqueue);
	EnCQueue(100, mycqueue);
	CQueueTraverse(mycqueue);

	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	//CQueueTraverse(mycqueue);

	EnCQueue(10, mycqueue);
	EnCQueue(20, mycqueue);
	EnCQueue(30, mycqueue);
	EnCQueue(40, mycqueue);
	//CQueueTraverse(mycqueue);

	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	DeCQueue(mycqueue);
	//CQueueTraverse(mycqueue);
	EnCQueue(50, mycqueue);
	EnCQueue(60, mycqueue);
	EnCQueue(70, mycqueue);
	EnCQueue(80, mycqueue);
	EnCQueue(90, mycqueue);
	EnCQueue(100, mycqueue);
	CQueueTraverse(mycqueue);


}


int main() {
	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	return 0;
}