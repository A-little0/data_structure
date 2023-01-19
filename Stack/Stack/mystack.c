#include "mystack.h"
#include "malloc.h"

Stack* StackInit()//��ʼ��˳��ջ
{
	Stack* newstack = (Stack*)malloc(sizeof(Stack));
	if (newstack != NULL)
	{
		newstack->base = &(newstack->StaticArr[0]);
		newstack->top = newstack->base;

		return newstack;
	}
	else
	{
		printf("Stack init error:no enough space to init\r\n");
	}
}
void DestroyStack(Stack* targetstack)//�ݻ�˳��ջ
{
	if (targetstack != NULL)
	{
		free(targetstack);
	}
	else
	{
		printf("DestroyStack error:this pointer is null\r\n");
	}
}
void CleanStack(Stack* targetstack)//���˳��ջ
{
	if (targetstack != NULL)
	{
		targetstack->top = targetstack->base;
	}
	else
	{
		printf("clean stack error: this pointer is null\r\n");
	}
}
int StackEmpty(Stack* targetstack)//�ж�˳��ջ�Ƿ�Ϊ�գ�Ϊ���򷵻�true ���򷵻�false
{
	if (targetstack->top == targetstack->base)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int GetStackLength(Stack* targetstack)//��ȡջ��Ԫ�ظ���
{
	return targetstack->top - targetstack->base;
}
int GetTop(Stack* targetstack)//��ȡ˳��ջ����Ԫ��
{
	if (StackEmpty(targetstack))
	{
		printf("get top error:this stack is empty\r\n");
	}
	else
	{
		return *(targetstack->top - 1);
	}
}
void Push(const int value, Stack* targetstack)//��ջ
{
	if (targetstack->top - targetstack->base < MAXSIZE)
	{
		*(targetstack->top) = value;
		targetstack->top++;
	}
	else
	{
		printf("push error:this stack is full\r\n");
	}
}
int Pop(Stack* targetstack)//��ջ
{
	if (StackEmpty(targetstack))
	{
		printf("pop error:this stack is empty\r\n");
	}
	else
	{
		targetstack->top--;
		return *(targetstack->top);
	}
}
void TraverseStack(Stack* targetstack)//����˳��ջ��Ԫ�أ���ջ����ջ��˳�������
{
	if (StackEmpty(targetstack))
	{
		printf("this stack is empty\r\n");
	}
	else
	{
		for (int i = 1; i <= targetstack->top - targetstack->base; i++)
		{
			int temp = *(targetstack->top - i);
			printf("top%d:%d\r\n", i, temp);
		}
	}
}


LinkStack* LinkStackInit()
{
	LinkStack* newlinkstack = (LinkStack*)malloc(sizeof(LinkStack));
	if (newlinkstack != NULL)
	{
		newlinkstack->data = 0;
		newlinkstack->p_next = NULL;
		return newlinkstack;
	}
	else
	{
		printf("link stack init error:no enough space to init\r\n");
	}
}
int LinkStackEmpty(LinkStack* targetlinkstack)
{
	if (targetlinkstack->p_next == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int LinkStack_GetLength(LinkStack* targetlinkstack)
{
	int length = 0;
	LinkStack* top = targetlinkstack;
	for (; top->p_next != NULL; length++)
	{
		top = top->p_next;
	}
	return length;
}

LinkStack* LinkStack_Push(const int value, LinkStack* targetlinkstack)
{
	LinkStack* newlinkstack = (LinkStack*)malloc(sizeof(LinkStack));
	if (newlinkstack != NULL)
	{
		newlinkstack->data = value;
		newlinkstack->p_next = targetlinkstack;
		return newlinkstack;
	}
	else
	{
		printf("link stack push error:no enough space to push\r\n");
	}
}
LinkStack* LinkStack_Pop(LinkStack* targetlinkstack)
{
	if (LinkStackEmpty(targetlinkstack))
	{
		printf("link stack pop error:this link stack is empty\r\n");
	}
	else
	{
		int topdata = targetlinkstack->data;
		LinkStack* freetop = targetlinkstack;
		targetlinkstack = targetlinkstack->p_next;
		free(freetop);
		return targetlinkstack;
	}
}
int LinkStack_Gettop(LinkStack* targetlinkstack)
{
	if (LinkStackEmpty(targetlinkstack))
	{
		printf("link stack gettop error:this stack is empty\r\n");
	}
	else
	{
		return targetlinkstack->data;
	}
}