//
// Created by LPCTSTR_MSR on 2019/4/21.
//

#ifndef CURRICULUM_WORK_PLAYERMANAGER_H
#define CURRICULUM_WORK_PLAYERMANAGER_H


#include "Player.h"

class PlayerManager {
    PlayerManager();
    Player local;
public:
    Player &getLocal() ;

private:
    vector<Player >other;
public:
    size_t GetPlayerCardNum(int player=-1);
    int DrawCard(int num,int player=-1);
    static PlayerManager* GetInstance();
    void Deliver();
    void Other_Sort();
    void Other_Sort_F();
    vector<string> Get_Other_Card();
};


#endif //CURRICULUM_WORK_PLAYERMANAGER_H
