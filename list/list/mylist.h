#ifndef _MYLIST_H
#define _MYLIST_H

#include "main.h"

//��������
typedef struct list {
	int value;//����ֵ
	struct list* p_next;//������һ��Ԫ�أ��ڵ㣩�ĵ�ַ
}list;

list* list_Init();//��ʼ����ͷ�ڵ�ĵ�����
void push_back(int value, list* point_head);//β��һ��Ԫ��
void pop_back(list* point_head);//βɾһ��Ԫ��
void insert(int value,unsigned int subscupt, list* point_head);//����Ԫ�ص������м�
void delete(unsigned int subscupt, list* point_head);//ɾ��������ĳһ����
void repleace(unsigned int subscupt, int r_value, list* point_head);//�滻ĳһ��Ԫ��
void repleace_t(int source_value, int target_value, list* point_head);//��source_value�滻Ϊtarget_value
void find(int value,list* point_head);//����ĳ��ֵ
void show_value(unsigned int subscipt,list* point_head);//��ӡĳ��Ԫ��
void show_somevalue(unsigned int a, unsigned int b,list* point_head);//��ӡ[a,b]�����Ԫ��
void sort_value(list* point_head);//��С�������򣨸ı�ԭ����
void sortReverse_value(list* point_head);//�Ӵ�С���򣨸ı�ԭ����
void sort_valueC(const list* point_head);//��С�������򣨲��ı�ԭ��
void sortReverse_valueC(const list* point_head);//�Ӵ�С���򣨲��ı�ԭ��
#endif
