#include "myqueue.h"
#include "malloc.h"

Queue* QueueInit()//初始化队列
{
	Queue* newqueue = (Queue*)malloc(sizeof(Queue));
	if (newqueue != NULL)
	{
		//队列数组第一个空间存放元素
		//front==rear==0时队列为空
		newqueue->front = 0;
		newqueue->rear = 0;
	}
	else
	{
		printf("Queue init error:no enough space to init\r\n");
	}
}
void DestroyQueue(Queue* targetqueue)//摧毁队列
{
	free(targetqueue);
}
void ClearQueue(Queue* targetqueue)//清空队列
{
	targetqueue->front = 0;
	targetqueue->rear = 0;
}
int QueueEmpty(Queue* targetqueue)//判断队列是否为空，是返回TRUE,否则返回FALSE
{
	if (targetqueue->front == 0 && targetqueue->rear == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int QueueLength(Queue* targetqueue)//获取队列的长度
{
	return targetqueue->rear - targetqueue->front;
}
int GetHead(Queue* targetqueue)//获取头元素
{
	if (QueueEmpty(targetqueue))
	{
		printf("get head error:this queue is empty\r\n");
	}
	else
	{
		return targetqueue->dataarr[targetqueue->front];
	}
}
void EnQueue(const int value, Queue* targetqueue)//入队列
{
	if (targetqueue->rear < MAXSIZE)
	{
		targetqueue->dataarr[targetqueue->rear] = value;
		targetqueue->rear++;
	}
	else
	{
		printf("EnQueue error:this queue this fall\r\n");
	}
}
int DeQueue(Queue* targetqueue)//出队列
{
	if (QueueEmpty(targetqueue))
	{
		printf("Dequeue error:this queue this empty\r\n");
	}
	else
	{
		int popvalue = 0;
		popvalue = targetqueue->dataarr[targetqueue->front];
		targetqueue->front++;
		if (targetqueue->front == targetqueue->rear)
		{
			targetqueue->front = 0;
			targetqueue->rear = 0;
		}
		return popvalue;
	}
}
void QueueTraverse(Queue* targetqueue)//遍历队列
{
	if (QueueEmpty(targetqueue))
	{
		printf("traverse queue error:this queue is empty\r\n");
	}
	else
	{
		int length = QueueLength(targetqueue);
		for (int i = 0; i < length; i++)
		{
			int topvalue = targetqueue->dataarr[targetqueue->front + i];
			printf("top%d:%d\r\n",i,topvalue);
		}
	}
}
