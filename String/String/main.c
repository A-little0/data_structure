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

void test05()
{
	printf("ok");
	Sstring* str = StringInit();
	StrAssign(str, "abcdefghjnizklmnjnizk");

	Sstring* sonstr = StringInit();
	StrAssign(sonstr, "jnizk");

	int* point = IndexBF(str, sonstr);
	int num = sizeof("abcdefghjnizklmnjnizk") / sizeof('a');
	for (int i = 0; i < num; i++)
	{
		printf("%d\r\n", *point);
		point++;
	}
}

void test06()
{
	Sstring* str = StringInit();
	StrAssign(str, "aaaaabbbbbbccccccbbbbbbc");
	//printf("%d\r\n", StrLength(str));
	Sstring* comparestr = StringInit();
	StrAssign(comparestr, "bbbbbb");

	Sstring* replacestr = StringInit();
	StrAssign(replacestr, "successful");
	int* point = IndexBF(str, comparestr);
	int num = sizeof("aaaaabbbbbbcccccc") / sizeof('a');
	for (int i = 0; i < num; i++)
	{
		printf("%d\r\n", *point);
		point++;
	}
	Replace(str, comparestr, replacestr);
	ShowString(str);
}


int main() {

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();

	system("pause");
	return 0;
}