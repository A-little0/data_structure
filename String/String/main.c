#include "main.h"
#include "mystring.h"

void test01()
{
	Sstring* str = StringInit();
	StrAssign(str, "hello world");
	ShowString(str);
	
	Sstring* str2 = StringInit();
	StrCopy(str2, str);
	ShowString(str2);
}


int main() {

	test01();



	system("pause");
	return 0;
}