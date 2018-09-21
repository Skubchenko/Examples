// дихотомия.cpp: определяет точку входа для консольного приложения.
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
	
	float a, b, c, n, x, y, z, l, e, L, fy, fz, fx;
	
	l = 0.1;
	a = -5;
	b = 1;
	e = 0.25;
	n = 1;
	
	cout << "l = " << l << endl;
	cout << "Интервал: [" << a << ", " << b << "]" << endl;
	cout << "е < " << e << endl << endl; 
	
	while (n != 0)
	{
		cout << "Итерация №" << n << endl;
		y = (a+b-l)/2;
		cout << "y = " << y << "; ";
		z = (a+b+l)/2;
		cout << "z = " << z << endl;
		fy = y*y + 6*y + 12;
		cout << "Fy = " << fy << "; ";
		fz = z*z + 6*z + 12;
		cout << "Fz = " << fz << endl;
		
		if(fy < fz)
		{
			b = z;
			cout << "Новый интервал: [" << a << ", " << b << "]" << endl;
		}
		else
		{
			a = y;
			cout << "Новый интервал: [" << a << ", " << b << "]" << endl;
		}
		
		c = b - a;
		L = fabs(c);
		cout << "|L| = " << L << endl << endl;
		
		if(L < e)
		{
			x = (a + b)/2;
			cout << "Точка минимума х = " << x << endl;
			cout << "Конечный интервал: [" << a << ", " << b << "]" << endl;
			fx = x*x + 6*x + 12;
			cout << "Значение функции в точке минимума Fx = " << fx << endl;
			n = 0;
		}
		else
		{
			n++;
		}
	}
	
	system("pause");
}


