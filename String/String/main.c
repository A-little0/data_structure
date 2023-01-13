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

void test08()
{
	Sstring* str = StringInit();
	StrAssign(str, "abcdabcdabcdcjnabcdcjn");
	//printf("%d\r\n", StrLength(str));
	Sstring* comparestr = StringInit();
	StrAssign(comparestr, "cjn");

	int* p=IndexKMP(str, comparestr);
	p++;
	printf("%d", *p);
}

int nexttest(Sstring* son_str,int poserror)
{
	int strlen = son_str->len;//获取子串的长度
	char* next = son_str->str;//获取子串
	
	int next_posbagin = 1;//子串头指针
	int next_posend = strlen;//子串尾指针

	int nextarr[MINLENGTH] = {0};//初始化next
	nextarr[0] = -1;//next数组的第一个元素必为-1

	int comparelen = poserror - 1;
	for (int i = 1; i < comparelen; i++)//
	{
		for (int j = 0; j < i; j++)
		{
			if (next[j] == next[comparelen - i+j])
			{
				nextarr[poserror-1] = i;
			}
			else if(next[j] != next[comparelen - i + j]&&nextarr[poserror-1]==0)
			{
				nextarr[poserror-1] = 0;
			}
		}
	}
	return nextarr[poserror-1];
}


int main() {

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//Sstring* str = StringInit();
	//StrAssign(str, "ABCDABD");
	//int num=nexttest(str, 7);
	//printf("%d", num);
	test08();

	system("pause");
	return 0;
}