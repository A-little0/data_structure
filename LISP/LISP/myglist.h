#ifndef __MYGLIST_H
#define __MYGLIST_H
#include "malloc.h"
#include "main.h"
#define AtomType int

/******************************this is my GList define ********************************************/
//typedef struct AtomNote {
//	int value;
//}AtomNote;
//typedef struct GlistNote {
//	int tag;//如果tar==1则该表节点是子表，如果tar==0则该表为嵌套表
//	struct GlistNote* glistnoteptr;//指向GlistNote
//	struct AtomNote* atomptr;//指向原子
// }GlistNote;
/*************************************************************************************************/


/*******************************this Glist define from book**************************************/
typedef enum { ATOM, LIST } ElemTag;  //ATOM==0原子;LIST==1子表;
typedef struct GLNode
{
	ElemTag tag;//公共部分用于区分原子结点和表结点

	union//原子结点和表结点的联合部分
	{
		AtomType atom;//atom是原子结点的值域，AtomType由用户定义
		struct { struct GLNode* hp, * tp; }ptr;//ptr是表结点的指针域，ptr.hp，ptr.tp分别指向表头和表尾
	};
}GList;
/************************************************************************************************/

GList* GListInit();
void AddNode(GList* targetglist);
GList* GetHead(GList* targetlist);
GList* GetTail(GList* targetlist);
void DestroyGList(GList* targetlist);//最后还要在手动释放自己；
#endif
