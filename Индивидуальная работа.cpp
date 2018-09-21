// Индивидуальная работа.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <locale.h>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"RUSSIAN");
	struct
{
	    string FIO;
		int BDD;
		int BMM;
		int BYYYY;
		int EDD;
		int EMM;
		int EYYYY;
} param;
	string azaza;
	fstream parametr("Param.ini");
	//cout<<parametr.is_open();
	if (!parametr.is_open())
	{
		cout << "Файл не может быть открыт."<<endl;
		system("pause");
	}
	else
	{
	getline(parametr,param.FIO);
	getline(parametr,azaza,'.');
	param.BDD=atoi(azaza.c_str());
	getline(parametr,azaza,'.');
	param.BMM=atoi(azaza.c_str());
	getline(parametr,azaza);
	param.BYYYY=atoi(azaza.c_str());
	getline(parametr,azaza,'.');
    param.EDD=atoi(azaza.c_str());
	getline(parametr,azaza,'.');
	param.EMM=atoi(azaza.c_str());
	getline(parametr,azaza);
	param.EYYYY=atoi(azaza.c_str());
	parametr.close(); 
	}
	string number;
	fstream file1("Client.txt");
	if (!file1.is_open())
	{
		cout << "Файл не может быть открыт."<<endl;
	    system("pause");
	}
	else
	{
	int i;
	string name;
	for (i=0;i<11;i++)
	{
		getline(file1,name,',');
		if (name==param.FIO)
		{
			getline (file1,number,',');
		    break;
		}
		else 
		{
				getline(file1,name);
		} 
	    if(i==10)
	{
		  fstream file2("Report.txt");
		  file2 << "Нет данных";
		  file2.close();
	}
	}
	file1.close();
	}
	//cout<<number<<endl;
	struct
	{
	    string number2;
		int code;
		int UslugaDD;
		int UslugaMM;
		int UslugaYYYY;
	} info;
	int b[10],c[10],d[10],e[10],k;
	string a[10],nomer;
	fstream M("Uslugi klienta.txt");
	if (!M.is_open())
	{
		cout << "Файл не может быть открыт."<<endl;
		system("pause");
	}
	else
	{
	for(k=0;k<10;k++)
	{
		getline(M,nomer,',');
		info.number2=nomer;
		getline(M,nomer,',');
		info.code=atoi(nomer.c_str());
		getline(M,nomer,'.');
		info.UslugaDD=atoi(nomer.c_str());
		getline(M,nomer,'.');
		info.UslugaMM=atoi(nomer.c_str());
		getline(M,nomer,' ');
		info.UslugaYYYY=atoi(nomer.c_str());
		getline(M,nomer);
		a[k]=info.number2;
		b[k]=info.code;
		c[k]=info.UslugaDD;
		d[k]=info.UslugaMM;
		e[k]=info.UslugaYYYY;
	}
	//cout << a[4]<< "\t"<< b[4]<<"\t"<<c[4]<<"\t"<<d[4]<<"\t"<<e[4]<<endl;
	M.close();
	}
	struct 
	{
		string usluga;
		int code2;
	} spisok;
	int h[10];
	string strochka,g[10];
	fstream N("Uslugi.txt");
	if (!N.is_open())
	{
		cout << "Файл не может быть открыт."<<endl;
		system("pause");
	}
	else
	{
	for (int s=0;s<10;s++)
	{
		getline (N,strochka,',');
		spisok.usluga=strochka;
		getline(N,strochka,',');
		spisok.code2=atoi(strochka.c_str());
		getline(N,strochka);
		g[s]=spisok.usluga;
		h[s]=spisok.code2;
	}
	//cout<< g[6]<<"\t"<<h[6]<<endl;
	N.close();
	}
	int j,l,m[10];
	j=(param.BDD)+(param.BMM-1)*30+(param.BYYYY-2005)*365;
	l=(param.EDD)+(param.EMM-1)*30+(param.EYYYY-2005)*365;
	for (k=0;k<10;k++)
	{
	m[k]=(c[k])+(d[k]-1)*30+(e[k]-2005)*365;
	}
	//cout<<j<<endl;
	//cout<<l<<endl;
	//cout<<m[3]<<endl;
	int vel;
	fstream T("Report.txt");
	for (k=0;k<10;k++)
	{
	for ( int s=0;s<10;s++)
		if (number==a[k])
		{ if (m[k]>j)
		{ if (m[k]<l)
		{if (b[k]==h[s])
		{
		T << g[s] << "\n";
		vel=true;
		}
		}
		}
		}
	}
	T.close();
	if (vel==1) 
		cout<<"Fail Report.txt imeet dannye"<<endl;
	else 
	cout <<"Fail Report.txt pust"<<endl;
	system("pause");
	return(0);
	}
