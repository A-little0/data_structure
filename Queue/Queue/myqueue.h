#ifndef __MYQUEUE_H
#define __MYQUEUE_H
#include "main.h"
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0

typedef struct Queue {
	int dataarr[MAXSIZE];
	int front;
	int rear;
}Queue;

Queue* QueueInit();//��ʼ������
void DestroyQueue(Queue* targetqueue);//�ݻٶ���
void ClearQueue(Queue* targetqueue);//��ն���
int QueueEmpty(Queue* targetqueue);//�ж϶����Ƿ�Ϊ�գ��Ƿ���TRUE,���򷵻�FALSE
int QueueLength(Queue* targetqueue);//��ȡ���еĳ���
int GetHead(Queue* targetqueue);//��ȡͷԪ��
void EnQueue(const int value,Queue* targetqueue);//�����
int DeQueue(Queue* targetqueue);//������
void QueueTraverse(Queue* targetqueue);//��������
#endif
