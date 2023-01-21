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

//ѭ������
CQueue* CQueueInit()
{
	CQueue* newcqueue = (CQueue*)malloc(sizeof(CQueue));
	if (newcqueue != NULL)
	{
		newcqueue->frone = 0;
		newcqueue->rear = 0;
	}
	else
	{
		printf("CQueue init error:no enough space to init\r\n");
	}
	
}
void DestroyCQueue(CQueue* targetcqueue)
{
	free(targetcqueue);
}
void ClearCQueue(CQueue* targetcqueue)
{
	targetcqueue->frone = 0;
	targetcqueue->rear = 0;
}
int CQueueEmpty(CQueue* targetcqueue)
{
	if (targetcqueue->frone == 0 && targetcqueue->rear==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int CQueueLength(CQueue* targetcqueue)
{
	if (targetcqueue->rear > targetcqueue->frone)
	{
		int length = targetcqueue->rear - targetcqueue->frone;
		return length;
	}
	else if (targetcqueue->rear < targetcqueue->frone)
	{
		int length = targetcqueue->rear  + MAXSIZE - targetcqueue->frone;
		return length;
	}
	else if(targetcqueue->rear==targetcqueue->frone&&targetcqueue->frone!=0)
	{
		return MAXSIZE;
	}
	else
	{
		return 0;
	}
}
int GetHead_C(CQueue* targetcqueue)
{
	if (CQueueEmpty(targetcqueue))
	{
		printf("get head error:this cqueue is empty\r\n");
	}
	else
	{
		return targetcqueue->dataarr[targetcqueue->frone];
	}
}
void EnCQueue(const int value, CQueue* targetcqueue)
{
	int length = CQueueLength(targetcqueue);
	if (length < MAXSIZE)
	{
		if (targetcqueue->frone == 0)
		{
			targetcqueue->dataarr[targetcqueue->rear] = value;
			targetcqueue->rear++;
		}
		else
		{
			if (targetcqueue->rear > targetcqueue->frone)
			{
				targetcqueue->dataarr[targetcqueue->rear] = value;
				targetcqueue->rear++;
				if (targetcqueue->rear == MAXSIZE)
				{
					targetcqueue->rear = 0;
				}
			}
			else if (targetcqueue->rear < targetcqueue->frone)
			{
				targetcqueue->dataarr[targetcqueue->rear] = value;
				targetcqueue->rear++;
			}
		}
	}
	else 
	{
		printf("EnCQueue error:this cqueue is fall\r\n");
	}
}
int DeCQueue(CQueue* targetcqueue)
{
	if (CQueueEmpty(targetcqueue))
	{
		printf("DeCQueue error:this CQueue is emtpy\r\n");
	}
	else
	{
		//int length = CQueueLength(targetcqueue);
		if (targetcqueue->frone >= targetcqueue->rear)
		{
			int popvalue = targetcqueue->dataarr[targetcqueue->frone];
			targetcqueue->frone++;
			if (targetcqueue->frone == MAXSIZE)
			{
				targetcqueue->frone = 0;
			}
			return popvalue;
		}
		else if(targetcqueue->frone<targetcqueue->rear)
		{
			int popvalue = targetcqueue->dataarr[targetcqueue->frone];
			targetcqueue->frone++;
			if (targetcqueue->rear == MAXSIZE)
			{
				targetcqueue->rear = 0;
			}
			else if (targetcqueue->frone == targetcqueue->rear)
			{
				targetcqueue->frone = 0;
				targetcqueue->rear = 0;
			}

			return popvalue;
		}
	}
}
void CQueueTraverse(CQueue* targetcqueue)
{
	if (CQueueEmpty(targetcqueue))
	{
		printf("CQueueTraverse error:this CQueue is empty\r\n");
	}
	else
	{
		int length = CQueueLength(targetcqueue);
		int begin = targetcqueue->frone;
		for (int i = 1; i <= length; i++)
		{
			int showvalue = targetcqueue->dataarr[begin];
			printf("top%d:%d\r\n", i, showvalue);
			begin++;
			if (begin == MAXSIZE)
			{
				begin = 0;
			}
		}
	}
}