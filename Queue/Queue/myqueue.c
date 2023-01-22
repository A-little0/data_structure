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

//循环队列
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

//链队列
LinkQueue* LinkQueueInit()
{
	LinkQueue* newlinkqueue = (LinkQueue*)malloc(sizeof(LinkQueue));
	if (newlinkqueue != NULL)
	{
		newlinkqueue->data = -1;
		newlinkqueue->next = NULL;
	}
	else
	{
		printf("linkqueue init error:no enough space to init\r\n");
	}
}
void DestroyLinkQueue(LinkQueue* targetlinkqueue)
{
	LinkQueue* ptrfirst = targetlinkqueue;
	LinkQueue* ptrsecond = targetlinkqueue->next;
	while (ptrfirst!=NULL)
	{
		free(ptrfirst);
		ptrfirst = ptrsecond;
		if (ptrfirst==NULL)
		{
			;
		}
		else
		{
			ptrsecond = ptrfirst->next;
		}
	}
}
void ClearLinkQueue(LinkQueue* targetlinkqueue)
{
	LinkQueue* ptrfirst = targetlinkqueue->next;
	LinkQueue* ptrsecond = targetlinkqueue->next;
	while (ptrfirst != NULL)
	{
		ptrsecond = ptrfirst->next;
		free(ptrfirst);
		ptrfirst = ptrsecond;
		if (ptrfirst != NULL)
		{
			ptrsecond = ptrfirst->next;
		}
		else
		{
			;
		}
	}
}
int LinkQueueEmpty(LinkQueue* targetlinkqueue)
{
	if (targetlinkqueue->next == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int LinkQueueLength(LinkQueue* targetlinkqueue)
{
	int length = 0;
	LinkQueue* ptr = targetlinkqueue;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		length++;
	}

	return length;
}
int GetHead_L(LinkQueue* targetlinkqueue)
{
	if (LinkQueueEmpty(targetlinkqueue))
	{
		printf("GetHead_L error:this linkqueue is empty\r\n");
	}
	else
	{
		return targetlinkqueue->data;
	}
}
void EnLinkQueue(const int value, LinkQueue* targetlinkqueue)
{
	int length = LinkQueueLength(targetlinkqueue);
	LinkQueue* ptr = targetlinkqueue;
	for (int i = 0; i < length; i++)
	{
		ptr = ptr->next;
	}
	LinkQueue* newlinkqueue_note = (LinkQueue*)malloc(sizeof(LinkQueue));
	if (newlinkqueue_note != NULL)
	{
		newlinkqueue_note->data = value;
		newlinkqueue_note->next = NULL;
		ptr->next = newlinkqueue_note;
	}
	else
	{
		printf("EnLinkQueue error:no enough space to build new note\r\n");
	}
}
int DeLinkQueue(LinkQueue* targetlinkqueue)
{
	LinkQueue* ptr = targetlinkqueue;
	
	if (ptr->next != NULL)
	{
		int popvalue;
		popvalue = ptr->next->data;
		ptr = ptr->next->next;
		free(targetlinkqueue->next);
		targetlinkqueue->next = ptr;
		return popvalue;
	}
	else
	{
		printf("DeLinkQueue error:this LinkQueue is empty\r\n");
	}
	
}
void LinkQueueTraverse(LinkQueue* targetlinkqueue)
{
	if (LinkQueueEmpty(targetlinkqueue))
	{
		printf("LinkQueueTraverse error: this LinkQueue is empty\r\n");
	}
	else
	{
		LinkQueue* ptr = targetlinkqueue->next;
		for(int i=1; ptr != NULL;i++)
		{
			int showvalue = ptr->data;
			printf("top%d:%d\r\n", i, showvalue);
			ptr = ptr->next;
		}
	}
}