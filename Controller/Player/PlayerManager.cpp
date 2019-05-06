//
// Created by LPCTSTR_MSR on 2019/4/21.
//

#include "PlayerManager.h"

PlayerManager::PlayerManager() {
    other.emplace_back();
    other.emplace_back();
    other.emplace_back();
}

PlayerManager *PlayerManager::GetInstance() {
    static PlayerManager playerManager;
    return &playerManager;
}

int PlayerManager::DrawCard(int num, int player) {
    if(player==-1)
        for(int i = 0;i<num;i++) {
            bool t=CardDispatcher::GetInstance()->DrawCard(local.CardSet);
            if(t==false)
                return 0;
        }
    return -1;
}

size_t PlayerManager::GetPlayerCardNum(int player) {
    if(player==-1)
        return local.CardSet.size();
    return 0;
}

Player &PlayerManager::getLocal() {
    return local;
}

void PlayerManager::Deliver() {
    int size=CardDispatcher::GetInstance()->GetPoolSize();
    size=size*3/4;
    for(int i=0;i<size;i++)
        CardDispatcher::GetInstance()->DrawCard(other[i % 3].CardSet);
    DrawCard(CardDispatcher::GetInstance()->GetPoolSize());
}

void PlayerManager::Other_Sort() {
    for(int i =0;i<3;i++)
        CardDispatcher::GetInstance()->SortCard(other[i].CardSet);

}

void PlayerManager::Other_Sort_F() {
    for(int i =0;i<3;i++)
        CardDispatcher::GetInstance()->SortCard_F(other[i].CardSet);
}

vector<string> PlayerManager::Get_Other_Card() {
    vector<string> p;
    for(int i=0;i<3;i++){
        p.push_back("   ");
        p.push_back("Player "+to_string(i+1)+":");
        p.push_back("   ");
        for(int j=0;j<other[i].CardSet.size();j++)
            p.push_back(other[i].CardSet[j]->GetGeneral());
    }
    return p;
}
