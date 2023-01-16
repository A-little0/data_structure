#include "mylist.h"
#include "malloc.h"

//带头节点的单链表
list* list_Init()//初始化带头节点的单链表
{
	list* p_head = (list*)malloc(sizeof(list));
	if (p_head == NULL)
	{
		printf("开辟内存错误");
	}
	else
	{
		p_head->p_next = NULL;
		p_head->value = 0;
	}

	return p_head;
}

void push_back(int value,list *point_head)//尾插一个元素
{
	//创建要插入的变量
	list* L_next = (list*)malloc(sizeof(list));
	if (L_next == NULL)
	{
		printf("error:no enough space to push back");
	}
	else
	{
		list* temp = point_head;
		while (temp->p_next != NULL)//遍历出尾元素
		{
			temp = temp->p_next;
		}
		L_next->value = value;
		L_next->p_next = NULL;
		temp->p_next = L_next;//将上一个单链表的尾元素的指针指向要插入的元素；
		temp = NULL;
	}
}
void pop_back(list* point_head)
{
	list* p_last = point_head;
	int i = 0;
	for (; p_last->p_next != NULL; i++)
	{
		p_last = p_last->p_next;
	}
	free(p_last);
	p_last = NULL;
	list* p_Llast = point_head;
	for (int j = 0; j < i - 1; j++)
	{
		p_Llast = p_Llast->p_next;
	}
	p_Llast->p_next = NULL;
}
void insert(int value, unsigned int subscipt, list* point_head)
{

	unsigned int num = 0;
	list* p_temp = point_head;
	for (; p_temp->p_next != NULL; num++)
	{
		p_temp = p_temp->p_next;
	}
	if (subscipt > 0 && subscipt <= num)//判断subscipt是否在区间范围之内（除取头节点）
	{
		list* L_next = (list*)malloc(sizeof(list));	// 创建目标元素
		if (L_next != NULL)
		{
			//给开辟好的地址赋值
			L_next->value = value;
			// 将目标元素的指针指向下标为subscipt的元素
			p_temp = point_head;
			for (int i = 0; i < subscipt; i++)
			{
				p_temp = p_temp->p_next;
			}
			L_next->p_next = p_temp;
			//找到下标为subscipt-1的指针并指向目标元素的地址
			p_temp = point_head;
			for (int j = 0; j < subscipt - 1; j++)
			{
				p_temp = p_temp->p_next;
			}
			p_temp->p_next = L_next;
		}
		else
		{
			printf("insert error:no enough speace to insert");
		}
	}
	else
	{
		printf("error:下标访问越界");
	}
	p_temp = NULL;


}
void delete(unsigned int subscipt, list* point_head)
{
	int num = 0;
	list* p_target = point_head;
	for (; p_target->p_next != NULL; num++)
	{
		p_target = p_target->p_next;
	}
	p_target = point_head;
	if (subscipt > 0 && subscipt <= num)
	{

		for (int i = 0; i < subscipt; i++)
		{
			p_target = p_target->p_next;
		}
		//创建一个list类型的指针
		list* p_temp = point_head;
		for (int j = 0; j < subscipt-1; j++)
		{
			p_temp = p_temp->p_next;
		}
		//将下标为subscipt-1的元素的指针指向下标为subscipt+1的元素
		p_temp->p_next = p_temp->p_next->p_next;
		//将下标为subscipt的元素free
		free(p_target);
	}
	else
	{
		printf("delete error:下标访问越界");
	}
	p_target = NULL;
}
void repleace(unsigned int subscupt, int r_value, list* point_head)//替换某一个元素
{
	int num=0;
	list* p_target = point_head;
	for (; p_target->p_next != NULL; num++)
	{
		p_target = p_target->p_next;
	}
	if (subscupt > 0 && subscupt <= num)
	{
		p_target = point_head;
		for (int i = 0; i < subscupt; i++)
		{
			p_target = p_target->p_next;
		}
		p_target->value =r_value;
	}
	else
	{
		printf("repleace error:下标访问越界");
	}
	p_target = NULL;
}
void repleace_t(int source_value, int target_value, list* point_head)//将source_value替换为target_value
{
	list* p_target = point_head;
	unsigned int subscipt = 0;
	unsigned int num = 0;
	for (; p_target->p_next != NULL; num++)
	{
		p_target = p_target->p_next;
	}
	p_target = point_head;
	for (int i = 0; i < num ; i++)
	{
		p_target = p_target->p_next;
		if (p_target->value == source_value)
		{
			subscipt = i;
			//printf("subscipt: %d\n\r", subscipt);
			p_target->value = target_value;
		}
	}
	if (subscipt == 0)
	{
		printf("this value are not find");
	}
	p_target = NULL;
}
void find(int value,list* point_head)//查找某个值
{
	list* p_target = point_head;
	unsigned int subscipt = 0;
	unsigned int num = 0;
	for (; p_target->p_next != NULL; num++)
	{
		p_target = p_target->p_next;
	}
	p_target = point_head;
	for (int i = 0; i < num+1; i++)
	{
		if (p_target->value == value)
		{
			subscipt = i;
			printf("subscipt: %d\n\r", subscipt);
		}
		p_target = p_target->p_next;
	}
	if (subscipt == 0)
	{
		printf("this value are not find");
	}
}
void show_value(unsigned int subscipt,list* point_head)//打印第n个元素
{
	list* p_target = point_head;
	unsigned int num = 0;
	for (; p_target->p_next != NULL; num++)
	{
		p_target = p_target->p_next;
	}
	if (subscipt >= 0 && subscipt <= num)
	{
		p_target = point_head;
		for (int j = 0; j < subscipt; j++)
		{
			p_target = p_target->p_next;
		}
		printf("%d", p_target->value);
	}
	else
	{
		printf("show value error:下标访问越界");
	}
}
void show_somevalue(unsigned int a, unsigned int b,list* point_head)//打印[a,b]区间的元素
{
	list* p_target = point_head;
	unsigned int num = 0;
	for (; p_target->p_next != NULL; num++)
	{
		p_target = p_target->p_next;
	}
	if (b >= 0 && b<= num)
	{
		if (a >= 0 && a <= b)
		{
			p_target = point_head;
			for (int j = 0; j < b; j++)
			{
				p_target = p_target->p_next;
				if (j>= a-1)
				{
					printf("%d\n\r", p_target->value);
				}
			}
		}
		else
		{
			printf("error:下标访问越界");
		}
	}
	else
	{
		printf("error:下标访问越界");
	}
}
void sort_value(list* point_head)//从小到大排序（改变原链表）
{
	list* begain = point_head;
	list* end = point_head;
	int num = 0;
	for (; end->p_next != NULL; num++)
	{
		end = end->p_next;
	}
	end = point_head;
	if (end->p_next != NULL )
	{
		end = end->p_next;
		if (end->p_next != NULL)
		{
			end = end->p_next;
			begain = begain->p_next;
			for (int i = 0; i < num - 1; i++)
			{
				for (int j = 0; j < num - 1; j++)
				{
					if (begain->value > end->value)
					{
						int temp = end->value;
						end->value = begain->value;
						begain->value = temp;
						if (end->p_next != NULL)
						{
							end = end->p_next;
							begain = begain->p_next;
						}
					}
				}
				end = point_head->p_next->p_next;
				begain = point_head->p_next;
			}
		}
		else {/*list 只含有一个元素*/ };
	}
	else
	{
		printf("sort error:this list is empty");
	}
	begain = NULL;
	end = NULL;
}
void sortReverse_value(list* point_head)//从大到小排序（改变原链表）
{
	list* begain = point_head;
	list* end = point_head;
	int num = 0;
	for (; end->p_next != NULL; num++)
	{
		end = end->p_next;
	}
	end = point_head;
	if (end->p_next != NULL)
	{
		end = end->p_next;
		if (end->p_next != NULL)
		{
			end = end->p_next;
			begain = begain->p_next;
			for (int i = 0; i < num - 1; i++)
			{
				for (int j = 0; j < num - 1; j++)
				{
					if (begain->value < end->value)
					{
						int temp = end->value;
						end->value = begain->value;
						begain->value = temp;
						if (end->p_next != NULL)
						{
							end = end->p_next;
							begain = begain->p_next;
						}
					}
				}
				end = point_head->p_next->p_next;
				begain = point_head->p_next;
			}
		}
		else {/*list 只含有一个元素*/ };
	}
	else
	{
		printf("sort error:this list is empty");
	}
	begain = NULL;
	end = NULL;
}
void sort_valueC(const list* point_head)//从小到大排序（不改变原表）
{
	int num = 0;
	const list* temp = point_head;
	for (; temp->p_next != NULL; num++)
	{
		temp = temp->p_next;
	}
	
	if (num > 1)//有两个或者两个以上的元素
	{	
		//得出元素个数（不包括头节点）
		temp = point_head->p_next;
		int* arr = (int*)calloc(num,sizeof(int));//开辟内存存储list的值
		int* arr_begin = arr;
		for (int i = 0; i < num; i++)
		{
			*arr_begin = temp->value;
			if(i<num-1)
			{
				arr_begin++;
			}
			if (temp->p_next != NULL)
			{
				temp = temp->p_next;
			}
		}
		//排序
		arr_begin = arr;
		int* arr_end = arr;
		for (int i = 0; i < num - 1; i++)
		{
			for (int j = 0; j < num-i - 1; j++)
			{
				arr_end++;
				if (*arr_begin > *arr_end)
				{
					int tempnum = *arr_end;
					*arr_end = *arr_begin;
					*arr_begin = tempnum;
				}
				if(j<num-i-1)
				{
					arr_begin++;
				}

			}
			arr_begin = arr;
			arr_end = arr;
		}
		//输出排序结果
		arr_begin = arr;
		arr_end = NULL;
		for (int i = 0; i < num; i++)
		{
			int a = *arr_begin;
			printf("%d\r\n",a);
			if(i<temp-1)
			{
				arr_begin++;
			}
		}
		//释放内存
		free(arr);
		arr_begin = NULL;
		arr = NULL;
		temp = NULL;
	}
	else if(num==1) {/*只含有一个元素*/ }
	else { printf("this is a empty list"); }
}
void sortReverse_valueC(const list* point_head)//从大到小排序（不改变原表）
{
	int num = 0;
	const list* temp = point_head;
	for (; temp->p_next != NULL; num++)
	{
		temp = temp->p_next;
	}

	if (num > 1)//有两个或者两个以上的元素
	{
		//得出元素个数（不包括头节点）
		temp = point_head->p_next;
		int* arr = (int*)calloc(num, sizeof(int));//开辟内存存储list的值
		int* arr_begin = arr;
		for (int i = 0; i < num; i++)
		{
			*arr_begin = temp->value;
			if (i < num - 1)
			{
				arr_begin++;
			}
			if (temp->p_next != NULL)
			{
				temp = temp->p_next;
			}
		}
		//排序
		arr_begin = arr;
		int* arr_end = arr;
		for (int i = 0; i < num - 1; i++)
		{
			for (int j = 0; j < num - i - 1; j++)
			{
				arr_end++;
				if (*arr_begin < *arr_end)
				{
					int tempnum = *arr_end;
					*arr_end = *arr_begin;
					*arr_begin = tempnum;
				}
				if (j < num - i - 1)
				{
					arr_begin++;
				}

			}
			arr_begin = arr;
			arr_end = arr;
		}
		//输出排序结果
		arr_begin = arr;
		arr_end = NULL;
		for (int i = 0; i < num; i++)
		{
			int a = *arr_begin;
			printf("%d\r\n", a);
			if (i < temp - 1)
			{
				arr_begin++;
			}
		}
		//释放内存
		free(arr);
		arr_begin = NULL;
		arr = NULL;
		temp = NULL;
	}
	else if (num == 1) {/*只含有一个元素*/ }
	else { printf("this is a empty list"); }
}
void destroy(list* point_head)//释放空间
{
	free(point_head);
}

