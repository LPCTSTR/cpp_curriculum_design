//
// Created by LPCTSTR_MSR on 2019/4/21.
//

#include "Player.h"

vector<string> Player::GetCard() {
    vector<string> p;
    for(int i = 0 ;i<CardSet.size();i++)
        p.push_back(CardSet[i]->getAattr()+" "+CardSet[i]->getBattr());
    return p;
}
