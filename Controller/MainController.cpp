//
// Created by LPCTSTR_MSR on 2019/4/20.
//

#include <sstream>
#include <map>
#include <unordered_map>
#include "MainController.h"

bool MainController::run() {
    while(1){
        UpdateInfo();
        Video::GetInstance()->UpdateDisplay();
        string command;
        cout<<"Enter Your Cmd here:";
        getline(cin,command);
        int flag=AddCommand(command);
        if(flag==-5)
            Video::GetInstance()->MsgBox("Invalid cmd");
        else if(flag==-1)
            break;
    }
}

unordered_map<string,ICommand*> Cmd_table;

int MainController::AddCommand(string cmd) {
    stringstream s_stream(cmd);
    vector<string >tmp;
    string buf;
    while(s_stream>>buf)
        tmp.push_back(buf);
    if(tmp.size()==0||(Cmd_table.find(tmp[0]))==Cmd_table.end())
        return -5;
    return Cmd_table[tmp[0]]->execute(vector<string>(tmp.begin()+1,tmp.end()));
}




MainController *MainController::GetInstance() {
    static MainController instance;
    return &instance;
}

MainController::MainController() {
    //添加命令
    Cmd_table["exit"]=new cmd_Exit();
    Cmd_table["print"]=new cmd_Info();
    Cmd_table["player"]=new PlayerCmd();
    Cmd_table["test"]=new cmd_test();
    Cmd_table["pool"]=new Pool_Cmd();
    Video::GetInstance()->UpdateMenuTitle("Main View");
}

void MainController::UpdateInfo() {
    size_t size=CardDispatcher::GetInstance()->GetPoolSize();
    Video::GetInstance()->UpdatePoolNum(to_string(size));
    Video::GetInstance()->UpdatePlayerCard(to_string(PlayerManager::GetInstance()->GetPlayerCardNum()));
    Video::GetInstance()->UpdatePlayerCardList(PlayerManager::GetInstance()->getLocal().GetCard());
}
