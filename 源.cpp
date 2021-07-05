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
//������ת��
void PlusOperater()
{
	fuHao[NumberCounter++] = '+';
	ChangeStack();
}
//�Ӻ���ջ
void MinusOperater()
{
	fuHao[NumberCounter++] = '-';
	ChangeStack();
}
//������ջ
void TimeOperater()
{
	fuHao[NumberCounter++] = '*';
	ChangeStack();
}
//�˺���ջ
void DivideOperater()
{
	fuHao[NumberCounter++] = '/';
	ChangeStack();
}
//������ջ
void NumberPush(string tmp)
{
	Stackp[NumberCounter] = tmp;
}
//������ջ(����ֵΪ������tmp)
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
//���ؼ���ʽ
void ButtonCE()
{
	NumberCounter = 0;
	MaxFenMu = 1;
	ZeroMemory(fuHao, strlen(fuHao)+1);
}
//��հ�ť
void getMaxFenMu() 
{
	UINT64 tmp = 1;
	for (int i = 0; i < NumberCounter; i++)
	{
		tmp *= atoi(fenMu[i].c_str());
	}
	MaxFenMu = tmp;
}
//ȡ������ĸ
void fenZiChange()
{
	for (int i = 0; i < NumberCounter; i++)
	{
		fenZi[i] = to_string(atoi(fenZi[i].c_str()) * MaxFenMu / atoi(fenMu[i].c_str()));
	}
}
//ת������Ϊ���пɼӼ���
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
//�˸��
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
//���Լ��







