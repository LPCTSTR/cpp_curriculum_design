//
// Created by LPCTSTR_MSR on 2019/4/21.
//

#include "BasicCmd.h"
int cmd_Exit::execute(vector<string> para) {
    return -1;
}

int cmd_Info::execute(vector<string> para) {
//    if(para[0]!="-card")
//        Video::GetInstance()->UpdateInfo(para[0]);
//    else
//        Video::GetInstance()->UpdateCard(
//            {{"A Spade"},
//             {"2 Diamond"},
//             {"10 Heart"}}
//             );
    Video::GetInstance()->UpdateInfo(para[0]);
    return 0;
}

int cmd_test::execute(vector<string> para) {
    Video::GetInstance()->MsgBox(para[0]);
}
