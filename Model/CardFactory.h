//
// Created by LPCTSTR_MSR on 2019/4/18.
//

#ifndef CURRICULUM_WORK_CARDFACTORY_H
#define CURRICULUM_WORK_CARDFACTORY_H

#include "Card.h"
#include "Pool/Pool.hpp"

class CardFactory {
private:
    vector<pair<string,string>> CardMap;
    vector<pair<pair<string,string>,int>> CardMapEx;
    int SingleCardNum;
public:
    CardFactory& setCardMap(const vector<pair<string, string>> &CardMap);

    void SetDefault();
    CardFactory& SetSingleCardNum(int num);

    void PoolShuffle(Object_Pool<Card >&pool);
};


#endif //CURRICULUM_WORK_CARDFACTORY_H
