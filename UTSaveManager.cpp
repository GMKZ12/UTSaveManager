// UTSaveManager.cpp: 定义应用程序的入口点。
//

#include "UTSaveManager.h"

using namespace std;
#include "jsonxx/json.hpp"
using namespace jsonxx;
string Input;
string GameDir;
string KillUTName;
string Command;
string SaveDir;
string BackUpName;
json j;
bool FirstOpen;
int main()
{
	
	ifstream ifs;
	ifstream ifsJson("config.json");
	ifsJson >> j;
	
	//ifs.open("config.config");
	//getline(ifs, KillUTName);
	//getline(ifs, GameDir);
	//getline(ifs, SaveDir);
	//KillCommand.append("taskkill /F /IM ");
	//KillCommand.append(KillName);
	
	/*
	if (KillUTName == ""||GameDir == ""||SaveDir == "") {
		cout<< "Please write config.config!!" << endl;
		cout<< "For more information:https://github.com/GMKZ12/UTSaveManager/" << endl;
		system("pause");
		return 0;
	}
	*/
	GameDir = j["GameDir"].as_string();
	SaveDir = j["SaveDir"].as_string();
	KillUTName = j["UTExe"].as_string();
	FirstOpen = j["FirstOpen"].as_bool();

	if (FirstOpen == true) {
		ofstream ofsJson("config.json");
		cout<< "We detect you first open the program.Please input your UNDERTALE information:)" << endl;
		cout << "GameDir:";
		cin >> Input;
		j["GameDir"] = Input;
		cout << "SaveDir:";
		cin >> Input;
		j["SaveDir"] = Input;
		cout << "UTExeGameName:";
		cin >> Input;
		j["UTExe"] = Input;
		Input = "NOTHING";
		j["FirstOpen"] = false;
		ofsJson << j << std::endl;
		ofsJson.close();
		cout << "Successfully edit config file \"config.json\" " << endl;
	}

	GameDir = j["GameDir"].as_string();
	SaveDir = j["SaveDir"].as_string();
	KillUTName = j["UTExe"].as_string();
	FirstOpen = j["FirstOpen"].as_bool();

	cout << "For more information:https://github.com/GMKZ12/UTSaveManager/" << endl;
	cout<< "Input \"start\"  to start,\"stop\"  to stop" << endl;
	

	
	
	cout << ">";
		cin >> Input;
		if (Input == "start") {
			cout << "starting Undertale" << endl;
			//getline(ifs, KillUTName);
			//getline(ifs, GameDir);
			cout <<  "GamePath:" << GameDir << endl;
			cout<< "GameName:" << KillUTName << endl;
			cout<< "SavePath:" << SaveDir << endl;
			ShellExecute(NULL, "open", GameDir.c_str(), NULL, NULL, SW_SHOW);
			Input = "NOTHING";
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
					//CopyFile((SaveDir+"\\*").c_str(), ("backups\\"+BackUpName).c_str(),true);
					Input = "NOTHING";
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
						Input = "NOTHING";
					}
					else{
						cout<< "Backup cancel" << endl;
						Input = "NOTHING";
					}
					
				}
				if (Input=="restart") {
					Command = "taskkill /F /IM " + KillUTName;
					system(Command.c_str());
					cout << "Restarting in 3s" << endl;
					Delay(3000);
					ShellExecute(NULL, "open", GameDir.c_str(), NULL, NULL, SW_SHOW);
					Input = "NOTHING";
				}
				if (Input == "stop") {
					Command = "taskkill /IM " + KillUTName;
					system(Command.c_str());
					system("pause");
					Input = "NOTHING";
					break;
				}if (Input == "NOTHING") {
					
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
		}if (Input == "help")
		{
			CommandHelp();
		}
		
		
		ifsJson.close();
		//ifs.close();
	return 0;
}