// Pack.cpp : Defines the entry point for the console application.
//

/*
	测试 pack 参数的性质，特别是在模板声明时，模板的对齐位数和生成模板实例时的对齐函数不一致时的情况
	测试结果：pack类型固定在模板信息之中。
	疑惑：为什么会在VS2012时，当模板实现在不同的pack下会报 this 的 pack 的warning？
*/

#include "stdafx.h"
#include <stdio.h>

#include <list>
#include "pack_template.h"

#pragma pack(1)
typedef packTemplate<float> packTemplate_float;
typedef std::list<int> list_Int;

class packContianer
{
public:
	packContianer() :pt(5.2f) {}
	packTemplate_float pt;
	list_Int listInt;
	float kt;

};

void printBinary(long long z)
{
	int bit = 8 * sizeof(long long) - 1;
	int space = 0;
	while (bit >= 0)
	{
		long long m = (long long)1 << bit;
		if (z & m) printf("1");
		else printf("0");
		bit--;
		space++;
		if (space == 8)
		{
			space = 0;
			printf(" ");
		}

	}
	printf("\n");
}

int main()
{
	packTemplate_float pt(5.2f);
	packContianer ptc;
	printf("sizeof packTemplate is %d\n",sizeof(pt));
	printf("sizeof packTemplate Container is %d\n", sizeof(ptc));
	char chs[15];
	try 
	{
		_snprintf_s(chs,_TRUNCATE, "%s %.1f abc %s \n", "", 1.254555f, "d");
	}
	catch (...)
	{
		printf("exception\n");
	}
	printf(chs);
	printBinary(78);
	printBinary(4294967296);
	printBinary(4555791312875423381);
    return 0;
}

#pragma pack()

