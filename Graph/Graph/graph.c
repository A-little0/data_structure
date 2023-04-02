#include "graph.h"
#include "malloc.h"

/*********************************************************/
AM_to_Graph* creatAdjacencyMatrix_toGraph(int vnum)//构造关系矩阵
{
	if (vnum > 0)
	{
		AM_to_Graph* newAM = (AM_to_Graph*)malloc(sizeof(AM_to_Graph));
		if (newAM != NULL)
		{
			newAM->vexnum = vnum;
			newAM->linkarr = (int*)malloc(sizeof(int) *vnum* vnum);
			if (newAM->linkarr != NULL)
			{
				for (int i = 0; i < vnum; i++)
				{
					for (int j = i; j < vnum; j++)
					{
						if (i == j) { newAM->linkarr[i][j] = 0;}
						else
						{
							int temp = 0;
							printf("the %d to %d have arc?\r\n",i,j);
							printf("have is 1--haven't is 0 \r\n");
							scanf("%d", &temp);
							while (temp != 1 && temp != 0)
							{
								printf("please put to right num\r\n");
								scanf("%d", &temp);
							}

							newAM->linkarr[i][j] = temp;
							newAM->linkarr[j][i] = temp;
						}
					}
				}
				return newAM;
			}
			else
			{
				printf("func with creatAdjacencyMatrix_toGraph error: no enough space to creat linkarr\r\n");
			}

		}
		else
		{
			printf("func with creatAdjacencyMatrix_toGraph error:no enough space to creat all\r\n");
		}
	}
	else
	{
		printf("func with creatAdjacencyMatrix_toGraph error:please creat the vnum > 0\r\n");
	}
}

