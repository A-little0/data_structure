#ifndef _MYLIST_H
#define _MYLIST_H

#include "main.h"

//单向链表
typedef struct list {
	int value;//储存值
	struct list* p_next;//储存下一个元素（节点）的地址
}list;

list* list_Init();//初始化带头节点的单链表
void push_back(int value, list* point_head);//尾插一个元素
void pop_back(list* point_head);//尾删一个元素
void insert(int value,unsigned int subscupt, list* point_head);//插入元素到链表中间
void delete(unsigned int subscupt, list* point_head);//删除链表中某一个数
void repleace(unsigned int subscupt, int r_value, list* point_head);//替换某一个元素
void repleace_t(int source_value, int target_value, list* point_head);//将source_value替换为target_value
void find(int value,list* point_head);//查找某个值
void show_value(unsigned int subscipt,list* point_head);//打印某个元素
void show_somevalue(unsigned int a, unsigned int b,list* point_head);//打印[a,b]区间的元素
void sort_value(list* point_head);//从小到大排序（改变原链表）
void sortReverse_value(list* point_head);//从大到小排序（改变原链表）
void sort_valueC(const list* point_head);//从小到大排序（不改变原表）
void sortReverse_valueC(const list* point_head);//从大到小排序（不改变原表）
#endif
