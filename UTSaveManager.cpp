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
		cout<< "For more information:https://github.com/GMKZ12/UTSaveManager/" << endl;
		system("pause");
		return 0;
	}
	cout << "For more information:https://github.com/GMKZ12/UTSaveManager/" << endl;
	cout<< "Input \"start\"  to start,\"stop\"  to stop" << endl;
	cout << ">";
		cin >> Input;
		if (Input == "start") {
			cout << "starting Undertale" << endl;
			getline(ifs, KillUTName);
			getline(ifs, GameDir);
			cout <<  "GamePath:" << GameDir << endl;
			cout<< "GameName:" << KillUTName << endl;
			cout<< "SavePath:" << SaveDir << endl;
			ShellExecute(NULL, "open", GameDir.c_str(), NULL, NULL, SW_SHOW);
			while (true) {
				cout << ">";
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
					cout << ">";
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
				if (Input=="restart") {
					Command = "taskkill /F /IM " + KillUTName;
					system(Command.c_str());
					cout << "Restarting in 3s" << endl;
					Delay(3000);
					ShellExecute(NULL, "open", GameDir.c_str(), NULL, NULL, SW_SHOW);
				}
				if (Input == "stop") {
					Command = "taskkill /IM " + KillUTName;
					system(Command.c_str());
					system("pause");
					break;
				}else {
					cout<< "Unknown command,you can input stop,make,back,restart "<< endl;
				}
			}
		}if (Input == "stop") {
			cout<< "Stopping" << endl;
			Command = "taskkill /IM " + KillUTName;
			system(Command.c_str());
			system("pause");
			return 0;
		}
		
		
	
	ifs.close();
	return 0;
}