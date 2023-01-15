// UTSaveManager.cpp: 定义应用程序的入口点。
//

#include "UTSaveManager.h"

using namespace std;
string Input;
string GameDir;
string KillUTName;
string Command;
string SaveDir;
string BackUpName;

void   Delay(int   time)//time*1000为秒数 
{
	clock_t   now = clock();

	while (clock() - now < time);
}

int main()
{
	ofstream ofs;
	ifstream ifs;
	ifs.open("config.config");
	getline(ifs, KillUTName);
	getline(ifs, GameDir);
	getline(ifs, SaveDir);
	//KillCommand.append("taskkill /F /IM ");
	//KillCommand.append(KillName);
	
	if (KillUTName == ""||GameDir == ""||SaveDir == "") {
		cout<< "Please write config.config!!" << endl;
		system("pause");
		return 0;
	}
	
		cin >> Input;
		if (Input == "start") {
			cout << "starting Undertale" << endl;
			getline(ifs, KillUTName);
			getline(ifs, GameDir);
			cout << GameDir << endl;
			cout<< KillUTName <<endl;
			ShellExecute(NULL, "open", GameDir.c_str(), NULL, NULL, SW_SHOW);
			while (true) {
				cin >> Input;
				if (Input == "make") {
					cout << "Please input backup name:";
					cin >> BackUpName;
					Command = "mkdir backups\\" + BackUpName;
					system(Command.c_str());
					Command = "xcopy " + SaveDir + "\\*" + " backups\\"+BackUpName;
					system(Command.c_str());
				}
				if (Input == "back") {
					Command = "dir backups\\";
					system(Command.c_str());
					cout << "Please input backup name:";
					cin >> BackUpName;
					cout<< "Sure? yes/no" << endl;
					cin >> Input;
					if (Input=="yes") {
						cout<< "Closing Undertale in 3s" << endl;
						Delay(3000);
						Command = "taskkill /F /IM " + KillUTName;
						system(Command.c_str());
						Command = "xcopy /y backups\\" + BackUpName + "\\* " + SaveDir;
						system(Command.c_str());
						cout<< "Restarting in 3s" << endl;
						Delay(3000);
						ShellExecute(NULL, "open", GameDir.c_str(), NULL, NULL, SW_SHOW);
					}
					else{
						cout<< "Backup cancel" << endl;
					}
					
				}

				if (Input == "stop") {
					Command = "taskkill /IM " + KillUTName;
					system(Command.c_str());
					break;
				}
			}
		}
		
	
	ifs.close();
	return 0;
}
