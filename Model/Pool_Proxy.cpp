//
// Created by LPCTSTR_MSR on 2019/4/18.
//


#include "Pool_Proxy.h"

vector<string> Pool_Proxy::PrintPool() {
    vector<pCard> tmp;
    vector<string >ret;
    int length=pool.size();
    for (int i = 0; i < length; i++) {
        tmp.push_back(move(pool.Get()));
        ret.push_back(tmp[i]->getAattr() + " " + tmp[i]->getBattr());
    }
    return ret;
}

pCard Pool_Proxy::GetCard() {
    return move(pool.Get());
}


Pool_Proxy::Pool_Proxy() {
}

void Pool_Proxy::build(const vector<pair<string, string>> &CardTypeMap, int num) {
    CardInstNum = num;
    this->CardTypeMap = CardTypeMap;
    this->CardTypeMap = CardTypeMap;
    pool.Init(CardTypeMap.size() * CardInstNum);
    cardFactory.setCardMap(CardTypeMap).SetSingleCardNum(num).PoolShuffle(pool);
}

void Pool_Proxy::Default_build() {
    pool.Init(54);
    cardFactory.SetDefault();
    cardFactory.PoolShuffle(this->pool);
}

size_t Pool_Proxy::GetPoolSize() {
    return pool.size();
}
