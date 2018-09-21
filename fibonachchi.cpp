// фибоначчи.cpp: определяет точку входа для консольного приложения.
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
	
	float n, x, y, z, a, b, c, l, e, L, fy, fz, fx;
	int i = 0, N = 0, k;
	
	l = 0.1;
	a = -5;
	b = 1;
	e = 0.25;
	k = 0;
	
	cout << "l = " << l << endl;
	cout << "Интервал: [" << a << ", " << b << "]" << endl;
	cout << "е < " << e << endl << endl; 
	
	float F[11] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	
	while(i != 12)
	{
		if(F[i] > (b - a)/l)
		{
			while(k != N-2)
			{
				N = i;
				cout << "Итерация №" << k + 1 << endl;
				
				y = a + (F[N-2]/F[N]) * (b - a);
				z = a + (F[N-1]/F[N]) * (b - a);
				cout << "y = " << y << "; ";
				cout << "z = " << z << endl;
	
				fy = y*y + 6*y + 12;
				fz = z*z + 6*z + 12;
				cout << "Fy = " << fy << "; ";
				cout << "Fz = " << fz << endl;
		
				if(fy < fz)
				{
					b = z;
					z = y;
					y = a + (F[N-k-3]/F[N-k-1]) * (b - a);	
					cout << "Новый интервал: [" << a << ", " << b << "]" << endl;
					cout << "Новый y = " << y << "; ";
					cout << "Новый z = " << z << endl << endl; 			
				}
				else
				{
					a = y;
					y = z;
					z = a + (F[N-k-2]/F[N-k-1]) * (b - a);
					cout << "Новый интервал: [" << a << ", " << b << "]" << endl;
					cout << "Новый y = " << y << "; ";
					cout << "Новый z = " << z << endl << endl; 
				}
				
				if(k != N - 3)
				{
					k++;
				}
				else
				{
					cout << "Последняя итерация" << endl;
					
					y = (a + b)/2;
					z = y + e;
					cout << "Конечный y = " << y << "; ";
					cout << "Конечный z = " << z << endl; 
					
					fy = y*y + 6*y + 12;
					fz = z*z + 6*z + 12;
					cout << "Fy = " << fy << "; ";
					cout << "Fz = " << fz << endl;
				
					if(fy <= fz)
					{
						b = z;
						cout << "Конечный интервал: [" << a << ", " << b << "]" << endl;
					}
					else
					{
						a = y;
						cout << "Конечный интервал: [" << a << ", " << b << "]" << endl;
					}
					
					x = (a + b)/2;
					k = N - 2;
					cout << "Точка минимума х = " << x << endl;
					fx = x*x + 6*x + 12;
					cout << "Значение функции в точке минимума Fx = " << fx << endl;
				}
			}			
		}
		else
		{
			i++;
		}
	}
	
	system("pause");
}

