#ifndef __MYSTATIC_H
#define __MYSTATIC_H
#include "main.h"

#define MAXSIZE 200
#define TRUE 1
#define FALSE 0

//˳��ջ
typedef struct Stack {

	int StaticArr[MAXSIZE];
	int* top;
	int* base;
}Stack;

Stack* StackInit();//��ʼ��˳��ջ
void DestroyStack(Stack* targetstack);//�ݻ�˳��ջ
void CleanStack(Stack* targetstack);//���˳��ջ
int StackEmpty(Stack* targetstack);//�ж�˳��ջ�Ƿ�Ϊ�գ�Ϊ���򷵻�true ���򷵻�false
int GetStackLength(Stack* targetstack);//��ȡջ��Ԫ�ظ���
int GetTop(Stack* targetstack);//��ȡ˳��ջ����Ԫ��
void Push(const int value, Stack* targetstack);//��ջ
int Pop(Stack* targetstack);//��ջ
void TraverseStack(Stack* targetstack);//����˳��ջ��Ԫ�أ���ջ����ջ��˳�������

//��ջ
typedef struct LinkStack {
	int data;
	struct LinkStack* p_next;
}LinkStack, * LinkstackTop;



LinkStack* LinkStackInit();
int LinkStackEmpty(LinkStack* targetlinkstack);
LinkStack* LinkStack_Push(const int valuse, LinkStack* targetlinkstack);
LinkStack* LinkStack_Pop(LinkStack* targetlinkstack);
int LinkStack_Gettop(LinkStack* targetlinkstack);
#endif

