//**********************************************//
//
//
//		Calculator.dll Demo
//
//
//**********************************************//

#include<iostream>
#include<string>
#include<cstdlib>
#include<Windows.h>
#include"Calculator.h"
using namespace std;
string fenZi[100] = {"0"};
string fenMu[100] = { "1" };
char fuHao[100] = {0};
string* Stackp=fenZi;
int NumberCounter = 0;
unsigned long MaxFenMu = 1;
void ChangeStack();
void PlusOperater();
void MinusOperater();
void TimeOperater();
void DivideOperater();
void NumberPush(string tmp);
string Calcutest();
void ButtonCE();
void getMaxFenMu();
void fenZiChange();
void ButtonBack(int NumberFlag);
unsigned long gcd(unsigned long x, unsigned long y);


void ChangeStack()
{
	if (Stackp==fenZi)
	{
		Stackp = fenMu;
	}
	else
	{
		Stackp = fenZi;
	}
}
//分数线转换
void PlusOperater()
{
	fuHao[NumberCounter++] = '+';
	ChangeStack();
}
//加号入栈
void MinusOperater()
{
	fuHao[NumberCounter++] = '-';
	ChangeStack();
}
//减号入栈
void TimeOperater()
{
	fuHao[NumberCounter++] = '*';
	ChangeStack();
}
//乘号入栈
void DivideOperater()
{
	fuHao[NumberCounter++] = '/';
	ChangeStack();
}
//除号入栈
void NumberPush(string tmp)
{
	Stackp[NumberCounter] = tmp;
}
//数字入栈(输入值为完整的tmp)
string Calcutest()
{
	string tmp;
	for (int i = 0; i < NumberCounter; i++)
	{
		tmp += fenZi[i];
		if(fuHao[i]=='=')
		{
			break;
		}
		tmp += fuHao[i];
	}
	return tmp;
}
//返回计算式
void ButtonCE()
{
	NumberCounter = 0;
	MaxFenMu = 1;
	ZeroMemory(fuHao, strlen(fuHao)+1);
}
//清空按钮
void getMaxFenMu() 
{
	UINT64 tmp = 1;
	for (int i = 0; i < NumberCounter; i++)
	{
		tmp *= atoi(fenMu[i].c_str());
	}
	MaxFenMu = tmp;
}
//取公共分母
void fenZiChange()
{
	for (int i = 0; i < NumberCounter; i++)
	{
		fenZi[i] = to_string(atoi(fenZi[i].c_str()) * MaxFenMu / atoi(fenMu[i].c_str()));
	}
}
//转换分子为公有可加减数
void ButtonBack(int NumberFlag)
{
	if (NumberFlag)
	{
		Stackp[NumberCounter] = "0";
	}
	else
	{
		NumberCounter--;
		ChangeStack();
	}
}
//退格键
unsigned long gcd(unsigned long x,unsigned long y)
{
	unsigned long z = y;
	while (x % y != 0)
	{
		z = x % y;
		x = y;
		y = z;
	}
	return z;
}
//最大公约数







