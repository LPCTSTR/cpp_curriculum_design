//
// Created by LPCTSTR_MSR on 2019/4/20.
//

#ifndef CURRICULUM_WORK_MAINCONTROLLER_H
#define CURRICULUM_WORK_MAINCONTROLLER_H

#include "../View/DisplayBuffer.buffer"
#include "Command/Cmd_Pch.h"
#include "Player/PlayerManager.h"

class MainController {
    MainController();
public:
    bool run();
    static MainController* GetInstance();
    int AddCommand(string cmd);
    void UpdateInfo();
};


#endif //CURRICULUM_WORK_MAINCONTROLLER_H
