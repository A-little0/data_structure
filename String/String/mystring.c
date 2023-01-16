#include "mystring.h"
#include "malloc.h"

Sstring* StringInit()//��ʼ�����ַ���
{
	Sstring* str_point = (Sstring*)malloc(sizeof(Sstring));
	if (str_point != NULL)
	{
		str_point->len = 0;
		return str_point;
	}
	else
	{
		printf("error:�ڴ����ʧ��\r\n");
		return NULL;
	}

}

void StrAssign(Sstring* str,char* const_strpoint)//���ַ���������ʼ��str
{
	//��ȡ�ַ��������ĳ���
	int const_strlen = 0;
	char* tempC = const_strpoint;
	for (; *tempC != '\0'; const_strlen++)
	{
		tempC++;
	}
	tempC = const_strpoint;
	//��ʼ��
	if (str->len == 0&&const_strlen<=MINLENGTH)
	{
		Sstring* target_point = str;
		for (int i = 0; i < const_strlen;i++)
		{
			target_point->str[i] = *tempC;
			tempC++;
		}
		target_point->len = const_strlen;
	}
	else
	{
		printf("assign error:no enough string_space to assign\r\n");
	}
	tempC = NULL;
}
void ShowString(Sstring* str)
{
	if (str->len !=0)
	{
		for (unsigned int i = 0; i < str->len; i++)
		{
			printf("%c", str->str[i]);
		}
		printf("\r\n");
	}
	else
	{
		printf("this string is empty\r\n");
	}
}
Sstring* StrCopy(Sstring* str, Sstring* input_str)//��str����Ϊinput_str
{
	if (str->len >= 0)//str�ѳ�ʼ��
	{
		for (int i = 0; i < input_str->len; i++)
		{
			str->str[i] = input_str->str[i];
		}
		str->len = input_str->len;

		return str;
	}
}

