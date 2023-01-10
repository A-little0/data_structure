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

Sstring* StringInit();//��ʼ�����ַ���
void StrAssign(Sstring* str,char* const_strpoint);//���ַ���������ʼ��str
void ShowString(Sstring* str);//��ӡ�ַ����ĳ���
Sstring* StrCopy(Sstring* str,Sstring* input_str);//��str����Ϊinput_str
bool StrEmpty(Sstring* str);//�ж��ַ����Ƿ�Ϊ�գ�Ϊ�շ���true,���򷵻�false
int StrCompare(Sstring* str1,Sstring* str2);//str1>str2����>0 str1==str2����=0 str1<str2����<0
unsigned int StrLength(Sstring* str);//�����ַ�������
void ClearString(Sstring* str);//����ַ�������length���㣩
Sstring* Concat(Sstring* output_str,Sstring* input_str1,Sstring* input_str2);//�����ַ���1���ַ���2
Sstring* SubString(Sstring* str,unsigned int pos,unsigned int len);//���شӵ�pos��Ԫ�ؿ�ʼ����Ϊlen���Ӵ�
int* IndexBF(Sstring* capital_str,Sstring* son_str);//����con_str�Ƿ�Ϊ�������Ӵ��������򷵻ص�һ��Ԫ�ص�λ��λ�ã����򷵻�0��(BF�㷨)
int* IndexKMP(Sstring* capital_str, Sstring* son_str);//����con_str�Ƿ�Ϊ�������Ӵ��������򷵻ص�һ��Ԫ�ص�λ��λ�ã����򷵻�0��(KMP�㷨)
void Replace(Sstring* capital_str,Sstring* compare_str,Sstring* replaced_str);//��capital_str���ҵ���compare_str��ͬ���Ӵ������滻Ϊreplaced_str
void StrInsert(Sstring* capital_str,unsigned int pos,Sstring* insert_str);//�ڵ�POS��Ԫ��ǰ����insert_str
void StrDelete(Sstring* capital_str, unsigned int pos, unsigned int len);//�ڵ�POS��Ԫ����ɾ������Ϊlen���Ӵ�
void DestroyString(Sstring* str);//�����ڴ�

#endif
