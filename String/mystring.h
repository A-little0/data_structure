#ifndef __MYSTRING_H
#define __MYSTRING_H

#include "main.h"
#define MINLENGTH 250

typedef struct MyString {

	char str[MINLENGTH+1];
	unsigned int len;

}Sstring;

Sstring* StringInit();//��ʼ�����ַ���
void StrAssign(Sstring* str,char* const_strpoint);//���ַ���������ʼ��str
void ShowString(Sstring* str);//��ӡ�ַ����ĳ���
Sstring* StrCopy(Sstring* str,Sstring* input_str);//��str����Ϊinput_str
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
