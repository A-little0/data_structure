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
	StrCompare(str, str2);
	StrLength(str);
	ClearString(str);
	ShowString(str);
}
void test02()
{
	Sstring* str = StringInit();
	StrAssign(str, "hello ");
	ShowString(str);
	Sstring* str1 = StringInit();
	StrAssign(str1, "world");
	ShowString(str1);
	Sstring* str2 = StringInit();
	str2 = Concat(str2, str, str1);
	ShowString(str2);
	Sstring* str3=SubString(str2, 7, 5);
    ShowString(str3);
}

void test03()
{
	Sstring* str = StringInit();
	StrAssign(str, "i like c++ so much!");

	Sstring* sonstr = SubString(str, 8, 3);
	//ShowString(sonstr);
	int sub=IndexBF(str, sonstr);
	printf("%d\r\n", sub);
}
void test04()
{
	Sstring* str = StringInit();
	StrAssign(str, "i like c++ so much!");
	Sstring* str1 = StringInit();
	StrAssign(str1, "you and ");
	StrInsert(str, 8, str1);
	ShowString(str);
	StrDelete(str, 3, 4);
	ShowString(str);
}


int main() {

	//test01();
	//test02();
	//test03();
	test04();

	system("pause");
	return 0;
}