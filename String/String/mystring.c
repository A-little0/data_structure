#include "mystring.h"
#include "malloc.h"

Sstring* StringInit()//初始化空字符串
{
	Sstring* str_point = (Sstring*)malloc(sizeof(Sstring));
	if (str_point != NULL)
	{
		str_point->len = 0;
		return str_point;
	}
	else
	{
		printf("error:内存分配失败\r\n");
		return NULL;
	}

}

void StrAssign(Sstring* str,char* const_strpoint)//用字符串常量初始化str
{
	//获取字符串常量的长度
	int const_strlen = 0;
	char* tempC = const_strpoint;
	for (; *tempC != '\0'; const_strlen++)
	{
		tempC++;
	}
	tempC = const_strpoint;
	//初始化
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
Sstring* StrCopy(Sstring* str, Sstring* input_str)//将str复制为input_str
{
	if (str->len >= 0)//str已初始化
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
int StrCompare(Sstring* str1, Sstring* str2)//str1>str2返回>0 str1==str2返回=0 str1<str2返回<0
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
unsigned int StrLength(Sstring* str)//返回字符串长度
{
	//printf("%d\r\n", str->len);
	return str->len;
}
void ClearString(Sstring* str)//清空字符串（将length置零）
{
	str->len = 0;
}
Sstring* Concat(Sstring* output_str, Sstring* input_str1, Sstring* input_str2)//返回字符串1加字符串2
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
Sstring* SubString(Sstring* str, unsigned int pos, unsigned int len)//返回从第pos个元素开始长度为len的子串
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
				printf("substring error:长度越界\r\n");
				return str;
			}
		}
		else
		{
			printf("substring error:下标访问错误\r\n");
			return str;
		}
	}
	else
	{
		printf("substring error:this string is empty\r\n");
		return str;
	}
}
int* IndexBF(Sstring* capital_str, Sstring* son_str)//查找con_str是否为主串的子串，若有则返回第一个元素的下标位置，否则返回0
{
	if (capital_str->len > son_str->len && son_str->len!= 0)
	{
		static int subarr[MINLENGTH] = { 0 };//存储子串在主串第一个元素的位置
		int arr_sub = 0;//数组下标
		int cap_bagin = 0;//下标
		while ((capital_str->len - son_str->len) >= cap_bagin)
		{
			int sonsub ;
			for (sonsub=0; sonsub < son_str->len&&cap_bagin<=(capital_str->len-son_str->len);)
			{
				if (capital_str->str[cap_bagin + sonsub] == son_str->str[sonsub])
				{
					//continue;//匹配成功
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
int* IndexKMP(Sstring* capital_str, Sstring* son_str)//查找con_str是否为主串的子串，若有则返回第一个元素的位置位置，否则返回0；(KMP算法)
{
	if (capital_str->len >= son_str->len)//判断son_str是否为capital_str的子串
	{
		static int posarr[MINLENGTH] = { 0 };//初始化匹配首元素位置数组
		int posnum=0;
		int nextarr[MINLENGTH] = { 0 };//初始化next数组
		int poserror = 1;
		int son_pospoint = 1;
		
		while ((capital_str->len - son_str->len) + 1 >= son_pospoint)//遍历整个主串
		{
			int i = 1;//i为pos，指向子串第i个元素
			for (;i<=son_str->len;)
			{
				if (capital_str->str[son_pospoint + i - 1 - 1] == son_str->str[i - 1])
				{
					i++;//匹配成功
				}
				else//匹配失败KMP
				{
					poserror = i;//标记子串第i个元素是匹配失败的元素
					nextarr[0] = -1;//next数组的第一个元素必为-1

					int comparelen = poserror - 1;
					for (int m= 1;m < comparelen;m++)//判断最长前后缀
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
					son_pospoint += comparelen - nextarr[poserror - 1];//移动子串第一个元素在主串的第son_pospoint的位置
					if (nextarr[poserror - 1] == -1)//匹配失败的特殊情况：子串的的第一个元素匹配失败
					{
						i = 1;//更新i在son_str上的指向
					}
					else
					{
						i =nextarr[poserror - 1]+1;//更新i在son_str上的指向
					}

				}
			}
			if (i > son_str->len)//判断是否找到子串
			{
				posarr[posnum] = son_pospoint;
				posnum++;
				son_pospoint += son_str->len;//继续寻找下一个子串
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
void Replace(Sstring* capital_str, Sstring* compare_str, Sstring* replaced_str)//在capital_str中找到与compare_str相同的子串，并替换为replaced_str
{
	int* getpos = IndexBF(capital_str, compare_str);
	for (;(* getpos) != 0; )
	{
		StrInsert(capital_str,*getpos,replaced_str);//在第POS个元素前插入insert_str
		StrDelete(capital_str,*getpos+replaced_str->len,compare_str->len);//在第POS个元素起，删除长度为len的子串
		getpos++;
		if (*getpos != 0)
		{
			*getpos += (replaced_str->len - compare_str->len);
		}
	}
}
void StrInsert(Sstring* capital_str, unsigned int pos, Sstring* insert_str)//在第POS个元素前插入insert_str
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
		printf("strinsert error:元素下标访问越界\r\n");
	}
}
void StrDelete(Sstring* capital_str, unsigned int pos, unsigned int len)//在第POS个元素起，长度为len的子串
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
void DestroyString(Sstring* str)//回收内存
{
	free(str);
}