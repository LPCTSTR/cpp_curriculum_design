//
// Created by LPCTSTR_MSR on 2019/4/21.
//

#ifndef CURRICULUM_WORK_PLAYERCMD_H
#define CURRICULUM_WORK_PLAYERCMD_H

#include "ICommand.h"
class PlayerCmd :public ICommand{
public:
    int execute(vector<string> para) override;
};


#endif //CURRICULUM_WORK_PLAYERCMD_H
