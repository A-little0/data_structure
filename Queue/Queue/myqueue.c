#include "myqueue.h"
#include "malloc.h"

Queue* QueueInit()//��ʼ������
{
	Queue* newqueue = (Queue*)malloc(sizeof(Queue));
	if (newqueue != NULL)
	{
		//���������һ���ռ���Ԫ��
		//front==rear==0ʱ����Ϊ��
		newqueue->front = 0;
		newqueue->rear = 0;
	}
	else
	{
		printf("Queue init error:no enough space to init\r\n");
	}
}
void DestroyQueue(Queue* targetqueue)//�ݻٶ���
{
	free(targetqueue);
}
void ClearQueue(Queue* targetqueue)//��ն���
{
	targetqueue->front = 0;
	targetqueue->rear = 0;
}
int QueueEmpty(Queue* targetqueue)//�ж϶����Ƿ�Ϊ�գ��Ƿ���TRUE,���򷵻�FALSE
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
int QueueLength(Queue* targetqueue)//��ȡ���еĳ���
{
	return targetqueue->rear - targetqueue->front;
}
int GetHead(Queue* targetqueue)//��ȡͷԪ��
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
void EnQueue(const int value, Queue* targetqueue)//�����
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
int DeQueue(Queue* targetqueue)//������
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
void QueueTraverse(Queue* targetqueue)//��������
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
