#include "mylist.h"
#include "malloc.h"

list* list_Init()//��ʼ����ͷ�ڵ�ĵ�����
{
	list* p_head = (list*)malloc(sizeof(list));
	if (p_head == NULL)
	{
		printf("�����ڴ����");
	}
	else
	{
		p_head->p_next = NULL;
		p_head->value = 0;
	}

	return p_head;
}

void push_back(int value,list *point_head)//β��һ��Ԫ��
{
	//����Ҫ����ı���
	list* L_next = (list*)malloc(sizeof(list));
	if (L_next == NULL)
	{
		printf("error:no enough space to push back");
	}
	else
	{
		list* temp = point_head;
		while (temp->p_next != NULL)//������βԪ��
		{
			temp = temp->p_next;
		}
		L_next->value = value;
		L_next->p_next = NULL;
		temp->p_next = L_next;//����һ���������βԪ�ص�ָ��ָ��Ҫ�����Ԫ�أ�
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
	if (subscipt > 0 && subscipt <= num)//�ж�subscipt�Ƿ������䷶Χ֮�ڣ���ȡͷ�ڵ㣩
	{
		list* L_next = (list*)malloc(sizeof(list));	// ����Ŀ��Ԫ��
		if (L_next != NULL)
		{
			//�����ٺõĵ�ַ��ֵ
			L_next->value = value;
			// ��Ŀ��Ԫ�ص�ָ��ָ���±�Ϊsubscipt��Ԫ��
			p_temp = point_head;
			for (int i = 0; i < subscipt; i++)
			{
				p_temp = p_temp->p_next;
			}
			L_next->p_next = p_temp;
			//�ҵ��±�Ϊsubscipt-1��ָ�벢ָ��Ŀ��Ԫ�صĵ�ַ
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
		printf("error:�±����Խ��");
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
		//����һ��list���͵�ָ��
		list* p_temp = point_head;
		for (int j = 0; j < subscipt-1; j++)
		{
			p_temp = p_temp->p_next;
		}
		//���±�Ϊsubscipt-1��Ԫ�ص�ָ��ָ���±�Ϊsubscipt+1��Ԫ��
		p_temp->p_next = p_temp->p_next->p_next;
		//���±�Ϊsubscipt��Ԫ��free
		free(p_target);
	}
	else
	{
		printf("delete error:�±����Խ��");
	}
	p_target = NULL;
}
void repleace(unsigned int subscupt, int r_value, list* point_head)//�滻ĳһ��Ԫ��
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
		printf("repleace error:�±����Խ��");
	}
	p_target = NULL;
}
void repleace_t(int source_value, int target_value, list* point_head)//��source_value�滻Ϊtarget_value
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
void find(int value,list* point_head)//����ĳ��ֵ
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
void show_value(unsigned int subscipt,list* point_head)//��ӡ��n��Ԫ��
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
		printf("show value error:�±����Խ��");
	}
}
void show_somevalue(unsigned int a, unsigned int b,list* point_head)//��ӡ[a,b]�����Ԫ��
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
			printf("error:�±����Խ��");
		}
	}
	else
	{
		printf("error:�±����Խ��");
	}
}
void sort_value(list* point_head)//��С�������򣨸ı�ԭ����
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
		else {/*list ֻ����һ��Ԫ��*/ };
	}
	else
	{
		printf("sort error:this list is empty");
	}
	begain = NULL;
	end = NULL;
}
void sortReverse_value(list* point_head)//�Ӵ�С���򣨸ı�ԭ����
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
		else {/*list ֻ����һ��Ԫ��*/ };
	}
	else
	{
		printf("sort error:this list is empty");
	}
	begain = NULL;
	end = NULL;
}
void sort_valueC(const list* point_head)//��С�������򣨲��ı�ԭ��
{
	int num = 0;
	const list* temp = point_head;
	for (; temp->p_next != NULL; num++)
	{
		temp = temp->p_next;
	}
	
	if (num > 1)//�����������������ϵ�Ԫ��
	{	
		//�ó�Ԫ�ظ�����������ͷ�ڵ㣩
		temp = point_head->p_next;
		int* arr = (int*)calloc(num,sizeof(int));//�����ڴ�洢list��ֵ
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
		//����
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
		//���������
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
		//�ͷ��ڴ�
		free(arr);
		arr_begin = NULL;
		arr = NULL;
		temp = NULL;
	}
	else if(num==1) {/*ֻ����һ��Ԫ��*/ }
	else { printf("this is a empty list"); }
}
void sortReverse_valueC(const list* point_head)//�Ӵ�С���򣨲��ı�ԭ��
{
	int num = 0;
	const list* temp = point_head;
	for (; temp->p_next != NULL; num++)
	{
		temp = temp->p_next;
	}

	if (num > 1)//�����������������ϵ�Ԫ��
	{
		//�ó�Ԫ�ظ�����������ͷ�ڵ㣩
		temp = point_head->p_next;
		int* arr = (int*)calloc(num, sizeof(int));//�����ڴ�洢list��ֵ
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
		//����
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
		//���������
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
		//�ͷ��ڴ�
		free(arr);
		arr_begin = NULL;
		arr = NULL;
		temp = NULL;
	}
	else if (num == 1) {/*ֻ����һ��Ԫ��*/ }
	else { printf("this is a empty list"); }
}