//带头结点的循环链表
clist* clist_Init()
{
	clist* clist_point = (clist*)malloc(sizeof(clist));
	if (clist_point != NULL)
	{
		clist_point->value = 0;
		clist_point->p_next = clist_point;
		return clist_point;
	}
	else
	{
		printf("clist Init error:no enough space to init\r\n");
	}
}
int emptyClist(clist* point_head)
{
	if (point_head->p_next == point_head)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
void push_back_c(int value, clist* point_head)
{
	clist* sour_clistptr = point_head;

	clist* clistptr = (clist*)malloc(sizeof(clist));
		if (clistptr != NULL)
		{
			clistptr->value = value;
			
			if (emptyClist(sour_clistptr))
			{
				sour_clistptr->p_next = clistptr;
				clistptr->p_next = point_head;
			}
			else
			{
				while (sour_clistptr->p_next != point_head)
				{
					sour_clistptr = sour_clistptr->p_next;
				}
				sour_clistptr->p_next = clistptr;
				clistptr->p_next = point_head;
			}
		}
		else
		{
			printf("push back error:no enough space to push back\r\n");
		}
}
void pop_back_c(clist* point_head)
{
	clist* clistptr = point_head;
	
	if (emptyClist(clistptr))
	{
		printf("this clist is empty\r\n");
	}
	else
	{
		int times = 0;
		while (clistptr->p_next != point_head)
		{
			clistptr = clistptr->p_next;
			times++;
		}
		clist* tempptr = point_head;
		for (int i = 0; i < times-1; i++)
		{
			tempptr = tempptr->p_next;
		}
		tempptr->p_next = point_head;
		free(clistptr);
	}
}
void destroyC(clist* point_head)
{
	if (emptyClist)
	{
		free(point_head);
	}
	else
	{
		clist* beginptr = point_head;
		clist* endptr = beginptr->p_next;
		while (endptr!= point_head)
		{
			free(beginptr);
			beginptr = endptr;
			endptr = endptr->p_next;
		}
		free(endptr);
	}
}

//带头节点的双向循环列表
dlist* dlist_Init()
{
	dlist* dlistptr = (dlist*)malloc(sizeof(dlist));
	if (dlistptr != NULL)
	{
		dlistptr->value = 0;
		dlistptr->p_last = dlistptr;
		dlistptr->p_next = dlistptr;

	}
	else
	{
		printf("dlist init error:no enough space to init\r\n");
	}
}
int emptyDlist(dlist* point_head)
{
	if (point_head->p_next ==point_head&&point_head->p_last==point_head)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
void push_back_d(int value, dlist* point_head)
{
	dlist* dlistptr = (dlist*)malloc(sizeof(dlist));
	if (dlistptr != NULL)
	{
		dlist* sour_dlistptr = point_head;
		dlistptr->value = value;

		if (emptyDlist(point_head))
		{
			sour_dlistptr->p_next = dlistptr;
			dlistptr->p_next = point_head;
			dlistptr->p_last = point_head;
			point_head->p_last = dlistptr;
		}
		else
		{
			while (sour_dlistptr->p_next != point_head)
			{
				sour_dlistptr = sour_dlistptr->p_next;
			}
			sour_dlistptr->p_next = dlistptr;
			dlistptr->p_last = sour_dlistptr;
			dlistptr->p_next = point_head;
			point_head->p_last = dlistptr;
		}
	}
	else
	{
		printf("push back error: no enough space to push back to dlist\r\n");
	}

}
void pop_back_d(dlist* point_head)
{
	if (emptyDlist(point_head))
	{
		printf("pop back error: this dlist is empty\r\n");
	}
	else
	{
		dlist* endptr= point_head->p_last;
		dlist* endptr_last = endptr->p_last;
		endptr_last->p_next = point_head;
		point_head->p_last = endptr_last;
		free(endptr);
	}
}
void destroyD(dlist* point_head)
{
	if (emptyDlist)
	{
		free(point_head);
	}
	else
	{
		dlist* endptr = point_head->p_last;
		dlist* endptr_last = endptr->p_last;
		while (endptr_last != point_head)
		{
			free(endptr);
			endptr = endptr_last;
			endptr_last = endptr_last->p_last;
		}
		free(endptr);
		free(point_head);
	}
}
