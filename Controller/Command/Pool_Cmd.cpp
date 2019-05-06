//
// Created by LPCTSTR_MSR on 2019/4/23.
//

#include "Pool_Cmd.h"

int Pool_Cmd::execute(vector<string> para) {
    if(para[0]=="ps"){
        Video::GetInstance()->UpdateMenuTitle("Pool Card List");
        Video::GetInstance()->UpdatePoolList(CardDispatcher::GetInstance()->GetPoolList());
    }else if(para[0]=="ban"){
        if(para.size()<3){
            ArgErrorMsg();
            return 0;
        }
        CardDispatcher::GetInstance()->AddInterceptCard({para[1],para[2]});
        Video::GetInstance()->UpdateInfo(para[1]+" "+para[2]+" has been baned!");
    }else if(para[0]=="deliver"){
        PlayerManager::GetInstance()->Deliver();
        Video::GetInstance()->UpdateInfo("Deliver successfully!");
    }
}
