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
		printf("assign error:no enough string_space to assign");
	}
	tempC = NULL;
}
void ShowString(Sstring* str)
{
	if (str->len !=0)
	{
		for (int i = 0; i < str->len; i++)
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
				printf("substring error:����Խ��");
				return str;
			}
		}
		else
		{
			printf("substring error:�±���ʴ���");
			return str;
		}
	}
	else
	{
		printf("substring error:this string is empty");
		return str;
	}
}
int IndexBF(Sstring* capital_str, Sstring* son_str)//����con_str�Ƿ�Ϊ�������Ӵ��������򷵻ص�һ��Ԫ�ص��±�λ�ã����򷵻�0
{
	if (capital_str->len > son_str->len && son_str->len!= 0)
	{
		int cap_bagin = 0;
		for (int sonsub = 0; sonsub<son_str->len; sonsub++)
		{
			if (capital_str->str[cap_bagin + sonsub] == son_str->str[sonsub])
			{
				//continue;//ƥ��ɹ�
			}
			else if(capital_str->str[cap_bagin + sonsub] != son_str->str[sonsub]&&cap_bagin<capital_str->len)
			{
				sonsub = 0;
				cap_bagin++;
			}
		}
		if (cap_bagin != 0)
		{
			return cap_bagin;//�����±�
			int pos = cap_bagin+1;//����Ԫ�ص�pos��Ԫ��
			return pos;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		printf("index error:the first string is to short or is empty\r\n");
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
			printf("strdelete error:this string have not enough len to delete");
		}
	}
	else
	{
		printf("strdelete error:this string is empty ");
	}
}
void DestroyString(Sstring* str)//�����ڴ�
{
	free(str);
}