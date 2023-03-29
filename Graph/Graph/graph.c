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
					for (int j = 0; j < vnum; j++)
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