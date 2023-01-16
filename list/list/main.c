#include "main.h"
#include "mylist.h"


void test01()
{
	//list l;
	//l.value = 10;
	//l.p_next = NULL;
	//push_back(30, &l);
	//push_back(40, &l);
	//int a = l.p_next->value;
	//printf("%d", a);

}
void test02()
{
	list* mylist = list_Init();
	push_back(40, mylist);
	push_back(30, mylist);
	push_back(20, mylist);
	push_back(10, mylist);
	//pop_back(mylist);
	//show_value(3, mylist);
	//insert(40, 4, mylist);
	//delete(4, mylist);
	//repleace(4, 40, mylist);
	//repleace_t(40, 50, mylist);
	sort_value(mylist);
	sortReverse_valueC(mylist);
	//sortReverse_value(mylist);
	//sort_valueC(mylist);
	show_somevalue(1, 4, mylist);
	//find(30, mylist);
	//int a = mylist->p_next->p_next->p_next->value;
	//printf("%d",a);


}

void clisttest01()
{
	clist* myclist = clist_Init();
	if (emptyClist(myclist))
	{
		printf("this clist is empty\r\n");
	}
	else
	{
		printf("this clist is not empty\r\n");
	}
	
	push_back_c(40, myclist);
	if (myclist->p_next->value == 40)
	{
		printf("push back value success\r\n");
		if (myclist->p_next->p_next == myclist)
		{
			printf("point success\r\n");
		}
		else
		{
			printf("point false\r\n");
		}
	}
	else
	{
		printf("push back value false\r\n");
	}
	
	pop_back_c(myclist);
	if (emptyClist(myclist))
	{
		printf("this clist is empty and pop back success\r\n");
	}
	else
	{
		printf("this clist is not empty so pop back false\r\n");
	}
	if (myclist->p_next == myclist)
	{
		printf("point success\r\n");
	}
	else
	{
		printf("point false\r\n");
	}
}
void dlisttest01()
{
	dlist* mydlist = dlist_Init();
	if (emptyDlist(mydlist))
	{
		printf("this dlist is empty\r\n");
	}
	else
	{
		printf("this dlist is not empty\r\n");
	}

	push_back_d(40, mydlist);
	if (mydlist->p_next->value == 40)
	{
		printf("push back value success\r\n");
		if (mydlist->p_next->p_next == mydlist&&mydlist->p_last->value==40)
		{
			printf("point success\r\n");
		}
		else
		{
			printf("point false\r\n");
		}
	}
	else
	{
		printf("push back value false\r\n");
	}

	pop_back_d(mydlist);
	if (emptyDlist(mydlist))
	{
		printf("this dlist is empty and pop back success\r\n");
	}
	else
	{
		printf("this dlist is not empty so pop back false\r\n");
	}
	if (mydlist->p_next == mydlist&&mydlist->p_last==mydlist)
	{
		printf("point success\r\n");
	}
	else
	{
		printf("point false\r\n");
	}
}
void freetest()
{
	clist* myclist = clist_Init();
	if (emptyClist(myclist))
	{
		printf("this clist is empty\r\n");
	}
	else
	{
		printf("this clist is not empty\r\n");
	}
	//push_back_c(40, myclist);
	destroyC(myclist);

	//dlist* mydlist = dlist_Init();
	//if (emptyDlist(mydlist))
	//{
	//	printf("this dlist is empty\r\n");
	//}
	//else
	//{
	//	printf("this dlist is not empty\r\n");
	//}
	//push_back_d(40, mydlist);
	//destroyD(mydlist);
}

int main() {
	//test02();
	//clisttest01();
	//dlisttest01();
	freetest();
	system("pause");
	return 0;
}

