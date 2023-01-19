#include "main.h"
#include "mystack.h"

void test01()
{
	Stack* mystack = StackInit();

	if (mystack->base == mystack->top)//³õÊ¼»¯²âÊÔ
	{
		printf("mystack init success\r\n");
	}
	else
	{
		printf("mystack init fail\r\n");
	}

	if (StackEmpty(mystack))//
	{
		printf("this mystack is empty\r\n");
	}
	else
	{
		printf("this Stack is not empty\r\n");
	}

	int length = GetStackLength(mystack);
	printf("length:%d\r\n", length);

	GetTop(mystack);

	Push(40, mystack);
	Push(50, mystack);
	if (StackEmpty(mystack))
	{
		printf("this mystack is empty\r\n");

	}
	else
	{
		printf("this smystack is not empty\r\n");
		if (*(mystack->base + 1) == 50)
		{
			printf("push success\r\n");
		}
		else
		{
			printf("push fail\r\n");
		}
	}

	Pop(mystack);
	if (GetStackLength(mystack) == 1)
	{
		printf("pop success\r\n");
	}
	else
	{
		printf("pop fail\r\n");
	}
	int length2 = GetStackLength(mystack);
	printf("length:%d\r\n", length2);


	Push(50, mystack);
	Push(60, mystack);
	Push(70, mystack);
	Push(80, mystack);
	Push(90, mystack);
	TraverseStack(mystack);
}
void test02()
{
	LinkstackTop mylinkstkTop = LinkStackInit();
	if (0 == mylinkstkTop->data && mylinkstkTop->p_next == NULL)
	{
		printf("link stack init success\r\n");
	}
	else
	{
		printf("link stack init fail\r\n");
	}
	mylinkstkTop = LinkStack_Push(20, mylinkstkTop);
	if (LinkStackEmpty(mylinkstkTop))
	{
		printf("push value error\r\n");
	}
	else
	{
		if (mylinkstkTop->data == 20)
		{
			printf("link stack push success\r\n");
		}
		else
		{
			printf("link stack push fail\r\n");
		}
	}
	mylinkstkTop = LinkStack_Push(30, mylinkstkTop);
	mylinkstkTop = LinkStack_Push(40, mylinkstkTop);
	mylinkstkTop = LinkStack_Push(50, mylinkstkTop);
	mylinkstkTop = LinkStack_Push(60, mylinkstkTop);
	int topdata = LinkStack_Gettop(mylinkstkTop);
	printf("top data: %d\r\n", topdata);
	mylinkstkTop = LinkStack_Pop(mylinkstkTop);
	mylinkstkTop = LinkStack_Pop(mylinkstkTop);
	mylinkstkTop = LinkStack_Pop(mylinkstkTop);
	mylinkstkTop = LinkStack_Pop(mylinkstkTop);
	mylinkstkTop = LinkStack_Pop(mylinkstkTop);
	mylinkstkTop = LinkStack_Pop(mylinkstkTop);

}


int main() {
	//test01();
	test02();

	system("pause");
	return 0;
}