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
		printf("error:�ڴ����ʧ��");
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
	if (str->len != 0)
	{
		for (int i = 0; i < str->len; i++)
		{
			printf("%c", str->str[i]);
		}
		printf("\r\n");
	}
	else
	{
		printf("this string is empty");
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
