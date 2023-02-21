#ifndef __STACK_H
#define __STACK_H
#include <stdio.h>
#include <malloc.h>
#define BiTreeQueueSIZE 15
#define BinaryTreeTypeName int

typedef struct BinaryTree {

	BinaryTreeTypeName data;
	struct
	{
		struct BinaryTree* parent;
		struct BinaryTree* leftchild;
		struct BinaryTree* rightchild;
	}ptr;

}BinaryTree;


typedef struct BiTreeQueue{
	BinaryTree* queuearr[BiTreeQueueSIZE];
	struct 
	{
		int first;
		int last;
	}ptr;
}BiTreeQueue;

BiTreeQueue* BiTreeQueueInit();
void Push(BinaryTree* bitree, BiTreeQueue* biqueue);
BinaryTree* Pop(BiTreeQueue* bitreequeue);
int BiTreeQueueEmpty(BiTreeQueue* bitreequeue);


void libtest();
#endif
