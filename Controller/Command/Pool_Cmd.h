//
// Created by LPCTSTR_MSR on 2019/4/23.
//

#ifndef CURRICULUM_WORK_GLOBALCMD_H
#define CURRICULUM_WORK_GLOBALCMD_H

#include "ICommand.h"

class Pool_Cmd :public ICommand{
public:
    int execute(vector<string> para) override;

};


#endif //CURRICULUM_WORK_GLOBALCMD_H