bool StrEmpty(Sstring* str)
{
	if (str->len == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int StrCompare(Sstring* str1, Sstring* str2)//str1>str2����>0 str1==str2����=0 str1<str2����<0
{
	if (str1->len > str2->len)
	{
		printf("length:string1>string2r\r\n");
		return 1;
	}
	else if (str1->len == str2->len)
	{
		printf("length:string1==string2\r\n");
		return 0;
	}
	else
	{
		printf("length:string1<string2\r\n");
		return -1;
	}
}
unsigned int StrLength(Sstring* str)//�����ַ�������
{
	//printf("%d\r\n", str->len);
	return str->len;
}
void ClearString(Sstring* str)//����ַ�������length���㣩
{
	str->len = 0;
}
Sstring* Concat(Sstring* output_str, Sstring* input_str1, Sstring* input_str2)//�����ַ���1���ַ���2
{
	if (input_str1->len + input_str2->len <= MINLENGTH)
	{
		Sstring* outputstr = output_str;

			for (int i = 0; i < input_str1->len; i++)
			{
				outputstr->str[i] = input_str1->str[i];
			}
			outputstr->len = input_str1->len;
			for (int j = 0; j < input_str2->len; j++)
			{
				outputstr->str[ j + outputstr->len] = input_str2->str[j];
			}
			outputstr->len += input_str2->len;
			return outputstr;
	}
	else
	{
		printf("concat error:no enough length to add\r\n");
		return output_str;
	}
	
}
Sstring* SubString(Sstring* str, unsigned int pos, unsigned int len)//���شӵ�pos��Ԫ�ؿ�ʼ����Ϊlen���Ӵ�
{
	if (str->len != 0)
	{
		if (pos >= 1 && pos < str->len)
		{
			if (pos + len - 1 <= MINLENGTH)
			{
				Sstring* outputstr =(Sstring*)malloc(sizeof(Sstring));
				if (outputstr != NULL)
				{
					for (int i = pos - 1, j = 0; i < len+pos-1; j++, i++)
					{
						outputstr->str[j] = str->str[i];
					}
					outputstr->len = len;

					return outputstr;
				}

			}
			else
			{
				printf("substring error:����Խ��\r\n");
				return str;
			}
		}
		else
		{
			printf("substring error:�±���ʴ���\r\n");
			return str;
		}
	}
	else
	{
		printf("substring error:this string is empty\r\n");
		return str;
	}
}
int* IndexBF(Sstring* capital_str, Sstring* son_str)//����con_str�Ƿ�Ϊ�������Ӵ��������򷵻ص�һ��Ԫ�ص��±�λ�ã����򷵻�0
{
	if (capital_str->len > son_str->len && son_str->len!= 0)
	{
		static int subarr[MINLENGTH] = { 0 };//�洢�Ӵ���������һ��Ԫ�ص�λ��
		int arr_sub = 0;//�����±�
		int cap_bagin = 0;//�±�
		while ((capital_str->len - son_str->len) >= cap_bagin)
		{
			int sonsub ;
			for (sonsub=0; sonsub < son_str->len&&cap_bagin<=(capital_str->len-son_str->len);)
			{
				if (capital_str->str[cap_bagin + sonsub] == son_str->str[sonsub])
				{
					//continue;//ƥ��ɹ�
					sonsub++;
				}
				else if (capital_str->str[cap_bagin + sonsub] != son_str->str[sonsub] && cap_bagin < capital_str->len)
				{
					cap_bagin++;
					sonsub = 0;
				}
			}
			if (sonsub != 0)
			{
				subarr[arr_sub] = cap_bagin + 1;//cap_bagin+1==pos

				if (cap_bagin < capital_str->len)
				{
					cap_bagin += son_str->len;
				}
				arr_sub++;
			}
		}
		return subarr;
	}
	else
	{
		printf("index error:the first string is to short or is empty\r\n");
	}
}
int* IndexKMP(Sstring* capital_str, Sstring* son_str)//����con_str�Ƿ�Ϊ�������Ӵ��������򷵻ص�һ��Ԫ�ص�λ��λ�ã����򷵻�0��(KMP�㷨)
{
	if (capital_str->len >= son_str->len)//�ж�son_str�Ƿ�Ϊcapital_str���Ӵ�
	{
		static int posarr[MINLENGTH] = { 0 };//��ʼ��ƥ����Ԫ��λ������
		int posnum=0;
		int nextarr[MINLENGTH] = { 0 };//��ʼ��next����
		int poserror = 1;
		int son_pospoint = 1;
		
		while ((capital_str->len - son_str->len) + 1 >= son_pospoint)//������������
		{
			int i = 1;//iΪpos��ָ���Ӵ���i��Ԫ��
			for (;i<=son_str->len;)
			{
				if (capital_str->str[son_pospoint + i - 1 - 1] == son_str->str[i - 1])
				{
					i++;//ƥ��ɹ�
				}
				else//ƥ��ʧ��KMP
				{
					poserror = i;//����Ӵ���i��Ԫ����ƥ��ʧ�ܵ�Ԫ��
					nextarr[0] = -1;//next����ĵ�һ��Ԫ�ر�Ϊ-1

					int comparelen = poserror - 1;
					for (int m= 1;m < comparelen;m++)//�ж��ǰ��׺
					{
						for (int j = 0; j < m; j++)
						{
							if (son_str->str[j] == son_str->str[comparelen - m + j])
							{
								nextarr[poserror - 1] = m;
							}
							else if (son_str->str[j] != son_str->str[comparelen - m + j] && nextarr[poserror - 1] == 0)
							{
								nextarr[poserror - 1] = 0;
							}
						}
					}
					son_pospoint += comparelen - nextarr[poserror - 1];//�ƶ��Ӵ���һ��Ԫ���������ĵ�son_pospoint��λ��
					if (nextarr[poserror - 1] == -1)//ƥ��ʧ�ܵ�����������Ӵ��ĵĵ�һ��Ԫ��ƥ��ʧ��
					{
						i = 1;//����i��son_str�ϵ�ָ��
					}
					else
					{
						i =nextarr[poserror - 1]+1;//����i��son_str�ϵ�ָ��
					}

				}
			}
			if (i > son_str->len)//�ж��Ƿ��ҵ��Ӵ�
			{
				posarr[posnum] = son_pospoint;
				posnum++;
				son_pospoint += son_str->len;//����Ѱ����һ���Ӵ�
				i = 1;
			}
		}
		return posarr;
	}
	else
	{
		printf("indexkmp error:captial are too shortr\r\n");
	}
}
void Replace(Sstring* capital_str, Sstring* compare_str, Sstring* replaced_str)//��capital_str���ҵ���compare_str��ͬ���Ӵ������滻Ϊreplaced_str
{
	int* getpos = IndexBF(capital_str, compare_str);
	for (;(* getpos) != 0; )
	{
		StrInsert(capital_str,*getpos,replaced_str);//�ڵ�POS��Ԫ��ǰ����insert_str
		StrDelete(capital_str,*getpos+replaced_str->len,compare_str->len);//�ڵ�POS��Ԫ����ɾ������Ϊlen���Ӵ�
		getpos++;
		if (*getpos != 0)
		{
			*getpos += (replaced_str->len - compare_str->len);
		}
	}
}
void StrInsert(Sstring* capital_str, unsigned int pos, Sstring* insert_str)//�ڵ�POS��Ԫ��ǰ����insert_str
{
	if (pos > 0 && capital_str->len >= pos)
	{
		if (MINLENGTH >= (insert_str->len + capital_str->len))
		{
			int end = capital_str->len;
			for (int i=0;i<capital_str->len-pos+1;i++)
			{
				capital_str->str[end + insert_str->len-1] = capital_str->str[end-1];
				end--;
			}
			for (int j = 0; j < insert_str->len; j++)
			{
				capital_str->str[pos-1] = insert_str->str[j];
				pos++;
			}
			capital_str->len += insert_str->len;
		}
		else
		{
			printf("strinsert error:no enough spaces to insert\r\n");
		}
	}
	else
	{
		printf("strinsert error:Ԫ���±����Խ��\r\n");
	}
}
void StrDelete(Sstring* capital_str, unsigned int pos, unsigned int len)//�ڵ�POS��Ԫ���𣬳���Ϊlen���Ӵ�
{
	if (capital_str->len >= pos && pos > 0)
	{
		if (capital_str->len - pos + 1 >= len)
		{
			for (int i = 0;capital_str->len-(pos+len-1);pos++)
			{
				capital_str->str[pos - 1] = capital_str->str[pos - 1 + len];
			}
			capital_str->len -= len;
		}
		else
		{
			printf("strdelete error:this string have not enough len to delete\r\n");
		}
	}
	else
	{
		printf("strdelete error:this string is empty\r\n ");
	}
}
void DestroyString(Sstring* str)//�����ڴ�
{
	free(str);
}