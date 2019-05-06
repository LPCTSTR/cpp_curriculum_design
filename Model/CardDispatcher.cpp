//
// Created by LPCTSTR_MSR on 2019/4/18.
//

#include "CardDispatcher.h"
#include <string>
#include "../View/DisplayBuffer.buffer"
#include<unordered_map>

CardDispatcher &CardDispatcher::AddInterceptCard(CardSpec spec) {
    BlackList.push_back(spec);
    return *this;
}

CardDispatcher *CardDispatcher::GetInstance() {
    static CardDispatcher instance;
    return &instance;
}

CardDispatcher::CardDispatcher() : proxy() {

}

bool CardDispatcher::DrawCard(vector<pCard> &vector1) {
    if (GetPoolSize() == 0) {
        Video::GetInstance()->UpdateInfo("No Card to Draw!!!");
        return false;
    }
    auto p = proxy.GetCard();
    if (IsBlack(move(p))) {
        string p = ((*(Intercept_array.end() - 1))->GetGeneral() + " has been confiscated to the Intercept_Array");
        Video::GetInstance()->UpdateInfo(p);
        return false;
    } else
        vector1.push_back(move(OutBoundBuffer[OutBoundBuffer.size() - 1]));
    Video::GetInstance()->UpdateInfo("Draw Card Successfully!!!");
    return true;
}

bool CardDispatcher::IsBlack(pCard card) {
    for (auto i:BlackList)
        if (i.first == card->getAattr() && i.second == card->getBattr()) {
            Intercept_array.push_back(move(card));
            return true;
        }
    OutBoundBuffer.push_back(move(card));
    return false;
}

void CardDispatcher::build(const vector<pair<string, string>> &CardTypeMap, int num) {
    proxy.build(CardTypeMap, num);

}


CardDispatcher &CardDispatcher::SetDefaultAndBuild() {
    proxy.Default_build();
    return *this;
}

CardDispatcher &CardDispatcher::EXcludeInterceptCard(CardSpec spec) {
    for (int i = 0; i < BlackList.size(); i++)
        if (BlackList[i] == spec) {
            BlackList.erase(BlackList.begin() + i);
            return *this;
        }
    return *this;
}

size_t CardDispatcher::GetPoolSize() {
    return proxy.GetPoolSize();
}


vector<string> CardDispatcher::GetPoolList() {
    return proxy.PrintPool();
}
unordered_map<string, int> sortmap = {{"3", 1},
                                      {"4", 2},
                                      {"5", 3},
                                      {"6", 4},
                                      {"7", 5},
                                      {"8", 6},
                                      {"9", 7},
                                      {"10", 8},
                                      {"J", 9},
                                      {"Q", 10},
                                      {"K", 11},
                                      {"A", 12},
                                      {"2", 13},
                                      {"Joker", 14},
                                      {"Extra Joker", 15},

};

void CardDispatcher::SortCard(vector<pCard> &p) {
    sort(p.begin(), p.end(), [](const pCard &a, const pCard &b) {
        return sortmap[a->getAattr()] < sortmap[b->getAattr()];
    });
}
unordered_map<string, int> flower_map={
        {"Heart",1},
        {"Spade",2},
        {"Club",3},
        {"Diamond",4},
        {"-",5}
};
void CardDispatcher::SortCard_F(vector<pCard> &p) {
    sort(p.begin(), p.end(), [](const pCard &a, const pCard &b) {
        return flower_map[a->getBattr()] < flower_map[b->getBattr()];
        //vector的排序属于严格弱排序(<)，因而必须要在comp函数内用 <而不是(<=)
    });
}
