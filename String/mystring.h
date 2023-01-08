#ifndef __MYSTRING_H
#define __MYSTRING_H

#include "main.h"
#define MINLENGTH 250

typedef struct MyString {

	char str[MINLENGTH+1];
	unsigned int len;

}Sstring;

Sstring* StringInit();//初始化空字符串
void StrAssign(Sstring* str,char* const_strpoint);//用字符串常量初始化str
void ShowString(Sstring* str);//打印字符串的长度
Sstring* StrCopy(Sstring* str,Sstring* input_str);//将str复制为input_str
//StrEmpty();
//StrCompare();
//StrLength();
//ClearString();
//Concat();
//SubString();
//Index();
//Replace();
//StrInsert();
//StrDelete();
//DestroyString();

#endif
