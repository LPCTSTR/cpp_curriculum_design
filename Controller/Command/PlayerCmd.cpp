//
// Created by LPCTSTR_MSR on 2019/4/21.
//

#include <sstream>
#include "PlayerCmd.h"

int PlayerCmd::execute(vector<string> para) {
    if(para[0]=="draw") {
        if(para.size()!=2){
            ArgErrorMsg();
            return 0;
        }
        stringstream ss(para[1]);
        int num;
        ss >> num;
        PlayerManager::GetInstance()->DrawCard(num, -1);
    } else if(para[0]=="rm"){
        if(para.size()!=2){
            ArgErrorMsg();
            return 0;
        }
        stringstream ss(para[1]);
        int num;
        ss >> num;
        auto &p=PlayerManager::GetInstance()->getLocal().CardSet;
        if(num>p.size()||num<1) {
            Video::GetInstance()->UpdateInfo("The index is invalid!");
            return -5;
        }
        string text=p[num-1]->GetGeneral();
        p.erase(p.begin()+num-1);
        Video::GetInstance()->UpdateInfo(text+"has been released");
        return 0;
    }else if(para[0]=="sort"){
        if(para.size()>1&&para[1]=="-f") {
            CardDispatcher::SortCard_F(PlayerManager::GetInstance()->getLocal().CardSet);
            PlayerManager::GetInstance()->Other_Sort_F();
            return 0;
        }
        CardDispatcher::SortCard(PlayerManager::GetInstance()->getLocal().CardSet);
        PlayerManager::GetInstance()->Other_Sort();
    }else if(para[0]=="other"){
        Video::GetInstance()->UpdatePoolList(PlayerManager::GetInstance()->Get_Other_Card());
    }
    return 0;
}
