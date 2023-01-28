#include "myglist.h"



GList* GListInit()
{
	GList* newglist = (GList*)malloc(sizeof(GList));
	if (newglist != NULL)
	{
		newglist->tag = LIST;
		newglist->ptr.hp = NULL;
		newglist->ptr.tp = NULL;
	}
	else
	{
		printf("GListInit error��no enough space to init\r\n");
	}
}


void AddNode(GList* targetglist)
{
	if (targetglist->tag == 1)
	{	
		printf("do you want to add Node?\r\n y or n\r\n");
		char ch;
		scanf("%c", &ch);
		getchar();
		if (ch == 'y')
		{
			while (getchar() != '\n');//��ջ�����
			printf("add atom or list?\r\n");
			printf("this node is atom please push 0\r\nthis node is list please push 1\r\n");
			printf("\r\n");
			printf("begin to add listhead\r\n");

			char choice;
			scanf("%c", &choice);
			while (getchar() != '\n');//��ջ�����
			if (choice == '0')
			{
				GList* newglist = (GList*)malloc(sizeof(GList));
				if (newglist != NULL)
				{
					//�����½��
					newglist->tag = 0;
					int value = 0;
					printf("please push atom value\r\n");
					scanf("%d", &value);
					while (getchar() != '\n');//��ջ�����
					newglist->atom = value;
					//���ӽ��
					targetglist->ptr.hp = newglist;
					AddNode(newglist);
				}
			}
			else if (choice == '1')
			{
				GList* newglist = (GList*)malloc(sizeof(GList));
				if (newglist != NULL)
				{
					//�����½��
					newglist->tag = 1;
					newglist->ptr.hp = NULL;
					newglist->ptr.tp = NULL;

					//���ӽ��
					targetglist->ptr.hp = newglist;
					AddNode(newglist);
				}
			}
			printf("begin to add listtail\r\n");
			scanf("%c", &choice);
			while (getchar() != '\n');//��ջ�����
			if (choice == '0')
			{
				GList* newglist = (GList*)malloc(sizeof(GList));
				if (newglist != NULL)
				{
					//�����½��
					newglist->tag = 0;
					int value = 0;
					printf("please push atom value\r\n");
					scanf("%d", &value);
					while (getchar() != '\n');//��ջ�����
					newglist->atom = value;
					//���ӽ��
					targetglist->ptr.tp = newglist;
					AddNode(newglist);
				}
			}
			else if (choice == '1')
			{
				GList* newglist = (GList*)malloc(sizeof(GList));
				if (newglist != NULL)
				{
					//�����½��
					newglist->tag = 1;
					newglist->ptr.hp = NULL;
					newglist->ptr.tp = NULL;

					//���ӽ��
					targetglist->ptr.tp = newglist;
					AddNode(newglist);
				}
			}
		}
		else// if (ch == 'n')
		{
			//�˳�
		}
	}
}

GList* GetHead(GList* targetlist)
{
	GList* headglist = (GList*)malloc(sizeof(GList));
	if (headglist != NULL)
	{
		headglist = targetlist->ptr.hp;
		return headglist;
	}
	else
	{
		printf("gethead error:no enough space\r\n");
	}
}
GList* GetTail(GList* targetlist)
{
	GList* tailglist = (GList*)malloc(sizeof(GList));
	if (tailglist != NULL)
	{
		tailglist = targetlist->ptr.tp;
		return tailglist;
	}
	else
	{
		printf("gettail error:no enough spacer\r\n");
	}
}
void DestroyGList(GList* targetlist)
{
	if (targetlist->ptr.hp != NULL)
	{
		DestroyGList(targetlist->ptr.hp->ptr.hp);
		free(targetlist->ptr.hp);
		
	}
	if (targetlist->ptr.tp != NULL)
	{
		DestroyGList(targetlist->ptr.tp->ptr.tp);
		free(targetlist->ptr.tp);
	}
	free(targetlist);
}