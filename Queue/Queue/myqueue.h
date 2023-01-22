#ifndef __MYQUEUE_H
#define __MYQUEUE_H
#include "main.h"
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0

//顺序队列
typedef struct Queue {
	int dataarr[MAXSIZE];
	int front;
	int rear;
}Queue;

Queue* QueueInit();//初始化队列
void DestroyQueue(Queue* targetqueue);//摧毁队列
void ClearQueue(Queue* targetqueue);//清空队列
int QueueEmpty(Queue* targetqueue);//判断队列是否为空，是返回TRUE,否则返回FALSE
int QueueLength(Queue* targetqueue);//获取队列的长度
int GetHead(Queue* targetqueue);//获取头元素
void EnQueue(const int value,Queue* targetqueue);//入队列
int DeQueue(Queue* targetqueue);//出队列
void QueueTraverse(Queue* targetqueue);//遍历队列

//循环队列（可以解决顺序队列假溢出问题）
typedef struct CQueue {
	int dataarr[MAXSIZE];
	int frone;
	int rear;
}CQueue;

CQueue* CQueueInit();
void DestroyCQueue(CQueue* targetcqueue);
void ClearCQueue(CQueue* targetcqueue);
int CQueueEmpty(CQueue* targetcqueue);
int CQueueLength(CQueue* targetcqueue);
int GetHead_C(CQueue* targetcqueue);
void EnCQueue(const int value, CQueue* targetcqueue);
int DeCQueue(CQueue* targetcqueue);
void CQueueTraverse(CQueue* targetcqueue);

//链队列
typedef struct LinkQueue {
	int data;
	struct LinkQueue* next;
}LinkQueue;

LinkQueue* LinkQueueInit();
void DestroyLinkQueue(LinkQueue* targetlinkqueue);
void ClearLinkQueue(LinkQueue* targetlinkqueue);
int LinkQueueEmpty(LinkQueue* targetlinkqueue);
int LinkQueueLength(LinkQueue* targetlinkqueue);
int GetHead_L(LinkQueue* targetlinkqueue);
void EnLinkQueue(const int value,LinkQueue* targetlinkqueue);
int DeLinkQueue(LinkQueue* targetlinkqueue);
void LinkQueueTraverse(LinkQueue* targetlinkqueue);
#endif
