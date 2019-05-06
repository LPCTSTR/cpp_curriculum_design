//
// Created by LPCTSTR_MSR on 2019/4/21.
//

#include "ICommand.h"

void ICommand::ArgErrorMsg() {
    Video::GetInstance()->MsgBox("Args error!");
}
