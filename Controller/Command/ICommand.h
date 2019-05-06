//
// Created by LPCTSTR_MSR on 2019/4/21.
//

#ifndef CURRICULUM_WORK_ICOMMAND_H
#define CURRICULUM_WORK_ICOMMAND_H

#include "../Player/PlayerManager.h"
#include "../../View/DisplayBuffer.buffer"
class ICommand {
public:
    virtual int execute(vector<string> para)=0;
    void ArgErrorMsg();
};


#endif //CURRICULUM_WORK_ICOMMAND_H
