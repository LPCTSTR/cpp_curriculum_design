//
// Created by LPCTSTR_MSR on 2019/4/18.
//

#ifndef CURRICULUM_WORK_POOL_PROXY_H
#define CURRICULUM_WORK_POOL_PROXY_H


#include "CardFactory.h"
class Pool_Proxy {
public:
    Pool_Proxy();
    vector<string >PrintPool();
    void build(const vector<pair<string, string>> &CardTypeMap,int num);
    pCard GetCard();
    void Default_build();
    size_t GetPoolSize();
private:
    CardFactory cardFactory;
    int CardInstNum;
    Object_Pool<Card> pool;
    vector<pair<string,string>> CardTypeMap;

};


#endif //CURRICULUM_WORK_POOL_PROXY_H
