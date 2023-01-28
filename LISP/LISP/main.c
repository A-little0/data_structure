#include "main.h"
#include "myglist.h"

void test01()
{
	GList* myglist = GListInit();
	AddNode(myglist);
	DestroyGList(myglist);
}
void test02()
{
	char ch;
	scanf("%c", &ch);
	if (ch == 'y')
	{
		printf("you choice is yes\r\n");
	}
	else if (ch == 'n')
	{
		printf("you choice is not\r\n");
	}
	else
	{

	}
}

int main() {

	test01();
	//test02();

	system("pause");
	return 0;
}