// UTSaveManager.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<tlhelp32.h>
#include<comdef.h>

#include <ctime> 

using namespace std;
void   Delay(int   time)//time*1000为秒数 
{
	clock_t   now = clock();

	while (clock() - now < time);
}

void CommandHelp() {
	cout<< "Help:" << endl;
    cout << "First time you need to	edit the config.config file" << endl;
	cout<< "Like this" << endl;
	cout << "UNDERTALE.exe" << endl;
	cout << R"(C:\\g\\Undertale\\UNDERTALE.exe)" << endl;
	cout<<	R"(C:\\Users\\hzn62\\AppData\\Local\\UNDERTALE)" << endl;
	
}

// TODO: 在此处引用程序需要的其他标头。
