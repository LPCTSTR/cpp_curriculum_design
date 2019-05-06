//
// Created by LPCTSTR_MSR on 2019/4/21.
//

#ifndef CURRICULUM_WORK_BASICCLASS_H
#define CURRICULUM_WORK_BASICCLASS_H

#include "ICommand.h"
class cmd_Exit : public ICommand{

public:
    int execute(vector<string> para) override;
};

class cmd_Info : public ICommand{
public:
    int execute(vector<string> para) override;
};

class cmd_test: public ICommand{
public:
    int execute(vector<string> para) override;
};
#endif //CURRICULUM_WORK_BASICCLASS_H