UnGraph* creatUnGraph(int vnum)
{
	UnGraph* newungraph = (UnGraph*)malloc(sizeof(UnGraph));
	if (newungraph != NULL)
	{
		newungraph->am= creatAdjacencyMatrix_toGraph(vnum);
		for (int i = 0; i < vnum; i++)
		{
			Undeirected_Graph_Type temp=0;
			printf("please to put the %d data:",i);
			scanf("%d", &temp);
			newungraph->data[i] = temp;
		}
		return newungraph;
	}
	else
	{
		printf("func with creatUnGraph error:no enough space to creat\r\n");
		return NULL;
	}
}
int locateVex(const UnGraph* target_ungraph, int uvex)//返回结点uvex在无向图的位置(返回下标信息)
{
	if (target_ungraph != NULL)
	{
		for (int i = 0; i < target_ungraph->am->vexnum; i++)
		{
			if (target_ungraph->data[i] == uvex)
			{
				return i;
			}
		}
		return -1;
	}
	else
	{
		printf("func with locateVex error:the target_ungraph is empty\r\n");
		return -1;
	}
}
Undeirected_Graph_Type getVex(const UnGraph* target_ungraph,int pos)//返回下标为pos的信息
{
	if (target_ungraph != NULL && pos > 0 && pos < target_ungraph->am->vexnum )
	{
		return target_ungraph->data[pos];
	}
	else
	{
		printf("func with GetVex error；target_ungraph is empty or the pos is error\r\n");
	}
}
void putVex(UnGraph* target_ungraph, int pos, Undeirected_Graph_Type value)//为下表为pos的结点赋值value
{
	if (target_ungraph != NULL && pos > 0 && pos < target_ungraph->am->vexnum)
	{
		target_ungraph->data[pos] = value;
	}
	else
	{
		printf("func with putVex error:target_ungraph is empty or the pos is error\r\n");
	}
}
int firstAdjVex(const UnGraph* target_ungraph, int pos)//返回下标为pos的第一个邻接点的下标
{
	if (target_ungraph != NULL && pos >= 0 && pos < target_ungraph->am->vexnum)
	{
		for (int i = 0; i < target_ungraph->am->vexnum; i++)
		{
			if (target_ungraph->am->linkarr[pos][i] == 1)
			{
				return i;
			}
		}
		return -1;
	}
	else
	{
		printf("func with firstAdjVex error:target_ungraph is empty or pos is error\r\n");
	}
}
int nextAdjVex(const UnGraph* target_ungraph, int pos)//返回pos的nexpos
{
	if (target_ungraph != NULL && pos>=0 && pos < target_ungraph->am->vexnum)
	{
		int nexpos = 0;
		int flag = 0;
		for (int i = 0; i < target_ungraph->am->vexnum; i++)
		{
			if (target_ungraph->am->linkarr[pos][i] == 1 && flag <= 2)
			{
				nexpos = i;
			}
		}
		if (flag == 2)
		{
			return nexpos;
		}
		else if(flag==1)
		{
			printf("only one arc\r\n");
			return nexpos;
		}
		else
		{
			printf("no arc\r\n");
			return -1;
		}
	}
	else
	{
		printf("func with nextAdjVex error:this target_ungraph is empty or the pos value is error\r\n");
	}
}
void insertVex(UnGraph* target_ungraph, Undeirected_Graph_Type value)//插入值为value的结点
{
	int vnum = target_ungraph->am->vexnum+1;

	AM_to_Graph* newAM = (AM_to_Graph*)malloc(sizeof(AM_to_Graph));
	if (newAM != NULL)
	{
		//扩展关系矩阵
		newAM->vexnum = vnum;
		newAM->linkarr = (int*)malloc(sizeof(int) * vnum * vnum);
		if (newAM->linkarr != NULL)
		{
			for (int i = 0; i < vnum; i++)
			{
				if (i == vnum - 1)
				{
					newAM->linkarr[i][vnum - 1] = 0;
				}
				else
				{
					int temp = 0;
					printf("the %d to %d have arc?\r\n", i, vnum - 1);
					printf("have is 1--haven't is 0 \r\n");
					scanf("%d", &temp);
					while (temp != 1 && temp != 0)
					{
						printf("please put to right num\r\n");
						scanf("%d", &temp);
					}
					newAM->linkarr[i][vnum - 1] = temp;
				}
			}
			for (int i = 0; i < vnum-1; i++)
			{
				for (int j = i; j < vnum-1; j++)
				{
					if (i == j) { newAM->linkarr[i][j] = 0; }
					else
					{
						int temp = target_ungraph->am->linkarr[i][j];
						newAM->linkarr[i][j] = temp;
						newAM->linkarr[j][i] = temp;
					}
				}
			}
		}
		else
		{
			printf("func with insert error:no enough space to new linkarr\r\n");
		}
		//扩展结点
		target_ungraph->data[vnum - 1] = value;
		free(target_ungraph->am);
		target_ungraph->am = newAM;
	}
	else
	{
		printf("func with insert error:no enough spaace to new am\r\n");
	}

}
//void deleteVex(UnGraph* target_ungraph, int pos)//删除下标为pos的结点
//{
//	if (target_ungraph != NULL&&pos>=0 && pos < target_ungraph)
//	{
//		if(pos==target_ungraph->am->vexnum-1)
//		{
//			target_ungraph->am->vexnum--;
//		}
//		else
//		{
//			int begin = pos;
//			int end = begin + 1;
//			while (end < target_ungraph->am->vexnum)
//			{
//				for(int i=0;i<target_ungraph->am->vexnum)
//			}
//		}
//	}
//}
void insertArc(UnGraph* target_ungraph, int pos1, int pos2)//在下标为pos1和pos2之间建立弧
{
	if (target_ungraph != NULL && pos1 >= 0 && pos1 < target_ungraph->am->vexnum && pos2 >= 0 && pos2 < target_ungraph->am->vexnum)
	{
		if (target_ungraph->am->linkarr[pos1][pos2] == 1)
		{
			printf("the pos1 to pos2 haved arc\r\n");
		}
		else
		{
			target_ungraph->am->linkarr[pos1][pos2] = 1;
		}
	}
	else
	{
		printf("func with nsertArc error:this target_ungraph is empty or pos1,pos2 is error value\r\n");
	}
}
void deleteArc(UnGraph* target_ungraph, int pos1, int pos2)//删除下标为pos1和pos2之间的弧
{
	if (target_ungraph != NULL && pos1 >= 0 && pos1 < target_ungraph->am->vexnum && pos2 >= 0 && pos2 < target_ungraph->am->vexnum)
	{
		if (target_ungraph->am->linkarr[pos1][pos2] == 1)
		{
			printf("the pos1 to pos2 haven't arc\r\n");
		}
		else
		{
			target_ungraph->am->linkarr[pos1][pos2] = 0;
		}
	}
	else
	{
		printf("func with nsertArc error:this target_ungraph is empty or pos1,pos2 is error value\r\n");
	}
}