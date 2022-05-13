#include<stdio.h>
#include<string.h>


int GetWordNumber(char string[]);  //计算单词数量
int GetCharNumber(char string[]);  //计算字符数量


int main(int argc, char* argv[])
{
	char string[10000] = "\0";     // 用于存放整个文本
	char buff[1024];               // 用于存放文件每行字符
	int num = 0;                   // 计算结果
	FILE* fp = NULL;               // 定义打开文件操作

	// 打开文件
	fp = fopen(argv[2], "r");
	if (fp == NULL)
	{
		printf("file open faild!\n");
		return -1;
	}
	// 读取文本并以追加形式存入字符串
	while (!feof(fp))
	{
		if (fgets(buff, 1023, fp) != NULL)
		{ 
			strcat(string, buff);
		}
	}
	// 判断输入是否有效
	if (argc != 3)
	{
		printf("input parameter error!\n");
	}
	else
	{
		// 选择要计算的类型
		if (strcmp(argv[1], "-w") == 0)
		{
			num = GetWordNumber(string);
			printf("单词数： %d\n", num);
		}
		else if (strcmp(argv[1], "-c") == 0)
		{
			num = GetCharNumber(string);
			printf("字符数： %d\n", num);
		}
		else
		{
			printf("input parameter error!\n");
		}
	}
}


// 计算单词数量
int GetWordNumber(char string[])
{
	int count = 0;  // 单词数
	int flag = 0;   // 标志位，根据英语书写习惯句与句之间除标点外还会追加一个空格，通过此标志位来消除
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == ' ' || string[i] == ',' || string[i] == '.')
		{
			if (flag == 0)
			{
				count++;
				flag = 1;
			}
			else
			{
				flag = 0;
			}
		}
		else
		{
			flag = 0;
		}
	}

	return count;
}


// 计算字符数量
int GetCharNumber(char string[])
{
	// 由于所有字符均作计算，故可直接返回字符串长度
	return strlen(string);
}
