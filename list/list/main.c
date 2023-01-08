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
int main() {
	test02();



	system("pause");
	return 0;
}

