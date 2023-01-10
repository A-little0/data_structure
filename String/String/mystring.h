#ifndef __MYSTRING_H
#define __MYSTRING_H

#include "main.h"
#define MINLENGTH 250
#define true 1
#define false 0

typedef struct MyString {

	char str[MINLENGTH+1];
	unsigned int len;

}Sstring;

typedef int bool;

Sstring* StringInit();//初始化空字符串
void StrAssign(Sstring* str,char* const_strpoint);//用字符串常量初始化str
void ShowString(Sstring* str);//打印字符串的长度
Sstring* StrCopy(Sstring* str,Sstring* input_str);//将str复制为input_str
bool StrEmpty(Sstring* str);//判断字符串是否为空，为空返回true,否则返回false
int StrCompare(Sstring* str1,Sstring* str2);//str1>str2返回>0 str1==str2返回=0 str1<str2返回<0
unsigned int StrLength(Sstring* str);//返回字符串长度
void ClearString(Sstring* str);//清空字符串（将length置零）
Sstring* Concat(Sstring* output_str,Sstring* input_str1,Sstring* input_str2);//返回字符串1加字符串2
Sstring* SubString(Sstring* str,unsigned int pos,unsigned int len);//返回从第pos个元素开始长度为len的子串
int* IndexBF(Sstring* capital_str,Sstring* son_str);//查找con_str是否为主串的子串，若有则返回第一个元素的位置位置，否则返回0；(BF算法)
int* IndexKMP(Sstring* capital_str, Sstring* son_str);//查找con_str是否为主串的子串，若有则返回第一个元素的位置位置，否则返回0；(KMP算法)
void Replace(Sstring* capital_str,Sstring* compare_str,Sstring* replaced_str);//在capital_str中找到与compare_str相同的子串，并替换为replaced_str
void StrInsert(Sstring* capital_str,unsigned int pos,Sstring* insert_str);//在第POS个元素前插入insert_str
void StrDelete(Sstring* capital_str, unsigned int pos, unsigned int len);//在第POS个元素起，删除长度为len的子串
void DestroyString(Sstring* str);//回收内存

#endif
