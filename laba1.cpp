// laba1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "hasp_api.h"
#include "iostream"
#include <string.h>
#include <cstdio>
#include <cstdlib>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"Russian");
	const hasp_feature_t feature = HASP_DEFAULT_FID;

hasp_handle_t handle = HASP_INVALID_HANDLE_VALUE;
hasp_status_t status;

unsigned char vendor_code[] =
"AzIceaqfA1hX5wS+M8cGnYh5ceevUnOZIzJBbXFD6dgf3tBkb9cvUF/Tkd/iKu2fsg9wAysYKw7RMAsV"
"vIp4KcXle/v1RaXrLVnNBJ2H2DmrbUMOZbQUFXe698qmJsqNpLXRA367xpZ54i8kC5DTXwDhfxWTOZrB"
"rh5sRKHcoVLumztIQjgWh37AzmSd1bLOfUGI0xjAL9zJWO3fRaeB0NS2KlmoKaVT5Y04zZEc06waU2r6"
"AU2Dc4uipJqJmObqKM+tfNKAS0rZr5IudRiC7pUwnmtaHRe5fgSI8M7yvypvm+13Wm4Gwd4VnYiZvSxf"
"8ImN3ZOG9wEzfyMIlH2+rKPUVHI+igsqla0Wd9m7ZUR9vFotj1uYV0OzG7hX0+huN2E/IdgLDjbiapj1"
"e2fKHrMmGFaIvI6xzzJIQJF9GiRZ7+0jNFLKSyzX/K3JAyFrIPObfwM+y+zAgE1sWcZ1YnuBhICyRHBh"
"aJDKIZL8MywrEfB2yF+R3k9wFG1oN48gSLyfrfEKuB/qgNp+BeTruWUk0AwRE9XVMUuRbjpxa4YA67SK"
"unFEgFGgUfHBeHJTivvUl0u4Dki1UKAT973P+nXy2O0u239If/kRpNUVhMg8kpk7s8i6Arp7l/705/bL"
"Cx4kN5hHHSXIqkiG9tHdeNV8VYo5+72hgaCx3/uVoVLmtvxbOIvo120uTJbuLVTvT8KtsOlb3DxwUrwL"
"zaEMoAQAFk6Q9bNipHxfkRQER4kR7IYTMzSoW5mxh3H9O8Ge5BqVeYMEW36q9wnOYfxOLNw6yQMf8f9s"
"JN4KhZty02xm707S7VEfJJ1KNq7b5pP/3RjE0IKtB2gE6vAPRvRLzEohu0m7q1aUp8wAvSiqjZy7FLaT"
"tLEApXYvLvz6PEJdj4TegCZugj7c8bIOEqLXmloZ6EgVnjQ7/ttys7VFITB3mazzFiyQuKf4J6+b/a/Y";

	status = hasp_login(feature,vendor_code,&handle);
	if (status == HASP_STATUS_OK)
	{
		setlocale(LC_ALL,"Russian");
	char result;
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
	status = hasp_logout(handle);
	cout << "Сохранить минимальное значение функции на ключ? Если да, введите 1" <<endl;
			cin >> result;
			status = hasp_login(feature,vendor_code,&handle);
			if (( result == 1) && (status == HASP_STATUS_OK))
			{
				status = hasp_write(handle, HASP_FILEID_RW, 0, sizeof(x), &x);
				status = hasp_read(handle, HASP_FILEID_RW, 0, sizeof(x), &x);
				cout << "Запись прошла успешно!" <<endl;
			}
			else
		 {
			switch(status)
		    {
			   case HASP_CONTAINER_NOT_FOUND:
			   cout<<"Выполнение запрещено: отсутствует ключ, код ошибки "<<status<<endl;
			   break;
		    }
	     }
	}
	else
	{
		switch(status)
		{
		case HASP_CONTAINER_NOT_FOUND:
			cout<<"Выполнение запрещено: отсутствует ключ, код ошибки "<<status<<endl;
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
	}
			break;
		default:
			cout<<"ERROR "<<status<<endl;
			break;
		}
	}
status = hasp_logout(handle);
	system("pause");
}

