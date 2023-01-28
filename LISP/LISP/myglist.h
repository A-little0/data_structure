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
//	int tag;//���tar==1��ñ�ڵ����ӱ����tar==0��ñ�ΪǶ�ױ�
//	struct GlistNote* glistnoteptr;//ָ��GlistNote
//	struct AtomNote* atomptr;//ָ��ԭ��
// }GlistNote;
/*************************************************************************************************/


/*******************************this Glist define from book**************************************/
typedef enum { ATOM, LIST } ElemTag;  //ATOM==0ԭ��;LIST==1�ӱ�;
typedef struct GLNode
{
	ElemTag tag;//����������������ԭ�ӽ��ͱ���

	union//ԭ�ӽ��ͱ�������ϲ���
	{
		AtomType atom;//atom��ԭ�ӽ���ֵ��AtomType���û�����
		struct { struct GLNode* hp, * tp; }ptr;//ptr�Ǳ����ָ����ptr.hp��ptr.tp�ֱ�ָ���ͷ�ͱ�β
	};
}GList;
/************************************************************************************************/

GList* GListInit();
void AddNode(GList* targetglist);
GList* GetHead(GList* targetlist);
GList* GetTail(GList* targetlist);
void DestroyGList(GList* targetlist);//���Ҫ���ֶ��ͷ��Լ���
#endif
