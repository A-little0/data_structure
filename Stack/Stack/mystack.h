#ifndef __MYSTATIC_H
#define __MYSTATIC_H
#include "main.h"

#define MAXSIZE 200
#define TRUE 1
#define FALSE 0

//顺序栈
typedef struct Stack {

	int StaticArr[MAXSIZE];
	int* top;
	int* base;
}Stack;

Stack* StackInit();//初始化顺序栈
void DestroyStack(Stack* targetstack);//摧毁顺序栈
void CleanStack(Stack* targetstack);//清空顺序栈
int StackEmpty(Stack* targetstack);//判断顺序栈是否为空，为空则返回true 否则返回false
int GetStackLength(Stack* targetstack);//获取栈的元素个数
int GetTop(Stack* targetstack);//获取顺序栈顶的元素
void Push(const int value, Stack* targetstack);//入栈
int Pop(Stack* targetstack);//出栈
void TraverseStack(Stack* targetstack);//遍历顺序栈中元素（从栈顶到栈底顺序遍历）

//链栈
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

