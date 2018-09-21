// золотое сечение.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int nNumberofArgs, char* pszArgs[])
{
	setlocale(LC_ALL,"Russian");
	
	float n, x, y, z, a, b, c, e, L, fy, fz, fx;
	
	a = -5;
	b = 1;
	e = 0.25;
	n = 1;
	
	cout << "Интервал: [" << a << ", " << b << "]" << endl;
	cout << "е < " << e << endl << endl; 
	
	y = a + 0.382*(b-a);
	z = a + b - y;
	cout << "y = " << y << "; ";
	cout << "z = " << z << endl;
	
	while (n != 0)
	{	
		cout << "Итерация №" << n << endl;
				
		fy = y*y + 6*y + 12;
		fz = z*z + 6*z + 12;
		cout << "Fy = " << fy << "; ";
		cout << "Fz = " << fz << endl;
		
		if(fy < fz)
		{
			b = z;
			z = y;
			y = a + b - y;
			cout << "Новый интервал: [" << a << ", " << b << "]" << endl;
			cout << "Новый y = " << y << "; ";
			cout << "Новый z = " << z << endl; 
		}
		else
		{
			a = y;
			y = z;
			z = a + b - z;
			cout << "Новый интервал: [" << a << ", " << b << "]" << endl;
			cout << "Новый y = " << y << "; ";
			cout << "Новый z = " << z << endl; 
		}
		
		c = b - a;
		L = fabs(c);
		cout << "|L| = " << L << endl << endl;
		
		if(L < e)
		{
			x = (a + b)/2;
			n = 0;
			cout << "Точка минимума х = " << x << endl;
			cout << "Конечный интервал: [" << a << ", " << b << "]" << endl;
			fx = x*x + 6*x + 12;
			cout << "Значение функции в точке минимума Fx = " << fx << endl;
		}
		else
		{
			n++;
		}
	}
system("pause");
}
